__int64 __fastcall msm_cvp_disable_unprepare_clk(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x23
  const char **v5; // x21
  const char *v7; // x20
  __int64 result; // x0
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x8
  const char *v11; // x19
  __int64 v12; // x3
  unsigned __int64 v13; // x8

  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_837CA, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(a1 + 2208);
  v4 = *(_QWORD *)(v2 + 280);
  v5 = (const char **)(v4 + 32LL * (unsigned int)(*(_DWORD *)(v2 + 288) - 1));
  if ( (unsigned __int64)v5 < v4 )
  {
LABEL_5:
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v9 = _ReadStatusReg(SP_EL0);
    printk(&unk_86459, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  while ( 1 )
  {
    v7 = *v5;
    if ( !strcmp(*v5, s2) )
      break;
    v5 -= 4;
    if ( (unsigned __int64)v5 < v4 )
      goto LABEL_5;
  }
  v11 = v5[2];
  if ( v11 )
  {
    clk_disable(v5[2]);
    clk_unprepare(v11);
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      printk(&unk_93D68, &unk_8DA84, *v5, v12);
    if ( *((_BYTE *)v5 + 28) != 1 || !*(_QWORD *)(a1 + 2400) )
      return 0;
    result = msm_cvp_mmrm_set_value_in_range(a1, 0, 0);
    if ( (_DWORD)result )
    {
      result = 0;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v13 = _ReadStatusReg(SP_EL0);
        printk(&unk_83C20, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
        return 0;
      }
    }
  }
  else
  {
    result = 0;
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_83C54, &unk_8DA84, "msm_cvp_disable_unprepare_clk", v7);
      return 0;
    }
  }
  return result;
}
