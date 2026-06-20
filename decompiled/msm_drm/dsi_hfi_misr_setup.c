__int64 __fastcall dsi_hfi_misr_setup(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  int v3; // w19
  _QWORD *cmd_buf; // x0
  unsigned int v6; // w9
  __int64 v7; // x20
  unsigned int v8; // w0
  unsigned int v9; // w20
  __int64 result; // x0
  unsigned __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int64 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v1 = *(_QWORD *)(a1 + 1688)) != 0 && (v2 = *(_QWORD *)(a1 + 16)) != 0 )
  {
    v11 = 0;
    v12 = 0;
    v3 = *(_DWORD *)(v2 + 2740);
    cmd_buf = hfi_adapter_get_cmd_buf(*(_QWORD *)(v1 + 8));
    if ( cmd_buf )
    {
      v6 = *(_DWORD *)(a1 + 1348);
      v11 = __PAIR64__(*(unsigned __int8 *)(a1 + 1344), v3);
      v12 = v6;
      v7 = (__int64)cmd_buf;
      v8 = hfi_adapter_add_set_property((__int64)cmd_buf, -16777209, v3, 2u, (__int64)&v11, 0x10u, 0);
      if ( v8 )
      {
        v9 = v8;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to add property\n");
      }
      else
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: misr_setup: sending cmd buf\n");
        v9 = hfi_adapter_set_cmd_buf(v7);
        sde_evtlog_log(sde_dbg_base_evtlog, "dsi_hfi_misr_setup", 121, -1, v3, -16777209, v9, 13107, 239);
        if ( !v9 )
        {
          result = 0;
          goto LABEL_12;
        }
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to send misr_setup command\n");
      }
    }
    else
    {
      v9 = -22;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to get valid command buffer\n");
    }
    result = v9;
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
