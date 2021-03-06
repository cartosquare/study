set(SKIA_ROOT /Users/xuxiang/git_projects/skia/)
set(SKIA_LIB_DIR ${SKIA_ROOT}/out/Release)

message(STATUS "SKIA_ROOT: ${SKIA_ROOT}")
message(STATUS "SKIA_LIB_DIR: ${SKIA_LIB_DIR}")

set(SKIA_INCLUDE_DIRS 
"${SKIA_ROOT}/include/config"
"${SKIA_ROOT}/include/animator"
"${SKIA_ROOT}/include/core"
"${SKIA_ROOT}/include/device"
"${SKIA_ROOT}/include/effects"
"${SKIA_ROOT}/include/gpu"
"${SKIA_ROOT}/include/images"
"${SKIA_ROOT}/src/pathops"
"${SKIA_ROOT}/include/pdf"
"${SKIA_ROOT}/include/pipe"
"${SKIA_ROOT}/include/ports"
"${SKIA_ROOT}/include/record"
"${SKIA_ROOT}/include/svg"
"${SKIA_ROOT}/include/utils"
"${SKIA_ROOT}/include/views"
"${SKIA_ROOT}/include/xml"
"${SKIA_ROOT}/src/animator"
"${SKIA_ROOT}/src/core"	
"${SKIA_ROOT}/src/device"
"${SKIA_ROOT}/src/effects"
"${SKIA_ROOT}/src/gpu"
"${SKIA_ROOT}/src/images"
"${SKIA_ROOT}/src/image"
"${SKIA_ROOT}/src/lazy"
"${SKIA_ROOT}/include/opts"
"${SKIA_ROOT}/include/pathops"
"${SKIA_ROOT}/src/pdf"
"${SKIA_ROOT}/src/pipe"
"${SKIA_ROOT}/src/ports"
"${SKIA_ROOT}/src/sfnt"
"${SKIA_ROOT}/src/svg"
"${SKIA_ROOT}/src/utils"
"${SKIA_ROOT}/src/views"
"${SKIA_ROOT}/src/xml"
)
 
set(SKIA_LIBRARIES
    "${SKIA_LIB_DIR}/libcrash_handler.a"
    "${SKIA_LIB_DIR}/libetc1.a"
    "${SKIA_LIB_DIR}/libexperimental.a"
    "${SKIA_LIB_DIR}/libflags_common.a"
    "${SKIA_LIB_DIR}/libflags.a"
	"${SKIA_LIB_DIR}/libjpeg.a"
	"${SKIA_LIB_DIR}/libpng.a"
    "${SKIA_LIB_DIR}/libzlib.a"
    #"${SKIA_LIB_DIR}/libjsoncpp.a"
    "${SKIA_LIB_DIR}/libpicture_utils.a"
    "${SKIA_LIB_DIR}/libresources.a"
    "${SKIA_LIB_DIR}/libsk_tool_utils.a"
    "${SKIA_LIB_DIR}/libskflate.a"
    "${SKIA_LIB_DIR}/libskia_core.a"
    "${SKIA_LIB_DIR}/libskia_effects.a"
    "${SKIA_LIB_DIR}/libskia_images.a"
    "${SKIA_LIB_DIR}/libskia_opts_sse4.a"
	"${SKIA_LIB_DIR}/libskia_opts_ssse3.a"
    "${SKIA_LIB_DIR}/libskia_opts.a"
    "${SKIA_LIB_DIR}/libskia_pdf.a"
    "${SKIA_LIB_DIR}/libskia_ports.a"
    "${SKIA_LIB_DIR}/libskia_sfnt.a"
    "${SKIA_LIB_DIR}/libskia_skgpu.a"
    "${SKIA_LIB_DIR}/libskia_skgputest.a"
    "${SKIA_LIB_DIR}/libskia_utils.a"
    "${SKIA_LIB_DIR}/libSKKTX.a"
    "${SKIA_LIB_DIR}/libwebp_dec.a"
    "${SKIA_LIB_DIR}/libwebp_demux.a"
    "${SKIA_LIB_DIR}/libwebp_dsp.a"
    "${SKIA_LIB_DIR}/libwebp_enc.a"
    "${SKIA_LIB_DIR}/libwebp_utils.a"
     "-framework Foundation" "-framework Cocoa"
)