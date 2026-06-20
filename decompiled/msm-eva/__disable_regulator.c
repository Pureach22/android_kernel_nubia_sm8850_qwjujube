__int64 __fastcall _disable_regulator(__int64 a1, char *s2)
{
  __int64 v2; // x9
  unsigned __int64 v4; // x23
  _QWORD *v5; // x21
  const char *v7; // x22
  __int64 v8; // x3
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x8
  int v12; // w0
  __int16 v13; // w9
  int v14; // w8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8

  v2 = *(_QWORD *)(a1 + 2208);
  v4 = *(_QWORD *)(v2 + 264);
  v5 = (_QWORD *)(v4 + 24LL * (unsigned int)(*(_DWORD *)(v2 + 272) - 1));
  if ( (unsigned __int64)v5 < v4 )
  {
LABEL_4:
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_939F2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
    return result;
  }
  while ( 1 )
  {
    v7 = (const char *)v5[2];
    if ( !strcmp(v7, s2) )
      break;
    v5 -= 3;
    if ( (unsigned __int64)v5 < v4 )
      goto LABEL_4;
  }
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_84D55, &unk_8DA84, v7, v8);
  if ( (unsigned int)_acquire_regulator(v5, a1) )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v11 = _ReadStatusReg(SP_EL0);
      printk(&unk_91346, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), "warn");
    }
LABEL_18:
    v13 = msm_cvp_debug;
    v14 = msm_cvp_debug_out;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 2208) + 376LL) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v15 = _ReadStatusReg(SP_EL0);
        printk(&unk_8E7D2, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
      }
      __break(0x800u);
      v13 = msm_cvp_debug;
      v14 = msm_cvp_debug_out;
    }
    goto LABEL_23;
  }
  v12 = regulator_disable(*v5);
  v13 = msm_cvp_debug;
  v14 = msm_cvp_debug_out;
  if ( v12 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      printk(&unk_8601B, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), "warn");
    }
    goto LABEL_18;
  }
LABEL_23:
  result = 0;
  if ( (v13 & 0x400) != 0 && !v14 )
  {
    printk(&unk_9131C, &unk_8DA84, "__disable_regulator", s2);
    return 0;
  }
  return result;
}
