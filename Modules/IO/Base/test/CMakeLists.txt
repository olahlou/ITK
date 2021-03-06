itk_module_test()
set(ITK-IO-BaseTests
itkImageFileReaderTest1.cxx
itkImageFileWriterTest.cxx
itkIOBaseHeaderTest.cxx
itkIOCommonTest.cxx
itkNumericSeriesFileNamesTest.cxx
itkRegularExpressionSeriesFileNamesTest.cxx
itkArchetypeSeriesFileNamesTest.cxx
itkImageFileReaderDimensionsTest.cxx
itkImageFileReaderStreamingTest.cxx
itkImageFileReaderStreamingTest2.cxx
itkImageFileWriterPastingTest1.cxx
itkImageFileWriterPastingTest2.cxx
itkImageFileWriterPastingTest3.cxx
itkImageFileWriterStreamingPastingCompressingTest1.cxx
itkImageFileWriterStreamingTest1.cxx
itkImageFileWriterStreamingTest2.cxx
itkImageFileWriterTest2.cxx
itkImageFileWriterUpdateLargestPossibleRegionTest.cxx
itkImageIOBaseTest.cxx
itkImageIODirection2DTest.cxx
itkImageIODirection3DTest.cxx
itkImageIOFileNameExtensionsTests.cxx
)

CreateTestDriver(ITK-IO-Base  "${ITK-IO-Base-Test_LIBRARIES}" "${ITK-IO-BaseTests}")
add_test(NAME itkArchetypeSeriesFileNamesTest
      COMMAND ITK-IO-BaseTestDriver
    itkArchetypeSeriesFileNamesTest
    ${ITK_DATA_ROOT}/Input/Archetype/a5b7.PNG
    ${ITK_DATA_ROOT}/Input/Archetype/a7b1.PNG)
add_test(NAME itkArchetypeSeriesFileNamesTest2
      COMMAND ITK-IO-BaseTestDriver
    itkArchetypeSeriesFileNamesTest
    ${ITK_DATA_ROOT}/Input/Archetype/image.001
    ${ITK_DATA_ROOT}/Input/Archetype/image.010)
add_test(NAME itkIOBaseHeaderTest
      COMMAND ITK-IO-BaseTestDriver itkIOBaseHeaderTest)
add_test(NAME itkImageFileReaderTest1
      COMMAND ITK-IO-BaseTestDriver itkImageFileReaderTest1)
add_test(NAME itkImageFileWriterTest
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterTest
              ${ITK_TEST_OUTPUT_DIR}/test.png)
add_test(NAME itkIOCommonTest
      COMMAND ITK-IO-BaseTestDriver itkIOCommonTest)
add_test(NAME itkNumericSeriesFileNamesTest
      COMMAND ITK-IO-BaseTestDriver itkNumericSeriesFileNamesTest)
add_test(NAME itkRegularExpressionSeriesFileNamesTest
      COMMAND ITK-IO-BaseTestDriver itkRegularExpressionSeriesFileNamesTest
              ${ITK_DATA_ROOT}/Input)
add_test(NAME itkImageFileReaderDimensionsTest_MHD
      COMMAND ITK-IO-BaseTestDriver itkImageFileReaderDimensionsTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR} mha)
add_test(NAME itkImageFileReaderDimensionsTest_NRRD
      COMMAND ITK-IO-BaseTestDriver itkImageFileReaderDimensionsTest
              ${ITK_DATA_ROOT}/Input/vol-ascii.nrrd ${ITK_TEST_OUTPUT_DIR} nrrd)
add_test(NAME itkImageFileReaderStreamingTest_1
      COMMAND ITK-IO-BaseTestDriver itkImageFileReaderStreamingTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd 1 0)
add_test(NAME itkImageFileReaderStreamingTest_2
      COMMAND ITK-IO-BaseTestDriver itkImageFileReaderStreamingTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd 0 1)
add_test(NAME itkImageFileReaderStreamingTest_3
      COMMAND ITK-IO-BaseTestDriver itkImageFileReaderStreamingTest
              ${ITK_DATA_ROOT}/Input/vol-ascii.nrrd 0 0)
add_test(NAME itkImageFileReaderStreamingTest2_MHD
      COMMAND ITK-IO-BaseTestDriver itkImageFileReaderStreamingTest2
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd)
add_test(NAME itkImageFileWriterPastingTest1
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Baseline/IO/HeadMRVolume.mhd
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterPastingTest1_01.mha
    itkImageFileWriterPastingTest1 ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterPastingTest1_01.mha)
