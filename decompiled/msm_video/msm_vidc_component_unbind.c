__int64 __fastcall msm_vidc_component_unbind(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0

  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_96554, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_component_unbind");
  v2 = *(_QWORD *)(a1 + 744);
  if ( (unsigned int)of_device_is_compatible(v2, "qcom,vidc,cb-sec-pxl") )
    return msm_dma_unmap_all_for_dev(a1);
  if ( (unsigned int)of_device_is_compatible(v2, "qcom,vidc,cb-sec-bitstream") )
    return msm_dma_unmap_all_for_dev(a1);
  if ( (unsigned int)of_device_is_compatible(v2, "qcom,vidc,cb-sec-non-pxl") )
    return msm_dma_unmap_all_for_dev(a1);
  if ( (unsigned int)of_device_is_compatible(v2, "qcom,vidc,cb-ns") )
    return msm_dma_unmap_all_for_dev(a1);
  if ( (unsigned int)of_device_is_compatible(v2, "qcom,vidc,cb-ns-bitstream") )
    return msm_dma_unmap_all_for_dev(a1);
  result = of_device_is_compatible(v2, "qcom,vidc,cb-ns-pxl");
  if ( (_DWORD)result )
    return msm_dma_unmap_all_for_dev(a1);
  return result;
}
