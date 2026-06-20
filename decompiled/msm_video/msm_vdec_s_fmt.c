__int64 __fastcall msm_vdec_s_fmt(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x23
  __int64 v5; // x4
  unsigned int v6; // w8
  __int64 result; // x0
  __int64 v8; // x21
  __int64 *v9; // x8
  unsigned int v10; // w24
  const void *v11; // x21
  __int64 v12; // x8
  unsigned int (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x4
  __int64 v15; // x9
  __int64 v16; // x8
  unsigned int (__fastcall *v17)(__int64, __int64); // x8
  int v18; // w5
  int v19; // w6
  int v20; // w8
  void *v21; // x0
  int v22; // w5
  int v23; // w6
  int v24; // w8
  __int64 v25; // x1
  int v26; // w0
  unsigned int v27; // w8
  unsigned int v28; // w22
  int v29; // w8
  int v30; // w9
  int v31; // w9
  int v32; // w21
  int v33; // w22
  int v34; // w8
  unsigned int v35; // w8
  __int64 v36; // x8
  __int64 (__fastcall *v37)(__int64, __int64); // x8
  int v38; // w0
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 (__fastcall *v41)(__int64, __int64); // x9
  int v42; // w0
  unsigned int v43; // w9
  unsigned int v44; // w8
  char v45; // w8
  unsigned int v46; // w9
  unsigned int v47; // w8
  __int64 v48; // x8
  int v49; // w0
  __int64 v50; // x8
  __int64 (__fastcall *v51)(__int64, __int64); // x8
  int v52; // w0
  __int64 v53; // x8
  __int64 v54; // x8
  __int64 (__fastcall *v55)(__int64, __int64); // x8
  int v56; // w0
  __int64 v57; // x8
  __int64 (__fastcall *v58)(__int64, __int64); // x8
  int v59; // w8
  unsigned int v60; // w9
  unsigned int v61; // w8

  v2 = *(_QWORD *)(a1 + 320);
  msm_vdec_try_fmt(a1, a2);
  v5 = *a2;
  if ( (int)v5 > 12 )
  {
    if ( (_DWORD)v5 == 13 )
    {
      v11 = (const void *)(a1 + 1008);
      *(_DWORD *)(a1 + 1008) = 13;
      *(_DWORD *)(a1 + 1016) = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_vdec_s_fmt");
      if ( v2
        && (v16 = *(_QWORD *)(v2 + 6560)) != 0
        && (v17 = *(unsigned int (__fastcall **)(__int64, __int64))(v16 + 48)) != nullptr )
      {
        if ( *((_DWORD *)v17 - 1) != 1958436756 )
          __break(0x8228u);
        v14 = v17(a1, 4);
      }
      else
      {
        v14 = 0;
      }
      v22 = *(_DWORD *)(a1 + 2560);
      v23 = *(_DWORD *)(a1 + 2564);
      v24 = *(_DWORD *)(a1 + 2568);
      *(_DWORD *)(a1 + 1020) = v14;
      *(_DWORD *)(a1 + 2680) = v22;
      *(_DWORD *)(a1 + 2684) = v23;
      *(_DWORD *)(a1 + 2688) = v24;
      *(_DWORD *)(a1 + 2692) = v14;
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        goto LABEL_144;
      v21 = &unk_8400F;
      goto LABEL_45;
    }
    if ( (_DWORD)v5 == 14 )
    {
      v11 = (const void *)(a1 + 800);
      *(_DWORD *)(a1 + 800) = 14;
      *(_DWORD *)(a1 + 808) = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_vdec_s_fmt");
      if ( v2
        && (v12 = *(_QWORD *)(v2 + 6560)) != 0
        && (v13 = *(unsigned int (__fastcall **)(__int64, __int64))(v12 + 48)) != nullptr )
      {
        if ( *((_DWORD *)v13 - 1) != 1958436756 )
          __break(0x8228u);
        v14 = v13(a1, 3);
      }
      else
      {
        v14 = 0;
      }
      v18 = *(_DWORD *)(a1 + 2520);
      v19 = *(_DWORD *)(a1 + 2524);
      v20 = *(_DWORD *)(a1 + 2528);
      *(_DWORD *)(a1 + 812) = v14;
      *(_DWORD *)(a1 + 2640) = v18;
      *(_DWORD *)(a1 + 2644) = v19;
      *(_DWORD *)(a1 + 2648) = v20;
      *(_DWORD *)(a1 + 2652) = v14;
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        goto LABEL_144;
      v21 = &unk_8EDC2;
      goto LABEL_45;
    }
LABEL_23:
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_9531A, "err ", a1 + 340, "msm_vdec_s_fmt", v5);
    return 0;
  }
  if ( (_DWORD)v5 == 9 )
  {
    v15 = *(_QWORD *)(a1 + 1840);
    *(_DWORD *)(a1 + 592) = 9;
    if ( (*(_WORD *)(v15 + 320) & 1) != 0 && (*(_DWORD *)(a1 + 312) != 8 || *(_DWORD *)(a1 + 308) != 2) )
    {
      if ( *(_QWORD *)(a1 + 20312) )
      {
        a2[2] = *(_DWORD *)(a1 + 1904);
        a2[3] = *(_DWORD *)(a1 + 1908);
      }
      else
      {
        a2[3] = *(_DWORD *)(a1 + 396);
        a2[2] = *(_DWORD *)(a1 + 392);
      }
    }
    v25 = a2[4];
    *(_DWORD *)(a1 + 608) = v25;
    v26 = v4l2_colorformat_to_driver(a1, v25, "msm_vdec_s_fmt");
    v27 = a2[2];
    v28 = v26;
    if ( *(_QWORD *)(a1 + 20312) )
    {
      *(_DWORD *)(a1 + 600) = v27;
      v29 = a2[3];
      goto LABEL_101;
    }
    if ( !v27 )
      goto LABEL_57;
    if ( (unsigned int)v26 <= 0x10 )
    {
      if ( ((1 << v26) & 0x10016) != 0 )
      {
LABEL_56:
        v27 = (v27 + 127) & 0xFFFFFF80;
LABEL_57:
        *(_DWORD *)(a1 + 600) = v27;
        v29 = a2[3];
        if ( !v29 )
          goto LABEL_101;
        if ( (unsigned int)v26 > 0x10 )
          goto LABEL_98;
        if ( ((1 << v26) & 0x10016) != 0 )
        {
          v30 = 32;
LABEL_100:
          v29 = (v29 + v30 - 1) & -v30;
          goto LABEL_101;
        }
        if ( v26 != 8 )
        {
LABEL_98:
          if ( v26 != 256 && v26 != 128 )
          {
            v29 = 0;
LABEL_101:
            *(_DWORD *)(a1 + 604) = v29;
            *(_BYTE *)(a1 + 780) = 1;
            v46 = a2[2];
            if ( !v46 )
            {
              *(_DWORD *)(a1 + 624) = 0;
              if ( !v2 )
                goto LABEL_109;
              goto LABEL_116;
            }
            v47 = 0;
            if ( v26 > 15 )
            {
              if ( v26 == 16 || v26 == 128 || v26 == 256 )
                v47 = (2 * v46 + 255) & 0xFFFFFF00;
            }
            else
            {
              if ( (unsigned int)(v26 - 1) < 2 || v26 == 4 )
              {
                *(_DWORD *)(a1 + 624) = (v46 + 127) & 0xFFFFFF80;
                if ( !v2 )
                {
LABEL_109:
                  v48 = *(_QWORD *)(a1 + 1840);
                  *(_DWORD *)(a1 + 620) = 0;
                  v49 = 0;
                  if ( (*(_WORD *)(v48 + 320) & 1) == 0 )
                  {
                    v49 = 0;
                    *(_DWORD *)(a1 + 2560) = 0;
                  }
LABEL_138:
                  v59 = *(_DWORD *)(a1 + 2560);
                  v60 = *(_DWORD *)(a1 + 2568);
                  *(_DWORD *)(a1 + 2564) = v49;
                  v61 = v59 + v49;
                  if ( v60 < v61 )
                    *(_DWORD *)(a1 + 2568) = v61;
                  v11 = (const void *)(a1 + 592);
                  *(_DWORD *)(a1 + 2572) = *(_DWORD *)(a1 + 620);
                  ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
                    a1,
                    82,
                    v28,
                    "msm_vdec_s_fmt");
                  if ( (*(_WORD *)(*(_QWORD *)(a1 + 1840) + 320LL) & 1) == 0 )
                  {
                    *(_QWORD *)(a1 + 1880) = 0;
                    *(_DWORD *)(a1 + 1888) = a2[2];
                    *(_DWORD *)(a1 + 1892) = a2[3];
                  }
                  if ( !a1 || (msm_vidc_debug & 2) == 0 )
                    goto LABEL_144;
                  v14 = v4l2_pixelfmt_name(a1, *(unsigned int *)(a1 + 608));
                  v21 = &unk_856D0;
                  goto LABEL_45;
                }
LABEL_116:
                v50 = *(_QWORD *)(v2 + 6560);
                if ( v50 && (v51 = *(__int64 (__fastcall **)(__int64, __int64))(v50 + 48)) != nullptr )
                {
                  if ( *((_DWORD *)v51 - 1) != 1958436756 )
                    __break(0x8228u);
                  v52 = v51(a1, 2);
                }
                else
                {
                  v52 = 0;
                }
                v53 = *(_QWORD *)(a1 + 1840);
                *(_DWORD *)(a1 + 620) = v52;
                if ( (*(_WORD *)(v53 + 320) & 1) == 0 )
                {
                  v54 = *(_QWORD *)(v2 + 6560);
                  if ( v54 && (v55 = *(__int64 (__fastcall **)(__int64, __int64))(v54 + 56)) != nullptr )
                  {
                    if ( *((_DWORD *)v55 - 1) != 1958436756 )
                      __break(0x8228u);
                    v56 = v55(a1, 2);
                  }
                  else
                  {
                    v56 = 0;
                  }
                  *(_DWORD *)(a1 + 2560) = v56;
                }
                v57 = *(_QWORD *)(v2 + 6560);
                if ( v57 && (v58 = *(__int64 (__fastcall **)(__int64, __int64))(v57 + 64)) != nullptr )
                {
                  if ( *((_DWORD *)v58 - 1) != 1958436756 )
                    __break(0x8228u);
                  v49 = v58(a1, 2);
                }
                else
                {
                  v49 = 0;
                }
                goto LABEL_138;
              }
              if ( v26 == 8 )
              {
                *(_DWORD *)(a1 + 624) = (768 * ((v46 + 191) / 0xC0) / 3 + 255) & 0x7FFFFF00;
                if ( !v2 )
                  goto LABEL_109;
                goto LABEL_116;
              }
            }
            *(_DWORD *)(a1 + 624) = v47;
            if ( !v2 )
              goto LABEL_109;
            goto LABEL_116;
          }
        }
        v30 = 16;
        goto LABEL_100;
      }
      if ( v26 == 8 )
      {
        v27 = 192 * ((v27 + 191) / 0xC0);
        goto LABEL_57;
      }
    }
    if ( v26 != 256 && v26 != 128 )
    {
      v27 = 0;
      goto LABEL_57;
    }
    goto LABEL_56;
  }
  if ( (_DWORD)v5 != 10 )
    goto LABEL_23;
  v6 = *(_DWORD *)(a1 + 400);
  if ( v6 != a2[4] )
  {
    result = msm_vdec_codec_change(a1);
    if ( (_DWORD)result )
      return result;
    v6 = a2[4];
  }
  if ( v6 != 809062486 )
    goto LABEL_62;
  v8 = *(_QWORD *)(a1 + 320);
  core_lock(v8, "msm_vidc_check_max_sessions_vp9d");
  v9 = *(__int64 **)(v8 + 3528);
  if ( v9 == (__int64 *)(v8 + 3528) )
  {
    core_unlock(v8, "msm_vidc_check_max_sessions_vp9d");
LABEL_62:
    v31 = *(_DWORD *)(a1 + 400);
    *(_DWORD *)(a1 + 384) = 10;
    if ( v31 == 1129727304 )
      v32 = 31;
    else
      v32 = 15;
    v33 = ~v32;
    v34 = (a2[2] + v32) & ~v32;
    if ( *(_QWORD *)(a1 + 392) != __PAIR64__((a2[3] + v32) & ~v32, v34) )
    {
      ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
        a1,
        95,
        0,
        "msm_vdec_s_fmt");
      v34 = (a2[2] + v32) & v33;
    }
    *(_DWORD *)(a1 + 392) = v34;
    v35 = a2[3];
    *(_BYTE *)(a1 + 572) = 1;
    *(_DWORD *)(a1 + 416) = 0;
    *(_DWORD *)(a1 + 396) = (v35 + v32) & v33;
    if ( v2 )
    {
      v36 = *(_QWORD *)(v2 + 6560);
      if ( v36 && (v37 = *(__int64 (__fastcall **)(__int64, __int64))(v36 + 48)) != nullptr )
      {
        if ( *((_DWORD *)v37 - 1) != 1958436756 )
          __break(0x8228u);
        v38 = v37(a1, 1);
      }
      else
      {
        v38 = 0;
      }
      *(_DWORD *)(a1 + 412) = v38;
      v39 = *(_QWORD *)(v2 + 6560);
      if ( v39 )
      {
        v39 = *(_QWORD *)(v39 + 56);
        if ( v39 )
        {
          if ( *(_DWORD *)(v39 - 4) != 1958436756 )
            __break(0x8228u);
          LODWORD(v39) = ((__int64 (__fastcall *)(__int64, __int64))v39)(a1, 1);
        }
      }
      *(_DWORD *)(a1 + 2520) = v39;
      v40 = *(_QWORD *)(v2 + 6560);
      if ( v40 && (v41 = *(__int64 (__fastcall **)(__int64, __int64))(v40 + 64)) != nullptr )
      {
        if ( *((_DWORD *)v41 - 1) != 1958436756 )
          __break(0x8229u);
        v42 = v41(a1, 1);
        LODWORD(v39) = *(_DWORD *)(a1 + 2520);
      }
      else
      {
        v42 = 0;
      }
    }
    else
    {
      LODWORD(v39) = 0;
      v42 = 0;
      *(_DWORD *)(a1 + 412) = 0;
      *(_DWORD *)(a1 + 2520) = 0;
    }
    v43 = *(_DWORD *)(a1 + 2528);
    v44 = v39 + v42;
    v11 = (const void *)(a1 + 384);
    *(_DWORD *)(a1 + 2524) = v42;
    if ( v43 < v44 )
      *(_DWORD *)(a1 + 2528) = v44;
    *(_DWORD *)(a1 + 2532) = *(_DWORD *)(a1 + 412);
    *(_DWORD *)(a1 + 408) = a2[6];
    *(_BYTE *)(a1 + 576) = *((_BYTE *)a2 + 192);
    *(_BYTE *)(a1 + 574) = *((_BYTE *)a2 + 190);
    *(_BYTE *)(a1 + 575) = *((_BYTE *)a2 + 191);
    *(_DWORD *)(a1 + 616) = a2[6];
    *(_BYTE *)(a1 + 784) = *((_BYTE *)a2 + 192);
    *(_BYTE *)(a1 + 782) = *((_BYTE *)a2 + 190);
    v45 = *((_BYTE *)a2 + 191);
    *(_QWORD *)(a1 + 1880) = 0;
    *(_BYTE *)(a1 + 783) = v45;
    *(_DWORD *)(a1 + 1888) = a2[2];
    *(_DWORD *)(a1 + 1892) = a2[3];
    if ( !a1 || (msm_vidc_debug & 2) == 0 )
      goto LABEL_144;
    v14 = v4l2_pixelfmt_name(a1, a2[4]);
    v21 = &unk_906F7;
LABEL_45:
    printk(v21, "high", a1 + 340, "msm_vdec_s_fmt", v14);
LABEL_144:
    memcpy(a2, v11, 0xD0u);
    return 0;
  }
  v10 = 0;
  do
  {
    if ( *((_DWORD *)v9 + 77) == 2 && *((_DWORD *)v9 + 100) == 809062486 )
      ++v10;
    v9 = (__int64 *)*v9;
  }
  while ( v9 != (__int64 *)(v8 + 3528) );
  core_unlock(v8, "msm_vidc_check_max_sessions_vp9d");
  if ( v10 < 7 )
    goto LABEL_62;
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 4294967284LL;
  printk(&unk_81F6E, "err ", a1 + 340, "msm_vdec_s_fmt", 6);
  return 4294967284LL;
}
