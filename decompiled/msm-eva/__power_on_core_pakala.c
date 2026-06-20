__int64 __fastcall _power_on_core_pakala(__int64 a1)
{
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0
  unsigned int v4; // w19
  unsigned int v5; // w0
  unsigned int v6; // w21
  unsigned int v7; // w0
  unsigned int v8; // w0
  __int64 v9; // x2
  __int64 v10; // x3

  StatusReg = _ReadStatusReg(SP_EL0);
  result = _enable_gdsc(a1, "core");
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v4 = result;
      printk(&unk_880F6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return v4;
    }
    return result;
  }
  v5 = msm_cvp_prepare_enable_clk(a1, "eva_cc_mvs0_clk_src");
  if ( v5 )
  {
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v6 = v5;
      if ( !msm_cvp_debug_out )
        printk(&unk_955E3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    else
    {
      v6 = v5;
    }
    goto LABEL_21;
  }
  v7 = msm_cvp_prepare_enable_clk(a1, "core_clk");
  if ( v7 )
  {
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v6 = v7;
      if ( !msm_cvp_debug_out )
        printk(&unk_854F1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    else
    {
      v6 = v7;
    }
LABEL_20:
    msm_cvp_disable_unprepare_clk(a1, "eva_cc_mvs0_clk_src");
LABEL_21:
    _disable_gdsc(a1, "core");
    return v6;
  }
  v8 = msm_cvp_prepare_enable_clk(a1, "core_freerun_clk");
  if ( v8 )
  {
    v6 = v8;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      printk(&unk_96B04, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    msm_cvp_disable_unprepare_clk(a1, "core_clk");
    goto LABEL_20;
  }
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_94AA5, &unk_8DA84, v9, v10);
  trace_tracing_mark_write_2();
  return 0;
}
