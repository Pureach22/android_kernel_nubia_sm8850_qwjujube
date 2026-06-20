__int64 __fastcall dp_display_validate_mode(__int64 a1, __int64 a2, const char *a3, _DWORD *a4)
{
  const char *v8; // x23
  _DWORD *v9; // x8
  unsigned int v10; // w9
  unsigned int v11; // w8
  unsigned int v12; // w21
  const char *v13; // x22
  int v14; // w0
  _DWORD *v15; // x8
  unsigned int v16; // w24
  int v17; // w23
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned __int64 v20; // x23
  unsigned int v21; // w2
  void *v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  int v25; // w0
  _DWORD *v26; // x8
  int v27; // w3
  __int64 v28; // x0
  unsigned __int64 StatusReg; // x21
  unsigned int v30; // w23
  unsigned int v31; // w24
  __int64 v32; // x0
  unsigned __int64 v33; // x21
  __int64 v34; // x0
  unsigned __int64 v35; // x23
  void *v36; // x0
  unsigned int v37; // w23
  unsigned int v38; // w24
  __int64 v39; // x0
  unsigned __int64 v40; // x21
  _DWORD s[200]; // [xsp+8h] [xbp-328h] BYREF
  __int64 v43; // [xsp+328h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( a4 && a2 && a1 && a3 && a4[6] )
  {
    mutex_lock(a1 + 560);
    if ( !*(_QWORD *)(a2 + 944) )
    {
      if ( !g_dp_display || (v23 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v23 = 0;
      ipc_log_string(v23, "[e][%-4d]invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_24BABD, "dp_display_validate_mode");
      goto LABEL_72;
    }
    if ( !*(_QWORD *)(a1 - 976) )
    {
LABEL_72:
      v12 = -2;
      v13 = "invalid";
LABEL_73:
      mutex_unlock(a1 + 560);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d][%s clk:%d] mode is %s\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          a3 + 80,
          *(_DWORD *)a3,
          v13);
      goto LABEL_75;
    }
    v8 = (const char *)edid_ctl;
    if ( edid_ctl )
    {
      if ( strcmp((const char *)edid_ctl, "SmartGlasses") && strcmp(v8, "PGlass") )
      {
LABEL_11:
        v9 = *(_DWORD **)(a1 + 272);
        if ( *(v9 - 1) != 271107547 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, const char *, _DWORD *))v9)(a1, a2, a3, s);
        if ( s[0] == 640 && s[1] == 480 && s[12] == 25175 )
          goto LABEL_16;
        v14 = dp_display_validate_topology(a1 - 1168, a2, a3, s, a4);
        if ( v14 == -11 )
        {
          v15 = *(_DWORD **)(a2 + 1136);
          if ( *(v15 - 1) != 27531319 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, const char *, _DWORD *))v15)(a2, a3, s);
          v14 = dp_display_validate_topology(a1 - 1168, a2, a3, s, a4);
        }
        if ( !v14 )
        {
          if ( (s[16] & 1) != 0 )
          {
            v16 = BYTE1(s[22]);
            v17 = LOWORD(s[26]) >> 4;
          }
          else
          {
            v17 = s[13];
            v16 = s[13] / 3u;
          }
          if ( *(_BYTE *)(a1 + 34) == 1 )
          {
            v24 = *(_QWORD *)(a1 - 992);
            v25 = *(_DWORD *)(v24 + 76);
            v26 = (_DWORD *)(v24 + 80);
          }
          else
          {
            v25 = drm_dp_bw_code_to_link_rate(*(unsigned int *)(*(_QWORD *)(a1 - 1000) + 132LL));
            v26 = (_DWORD *)(*(_QWORD *)(a1 - 1000) + 128LL);
          }
          v27 = *(_DWORD *)a3;
          if ( *(_BYTE *)(a1 + 664) == 1 && v25 <= 540000 && v27 * v16 >= 0x298108 )
          {
            if ( !g_dp_display || (v28 = *(_QWORD *)(g_dp_display + 56)) == 0 )
              v28 = 0;
            StatusReg = _ReadStatusReg(SP_EL0);
            ipc_log_string(v28, "[d][%-4d]Limit mode clock: %d kHz\n", *(_DWORD *)(StatusReg + 1800), v27);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]Limit mode clock: %d kHz\n",
                *(_DWORD *)(StatusReg + 1800),
                *(_DWORD *)a3);
          }
          else
          {
            v30 = v27 * v17;
            v31 = 8 * v25 * *v26;
            if ( v30 <= v31 )
            {
              v37 = *(_DWORD *)(a1 + 36);
              v38 = s[12] / *(_DWORD *)(a2 + 976);
              if ( v38 <= v37 )
              {
LABEL_16:
                if ( !*a4 )
                {
                  mutex_lock(a1 + 608);
                  v10 = s[199];
                  *(_DWORD *)(a1 + 716) -= *(_DWORD *)(a2 + 936);
                  v11 = *(_DWORD *)(a2 + 936);
                  if ( v11 <= v10 )
                    v11 = v10;
                  *(_DWORD *)(a2 + 936) = v11;
                  *(_DWORD *)(a1 + 716) += v11;
                  mutex_unlock(a1 + 608);
                }
                v12 = 0;
                v13 = "valid";
                goto LABEL_73;
              }
              if ( !g_dp_display || (v39 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                v39 = 0;
              v40 = _ReadStatusReg(SP_EL0);
              ipc_log_string(v39, "[d][%-4d]clk: %d kHz, max: %d kHz\n", *(_DWORD *)(v40 + 1800), v38, v37);
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "[msm-dp-debug][%-4d]clk: %d kHz, max: %d kHz\n",
                  *(unsigned int *)(v40 + 1800),
                  v38,
                  v37);
            }
            else
            {
              if ( !g_dp_display || (v32 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                v32 = 0;
              v33 = _ReadStatusReg(SP_EL0);
              ipc_log_string(
                v32,
                "[d][%-4d]mode_rate: %d kHz, supported_rate: %d kHz\n",
                *(_DWORD *)(v33 + 1800),
                v30,
                v31);
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "[msm-dp-debug][%-4d]mode_rate: %d kHz, supported_rate: %d kHz\n",
                  *(unsigned int *)(v33 + 1800),
                  v30,
                  v31);
            }
          }
        }
        goto LABEL_72;
      }
      *(_BYTE *)(a2 + 981) = 0;
      if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v19 = 0;
      v20 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v19, "[i][%-4d]SmartGlasses 3D mode, set mode_override = 0\n", *(_DWORD *)(v20 + 1800));
      v21 = *(_DWORD *)(v20 + 1800);
      if ( (_drm_debug & 4) == 0 )
      {
        v22 = &unk_26BC96;
LABEL_64:
        printk(v22, "dp_display_validate_mode");
        goto LABEL_11;
      }
      v36 = &unk_22A09A;
    }
    else
    {
      if ( !g_dp_display || (v34 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v34 = 0;
      v35 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v34, "[i][%-4d]edid_ctl is NULL\n", *(_DWORD *)(v35 + 1800));
      v21 = *(_DWORD *)(v35 + 1800);
      if ( (_drm_debug & 4) == 0 )
      {
        v22 = &unk_21176E;
        goto LABEL_64;
      }
      v36 = &unk_23AED6;
    }
    printk(v36, v21);
    goto LABEL_11;
  }
  if ( !g_dp_display || (v18 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v18 = 0;
  ipc_log_string(v18, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_24B695, "dp_display_validate_mode");
  v12 = -2;
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return v12;
}
