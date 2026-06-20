__int64 __fastcall dsi_display_get_modes_helper(
        __int64 a1,
        __int64 *a2,
        int a3,
        __int64 a4,
        __int64 a5,
        _BYTE *a6,
        __int64 a7)
{
  __int64 v7; // x10
  __int64 v8; // x24
  __int64 v9; // x25
  __int64 v10; // x23
  __int64 *v11; // x22
  int v13; // w9
  int v14; // w28
  unsigned int v15; // w21
  int v16; // w13
  __int64 result; // x0
  __int64 v18; // x8
  unsigned int v19; // w27
  __int64 v20; // x0
  int v21; // w20
  bool v22; // zf
  __int64 v23; // x3
  __int64 v24; // x10
  int v25; // w20
  __int64 v26; // x8
  int v27; // w9
  int v28; // w11
  unsigned int v29; // w8
  int v30; // w27
  int v31; // w22
  __int64 v32; // x9
  __int64 v33; // x28
  int v34; // w8
  __int64 v35; // x9
  __int64 v36; // x0
  __int64 v37; // x27
  __int64 v38; // x23
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x21
  __int64 v42; // x0
  __int64 v43; // x9
  int v44; // w8
  __int64 v45; // x9
  int v46; // w8
  __int64 v47; // x20
  __int64 v48; // x8
  unsigned int v49; // w27
  __int64 v50; // x22
  int v51; // w21
  int v52; // w23
  __int64 v53; // x28
  __int64 v54; // x8
  __int64 v55; // x25
  unsigned int v56; // w24
  int v57; // w9
  char *v58; // x8
  __int64 v59; // x0
  int v60; // w27
  __int64 v61; // x20
  int v67; // [xsp+38h] [xbp-1D8h]
  int v68; // [xsp+40h] [xbp-1D0h]
  int v69; // [xsp+44h] [xbp-1CCh]
  int v70; // [xsp+48h] [xbp-1C8h]
  unsigned int v71; // [xsp+4Ch] [xbp-1C4h]
  int v72; // [xsp+50h] [xbp-1C0h]
  int v73; // [xsp+54h] [xbp-1BCh]
  __int64 v74; // [xsp+58h] [xbp-1B8h]
  int v76; // [xsp+68h] [xbp-1A8h]
  char v77; // [xsp+78h] [xbp-198h]
  _QWORD src[24]; // [xsp+80h] [xbp-190h] BYREF
  _QWORD dest[26]; // [xsp+140h] [xbp-D0h] BYREF

  dest[24] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    result = 0;
    goto LABEL_76;
  }
  v7 = *(_QWORD *)(a1 + 264);
  v8 = a7;
  v9 = a5;
  v10 = a4;
  v11 = a2;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  _ReadStatusReg(SP_EL0);
  v74 = v7;
  while ( 1 )
  {
    v18 = *v11;
    v73 = v13;
    memset(src, 0, sizeof(src));
    v19 = *(_DWORD *)(v18 + 2872);
    v76 = v16;
    v20 = _kmalloc_cache_noprof(kthread_park, 3520, 3456);
    src[23] = v20;
    if ( !v20 )
      goto LABEL_75;
    v21 = *(_DWORD *)(a1 + 1212);
    v22 = v21 == LODWORD(src[22]);
    v72 = src[22];
    *(_BYTE *)(v20 + 3444) = *(_BYTE *)(*v11 + 1602);
    if ( v22 )
      v23 = *(unsigned int *)(a1 + 1208);
    else
      v23 = 0xFFFFFFFFLL;
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD *, __int64))dsi_panel_get_mode)(
                         *(_QWORD *)(a1 + 264),
                         v15,
                         src,
                         v23) )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to get mode idx %d from panel\n",
        *(const char **)(a1 + 32),
        v15);
      kfree(src[23]);
      result = 4294967274LL;
      goto LABEL_76;
    }
    v24 = v74;
    v77 = src[20];
    v68 = v21;
    v69 = *(unsigned __int8 *)(src[23] + 3400LL);
    if ( *(_DWORD *)(v74 + 1224) == 7 && LOBYTE(src[9]) == 1 && (*(_BYTE *)(src[23] + 3444LL) & 1) == 0 )
    {
      *(_DWORD *)(v74 + 1224) = 3;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: updated dst_format from %d to %d\n", 7, 3);
      v24 = v74;
    }
    v25 = 1;
    if ( *(_BYTE *)(v10 + 28) == 1 && (v77 & 1) != 0 )
      v25 = *(_DWORD *)(v10 + 24);
    if ( (v77 & 2) != 0 )
    {
      dsi_panel_calc_dsi_transfer_time(*(_QWORD *)(a1 + 264) + 1224LL, src, v19);
      v26 = src[23];
      v28 = src[8];
      v27 = HIDWORD(src[8]);
      *(_QWORD *)(src[23] + 2416LL) = src[7];
      v24 = v74;
      *(_DWORD *)(v26 + 2396) = v27;
      *(_DWORD *)(v26 + 2384) = v28;
    }
    v70 = v14;
    v71 = v15;
    if ( *(_BYTE *)(v24 + 1280) != 1 || (v29 = *(_DWORD *)(v24 + 1284), v29 < 2) )
      v29 = *(_DWORD *)(a1 + 160);
    v30 = v76;
    LODWORD(src[1]) *= v29;
    HIDWORD(src[1]) *= v29;
    LODWORD(src[0]) *= v29;
    HIDWORD(src[0]) *= v29;
    v16 = v76;
    LODWORD(src[2]) *= v29;
    LODWORD(src[19]) *= v29;
    if ( v25 )
      break;
