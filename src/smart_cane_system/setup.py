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
        'camera_node = smart_cane_system.camera_node:main',
        'yolo_detection_node = smart_cane_system.yolo_detection_node:main',
        'ultrasonic_node = smart_cane_system.ultrasonic_node:main',
        'obstacle_fusion_node = smart_cane_system.obstacle_fushion:main',
        'speaker_node = smart_cane_system.speaker_node:main',
        'vibration_node = smart_cane_system.vibration_node:main',
   	 ],
	},
)
