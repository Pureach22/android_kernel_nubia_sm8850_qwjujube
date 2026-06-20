__int64 __fastcall clk_rate_set(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x8
  __int64 *v3; // x19
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x0
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x1
  unsigned int v10; // w9
  unsigned __int64 StatusReg; // x8

  v2 = *(_QWORD *)(cvp_driver + 48);
  v3 = *(__int64 **)(v2 + 256);
  if ( a2 )
  {
    v4 = *(unsigned int *)(v2 + 776);
    v5 = *(_QWORD *)(v2 + 768);
    if ( (_DWORD)v4 )
    {
      v6 = 0;
      while ( *(unsigned int *)(v5 + 4 * v6) < a2 )
      {
        if ( v4 == ++v6 )
        {
          LODWORD(v6) = v4;
          break;
        }
      }
    }
    else
    {
      LODWORD(v6) = 0;
    }
    if ( (_DWORD)v6 == (_DWORD)v4 )
      v10 = v4 - 1;
    else
      v10 = v6;
    msm_cvp_clock_voting = *(_DWORD *)(v5 + 4LL * v10);
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8D48A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      if ( !v3 )
        return 0;
    }
    else if ( !v3 )
    {
      return 0;
    }
    v8 = (void (__fastcall *)(__int64, __int64))v3[13];
    if ( !v8 )
      return 0;
    v7 = *v3;
    v9 = (unsigned int)msm_cvp_clock_voting;
  }
  else
  {
    v7 = *v3;
    msm_cvp_clock_voting = 0;
    if ( !v3 )
      return 0;
    v8 = (void (__fastcall *)(__int64, __int64))v3[13];
    if ( !v8 )
      return 0;
    v9 = *(unsigned int *)(v7 + 24);
  }
  if ( *((_DWORD *)v8 - 1) != 19073560 )
    __break(0x8228u);
  v8(v7, v9);
  return 0;
}
