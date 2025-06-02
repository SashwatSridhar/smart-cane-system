from setuptools import find_packages, setup
from glob import glob
package_name = 'smart_cane_system'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sash',
    maintainer_email='sash@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'ultrasonic_node = smart_cane_system.ultrasonic_node:main',
            'camera_node = smart_cane_system.camera_node:main',
            'detection_node = smart_cane_system.detection_node:main',
            'feedback_node = smart_cane_system.feedback_node:main',
        ],
    },
)
