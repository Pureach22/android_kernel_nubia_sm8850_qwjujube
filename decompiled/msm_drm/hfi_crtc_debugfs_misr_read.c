__int64 __fastcall hfi_crtc_debugfs_misr_read(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x21
  int display_id; // w0
  int v7; // w19
  _QWORD *cmd_buf; // x0
  __int64 v9; // x20
  unsigned int v10; // w20
  __int64 result; // x0
  void *v12; // x0
  _DWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_15;
  if ( !*a1 )
    goto LABEL_15;
  v1 = *(_QWORD *)(*a1 + 56LL);
  if ( !v1 )
    goto LABEL_15;
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 )
    goto LABEL_15;
  v3 = *(_QWORD *)(v2 + 6440);
  if ( !v3 )
    goto LABEL_15;
  v4 = a1[1004];
  if ( !v4 )
    goto LABEL_15;
  display_id = hfi_crtc_get_display_id(a1, a1[251]);
  if ( display_id == -1 )
  {
    v12 = &unk_231479;
LABEL_14:
    printk(v12, "hfi_crtc_debugfs_misr_read");
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  v7 = display_id;
  cmd_buf = hfi_adapter_get_cmd_buf(v3 + 8);
  if ( !cmd_buf )
  {
    v12 = &unk_2426FC;
    goto LABEL_14;
  }
  *(_QWORD *)(v4 + 80) = hfi_crtc_misr_read_hfi_prop_handler;
  v9 = (__int64)cmd_buf;
  v13[0] = v7;
  v13[1] = 1;
  if ( (unsigned int)hfi_adapter_add_get_property((__int64)cmd_buf, -16777208, v7, 2u, (__int64)v13, 8u, v4 + 80, 6) )
    printk(&unk_22A770, "hfi_crtc_debugfs_misr_read");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "hfi_crtc_debugfs_misr_read",
    598,
    -1,
    *((_DWORD *)a1 + 28),
    v7,
    -16777208,
    13107,
    239);
  v10 = hfi_adapter_set_cmd_buf_blocking(v9);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "hfi_crtc_debugfs_misr_read",
    600,
    -1,
    *((_DWORD *)a1 + 28),
    v7,
    -16777208,
    v10,
    68);
  result = v10;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
