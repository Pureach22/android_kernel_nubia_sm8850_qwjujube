__int64 __fastcall sde_encoder_cesta_update(__int64 result, unsigned int a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  int v5; // w8
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x8
  unsigned int v11; // w22
  __int64 v12; // x25
  void *v13; // x0
  _BOOL4 v14; // w24
  __int64 v15; // x26
  __int64 v16; // x27
  __int64 v17; // x23
  bool v18; // w26
  __int64 v19; // x8
  unsigned int v20; // w8
  char v21; // w9
  __int64 v22; // x8
  __int64 v23; // x26
  __int64 v24; // x27
  __int64 v25; // x0
  int v26; // w26
  unsigned __int64 v27; // x28
  __int64 v28; // x23
  __int64 v29; // x27
  __int64 v30; // x0
  __int64 v31; // x27
  __int64 v32; // x8
  unsigned __int64 v33; // x9
  int v34; // w4
  int v35; // w4
  void (__fastcall *v36)(__int64, __int64 *, char *, char *); // x8
  void (__fastcall *v37)(__int64, __int64); // x8
  __int64 v38; // x1
  char v39; // w8
  __int64 v40; // x0
  __int64 v41; // x8
  int v42; // w24
  char v43; // w8
  int v44; // w8
  int v45; // w9
  int v46; // w9
  void (__fastcall *v47)(__int64, __int64 *); // x8
  int v48; // w4
  __int64 v49; // [xsp+60h] [xbp-C0h]
  unsigned __int64 v50; // [xsp+68h] [xbp-B8h]
  __int64 v51; // [xsp+78h] [xbp-A8h]
  __int64 v52; // [xsp+80h] [xbp-A0h]
  __int64 v53; // [xsp+88h] [xbp-98h]
  __int64 v54; // [xsp+90h] [xbp-90h]
  unsigned __int64 v55; // [xsp+98h] [xbp-88h]
  char v56[4]; // [xsp+A0h] [xbp-80h] BYREF
  char v57[4]; // [xsp+A4h] [xbp-7Ch] BYREF
  __int64 v58; // [xsp+A8h] [xbp-78h] BYREF
  __int64 v59; // [xsp+B0h] [xbp-70h]
  int v60; // [xsp+B8h] [xbp-68h]
  __int64 v61; // [xsp+C0h] [xbp-60h] BYREF
  int v62; // [xsp+C8h] [xbp-58h]
  char s[8]; // [xsp+D0h] [xbp-50h] BYREF
  __int64 v64; // [xsp+D8h] [xbp-48h]
  __int64 v65; // [xsp+E0h] [xbp-40h]
  __int64 v66; // [xsp+E8h] [xbp-38h]
  __int64 v67; // [xsp+F0h] [xbp-30h]
  __int64 v68; // [xsp+F8h] [xbp-28h]
  __int64 v69; // [xsp+100h] [xbp-20h]
  __int64 v70; // [xsp+108h] [xbp-18h]
  __int64 v71; // [xsp+110h] [xbp-10h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 4960);
  v62 = 0;
  v61 = 0;
  v60 = 0;
  v58 = 0;
  v59 = 0;
  v57[0] = 0;
  v56[0] = 0;
  if ( !v2 )
    goto LABEL_123;
  v3 = result;
  if ( !*(_QWORD *)(result + 1360) )
    goto LABEL_123;
  if ( result )
  {
    v5 = *(_DWORD *)(result + 196);
    if ( v5 )
    {
      v6 = *(_QWORD *)(result + 200);
      if ( v6 && (*(_BYTE *)(v6 + 2290) & 1) != 0 )
        goto LABEL_123;
      if ( v5 != 1 )
      {
        v7 = *(_QWORD *)(result + 208);
        if ( v7 && (*(_BYTE *)(v7 + 2290) & 1) != 0 )
          goto LABEL_123;
        if ( v5 != 2 )
        {
          v8 = *(_QWORD *)(result + 216);
          if ( v8 && (*(_BYTE *)(v8 + 2290) & 1) != 0 )
            goto LABEL_123;
          if ( v5 != 3 )
          {
            v9 = *(_QWORD *)(result + 224);
            if ( v9 && (*(_BYTE *)(v9 + 2290) & 1) != 0 )
              goto LABEL_123;
            if ( v5 != 4 )
              goto LABEL_124;
          }
        }
      }
    }
    if ( *(_QWORD *)result )
    {
      v10 = *(_QWORD *)(*(_QWORD *)result + 56LL);
      if ( v10 && *(_QWORD *)(v10 + 8) )
      {
        result = sde_kms_get_disp_op();
        v11 = result;
        v12 = *(_QWORD *)(v3 + 200);
        if ( !v12 )
          goto LABEL_123;
        goto LABEL_26;
      }
      v13 = &unk_234896;
    }
    else
    {
      v13 = &unk_26FCAB;
    }
    result = printk(v13, "sde_encoder_get_kms");
  }
  v11 = 0;
  v12 = *(_QWORD *)(v3 + 200);
  if ( !v12 )
  {
LABEL_123:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_26:
  if ( !*(_QWORD *)(v12 + 416) )
    goto LABEL_123;
  if ( v3 )
  {
    v14 = *(_DWORD *)(v3 + 648) == 2;
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    v14 = 0;
  }
  result = sde_core_perf_crtc_update(*(_QWORD *)(v3 + 1360), a2);
  v15 = *(_QWORD *)(v3 + 200);
  v16 = *(_QWORD *)(v12 + 416);
  if ( !v15 )
    goto LABEL_77;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  *(_QWORD *)s = 0;
  v64 = 0;
  v17 = *(_QWORD *)(v15 + 8);
  if ( !v17 )
    goto LABEL_77;
  if ( v3 )
  {
    v18 = *(_DWORD *)(v3 + 648) != 2;
    v19 = *(_QWORD *)(v3 + 1360);
    if ( !v19 )
      goto LABEL_47;
  }
  else
  {
    result = printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    v17 = *(_QWORD *)(v15 + 8);
    v18 = 1;
    v19 = 0xBCA8000048025LL;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v19 + 2008) + 10LL) & 0xE) != 0 )
    goto LABEL_77;
  result = *(_QWORD *)(v17 + 2512);
  if ( result )
  {
    v19 = *(_QWORD *)result;
    if ( !*(_QWORD *)result )
      goto LABEL_47;
    v19 = *(_QWORD *)v19;
    if ( !v19 )
      goto LABEL_47;
    v19 = *(_QWORD *)(v19 + 56);
    if ( !v19 )
      goto LABEL_47;
    v19 = *(_QWORD *)(v19 + 8);
    if ( !v19 )
      goto LABEL_47;
    v19 = *(_QWORD *)(*(_QWORD *)v19 + 80LL);
    if ( !v19 )
      goto LABEL_47;
    if ( *(_DWORD *)(v19 - 4) != -1440990782 )
      __break(0x8228u);
    result = ((__int64 (*)(void))v19)();
    if ( result )
    {
      v20 = *(_DWORD *)(result + 8);
      if ( (v20 & 0xD4) != 0 )
        goto LABEL_77;
      LODWORD(v19) = (v20 >> 8) & 1;
      goto LABEL_47;
    }
  }
  LOBYTE(v19) = 0;
