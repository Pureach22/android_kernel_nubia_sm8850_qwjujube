__int64 __fastcall _power_on_controller_pakala(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  unsigned int v6; // w19
  unsigned int v7; // w0
  unsigned int v8; // w21
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  __int64 v13; // x2
  __int64 v14; // x3

  StatusReg = _ReadStatusReg(SP_EL0);
  result = _enable_gdsc(a1, "controller");
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v4 = *(unsigned int *)(StatusReg + 1800);
      v5 = *(unsigned int *)(StatusReg + 1804);
      v6 = result;
      printk(&unk_96ACF, v4, v5, &unk_8E7CE);
      return v6;
    }
    return result;
  }
  v7 = msm_cvp_prepare_enable_clk(a1, "sleep_clk");
  if ( v7 )
  {
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v8 = v7;
      if ( !msm_cvp_debug_out )
        printk(&unk_91DE1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    else
    {
      v8 = v7;
    }
    goto LABEL_33;
  }
  v9 = msm_cvp_prepare_enable_clk(a1, "core_axi_clock");
  if ( v9 )
  {
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v8 = v9;
      if ( !msm_cvp_debug_out )
        printk(&unk_92AEA, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    else
    {
      v8 = v9;
    }
    goto LABEL_32;
  }
  v10 = msm_cvp_prepare_enable_clk(a1, "cvp_axi_clock");
  if ( v10 )
  {
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v8 = v10;
      if ( !msm_cvp_debug_out )
        printk(&unk_8B928, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    else
    {
      v8 = v10;
    }
    goto LABEL_31;
  }
  v11 = msm_cvp_prepare_enable_clk(a1, "cvp_clk");
  if ( v11 )
  {
    if ( (msm_cvp_debug & 1) != 0 )
    {
      v8 = v11;
      if ( !msm_cvp_debug_out )
        printk(&unk_89195, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    else
    {
      v8 = v11;
    }
LABEL_30:
    msm_cvp_disable_unprepare_clk(a1, "cvp_axi_clock");
LABEL_31:
    msm_cvp_disable_unprepare_clk(a1, "core_axi_clock");
LABEL_32:
    msm_cvp_disable_unprepare_clk(a1, "sleep_clk");
LABEL_33:
    _disable_gdsc(a1, "controller");
    return v8;
  }
  v12 = msm_cvp_prepare_enable_clk(a1, "cvp_freerun_clk");
  if ( v12 )
  {
    v8 = v12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      printk(&unk_8A45C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    msm_cvp_disable_unprepare_clk(a1, "cvp");
    goto LABEL_30;
  }
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_92B21, &unk_8DA84, v13, v14);
  trace_tracing_mark_write_2(69, StatusReg, "__power_on_controller_v1");
  return 0;
}
