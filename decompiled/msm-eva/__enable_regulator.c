__int64 __fastcall _enable_regulator(__int64 a1, char *s2)
{
  __int64 v2; // x8
  _QWORD *v4; // x20
  _QWORD *v5; // x21
  __int64 result; // x0
  unsigned __int64 v7; // x8
  unsigned int v8; // w19
  __int64 v9; // x3
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x8

  v2 = *(_QWORD *)(a1 + 2208);
  v4 = *(_QWORD **)(v2 + 264);
  v5 = &v4[3 * *(unsigned int *)(v2 + 272)];
  if ( v4 >= v5 )
  {
LABEL_4:
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_8F375, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  while ( strcmp((const char *)v4[2], s2) )
  {
    v4 += 3;
    if ( v4 >= v5 )
      goto LABEL_4;
  }
  result = regulator_enable(*v4);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = _ReadStatusReg(SP_EL0);
      v8 = result;
      printk(&unk_857BA, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
      return v8;
    }
    return result;
  }
  if ( !(unsigned int)regulator_is_enabled(*v4) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      printk(&unk_88A92, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
    }
    regulator_disable(*v4);
    return 4294967274LL;
  }
  result = 0;
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_824BF, &unk_8DA84, v4[2], v9);
    return 0;
  }
  return result;
}
