__int64 __fastcall dsi_display_cmd_transfer(__int64 a1, __int64 a2, _BYTE *a3, unsigned int a4, char a5)
{
  char v9; // w23
  __int64 v10; // x0
  int host_engine_init_state; // w0
  int v12; // w7
  int v13; // w3
  int v14; // w4
  __int64 v15; // x0
  int v16; // w0
  __int64 v17; // x1
  __int64 v18; // x2
  unsigned int v19; // w8
  unsigned int v20; // w9
  unsigned int v21; // w21
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x22
  int v26; // w23
  int v27; // w8
  __int64 v28; // x1
  char v29[4]; // [xsp+0h] [xbp-10h]
  _BYTE v30[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && a3 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [DSI] Display command transfer\n");
    v9 = a3[3];
    mutex_lock(a2 + 72);
    if ( *(_DWORD *)(a2 + 160) )
    {
      v10 = *(_QWORD *)(a2 + 168);
      v30[0] = 0;
      host_engine_init_state = dsi_ctrl_get_host_engine_init_state(v10, v30);
      v13 = v30[0];
      v14 = host_engine_init_state;
      if ( !host_engine_init_state )
      {
        if ( v30[0] )
        {
          if ( *(_DWORD *)(a2 + 160) < 2u
            || (v15 = *(_QWORD *)(a2 + 216),
                v30[0] = 0,
                v16 = dsi_ctrl_get_host_engine_init_state(v15, v30),
                v13 = v30[0],
                (v14 = v16) == 0)
            && v30[0] )
          {
LABEL_11:
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "dsi_display_cmd_transfer",
              1350,
              -1,
              *(_DWORD *)(a2 + 1644),
              a4,
              -1059143953,
              v12,
              0);
            v19 = *(_DWORD *)(a2 + 1644);
            v20 = v19 + a4;
            if ( *(_DWORD *)(*(_QWORD *)(a2 + 264) + 1352LL) == 2 )
            {
              if ( v20 <= 0x1000 )
                goto LABEL_13;
            }
            else if ( v20 < 0x801 )
            {
LABEL_13:
              if ( v19 > 0x1000 )
                goto LABEL_38;
              goto LABEL_23;
            }
            memset(&dbgfs_tx_cmd_buf, 0, 0x1000u);
            v19 = 0;
            *(_DWORD *)(a2 + 1644) = 0;
LABEL_23:
            v18 = a4;
            v17 = 4096 - v19;
            if ( (unsigned int)v17 < a4 )
            {
LABEL_39:
              _fortify_panic(17, v17, v18);
              JUMPOUT(0x1DE450);
            }
            v23 = *(unsigned int *)(a2 + 1644);
            if ( (unsigned int)v23 > 0x1000 )
            {
LABEL_38:
              __break(0x5512u);
              goto LABEL_39;
            }
            memcpy((char *)&dbgfs_tx_cmd_buf + v23, a3, a4);
            *(_DWORD *)(a2 + 1644) += a4;
            if ( (v9 & 0x40) != 0 )
            {
              v21 = 0;
            }
            else
            {
              *(_DWORD *)(a2 + 1656) = 0;
              dsi_panel_get_cmd_pkt_count(&dbgfs_tx_cmd_buf);
              dsi_panel_alloc_cmd_packets(a2 + 1648, *(unsigned int *)v29);
              ((void (__fastcall *)(void *, _QWORD, _QWORD, _QWORD))dsi_panel_create_cmd_packets)(
                &dbgfs_tx_cmd_buf,
                *(unsigned int *)(a2 + 1644),
                *(unsigned int *)v29,
                *(_QWORD *)(a2 + 1664));
              v24 = *(_QWORD *)(a2 + 264);
              v25 = *(_QWORD *)(a2 + 1664);
              *(_DWORD *)(a2 + 1644) = 0;
              mutex_lock(v24 + 1040);
              if ( *(int *)v29 < 1 )
              {
                v21 = 0;
              }
              else
              {
                v26 = 0;
                while ( 1 )
                {
                  v21 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))dsi_host_transfer_sub)(
                          a2 + 1264,
                          v25,
                          a5 & 1);
                  if ( (v21 & 0x80000000) != 0 )
                    break;
                  v27 = *(_DWORD *)(v25 + 44);
                  if ( v27 )
                    usleep_range_state((unsigned int)(1000 * v27), (unsigned int)(1000 * v27 + 10), 2);
                  ++v26;
                  v25 += 64;
                  if ( v26 >= *(int *)v29 )
                    goto LABEL_37;
                }
                drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to send command, rc=%d\n", v21);
              }
LABEL_37:
              mutex_unlock(*(_QWORD *)(a2 + 264) + 1040LL);
              memset(&dbgfs_tx_cmd_buf, 0, 0x1000u);
              dsi_panel_destroy_cmd_packets(a2 + 1648);
              dsi_panel_dealloc_cmd_packets(a2 + 1648);
            }
            goto LABEL_19;
          }
        }
      }
      if ( !v14 )
      {
        if ( (v13 & 1) != 0 )
          goto LABEL_11;
        if ( (unsigned int)__ratelimit(&dsi_display_cmd_transfer__rs, "dsi_display_cmd_transfer") )
          printk(&unk_22FCE4, v28);
LABEL_18:
        v21 = -1;
LABEL_19:
        mutex_unlock(a2 + 72);
        goto LABEL_20;
      }
    }
    else
    {
      v14 = -22;
      v13 = 1;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [DSI] Invalid host state %d rc %d\n", v13, v14);
    goto LABEL_18;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [DSI] invalid params\n");
  v21 = -22;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v21;
}
