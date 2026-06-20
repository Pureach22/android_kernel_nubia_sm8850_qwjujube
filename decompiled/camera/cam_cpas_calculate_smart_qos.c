__int64 __fastcall cam_cpas_calculate_smart_qos(__int64 a1)
{
  __int64 v1; // x25
  _DWORD *v2; // x17
  unsigned __int8 *v3; // x8
  __int64 v4; // x0
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x21
  __int64 v7; // x2
  __int64 v8; // x10
  _QWORD *v9; // x11
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x11
  __int64 v12; // x26
  __int64 v13; // x28
  _DWORD *v14; // x24
  unsigned __int64 v15; // x4
  int v16; // w30
  int v17; // w16
  const char *v18; // x3
  __int64 v19; // x13
  _QWORD *v20; // x10
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x27
  __int64 v23; // x9
  int v24; // w28
  _DWORD *v25; // x19
  int v26; // w20
  int v27; // w26
  unsigned __int64 v28; // x11
  __int64 v29; // x9
  unsigned __int64 v30; // x28
  __int64 v31; // x1
  int v32; // w8
  unsigned __int64 v33; // x20
  unsigned __int64 v34; // x10
  unsigned __int64 v35; // x20
  __int64 v36; // x28
  char *v38; // x9
  unsigned __int64 v39; // x10
  unsigned __int64 v40; // x26
  unsigned __int64 v41; // x19
  char v42; // w8
  unsigned int v43; // w9
  char v44; // w10
  unsigned int v45; // w8
  unsigned int v46; // w7
  _DWORD *v47; // x19
  int v48; // w26
  unsigned int v49; // w8
  unsigned __int64 v50; // x9
  __int64 v51; // x26
  unsigned __int64 v52; // x28
  _DWORD *v53; // x19
  int v54; // w27
  const char *v55; // x20
  int v56; // w8
  int v57; // w9
  __int64 v58; // x6
  int v59; // w26
  int v60; // w19
  _DWORD *v61; // x19
  int v62; // w26
  __int64 v63; // x19
  __int64 v64; // x9
  _QWORD *v65; // x10
  __int64 v66; // x8
  int v68; // [xsp+18h] [xbp-58h]
  int v69; // [xsp+48h] [xbp-28h]
  int v70; // [xsp+4Ch] [xbp-24h]
  int v71; // [xsp+4Ch] [xbp-24h]
  int v72; // [xsp+4Ch] [xbp-24h]
  int v73; // [xsp+4Ch] [xbp-24h]
  __int64 v74; // [xsp+50h] [xbp-20h]
  __int64 v75; // [xsp+50h] [xbp-20h]
  __int64 v76; // [xsp+50h] [xbp-20h]
  __int64 v77; // [xsp+50h] [xbp-20h]
  __int64 v78; // [xsp+50h] [xbp-20h]
  unsigned __int64 v79; // [xsp+58h] [xbp-18h]
  unsigned __int64 v80; // [xsp+58h] [xbp-18h]
  unsigned __int64 v81; // [xsp+58h] [xbp-18h]
  unsigned __int64 v82; // [xsp+58h] [xbp-18h]
  unsigned __int64 v83; // [xsp+58h] [xbp-18h]
  __int64 v84; // [xsp+60h] [xbp-10h]
  __int64 v85; // [xsp+60h] [xbp-10h]
  __int64 v86; // [xsp+60h] [xbp-10h]
  __int64 v87; // [xsp+60h] [xbp-10h]
  __int64 v88; // [xsp+60h] [xbp-10h]
  __int64 v89; // [xsp+68h] [xbp-8h]
  __int64 v90; // [xsp+68h] [xbp-8h]
  __int64 v91; // [xsp+68h] [xbp-8h]
  __int64 v92; // [xsp+68h] [xbp-8h]
  __int64 v93; // [xsp+68h] [xbp-8h]
  __int64 v94; // [xsp+68h] [xbp-8h]

  v1 = *(_QWORD *)(a1 + 3392);
  v2 = &unk_393000;
  v3 = *(unsigned __int8 **)(v1 + 1616);
  if ( v3[9] )
  {
    v4 = *(_QWORD *)(a1 + 3680);
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      if ( v5 == 10 )
      {
LABEL_75:
        __break(0x5512u);
        return cam_cpas_is_new_rt_bw_lower(v4);
      }
      v8 = *(_QWORD *)&v3[8 * v5 + 16];
      v9 = *(_QWORD **)(v8 + 48);
      v10 = v9[3];
      if ( *(_BYTE *)(v1 + 1610) == 1 )
        v10 += v9[10] + v9[13] + v9[17] + v9[20] + v9[24] + v9[27];
      v11 = *(unsigned int *)(v8 + 128);
      v7 += v10 / v11;
      if ( v6 <= v10 / v11 )
        v6 = v10 / v11;
      if ( (debug_mdl & 0x2000004) != 0 && !v2[919] )
      {
        v12 = v4;
        v13 = v7;
        v14 = v2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x2000004,
          4,
          "cam_cpas_calculate_smart_qos",
          985,
          "NIU[%d][%s]camnoc_bw %llu, niu_size %u, init_bw_per_kb %lld, remainder %lld, max_bw_per_kb %lld, total_bw_per_kb %lld",
          v5,
          *(const char **)(v8 + 24),
          v10,
          v11,
          v10 / v11,
          v10 % v11,
          v6,
          v7);
        v3 = *(unsigned __int8 **)(v1 + 1616);
        v7 = v13;
        v4 = v12;
        v2 = v14;
      }
      ++v5;
    }
    while ( v5 < v3[9] );
    if ( !v6 )
      goto LABEL_62;
    if ( v3[9] )
    {
      v15 = 0;
      v16 = 0;
      v17 = 0;
      v18 = "cam_cpas_calculate_smart_qos";
      while ( 1 )
      {
        if ( v15 == 10 )
          goto LABEL_75;
        v19 = *(_QWORD *)&v3[8 * v15 + 16];
        v20 = *(_QWORD **)(v19 + 48);
        v21 = v20[3];
        if ( *(_BYTE *)(v1 + 1610) == 1 )
          v21 += v20[10] + v20[13] + v20[17] + v20[20] + v20[24] + v20[27];
        v22 = v21 / *(unsigned int *)(v19 + 128);
        v23 = v3[6];
        if ( 100 * v22 <= v7 * v23 )
        {
          v28 = ((v23 - (unsigned __int64)v3[7]) * v7) >> 2;
          v29 = v3[4];
          v30 = v22 * v3[8] * (v29 - v3[5]);
          v31 = debug_mdl & 0x2000004;
          v32 = v2[919];
          v33 = (unsigned __int64)((v28 * (unsigned __int128)0x28F5C28F5C28F5C3uLL) >> 64) >> 2;
          if ( (debug_mdl & 0x2000004) != 0 && !v32 )
          {
            v88 = v7;
            v94 = v4;
            v78 = v19;
            v83 = v15;
            v61 = v2;
            v62 = v17;
            v73 = v16;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v31,
              4,
              v18,
              1032,
              "ramp_val=%lld, total_bw_ramp_val=%lld",
              v30,
              (unsigned __int64)((v28 * (unsigned __int128)0x28F5C28F5C28F5C3uLL) >> 64) >> 2);
            v19 = v78;
            v15 = v83;
            v7 = v88;
            v4 = v94;
            v16 = v73;
            LOBYTE(v29) = *(_BYTE *)(*(_QWORD *)(v1 + 1616) + 4LL);
            v32 = v61[919];
            v18 = "cam_cpas_calculate_smart_qos";
            v17 = v62;
            v2 = v61;
            v31 = debug_mdl & 0x2000004;
          }
          if ( v33 > 2 * (v30 % (unsigned int)v33) )
            v34 = v30 / (unsigned int)v33;
          else
            LOBYTE(v34) = v30 / (unsigned int)v33 + 1;
          LOBYTE(v24) = v29 - v34;
          if ( !v31 || v32 )
            goto LABEL_31;
          v84 = v7;
          v89 = v4;
          v74 = v19;
          v79 = v15;
          v25 = v2;
          v26 = v17;
          v27 = v16;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v31,
            4,
            v18,
            1044,
            "Current niu clamp_threshold=%d, val=%d",
            (unsigned __int8)(v29 - v34),
            (unsigned __int8)v34);
        }
        else
        {
          v24 = v3[5];
          if ( (debug_mdl & 0x2000004) == 0 || v2[919] )
            goto LABEL_31;
          v84 = v7;
          v89 = v4;
          v74 = *(_QWORD *)&v3[8 * v15 + 16];
          v79 = v15;
          v25 = v2;
          v26 = v17;
          v27 = v16;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x2000004,
            4,
            v18,
            1013,
            "Current niu clamp_threshold=%d",
            v24);
        }
        v19 = v74;
        v15 = v79;
        v7 = v84;
        v4 = v89;
        v16 = v27;
        v18 = "cam_cpas_calculate_smart_qos";
        v17 = v26;
        v2 = v25;
