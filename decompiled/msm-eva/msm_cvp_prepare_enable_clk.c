__int64 __fastcall msm_cvp_prepare_enable_clk(__int64 a1, char *s2)
{
  __int64 v2; // x8
  const char **v4; // x21
  const char **v5; // x23
  const char *v7; // x20
  __int64 v8; // x3
  __int64 result; // x0
  unsigned __int64 v10; // x8
  unsigned __int64 StatusReg; // x8
  const char *v12; // x19
  unsigned __int64 v13; // x8
  __int64 v14; // x0
  const char *v15; // x19
  unsigned int v16; // w0
  unsigned int v17; // w20
  unsigned __int64 v18; // x8
  unsigned int v19; // w19
  __int64 v20; // x3
  const char *v21; // x19
  unsigned __int64 v22; // x8

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
  v4 = *(const char ***)(v2 + 280);
  v5 = &v4[4 * *(unsigned int *)(v2 + 288)];
  if ( v4 >= v5 )
  {
LABEL_5:
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v10 = _ReadStatusReg(SP_EL0);
    printk(&unk_86459, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  while ( 1 )
  {
    v7 = *v4;
    if ( !strcmp(*v4, s2) )
      break;
    v4 += 4;
    if ( v4 >= v5 )
      goto LABEL_5;
  }
  v12 = v4[2];
  if ( v12 )
  {
    if ( *((_BYTE *)v4 + 28) == 1 )
    {
      if ( *(_QWORD *)(a1 + 2400) )
      {
        if ( (unsigned int)msm_cvp_mmrm_set_value_in_range(a1, 0, 0) && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v13 = _ReadStatusReg(SP_EL0);
          printk(&unk_83C20, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
        }
      }
      else
      {
        if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_830D3, &unk_8DA84, "msm_cvp_prepare_enable_clk", v8);
          v12 = v4[2];
        }
        v14 = clk_round_rate(v12, 0);
        clk_set_rate(v12, v14);
      }
    }
    v15 = v4[2];
    result = clk_prepare(v15);
    if ( (_DWORD)result )
      goto LABEL_28;
    v16 = clk_enable(v15);
    if ( v16 )
    {
      v17 = v16;
      clk_unprepare(v15);
      result = v17;
LABEL_28:
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v18 = _ReadStatusReg(SP_EL0);
        v19 = result;
        printk(&unk_88F13, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
        return v19;
      }
      return result;
    }
    if ( (_clk_is_enabled(v4[2]) & 1) != 0 )
    {
      result = 0;
      if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      {
        printk(&unk_971DB, &unk_8DA84, *v4, v20);
        return 0;
      }
      return result;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v22 = _ReadStatusReg(SP_EL0);
      printk(&unk_85194, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
    }
    v21 = v4[2];
    clk_disable(v21);
    clk_unprepare(v21);
    return 4294967274LL;
  }
  result = 0;
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_878C8, &unk_8DA84, "msm_cvp_prepare_enable_clk", v7);
    return 0;
  }
  return result;
}
