__int64 __fastcall dsi_panel_send_cmd(const char **a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v4; // x8
  _DWORD *v5; // x11
  int v6; // w10
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  unsigned int v14; // w9
  const char *v15; // x8
  __int64 v16; // x24
  signed int v17; // w9
  __int64 v18; // x10
  __int16 v19; // w11
  unsigned int v20; // w21
  __int64 result; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params panel NULL\n");
    return (unsigned int)-22;
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: Send command %x\n", a3);
  v11 = mutex_lock(a1 + 130);
  if ( a2 )
    LOBYTE(a2) = *(_BYTE *)(a2 + 16);
  v15 = a1[178];
  if ( !v15 )
    goto LABEL_14;
  if ( a3 < 0x3C )
  {
    v16 = *((_QWORD *)v15 + 23) + 40LL * a3;
    if ( *(_QWORD *)(v16 + 16) )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_panel_prepare_cmd",
        5672,
        -1,
        *(_DWORD *)(v16 + 8),
        a3,
        a4 & 1,
        -1059143953,
        vars0);
      if ( *(_DWORD *)(v16 + 8) )
      {
        v17 = 0;
        do
        {
          *(_BYTE *)(*(_QWORD *)(v16 + 16) + ((__int64)v17 << 6) + 40) = a4 & 1;
          if ( (a4 & 1) != 0 && v17 >= (unsigned int)(*(_DWORD *)(v16 + 8) - 1) )
          {
            v18 = *(_QWORD *)(v16 + 16) + ((__int64)v17 << 6);
            v19 = *(_WORD *)(v18 + 2) & 0xFFBF;
          }
          else
          {
            v18 = *(_QWORD *)(v16 + 16) + ((__int64)v17 << 6);
            v19 = *(_WORD *)(v18 + 2) | 0x40;
          }
          *(_WORD *)(v18 + 2) = v19;
          ++v17;
        }
        while ( (unsigned int)v17 < *(_DWORD *)(v16 + 8) );
      }
      goto LABEL_15;
    }
LABEL_14:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
LABEL_15:
    v20 = dsi_panel_tx_cmd_set(a1, a3, a2 & 1);
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_panel_send_cmd", 5707, -1, a2 & 1, a3, v20, -1059143953, vars0);
    if ( v20 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to send cmd type %x rc=%d\n", *a1, a3, v20);
    mutex_unlock(a1 + 130);
    return v20;
  }
  __break(0x5512u);
  if ( &qword_294000 )
    return dsi_panel_send_roi_dcs(v11, v12, v13);
  sde_reg_write(
    (__int64)a1,
    *(_DWORD *)(*((_QWORD *)a1[9] + 6) + 344LL) + 8,
    *(_DWORD *)((char *)&info[19] + (unsigned int)v15 * (unsigned __int64)v14) & 0x1FFF,
    "dspp->cap->sblk->ad.base + blk_offset");
  sde_reg_write(
    (__int64)a1,
    *(_DWORD *)(*((_QWORD *)a1[9] + 6) + 344LL) + 1104,
    1u,
    "dspp->cap->sblk->ad.base + blk_offset");
  sde_reg_write(
    (__int64)a1,
    *(_DWORD *)(*((_QWORD *)a1[9] + 6) + 344LL) + 316,
    6u,
    "dspp->cap->sblk->ad.base + blk_offset");
  v4 = *((unsigned int *)a1 + 16);
  if ( (unsigned int)v4 > 4 )
  {
    __break(0x5512u);
    goto LABEL_30;
  }
  if ( ((144 * v4) | 4uLL) > 0x2D0 )
  {
LABEL_30:
    __break(1u);
    JUMPOUT(0x164680);
  }
  result = 0;
  v5 = &info[36 * (unsigned int)v4];
  v6 = v5[1];
  v5[1] = v6 | 2;
  if ( (~v6 & 5) == 0 && (v6 & 0x88) != 0 )
  {
    if ( ((144 * v4) | 0xCuLL) <= 0x2D0 )
    {
      ad4_mode_setup((__int64)a1, (unsigned int)info[36 * (unsigned int)v4 + 3]);
      return 0;
    }
    goto LABEL_30;
  }
  return result;
}
