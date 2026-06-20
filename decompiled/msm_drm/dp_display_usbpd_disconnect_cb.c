__int64 __fastcall dp_display_usbpd_disconnect_cb(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 v3; // x0
  unsigned __int64 v4; // x20
  int v5; // w7
  int v6; // w0
  int v7; // w5
  int v8; // w2
  int v9; // w4
  __int64 v11; // x0
  __int64 v12; // x0
  void (*v13)(void); // x9
  void (*v14)(void); // x8
  void (*v15)(void); // x8
  void (*v16)(void); // x8
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  int v23; // w7
  __int64 v24; // x8
  unsigned int v25; // w20
  __int64 v26; // x21
  unsigned __int64 StatusReg; // x24
  int v28; // w22
  const char *v29; // x0
  int v30; // w6
  int v31; // w7
  int v32; // w21
  int v33; // w20
  const char *v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x8
  void *v38; // x0
  __int64 v39; // x0
  char v40; // [xsp+0h] [xbp+0h]
  char v41; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 152);
    if ( v1 )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_usbpd_disconnect_cb",
        1853,
        8,
        4369,
        *(_DWORD *)(v1 + 12),
        *(unsigned __int8 *)(*(_QWORD *)(v1 + 192) + 1LL),
        -1059143953,
        v40);
      v2 = *(_DWORD *)(v1 + 12);
      if ( (~v2 & 0x104) != 0 )
      {
        if ( (v2 & 4) != 0 && (*(_BYTE *)(*(_QWORD *)(v1 + 192) + 1LL) & 1) != 0 )
        {
          v13 = *(void (**)(void))(*(_QWORD *)(v1 + 168) + 192LL);
          if ( *((_DWORD *)v13 - 1) != -187382708 )
            __break(0x8229u);
          v13();
        }
        v14 = *(void (**)(void))(*(_QWORD *)(v1 + 184) + 32LL);
        if ( *((_DWORD *)v14 - 1) != -1878159161 )
          __break(0x8228u);
        v14();
        v15 = *(void (**)(void))(*(_QWORD *)(v1 + 160) + 80LL);
        if ( *((_DWORD *)v15 - 1) != 532007358 )
          __break(0x8228u);
        v15();
        if ( (**(_BYTE **)(v1 + 192) & 1) == 0
          && (*(_BYTE *)(v1 + 1825) & 1) == 0
          && (*(_BYTE *)(*(_QWORD *)(v1 + 136) + 732LL) & 1) == 0 )
        {
          v16 = *(void (**)(void))(*(_QWORD *)(v1 + 160) + 96LL);
          if ( v16 )
          {
            if ( *((_DWORD *)v16 - 1) != 1205381171 )
              __break(0x8228u);
            v16();
          }
        }
        dp_display_disconnect_sync(v1);
        mutex_lock(v1 + 1728);
        dp_display_host_deinit(v1, v17, v18, v19, v20, v21, v22, v23);
        v24 = g_dp_display;
        v25 = *(_DWORD *)(v1 + 12) & 0xFFFFFFFE;
        *(_DWORD *)(v1 + 12) = v25;
        if ( !v24 || (v26 = *(_QWORD *)(v24 + 56)) == 0 )
          v26 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        v28 = *(_DWORD *)(StatusReg + 1800);
        v29 = dp_display_state_name(v25);
        ipc_log_string(v26, "[d][%-4d]%s: state (0x%x): %s\n", v28, "remove DP_STATE_CONFIGURED", v25, v29);
        if ( (_drm_debug & 4) != 0 )
        {
          v32 = *(_DWORD *)(v1 + 12);
          v33 = *(_DWORD *)(StatusReg + 1800);
          v34 = dp_display_state_name(v32);
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
            v33,
            "remove DP_STATE_CONFIGURED",
            v32,
            v34);
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "dp_display_usbpd_disconnect_cb",
          1877,
          8,
          *(_DWORD *)(v1 + 12),
          -1059143953,
          v30,
          v31,
          v41);
        mutex_unlock(v1 + 1728);
        v35 = edid_ctl;
        if ( edid_ctl )
        {
          if ( *(_BYTE *)(edid_ctl + 41) == 1 )
          {
            *(_BYTE *)(edid_ctl + 41) = 0;
          }
          else
          {
            *(_BYTE *)(*(_QWORD *)(v1 + 176) + 981LL) = 0;
            *(_DWORD *)(v35 + 16) = 0;
            *(_QWORD *)v35 = 0;
            *(_QWORD *)(v35 + 8) = 0;
            v37 = edid_ctl;
            v38 = *(void **)(edid_ctl + 32);
            *(_QWORD *)(edid_ctl + 20) = 0;
            *(_DWORD *)(v37 + 28) = 0;
            *(_BYTE *)(v37 + 40) = 0;
            memset(v38, 0, 0x1000u);
            **(_QWORD **)(edid_ctl + 48) = 0;
          }
        }
        else
        {
          if ( !g_dp_display || (v36 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v36 = 0;
          ipc_log_string(v36, "[w][%-4d]: edid_ctl = NULL\n", *(_DWORD *)(StatusReg + 1800));
          printk(&unk_211805, "dp_display_usbpd_disconnect_cb");
        }
        if ( !g_dp_display || (v39 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v39 = 0;
        ipc_log_string(
          v39,
          "[i][%-4d]: simulate_hpd = %d, cable_connected = %d\n",
          *(_DWORD *)(StatusReg + 1800),
          *(unsigned __int8 *)(edid_ctl + 41),
          *(unsigned __int8 *)(edid_ctl + 40));
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_276398, *(unsigned int *)(StatusReg + 1800));
        else
          printk(&unk_25DB43, "dp_display_usbpd_disconnect_cb");
        v6 = sde_dbg_base_evtlog;
        v7 = *(_DWORD *)(v1 + 12);
        v8 = 1900;
        v9 = 8738;
      }
      else
      {
        if ( !g_dp_display || (v3 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v3 = 0;
        v4 = _ReadStatusReg(SP_EL0);
        ipc_log_string(v3, "[d][%-4d]disconnect already in progress\n", *(_DWORD *)(v4 + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]disconnect already in progress\n", *(_DWORD *)(v4 + 1800));
        v6 = sde_dbg_base_evtlog;
        v7 = *(_DWORD *)(v1 + 12);
        v8 = 1859;
        v9 = 13107;
      }
      sde_evtlog_log(v6, "dp_display_usbpd_disconnect_cb", v8, 8, v9, v7, -1059143953, v5, v41);
      return 0;
    }
    else
    {
      if ( !g_dp_display || (v12 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v12 = 0;
      ipc_log_string(v12, "[e][%-4d]no driver data found\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_26F6F4, "dp_display_usbpd_disconnect_cb");
      return 4294967277LL;
    }
  }
  else
  {
    if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v11 = 0;
    ipc_log_string(v11, "[e][%-4d]invalid dev\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24218F, "dp_display_usbpd_disconnect_cb");
    return 4294967274LL;
  }
}
