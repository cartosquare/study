# SKIA_ROOT should be set
#set(SKIA_ROOT "" CACHE PATH "Skia root directory")
set(SKIA_ROOT C:/passport/workspace/skia)

# Set include directories
FILE(GLOB SKIA_INCLUDES_A ${SKIA_ROOT}/include ${SKIA_ROOT}/include/*)
FILE(GLOB SKIA_INCLUDES_B ${SKIA_ROOT}/src ${SKIA_ROOT}/src/*)
set(SKIA_INCLUDE_DIRS ${SKIA_INCLUDES_A} ${SKIA_INCLUDES_B})

# List link libraries
	file(GLOB SKIA_LIBRARIES_A ${SKIA_ROOT}/out/Release_Developer/*.lib)
	file(GLOB SKIA_LIBRARIES_B ${SKIA_ROOT}/out/Release_Developer/obj/gyp/*.lib)
	set(SKIA_LIBRARIES
		${SKIA_LIBRARIES_A} 
		${SKIA_LIBRARIES_B} 
		ws2_32.lib 
		OpenGL32.lib
		usp10.lib
		kernel32.lib
		gdi32.lib
		winspool.lib
		comdlg32.lib
		advapi32.lib
		shell32.lib
		ole32.lib
		oleaut32.lib
		user32.lib
		uuid.lib
		odbc32.lib
		odbccp32.lib
		DelayImp.lib
		windowscodecs.lib
		)


message(STATUS "SKIA_INCLUDE_DIRS:${SKIA_INCLUDE_DIRS}")
message(STATUS "SKIA_LIBRARIES:${SKIA_LIBRARIES}")