LABEL_31:
        if ( (unsigned __int8)v24 <= 0xFu )
        {
          v56 = debug_mdl;
          v57 = v2[919];
          v35 = 0;
          v58 = 15;
          v59 = 15;
          do
          {
            v35 = *(unsigned __int8 *)(*(_QWORD *)(v1 + 1616) + 2LL) | (16 * v35);
            if ( (v56 & 0x2000004) != 0 && !v57 )
            {
              v87 = v7;
              v93 = v4;
              v82 = v15;
              v60 = v17;
              v72 = v16;
              v77 = v19;
              ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
                3,
                v56 & 0x2000004,
                4,
                v18,
                1055,
                "pos=%d, val=0x%x, priority=0x%llx",
                v58);
              v19 = v77;
              v15 = v82;
              v7 = v87;
              v4 = v93;
              v2 = &unk_393000;
              v16 = v72;
              v56 = debug_mdl;
              v57 = debug_priority;
              v18 = "cam_cpas_calculate_smart_qos";
              v17 = v60;
            }
            v58 = (unsigned int)(char)--v59;
          }
          while ( (int)v58 >= (unsigned __int8)v24 );
        }
        else
        {
          v35 = 0;
        }
        if ( (((_BYTE)v24 - 1) & 0x80) == 0 )
        {
          v36 = (char)(v24 - 1);
          do
          {
            if ( v36 )
            {
              v38 = *(char **)(v1 + 1616);
              v39 = v22 * v36 * (unsigned __int8)v38[3] / 0x64;
              v40 = v39 / (unsigned int)v6;
              v41 = v39 % (unsigned int)v6;
              if ( (debug_mdl & 0x2000004) != 0 && !v2[919] )
              {
                v86 = v7;
                v91 = v4;
                v81 = v15;
                v69 = v17;
                v71 = v16;
                v76 = v19;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x2000004,
                  4,
                  v18,
                  1076,
                  "pos=%d, bw_per_kb=%lld, pos*bw_per_kb=%lld, ramp_val=%lld, remainder=%lld, max_bw_per_kb=%lld",
                  v36,
                  v22,
                  v22 * v36,
                  v40,
                  v41,
                  v6);
                v19 = v76;
                v15 = v81;
                v7 = v86;
                v4 = v91;
                v17 = v69;
                v16 = v71;
                v38 = *(char **)(v1 + 1616);
                v18 = "cam_cpas_calculate_smart_qos";
                v2 = &unk_393000;
              }
              v42 = *v38;
              v43 = (unsigned __int8)v38[1];
              if ( v6 > 2 * v41 )
                v44 = v40;
              else
                v44 = v40 + 1;
              v45 = (unsigned __int8)(v42 + v44);
              if ( v45 >= v43 )
                v46 = v43;
              else
                v46 = v45;
            }
            else
            {
              v46 = **(unsigned __int8 **)(v1 + 1616);
            }
            v35 = v46 | (16 * v35);
            if ( (debug_mdl & 0x2000004) != 0 && !v2[919] )
            {
              v85 = v7;
              v90 = v4;
              v80 = v15;
              v47 = v2;
              v48 = v17;
              v70 = v16;
              v75 = v19;
              ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                debug_mdl & 0x2000004,
                4,
                v18,
                1091,
                "pos=%d, val=0x%x, priority=0x%llx",
                (unsigned int)v36);
              v19 = v75;
              v15 = v80;
              v7 = v85;
              v4 = v90;
              v16 = v70;
              v18 = "cam_cpas_calculate_smart_qos";
              v17 = v48;
              v2 = v47;
            }
          }
          while ( v36-- > 0 );
        }
        v49 = *(_DWORD *)(v19 + 140);
        v50 = HIDWORD(v35);
        *(_QWORD *)(v19 + 132) = v35;
        if ( __PAIR64__(*(_DWORD *)(v19 + 144), v49) != v35 )
          v17 = 1;
        if ( (debug_mdl & 0x2000004) != 0 && !v2[919] )
        {
          v92 = v4;
          v51 = v7;
          v52 = v15;
          v53 = v2;
          v54 = v17;
          v68 = v35;
          v55 = v18;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x2000004,
            4,
            v18,
            1106,
            "Node[%d][%s]Priority applied high 0x%x low 0x%x, new high 0x%x low 0x%x, needs_update %d",
            v16,
            *(const char **)(v19 + 24),
            *(_DWORD *)(v19 + 144),
            v49,
            v50,
            v68,
            v17 & 1);
          v4 = v92;
          v18 = v55;
          v15 = v52;
          v17 = v54;
          v7 = v51;
          v2 = v53;
        }
        v3 = *(unsigned __int8 **)(v1 + 1616);
        v16 = ++v15;
        if ( v15 >= v3[9] )
        {
          if ( !v3[9] || (*(_BYTE *)(v4 + 159426) & (unsigned __int8)v17 & 1) == 0 )
            return v17 & 1;
          v63 = 0;
          while ( v63 != 10 )
          {
            v64 = *(_QWORD *)&v3[8 * v63 + 16];
            v65 = *(_QWORD **)(v64 + 48);
            v66 = v65[3];
            if ( *(_BYTE *)(v1 + 1610) == 1 )
              v66 += v65[10] + v65[13] + v65[17] + v65[20] + v65[24] + v65[27];
            v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x2000000,
                   3,
                   "cam_cpas_calculate_smart_qos",
                   1130,
                   "Node[%d][%s] camnoc_bw=%lld, niu_size=%d, offset high 0x%x, low 0x%x, Priority new high 0x%x low 0x%x"
                   ", applied high 0x%x low 0x%x",
                   v63,
                   *(const char **)(v64 + 24),
                   v66,
                   *(_DWORD *)(v64 + 128),
                   *(_DWORD *)(v64 + 124),
                   *(_DWORD *)(v64 + 120),
                   *(_DWORD *)(v64 + 136),
                   *(_DWORD *)(v64 + 132),
                   *(_DWORD *)(v64 + 144),
                   *(_DWORD *)(v64 + 140));
            v3 = *(unsigned __int8 **)(v1 + 1616);
            if ( ++v63 >= (unsigned __int64)v3[9] )
            {
              LOBYTE(v17) = 1;
              return v17 & 1;
            }
          }
          goto LABEL_75;
        }
      }
    }
    LOBYTE(v17) = 0;
  }
  else
  {
LABEL_62:
    LOBYTE(v17) = 0;
    if ( (debug_mdl & 0x2000004) != 0 && !v2[919] )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x2000004,
        4,
        "cam_cpas_calculate_smart_qos",
        989,
        "No valid bw on NIU nodes");
      LOBYTE(v17) = 0;
    }
  }
  return v17 & 1;
}
