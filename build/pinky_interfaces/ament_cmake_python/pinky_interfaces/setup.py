from setuptools import find_packages
from setuptools import setup

setup(
    name='pinky_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('pinky_interfaces', 'pinky_interfaces.*')),
)