LABEL_47:
  v21 = a2 != 1 || v18;
  if ( (v21 & 1) == 0 && (v19 & 1) == 0 )
  {
    v22 = *(_QWORD *)(v17 + 2512);
    if ( v22 )
      v23 = *(_QWORD *)(v22 + 1664);
    else
      v23 = 0;
    v53 = ktime_get(result);
    v51 = v23 - 3000000;
    v52 = v16;
    if ( v23 - 3000000 <= v53 )
    {
      v33 = 0;
      LODWORD(v55) = 0;
      LODWORD(v27) = 0;
    }
    else
    {
      v24 = v23 - 3000000 - v53;
      v50 = (v24 + 999) / 0x3E8uLL;
      v25 = snprintf(s, 0x40u, "schedule_timeout_%llu", v23);
      v55 = (unsigned __int64)(((v50 + 999) * (unsigned __int128)0x10624DD2F1A9FBFuLL) >> 64) >> 2;
      if ( (_DWORD)v55 )
      {
        v49 = v23;
        v26 = 0;
        LODWORD(v27) = 1000;
        v28 = v24;
        _ReadStatusReg(SP_EL0);
        v54 = v24 / 1000;
        do
        {
          v29 = ktime_get(v25);
          v30 = usleep_range_state((unsigned int)(v27 - 100), (unsigned int)v27, 2);
          v31 = ktime_get(v30) - v29;
          v25 = sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "sde_encoder_cesta_update_on_ept",
                  2116,
                  -1,
                  v26,
                  v27,
                  v54,
                  v28 / 1000,
                  v31 / 1000);
          v32 = v28 - v31;
          if ( v28 <= v31 )
            break;
          v28 -= v31;
          if ( v32 != 1000000 )
          {
            v27 = (v32 + 999) / 0x3E8uLL;
            if ( (unsigned int)v27 < 0x64 )
              break;
          }
          ++v26;
        }
        while ( (_DWORD)v55 != v26 );
        v23 = v49;
      }
      else
      {
        LODWORD(v55) = 0;
        LODWORD(v27) = 1000;
      }
      v33 = v50;
    }
    if ( (_drm_debug & 4) != 0 )
    {
      if ( v3 )
        v34 = *(_DWORD *)(v3 + 24);
      else
        v34 = -1;
      _drm_dev_dbg(
        0,
        0,
        0,
        "enc:%d, ept elapsed; ept:%llu, ept_ts:%llu, current_ts:%llu timeout:%llu\n",
        v34,
        v23,
        v51,
        v53,
        v33);
    }
    if ( v3 )
      v35 = *(_DWORD *)(v3 + 24);
    else
      v35 = -1;
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "sde_encoder_cesta_update_on_ept",
               2133,
               -1,
               v35,
               v53 / 1000,
               v55,
               v27,
               v51 / 1000);
    v16 = v52;
  }
