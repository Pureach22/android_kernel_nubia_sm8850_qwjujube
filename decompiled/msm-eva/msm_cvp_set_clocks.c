__int64 __fastcall msm_cvp_set_clocks(__int64 a1)
{
  __int64 *v2; // x8
  __int64 (__fastcall *v3)(__int64, __int64); // x9
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 && (v2 = *(__int64 **)(a1 + 256)) != nullptr )
  {
    v3 = (__int64 (__fastcall *)(__int64, __int64))v2[13];
    if ( v3 )
    {
      v4 = *v2;
      v5 = *(unsigned int *)(a1 + 1272);
      if ( *((_DWORD *)v3 - 1) != 19073560 )
        __break(0x8229u);
      return v3(v4, v5);
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
