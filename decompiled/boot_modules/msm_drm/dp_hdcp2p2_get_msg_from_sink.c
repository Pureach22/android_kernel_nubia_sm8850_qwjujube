__int64 __fastcall dp_hdcp2p2_get_msg_from_sink(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w23
  unsigned int v4; // w20
  __int64 v5; // x24
  __int64 v6; // x0
  unsigned __int64 StatusReg; // x25
  int v8; // w2
  __int64 v9; // x0
  __int64 v10; // x21
  int v11; // w27
  __int64 v12; // x0
  int v13; // w24
  int v14; // w20
  __int64 result; // x0
  __int64 v16; // x8
  __int64 v17; // x21
  int v18; // w8
  __int64 ipc_log_context; // x0
  void *v20; // x0
  int v21; // w23
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 (__fastcall **v25)(_QWORD); // x8
  __int64 (__fastcall *v26)(_QWORD); // x8
  __int64 v27; // x0
  int v28; // w8
  int v29; // w19
  __int64 v30; // x20
  const char *v31; // x0
  _QWORD v32[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v33; // [xsp+18h] [xbp-28h]
  __int64 v34; // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  __int64 v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 344);
  v35 = 0;
  v36 = 0;
  v3 = *(_DWORD *)(a1 + 392);
  v33 = 0;
  v34 = 0;
  v4 = *(_DWORD *)(a1 + 424);
  v5 = *(_QWORD *)(a1 + 384);
  v32[0] = 0;
  v32[1] = v2;
  if ( !*(_DWORD *)(a1 + 80) || *(_DWORD *)(a1 + 80) == 3 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid hdcp state\n", *(_DWORD *)(StatusReg + 1800));
    v20 = &unk_275BDA;
LABEL_20:
    result = printk(v20, "dp_hdcp2p2_aux_read_message");
    v14 = -22;
    goto LABEL_23;
  }
  v6 = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v8 = *(_DWORD *)(StatusReg + 1800);
  if ( !v5 )
  {
    ipc_log_string(v6, "[e][%-4d]invalid request buffer\n", v8);
    v20 = &unk_255AF1;
    goto LABEL_20;
  }
  v9 = ipc_log_string(v6, "[d][%-4d]offset(0x%x), size(%d)\n", v8, v4, v3);
  if ( (_drm_debug & 4) != 0 )
    v9 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]offset(0x%x), size(%d)\n", *(_DWORD *)(StatusReg + 1800), v4, v3);
  v10 = ktime_get(v9);
  while ( 1 )
  {
    v11 = v3 >= 16 ? 16 : v3;
    v12 = drm_dp_dpcd_read(*(_QWORD *)(a1 + 168), v4, v5, v11);
    if ( v11 != (_DWORD)v12 )
      break;
    v3 -= v11;
    v5 += v11;
    v4 += v11;
    if ( v3 <= 0 )
    {
      v13 = v12;
      v14 = 0;
      goto LABEL_13;
    }
  }
  v21 = v12;
  v22 = get_ipc_log_context(v12);
  ipc_log_string(
    v22,
    "[e][%-4d]fail: offset(0x%x), size(0x%x), rc(0x%x)\n",
    *(_DWORD *)(StatusReg + 1800),
    v4,
    v11,
    v21);
  printk(&unk_237139, "dp_hdcp2p2_aux_read_message");
  v13 = v21;
  v12 = sde_evtlog_log(sde_dbg_base_evtlog, "dp_hdcp2p2_aux_read_message", 404, 8, 4369, v4, v11, v21, 239);
  v14 = -22;
LABEL_13:
  result = ktime_get(v12);
  v16 = *(unsigned int *)(a1 + 408);
  if ( (_DWORD)v16 )
  {
    v17 = (result - v10) / 1000000;
    if ( v17 > v16 )
    {
      v23 = get_ipc_log_context(result);
      ipc_log_string(
        v23,
        "[e][%-4d]HDCP read timeout exceeded (%lldms > %ums)\n",
        *(_DWORD *)(StatusReg + 1800),
        v17,
        *(_DWORD *)(a1 + 408));
      result = printk(&unk_21BA7D, "dp_hdcp2p2_aux_read_message");
      v14 = -110;
LABEL_23:
      v24 = get_ipc_log_context(result);
      ipc_log_string(v24, "[e][%-4d]error reading message %d\n", *(_DWORD *)(StatusReg + 1800), v14);
      printk(&unk_23DE88, "dp_hdcp2p2_get_msg_from_sink");
      LODWORD(v32[0]) = 10;
      result = msleep(1000);
      if ( !a1 )
        goto LABEL_30;
      goto LABEL_24;
    }
  }
  if ( v11 != v13 )
    goto LABEL_23;
  v18 = *(_DWORD *)(a1 + 404);
  LODWORD(v33) = *(_DWORD *)(a1 + 400);
  HIDWORD(v33) = v18;
  LODWORD(v32[0]) = 9;
  if ( !a1 )
    goto LABEL_30;
LABEL_24:
  v25 = *(__int64 (__fastcall ***)(_QWORD))(a1 + 352);
  if ( v25 )
  {
    v26 = *v25;
    if ( v26 )
    {
      if ( *((_DWORD *)v26 - 1) != -417196079 )
        __break(0x8228u);
      result = v26(v32);
      if ( (_DWORD)result )
      {
        v27 = get_ipc_log_context(result);
        v28 = v32[0];
        v29 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
        v30 = v27;
        v31 = sde_hdcp_2x_cmd_to_str(v28);
        ipc_log_string(v30, "[e][%-4d]error sending %s to lib\n", v29, v31);
        sde_hdcp_2x_cmd_to_str(v32[0]);
        result = printk(&unk_24E728, "dp_hdcp2p2_wakeup_lib");
      }
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
