__int64 __fastcall dsi_display_status_reg_read(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  long double v4; // q0
  unsigned int v5; // w22
  int v6; // w0
  long double v7; // q0
  unsigned int v8; // w8
  int v9; // w0
  unsigned int v10; // w20
  unsigned int v11; // w0

  *(double *)&v4 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]:  ++\n");
  v5 = *(_DWORD *)(a1 + 840);
  if ( v5 < 3 )
  {
    if ( !*(_QWORD *)(a1 + 1224) )
    {
      v11 = dsi_host_alloc_cmd_tx_buffer(a1);
      if ( v11 )
      {
        v10 = v11;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate cmd tx buffer memory\n");
        return v10;
      }
    }
    v6 = dsi_display_validate_status(a1 + 168 + 48LL * v5, a1, v4);
    if ( v6 <= 0 )
    {
      v10 = v6;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] read status failed on master,rc=%d\n",
        *(_QWORD *)(a1 + 32),
        (unsigned int)v6);
      return v10;
    }
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2200LL) != 1 )
      return 1;
    v8 = *(_DWORD *)(a1 + 160);
    if ( !v8 )
      return 1;
    if ( v5 )
    {
      v9 = dsi_display_validate_status(a1 + 168, a1, v7);
      if ( v9 < 1 )
      {
LABEL_12:
        v10 = v9;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] read status failed on slave,rc=%d\n",
          *(_QWORD *)(a1 + 32),
          (unsigned int)v9);
        return v10;
      }
      v8 = *(_DWORD *)(a1 + 160);
    }
    v10 = 1;
    if ( v8 < 2 )
      return v10;
    if ( v5 == 1 )
      return v10;
    v9 = dsi_display_validate_status(a1 + 216, a1, v7);
    if ( v9 >= 1 )
      return v10;
    goto LABEL_12;
  }
  __break(0x5512u);
  return dsi_display_status_check_te(v2, v3, v4);
}
