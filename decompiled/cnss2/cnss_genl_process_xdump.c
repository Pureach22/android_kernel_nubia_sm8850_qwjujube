__int64 __fastcall cnss_genl_process_xdump(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x21
  __int64 first_plat_priv; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x8
  __int64 v7; // x6
  __int64 v8; // x19
  _BYTE *v9; // x0
  _BYTE *v10; // x20
  char v11; // w9
  _BOOL4 v12; // w8
  bool v13; // zf
  unsigned __int64 v14; // x10
  char v15; // w9
  int v16; // w11
  unsigned int v17; // w8
  unsigned int v18; // w9
  const char *v19; // x1
  unsigned __int64 v20; // x8
  const char *v21; // x1
  unsigned __int64 v22; // x8
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  unsigned __int64 v27; // x9
  __int64 v28; // x19
  const char *v29; // x1
  __int64 v30; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v32; // x20
  unsigned int v33; // w19
  const char *v34; // x1
  unsigned __int64 v35; // x8
  const char *v36; // x1
  __int16 v37; // w9
  const char *v38; // x8
  __int16 v39; // w10
  const char *v40; // x9
  __int64 v41; // x0
  __int64 v42; // x1
  _BYTE *v43; // x3
  __int16 v44; // w10
  const char *v45; // x9
  __int16 v46; // w9
  const char *v47; // x8
  __int16 v48; // w11
  const char *v49; // x10
  char v50; // [xsp+0h] [xbp+0h]

  v2 = *(_QWORD **)(a2 + 32);
  first_plat_priv = cnss_get_first_plat_priv();
  if ( first_plat_priv )
  {
    v6 = v2[1];
    if ( v6 )
    {
      v7 = *(unsigned __int8 *)(v6 + 4);
      switch ( (_DWORD)v7 )
      {
        case 6:
          v30 = v2[2];
          StatusReg = _ReadStatusReg(SP_EL0);
          v32 = first_plat_priv;
          v33 = *(_DWORD *)(v30 + 4);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v34 = "irq";
          }
          else
          {
            v44 = *(_DWORD *)(StatusReg + 16);
            v45 = (const char *)(StatusReg + 2320);
            if ( (v44 & 0xFF00) != 0 )
              v34 = "soft_irq";
            else
              v34 = v45;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v34,
            "cnss_genl_xdump_wl_over_bt_resp_hdl",
            6u,
            6u,
            "Received XDUMP_SUBCMD_WL_OVER_BT_RESP: result %d\n",
            v33,
            v5,
            v50);
          cnss_xdump_wl_over_bt_complete(v32, v33);
          return 0;
        case 2:
          v27 = _ReadStatusReg(SP_EL0);
          v28 = first_plat_priv;
          if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
          {
            v29 = "irq";
          }
          else
          {
            v39 = *(_DWORD *)(v27 + 16);
            v40 = (const char *)(v27 + 2320);
            if ( (v39 & 0xFF00) != 0 )
              v29 = "soft_irq";
            else
              v29 = v40;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v29,
            "cnss_genl_xdump_bt_over_wl_req_hdl",
            6u,
            6u,
            "Received XDUMP_SUBCMD_BT_OVER_WL_REQ\n",
            v7,
            v5,
            v50);
          v41 = v28;
          v42 = 24;
          v43 = nullptr;
          goto LABEL_47;
        case 1:
          v8 = first_plat_priv;
          v9 = (_BYTE *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 1);
          v10 = v9;
          if ( !v9 )
          {
            cnss_genl_send_xdump_wlan_arrival(0, 0, 0, 0);
            return 0;
          }
          v11 = *v9 & 0xF8;
          v12 = v2[5] != 0;
          v13 = v2[6] == 0;
          v14 = _ReadStatusReg(SP_EL0);
          v15 = v11 & 0xFD | (2 * v12);
          v16 = !v13;
          v17 = 2 * v12;
          *v9 = v15 & 0xFB | (4 * (v16 & 1)) | 1;
          v18 = 4 * v16;
          if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
          {
            v19 = "irq";
          }
          else
          {
            v48 = *(_DWORD *)(v14 + 16);
            v49 = (const char *)(v14 + 2320);
            if ( (v48 & 0xFF00) != 0 )
              v19 = "soft_irq";
            else
              v19 = v49;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v19,
            "cnss_genl_xdump_bt_arrival_hdl",
            6u,
            6u,
            "Received XDUMP_SUBCMD_BT_ARRIVAL: wl_over_bt: %d, bt_over_wl %d\n",
            v17 >> 1,
            v18 >> 2,
            v50);
          v41 = v8;
          v42 = 23;
          v43 = v10;
LABEL_47:
          cnss_driver_event_post(v41, v42, 0, v43);
          return 0;
      }
      v35 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v35 + 16) & 0xF0000) != 0 )
      {
        v36 = "irq";
      }
      else
      {
        v46 = *(_DWORD *)(v35 + 16);
        v47 = (const char *)(v35 + 2320);
        if ( (v46 & 0xFF00) != 0 )
          v36 = "soft_irq";
        else
          v36 = v47;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v36,
        "cnss_genl_process_xdump",
        3u,
        3u,
        "Unrecognized subcmd: %d\n",
        v7,
        v5,
        v50);
    }
    else
    {
      v22 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
      {
        v23 = "irq";
      }
      else
      {
        v37 = *(_DWORD *)(v22 + 16);
        v38 = (const char *)(v22 + 2320);
        if ( (v37 & 0xFF00) != 0 )
          v23 = "soft_irq";
        else
          v23 = v38;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v23,
        "cnss_genl_process_xdump",
        3u,
        3u,
        "No CNSS_GENL_ATTR_XDUMP_SUBCMD\n",
        v4,
        v5,
        v50);
    }
    return 4294967274LL;
  }
  v20 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v20 + 16) & 0xF0000) != 0 )
  {
    v21 = "irq";
  }
  else
  {
    v24 = *(_DWORD *)(v20 + 16);
    v25 = (const char *)(v20 + 2320);
    if ( (v24 & 0xFF00) != 0 )
      v21 = "soft_irq";
    else
      v21 = v25;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v21,
    "cnss_genl_process_xdump",
    3u,
    3u,
    "cnss not ready\n",
    v4,
    v5,
    v50);
  return 4294967277LL;
}
