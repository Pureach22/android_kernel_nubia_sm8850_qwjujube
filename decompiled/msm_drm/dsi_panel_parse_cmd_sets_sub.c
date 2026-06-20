__int64 __fastcall dsi_panel_parse_cmd_sets_sub(__int64 a1, unsigned int a2, __int64 *a3)
{
  __int64 v3; // x19
  unsigned int v4; // w20
  __int64 *v5; // x21
  __int64 v6; // x22
  int v7; // w23
  char **v8; // x24
  __int64 (__fastcall *v9)(__int64, char *, unsigned int *); // x8
  __int64 v10; // x0
  char *v11; // x1
  __int64 v12; // x0
  double v13; // d0
  __int64 v14; // x8
  unsigned int v15; // w9
  unsigned int v16; // w10
  bool v17; // cf
  __int64 v18; // x3
  unsigned int v19; // w22
  _DWORD *v20; // x8
  __int64 v21; // x0
  char *v22; // x1
  const char *v23; // x0
  const char *v24; // x21
  int v25; // w8
  unsigned __int64 StatusReg; // x25
  __int64 v27; // x26
  __int64 v28; // x3
  unsigned int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  if ( a2 > 0x3A )
  {
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v27 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &dsi_panel_alloc_cmd_packets__alloc_tag;
    v28 = _kmalloc_noprof(a1, 3520);
    *(_QWORD *)(StatusReg + 80) = v27;
    *(_QWORD *)(v3 + 16) = v28;
    if ( v28 )
    {
LABEL_11:
      *(_DWORD *)(v3 + 8) = v7;
      v19 = ((__int64 (__fastcall *)(__int64))dsi_panel_create_cmd_packets)(v6);
      if ( v19 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to create cmd packets, rc=%d\n", v19);
LABEL_13:
        kfree(*(_QWORD *)(v3 + 16));
        *(_QWORD *)(v3 + 16) = 0;
        goto LABEL_28;
      }
      v20 = (_DWORD *)v5[2];
      v21 = *v5;
      v22 = cmd_set_state_map[v4];
      if ( *(v20 - 1) != -1612502898 )
        __break(0x8228u);
      v23 = (const char *)((__int64 (__fastcall *)(__int64, char *, _QWORD))v20)(v21, v22, 0);
      if ( !v23 || (v24 = v23, !strcmp(v23, "dsi_lp_mode")) )
      {
        v25 = 0;
      }
      else
      {
        if ( strcmp(v24, "dsi_hs_mode") )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: [%s] command state unrecognized-%s\n",
            cmd_set_state_map[v4],
            v24);
          goto LABEL_13;
        }
        v25 = 1;
      }
      *(_DWORD *)(v3 + 4) = v25;
      v19 = 0;
      *(_QWORD *)(v3 + 24) = v8[v4];
      *(_BYTE *)(v3 + 32) = v4 != 56;
      goto LABEL_28;
    }
LABEL_27:
    v19 = -12;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate cmd packets, rc=%d\n", 4294967284LL);
    goto LABEL_28;
  }
  v8 = cmd_set_prop_map;
  v4 = a2;
  v3 = a1;
  v9 = (__int64 (__fastcall *)(__int64, char *, unsigned int *))a3[2];
  v10 = *a3;
  v11 = cmd_set_prop_map[a2];
  v5 = a3;
  if ( *((_DWORD *)v9 - 1) != -1612502898 )
    __break(0x8228u);
  v12 = v9(v10, v11, &v30);
  if ( !v12 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s commands not defined\n", cmd_set_prop_map[v4]);
    v19 = -524;
    goto LABEL_28;
  }
  v6 = v12;
  v13 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: type=%d, name=%s, length=%d\n", v4, cmd_set_prop_map[v4], v30);
  v7 = 0;
  if ( v30 < 7 )
  {
LABEL_10:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] packet-count=%d, %d\n", cmd_set_prop_map[v4], v7, v30);
    v18 = _kmalloc_noprof((unsigned int)(v7 << 6), 3520);
    *(_QWORD *)(v3 + 16) = v18;
    if ( v18 )
      goto LABEL_11;
    goto LABEL_27;
  }
  v7 = 0;
  v14 = v6;
  v15 = v30;
  while ( 1 )
  {
    v16 = __rev16(*(unsigned __int16 *)(v14 + 5)) + 7;
    v17 = v15 >= v16;
    v15 -= v16;
    if ( !v17 )
      break;
    v14 += v16;
    ++v7;
    if ( v15 <= 6 )
      goto LABEL_10;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: format error\n", v13);
  v19 = -22;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: commands failed, rc=%d\n", 4294967274LL);
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v19;
}
