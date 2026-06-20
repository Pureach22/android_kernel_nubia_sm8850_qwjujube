__int64 __fastcall dp_ctrl_on(__int64 a1, char a2, char a3, char a4, char a5)
{
  unsigned int v6; // w20
  __int64 v9; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x21
  __int64 v15; // x28
  __int64 v16; // x0
  __int64 (*v17)(void); // x8
  __int64 v18; // x0
  int v19; // w8
  char v20; // w26
  unsigned int i; // w27
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w20
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 (*v27)(void); // x8
  __int64 v28; // x0
  __int64 (*v29)(void); // x8
  __int64 (*v30)(void); // x8
  void (*v31)(void); // x8
  __int64 v32; // x8
  unsigned __int8 *v33; // x8
  unsigned int v34; // w9
  int v35; // w8
  __int64 v36; // x0
  __int64 v37; // x8
  int v38; // w9
  int v39; // w10
  int v40; // w9
  __int64 v41; // x0
  void (*v42)(void); // x8
  void (*v43)(void); // x8
  __int64 (*v44)(void); // x8
  __int64 v45; // x0
  __int64 v46; // x0
  void (*v47)(void); // x8
  __int64 (*v48)(void); // x8
  __int64 v49; // x0
  __int64 v50; // x0
  const char *v51; // x22
  void *v52; // x19
  __int64 v53; // x0

  if ( !a1 )
    return (unsigned int)-22;
  if ( (*(_BYTE *)(a1 + 257) & 1) != 0 )
    return 0;
  if ( *(_DWORD *)(a1 + 264) )
    return (unsigned int)-1;
  *(_BYTE *)(a1 + 258) = a2 & 1;
  if ( (a3 & 1) != 0 )
  {
    *(_BYTE *)(a1 + 259) = a3 & 1;
    *(_BYTE *)(a1 + 260) = a4 & 1;
  }
  if ( (**(_BYTE **)(a1 + 152) & 8) != 0 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = ipc_log_string(ipc_log_context, "[d][%-4d]using phy test link parameters\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      v9 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]using phy test link parameters\n", *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    v9 = drm_dp_link_rate_to_bw_code(*(unsigned int *)(*(_QWORD *)(a1 + 144) + 76LL));
    *(_DWORD *)(*(_QWORD *)(a1 + 152) + 132LL) = (unsigned __int8)v9;
    *(_DWORD *)(*(_QWORD *)(a1 + 152) + 128LL) = *(_DWORD *)(*(_QWORD *)(a1 + 144) + 80LL);
  }
  v12 = get_ipc_log_context(v9);
  v13 = *(_QWORD *)(a1 + 152);
  v14 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v12,
    "[d][%-4d]bw_code=%d, lane_count=%d\n",
    *(_DWORD *)(v14 + 1800),
    *(_DWORD *)(v13 + 132),
    *(_DWORD *)(v13 + 128));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]bw_code=%d, lane_count=%d\n",
      *(_DWORD *)(v14 + 1800),
      *(_DWORD *)(*(_QWORD *)(a1 + 152) + 132LL),
      *(_DWORD *)(*(_QWORD *)(a1 + 152) + 128LL));
  v15 = *(_QWORD *)(a1 + 152);
  v16 = *(_QWORD *)(a1 + 176);
  *(_BYTE *)(a1 + 268) = *(_DWORD *)(v15 + 128);
  *(_BYTE *)(a1 + 269) = *(_DWORD *)(v15 + 132);
  v17 = *(__int64 (**)(void))(v16 + 144);
  if ( *((_DWORD *)v17 - 1) != -1475637880 )
    __break(0x8228u);
  v18 = v17();
  if ( (a5 & 1) != 0 )
    v19 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 736LL);
  else
    v19 = 100;
  v20 = 0;
  for ( i = v19 - 1; ; --i )
  {
    v22 = get_ipc_log_context(v18);
    ipc_log_string(
      v22,
      "[d][%-4d]bw_code=%d, lane_count=%d\n",
      *(_DWORD *)(v14 + 1800),
      *(_DWORD *)(v15 + 132),
      *(_DWORD *)(v15 + 128));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]bw_code=%d, lane_count=%d\n",
        *(_DWORD *)(v14 + 1800),
        *(_DWORD *)(v15 + 132),
        *(_DWORD *)(v15 + 128));
    v23 = drm_dp_bw_code_to_link_rate(*(unsigned int *)(*(_QWORD *)(a1 + 152) + 132LL));
    v24 = v23;
    v25 = get_ipc_log_context(v23);
    ipc_log_string(v25, "[d][%-4d]rate=%d\n", *(_DWORD *)(v14 + 1800), v24);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]rate=%d\n", *(_DWORD *)(v14 + 1800), v24);
    dp_ctrl_set_clock_rate(a1, "link_clk_src");
    v26 = *(_QWORD *)(a1 + 184);
    v27 = *(__int64 (**)(void))(v26 + 400);
    if ( v27 )
    {
      if ( *((_DWORD *)v27 - 1) != -1303907462 )
        __break(0x8228u);
      v28 = v27();
      if ( (v28 & 0x80000000) != 0 )
      {
        v6 = v28;
        v52 = &unk_27C5D4;
        v51 = "[e][%-4d]DP pll cfg failed\n";
        goto LABEL_91;
      }
      v26 = *(_QWORD *)(a1 + 184);
    }
    v29 = *(__int64 (**)(void))(v26 + 408);
    if ( v29 )
    {
      if ( *((_DWORD *)v29 - 1) != -928861002 )
        __break(0x8228u);
      v28 = v29();
      if ( (v28 & 0x80000000) != 0 )
      {
        v6 = v28;
        v51 = "[e][%-4d]DP pll prepare failed\n";
        v52 = &unk_226610;
        goto LABEL_91;
      }
    }
    v30 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 160) + 48LL);
    if ( *((_DWORD *)v30 - 1) != -1712294539 )
      __break(0x8228u);
    v28 = v30();
    if ( (_DWORD)v28 )
    {
      v6 = -22;
      v51 = "[e][%-4d]Unabled to start link clocks\n";
      v52 = &unk_2599CE;
LABEL_91:
      v53 = get_ipc_log_context(v28);
      ipc_log_string(v53, v51, *(unsigned int *)(v14 + 1800));
      printk(v52, "dp_ctrl_enable_link_clock");
      return v6;
    }
    v31 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 256LL);
    if ( *((_DWORD *)v31 - 1) != -2029659320 )
      __break(0x8228u);
    v31();
    dp_ctrl_configure_source_link_params(a1, 1);
    if ( 10 * (i / 0xA) == i )
    {
      v32 = *(_QWORD *)(a1 + 152);
      v20 = 1;
      *(_DWORD *)(v32 + 128) = *(unsigned __int8 *)(a1 + 268);
      *(_DWORD *)(v32 + 132) = *(unsigned __int8 *)(a1 + 269);
    }
    v33 = *(unsigned __int8 **)(a1 + 144);
    v34 = *v33;
    if ( v34 < 0x14 )
    {
      if ( v34 >= 0x12 )
      {
LABEL_48:
        if ( (v33[2] & 0x40) != 0 )
          v35 = 3;
        else
          v35 = 2;
        if ( (v20 & 1) == 0 )
          goto LABEL_58;
        goto LABEL_54;
      }
      v35 = 2;
      if ( (v20 & 1) == 0 )
        goto LABEL_58;
    }
    else
    {
      if ( ((char)v33[3] & 0x80000000) == 0 )
        goto LABEL_48;
      v35 = 7;
      if ( (v20 & 1) == 0 )
        goto LABEL_58;
    }
