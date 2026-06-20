__int64 __fastcall dsi_display_process_dcs_cmd_bitmask(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  char v5; // w23
  int v6; // w8
  unsigned __int64 v7; // x6
  int v8; // w9
  char v9; // w8
  int v10; // w0
  unsigned __int64 v11; // x7
  unsigned int v13; // w20

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 72);
    v4 = 0;
    v5 = 0;
    while ( 1 )
    {
      v11 = *(_QWORD *)(a2 + 8);
      if ( ((v11 >> v4) & 1) != 0 )
      {
        if ( v11 )
        {
          v6 = __clz(v11);
          v7 = HIDWORD(v11);
          v8 = v4 ^ v6;
          v9 = 64 - v6;
          v5 |= v8 == 63;
        }
        else
        {
          LODWORD(v7) = 0;
          v9 = 0;
        }
        sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_process_dcs_cmd_bitmask", 9248, -1, v4, v5 & 1, v7, v11, v9);
        v10 = dsi_panel_send_cmd(*(_QWORD *)(a1 + 264), a2, (unsigned int)v4, v5 & 1);
        if ( v10 )
          break;
      }
      if ( ++v4 == 64 )
      {
        v13 = 0;
        goto LABEL_13;
      }
    }
    v13 = v10;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: fail cmd idx:%d rc:%d\n", v4, v10);
LABEL_13:
    mutex_unlock(a1 + 72);
    return v13;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return 4294967274LL;
  }
}
