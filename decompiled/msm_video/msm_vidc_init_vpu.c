__int64 __fastcall msm_vidc_init_vpu(__int64 *a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  unsigned int v4; // w20

  v1 = *a1;
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*a1 + 760), "qcom,canoe-vidc")
    || (unsigned int)of_device_is_compatible(*(_QWORD *)(v1 + 760), "qcom,canoe-vidc-v2")
    || (unsigned int)of_device_is_compatible(*(_QWORD *)(v1 + 760), "qcom,alor-vidc") )
  {
    result = msm_vidc_init_iris4(a1);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v4 = result;
        printk(&unk_951EC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_vpu");
        return v4;
      }
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_80D43, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_vpu");
    return 4294967274LL;
  }
  return result;
}
