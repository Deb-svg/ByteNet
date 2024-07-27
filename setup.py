from setuptools import setup, Extension
import os

# Define the extension module
byte_network_module = Extension(
    'bytenet',
    sources=[
        'src/bytenet.cpp',
        'src/network.cpp'
    ],
    include_dirs=[
        'include'
    ],
    extra_compile_args=['-std=c++17']
)

setup(
    name='ByteNet',
    version='1.0.0',
    description='A high-performance network library',
    author='Your Name',
    author_email='your.email@example.com',
    url='https://github.com/yourusername/ByteNet',
    packages=['bytenet'],
    ext_modules=[byte_network_module],
    classifiers=[
        'Programming Language :: Python :: 3',
        'Programming Language :: C++',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
)
