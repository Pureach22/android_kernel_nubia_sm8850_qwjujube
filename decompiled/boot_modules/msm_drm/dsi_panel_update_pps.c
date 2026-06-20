__int64 __fastcall dsi_panel_update_pps(const char **a1)
{
  __int64 v2; // x1
  __int64 v3; // x21
  int v4; // w9
  unsigned int v5; // w20
  int v6; // w9
  int v7; // w0
  unsigned __int64 v8; // x22
  __int64 v9; // x23

  if ( a1 && a1[178] )
  {
    mutex_lock(a1 + 130);
    v3 = *((_QWORD *)a1[178] + 23);
    if ( *(_BYTE *)(v3 + 3400) == 1 )
    {
      v4 = *(_DWORD *)(v3 + 2688);
      *(_DWORD *)((char *)a1 + 2049) = 266;
      *((_BYTE *)a1 + 2053) = v4;
      *((_WORD *)a1 + 1027) = 0x8000;
      sde_dsc_create_pps_buf_cmd(v3 + 2496, (char *)a1 + 2056, 0, 0x80u);
    }
    else if ( *(_BYTE *)(v3 + 3401) == 1 )
    {
      v6 = *(_DWORD *)(v3 + 3352);
      *(_DWORD *)((char *)a1 + 2049) = 266;
      *((_BYTE *)a1 + 2053) = v6;
      *((_WORD *)a1 + 1027) = 0x8000;
      sde_vdc_create_pps_buf_cmd(v3 + 2712, (_BYTE *)a1 + 2056, 0, 0x80u);
    }
    if ( ((*(_BYTE *)(v3 + 3400) & 1) != 0 || *(_BYTE *)(v3 + 3401) == 1)
      && (v7 = ((__int64 (__fastcall *)(char *, __int64, __int64, _QWORD))dsi_panel_create_cmd_packets)(
                 (char *)a1 + 2049,
                 v2,
                 1,
                 *(_QWORD *)(v3 + 776))) != 0 )
    {
      v5 = v7;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to create cmd packets, rc=%d\n", v7);
    }
    else
    {
      v5 = dsi_panel_tx_cmd_set(a1, 0x13u, 0);
      if ( v5 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_PPS cmds, rc=%d\n",
          *a1,
          v5);
      if ( *(_DWORD *)(v3 + 768) )
      {
        v8 = 0;
        v9 = 16;
        do
        {
          kfree(*(_QWORD *)(*(_QWORD *)(v3 + 776) + v9));
          ++v8;
          v9 += 64;
        }
        while ( v8 < *(unsigned int *)(v3 + 768) );
      }
    }
    mutex_unlock(a1 + 130);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return (unsigned int)-22;
  }
  return v5;
}
