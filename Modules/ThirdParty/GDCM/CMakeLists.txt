project(ITK-GDCM)

option(ITK_USE_SYSTEM_GDCM "Use an outside build of GDCM." OFF)
mark_as_advanced(ITK_USE_SYSTEM_GDCM)

if(ITK_USE_SYSTEM_GDCM)
  find_package(GDCM REQUIRED)
  set(ITK-GDCM_SYSTEM_INCLUDE_DIRS
    ${GDCM_INCLUDE_DIR}
    )
  set(ITK-GDCM_LIBRARIES  gdcmDICT gdcmMSFF )
  set(ITK-GDCM_NO_SRC 1)
else()
  set(ITK-GDCM_INCLUDE_DIRS
    ${ITK-GDCM_BINARY_DIR}
    ${ITK-GDCM_BINARY_DIR}/src/gdcm/Source/Common
    ${ITK-GDCM_SOURCE_DIR}/src/gdcm/Source/MediaStorageAndFileFormat
    ${ITK-GDCM_SOURCE_DIR}/src/gdcm/Source/DataDictionary
    ${ITK-GDCM_SOURCE_DIR}/src/gdcm/Source/Common
    ${ITK-GDCM_SOURCE_DIR}/src/gdcm/Source/InformationObjectDefinition
    ${ITK-GDCM_SOURCE_DIR}/src/gdcm/Source/MessageExchangeDefinition
    ${ITK-GDCM_SOURCE_DIR}/src/gdcm/Source/DataStructureAndEncodingDefinition
    )
  check_include_file("stdint.h"       GDCM_HAVE_STDINT_H)
  if(NOT GDCM_HAVE_STDINT_H)
    # for MSVC only gdcm has a stdint.h that works for that
    # compiler found in Utilities/C99
    if(MSVC)
      list(APPEND ITK-GDCM_INCLUDE_DIRS
        ${ITK-GDCM_SOURCE_DIR}/src/gdcm/Utilities/C99)
    endif()
  endif()
  set(ITK-GDCM_LIBRARIES  gdcmDICT gdcmMSFF )
endif()

itk_module_impl()
