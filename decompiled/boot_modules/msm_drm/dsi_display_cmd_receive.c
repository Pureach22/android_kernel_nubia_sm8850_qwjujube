__int64 __fastcall dsi_display_cmd_receive(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        _QWORD *a6)
{
  int v11; // w0
  int v12; // w22
  __int64 v13; // x8
  __int64 v14; // x0
  int host_engine_init_state; // w0
  int v16; // w7
  int v17; // w3
  int v18; // w4
  __int64 v19; // x0
  int v20; // w0
  __int64 v22; // x1
  char v23[8]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v24; // [xsp+8h] [xbp-48h]
  __int64 v25; // [xsp+10h] [xbp-40h]
  __int64 v26; // [xsp+18h] [xbp-38h]
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 v28; // [xsp+28h] [xbp-28h]
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+38h] [xbp-18h]
  _BYTE v31[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+48h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  *(_QWORD *)v23 = 0;
  v24 = 0;
  if ( !a1 || !a2 || !a4 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [DSI] invalid params\n");
    v12 = -22;
    goto LABEL_27;
  }
  v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, char *))dsi_panel_create_cmd_packets)(a2, a3, 1, v23);
  if ( !v11 )
  {
    v26 = a5;
    v27 = a4;
    *(_WORD *)&v23[2] |= 0x80u;
    mutex_lock(a1 + 72);
    v13 = *(_QWORD *)(a1 + 264);
    if ( v13 && ((*(_BYTE *)(v13 + 1974) & 1) != 0 || *(_BYTE *)(v13 + 1016) == 1) )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Simulation panel doesn't support read commands\n");
      v12 = 0;
LABEL_26:
      mutex_unlock(a1 + 72);
      goto LABEL_27;
    }
    if ( *(_DWORD *)(a1 + 160) )
    {
      v14 = *(_QWORD *)(a1 + 168);
      v31[0] = 0;
      host_engine_init_state = dsi_ctrl_get_host_engine_init_state(v14, v31);
      v17 = v31[0];
      v18 = host_engine_init_state;
      if ( !host_engine_init_state )
      {
        if ( v31[0] )
        {
          if ( *(_DWORD *)(a1 + 160) < 2u )
            goto LABEL_19;
          v19 = *(_QWORD *)(a1 + 216);
          v31[0] = 0;
          v20 = dsi_ctrl_get_host_engine_init_state(v19, v31);
          v17 = v31[0];
          v18 = v20;
          if ( !v20 )
          {
            if ( v31[0] )
              goto LABEL_19;
          }
        }
      }
      if ( !v18 )
      {
        if ( (v17 & 1) != 0 )
        {
LABEL_19:
          sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_cmd_receive", 1484, -1, a3, a5, -1059143953, v16, v23[0]);
          v12 = ((__int64 (__fastcall *)(__int64, char *))dsi_display_cmd_rx)(a1, v23);
          if ( v12 <= 0 )
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [DSI] Display command receive failed, rc=%d\n",
              v12);
          if ( a6 )
            *a6 = v30;
          goto LABEL_26;
        }
        if ( (unsigned int)__ratelimit(&dsi_display_cmd_receive__rs, "dsi_display_cmd_receive") )
          printk(&unk_22FCE4, v22);
LABEL_25:
        v12 = -1;
        goto LABEL_26;
      }
    }
    else
    {
      v18 = -22;
      v17 = 1;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [DSI] Invalid host state = %d rc = %d\n", v17, v18);
    goto LABEL_25;
  }
  v12 = v11;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [DSI] command packet create failed, rc = %d\n", v11);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v12;
}