LABEL_54:
    if ( v35 == 3 )
    {
      v35 = 2;
    }
    else if ( v35 == 7 )
    {
      v35 = 3;
    }
LABEL_58:
    *(_DWORD *)(a1 + 280) = v35;
    v36 = dp_ctrl_setup_main_link(a1);
    v6 = v36;
    if ( !(_DWORD)v36 )
    {
      *(_BYTE *)(a1 + 257) = 1;
      return v6;
    }
    if ( !i || *(_DWORD *)(a1 + 264) )
      break;
    if ( (_DWORD)v36 != -11 )
    {
      v37 = *(_QWORD *)(a1 + 152);
      v38 = *(_DWORD *)(v37 + 132);
      if ( v38 == 20 )
        v39 = 10;
      else
        v39 = 6;
      if ( v38 == 30 )
        v40 = 20;
      else
        v40 = v39;
      *(_DWORD *)(v37 + 132) = v40;
      v41 = get_ipc_log_context(v36);
      ipc_log_string(
        v41,
        "[d][%-4d]new bw code=0x%x\n",
        *(_DWORD *)(v14 + 1800),
        *(_DWORD *)(*(_QWORD *)(a1 + 152) + 132LL));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]new bw code=0x%x\n",
          *(_DWORD *)(v14 + 1800),
          *(_DWORD *)(*(_QWORD *)(a1 + 152) + 132LL));
      v42 = *(void (**)(void))(*(_QWORD *)(a1 + 144) + 1008LL);
      if ( *((_DWORD *)v42 - 1) != -362183607 )
        __break(0x8228u);
      v42();
    }
    dp_ctrl_configure_source_link_params(a1, 0);
    v43 = *(void (**)(void))(*(_QWORD *)(a1 + 160) + 48LL);
    if ( *((_DWORD *)v43 - 1) != -1712294539 )
      __break(0x8228u);
    v43();
    v44 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 184) + 416LL);
    if ( v44 )
    {
      if ( *((_DWORD *)v44 - 1) != -928861002 )
        __break(0x8228u);
      v45 = v44();
      if ( (v45 & 0x80000000) != 0 )
      {
        v46 = get_ipc_log_context(v45);
        ipc_log_string(v46, "[e][%-4d]pll unprepare failed\n", *(_DWORD *)(v14 + 1800));
        printk(&unk_24ECF1, "dp_ctrl_disable_link_clock");
      }
    }
    v18 = msleep(20);
  }
  v47 = *(void (**)(void))(*(_QWORD *)(a1 + 160) + 48LL);
  if ( *((_DWORD *)v47 - 1) != -1712294539 )
    __break(0x8228u);
  v47();
  v48 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 184) + 416LL);
  if ( v48 )
  {
    if ( *((_DWORD *)v48 - 1) != -928861002 )
      __break(0x8228u);
    v49 = v48();
    if ( (v49 & 0x80000000) != 0 )
    {
      v50 = get_ipc_log_context(v49);
      ipc_log_string(v50, "[e][%-4d]pll unprepare failed\n", *(_DWORD *)(v14 + 1800));
      printk(&unk_24ECF1, "dp_ctrl_disable_link_clock");
    }
  }
  return v6;
}
