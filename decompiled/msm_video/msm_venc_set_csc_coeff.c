__int64 __fastcall msm_venc_set_csc_coeff(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 v10; // x23
  __int64 result; // x0
  unsigned int v12; // w20

  if ( !a1 )
    return venus_hfi_session_property(0, a3, 0, 1, 12, a4, a5);
  v10 = a1;
  if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_8FA1A, "high", a1 + 340, a2, a6);
    a1 = v10;
  }
  result = venus_hfi_session_property(a1, a3, 0, 1, 12, a4, a5);
  if ( (_DWORD)result )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v12 = result;
      printk(&unk_83132, "err ", v10 + 340, "msm_venc_set_csc_coeff", a2);
      return v12;
    }
  }
  return result;
}
