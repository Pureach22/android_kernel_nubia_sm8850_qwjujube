__int64 __fastcall dsi_display_hfi_send_cmd_buf(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        unsigned int a7,
        int a8)
{
  int v8; // w23
  __int64 v12; // x8
  int v15; // w20
  _QWORD *cmd_buf; // x0
  __int64 v18; // x21
  int v19; // w6
  int v20; // w2
  int v21; // w4
  int v22; // w5
  int v23; // w0
  unsigned int v24; // w20
  int v25; // w7
  char v26; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    v8 = a8;
    v12 = *(_QWORD *)(a1 + 16);
    if ( a3 - 33554438 >= 5 )
    {
      if ( a3 == 33554443 )
        v8 = 0;
    }
    else
    {
      v8 = a8 | 2;
    }
    if ( v12 )
      v15 = *(_DWORD *)(v12 + 2740);
    else
      v15 = -1;
    cmd_buf = hfi_adapter_get_cmd_buf(a2);
    if ( cmd_buf )
    {
      v18 = (__int64)cmd_buf;
      if ( (v8 & 2) != 0 )
      {
        if ( (unsigned int)hfi_adapter_add_get_property((__int64)cmd_buf, a3, v15, a5, a6, a7, a1 + 1696, v8) )
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: could not set property for hfi_cmd 0x%x\n", a3);
        sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_hfi_send_cmd_buf", 367, -1, v15, a3, 13107, -1059143953, v26);
        v19 = hfi_adapter_set_cmd_buf_blocking(v18);
        v20 = 369;
        v21 = v15;
        v23 = sde_dbg_base_evtlog;
        v22 = a3;
        v24 = v19;
        v25 = 17476;
      }
      else
      {
        if ( (unsigned int)hfi_adapter_add_set_property((__int64)cmd_buf, a3, v15, a5, a6, a7, v8) )
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: could not set property for hfi_cmd 0x%x\n", a3);
        v19 = hfi_adapter_set_cmd_buf(v18);
        v20 = 377;
        v21 = v15;
        v22 = a3;
        v23 = sde_dbg_base_evtlog;
        v24 = v19;
        v25 = 21845;
      }
      sde_evtlog_log(v23, "dsi_display_hfi_send_cmd_buf", v20, -1, v21, v22, v19, v25, 239);
      if ( v24 )
      {
        printk(&unk_253404, a3);
        return v24;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: could not get cmd_buf for hfi_cmd 0x%x\n", a3);
      return 4294967277LL;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display\n");
    return 4294967274LL;
  }
}
