__int64 __fastcall cvp_power_set(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x9
  __int64 *v3; // x8
  __int64 v4; // x10
  __int64 (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v9; // w19

  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(__int64 **)(v2 + 256);
  if ( !v3 )
    return 4294967274LL;
  v4 = *v3;
  if ( !*v3 )
    return 4294967274LL;
  if ( a2 < 0xF4240 )
  {
    if ( a2 >= 0x3E9 )
    {
      *(_BYTE *)(*(_QWORD *)(v4 + 2208) + 329LL) = 1;
      *(_DWORD *)(*(_QWORD *)(v4 + 2208) + 432LL) = a2;
    }
  }
  else
  {
    *(_BYTE *)(*(_QWORD *)(v4 + 2208) + 329LL) = 0;
  }
  if ( !*(_DWORD *)(v2 + 304) )
    return 4294967274LL;
  if ( !a2 )
    return 0;
  v5 = (__int64 (__fastcall *)(_QWORD))v3[19];
  if ( !v5 )
    return 0;
  v6 = *v3;
  if ( *((_DWORD *)v5 - 1) != -1066802076 )
    __break(0x8229u);
  result = v5(v6);
  if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = result;
    printk(&unk_82A17, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return v9;
  }
  return result;
}
