from setuptools import find_packages
from setuptools import setup

setup(
    name='smart_cane_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('smart_cane_interfaces', 'smart_cane_interfaces.*')),
)
