__int64 __fastcall dp_display_config_hdr(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v6; // x25
  __int64 core_clk_rate; // x22
  int *v10; // x24
  int v11; // w23
  int v12; // w23
  __int64 v13; // x0
  unsigned __int64 StatusReg; // x24
  __int64 (*v15)(void); // x8
  __int64 v16; // x0
  void *v17; // x0
  __int64 v18; // x0
  unsigned __int64 v19; // x24
  _DWORD *v20; // x8
  __int64 v22; // x0
  __int64 v23; // x19
  int v24; // w20
  const char *v25; // x0
  int v26; // w6
  int v27; // w7
  char v28; // [xsp+0h] [xbp+0h]

  if ( !a1 || !a2 )
  {
    if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v22 = 0;
    ipc_log_string(v22, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_275B6D;
    goto LABEL_32;
  }
  v6 = *(_QWORD *)(a2 + 944);
  if ( (sde_cesta_is_enabled(**(unsigned int **)(*(_QWORD *)a1 + 64LL)) & 1) == 0 )
  {
    v15 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 1024) + 80LL);
    if ( *((_DWORD *)v15 - 1) != -1990250310 )
      __break(0x8228u);
    core_clk_rate = v15();
    if ( core_clk_rate )
      goto LABEL_5;
    goto LABEL_15;
  }
  core_clk_rate = sde_cesta_get_core_clk_rate(**(unsigned int **)(*(_QWORD *)a1 + 64LL));
  if ( !core_clk_rate )
  {
LABEL_15:
    if ( !g_dp_display || (v16 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v16 = 0;
    ipc_log_string(v16, "[e][%-4d]invalid rate for core_clk\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v17 = &unk_24222D;
LABEL_32:
    printk(v17, "dp_display_config_hdr");
    return 4294967274LL;
  }
LABEL_5:
  v10 = (int *)(a1 - 1156);
  v11 = *(_DWORD *)(a1 - 1156);
  if ( (v11 & 0x40) != 0 )
  {
    v12 = *(unsigned __int8 *)(v6 + 4744);
    if ( (v12 & 1) != 0 )
    {
      if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v13 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(v13, "[d][%-4d]piggy-backing with colorspace\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]piggy-backing with colorspace\n",
          *(unsigned int *)(StatusReg + 1800));
    }
    else
    {
      if ( !g_dp_display || (v18 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v18 = 0;
      v19 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v18, "[d][%-4d]flushing the HDR metadata\n", *(_DWORD *)(v19 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]flushing the HDR metadata\n", *(unsigned int *)(v19 + 1800));
    }
    v20 = *(_DWORD **)(a2 + 1064);
    if ( *(v20 - 1) != 335021814 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))v20)(
             a2,
             a3,
             a4 & 1,
             core_clk_rate,
             v12 ^ 1u);
  }
  else
  {
    if ( !g_dp_display || (v23 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v23 = 0;
    v24 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    v25 = dp_display_state_name(v11);
    ipc_log_string(v23, "[e][%-4d]%s: state (0x%x): %s\n", v24, "[not enabled]", v11, v25);
    dp_display_state_name(*v10);
    printk(&unk_24548C, "dp_display_config_hdr");
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_config_hdr", 3521, 8, *v10, -1059143953, v26, v27, v28);
    return 0;
  }
}
