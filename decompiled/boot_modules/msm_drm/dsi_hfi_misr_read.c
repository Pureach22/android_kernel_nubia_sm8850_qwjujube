__int64 __fastcall dsi_hfi_misr_read(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x22
  unsigned int v3; // w19
  __int64 v4; // x21
  __int64 v5; // x0
  _QWORD *cmd_buf; // x0
  __int64 v7; // x20
  unsigned int v8; // w20
  __int64 result; // x0
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_11;
  v1 = *(_QWORD *)(a1 + 1688);
  if ( !v1 )
    goto LABEL_11;
  v2 = *(_QWORD *)(a1 + 16);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 2740);
    v4 = a1;
  }
  else
  {
    v4 = a1;
    v3 = -1;
  }
  v5 = *(_QWORD *)(v1 + 8);
  v10[0] = 0;
  cmd_buf = hfi_adapter_get_cmd_buf(v5);
  if ( !cmd_buf )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to get valid command buffer\n");
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v7 = (__int64)cmd_buf;
  v10[0] = v3;
  if ( (unsigned int)hfi_adapter_add_get_property((__int64)cmd_buf, -16777208, v3, 2u, (__int64)v10, 8u, v4 + 1696, 6) )
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to add MISR read command\n");
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_hfi_misr_read", 198, -1, *(_DWORD *)(v2 + 64), v3, -16777208, 13107, 239);
  v8 = hfi_adapter_set_cmd_buf_blocking(v7);
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_hfi_misr_read", 201, -1, *(_DWORD *)(v2 + 64), v3, -16777208, v8, 68);
  result = v8;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
