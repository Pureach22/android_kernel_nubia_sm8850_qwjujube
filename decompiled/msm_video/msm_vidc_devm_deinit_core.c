__int64 __fastcall msm_vidc_devm_deinit_core(__int64 result)
{
  __int64 v1; // x19
  char v2; // w8
  __int64 v3; // x0
  _QWORD *v4; // x19

  v1 = result;
  v2 = msm_vidc_debug;
  if ( (msm_vidc_debug & 2) != 0 )
  {
    result = printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_devm_deinit_core");
    v2 = msm_vidc_debug;
    if ( v1 )
      goto LABEL_3;
  }
  else if ( result )
  {
LABEL_3:
    if ( (v2 & 2) != 0 )
      printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_deinitialize_core");
    msm_vidc_update_core_state(v1, 0, "msm_vidc_deinitialize_core");
    v3 = *(_QWORD *)(v1 + 6224);
    if ( v3 )
      destroy_workqueue(v3);
    result = *(_QWORD *)(v1 + 6216);
    v4 = (_QWORD *)(v1 + 6216);
    if ( result )
      result = destroy_workqueue(result);
    *v4 = 0;
    v4[1] = 0;
    return result;
  }
  if ( (v2 & 1) != 0 )
    return printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_deinitialize_core");
  return result;
}
