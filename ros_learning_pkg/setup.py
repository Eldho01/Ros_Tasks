from setuptools import find_packages, setup

package_name = 'ros_learning_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='userEmail',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "first_node = ros_learning_pkg.first_node:main",
            "news_station = ros_learning_pkg.news_station:main",
            "smart_phone = ros_learning_pkg.smart_phone:main",
            "add_twoInts = ros_learning_pkg.service:main",
        ],
    },  
)
