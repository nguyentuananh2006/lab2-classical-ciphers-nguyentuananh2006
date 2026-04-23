from pathlib import Path
import re
import subprocess
import sys

root = Path('.')
errors = []
warnings = []

required_files = [
    'README.md',
    'report-1page.md',
    'src/caesar.cpp',
    'src/rail_fence.cpp',
    'data/input.txt',
    'tests/test_cases.md',
    'logs/run_log.md',
]

for rel in required_files:
    if not (root / rel).exists():
        errors.append(f'Thieu file bat buoc: {rel}')

if errors:
    print('\n'.join(f'::error::{e}' for e in errors))
    sys.exit(1)

def read_file(path):
    try:
        return (root / path).read_text(encoding='utf-8')
    except:
        return ""

readme = read_file('README.md')
report = read_file('report-1page.md')
caesar = read_file('src/caesar.cpp')
rail = read_file('src/rail_fence.cpp')
tests = read_file('tests/test_cases.md')
log = read_file('logs/run_log.md')

for keyword in ['Caesar', 'Rail Fence', 'GitHub']:
    if keyword.lower() not in readme.lower():
        errors.append(f'README.md thieu noi dung: {keyword}')

if 'TODO' in caesar.upper():
    errors.append('src/caesar.cpp van con TODO.')
if 'TODO' in rail.upper():
    errors.append('src/rail_fence.cpp van con TODO.')

if 'caesar_decrypt' not in caesar:
    errors.append('src/caesar.cpp thieu caesar_decrypt().')
if 'rail_fence_decrypt' not in rail:
    errors.append('src/rail_fence.cpp thieu rail_fence_decrypt().')
if 'read_message_from_file' not in rail:
    errors.append('src/rail_fence.cpp thieu read_message_from_file().')

if '| I LOVE YOU |' in report and ('|  |' in report or '| |' in report):
    warnings.append('report-1page.md chua dien du thong tin bang.')

def count_checked(content):
    return len(re.findall(r'^-\s*\[[xX]\]', content, flags=re.MULTILINE))

if count_checked(tests) < 6:
    errors.append('tests/test_cases.md can tick it nhat 6 o.')
if count_checked(log) < 6:
    errors.append('logs/run_log.md can tick it nhat 6 o.')

placeholders = ['Viết 3-5 dòng', 'Viet 3-5 dong', 'ngắn gọn ở đây', 'ngan gon o day']
if any(p in log for p in placeholders):
    warnings.append('logs/run_log.md van con placeholder.')

def compile_cpp(src, out):
    try:
        res = subprocess.run(['g++', '-std=c++17', '-O2', '-o', out, src], capture_output=True, text=True)
        return res.stderr if res.returncode != 0 else None
    except:
        return "g++ not found"

err1 = compile_cpp('src/caesar.cpp', 'caesar_bin')
if err1: errors.append(f'Loi bien dich caesar.cpp: {err1[:200]}')

err2 = compile_cpp('src/rail_fence.cpp', 'rail_bin')
if err2: errors.append(f'Loi bien dich rail_fence.cpp: {err2[:200]}')

if warnings:
    print('\n'.join(f'::warning::{w}' for w in warnings))

if errors:
    print('\n'.join(f'::error::{e}' for e in errors))
    sys.exit(1)

print('::notice::FIT4012 Lab 2 auto check passed.')
