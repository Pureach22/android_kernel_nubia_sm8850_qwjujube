__int64 __fastcall zte_dsi_panel_update_backlight(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v4; // w19
  __int64 v5; // x1
  __int64 v6; // x23
  __int64 v7; // x1
  unsigned int v8; // w24
  __int64 v9; // x9
  int v10; // w10
  int v11; // w23
  unsigned int v12; // w8
  __int64 v13; // x19
  unsigned int v14; // w25
  int v15; // w26
  __int64 v16; // x0
  int v17; // w8
  unsigned int v18; // w19
  int v19; // w24

  if ( !a1 || (unsigned int)a2 >= 0x10000 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
  v4 = a2;
  printk(&unk_267639, a2);
  if ( !v4 )
    goto LABEL_10;
  if ( *(_BYTE *)(a1 + 2556) == 1 && (*(_BYTE *)(a1 + 2557) & 1) == 0 )
  {
    v5 = *(unsigned int *)(a1 + 2220);
LABEL_31:
    printk(&unk_259030, v5);
    result = 0;
    v9 = a1;
    v10 = v4;
    goto LABEL_27;
  }
  v5 = *(unsigned int *)(a1 + 2220);
  if ( (unsigned int)(v5 - 1) <= 1 )
    goto LABEL_31;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 2312) + 40LL) != zte_dsi_panel_update_backlight_last_fps
    && zte_dsi_panel_update_backlight_last_brightness == v4 )
  {
    printk(&unk_222B8C, v5);
    v10 = v4;
    v9 = a1;
    result = 0;
    goto LABEL_27;
  }
LABEL_10:
  if ( *(_BYTE *)(a1 + 1576) == 1 )
  {
    v6 = *(_QWORD *)(a1 + 984);
    *(_QWORD *)(a1 + 984) = v6 | 0x800;
  }
  else
  {
    v6 = 0;
  }
  if ( *(_BYTE *)(a1 + 1512) )
    v4 = ((unsigned __int8)v4 << 8) | (v4 >> 8);
  result = mipi_dsi_dcs_set_display_brightness(a1 + 24, v4);
  if ( (result & 0x80000000) != 0 )
  {
    v8 = result;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to update dcs backlight:%d\n", v4);
    result = v8;
  }
  v9 = a1;
  if ( *(_BYTE *)(a1 + 1576) == 1 )
    *(_QWORD *)(a1 + 984) = v6;
  if ( *(_BYTE *)(a1 + 1512) )
    v10 = ((unsigned __int8)v4 << 8) | (v4 >> 8);
  else
    v10 = v4;
  v11 = v10 != 0;
  if ( (unsigned __int8)dsi_panel_dim_handle_last_en == v11 )
    goto LABEL_26;
  if ( !v10 )
  {
LABEL_25:
    v12 = *(_DWORD *)(a1 + 2444);
    v13 = *(_QWORD *)(a1 + 2432);
    v14 = result;
    v15 = v10;
    *(_DWORD *)(a1 + 2440) = v10 != 0;
    v16 = _msecs_to_jiffies(v12);
    queue_delayed_work_on(32, v13, a1 + 2328, v16);
    result = v14;
    v10 = v15;
    v9 = a1;
    dsi_panel_dim_handle_last_en = v11;
    goto LABEL_26;
  }
  if ( (unsigned int)(*(_DWORD *)(a1 + 2220) - 1) >= 2 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 2312) + 8LL) )
    {
      v18 = result;
      v19 = v10;
      printk(&unk_22CB1C, v7);
      result = v18;
      v10 = v19;
      v9 = a1;
      goto LABEL_26;
    }
    goto LABEL_25;
  }
LABEL_26:
  *(_BYTE *)(v9 + 2558) = v11;
LABEL_27:
  v17 = *(_DWORD *)(*(_QWORD *)(v9 + 2312) + 40LL);
  zte_dsi_panel_update_backlight_last_brightness = v10;
  *(_DWORD *)(v9 + 2320) = v10;
  zte_dsi_panel_update_backlight_last_fps = v17;
  return result;
}
