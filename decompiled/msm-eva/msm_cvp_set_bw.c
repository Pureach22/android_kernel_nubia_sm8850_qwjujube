__int64 __fastcall msm_cvp_set_bw(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *v6; // x8
  __int64 (__fastcall *v7)(__int64, __int64, __int64, __int64, __int64, __int64); // x9
  __int64 v8; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 && (v6 = *(__int64 **)(a1 + 256)) != nullptr )
  {
    v7 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64))v6[14];
    if ( v7 )
    {
      v8 = *v6;
      if ( *((_DWORD *)v7 - 1) != 1936473550 )
        __break(0x8229u);
      return v7(v8, a2, a3, a4, a5, a1);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_95C3F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
