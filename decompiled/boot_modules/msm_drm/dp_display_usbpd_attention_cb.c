__int64 __fastcall dp_display_usbpd_attention_cb(__int64 a1)
{
  __int64 v1; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  unsigned int v7; // w9
  unsigned __int64 StatusReg; // x23
  __int64 v9; // x9
  int v10; // w8
  __int64 v11; // x0
  __int64 v12; // x9
  unsigned int v13; // w20
  __int64 v14; // x21
  int v15; // w22
  const char *v16; // x0
  int v17; // w6
  int v18; // w7
  int v19; // w21
  int v20; // w20
  const char *v21; // x0
  __int64 v22; // x0
  char v23; // [xsp+0h] [xbp-10h]

  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 152);
    if ( v3 )
    {
      if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v5 = 0;
      v6 = *(_QWORD *)(v3 + 128);
      v7 = *(_DWORD *)(v3 + 12);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        v5,
        "[i][%-4d]: hpd_irq:%d, hpd_high:%d, power_on:%d, is_connected:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(unsigned __int8 *)(v6 + 9),
        *(unsigned __int8 *)(v6 + 8),
        (v7 >> 6) & 1,
        (v7 >> 3) & 1);
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_21C954, *(unsigned int *)(StatusReg + 1800));
      else
        printk(&unk_264DEF, "dp_display_usbpd_attention_cb");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_usbpd_attention_cb",
        2087,
        8,
        *(_DWORD *)(v3 + 12),
        *(unsigned __int8 *)(*(_QWORD *)(v3 + 128) + 9LL),
        *(unsigned __int8 *)(*(_QWORD *)(v3 + 128) + 8LL),
        (*(_DWORD *)(v3 + 12) >> 6) & 1,
        (*(_DWORD *)(v3 + 12) & 8) != 0);
      v9 = *(_QWORD *)(v3 + 128);
      if ( (*(_BYTE *)(v9 + 8) & 1) != 0 )
      {
        v10 = *(_DWORD *)(v3 + 12);
        if ( (v10 & 0x800) != 0 )
        {
          if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v22 = 0;
          ipc_log_string(v22, "[w][%-4d]TUI is active\n", *(_DWORD *)(StatusReg + 1800));
          printk(&unk_26F583, "dp_display_usbpd_attention_cb");
        }
        else if ( (v10 & 4) != 0 && (*(_BYTE *)(v9 + 9) & 1) != 0 )
        {
          queue_work_on(32, *(_QWORD *)(v3 + 1520), v3 + 1664);
          complete_all(v3 + 96);
        }
        else if ( (v10 & 8) == 0 || (*(_BYTE *)(v3 + 1888) & 1) != 0 )
        {
          v12 = g_dp_display;
          v13 = v10 & 0xFFFFF6FF;
          *(_DWORD *)(v3 + 12) = v10 & 0xFFFFF6FF;
          if ( !v12 || (v14 = *(_QWORD *)(v12 + 56)) == 0 )
            v14 = 0;
          v15 = *(_DWORD *)(StatusReg + 1800);
          v16 = dp_display_state_name(v13);
          ipc_log_string(v14, "[d][%-4d]%s: state (0x%x): %s\n", v15, "remove DP_STATE_ABORTED", v13, v16);
          if ( (_drm_debug & 4) != 0 )
          {
            v19 = *(_DWORD *)(v3 + 12);
            v20 = *(_DWORD *)(StatusReg + 1800);
            v21 = dp_display_state_name(v19);
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
              v20,
              "remove DP_STATE_ABORTED",
              v19,
              v21);
          }
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "dp_display_usbpd_attention_cb",
            2113,
            8,
            *(_DWORD *)(v3 + 12),
            -1059143953,
            v17,
            v18,
            v23);
          queue_work_on(32, *(_QWORD *)(v3 + 1520), v3 + 1632);
        }
        else
        {
          if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v11 = 0;
          ipc_log_string(v11, "[d][%-4d]ignored\n", *(_DWORD *)(StatusReg + 1800));
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]ignored\n", *(_DWORD *)(StatusReg + 1800));
        }
      }
      else
      {
        dp_display_disconnect_sync(v3);
      }
      return 0;
    }
    else
    {
      if ( !g_dp_display || (v4 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v4 = 0;
      ipc_log_string(v4, "[e][%-4d]no driver data found\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_26F6F4, "dp_display_usbpd_attention_cb");
      return 4294967277LL;
    }
  }
  else
  {
    if ( !g_dp_display || (v1 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v1 = 0;
    ipc_log_string(v1, "[e][%-4d]invalid dev\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24218F, "dp_display_usbpd_attention_cb");
    return 4294967274LL;
  }
}