LABEL_47:
    if ( a1 )
    {
      v47 = *(_QWORD *)(a1 + 264);
      if ( *(_BYTE *)(v47 + 1392) == 1 )
      {
        v48 = *(unsigned int *)(v47 + 1224);
        v49 = (unsigned int)v48 > 7 ? 24 : bits_per_pixel[v48];
        if ( v76 < v16 )
        {
          v67 = v16;
          v50 = v76;
          v51 = ((*(_DWORD *)(v47 + 1228) >> 1) & 1) + (*(_DWORD *)(v47 + 1228) & 1);
          v52 = ((*(_DWORD *)(v47 + 1228) >> 2) & 1) + ((*(_DWORD *)(v47 + 1228) >> 3) & 1);
          while ( 1 )
          {
            v53 = *(_QWORD *)(a1 + 824) + 192 * v50;
            if ( !v53 )
              goto LABEL_64;
            v54 = *(_QWORD *)(v53 + 184);
            if ( *(_DWORD *)(v54 + 2424) )
            {
              *(_QWORD *)(v53 + 48) = **(unsigned int **)(v54 + 2432);
              dsi_display_adjust_mode_timing(a1, (unsigned int *)v53, v51 + v52, v49);
              v55 = *(_QWORD *)(v53 + 184);
              if ( *(_DWORD *)(v55 + 2424) )
                break;
            }
LABEL_54:
            v16 = v67;
            if ( v67 == (_DWORD)++v50 )
              goto LABEL_64;
          }
          v56 = 0;
          while ( 1 )
          {
            memcpy(dest, (const void *)v53, 0xC0u);
            memcpy(dest, (const void *)v53, 0x98u);
            dest[6] = *(unsigned int *)(*(_QWORD *)(v55 + 2432) + 4LL * (int)v56);
            dsi_display_adjust_mode_timing(a1, (unsigned int *)dest, v51 + v52, v49);
            v57 = *(_DWORD *)(v47 + 1396);
            v58 = (char *)&dest[1] + 4;
            if ( v57 != 1 )
            {
              if ( v57 != 2 )
                goto LABEL_60;
              v58 = (char *)&dest[4] + 4;
            }
            *(_DWORD *)(*(_QWORD *)(v55 + 2448) + 4LL * (int)v56) = *(_DWORD *)v58;
            v55 = *(_QWORD *)(v53 + 184);
LABEL_60:
            *(_DWORD *)(*(_QWORD *)(v55 + 2456) + 4LL * (int)v56++) = dest[19];
            v55 = *(_QWORD *)(v53 + 184);
            if ( v56 >= *(_DWORD *)(v55 + 2424) )
              goto LABEL_54;
          }
        }
      }
    }
