__int64 __fastcall hfi_crtc_debugfs_misr_setup(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x20
  int display_id; // w0
  int v6; // w19
  _QWORD *cmd_buf; // x0
  int v8; // w9
  int v9; // w8
  __int64 v10; // x20
  unsigned int v11; // w0
  unsigned int v12; // w20
  __int64 result; // x0
  void *v14; // x0
  unsigned int v15; // w19
  _DWORD v16[4]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v14 = &unk_211DA1;
LABEL_14:
    printk(v14, "hfi_crtc_debugfs_misr_setup");
LABEL_15:
    result = 4294967274LL;
    goto LABEL_16;
  }
  if ( !*(_QWORD *)a1 )
    goto LABEL_15;
  v1 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v1 )
    goto LABEL_15;
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 )
    goto LABEL_15;
  v3 = *(_QWORD *)(v2 + 6440);
  if ( !v3 )
    goto LABEL_15;
  display_id = hfi_crtc_get_display_id((__int64 *)a1, *(_QWORD *)(a1 + 2008));
  if ( display_id == -1 )
  {
    v14 = &unk_231479;
    goto LABEL_14;
  }
  v6 = display_id;
  cmd_buf = hfi_adapter_get_cmd_buf(v3 + 8);
  if ( !cmd_buf )
  {
    v14 = &unk_2426FC;
    goto LABEL_14;
  }
  v8 = *(_DWORD *)(a1 + 7360);
  v9 = *(unsigned __int8 *)(a1 + 7357);
  v16[0] = v6;
  v16[1] = v9;
  v10 = (__int64)cmd_buf;
  v16[2] = v8;
  v16[3] = 1;
  v11 = hfi_adapter_add_set_property((__int64)cmd_buf, -16777209, v6, 2u, (__int64)v16, 0x10u, 0);
  if ( v11 )
  {
    v15 = v11;
    printk(&unk_2314A6, "hfi_crtc_debugfs_misr_setup");
    result = v15;
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "misr_setup: sending cmd buf\n");
    v12 = hfi_adapter_set_cmd_buf(v10);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "hfi_crtc_debugfs_misr_setup",
      503,
      -1,
      *(_DWORD *)(a1 + 112),
      v6,
      -16777209,
      v12,
      51);
    if ( v12 )
    {
      printk(&unk_25E1BA, "hfi_crtc_debugfs_misr_setup");
      result = v12;
    }
    else
    {
      result = 0;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