LABEL_77:
  if ( a2 == 2 && (unsigned int)(*(_DWORD *)(v2 + 60) - 2) > 2 )
    goto LABEL_123;
  v36 = *(void (__fastcall **)(__int64, __int64 *, char *, char *))(v12 + 336);
  if ( *((_DWORD *)v36 - 1) != -732523917 )
    __break(0x8228u);
  v36(v12, &v58, v57, v56);
  if ( *(_BYTE *)(v3 + 4968) == 1 )
  {
    sde_cesta_force_db_update(*(_QWORD *)(v3 + 4960), 0, 0);
    *(_BYTE *)(v3 + 4969) = 1;
    v37 = *(void (__fastcall **)(__int64, __int64))(v16 + 1648);
    if ( v37 )
    {
      v38 = *(unsigned int *)(v2 + 8);
      if ( *((_DWORD *)v37 - 1) != -1646250321 )
        __break(0x8228u);
      v37(v16, v38);
    }
    if ( !v14 )
      goto LABEL_93;
    BYTE4(v59) = 0;
  }
  v39 = !v14;
  if ( a2 != 1 )
    v39 = 1;
  if ( (v39 & 1) == 0 && (*(_BYTE *)(v3 + 798) & 1) == 0 )
  {
    v40 = *(_QWORD *)(v3 + 4960);
    BYTE4(v59) = 0;
    sde_cesta_force_db_update(v40, BYTE3(v59), v60);
    *(_BYTE *)(v3 + 4969) = 1;
  }
LABEL_93:
  if ( (*(_BYTE *)(v3 + 798) & 1) != 0 )
    goto LABEL_99;
  v41 = *(_QWORD *)(*(_QWORD *)(v3 + 1360) + 2008LL);
  if ( !v41 )
    goto LABEL_99;
  v42 = *(_DWORD *)(v41 + 1568);
  if ( v42 == 2 )
  {
    v56[0] = 1;
    v57[0] = 1;
    if ( a2 != 4 )
      goto LABEL_102;
    goto LABEL_100;
  }
  if ( v42 != 1 )
  {
LABEL_99:
    if ( a2 != 4 )
      goto LABEL_102;
LABEL_100:
    sde_cesta_ctrl_setup(v2, 0);
    v43 = 1;
LABEL_105:
    *(_BYTE *)(v3 + 4968) = v43;
    goto LABEL_106;
  }
  BYTE4(v59) = 0;
  v56[0] = 1;
  v57[0] = 1;
  *(_BYTE *)(v3 + 4969) = 0;
  if ( a2 == 4 )
    goto LABEL_100;
LABEL_102:
  if ( a2 == 3 || (v56[0] & 1) != 0 )
  {
    sde_cesta_ctrl_setup(v2, &v58);
    v43 = 0;
    goto LABEL_105;
  }
LABEL_106:
  v44 = *(_DWORD *)(v2 + 60);
  if ( *(_BYTE *)(v2 + 57) )
    v45 = 8;
  else
    v45 = 2;
  LODWORD(v61) = *(_DWORD *)(v2 + 8);
  v46 = HIDWORD(v61) | v45;
  HIDWORD(v61) = v46;
  v62 = v44;
  if ( a2 == 3 || v56[0] == 1 )
    HIDWORD(v61) = v46 | 4;
  if ( !v44 && v57[0] != 1 )
    goto LABEL_119;
  if ( v11 <= 2 )
  {
    v47 = *(void (__fastcall **)(__int64, __int64 *))(v16 + 8LL * v11 + 1624);
    if ( v47 )
    {
      if ( *((_DWORD *)v47 - 1) != -1386749835 )
        __break(0x8228u);
      v47(v16, &v61);
    }
LABEL_119:
    if ( v3 )
      v48 = *(_DWORD *)(v3 + 24);
    else
      v48 = -1;
    result = sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_cesta_update", 2243, -1, v48, a2, v61, v62, SBYTE4(v61));
    goto LABEL_123;
  }
LABEL_124:
  __break(0x5512u);
  return sde_encoder_rc_restart_delayed();
}
