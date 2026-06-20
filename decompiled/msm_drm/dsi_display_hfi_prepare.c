__int64 __fastcall dsi_display_hfi_prepare(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x1
  unsigned int v4; // w20
  __int64 *v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x20
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x3
  void *v14; // x0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    v4 = 0;
    goto LABEL_20;
  }
  v2 = dsi_display_hfi_panel_enable_supplies(a1, 1);
  if ( !v2 )
  {
    v5 = *(__int64 **)(a1 + 16);
    if ( v5 && (v6 = *v5) != 0 && (v7 = *(_QWORD *)(v6 + 56)) != 0 )
    {
      v8 = *(_QWORD *)(v7 + 8);
      if ( v8 )
      {
        v9 = *(_QWORD *)(v8 + 6440);
        if ( v9 )
        {
          v10 = *(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL);
          v11 = _kvmalloc_node_noprof(76, 0, 3520, 0xFFFFFFFFLL);
          v12 = v11;
          if ( v11 )
          {
            v13 = *(_QWORD *)(a1 + 40);
            *(_DWORD *)v11 = 76;
            *(_DWORD *)(v11 + 4) = *(_DWORD *)v10;
            *(_DWORD *)(v11 + 8) = *(_DWORD *)(v10 + 4);
            *(_DWORD *)(v11 + 12) = *(_DWORD *)(v10 + 8);
            *(_DWORD *)(v11 + 16) = *(_DWORD *)(v10 + 12);
            *(_DWORD *)(v11 + 20) = *(_DWORD *)(v10 + 16);
            *(_DWORD *)(v11 + 24) = *(unsigned __int8 *)(v10 + 20);
            *(_DWORD *)(v11 + 28) = *(_DWORD *)(v10 + 24);
            *(_DWORD *)(v11 + 32) = *(_DWORD *)(v10 + 28);
            *(_DWORD *)(v11 + 36) = *(_DWORD *)(v10 + 32);
            *(_DWORD *)(v11 + 40) = *(_DWORD *)(v10 + 36);
            *(_DWORD *)(v11 + 44) = *(unsigned __int8 *)(v10 + 40);
            *(_DWORD *)(v11 + 48) = *(_DWORD *)(v10 + 44);
            *(_QWORD *)(v11 + 52) = *(_QWORD *)(v10 + 48);
            *(_DWORD *)(v11 + 60) = *(_DWORD *)(v10 + 156);
            v4 = dsi_display_hfi_send_cmd_buf(a1, v9 + 8, 33554442, v13, 2, v11, 76, 4);
            if ( !v4 )
            {
              kfree(v12);
              goto LABEL_20;
            }
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: Could not send HFI_COMMAND_DISPLAY_SET_MODE, rc=%d\n",
              v4);
            kfree(v12);
          }
          else
          {
            v4 = -12;
          }
        }
        else
        {
          v4 = -22;
        }
LABEL_19:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: set mode failed, rc=%d\n", v4);
        goto LABEL_20;
      }
      v14 = &unk_22A98C;
    }
    else
    {
      v14 = &unk_2207A9;
    }
    printk(v14, v3);
    v4 = -22;
    goto LABEL_19;
  }
  v4 = v2;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: [%s] dsi panel power supply %s failed, rc=%d\n",
    *(const char **)(a1 + 32),
    "enable",
    v2);
LABEL_20:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: DSI core power, enable=%d\n", "dsi_display_hfi_prepare", 1);
  return v4;
}
