__int64 __fastcall hal_srng_setup_idx(
        __int64 a1,
        unsigned int a2,
        int a3,
        unsigned int a4,
        __int64 a5,
        char a6,
        int a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  _QWORD *v15; // x27
  __int64 v16; // x22
  unsigned int v18; // w23
  const char *v19; // x2
  const char *v20; // x3
  unsigned int v21; // w0
  unsigned int v22; // w1
  __int64 v23; // x20
  __int64 v24; // x8
  __int64 v25; // x25
  unsigned int v26; // w21
  __int64 v27; // x9
  int v28; // w10
  int v29; // w8
  unsigned int v30; // w10
  __int64 v31; // x28
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w8
  int v41; // w11
  void *v42; // x0
  __int64 v43; // x9
  unsigned __int16 v44; // w10
  int v45; // w11
  int v46; // w10
  void *v47; // x0
  __int64 v48; // x8
  bool v49; // zf
  void *v50; // x0
  __int64 v51; // x11
  __int64 v52; // x9
  __int64 v53; // x24
  __int64 v54; // x23
  __int64 v55; // x8
  __int64 v56; // x25
  unsigned __int64 v57; // x26
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x1
  unsigned int v67; // w23
  __int64 (__fastcall *v68)(__int64, __int64); // x9
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int (__fastcall *v77)(_QWORD); // x8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x0
  __int64 v87; // x1
  __int64 v88; // x2
  void (__fastcall *v89)(__int64, __int64, __int64, __int64); // x9
  __int64 v90; // x3
  void (__fastcall *v91)(_QWORD); // x8
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 (__fastcall *v100)(_QWORD); // x8
  _DWORD *v101; // x9
  void (__fastcall *v102)(_QWORD); // x8
  __int64 v103; // x22
  int v104; // w23
  int v105; // w0
  int v106; // w21
  int v107; // w0
  __int64 v109; // x0
  int v110; // w24
  unsigned int v111; // w21
  __int64 v112; // x25
  char v113; // w26
  int v114; // w28
  __int64 v115; // [xsp+0h] [xbp-30h]
  char v116; // [xsp+24h] [xbp-Ch]
  unsigned int v117; // [xsp+28h] [xbp-8h]
  int v118; // [xsp+2Ch] [xbp-4h]

  v15 = (_QWORD *)(a1 + 73728);
  v16 = *(_QWORD *)(a1 + 74256) + 36LL * (int)a2;
  if ( *(unsigned __int16 *)(v16 + 4) > a3 )
  {
    if ( *(_BYTE *)(v16 + 20) && (*(_BYTE *)(v16 + 33) & 1) == 0 )
    {
      v18 = a3 + 18 * a4 + *(_DWORD *)v16;
      if ( (v18 & 0x80000000) != 0 )
        return 0;
    }
    else
    {
      v18 = *(_DWORD *)v16 + a3;
      if ( (v18 & 0x80000000) != 0 )
        return 0;
    }
    if ( is_hal_verbose_debug_enabled == 1 )
    {
      v110 = a3;
      v111 = a2;
      v112 = a5;
      v113 = a6;
      v114 = a7;
      qdf_trace_msg(
        0x46u,
        8u,
        "%s: mac_id %d ring_id %d",
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        "hal_srng_setup_idx",
        a4,
        v18);
      a6 = v113;
      a7 = v114;
      a2 = v111;
      a5 = v112;
      a3 = v110;
      if ( v18 < 0xEE )
      {
LABEL_11:
        v24 = a1 + 312LL * v18;
        if ( *(_BYTE *)(v24 + 73) )
        {
          if ( is_hal_verbose_debug_enabled != 1 )
            return 0;
          goto LABEL_67;
        }
        v23 = v24 + 72;
        v25 = *(_QWORD *)(a1 + 16);
        v26 = a3;
        *(_BYTE *)(v24 + 72) = v18;
        *(_DWORD *)(v24 + 184) = a2;
        v117 = a2;
        v118 = a7;
        v116 = a6;
        *(_DWORD *)(v24 + 188) = *(_DWORD *)(v16 + 24);
        *(_QWORD *)(v24 + 80) = *(_QWORD *)a5;
        v27 = *(_QWORD *)(a5 + 8);
        *(_QWORD *)(v24 + 88) = v27;
        v28 = *(unsigned __int16 *)(v16 + 6);
        *(_DWORD *)(v24 + 116) = v28;
        v29 = *(_DWORD *)(a5 + 16);
        v30 = v29 * v28;
        *(_DWORD *)(v23 + 32) = v29;
        *(_DWORD *)(v23 + 36) = v30;
        *(_DWORD *)(v23 + 40) = v30 - 1;
        *(_QWORD *)(v23 + 24) = v27 + 4LL * v30;
        *(_QWORD *)(v23 + 64) = *(_QWORD *)(a5 + 24);
        *(_DWORD *)(v23 + 72) = *(_DWORD *)(a5 + 32);
        *(_DWORD *)(v23 + 48) = *(_DWORD *)(a5 + 36);
        *(_DWORD *)(v23 + 52) = *(_DWORD *)(a5 + 40);
        *(_WORD *)(v23 + 304) = *(_WORD *)(a5 + 84);
        *(_BYTE *)(v23 + 306) = *(_BYTE *)(a5 + 86);
        if ( (a6 & 1) == 0 )
          *(_DWORD *)(v23 + 56) = *(_DWORD *)(a5 + 80);
        v31 = a5;
        *(_QWORD *)(v23 + 160) = a1;
        *(_DWORD *)(v23 + 264) = 60 * v29 / 0x64u;
        *(_DWORD *)(v23 + 276) = 90 * v29 / 0x64u;
        *(_DWORD *)(v23 + 268) = 70 * v29 / 0x64u;
        *(_DWORD *)(v23 + 260) = 50 * v29 / 0x64u;
        *(_DWORD *)(v23 + 272) = 80 * v29 / 0x64u;
        *(_DWORD *)(v23 + 256) = 0;
        qdf_trace_msg(
          0x46u,
          5u,
          "%s: ring_id: %u, wm_thresh- <50:%u, 50-60:%u, 60-70:%u, 70-80:%u, 80-90:%u, 90-100:%u",
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          "hal_srng_update_high_wm_thresholds",
          v18,
          0,
          70 * v29 / 0x64u,
          80 * v29 / 0x64u,
          90 * v29 / 0x64u);
        v40 = v26;
        *(_QWORD *)(v23 + 96) = v25 + *(unsigned int *)(v16 + 8) + (int)(*(unsigned __int16 *)(v16 + 16) * v26);
        v41 = *(_DWORD *)(v23 + 116);
        *(_QWORD *)(v23 + 104) = v25 + *(unsigned int *)(v16 + 12) + (int)(*(unsigned __int16 *)(v16 + 18) * v26);
        *(_DWORD *)(v23 + 76) = *(_DWORD *)(v31 + 48);
        if ( v41 )
        {
          *(_DWORD *)(v23 + 120) = 0;
          *(_DWORD *)(v23 + 152) = 1;
          v42 = (void *)(v15[36] + 4LL * v18);
          *(_QWORD *)(v23 + 128) = v42;
          if ( v42 )
          {
            qdf_mem_set(v42, 4u, 0);
            v40 = v26;
          }
          if ( !*(_BYTE *)(v16 + 20) )
          {
            v43 = *(_QWORD *)(v23 + 160);
            v44 = 8732;
            goto LABEL_27;
          }
        }
        else
        {
          v45 = *(_DWORD *)(v23 + 44);
          v46 = *(_DWORD *)(v23 + 36) - v45;
          *(_DWORD *)(v23 + 120) = 0;
          *(_DWORD *)(v23 + 124) = v46;
          v47 = (void *)(v15[36] + 4LL * v18);
          *(_QWORD *)(v23 + 128) = v47;
          *(_DWORD *)(v23 + 152) = *(_DWORD *)(v31 + 44) * v45;
          if ( v47 )
          {
            qdf_mem_set(v47, 4u, 0);
            v40 = v26;
          }
          if ( !*(_BYTE *)(v16 + 20) )
          {
            v43 = *(_QWORD *)(v23 + 160);
            v44 = 8800;
LABEL_27:
            v51 = *(_QWORD *)(v23 + 104);
            v52 = *(int *)(v43 + (v44 | 0x10000u));
            v53 = *(_QWORD *)(v23 + 144);
            v54 = v51 + v52;
            if ( v53 )
            {
              v55 = *(_QWORD *)(a1 + 16);
              v56 = v55 + 2300;
              v57 = (unsigned __int64)(v53 - (v55 + 2300)) >> 2;
              if ( (unsigned int)v57 < 0x28 )
              {
                if ( *(_DWORD *)(a1 + ((unsigned __int8)(v53 - (v55 - 4)) & 0xFC) + 74060) == (_DWORD)v54 - (_DWORD)v55 )
                  goto LABEL_36;
                qdf_trace_msg(
                  0x3Fu,
                  2u,
                  "%s: sanity check failure, expected %x, found %x",
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  "hal_validate_shadow_register");
              }
              else
              {
                qdf_trace_msg(
                  0x3Fu,
                  2u,
                  "%s: index %x out of bounds",
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  "hal_validate_shadow_register",
                  (unsigned int)v57);
              }
              LODWORD(v115) = v57;
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: baddr %pK, destination %pK, shadow_address %pK s0offset %pK index %x",
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                "hal_validate_shadow_register",
                *(_QWORD *)(a1 + 16),
                v54,
                v53,
                v56,
                v115);
            }
            else
            {
              v66 = v51 + v52;
              v67 = v40;
              v68 = *(__int64 (__fastcall **)(__int64, __int64))(v15[83] + 48LL);
              if ( *((_DWORD *)v68 - 1) != 925895004 )
                __break(0x8229u);
              *(_QWORD *)(v23 + 144) = v68(a1, v66);
              qdf_trace_msg(
                0x3Fu,
                2u,
                "%s: Ring (%d, %d) missing shadow config",
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                "hal_srng_setup_idx",
                v117,
                v67);
            }
LABEL_36:
            if ( *(_BYTE *)(v16 + 20) )
            {
LABEL_63:
              *(_DWORD *)(v23 + 80) = 0;
              *(_QWORD *)(v23 + 88) = 0;
              *(_QWORD *)(v23 + 176) = 0;
              *(_BYTE *)(v23 + 1) = 1;
              return v23;
            }
            if ( v118 && (v116 & 1) != 0 )
            {
              v77 = *(unsigned int (__fastcall **)(_QWORD))(v15[83] + 1888LL);
              if ( *((_DWORD *)v77 - 1) != -222874020 )
                __break(0x8228u);
              if ( !v77(a1) )
              {
                qdf_trace_msg(
                  0x38u,
                  2u,
                  "%s: \nTx ring halt not set:Ring(%d, %d)",
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  "hal_srng_setup_idx",
                  v117,
                  v26);
                v109 = printk(
                         &unk_AAA255,
                         "0",
                         "hal_srng_setup_idx",
                         "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hal/wifi3.0/hal_srng.c");
                dump_stack(v109);
              }
              v86 = a1;
              v87 = v23;
              v88 = 1;
              v89 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v15[83]
                                                                              + 8LL * (*(_DWORD *)(v23 + 116) == 0));
              v90 = (unsigned __int16)v118;
            }
            else
            {
              if ( v118 )
              {
                v91 = *(void (__fastcall **)(_QWORD))(v15[83] + 1856LL);
                if ( *((_DWORD *)v91 - 1) != 504023983 )
                  __break(0x8228u);
                v91(a1);
                do
                {
                  qdf_trace_msg(
                    0x46u,
                    5u,
                    "%s: Waiting for ring reset",
                    v92,
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    v99,
                    "hal_srng_setup_idx");
                  v100 = *(__int64 (__fastcall **)(_QWORD))(v15[83] + 1872LL);
                  if ( *((_DWORD *)v100 - 1) != -964191369 )
                    __break(0x8228u);
                }
                while ( (v100(a1) & 1) == 0 );
                v101 = *(_DWORD **)(v15[83] + 8LL * (*(_DWORD *)(v23 + 116) == 0));
                if ( *(v101 - 1) != 520370472 )
                  __break(0x8229u);
                ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v101)(a1, v23, v116 & 1, (unsigned __int16)v118);
                v102 = *(void (__fastcall **)(_QWORD))(v15[83] + 1864LL);
                if ( *((_DWORD *)v102 - 1) != 504023983 )
                  __break(0x8228u);
                v102(a1);
                goto LABEL_60;
              }
              v88 = v116 & 1;
              v86 = a1;
              v87 = v23;
              v90 = 0;
              v89 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v15[83]
                                                                              + 8LL * (*(_DWORD *)(v23 + 116) == 0));
            }
            if ( *((_DWORD *)v89 - 1) != 520370472 )
              __break(0x8229u);
            v89(v86, v87, v88, v90);
LABEL_60:
            if ( v117 == 9 )
            {
              *(_WORD *)(v23 + 156) = *(_WORD *)(v31 + 20);
              v103 = v15[66];
              v104 = *(_DWORD *)(v103 + 332) + *(unsigned __int16 *)(v103 + 340) * v26;
              v105 = hal_read32_mb_0(a1, v104 + 176);
              hal_write32_mb_0(a1, (unsigned int)(v104 + 176), v105 & 0xFFFF0000 | *(unsigned __int16 *)(v23 + 156));
              if ( *(_DWORD *)(v23 + 56) )
              {
                v106 = *(_DWORD *)(v103 + 332) + *(unsigned __int16 *)(v103 + 340) * v26;
                v107 = hal_read32_mb_0(a1, v106 + 64);
                hal_write32_mb_0(a1, (unsigned int)(v106 + 64), v107 & 0xFFFFFFF8 | *(_DWORD *)(v23 + 56));
                hal_read32_mb_0(a1, v106 + 64);
              }
            }
            goto LABEL_63;
          }
        }
        v48 = v15[38] + 4LL * v18;
        v50 = (void *)(v48 - 736);
        v49 = v48 == 736;
        LODWORD(v48) = *(_DWORD *)(v23 + 76) | 0x80000000;
        *(_QWORD *)(v23 + 144) = v50;
        *(_DWORD *)(v23 + 76) = v48;
        if ( !v49 )
          qdf_mem_set(v50, 4u, 0);
        goto LABEL_36;
      }
    }
    else if ( v18 < 0xEE )
    {
      goto LABEL_11;
    }
    __break(0x5512u);
LABEL_67:
    v19 = "%s: Ring (ring_type, ring_num) already initialized";
    v20 = "hal_srng_setup_idx";
    v21 = 70;
    v22 = 8;
    goto LABEL_7;
  }
  v19 = "%s: ring_num exceeded maximum no. of supported rings";
  v20 = "hal_get_srng_ring_id";
  v21 = 63;
  v22 = 4;
LABEL_7:
  qdf_trace_msg(v21, v22, v19, a8, a9, a10, a11, a12, a13, a14, a15, v20);
  return 0;
}
