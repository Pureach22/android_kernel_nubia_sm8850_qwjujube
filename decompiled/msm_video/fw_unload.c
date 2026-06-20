__int64 __fastcall fw_unload(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  unsigned int v4; // w20

  v2 = *(unsigned int *)(*(_QWORD *)(a1 + 3904) + 144LL);
  if ( (_DWORD)v2 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_84B7D, "high", 0xFFFFFFFFLL, "codec", "fw_unload");
      result = qcom_scm_pas_shutdown(*(unsigned int *)(*(_QWORD *)(a1 + 3904) + 144LL));
      if ( (_DWORD)result )
      {
LABEL_4:
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v4 = result;
          printk(&unk_801B5, "err ", 0xFFFFFFFFLL, "codec", (unsigned int)result);
          result = v4;
        }
      }
    }
    else
    {
      result = qcom_scm_pas_shutdown(v2);
      if ( (_DWORD)result )
        goto LABEL_4;
    }
    *(_DWORD *)(*(_QWORD *)(a1 + 3904) + 144LL) = 0;
    return result;
  }
  return 4294967274LL;
}
