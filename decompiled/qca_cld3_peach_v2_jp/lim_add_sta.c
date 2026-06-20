__int64 __fastcall lim_add_sta(__int64 a1, unsigned __int16 *a2, char a3, __int64 a4)
{
  __int16 v8; // w8
  int v9; // w9
  __int64 v10; // x26
  __int64 v11; // x0
  int v12; // w9
  __int64 v13; // x20
  __int64 *v14; // x1
  unsigned int v15; // w22
  __int16 v16; // w8
  char v17; // w10
  bool v18; // w8
  int v19; // w8
  int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w9
  unsigned int v30; // w8
  int v31; // w9
  int v32; // w8
  int v33; // w8
  int v34; // w8
  int v35; // w8
  char v36; // w8
  __int64 v37; // x8
  __int64 v38; // x24
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  int v40; // w8
  __int64 v41; // x8
  unsigned __int64 v42; // x8
  int v43; // w9
  unsigned int v44; // w8
  unsigned int v45; // w9
  unsigned int v46; // w8
  char v47; // w8
  char v48; // w9
  char v49; // w8
  int v50; // w9
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  int v60; // w9
  int v61; // w8
  int v62; // w8
  int v63; // w8
  int v64; // w8
  int v65; // w8
  int v66; // w8
  int v67; // w8
  int v68; // w8
  __int64 v69; // x8
  __int64 v70; // x8
  char v71; // w9
  unsigned int v72; // w9
  unsigned __int16 v73; // w24
  __int64 v74; // x27
  _DWORD *v75; // x0
  __int64 v76; // x23
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x4
  const char *v86; // x2
  unsigned int v87; // w1
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // w12
  int v97; // w14
  int v98; // w15
  int v99; // w16
  char v100; // w9
  __int64 v101; // x5
  __int64 v102; // x6
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  int v127; // w8
  __int64 v129; // [xsp+0h] [xbp-D0h]
  __int64 v130; // [xsp+8h] [xbp-C8h]
  __int64 v131; // [xsp+10h] [xbp-C0h]
  __int64 v132; // [xsp+18h] [xbp-B8h]
  __int64 v133; // [xsp+20h] [xbp-B0h]
  __int64 v134; // [xsp+28h] [xbp-A8h]
  __int64 v135; // [xsp+30h] [xbp-A0h]
  __int64 v136; // [xsp+38h] [xbp-98h]
  __int64 v137; // [xsp+40h] [xbp-90h]
  __int64 v138; // [xsp+48h] [xbp-88h]
  __int64 v139; // [xsp+58h] [xbp-78h]
  __int64 v140; // [xsp+60h] [xbp-70h] BYREF
  __int64 v141; // [xsp+68h] [xbp-68h]
  __int64 v142; // [xsp+70h] [xbp-60h]
  __int64 v143; // [xsp+78h] [xbp-58h]
  __int64 v144; // [xsp+80h] [xbp-50h]
  __int64 v145; // [xsp+88h] [xbp-48h]
  __int64 v146; // [xsp+90h] [xbp-40h] BYREF
  __int64 v147; // [xsp+98h] [xbp-38h]
  __int64 v148; // [xsp+A0h] [xbp-30h]
  __int64 v149; // [xsp+A8h] [xbp-28h]
  __int64 v150; // [xsp+B0h] [xbp-20h]
  __int64 v151; // [xsp+B8h] [xbp-18h]
  __int64 v152; // [xsp+C0h] [xbp-10h] BYREF
  __int64 v153; // [xsp+C8h] [xbp-8h]

  v153 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_WORD *)(a4 + 30);
  v9 = *(_DWORD *)(a4 + 32);
  v10 = *(_QWORD *)(a1 + 8);
  v144 = 0;
  v145 = 0;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  LOWORD(v152) = v8;
  *(_DWORD *)((char *)&v152 + 2) = v9;
  v11 = _qdf_mem_malloc(0x110u, "lim_add_sta", 2309);
  if ( !v11 )
  {
    v15 = 2;
    goto LABEL_153;
  }
  v12 = *(_DWORD *)(a4 + 88);
  v13 = v11;
  if ( v12 == 6 || v12 == 1 )
  {
    v14 = (__int64 *)(a2 + 169);
  }
  else if ( *((_BYTE *)a2 + 344) == 4 )
  {
    v14 = (__int64 *)(a2 + 169);
  }
  else
  {
    v14 = &v152;
  }
  qdf_mem_copy((void *)(v11 + 9), v14, 6u);
  qdf_mem_copy((void *)v13, (const void *)(a4 + 24), 6u);
  qdf_mem_copy((void *)(v13 + 134), a2 + 11, 2u);
  qdf_mem_copy((void *)(v13 + 36), a2 + 132, 0x3Eu);
  *(_WORD *)(v13 + 6) = a2[168];
  *(_BYTE *)(v13 + 18) = (*(_BYTE *)a2 & 2) != 0;
  *(_WORD *)(v13 + 16) = a2[10];
  if ( *(_DWORD *)(a4 + 88) == 1 && (a2[16] & 1) != 0 )
    *(_BYTE *)(v13 + 104) = (a2[16] & 2) != 0;
  v16 = *a2;
  v17 = *((_BYTE *)a2 + 344);
  *((_DWORD *)a2 + 2) = 21;
  *a2 = v16 & 0xFFFE;
  *(_BYTE *)(v13 + 8) = v17;
  *(_BYTE *)(v13 + 104) = a3;
  *(_DWORD *)(v13 + 100) = 0;
  if ( *(_DWORD *)(a4 + 88) == 1 )
  {
    v18 = (a2[16] & 8) != 0 && *(_BYTE *)(a4 + 155) != 0;
    *(_BYTE *)(v13 + 21) = v18;
    LOBYTE(v19) = (a2[16] & 0x10) != 0 && *(_BYTE *)(a4 + 7170) != 0;
  }
  else if ( *((_BYTE *)a2 + 344) == 4 )
  {
    *(_BYTE *)(v13 + 21) = (a2[16] & 8) != 0;
    v19 = (*((unsigned __int8 *)a2 + 32) >> 4) & 1;
  }
  else
  {
    *(_BYTE *)(v13 + 21) = *(_BYTE *)(a4 + 155);
    LOBYTE(v19) = *(_BYTE *)(a4 + 7170);
  }
  *(_BYTE *)(v13 + 115) = v19;
  if ( !policy_mgr_is_hw_dbs_2x2_capable(*(_QWORD *)(a1 + 21552))
    && *(_DWORD *)(a4 + 88) == 1
    && *((_BYTE *)a2 + 344) == 1
    && !*(_BYTE *)(v13 + 115)
    && *(_BYTE *)(a4 + 8635) == 2 )
  {
    v20 = *(unsigned __int8 *)(a4 + 9793);
    *(_BYTE *)(a4 + 9793) = v20 + 1;
    if ( !v20 )
      wma_cli_set_command(*(unsigned __int8 *)(a4 + 10), 113, 1, 1);
  }
  lim_update_sta_he_capable(a1, v13, a2, a4);
  v29 = *(unsigned __int8 *)(v13 + 115);
  *(_BYTE *)(v13 + 33) = *((_BYTE *)a2 + 332) >> 5;
  *(_BYTE *)(v13 + 32) = a2[167] & 7;
  *(_BYTE *)(v13 + 35) = (a2[166] & 4) != 0;
  *(_BYTE *)(v13 + 34) = (a2[166] & 2) != 0;
  *(_DWORD *)(v13 + 24) = *((_DWORD *)a2 + 87);
  *(_DWORD *)(v13 + 28) = *((_DWORD *)a2 + 82);
  if ( v29 )
  {
    if ( *((_BYTE *)a2 + 345) )
      *(_DWORD *)(v13 + 24) = *((unsigned __int8 *)a2 + 345) + 1;
    v30 = *((unsigned __int8 *)a2 + 352);
    *(_BYTE *)(v13 + 116) = v30;
    v31 = *(_DWORD *)(a4 + 88);
    if ( v31 == 4 || v31 == 1 )
    {
      if ( v30 >= *(unsigned __int8 *)(a4 + 8635) )
        LOBYTE(v30) = *(_BYTE *)(a4 + 8635);
      *(_BYTE *)(v13 + 116) = v30;
    }
    v32 = *((unsigned __int8 *)a2 + 344);
    if ( v32 == 4 || v32 == 1 )
      LOBYTE(v33) = *((_BYTE *)a2 + 353);
    else
      v33 = (*(_DWORD *)(a4 + 7268) >> 12) & 1;
    *(_BYTE *)(v13 + 120) = v33;
    *(_BYTE *)(v13 + 121) = *((_BYTE *)a2 + 354);
    *(_BYTE *)(v13 + 130) = *((_BYTE *)a2 + 355);
  }
  v34 = *((unsigned __int8 *)a2 + 344);
  if ( !*((_BYTE *)a2 + 344) )
  {
    *(_BYTE *)(v13 + 128) = *(_BYTE *)(a4 + 7236) & 1;
    v35 = (*(unsigned __int8 *)(a4 + 7236) >> 1) & 1;
LABEL_55:
    *(_BYTE *)(v13 + 129) = v35;
    goto LABEL_56;
  }
  if ( v34 == 4 || v34 == 1 )
  {
    if ( *(_BYTE *)(v13 + 120) && *(_BYTE *)(v10 + 2679) == 1 )
    {
      LOBYTE(v35) = 0;
      *(_BYTE *)(v13 + 128) = 0;
    }
    else
    {
      if ( (*(_BYTE *)(a4 + 7236) & 1) != 0 )
        v36 = *((_BYTE *)a2 + 630);
      else
        v36 = 0;
      *(_BYTE *)(v13 + 128) = v36;
      if ( (*(_BYTE *)(a4 + 7236) & 2) != 0 )
        LOBYTE(v35) = *((_BYTE *)a2 + 631);
      else
        LOBYTE(v35) = 0;
    }
    goto LABEL_55;
  }