add_test(NAME itkImageFileWriterPastingTest2_5
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterPastingTest2
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterPastingTest2_5.mha)
add_test(NAME itkImageFileWriterPastingTest2_6
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Baseline/IO/HeadMRVolume.mhd
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterPastingTest2_6.mha
    itkImageFileWriterPastingTest2 ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterPastingTest2_6.mha ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha)
add_test(NAME itkImageFileWriterPastingTest2_7
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterPastingTest2
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterPastingTest2_7.mha ${ITK_DATA_ROOT}/Input/HeadMRVolumeCompressed.mha)
add_test(NAME itkImageFileWriterPastingTest3
      COMMAND ITK-IO-BaseTestDriver
    itkImageFileWriterPastingTest3
            ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd
            ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterPastingTest3_01.mha)
add_test(NAME itkImageFileWriterStreamingPastingCompressingTest_MHA
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterStreamingPastingCompressingTest1
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreamingPastingCompressingTest mha 0 0 0 1 0 0 0 1)
add_test(NAME itkImageFileWriterStreamingPastingCompressingTest_NRRD
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterStreamingPastingCompressingTest1
              ${ITK_DATA_ROOT}/Input/vol-ascii.nrrd ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreamingPastingCompressingTest nrrd 0 0 1 1 0 0 1 1)
add_test(NAME itkImageFileWriterStreamingPastingCompressingTest_NHDR
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterStreamingPastingCompressingTest1
              ${ITK_DATA_ROOT}/Input/vol-ascii.nrrd ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreamingPastingCompressingTest nhdr 0 0 1 1 0 0 1 1)
add_test(NAME itkImageFileWriterStreamingPastingCompressingTest_VTK
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreamingPastingCompressingTest000.vtk
    itkImageFileWriterStreamingPastingCompressingTest1 ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreamingPastingCompressingTest vtk 0 0 0 0 0 0 0 0)
add_test(NAME itkImageFileWriterStreamingPastingCompressingTest_DCM
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterStreamingPastingCompressingTest1
              ${ITK_DATA_ROOT}/Input/HeadMRVolume.mhd ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreamingPastingCompressingTest dcm 0 0 1 1 0 0 1 1)
add_test(NAME itkImageFileWriterStreamingTest1_1
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Baseline/IO/HeadMRVolume.mhd
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming1_1.mha
    itkImageFileWriterStreamingTest1 ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming1_1.mha)
add_test(NAME itkImageFileWriterStreamingTest1_2
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Baseline/IO/HeadMRVolume.mhd
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming1_2.mha
    itkImageFileWriterStreamingTest1 ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming1_2.mha ${ITK_DATA_ROOT}/Input/HeadMRVolumeCompressed.mha 0)
add_test(NAME itkImageFileWriterStreamingTest1_3
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Baseline/IO/HeadMRVolume.mhd
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming1_3.mha
    itkImageFileWriterStreamingTest1 ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming1_3.mha ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha 1)
add_test(NAME itkImageFileWriterStreamingTest2_4
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Baseline/IO/HeadMRVolume.mhd
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming2_4.mha
    itkImageFileWriterStreamingTest2 ${ITK_DATA_ROOT}/Input/HeadMRVolume.mha ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterStreaming2_4.mha)
add_test(NAME itkImageFileWriterTest2_1
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterTest2
              ${ITK_TEST_OUTPUT_DIR}/test.nrrd)
add_test(NAME itkImageFileWriterTest2_2
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterTest2
              ${ITK_TEST_OUTPUT_DIR}/test.mha)
add_test(NAME itkImageFileWriterTest2_3
      COMMAND ITK-IO-BaseTestDriver itkImageFileWriterTest2
              ${ITK_TEST_OUTPUT_DIR}/test.vtk)
add_test(NAME itkImageFileWriterUpdateLargestPossibleRegionTest
      COMMAND ITK-IO-BaseTestDriver
    --compare ${ITK_DATA_ROOT}/Input/cthead1.png
              ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterUpdateLargestPossibleRegionTest.png
    itkImageFileWriterUpdateLargestPossibleRegionTest ${ITK_DATA_ROOT}/Input/cthead1.png ${ITK_TEST_OUTPUT_DIR}/itkImageFileWriterUpdateLargestPossibleRegionTest.png)
add_test(NAME itkImageIOBaseTest
      COMMAND ITK-IO-BaseTestDriver itkImageIOBaseTest)
