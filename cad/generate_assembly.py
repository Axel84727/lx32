import FreeCAD as App
import Part

doc = App.newDocument("Assembly")

# Base
base = Part.makeBox(100, 60, 5)

# FPGA (Tang Primer aprox)
fpga = Part.makeBox(60, 40, 10)
fpga.translate(App.Vector(-30, -20, 5))

# OLED (0.96 aprox)
oled = Part.makeBox(27, 27, 5)
oled.translate(App.Vector(30, -13, 5))

assembly = base.fuse(fpga).fuse(oled)

Part.show(assembly)

doc.recompute()
