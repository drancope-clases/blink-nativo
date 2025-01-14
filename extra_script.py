Import("env")
env.Append(LINKFLAGS=['-framework', 'Cocoa', '-framework', 'OpenGL'])