LABEL_56:
  *(_BYTE *)(v13 + 112) = *(_BYTE *)(a4 + 8);
  *(_BYTE *)(v13 + 131) = *(_BYTE *)(a4 + 10);
  *(_BYTE *)(v13 + 148) = *(_BYTE *)(a4 + 7032);
  v37 = *(_QWORD *)(a4 + 384);
  if ( v37 )
  {
    v38 = *(_QWORD *)(v37 + 8LL * a2[168]);
    if ( v38 )
    {
      if ( *(_BYTE *)(v38 + 3268) && *(_WORD *)(v38 + 1004) )
        vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                   &unk_89A401,
                                   4u,
                                   (unsigned __int8 *)(v38 + 1006),
                                   *(_WORD *)(v38 + 1004));
      else
        vendor_ie_ptr_from_oui = nullptr;
      v40 = *(unsigned __int8 *)(v13 + 21);
      *(_BYTE *)(v13 + 113) = vendor_ie_ptr_from_oui != nullptr;
      if ( v40 )
        qdf_mem_copy((void *)(v13 + 136), (const void *)(v38 + 3161), 2u);
      if ( *(_BYTE *)(v13 + 115) )
      {
        if ( *(_BYTE *)(v38 + 3344) )
          v41 = 3344;
        else
          v41 = 3296;
        v42 = *(_QWORD *)(v38 + v41);
        *(_DWORD *)(v13 + 140) = (unsigned __int16)((unsigned int)v42 >> 8)
                               | (((v42 >> 24) & 7) << 16) & 0xFFC7FFFF
                               | ((((unsigned int)(v42 >> 24) >> 3) & 1) << 19) & 0xFFCFFFFF
                               | ((((unsigned int)(v42 >> 24) >> 4) & 1) << 20) & 0xFFDFFFFF
                               | ((((unsigned int)(v42 >> 24) >> 5) & 1) << 21)
                               | (v42 >> 39 << 30)
                               | (((BYTE4(v42) & 7) << 23) | ((((unsigned int)(v42 >> 24) >> 6) & 1) << 22))
                               & 0xC3FFFFFF
                               | (((v42 >> 35) & 3) << 26) & 0xCFFFFFFF
                               | (((v42 >> 37) & 1) << 28) & 0xDFFFFFFF
                               | (((v42 >> 38) & 1) << 29);
      }
    }
    else
    {
      *(_BYTE *)(v13 + 113) = 0;
    }
    lim_add_he_cap(a1, a4, v13, v38);
  }
  if ( *((_BYTE *)a2 + 344) == 4 )
  {
    v43 = *(unsigned __int8 *)(v13 + 115);
    *(_WORD *)(v13 + 136) = a2[316];
    v44 = *((_DWORD *)a2 + 159);
    *(_DWORD *)(v13 + 140) = v44;
    if ( v43 )
      *(_BYTE *)(v13 + 32) = (v44 >> 23) & 7;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Adding tdls he capabilities",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_add_tdls_sta_he_config");
    qdf_mem_copy((void *)(v13 + 156), a2 + 418, 0x3Cu);
    if ( *(_BYTE *)(a4 + 8764) == 1 )
      lim_update_he_6ghz_band_caps(a1, a2 + 449, v13);
  }
  v45 = *a2;
  v46 = v45 >> 10;
  if ( (v45 & 0x40) != 0 && (*(_DWORD *)(a4 + 88) == 1 || *((_BYTE *)a2 + 344) == 4) )
  {
    *(_BYTE *)(v13 + 19) = 0;
    v47 = *((_BYTE *)a2 + 238);
    *(_BYTE *)(v13 + 19) = v47 & 1;
    v48 = a2[119] & 2 | v47 & 1;
    *(_BYTE *)(v13 + 19) = v48;
    v49 = a2[119] & 4 | v48;
    *(_BYTE *)(v13 + 19) = v49;
    *(_BYTE *)(v13 + 19) = a2[119] & 8 | v49 | (16 * (a2[119] & 8 | v49));
    *(_BYTE *)(v13 + 20) = (*((_BYTE *)a2 + 238) >> 5) & 3;
    v46 = *a2 >> 10;
  }
  v50 = *(unsigned __int8 *)(v13 + 128);
  *(_BYTE *)(v13 + 105) = v46 & 1;
  if ( !v50 )
    *(_WORD *)(v13 + 136) &= ~1u;
  if ( !*(_BYTE *)(v13 + 129) )
    *(_DWORD *)(v13 + 140) &= ~0x10u;
  *(_BYTE *)(a1 + 8885) = 0;
  *(_QWORD *)(a1 + 8888) = "lim_add_sta";
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v21, v22, v23, v24, v25, v26, v27, v28, "lim_add_sta", 0);
  v59 = *(unsigned __int8 *)(a1 + 8885);
  v150 = 0;
  v151 = 0;
  v148 = 0;
  v149 = 0;
  v146 = 0;
  v147 = 0;
  if ( v59 )
  {
    if ( *(_WORD *)(a1 + 8688) )
    {
      LOWORD(v146) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v146) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "lim_post_msg_to_process_deferred_queue",
          (unsigned __int16)v146);
    }
  }
  v60 = *(unsigned __int8 *)(v13 + 21);
  *(_DWORD *)(v13 + 144) = *(_DWORD *)(a4 + 96);
  if ( v60 )
  {
    if ( (*(_WORD *)(a4 + 7266) & 0x80) != 0 )
      *(_BYTE *)(v13 + 240) = (*(_WORD *)(v13 + 137) & 0x300) != 0;
  }
  else
  {
    if ( *(_BYTE *)(v13 + 115) )
      goto LABEL_129;
    if ( (*(_BYTE *)(v13 + 152) & 1) == 0 )
    {
      v61 = a2[136] & 0x7F;
      if ( ((unsigned int)(v61 - 12) > 0x3C || ((1LL << ((unsigned __int8)v61 - 12)) & 0x1000001001001041LL) == 0)
        && v61 != 96
        && v61 != 108 )
      {
        v62 = a2[137] & 0x7F;
        if ( ((unsigned int)(v62 - 12) > 0x3C || ((1LL << ((unsigned __int8)v62 - 12)) & 0x1000001001001041LL) == 0)
          && v62 != 96
          && v62 != 108 )
        {
          v63 = a2[138] & 0x7F;
          if ( ((unsigned int)(v63 - 12) > 0x3C || ((1LL << ((unsigned __int8)v63 - 12)) & 0x1000001001001041LL) == 0)
            && v63 != 96
            && v63 != 108 )
          {
            v64 = a2[139] & 0x7F;
            if ( ((unsigned int)(v64 - 12) > 0x3C || ((1LL << ((unsigned __int8)v64 - 12)) & 0x1000001001001041LL) == 0)
              && v64 != 96
              && v64 != 108 )
            {
              v65 = a2[140] & 0x7F;
              if ( ((unsigned int)(v65 - 12) > 0x3C || ((1LL << ((unsigned __int8)v65 - 12)) & 0x1000001001001041LL) == 0)
                && v65 != 96
                && v65 != 108 )
              {
                v66 = a2[141] & 0x7F;
                if ( ((unsigned int)(v66 - 12) > 0x3C
                   || ((1LL << ((unsigned __int8)v66 - 12)) & 0x1000001001001041LL) == 0)
                  && v66 != 96
                  && v66 != 108 )
                {
                  v67 = a2[142] & 0x7F;
                  if ( ((unsigned int)(v67 - 12) > 0x3C
                     || ((1LL << ((unsigned __int8)v67 - 12)) & 0x1000001001001041LL) == 0)
                    && v67 != 96
                    && v67 != 108 )
                  {
                    v68 = a2[143] & 0x7F;
                    if ( ((unsigned int)(v68 - 12) > 0x3C
                       || ((1LL << ((unsigned __int8)v68 - 12)) & 0x1000001001001041LL) == 0)
                      && v68 != 96
                      && v68 != 108 )
                    {
                      *(_DWORD *)(v13 + 144) = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( *(_BYTE *)(v13 + 115) )
  {
LABEL_129:
    if ( *(_BYTE *)(v13 + 240) )
      *(_BYTE *)(v13 + 240) = (*(_WORD *)(v13 + 141) & 0x700) != 0;
  }
  if ( (*(_DWORD *)(a4 + 7036) | 2) == 3 )
  {
    v69 = *(_QWORD *)(a4 + 384);
    if ( v69 )
    {
      v70 = *(_QWORD *)(v69 + 8LL * a2[168]);
      if ( v70 )
      {
        v71 = *(_BYTE *)(v70 + 3267);
        *(_BYTE *)(v13 + 132) = v71;
        *(_BYTE *)(v13 + 132) = v71 | (2 * *(_BYTE *)(v70 + 3266));
        if ( *(_BYTE *)(v70 + 3267) )
        {
          v72 = *(_DWORD *)(v70 + 3280);
          v73 = v72 - 4;
          if ( v72 >= 4 )
          {
            v74 = *(_QWORD *)(v70 + 3288);
            v75 = (_DWORD *)_qdf_mem_malloc(0x120u, "lim_add_sta", 2653);
            if ( v75 )
            {
              v76 = (__int64)v75;
              if ( (unsigned int)wlan_get_crypto_params_from_rsn_ie(v75, v74 + 4, v73, nullptr) )
              {
                v85 = *(unsigned __int8 *)(a4 + 10);
                v86 = "%s: vdev:%d Failed to extract crypto_params";
                v87 = 2;
              }
              else
              {
                v85 = *(unsigned int *)(v76 + 20);
                v86 = "%s: Peer key_mgmt:0x%x";
                v87 = 8;
                *(_DWORD *)(v13 + 252) = v85;
              }
              qdf_trace_msg(0x35u, v87, v86, v77, v78, v79, v80, v81, v82, v83, v84, "lim_add_sta", v85);
              _qdf_mem_free(v76);
            }
          }
        }
        else
        {
          qdf_trace_msg(0x35u, 8u, "%s: RSN is not present", v51, v52, v53, v54, v55, v56, v57, v58, "lim_add_sta");
        }
      }
    }
  }
  if ( *(_BYTE *)(v13 + 152) == 1 && *(_BYTE *)(v13 + 240) )
    *(_BYTE *)(v13 + 240) = (*(_BYTE *)(v13 + 165) & 0x10) != 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: he_mcs_12_13_map %0x",
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    "lim_update_he_mcs_12_13",
    a2[448]);
  if ( a2[448] )
    *(_WORD *)(v13 + 238) = a2[448];
  v96 = *(unsigned __int8 *)(v13 + 104);
  v97 = *(unsigned __int8 *)(v13 + 18);
  v98 = *(unsigned __int16 *)(v13 + 16);
  *(_BYTE *)(v13 + 241) = *(_BYTE *)(a4 + 10045);
  v99 = *(unsigned __int8 *)(v13 + 21);
  v100 = *(_BYTE *)(a4 + 10046);
  v140 = 4129;
  v141 = v13;
  v101 = *(unsigned __int8 *)(v13 + 9);
  v102 = *(unsigned __int8 *)(v13 + 10);
  *(_BYTE *)(v13 + 242) = v100;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev %d: %02x:%02x:%02x:**:**:%02x opmode %d sta_type %d subtype %d: update %d aid %d wmm %d li %d ht %d vht %d ht client %d",
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    "lim_add_sta",
    *(unsigned __int8 *)(a4 + 10),
    v101,
    v102,
    *(unsigned __int8 *)(v13 + 11),
    *(unsigned __int8 *)(v13 + 14),
    *(_DWORD *)(a4 + 7036),
    *((unsigned __int8 *)a2 + 344),
    a2[16] & 1,
    v96,
    *(unsigned __int16 *)(v13 + 6),
    v97,
    v98,
    v99,
    *(unsigned __int8 *)(v13 + 115),
    *(unsigned __int8 *)(a4 + 9793),
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    v150,
    v151,
    v152,
    v153);
  LODWORD(v133) = *(unsigned __int8 *)(v13 + 19);
  LODWORD(v136) = *(unsigned __int8 *)(v13 + 128);
  LODWORD(v138) = *(unsigned __int8 *)(v13 + 113);
  LODWORD(v137) = *(unsigned __int8 *)(v13 + 129);
  LODWORD(v135) = *(unsigned __int8 *)(v13 + 105);
  LODWORD(v134) = *(unsigned __int8 *)(v13 + 20);
  LODWORD(v132) = *(unsigned __int8 *)(v13 + 130);
  LODWORD(v131) = *(unsigned __int8 *)(v13 + 121);
  LODWORD(v130) = *(unsigned __int8 *)(v13 + 120);
  LODWORD(v129) = *(_DWORD *)(v13 + 28);
  qdf_trace_msg(
    0x35u,
    8u,
    "max_ampdu: density %d size %d, width %d sgi20 %d sgi40 %d mimops %d txbf %d subfer %d vht_mcs11 %d uapsd %d max sple"
    "n %d pmf %d ht ldpc %d vht ldpc %d isp2p %d",
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    v110,
    *(unsigned __int8 *)(v13 + 33),
    *(unsigned __int8 *)(v13 + 32),
    *(unsigned int *)(v13 + 24),
    *(unsigned __int8 *)(v13 + 35),
    *(unsigned __int8 *)(v13 + 34),
    v129,
    v130,
    v131,
    v132,
    v133,
    v134,
    v135,
    v136,
    v137,
    v138);
  mac_trace_msg_tx(a1, *(unsigned __int8 *)(a4 + 8), 4129);
  v15 = wma_post_ctrl_msg(a1, &v140);
  if ( v15 )
  {
    *(_BYTE *)(a1 + 8885) = 1;
    *(_QWORD *)(a1 + 8888) = "lim_add_sta";
    qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v111, v112, v113, v114, v115, v116, v117, v118, "lim_add_sta", 1);
    v127 = *(unsigned __int8 *)(a1 + 8885);
    v150 = 0;
    v151 = 0;
    v148 = 0;
    v149 = 0;
    v146 = 0;
    v147 = 0;
    if ( v127 )
    {
      if ( *(_WORD *)(a1 + 8688) )
      {
        LOWORD(v146) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v146) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to post lim msg:0x%x",
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            v125,
            v126,
            "lim_post_msg_to_process_deferred_queue",
            (unsigned __int16)v146);
      }
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: ADD_STA_REQ for aId %d failed (reason %X)",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "lim_add_sta",
      a2[168],
      v15);
    _qdf_mem_free(v13);
  }
LABEL_153:
  _ReadStatusReg(SP_EL0);
  return v15;
}