LABEL_64:
    if ( v68 == v72 )
      *(_BYTE *)(*(_QWORD *)(a1 + 824) + 192LL * v76 + 172) = 1;
    v9 = a5;
    v8 = a7;
    v10 = a4;
    v11 = a2;
    if ( (v77 & 1) != 0 && *(_BYTE *)(a4 + 28) == 1 )
    {
      v59 = src[23];
      v60 = v16;
      if ( *a6 == 1 )
      {
        v61 = src[23];
        kfree(*(_QWORD *)(src[23] + 2432LL));
        kfree(*(_QWORD *)(v61 + 2448));
        kfree(*(_QWORD *)(v61 + 2456));
        v59 = src[23];
      }
      kfree(v59);
      v16 = v60;
    }
    v15 = v71 + 1;
    v14 = v70 + (v69 ^ 1);
    v13 = v73 + v69;
    if ( v71 + 1 == a3 )
    {
      result = 0;
      if ( v13 && v14 )
      {
        result = 0;
        *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1416LL) = 1;
      }
      goto LABEL_76;
    }
  }
  v31 = 0;
  while ( 1 )
  {
    v32 = *(_QWORD *)(a1 + 824);
    v33 = v32 + 192LL * (unsigned int)(v30 + v31);
    if ( !v33 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid mode data\n");
      result = 4294967282LL;
      goto LABEL_76;
    }
    memcpy((void *)(v32 + 192LL * (unsigned int)(v30 + v31)), src, 0xC0u);
    v34 = *(_DWORD *)(v33 + 136);
    if ( !v34 )
    {
      v34 = *(_DWORD *)(v9 + 4);
      if ( v34 )
        *(_DWORD *)(v33 + 136) = v34;
    }
    if ( !*(_DWORD *)(v33 + 140) && *(_DWORD *)v8 )
      *(_DWORD *)(v33 + 140) = *(_DWORD *)v8;
    v35 = src[23];
    *(_DWORD *)(src[23] + 2400LL) = v34;
    *(_DWORD *)(v35 + 2404) = *(_DWORD *)(v33 + 140);
    if ( *(_BYTE *)(v10 + 28) != 1 || (v77 & 1) == 0 )
      goto LABEL_26;
    v36 = kmemdup_noprof(src[23], 3456, 3264);
    v37 = v36;
    *(_QWORD *)(v33 + 184) = v36;
    if ( !v36 )
      goto LABEL_75;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1392LL) == 1 )
    {
      v38 = *(unsigned int *)(v36 + 2424);
      v39 = _kmalloc_noprof(4 * v38, 3520);
      *(_QWORD *)(v37 + 2448) = v39;
      if ( !v39 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate space for front porch list\n");
        goto LABEL_74;
      }
      v40 = _kmalloc_noprof(4 * v38, 3520);
      *(_QWORD *)(v37 + 2432) = v40;
      if ( !v40 )
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate space for rates list\n");
        goto LABEL_74;
      }
      v41 = 4 * v38;
      memcpy(*(void **)(v37 + 2432), *(const void **)(src[23] + 2432LL), 4 * v38);
      memcpy(*(void **)(v37 + 2448), *(const void **)(src[23] + 2448LL), 4 * v38);
      v10 = a4;
      v42 = _kmalloc_noprof(v41, 3520);
      *(_QWORD *)(v37 + 2456) = v42;
      if ( !v42 )
        break;
    }
    v30 = v76;
    *(_DWORD *)(v33 + 176) += v76 + v31;
    *(_DWORD *)(v33 + 44) = *(_DWORD *)(*(_QWORD *)(v10 + 16) + 4LL * v31);
    if ( *(_DWORD *)(v9 + 4) && *(_DWORD *)(v9 + 16) )
    {
      v43 = *(_QWORD *)(v33 + 184);
      v44 = *(_DWORD *)(*(_QWORD *)(v9 + 8) + 4LL * v31);
      *(_DWORD *)(v33 + 136) = v44;
      *(_DWORD *)(v43 + 2400) = v44;
    }
    if ( *(_DWORD *)(v8 + 16) )
    {
      v45 = *(_QWORD *)(v33 + 184);
      v46 = *(_DWORD *)(*(_QWORD *)(v8 + 8) + 4LL * v31);
      *(_DWORD *)(v33 + 140) = v46;
      *(_DWORD *)(v45 + 2404) = v46;
    }
    dsi_display_get_dfps_timing(a1, v33);
    dsi_panel_get_fps_switch_cmd(*(_QWORD *)(a1 + 264), v33, *(unsigned int *)(v33 + 44));
    *(_DWORD *)(v33 + 160) = 1;
LABEL_26:
    if ( v25 == ++v31 )
    {
      v16 = v30 + v31;
      goto LABEL_47;
    }
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate space for pixel clocks list\n");
LABEL_74:
  kfree(*(_QWORD *)(v37 + 2432));
  kfree(*(_QWORD *)(v37 + 2448));
  kfree(*(_QWORD *)(v37 + 2456));
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: unable to copy dyn clock list\n");
LABEL_75:
  result = 4294967284LL;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
