__int64 __fastcall dp_hdcp2p2_cp_irq(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w20
  int v13; // w24
  __int64 v14; // x0
  int v15; // w20
  _DWORD *v16; // x23
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned __int64 StatusReg; // x19
  __int64 ipc_log_context; // x0
  void *v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x20
  __int64 v27; // x0
  void *v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned __int64 v31; // x20
  __int64 v32; // x0
  int v33; // w8
  int v34; // w20
  unsigned int v35; // w9
  int v36; // w6
  int v37; // w7
  __int64 result; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  char v41; // [xsp+0h] [xbp-10h]
  char v42; // [xsp+0h] [xbp-10h]
  _BYTE v43[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = sde_evtlog_log(sde_dbg_base_evtlog, "dp_hdcp2p2_cp_irq", 697, 8, 4369, -1059143953, a7, a8, v41);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(v9);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v23 = &unk_275B6D;
LABEL_18:
    printk(v23, "dp_hdcp2p2_valid_handle");
LABEL_35:
    result = 4294967274LL;
    goto LABEL_36;
  }
  if ( !*(_QWORD *)(a1 + 344) )
  {
    v24 = get_ipc_log_context(v9);
    ipc_log_string(v24, "[e][%-4d]HDCP library needs to be acquired\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v23 = &unk_233A43;
    goto LABEL_18;
  }
  if ( !*(_QWORD *)(a1 + 352) )
  {
    v25 = get_ipc_log_context(v9);
    ipc_log_string(v25, "[e][%-4d]invalid lib ops data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v23 = &unk_260BD9;
    goto LABEL_18;
  }
  if ( *(_DWORD *)(a1 + 80) == 3 || !*(_DWORD *)(a1 + 80) )
  {
    v20 = get_ipc_log_context(v9);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v20, "[d][%-4d]invalid hdcp state\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]invalid hdcp state\n", *(unsigned int *)(StatusReg + 1800));
    goto LABEL_35;
  }
  v10 = *(_QWORD *)(a1 + 168);
  v43[0] = 0;
  *(_BYTE *)(a1 + 480) = 0;
  v11 = drm_dp_dpcd_read(v10, 513, v43, 1);
  if ( v11 == 1 )
  {
    v12 = v43[0];
    v13 = v43[0] & 4;
    v14 = get_ipc_log_context(1);
    v15 = (v12 >> 2) & 1;
    v16 = (_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    v17 = ipc_log_string(v14, "[d][%-4d]cp_irq=0x%x\n", *v16, v15);
    if ( (_drm_debug & 4) != 0 )
      v17 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]cp_irq=0x%x\n", *v16, v15);
    v43[0] = 0;
    if ( !v13 )
      goto LABEL_22;
    v18 = drm_dp_dpcd_read(*(_QWORD *)(a1 + 168), 431251, v43, 1);
    if ( v18 == 1 )
    {
      *(_BYTE *)(a1 + 480) = v43[0];
      v19 = get_ipc_log_context(1);
      v17 = ipc_log_string(v19, "[d][%-4d]rx_status=0x%x\n", *v16, *(unsigned __int8 *)(a1 + 480));
      if ( (_drm_debug & 4) != 0 )
        v17 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]rx_status=0x%x\n", *v16, *(unsigned __int8 *)(a1 + 480));
      goto LABEL_22;
    }
    v26 = v18;
    v29 = get_ipc_log_context(v18);
    ipc_log_string(v29, "[e][%-4d]rxstatus read failed\n", *v16);
    v28 = &unk_222D1E;
  }
  else
  {
    v26 = v11;
    v27 = get_ipc_log_context(v11);
    ipc_log_string(v27, "[e][%-4d]cp irq read failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v28 = &unk_2643F6;
  }
  v17 = printk(v28, "dp_hdcp2p2_read_rx_status");
  if ( (_DWORD)v26 )
  {
    v40 = get_ipc_log_context(v17);
    ipc_log_string(v40, "[e][%-4d]failed to read rx status\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_27C092, "dp_hdcp2p2_cp_irq");
    result = v26;
    goto LABEL_36;
  }
LABEL_22:
  v30 = get_ipc_log_context(v17);
  v31 = _ReadStatusReg(SP_EL0);
  v32 = ipc_log_string(v30, "[d][%-4d]sink_rx_status=0x%x\n", *(_DWORD *)(v31 + 1800), *(unsigned __int8 *)(a1 + 480));
  if ( (_drm_debug & 4) != 0 )
    v32 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]sink_rx_status=0x%x\n",
            *(_DWORD *)(v31 + 1800),
            *(unsigned __int8 *)(a1 + 480));
  if ( !*(_BYTE *)(a1 + 480) )
  {
    v39 = get_ipc_log_context(v32);
    ipc_log_string(v39, "[d][%-4d]not a hdcp 2.2 irq\n", *(_DWORD *)(v31 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]not a hdcp 2.2 irq\n", *(unsigned int *)(v31 + 1800));
    goto LABEL_35;
  }
  if ( (*(_BYTE *)(a1 + 482) & *(_BYTE *)(a1 + 480)) == 0 && (*(_BYTE *)(a1 + 483) & 1) == 0 )
  {
    v33 = -29;
    do
    {
      v34 = v33;
      msleep(20);
      if ( (*(_BYTE *)(a1 + 483) & 1) != 0 )
        break;
      v33 = v34 + 1;
    }
    while ( v34 );
  }
  v35 = *(_DWORD *)(a1 + 8);
  if ( *(_DWORD *)a1 - *(_DWORD *)(a1 + 4) <= v35 )
  {
    *(_DWORD *)(a1 + 4LL * (v35 & *(_DWORD *)a1) + 24) = 6;
    __dmb(0xAu);
    ++*(_DWORD *)a1;
  }
  _wake_up(a1 + 56, 3, 1, 0);
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_hdcp2p2_cp_irq", 752, 8, 8738, -1059143953, v36, v37, v42);
  result = 0;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
