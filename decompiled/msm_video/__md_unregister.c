__int64 __fastcall _md_unregister(__int64 a1)
{
  __int64 result; // x0

  if ( !*(_QWORD *)(a1 + 4688) )
    return 0;
  if ( (qcom_va_md_enabled() & 1) == 0 )
    return 0;
  result = qcom_va_md_unregister("msm_vidc", &_md_nb);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_90C57, "err ", 0xFFFFFFFFLL, "codec", "__md_unregister");
    return 4294967274LL;
  }
  return result;
}
