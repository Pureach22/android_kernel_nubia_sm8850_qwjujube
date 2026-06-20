__int64 __fastcall dp_ctrl_stream_on(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x0
  __int64 (*v6)(void); // x8
  __int64 v7; // x0
  int v8; // w8
  const char *v9; // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 (*v14)(void); // x8
  __int64 v15; // x0
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  __int64 v17; // x8
  __int64 v18; // x19
  void (*v19)(void); // x9
  void (*v20)(void); // x8
  void (*v21)(void); // x8
  __int64 (*v22)(void); // x8
  __int64 v23; // x0
  int v24; // w21
  __int64 v25; // x0
  unsigned __int64 v26; // x22
  const char *v27; // x3
  __int64 v28; // x0
  const char *v29; // x5
  const char *v30; // x20
  bool v31; // zf
  unsigned int v32; // w19
  __int64 v33; // x0
  void *v34; // x0
  __int64 v35; // x0
  const char *v36; // x4
  const char *v37; // x6
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  void (*v41)(void); // x8
  __int64 v42; // x0
  __int64 (*v43)(void); // x8
  __int64 v44; // x0
  char v45; // w21
  __int64 v46; // x0
  unsigned __int64 v47; // x22
  const char *v48; // x21
  __int64 v49; // x0
  __int64 v50; // x0
  char s2[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v52; // [xsp+10h] [xbp-20h]
  __int64 v53; // [xsp+18h] [xbp-18h]
  __int64 v54; // [xsp+20h] [xbp-10h]
  __int64 v55; // [xsp+28h] [xbp-8h]

  result = 4294967274LL;
  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
    goto LABEL_66;
  if ( (*(_BYTE *)(a1 + 257) & 1) == 0 )
  {
    ipc_log_context = get_ipc_log_context(4294967274LL);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]controller powered off\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]controller powered off\n", *(_DWORD *)(StatusReg + 1800));
    result = 0xFFFFFFFFLL;
    goto LABEL_66;
  }
  v5 = *(_QWORD *)(a1 + 160);
  v53 = 0;
  v54 = 0;
  *(_QWORD *)s2 = 0;
  v52 = 0;
  v6 = *(__int64 (**)(void))(v5 + 64);
  if ( *((_DWORD *)v6 - 1) != 1342260239 )
    __break(0x8228u);
  v7 = v6();
  if ( (_DWORD)v7 )
  {
    v32 = v7;
LABEL_65:
    v39 = get_ipc_log_context(v7);
    ipc_log_string(v39, "[e][%-4d]failure on stream clock enable\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_21C405, "dp_ctrl_stream_on");
    result = v32;
    goto LABEL_66;
  }
  v8 = *(_DWORD *)(a2 + 912);
  if ( v8 == 1 )
  {
    v9 = "strm1_pixel_clk";
  }
  else
  {
    if ( v8 )
    {
      v38 = get_ipc_log_context(v7);
      ipc_log_string(
        v38,
        "[e][%-4d]Invalid stream:%d for clk enable\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a2 + 912));
      v34 = &unk_276082;
      goto LABEL_64;
    }
    v9 = "strm0_pixel_clk";
  }
  v13 = *(_QWORD *)v9;
  v12 = *((_QWORD *)v9 + 1);
  *(_QWORD *)s2 = v13;
  v52 = v12;
  dp_ctrl_set_clock_rate(a1, s2);
  v14 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 160) + 48LL);
  if ( *((_DWORD *)v14 - 1) != -1712294539 )
    __break(0x8228u);
  v15 = v14();
  if ( (_DWORD)v15 )
  {
    v33 = get_ipc_log_context(v15);
    ipc_log_string(
      v33,
      "[e][%-4d]Unabled to start stream:%d clocks\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a2 + 912));
    v34 = &unk_256268;
LABEL_64:
    v7 = printk(v34, "dp_ctrl_enable_stream_clocks");
    v32 = -22;
    goto LABEL_65;
  }
  v16 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1024);
  *(_BYTE *)(a2 + 972) = 1;
  if ( *((_DWORD *)v16 - 1) != -2060240890 )
    __break(0x8228u);
  result = v16(a2, 1);
  if ( !(_DWORD)result )
  {
    v17 = *(_QWORD *)(a1 + 152);
    if ( (*(_BYTE *)v17 & 8) == 0 )
    {
      dp_ctrl_mst_stream_setup(a1, a2);
      v40 = *(_QWORD *)(a1 + 176);
      *(_DWORD *)(a1 + 224) = 0;
      v41 = *(void (**)(void))(v40 + 56);
      if ( *((_DWORD *)v41 - 1) != -1041116529 )
        __break(0x8228u);
      v41();
      dp_ctrl_mst_send_act(a1);
      dp_ctrl_wait4video_ready(a1);
      v42 = *(_QWORD *)(a1 + 176);
      ++*(_DWORD *)(a1 + 276);
      v43 = *(__int64 (**)(void))(v42 + 120);
      if ( *((_DWORD *)v43 - 1) != -163313110 )
        __break(0x8228u);
      v44 = v43();
      v45 = v44;
      v46 = get_ipc_log_context(v44);
      v47 = _ReadStatusReg(SP_EL0);
      if ( (v45 & 1) != 0 )
        v48 = "READY";
      else
        v48 = "NOT READY";
      ipc_log_string(v46, "[d][%-4d]mainlink %s\n", *(_DWORD *)(v47 + 1800), v48);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mainlink %s\n", *(_DWORD *)(v47 + 1800), v48);
      dp_ctrl_fec_setup(a1);
      v49 = dp_ctrl_dsc_setup(a1, a2);
      v50 = get_ipc_log_context(v49);
      ipc_log_string(v50, "[i][%-4d]: CRC disabled\n", *(_DWORD *)(v47 + 1800));
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_272819, *(unsigned int *)(v47 + 1800));
      else
        printk(&unk_230C39, "dp_ctrl_stream_on");
      goto LABEL_62;
    }
    v18 = *(unsigned int *)(v17 + 120);
    v19 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 152LL);
    if ( *((_DWORD *)v19 - 1) != -922222210 )
      __break(0x8229u);
    v19();
    v20 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 176LL);
    if ( *((_DWORD *)v20 - 1) != -1041116529 )
      __break(0x8228u);
    v20();
    dp_ctrl_update_sink_vx_px(a1);
    v21 = *(void (**)(void))(*(_QWORD *)(a1 + 152) + 184LL);
    if ( *((_DWORD *)v21 - 1) != 1968921649 )
      __break(0x8228u);
    v21();
    v22 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 176) + 184LL);
    if ( *((_DWORD *)v22 - 1) != -618841677 )
      __break(0x8228u);
    v23 = v22();
    v24 = v23;
    v25 = get_ipc_log_context(v23);
    v26 = _ReadStatusReg(SP_EL0);
    if ( (unsigned int)v18 > 7 )
      v27 = "unknown";
    else
      v27 = off_281020[v18];
    v28 = ipc_log_string(v25, "[d][%-4d]pattern_request: %s. pattern_sent: 0x%x\n", *(_DWORD *)(v26 + 1800), v27, v24);
    if ( (_drm_debug & 4) != 0 )
    {
      if ( (unsigned int)v18 > 7 )
        v29 = "unknown";
      else
        v29 = off_281020[v18];
      v28 = _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]pattern_request: %s. pattern_sent: 0x%x\n",
              *(_DWORD *)(v26 + 1800),
              v29,
              v24);
    }
    v30 = "failed";
    if ( v24 <= 127 )
    {
      if ( v24 == 8 )
      {
        v31 = (_DWORD)v18 == 1;
      }
      else
      {
        if ( v24 != 64 )
          goto LABEL_54;
        v31 = (_DWORD)v18 == 7;
      }
    }
    else
    {
      switch ( v24 )
      {
        case 128:
          v31 = (_DWORD)v18 == 2 || (_DWORD)v18 == 5;
          break;
        case 256:
          v31 = (_DWORD)v18 == 3;
          break;
        case 512:
          v31 = (_DWORD)v18 == 4;
          break;
        default:
LABEL_54:
          v35 = get_ipc_log_context(v28);
          if ( (unsigned int)v18 > 7 )
            v36 = "unknown";
          else
            v36 = off_281020[v18];
          ipc_log_string(v35, "[d][%-4d]%s: %s\n", *(_DWORD *)(v26 + 1800), v30, v36);
          if ( (_drm_debug & 4) != 0 )
          {
            if ( (unsigned int)v18 > 7 )
              v37 = "unknown";
            else
              v37 = off_281020[v18];
            _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: %s\n", *(_DWORD *)(v26 + 1800), v30, v37);
          }
LABEL_62:
          result = 0;
          goto LABEL_66;
      }
    }
    if ( v31 )
      v30 = "success";
    goto LABEL_54;
  }
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return result;
}
