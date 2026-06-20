__int64 __fastcall dp_altmode_set_usb_dp_mode(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 device_by_node; // x0
  __int64 v6; // x21
  int v7; // w25
  unsigned __int64 StatusReg; // x26
  __int64 v9; // x0
  __int64 v11; // x0
  unsigned int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 ipc_log_context; // x0
  void *v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  _QWORD v20[11]; // [xsp+8h] [xbp-58h] BYREF

  v20[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v1 = *(_QWORD *)(a1 + 8)) == 0 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid args\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_27C178;
LABEL_15:
    printk(v16, "dp_altmode_set_usb_dp_mode");
    v12 = -22;
    goto LABEL_16;
  }
  v3 = *(_QWORD *)(v1 + 744);
  memset(v20, 0, 80);
  v4 = _of_parse_phandle_with_args(v3, "usb-controller", 0, 0, 0, v20);
  if ( (_DWORD)v4 || (v4 = v20[0]) == 0 )
  {
    v17 = get_ipc_log_context(v4);
    ipc_log_string(v17, "[e][%-4d]unable to get usb node\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_247FE0;
    goto LABEL_15;
  }
  device_by_node = of_find_device_by_node();
  if ( !device_by_node )
  {
    v18 = get_ipc_log_context(0);
    ipc_log_string(v18, "[e][%-4d]unable to get usb pdev\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v16 = &unk_229850;
    goto LABEL_15;
  }
  v6 = device_by_node;
  v7 = -250;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v11 = dwc3_msm_set_dp_mode(v6 + 16, *(unsigned __int8 *)(a1 + 104), *(unsigned int *)(a1 + 108));
    v12 = v11;
    if ( (_DWORD)v11 != -11 && (_DWORD)v11 != -16 )
      break;
    v9 = get_ipc_log_context(v11);
    ipc_log_string(v9, "[w][%-4d]USB busy, retry\n", *(_DWORD *)(StatusReg + 1800));
    printk(&unk_22CDFD, "dp_altmode_set_usb_dp_mode");
    msleep(20);
    if ( __CFADD__(v7++, 1) )
    {
      v13 = platform_device_put(v6);
      goto LABEL_11;
    }
  }
  v13 = platform_device_put(v6);
  if ( !v12 )
    goto LABEL_16;
LABEL_11:
  v14 = get_ipc_log_context(v13);
  ipc_log_string(v14, "[e][%-4d]Error releasing SS lanes: %d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v12);
  printk(&unk_23A834, "dp_altmode_set_usb_dp_mode");
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v12;
}
