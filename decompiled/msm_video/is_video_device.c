bool __fastcall is_video_device(__int64 a1)
{
  return (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sm8450-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sm8550-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sm8550-vidc-v2")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sa8255-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sm8650-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sm8650-vidc-v2")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,cliffs-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,volcano-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sm8750-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sm8750-vidc-v2")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,canoe-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,canoe-vidc-v2")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,seraph-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,sa8797-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,niobe-vidc")
      || (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,alor-vidc") != 0;
}
