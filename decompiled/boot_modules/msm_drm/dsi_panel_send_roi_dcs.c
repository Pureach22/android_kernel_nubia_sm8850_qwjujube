__int64 __fastcall dsi_panel_send_roi_dcs(const char **a1, int a2, unsigned __int16 *a3)
{
  const char *v3; // x8
  __int64 v5; // x25
  __int64 v8; // x22
  unsigned int v9; // w8
  __int16 v10; // x10^2
  __int64 v11; // x0
  __int64 v12; // x23
  unsigned int v13; // w8
  unsigned __int16 v14; // w9
  __int16 v15; // w9
  unsigned __int64 v16; // x24
  _BYTE *v17; // x0
  unsigned int v18; // w20
  unsigned __int64 v19; // x19
  __int64 v20; // x21
  unsigned __int64 StatusReg; // x23
  __int64 v22; // x24
  __int64 (__fastcall *v23)(_QWORD, _QWORD, _QWORD); // x0

  if ( a1 && (v3 = a1[178]) != nullptr )
  {
    v5 = *((_QWORD *)v3 + 23);
    *(_QWORD *)(v5 + 816) = 0;
    v8 = _kmalloc_cache_noprof(_mutex_init, 3520, 5);
    if ( v8 )
    {
      while ( 1 )
      {
        v9 = *a3;
        v10 = bswap32(v9) >> 16;
        LOWORD(v9) = v9 + a3[2] - 1;
        *(_BYTE *)v8 = 42;
        *(_BYTE *)(v8 + 4) = v9;
        *(_WORD *)(v8 + 1) = v10;
        *(_BYTE *)(v8 + 3) = BYTE1(v9);
        v11 = _kmalloc_cache_noprof(_mutex_init, 3520, 5);
        v12 = v11;
        if ( !v11 )
          goto LABEL_16;
        v13 = a3[1];
        v14 = a3[3];
        *(_BYTE *)v11 = 43;
        v15 = v13 + v14 - 1;
        *(_BYTE *)(v11 + 4) = v15;
        *(_WORD *)(v11 + 1) = bswap32(v13) >> 16;
        *(_BYTE *)(v11 + 3) = HIBYTE(v15);
        *(_QWORD *)(v5 + 800) = 20;
        *(_DWORD *)(v5 + 808) = 2;
        v16 = (unsigned __int64)*(unsigned int *)(v5 + 808) << 6;
        v17 = (_BYTE *)_kmalloc_noprof(v16, 3520);
        *(_QWORD *)(v5 + 816) = v17;
        if ( !v17 )
        {
LABEL_16:
          kfree(v8);
          kfree(v12);
          kfree(*(_QWORD *)(v5 + 816));
          goto LABEL_17;
        }
        if ( v16 )
          break;
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v22 = *(_QWORD *)(StatusReg + 80);
        v23 = _mutex_init;
        *(_QWORD *)(StatusReg + 80) = &dsi_panel_roi_prepare_dcs_cmds__alloc_tag;
        v8 = _kmalloc_cache_noprof(v23, 3520, 5);
        *(_QWORD *)(StatusReg + 80) = v22;
        if ( !v8 )
          goto LABEL_17;
      }
      *v17 = 0;
      *(_BYTE *)(*(_QWORD *)(v5 + 816) + 1LL) = 57;
      *(_WORD *)(*(_QWORD *)(v5 + 816) + 2LL) = 128;
      *(_WORD *)(*(_QWORD *)(v5 + 816) + 2LL) |= 0x40u;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 8LL) = 5;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 16LL) = v8;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 24LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 32LL) = 0;
      *(_BYTE *)(*(_QWORD *)(v5 + 816) + 40LL) = 0;
      *(_DWORD *)(*(_QWORD *)(v5 + 816) + 44LL) = 0;
      *(_DWORD *)(*(_QWORD *)(v5 + 816) + 48LL) = a2;
      *(_BYTE *)(*(_QWORD *)(v5 + 816) + 64LL) = 0;
      *(_BYTE *)(*(_QWORD *)(v5 + 816) + 65LL) = 57;
      *(_WORD *)(*(_QWORD *)(v5 + 816) + 66LL) = 128;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 72LL) = 5;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 80LL) = v12;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 88LL) = 0;
      *(_QWORD *)(*(_QWORD *)(v5 + 816) + 96LL) = 0;
      *(_BYTE *)(*(_QWORD *)(v5 + 816) + 104LL) = 1;
      *(_DWORD *)(*(_QWORD *)(v5 + 816) + 108LL) = 0;
      *(_DWORD *)(*(_QWORD *)(v5 + 816) + 112LL) = a2;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] send roi x %d y %d w %d h %d\n", *a1, *a3, a3[1], a3[2], a3[3]);
      sde_evtlog_log(sde_dbg_base_evtlog, "dsi_panel_send_roi_dcs", 5740, -1, *a3, a3[1], a3[2], a3[3], 239);
      mutex_lock(a1 + 130);
      v18 = dsi_panel_tx_cmd_set(a1, 0x14u, 0);
      if ( v18 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_ROI cmds, rc=%d\n",
          *a1,
          v18);
      mutex_unlock(a1 + 130);
      if ( *(_DWORD *)(v5 + 808) )
      {
        v19 = 0;
        v20 = 16;
        do
        {
          kfree(*(_QWORD *)(*(_QWORD *)(v5 + 816) + v20));
          ++v19;
          v20 += 64;
        }
        while ( v19 < *(unsigned int *)(v5 + 808) );
      }
      kfree(*(_QWORD *)(v5 + 816));
    }
    else
    {
LABEL_17:
      v18 = -12;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to prepare DSI_CMD_SET_ROI cmds, rc=%d\n",
        *a1,
        -12);
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v18;
}
