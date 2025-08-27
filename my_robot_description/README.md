
## URDF(Unified Robot Description Format)

- This is an *xml* file used to describe the physical and kinematic properties of a robot.
- It defines things like :
    + Links
        - Visual
        - Inertial
        - Collision
        [more info.](https://wiki.ros.org/urdf/XML/link)
    + Joints
        - Parent
        - Child
        - Axis
        - Limit etc.
        [more info.](https://wiki.ros.org/urdf/XML/joint)

### XACRO (*xmlMacro*)

- This is used to write **urdf** with little redundency
- This format allow to use
    + Constants
    + Math
    + Macros

- To use *xacro* we need to properly specify the namespace correctly

    >   1. <?xml version="1.0"?>
    >   2. <robot xmlns:xacro="http://www.ros.org/wiki/xacro" name="firefighter"> ...

- [more info.](https://wiki.ros.org/xacro)

### Rviz

- [visualisation tool](https://wiki.ros.org/rviz)
- we can lauch rviz with pre-configured window using config file
- when in gui the TFs shown will have a color scheme like
    + x axis : red
    + y axis : green
    + z axis : bule