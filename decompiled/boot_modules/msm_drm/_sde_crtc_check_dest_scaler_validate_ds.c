__int64 __fastcall sde_crtc_check_dest_scaler_validate_ds(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        _DWORD *a6)
{
  unsigned __int64 v6; // x6
  __int64 v9; // x20
  unsigned __int64 v10; // x25
  unsigned int v11; // w23
  unsigned int v12; // w22
  __int64 v13; // x26
  __int64 *v14; // x27
  __int64 v15; // x21
  __int64 v16; // x19
  __int64 v17; // x21
  __int64 v18; // x8
  unsigned int v19; // w4
  int v20; // w5
  __int64 v21; // x1
  __int64 sde_connector_state; // x0
  int v23; // w8
  __int64 v24; // x19
  int v25; // w6
  unsigned int v26; // w9
  int v27; // w9
  __int64 result; // x0
  int *v29; // x20
  int v30; // w4
  int v31; // w7
  int v32; // w0
  char *v33; // x1
  int v34; // w2
  int v35; // w8
  int v36; // w5
  int v37; // w6
  char v38; // [xsp+0h] [xbp-B0h]
  __int64 v41; // [xsp+78h] [xbp-38h]
  _DWORD *v42; // [xsp+80h] [xbp-30h]
  __int64 v44; // [xsp+90h] [xbp-20h] BYREF
  _QWORD v45[3]; // [xsp+98h] [xbp-18h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v6) = *(_DWORD *)(a3 + 2044);
  if ( (_DWORD)v6 )
  {
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = a3 + 4096;
    v14 = (__int64 *)(a2 + 2224);
    v41 = a2;
    v42 = (_DWORD *)(a3 + 620);
    while ( 1 )
    {
      if ( v9 == 2960 )
        __break(0x5512u);
      v15 = *(unsigned int *)(a3 + v9 + 2056);
      if ( v9 )
        v16 = a3 + v9 + 1464;
      else
        v16 = 0;
      if ( v10 != v15 || (unsigned int)v15 >= *(_DWORD *)(a2 + 2192) )
      {
        printk(&unk_248F86, "_sde_crtc_check_dest_scaler_validate_ds");
        v30 = *(_DWORD *)(a1 + 112);
        v31 = *(_DWORD *)(a3 + v9 + 2060);
        v32 = sde_dbg_base_evtlog;
        v33 = "_sde_crtc_check_dest_scaler_validate_ds";
        v34 = 4227;
        LOBYTE(v35) = -83;
        v36 = v10;
        v37 = v15;
        goto LABEL_54;
      }
      v17 = *v14;
      if ( !(v11 | v12) )
      {
        v18 = *(_QWORD *)(*(_QWORD *)(v17 + 40) + 56LL);
        v11 = *(_DWORD *)(v18 + 52);
        v12 = *(_DWORD *)(v18 + 56);
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "max DS width [%d,%d] for num_ds = %d\n", v11, v12, v6);
      }
      v19 = *(_DWORD *)(a3 + v9 + 2064);
      if ( (*(_BYTE *)(v13 + 2826) & 1) == 0
        && (v19 > a5 || *(_DWORD *)(a3 + v9 + 2068) > (unsigned int)*(unsigned __int16 *)(a4 + 14))
        || !v19
        || (v20 = *(_DWORD *)(a3 + v9 + 2068)) == 0 )
      {
        printk(&unk_27D42B, "_sde_crtc_check_dest_scaler_lm");
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_crtc_check_dest_scaler_lm",
          4092,
          -1,
          *(_DWORD *)(a1 + 112),
          *(_DWORD *)(a3 + v9 + 2064),
          *(_DWORD *)(a3 + v9 + 2068),
          a5,
          *(_WORD *)(a4 + 14));
        result = 4294967289LL;
        goto LABEL_56;
      }
      if ( v16 && (v19 != *(_DWORD *)(v16 + 8) || v20 != *(_DWORD *)(v16 + 12)) )
        break;
      v21 = *(_QWORD *)(a3 + 328);
      v44 = 0;
      v45[0] = 0;
      sde_connector_state = sde_crtc_get_sde_connector_state((_QWORD *)a1, v21);
      if ( !sde_connector_state )
        goto LABEL_55;
      if ( *(_DWORD *)(sde_connector_state + 2048) )
        sde_kms_rect_merge_rectangles(sde_connector_state + 2048, v45);
      if ( *v42 )
        sde_kms_rect_merge_rectangles(v42, &v44);
      if ( (*(_BYTE *)(v13 + 2825) & 1) != 0 )
        v23 = 1;
      else
        v23 = *(unsigned __int8 *)(v13 + 2826);
      v24 = a3 + v9;
      v25 = *(_DWORD *)(a3 + v9 + 2060);
      if ( (v25 & 6) != 0 )
      {
        v26 = *(_DWORD *)(v24 + 2192);
        if ( v26 > v11
          || !v26
          || (v27 = *(_DWORD *)(a3 + v9 + 2224), v27 - 1 >= v12)
          || (v25 & 8) != 0 && v27 != a5
          || (v25 & 8) != 0 && HIWORD(v45[0]) && *(_DWORD *)(a3 + v9 + 2228) != HIWORD(v45[0]) )
        {
LABEL_51:
          v29 = (int *)(a3 + v9);
          printk(&unk_24C5AD, "_sde_crtc_check_dest_scaler_cfg");
          printk(&unk_248FC9, "_sde_crtc_check_dest_scaler_cfg");
          printk(&unk_27D46C, "_sde_crtc_check_dest_scaler_cfg");
          printk(&unk_279FF2, "_sde_crtc_check_dest_scaler_cfg");
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_crtc_check_dest_scaler_cfg",
            4191,
            -1,
            *(_DWORD *)(a1 + 112),
            v29[520],
            v29[580],
            v29[515],
            v11);
          v29[515] &= 0xFFFFFFF9;
          goto LABEL_55;
        }
        if ( (v25 & 8) != 0 && HIWORD(v44) )
        {
          if ( *(_DWORD *)(a3 + v9 + 2208) != HIWORD(v44) )
            goto LABEL_51;
        }
        else if ( ((v23 | ((*(_DWORD *)(a3 + v9 + 2060) & 8u) >> 3)) & 1) == 0
               && (v27 != a5 || *(_DWORD *)(a3 + v9 + 2228) != *(unsigned __int16 *)(a4 + 14)) )
        {
          goto LABEL_51;
        }
      }
      if ( (v25 & 1) != 0 )
      {
        ++*a6;
        v25 = *(_DWORD *)(v24 + 2060);
      }
      if ( (_drm_debug & 4) != 0 )
      {
        _drm_dev_dbg(0, 0, 0, "ds[%d]: flags[0x%X]\n", *(_DWORD *)(v17 + 32) - 1, v25);
        v25 = *(_DWORD *)(v24 + 2060);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "_sde_crtc_check_dest_scaler_validate_ds",
        4259,
        4,
        *(_DWORD *)(a1 + 112),
        *(_DWORD *)(v17 + 32) - 1,
        v25,
        -1059143953,
        v38);
      v6 = *(unsigned int *)(a3 + 2044);
      ++v10;
      a2 = v41;
      v14 += 6;
      v9 += 592;
      if ( v10 >= v6 )
        goto LABEL_49;
    }
    printk(&unk_234C0C, "_sde_crtc_check_dest_scaler_lm");
    v30 = *(_DWORD *)(a1 + 112);
    v32 = sde_dbg_base_evtlog;
    v36 = *(_DWORD *)(a3 + v9 + 2064);
    v31 = *(_DWORD *)(v16 + 8);
    v35 = *(_DWORD *)(v16 + 12);
    v37 = *(_DWORD *)(a3 + v9 + 2068);
    v33 = "_sde_crtc_check_dest_scaler_lm";
    v34 = 4104;
LABEL_54:
    sde_evtlog_log(v32, v33, v34, -1, v30, v36, v37, v31, v35);
LABEL_55:
    result = 4294967274LL;
  }
  else
  {
LABEL_49:
    result = 0;
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
