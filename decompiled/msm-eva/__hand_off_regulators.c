__int64 __fastcall _hand_off_regulators(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v2; // x23
  int v4; // w22
  __int64 result; // x0
  __int64 v6; // x3
  unsigned __int64 v7; // x8
  _QWORD *v8; // x20
  unsigned int v9; // w21
  unsigned __int64 StatusReg; // x8
  unsigned int v11; // w20

  v1 = *(_QWORD *)(a1 + 2208);
  v2 = *(_QWORD *)(v1 + 264);
  if ( v2 >= v2 + 24LL * *(unsigned int *)(v1 + 272) )
    return 0;
  v4 = 0;
  while ( *(_BYTE *)(v2 + 8) != 1 )
  {
LABEL_3:
    v2 += 24LL;
    ++v4;
    if ( v2 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 264LL)
             + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 272LL) )
      return 0;
  }
  result = regulator_set_mode(*(_QWORD *)v2, 1);
  if ( !(_DWORD)result )
  {
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      printk(&unk_83794, &unk_8DA84, *(_QWORD *)(v2 + 16), v6);
    goto LABEL_3;
  }
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = result;
    printk(&unk_874A0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    result = v11;
  }
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 264LL);
  v8 = (_QWORD *)(v7 + 24LL * v4);
  if ( (unsigned __int64)v8 >= v7 )
  {
    v9 = result;
    do
    {
      _acquire_regulator(v8, a1);
      v8 -= 3;
    }
    while ( (unsigned __int64)v8 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 264LL) );
    return v9;
  }
  return result;
}
