__int64 __fastcall _power_off_controller_pakala(__int64 a1)
{
  int i; // w21
  unsigned int v3; // w0
  unsigned int v4; // w20
  __int64 v5; // x8
  void (__fastcall *v6)(_QWORD); // x8
  int j; // w21
  unsigned int v8; // w0
  unsigned int v9; // w20
  __int64 v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  unsigned int v12; // w27
  unsigned int v13; // w20
  unsigned int v14; // w21
  int v16; // w21
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8

  _write_register(a1, 0xA0168u, 3u);
  _write_register(a1, 0xD0018u, 1u);
  _write_register(a1, 0xB005Cu, 1u);
  for ( i = 0; i != 2000; ++i )
  {
    v3 = _read_register(a1, 0xB0060u);
    v4 = v3;
    if ( (v3 & 2) == 0 && (v3 & 5) != 4 )
      break;
    _write_register(a1, 0xB005Cu, 0);
    usleep_range_state(10, 20, 2);
    _write_register(a1, 0xD0018u, 1u);
    _write_register(a1, 0xB005Cu, 1u);
    usleep_range_state(1000, 1200, 2);
  }
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_937E0, &unk_8DA84, "__enter_cpu_noc_lpi", v4);
  if ( i == 2000 )
  {
    _read_register(a1, 0xC0010u);
    _read_register(a1, 0xA004Cu);
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8E78A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      if ( !a1 )
        goto LABEL_17;
    }
    else if ( !a1 )
    {
      goto LABEL_17;
    }
    v5 = *(_QWORD *)(a1 + 2512);
    if ( v5 )
    {
      v6 = *(void (__fastcall **)(_QWORD))(v5 + 72);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != -639316779 )
          __break(0x8228u);
        v6(a1);
      }
    }
  }
LABEL_17:
  _write_register(a1, 0xE002Cu, 1u);
  for ( j = 0; j != 2000; ++j )
  {
    v8 = _read_register(a1, 0xE0030u);
    v9 = v8;
    if ( (v8 & 2) == 0 && (v8 & 5) != 4 )
      break;
    _write_register(a1, 0xE002Cu, 0);
    usleep_range_state(10, 20, 2);
    _write_register(a1, 0xE002Cu, 1u);
    usleep_range_state(1000, 1200, 2);
  }
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_956CC, &unk_8DA84, "__enter_video_ctl_noc_lpi", v9);
  _write_register(a1, 0xE002Cu, 0);
  if ( j == 2000 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v24 = _ReadStatusReg(SP_EL0);
      printk(&unk_92C57, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), "warn");
      if ( !a1 )
        goto LABEL_33;
    }
    else if ( !a1 )
    {
      goto LABEL_33;
    }
    v10 = *(_QWORD *)(a1 + 2512);
    if ( v10 )
    {
      v11 = *(void (__fastcall **)(_QWORD))(v10 + 72);
      if ( v11 )
      {
        if ( *((_DWORD *)v11 - 1) != -639316779 )
          __break(0x8228u);
        v11(a1);
      }
    }
  }
LABEL_33:
  _write_register(a1, 0xB0054u, 0);
  v12 = 0;
  do
  {
    v13 = _read_register(a1, 0xB0058u);
    usleep_range_state(50, 100, 2);
    v14 = v12 + 1;
    if ( !v13 )
      break;
  }
  while ( v12++ < 0x3E7 );
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_975D5, &unk_8DA84, v13, v14);
    if ( v14 != 1000 )
      goto LABEL_43;
  }
  else if ( v14 != 1000 )
  {
    goto LABEL_43;
  }
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v25 = _ReadStatusReg(SP_EL0);
    printk(&unk_8AF9A, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), "warn");
  }
LABEL_43:
  v16 = _read_register(a1, 0xE0008u);
  _write_register(a1, 0xE0008u, v16 | 0x10);
  usleep_range_state(50, 100, 2);
  _write_register(a1, 0xE0008u, v16 & 0xFFFFFFEF);
  if ( (unsigned int)msm_cvp_disable_unprepare_clk(a1, "core_freerun_clk")
    && (msm_cvp_debug & 1) != 0
    && !msm_cvp_debug_out )
  {
    v18 = _ReadStatusReg(SP_EL0);
    printk(&unk_8FD7E, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
  }
  if ( (unsigned int)msm_cvp_disable_unprepare_clk(a1, "cvp_freerun_clk")
    && (msm_cvp_debug & 1) != 0
    && !msm_cvp_debug_out )
  {
    v19 = _ReadStatusReg(SP_EL0);
    printk(&unk_8352D, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
  }
  if ( (unsigned int)msm_cvp_disable_unprepare_clk(a1, "cvp_clk") && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v20 = _ReadStatusReg(SP_EL0);
    printk(&unk_86891, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
  }
  if ( (unsigned int)msm_cvp_disable_unprepare_clk(a1, "sleep_clk") && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v21 = _ReadStatusReg(SP_EL0);
    printk(&unk_87EC1, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
  }
  _disable_gdsc(a1, "controller");
  msm_cvp_disable_unprepare_clk(a1, "core_axi_clock");
  msm_cvp_disable_unprepare_clk(a1, "cvp_axi_clock");
  if ( (unsigned int)msm_cvp_disable_unprepare_clk(a1, "eva_cc_mvs0_clk_src")
    && (msm_cvp_debug & 1) != 0
    && !msm_cvp_debug_out )
  {
    v22 = _ReadStatusReg(SP_EL0);
    printk(&unk_91E27, *(unsigned int *)(v22 + 1800), *(unsigned int *)(v22 + 1804), &unk_8E7CE);
  }
  return 0;
}
