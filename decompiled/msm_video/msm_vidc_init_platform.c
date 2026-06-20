__int64 __fastcall msm_vidc_init_platform(__int64 *a1)
{
  __int64 v1; // x22
  char **v3; // x8
  __int64 (__fastcall *v4)(__int64); // x8
  __int64 result; // x0
  unsigned int v6; // w19

  v1 = *a1;
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_init_platform");
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v1 + 760), "qcom,canoe-vidc") )
  {
    v3 = &compat_handle;
LABEL_9:
    v4 = (__int64 (__fastcall *)(__int64))v3[2];
    if ( *((_DWORD *)v4 - 1) != -1850880742 )
      __break(0x8228u);
    result = v4((__int64)a1);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v6 = result;
        printk(&unk_951EC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_platform");
        return v6;
      }
    }
    return result;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v1 + 760), "qcom,canoe-vidc-v2") )
  {
    v3 = &off_99300;
    goto LABEL_9;
  }
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v1 + 760), "qcom,alor-vidc") )
  {
    v3 = &off_99320;
    goto LABEL_9;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_80D43, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_init_platform");
  return 4294967274LL;
}
