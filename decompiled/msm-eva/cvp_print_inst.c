__int64 __fastcall cvp_print_inst(int a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x21
  unsigned __int64 v4; // x8
  unsigned int v5; // w19
  unsigned int v6; // w20
  const char *v7; // x0
  __int64 v9; // x22
  unsigned __int64 StatusReg; // x8
  unsigned int v11; // w20
  unsigned int v12; // w21
  int v13; // w19
  const char *v14; // x0
  __int64 v15; // x22
  unsigned __int64 v16; // x8
  unsigned int v17; // w20
  unsigned int v18; // w21
  int v19; // w19
  const char *v20; // x0
  unsigned __int64 v21; // x8
  const char *v22; // x0
  __int64 v23; // x3
  const char *debug_level_str_0; // x0
  const char *v25; // x0

  if ( a2 )
  {
    if ( (msm_cvp_debug & a1) != 0 && !msm_cvp_debug_out )
    {
      v9 = a2;
      if ( (unsigned int)(a1 - 1) > 1 )
      {
        v13 = a1;
        debug_level_str_0 = get_debug_level_str_0(a1);
        printk(&unk_8D41D, debug_level_str_0, v9 + 15392, *(unsigned int *)(v9 + 136));
      }
      else
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v11 = *(_DWORD *)(StatusReg + 1800);
        v12 = *(_DWORD *)(StatusReg + 1804);
        v13 = a1;
        v14 = get_debug_level_str_0(a1);
        printk(&unk_90D06, v11, v12, v14);
      }
      a1 = v13;
      a2 = v9;
    }
    if ( (msm_cvp_debug & a1) != 0 && !msm_cvp_debug_out )
    {
      v15 = a2;
      if ( (unsigned int)(a1 - 1) > 1 )
      {
        v19 = a1;
        v25 = get_debug_level_str_0(a1);
        printk(&unk_8297A, v25, *(unsigned int *)(v15 + 14844), *(unsigned int *)(v15 + 14824));
      }
      else
      {
        v16 = _ReadStatusReg(SP_EL0);
        v17 = *(_DWORD *)(v16 + 1800);
        v18 = *(_DWORD *)(v16 + 1804);
        v19 = a1;
        v20 = get_debug_level_str_0(a1);
        printk(&unk_8F97D, v17, v18, v20);
      }
      a1 = v19;
      a2 = v15;
    }
    v2 = 0;
    if ( (msm_cvp_debug & a1) != 0 && !msm_cvp_debug_out )
    {
      v3 = a2;
      if ( (unsigned int)(a1 - 1) > 1 )
      {
        v22 = get_debug_level_str_0(a1);
        printk(&unk_8A23D, v22, v3 + 14996, v23);
      }
      else
      {
        v4 = _ReadStatusReg(SP_EL0);
        v5 = *(_DWORD *)(v4 + 1800);
        v6 = *(_DWORD *)(v4 + 1804);
        v7 = get_debug_level_str_0(a1);
        printk(&unk_8B6AD, v5, v6, v7);
      }
      return 0;
    }
  }
  else
  {
    v2 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v21 = _ReadStatusReg(SP_EL0);
      printk(&unk_894AF, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
      return (unsigned int)-22;
    }
  }
  return v2;
}