add_test(NAME itkImageIODirection2DTest01
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceBorder20.png 1.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceBorder20.mhd)
add_test(NAME itkImageIODirection2DTest02
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceShifted13x17y.png 1.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceShifted13x17y.mhd)
add_test(NAME itkImageIODirection2DTest03
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceBorder20DirectionPlus30.mhd 0.8660254 -0.5 0.5 0.8660254 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceBorder20DirectionPlus30.mhd)
add_test(NAME itkImageIODirection2DTest04
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceShifted13x17yDirectionPlus30.mhd 0.8660254 -0.5 0.5 0.8660254 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceShifted13x17yDirectionPlus30.mhd)
add_test(NAME itkImageIODirection2DTest05
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainT1SliceBorder20DirectionPlus30.mhd 0.8660254 -0.5 0.5 0.8660254 ${ITK_TEST_OUTPUT_DIR}/BrainT1SliceBorder20DirectionPlus30.mhd)
add_test(NAME itkImageIODirection2DTest06
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceBorder20.mhd 1.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceBorder20.nhdr)
add_test(NAME itkImageIODirection2DTest07
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceShifted13x17y.mhd 1.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceShifted13x17y.nhdr)
add_test(NAME itkImageIODirection2DTest08
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceBorder20DirectionPlus30.mhd 0.8660254 -0.5 0.5 0.8660254 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceBorder20DirectionPlus30.nhdr)
add_test(NAME itkImageIODirection2DTest09
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceShifted13x17yDirectionPlus30.mhd 0.8660254 -0.5 0.5 0.8660254 ${ITK_TEST_OUTPUT_DIR}/BrainProtonDensitySliceShifted13x17yDirectionPlus30.nhdr)
add_test(NAME itkImageIODirection2DTest10
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainT1SliceBorder20DirectionPlus30.mhd 0.8660254 -0.5 0.5 0.8660254 ${ITK_TEST_OUTPUT_DIR}/BrainT1SliceBorder20DirectionPlus30.nhdr)
add_test(NAME itkImageIODirection2DTest11
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceBorder20.nhdr 1.0 0.0 0.0 1.0)
add_test(NAME itkImageIODirection2DTest12
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceShifted13x17y.nhdr 1.0 0.0 0.0 1.0)
add_test(NAME itkImageIODirection2DTest13
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceBorder20DirectionPlus30.nhdr 0.8660254 -0.5 0.5 0.8660254)
add_test(NAME itkImageIODirection2DTest14
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainProtonDensitySliceShifted13x17yDirectionPlus30.nhdr 0.8660254 -0.5 0.5 0.8660254)
add_test(NAME itkImageIODirection2DTest15
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection2DTest
              ${ITK_SOURCE_DIR}/Examples/Data/BrainT1SliceBorder20DirectionPlus30.nhdr 0.8660254 -0.5 0.5 0.8660254)
add_test(NAME itkImageIODirection3DTest01
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirectionIdentity.mhd 1.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/HeadMRVolumeWithDirectionIdentity.mhd)
add_test(NAME itkImageIODirection3DTest02
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirection.mhd 0.8660254 0.5 0.0 -0.5 0.8660254 0.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/HeadMRVolumeWithDirection.mhd)
add_test(NAME itkImageIODirection3DTest03
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirectionIdentity.mhd 1.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/HeadMRVolumeWithDirectionIdentity.nhdr)
add_test(NAME itkImageIODirection3DTest04
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirection.mhd 0.8660254 0.5 0.0 -0.5 0.8660254 0.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/HeadMRVolumeWithDirection.nhdr)
add_test(NAME itkImageIODirection3DTest05
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirectionIdentity.nhdr 1.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 1.0)
add_test(NAME itkImageIODirection3DTest06
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirection.nhdr 0.8660254 0.5 0.0 -0.5 0.8660254 0.0 0.0 0.0 1.0)
add_test(NAME itkImageIODirection3DTest07
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirection001.mhd 1.0 0.0 0.0 0.0 -1.0 0.0 0.0 0.0 1.0 ${ITK_TEST_OUTPUT_DIR}/HeadMRVolumeWithDirection001.nhdr)
add_test(NAME itkImageIODirection3DTest08
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirection002.mhd 1.0 0.0 0.0 0.0 0.0 01.0 0.0 -1.0 0.0 ${ITK_TEST_OUTPUT_DIR}/HeadMRVolumeWithDirection002.nhdr)
add_test(NAME itkImageIODirection3DTest09
      COMMAND ITK-IO-BaseTestDriver itkImageIODirection3DTest
              ${ITK_DATA_ROOT}/Input/HeadMRVolumeWithDirection003.mhd 0.0 -1.0 0.0 0.0 0.0 1.0 1.0 0.0 0.0 ${ITK_TEST_OUTPUT_DIR}/HeadMRVolumeWithDirection003.nhdr)
add_test(NAME itkImageIOFileNameExtensionsTests
      COMMAND ITK-IO-BaseTestDriver itkImageIOFileNameExtensionsTests)
