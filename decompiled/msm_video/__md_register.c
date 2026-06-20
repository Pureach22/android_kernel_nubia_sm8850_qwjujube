__int64 __fastcall _md_register(__int64 a1)
{
  __int64 result; // x0

  if ( !*(_QWORD *)(a1 + 4688) )
    return 0;
  if ( (qcom_va_md_enabled() & 1) == 0 )
    return 0;
  result = qcom_va_md_register("msm_vidc", &_md_nb);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8CDBB, "err ", 0xFFFFFFFFLL, "codec", "__md_register");
    return 4294967274LL;
  }
  return result;
}
