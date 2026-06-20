// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall gsi_set_alt(__int64 a1, int a2, unsigned int a3)
{
  unsigned int v3; // w20
  _QWORD *v6; // x22
  __int64 result; // x0
  _QWORD *v8; // x2
  int v9; // w0
  __int64 v10; // x8
  void *v11; // x0
  int v12; // w0
  unsigned int v13; // w8
  _QWORD *v14; // x9
  unsigned int v15; // w20
  _QWORD *v16; // x9
  char v17; // w9
  __int64 v18; // x0
  unsigned __int64 netdev; // x0
  _QWORD *v20; // x0
  _QWORD *v21; // x8
  unsigned __int64 v22; // x21
  __int64 v23; // x0
  unsigned int v24; // w21

  v3 = a3;
  v6 = *(_QWORD **)(*(_QWORD *)(a1 + 48) + 48LL);
  if ( a1 )
    ipc_log_string(*(_QWORD *)(a1 + 1344), "intf=%u, alt=%u", a2, a3);
  if ( *(_DWORD *)(a1 + 228) == a2 || *(_DWORD *)(a1 + 224) == 2 )
  {
    if ( v3 )
      return 4294967274LL;
    v8 = *(_QWORD **)(a1 + 1208);
    if ( !v8 )
      return 4294967274LL;
    if ( *v8 )
    {
      if ( a1 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 1344), "reset gsi control %d", a2);
        v8 = *(_QWORD **)(a1 + 1208);
      }
      usb_ep_disable(v8);
    }
    v9 = config_ep_by_speed(*v6, a1);
    if ( v9 )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 1208) + 24LL) = 0;
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1344),
          "Config-fail notify ep %s: err %d",
          *(const char **)(*(_QWORD *)(a1 + 1208) + 8LL),
          v9);
        v10 = *(_QWORD *)(a1 + 1208);
        v11 = &unk_1171C;
LABEL_19:
        printk(v11, *(_QWORD *)(v10 + 8));
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    v12 = usb_ep_enable(*(_QWORD *)(a1 + 1208));
    if ( v12 )
    {
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1344),
          "usb ep#%s enable failed, err#%d",
          *(const char **)(*(_QWORD *)(a1 + 1208) + 8LL),
          v12);
        v10 = *(_QWORD *)(a1 + 1208);
        v11 = &unk_10795;
        goto LABEL_19;
      }
      return 4294967274LL;
    }
    **(_QWORD **)(a1 + 1208) = a1;
  }
  if ( *(_DWORD *)(a1 + 232) != a2 )
  {
    result = 0;
    goto LABEL_28;
  }
  v13 = *(_DWORD *)(a1 + 224);
  *(_BYTE *)(a1 + 561) = 0;
  if ( v13 <= 4 && ((1 << v13) & 0x15) != 0 )
  {
    v14 = *(_QWORD **)(a1 + 304);
    v3 = v14 && !*v14;
  }
  else if ( v3 > 1 )
  {
LABEL_48:
    v20 = *(_QWORD **)(a1 + 1208);
    if ( v20 )
    {
      if ( *v20 )
        usb_ep_disable(v20);
    }
    return 4294967274LL;
  }
  if ( v3 == *(unsigned __int8 *)(a1 + 276) )
    return 0;
  v16 = *(_QWORD **)(a1 + 304);
  if ( !v16 )
  {
    if ( v3 )
    {
LABEL_44:
      if ( *(_QWORD *)(a1 + 312) )
        *(_BYTE *)(a1 + 460) = 1;
      *(_QWORD *)(a1 + 496) = *v6;
      *(_QWORD *)(a1 + 504) = v6;
      if ( !v13 )
      {
        v18 = gsi_rndis_open(a1);
        netdev = gsi_rndis_get_netdev(v18);
        if ( netdev > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_48;
        v22 = netdev;
        if ( a1 )
          ipc_log_string(*(_QWORD *)(a1 + 1344), "RNDIS RX/TX early activation");
        v23 = *(_QWORD *)(a1 + 264);
        *(_WORD *)(a1 + 550) = 0;
        rndis_set_param_dev(v23, v22, a1 + 550);
        v13 = *(_DWORD *)(a1 + 224);
      }
      if ( v13 == 1 )
        *(_WORD *)(a1 + 550) = 15;
      post_event(a1 + 304, 3);
      queue_delayed_work_on(32, *(_QWORD *)(a1 + 680), a1 + 576, 1);
      result = 0x7FFF;
LABEL_63:
      *(_BYTE *)(a1 + 276) = v3;
      if ( !a1 )
        goto LABEL_28;
      goto LABEL_64;
    }
    goto LABEL_52;
  }
  if ( *v16 )
    *(_DWORD *)(a1 + 564) = 0x4000;
  if ( v3 )
  {
    if ( v13 == 4 )
      v17 = 3;
    else
      v17 = 2;
    *(_BYTE *)(a1 + 372) = v17;
    goto LABEL_44;
  }
  if ( *v16 )
  {
LABEL_52:
    v21 = *(_QWORD **)(a1 + 312);
    if ( !v21 || *v21 )
    {
      result = 0;
      goto LABEL_63;
    }
  }
  post_event(a1 + 304, 7);
  queue_delayed_work_on(32, *(_QWORD *)(a1 + 680), a1 + 576, 0);
  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: Disconnecting\n", "gsi_set_alt");
    LODWORD(result) = 0;
    *(_BYTE *)(a1 + 276) = v3;
LABEL_64:
    v24 = result;
    ipc_log_string(*(_QWORD *)(a1 + 1344), "DATA_INTERFACE id = %d, status = %d", *(_DWORD *)(a1 + 232), v3);
    result = v24;
    goto LABEL_28;
  }
  result = 0;
  unk_114 = v3;
LABEL_28:
  *(_DWORD *)(a1 + 272) = 1;
  if ( *(_DWORD *)(a1 + 224) == 4 )
  {
    v15 = result;
    gsi_ctrl_send_cpkt_tomodem(a1, 0, 0);
    return v15;
  }
  return result;
}
