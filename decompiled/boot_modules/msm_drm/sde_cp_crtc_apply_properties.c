__int64 __fastcall sde_cp_crtc_apply_properties(_QWORD *a1)
{
  __int64 v1; // x20
  unsigned __int64 v2; // x27
  int disp_op; // w0
  int v5; // w7
  int v6; // w8
  unsigned int v7; // w10
  __int64 v8; // x8
  __int64 v9; // x9
  int demura_sw_fuse_value; // w21
  __int64 result; // x0
  __int64 v12; // x26
  _QWORD *v13; // x23
  __int64 v14; // x24
  unsigned int v15; // w4
  __int64 *v16; // x8
  __int64 v17; // x22
  __int64 v18; // x28
  __int64 v19; // x25
  __int64 v20; // x1
  unsigned int v21; // w2
  __int64 v22; // x10
  unsigned int v23; // w1
  unsigned int v24; // w8
  _QWORD *v25; // x15
  int v26; // w8
  int v27; // w11
  int v28; // w12
  int v29; // w13
  __int64 v30; // x14
  __int64 v31; // x16
  __int64 v32; // x17
  __int64 v33; // x9
  __int64 *v34; // x11
  __int64 v35; // x10
  __int64 v36; // x12
  int v37; // w0
  _QWORD *v38; // x8
  __int64 v39; // x9
  int v40; // w8
  __int64 v41; // x0
  __int64 v42; // x1
  __int64 v43; // x2
  __int64 v44; // x22
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x4
  __int64 v48; // x9
  size_t v49; // x3
  __int64 v50; // x2
  __int64 v51; // x9
  __int64 v52; // x0
  _QWORD *v53; // x8
  __int64 *v54; // x9
  __int64 v55; // x10
  unsigned int v56; // w8
  unsigned __int64 *v57; // x1
  _QWORD *v58; // x8
  int v59; // w4
  int v60; // w28
  __int64 v61; // x8
  int v62; // w0
  __int64 v63; // x8
  __int64 v64; // x22
  unsigned int v65; // w0
  int v66; // w8
  unsigned int v67; // w23
  int v68; // w22
  __int64 v69; // x0
  __int64 *v70; // x24
  __int64 v71; // x25
  __int64 v72; // x26
  void (__fastcall *v73)(_QWORD); // x8
  __int64 v74; // x0
  void (__fastcall *v75)(__int64, __int64, __int64); // x8
  __int64 v76; // x1
  int v77; // w4
  int v78; // w10
  _QWORD *v79; // x25
  int v80; // w8
  _QWORD *v81; // x24
  __int64 v82; // x8
  int v83; // w9
  _DWORD *v84; // x22
  __int64 v85; // x21
  int v86; // w1
  int v87; // w10
  __int64 v88; // x8
  __int64 v89; // x9
  int v90; // w8
  bool v91; // zf
  __int64 v92; // x9
  char v93; // w10
  int v94; // w10
  _DWORD *v95; // x10
  int v96; // w9
  __int64 v97; // x23
  _DWORD *v98; // x21
  int v99; // w8
  unsigned __int64 v100; // x25
  __int64 *v101; // x26
  __int64 v102; // x9
  __int64 v103; // x10
  __int64 v104; // x0
  int v105; // w11
  int v106; // w0
  int v107; // w1
  __int64 v108; // x8
  __int64 v109; // x9
  __int64 v110; // x9
  __int64 v111; // x10
  __int64 v112; // x9
  char v113; // w22
  _QWORD *v114; // x0
  _QWORD *v115; // x22
  unsigned int v116; // w8
  unsigned __int64 v117; // x23
  __int64 v118; // x24
  __int64 v119; // x21
  void (__fastcall *v120)(__int64, __int64, __int64); // x8
  __int64 v121; // x9
  __int64 v122; // x1
  __int64 v123; // x0
  void (__fastcall *v124)(__int64, __int64, __int64); // x8
  __int64 v125; // x9
  __int64 v126; // x1
  char v127; // [xsp+0h] [xbp-130h]
  __int64 v128; // [xsp+8h] [xbp-128h]
  _QWORD *v129; // [xsp+18h] [xbp-118h]
  unsigned int v130; // [xsp+20h] [xbp-110h]
  unsigned int v131; // [xsp+24h] [xbp-10Ch]
  _QWORD *v132; // [xsp+28h] [xbp-108h]
  _QWORD *v133; // [xsp+30h] [xbp-100h]
  char v134; // [xsp+38h] [xbp-F8h]
  __int64 v135; // [xsp+40h] [xbp-F0h] BYREF
  __int64 v136; // [xsp+48h] [xbp-E8h] BYREF
  _DWORD *v137; // [xsp+50h] [xbp-E0h] BYREF
  __int64 v138; // [xsp+58h] [xbp-D8h]
  __int64 v139; // [xsp+60h] [xbp-D0h]
  __int64 v140; // [xsp+68h] [xbp-C8h]
  __int64 v141; // [xsp+70h] [xbp-C0h]
  __int64 v142; // [xsp+78h] [xbp-B8h]
  __int64 v143; // [xsp+80h] [xbp-B0h]
  __int64 v144; // [xsp+88h] [xbp-A8h]
  __int64 v145; // [xsp+90h] [xbp-A0h]
  __int64 v146; // [xsp+98h] [xbp-98h]
  __int64 v147; // [xsp+A0h] [xbp-90h]
  __int64 v148; // [xsp+A8h] [xbp-88h]
  __int64 v149; // [xsp+B0h] [xbp-80h]
  __int64 v150; // [xsp+B8h] [xbp-78h]
  __int64 v151; // [xsp+C0h] [xbp-70h]
  __int64 v152; // [xsp+C8h] [xbp-68h]
  __int64 v153; // [xsp+D0h] [xbp-60h]
  __int64 v154; // [xsp+D8h] [xbp-58h]
  __int64 v155; // [xsp+E0h] [xbp-50h]
  __int64 v156; // [xsp+E8h] [xbp-48h]
  __int64 v157; // [xsp+F0h] [xbp-40h]
  __int64 v158; // [xsp+F8h] [xbp-38h]
  __int64 v159; // [xsp+100h] [xbp-30h]
  __int64 v160; // [xsp+108h] [xbp-28h]
  __int64 v161; // [xsp+110h] [xbp-20h]
  __int64 v162; // [xsp+118h] [xbp-18h]
  __int64 v163; // [xsp+120h] [xbp-10h]

  v163 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*a1 )
  {
    result = _drm_err("invalid crtc %pK dev %pK\n", a1, nullptr);
    goto LABEL_36;
  }
  disp_op = sde_crtc_get_disp_op((__int64)a1);
  if ( !a1[251] )
  {
    result = _drm_err("invalid sde_crtc_state %pK\n", nullptr);
    goto LABEL_36;
  }
  v6 = *((_DWORD *)a1 + 548);
  if ( !v6 )
    goto LABEL_37;
  if ( (unsigned int)(v6 - 9) < 0xFFFFFFF8 )
    goto LABEL_330;
  LODWORD(v2) = disp_op;
  v7 = a1[277] != 0;
  if ( v6 != 1 )
  {
    if ( a1[283] )
      ++v7;
    if ( v6 != 2 )
    {
      if ( a1[289] )
        ++v7;
      if ( v6 != 3 )
      {
        if ( a1[295] )
          ++v7;
        if ( v6 != 4 )
        {
          if ( a1[301] )
            ++v7;
          if ( v6 != 5 )
          {
            if ( a1[307] )
              ++v7;
            if ( v6 != 6 )
            {
              if ( a1[313] )
                ++v7;
              if ( v6 != 7 && a1[319] )
                ++v7;
            }
          }
        }
      }
    }
  }
  if ( !v7 )
  {
LABEL_37:
    result = _drm_dev_dbg(0, 0, 1, "no mixers for this crtc\n");
    goto LABEL_36;
  }
  v130 = v7;
  v8 = *(_QWORD *)(*(_QWORD *)(*a1 + 56LL) + 8LL);
  if ( !v8 )
  {
    _drm_dev_dbg(0, 0, 1, "!kms = %d\n", 1);
LABEL_40:
    demura_sw_fuse_value = 0;
    goto LABEL_41;
  }
  v9 = *(_QWORD *)(v8 + 152);
  if ( v9 )
    LOBYTE(v9) = *(_BYTE *)(v9 + 20120);
  demura_sw_fuse_value = 1;
  if ( (v9 & 1) == 0 && disp_op != 1 )
  {
    if ( *(_QWORD *)(v8 + 3560) )
    {
      demura_sw_fuse_value = sde_hw_get_demura_sw_fuse_value();
      _drm_dev_dbg(0, 0, 1, "demura_sw_fuse value: 0x%x\n", demura_sw_fuse_value);
      goto LABEL_41;
    }
    goto LABEL_40;
  }
LABEL_41:
  v12 = a1[251];
  v131 = v2;
  v134 = (char)a1;
  if ( v12 )
  {
    if ( (unsigned int)(*(_DWORD *)(v12 + 4608) - 53) >= 0xFFFFFFCC )
    {
      v13 = (_QWORD *)(v12 + 5864);
      v1 = v12 + 4616;
      v14 = 0;
      v128 = v12 + 6072;
      v129 = a1 + 569;
      v132 = a1 + 571;
      v133 = a1 + 277;
      while ( 1 )
      {
        if ( v14 == 52 )
          goto LABEL_330;
        v15 = *((_DWORD *)v13 + v14);
        if ( v15 >= 0x34 )
          goto LABEL_44;
        v16 = (__int64 *)(v1 + 24LL * v15);
        v17 = *v16;
        v18 = v16[1];
        *v16 = 0;
        v16[1] = 0;
        v19 = v16[2];
        v16[2] = 0;
        sde_evtlog_log(sde_dbg_base_evtlog, "_sde_cp_flush_properties", 2659, -1, v15, v18, -1059143953, v5, v127);
        if ( !v19 )
          goto LABEL_44;
        mutex_lock(a1 + 583);
        v20 = *((unsigned int *)a1 + 548);
        if ( (unsigned int)v20 >= 9 )
        {
          printk(&unk_27086C, v20);
          goto LABEL_142;
        }
        if ( (_DWORD)v20 )
        {
          v21 = a1[277] != 0;
          if ( (_DWORD)v20 != 1 )
          {
            if ( a1[283] )
              ++v21;
            if ( (_DWORD)v20 != 2 )
            {
              if ( a1[289] )
                ++v21;
              if ( (_DWORD)v20 != 3 )
              {
                if ( a1[295] )
                  ++v21;
                if ( (_DWORD)v20 != 4 )
                {
                  if ( a1[301] )
                    ++v21;
                  if ( (_DWORD)v20 != 5 )
                  {
                    if ( a1[307] )
                      ++v21;
                    if ( (_DWORD)v20 != 6 )
                    {
                      if ( a1[313] )
                        ++v21;
                      if ( (_DWORD)v20 != 7 && a1[319] )
                        ++v21;
                    }
                  }
                }
              }
            }
          }
          if ( v21 )
            break;
        }
LABEL_97:
        v37 = sde_cp_ad_validate_prop(v19, a1);
        if ( v37 )
        {
          _drm_err("ad property validation failed ret %d\n", v37);
          goto LABEL_142;
        }
        v38 = *(_QWORD **)(v19 + 80);
        v2 = v19 + 72;
        if ( *v38 == v19 + 72 && (v39 = *(_QWORD *)v2, *(_QWORD *)(*(_QWORD *)v2 + 8LL) == v2) )
        {
          *(_QWORD *)(v39 + 8) = v38;
          *v38 = v39;
        }
        else
        {
          _list_del_entry_valid_or_report(v19 + 72);
        }
        *(_QWORD *)(v19 + 72) = v19 + 72;
        *(_QWORD *)(v19 + 80) = v2;
        v40 = *(_DWORD *)(v17 + 48);
        if ( (v40 & 0x10) != 0 )
        {
          if ( v18 )
          {
            v41 = drm_property_lookup_blob(*a1, (unsigned int)v18);
            if ( !v41 )
            {
              _drm_err("invalid blob id %lld feature %d\n", v18, *(_DWORD *)(v19 + 8));
              goto LABEL_142;
            }
            v42 = *(_QWORD *)(v41 + 72);
            v43 = *(unsigned int *)(v19 + 92);
            v44 = v41;
            if ( v42 != v43 )
            {
              _drm_err("invalid blob len %zd exp %d feature %d\n", v42, v43, *(_DWORD *)(v19 + 8));
              drm_property_blob_put(v44);
              goto LABEL_142;
            }
            v45 = *(_QWORD *)(v19 + 16);
            if ( v45 )
              drm_property_blob_put(v45);
            *(_QWORD *)(v19 + 16) = v44;
            *(_QWORD *)(v19 + 24) = v18;
          }
          else
          {
            v52 = *(_QWORD *)(v19 + 16);
            if ( v52 )
              drm_property_blob_put(v52);
            *(_QWORD *)(v19 + 16) = 0;
            *(_QWORD *)(v19 + 24) = 0;
          }
          goto LABEL_128;
        }
        if ( (v40 & 2) == 0 )
        {
          if ( (v40 & 8) == 0 )
            goto LABEL_142;
          goto LABEL_119;
        }
        v46 = *(_QWORD *)(v19 + 16);
        if ( !v46 )
          goto LABEL_119;
        if ( v18 )
        {
          v47 = *(unsigned int *)(v19 + 8);
          if ( (unsigned int)v47 >= 0x34 )
            goto LABEL_330;
          v48 = v128 + 16 * v47;
          if ( !*(_QWORD *)v48 )
          {
            v50 = *(_QWORD *)(v46 + 72);
            LODWORD(v49) = *(_DWORD *)(v48 + 8);
LABEL_173:
            _drm_err("invalid addr %llu exp len %zu act %d feature is %d\n", *(_QWORD *)v48, v50, v49, v47);
            goto LABEL_142;
          }
          v49 = *(unsigned int *)(v48 + 8);
          v50 = *(_QWORD *)(v46 + 72);
          if ( v50 != v49 )
            goto LABEL_173;
          v51 = *(unsigned int *)(v19 + 8);
          if ( (unsigned int)v51 > 0x33 )
            goto LABEL_330;
          memcpy(*(void **)(v46 + 80), *(const void **)(v128 + 16 * v51), v49);
LABEL_119:
          *(_QWORD *)(v19 + 24) = v18;
          goto LABEL_128;
        }
        *(_QWORD *)(v19 + 24) = 0;
LABEL_128:
        v53 = *(_QWORD **)(v19 + 64);
        v54 = (__int64 *)(v19 + 56);
        if ( *v53 == v19 + 56 && (v55 = *v54, *(__int64 **)(*v54 + 8) == v54) )
        {
          *(_QWORD *)(v55 + 8) = v53;
          *v53 = v55;
        }
        else
        {
          _list_del_entry_valid_or_report(v19 + 56);
        }
        *(_QWORD *)(v19 + 56) = v19 + 56;
        *(_QWORD *)(v19 + 64) = v54;
        v56 = *(_DWORD *)(v19 + 8);
        if ( v56 <= 0x2B && ((1LL << v56) & 0x7F8000) != 0 )
        {
          v57 = (unsigned __int64 *)a1[572];
          if ( (_QWORD *)v2 != v132 && (unsigned __int64 *)v2 != v57 && (_QWORD *)*v57 == v132 )
          {
            v58 = a1 + 571;
            a1[572] = v2;
LABEL_141:
            *(_QWORD *)(v19 + 72) = v58;
            *(_QWORD *)(v19 + 80) = v57;
            *v57 = v2;
            goto LABEL_142;
          }
        }
        else
        {
          v57 = (unsigned __int64 *)a1[570];
          if ( (_QWORD *)v2 != v129 && (unsigned __int64 *)v2 != v57 && (_QWORD *)*v57 == v129 )
          {
            v58 = a1 + 569;
            a1[570] = v2;
            goto LABEL_141;
          }
        }
        _list_add_valid_or_report(v19 + 72, v57);
LABEL_142:
        mutex_unlock(a1 + 583);
        v59 = *(_DWORD *)(v19 + 8);
        v2 = *(_QWORD *)(v19 + 24);
        if ( v59 <= 44 )
        {
          if ( v59 != 42 )
          {
            if ( v59 != 43 )
            {
              if ( v59 != 44 )
                goto LABEL_168;
              if ( v2 )
                *((_BYTE *)a1 + 7948) = 1;
              else
                *((_BYTE *)a1 + 7948) = 0;
              goto LABEL_167;
            }
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "_sde_cp_check_aiqe_properties",
              5080,
              -1,
              43,
              *((unsigned __int8 *)a1 + 7948),
              -1059143953,
              v5,
              v127);
            if ( v2 )
            {
              v63 = *(_QWORD *)(v19 + 16);
              if ( v63 )
              {
                v64 = *(_QWORD *)(v63 + 80);
                if ( (*((_BYTE *)a1 + 7948) & 1) != 0 )
                {
                  aiqe_register_client(2);
                  get_mdnie_art_frame_count(a1 + 1003, *(unsigned int *)(v64 + 8));
                }
                else
                {
                  *(_DWORD *)(v64 + 8) = 0;
                  *((_DWORD *)a1 + 2006) = 1;
                }
              }
              goto LABEL_167;
            }
            v62 = 2;
            goto LABEL_166;
          }
          v60 = 1;
          goto LABEL_162;
        }
        if ( v59 != 45 )
        {
          if ( v59 == 47 )
          {
            v60 = 5;
          }
          else
          {
            if ( v59 != 49 )
              goto LABEL_168;
            v60 = 3;
          }
LABEL_162:
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_cp_check_aiqe_properties",
            5080,
            -1,
            v59,
            *((unsigned __int8 *)a1 + 7948),
            -1059143953,
            v5,
            v127);
          v62 = v60;
          if ( !v2 )
            goto LABEL_166;
          goto LABEL_163;
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "_sde_cp_check_aiqe_properties",
          5080,
          -1,
          45,
          *((unsigned __int8 *)a1 + 7948),
          -1059143953,
          v5,
          v127);
        v61 = *(_QWORD *)(v19 + 16);
        if ( !v61 || *(_DWORD *)(v19 + 92) != 68 || (*(_BYTE *)(v61 + 4) & 1) == 0 )
        {
          v62 = 4;
LABEL_166:
          aiqe_deregister_client(v62);
          goto LABEL_167;
        }
        v62 = 4;
LABEL_163:
        aiqe_register_client(v62);
LABEL_167:
        v59 = *(_DWORD *)(v19 + 8);
        v2 = *(_QWORD *)(v19 + 24);
LABEL_168:
        if ( (unsigned int)(v59 - 3) <= 5 )
          cp_feature_set_curr_mode(dword_289B88[v59 - 3], a1 + 1056, v2);
LABEL_44:
        if ( ++v14 >= (unsigned __int64)*(unsigned int *)(v12 + 4608) )
        {
          *(_DWORD *)(v12 + 4608) = 0;
          *v13 = 0;
          *(_QWORD *)(v12 + 5872) = 0;
          *(_QWORD *)(v12 + 5880) = 0;
          *(_QWORD *)(v12 + 5888) = 0;
          *(_QWORD *)(v12 + 5896) = 0;
          *(_QWORD *)(v12 + 5904) = 0;
          *(_QWORD *)(v12 + 5912) = 0;
          *(_QWORD *)(v12 + 5920) = 0;
          *(_QWORD *)(v12 + 5928) = 0;
          *(_QWORD *)(v12 + 5936) = 0;
          *(_QWORD *)(v12 + 5944) = 0;
          *(_QWORD *)(v12 + 5952) = 0;
          *(_QWORD *)(v12 + 5960) = 0;
          *(_QWORD *)(v12 + 5968) = 0;
          *(_QWORD *)(v12 + 5976) = 0;
          *(_QWORD *)(v12 + 5984) = 0;
          *(_QWORD *)(v12 + 5992) = 0;
          *(_QWORD *)(v12 + 6000) = 0;
          *(_QWORD *)(v12 + 6008) = 0;
          *(_QWORD *)(v12 + 6016) = 0;
          *(_QWORD *)(v12 + 6024) = 0;
          *(_QWORD *)(v12 + 6032) = 0;
          *(_QWORD *)(v12 + 6040) = 0;
          *(_QWORD *)(v12 + 6048) = 0;
          *(_QWORD *)(v12 + 6056) = 0;
          *(_QWORD *)(v12 + 6064) = 0;
          goto LABEL_178;
        }
      }
      if ( v21 - 9 < 0xFFFFFFF8 )
        goto LABEL_330;
      if ( v21 == 1 )
      {
        v22 = 0;
        v23 = 0;
        v24 = 0;
      }
      else
      {
        v22 = v21 & 0xE;
        v25 = a1 + 283;
        v26 = 0;
        v27 = 0;
        v28 = 0;
        v29 = 0;
        v30 = v22;
        do
        {
          v31 = *(v25 - 8);
          if ( *(v25 - 6) )
            ++v28;
          v32 = *(v25 - 2);
          if ( *v25 )
            ++v29;
          v25 += 12;
          if ( v31 )
            ++v26;
          if ( v32 )
            ++v27;
          v30 -= 2;
        }
        while ( v30 );
        v23 = v27 + v26;
        v24 = v29 + v28;
        if ( v22 == v21 )
        {
LABEL_92:
          if ( *(_BYTE *)(v19 + 88) == 1 && v24 < v21 )
          {
            _drm_err("invalid dspp cnt %d mixer cnt %d\n", v24, v21);
            goto LABEL_142;
          }
          if ( v23 < v21 )
          {
            _drm_err("invalid lm cnt %d mixer cnt %d\n", v23, v21);
            goto LABEL_142;
          }
          goto LABEL_97;
        }
      }
      v33 = v21 - v22;
      v34 = &v133[6 * (unsigned int)v22];
      do
      {
        v35 = *v34;
        v36 = *(v34 - 2);
        v34 += 6;
        if ( v35 )
          ++v24;
        if ( v36 )
          ++v23;
        --v33;
      }
      while ( v33 );
      goto LABEL_92;
    }
  }
  else
  {
    _drm_err("invalid sde_crtc_state %pK\n", nullptr);
  }
LABEL_178:
  sde_cp_check_mdnie_art_done(a1);
  mutex_lock(a1 + 583);
  v65 = sde_crtc_get_disp_op((__int64)a1);
  v66 = *((_DWORD *)a1 + 548);
  if ( !v66 )
    goto LABEL_218;
  if ( (unsigned int)(v66 - 9) < 0xFFFFFFF8 )
    goto LABEL_330;
  v67 = v65;
  v68 = a1[277] != 0;
  if ( v66 != 1 )
  {
    if ( a1[283] )
      ++v68;
    if ( v66 != 2 )
    {
      if ( a1[289] )
        ++v68;
      if ( v66 != 3 )
      {
        if ( a1[295] )
          ++v68;
        if ( v66 != 4 )
        {
          if ( a1[301] )
            ++v68;
          if ( v66 != 5 )
          {
            if ( a1[307] )
              ++v68;
            if ( v66 != 6 )
            {
              if ( a1[313] )
                ++v68;
              if ( v66 != 7 && a1[319] )
                ++v68;
            }
          }
        }
      }
    }
  }
  if ( v68 )
  {
    v69 = raw_spin_lock_irqsave(a1 + 969);
    if ( (*((_BYTE *)a1 + 7673) & 1) != 0 )
    {
      v133 = (_QWORD *)v69;
      sde_cp_dspp_flush_helper(a1, 26);
      v2 = 0;
      LOBYTE(v1) = v68;
      v70 = a1 + 277;
      do
      {
        if ( v2 == 8 )
          goto LABEL_330;
        if ( v2 <= 4 )
        {
          v71 = *v70;
          if ( *v70 )
          {
            v72 = *(v70 - 1);
            if ( v72 )
            {
              if ( v67 > 2 )
                goto LABEL_330;
              v73 = *(void (__fastcall **)(_QWORD))(v71 + 8LL * v67 + 760);
              if ( v73 )
              {
                v74 = *v70;
                if ( *((_DWORD *)v73 - 1) != 206991498 )
                  __break(0x8228u);
                v73(v74);
              }
              v75 = *(void (__fastcall **)(__int64, __int64, __int64))(v72 + 8LL * v67 + 1096);
              if ( v75 )
              {
                v76 = *(unsigned int *)(v71 + 64);
                if ( *((_DWORD *)v75 - 1) != -365933170 )
                  __break(0x8228u);
                v75(v72, v76, 1);
              }
            }
          }
        }
        ++v2;
        v70 += 6;
      }
      while ( v68 != v2 );
      v77 = *((_DWORD *)a1 + 28);
      *((_BYTE *)a1 + 7673) = 0;
      sde_evtlog_log(sde_dbg_base_evtlog, "_sde_clear_ltm_merge_mode", 2233, -1, v77, v68, 0, -1059143953, v127);
      raw_spin_unlock_irqrestore(a1 + 969, v133);
    }
    else
    {
      raw_spin_unlock_irqrestore(a1 + 969, v69);
    }
  }
  else
  {
LABEL_218:
    _drm_err("no mixers for this crtc\n");
  }
  v78 = *((unsigned __int8 *)a1 + 7764);
  *((_BYTE *)a1 + 7764) = 0;
  v79 = (_QWORD *)a1[569];
  LODWORD(v133) = v78;
  if ( v79 != a1 + 569 )
  {
    LOBYTE(v1) = 0;
    v134 = 0;
    while ( 1 )
    {
      v80 = *((_DWORD *)v79 - 16);
      v81 = (_QWORD *)*v79;
      if ( (v80 & 0xFFFFFFFE) == 0x26 )
      {
        if ( demura_sw_fuse_value == 1 )
          goto LABEL_230;
      }
      else if ( demura_sw_fuse_value == 1 || v80 != 41 )
      {
LABEL_230:
        sde_cp_crtc_commit_feature(v79 - 9, a1);
        sde_cp_dspp_flush_helper(a1, *((unsigned int *)v79 - 16));
        if ( *((_BYTE *)v79 + 16) == 1 && *((_BYTE *)v79 + 17) != 1 )
          v134 = 1;
        else
          LOBYTE(v1) = 1;
        goto LABEL_224;
      }
      _drm_dev_dbg(0, 0, 1, "demura_sw_fuse is not enabled: 0x%x\n", demura_sw_fuse_value);
LABEL_224:
      v79 = v81;
      if ( v81 == a1 + 569 )
        goto LABEL_238;
    }
  }
  if ( (_QWORD *)a1[571] != a1 + 571 || (_QWORD *)a1[573] != a1 + 573 || (_QWORD *)a1[567] != a1 + 567 )
  {
    LOBYTE(v1) = 0;
    v134 = 0;
LABEL_238:
    v82 = a1[251];
    v161 = 0;
    v162 = 0;
    v159 = 0;
    v160 = 0;
    v157 = 0;
    v158 = 0;
    v155 = 0;
    v156 = 0;
    v153 = 0;
    v154 = 0;
    v151 = 0;
    v152 = 0;
    v149 = 0;
    v150 = 0;
    v147 = 0;
    v148 = 0;
    v145 = 0;
    v146 = 0;
    v143 = 0;
    v144 = 0;
    v141 = 0;
    v142 = 0;
    v139 = 0;
    v140 = 0;
    v137 = nullptr;
    v138 = 0;
    v135 = 0;
    v136 = 0;
    if ( !v82 )
    {
      _drm_err("invalid sde_crtc_state %pK\n", nullptr);
LABEL_306:
      _drm_err("failed to set pu features, skip cp updates\n");
      goto LABEL_307;
    }
    v83 = *((_DWORD *)a1 + 548);
    if ( !v83 )
      goto LABEL_243;
    if ( a1[275] )
    {
      if ( !a1[276] )
      {
        v107 = 0;
        goto LABEL_305;
      }
      if ( v83 == 1 )
        goto LABEL_243;
      if ( a1[281] )
      {
        if ( !a1[282] )
        {
          v107 = 1;
          goto LABEL_305;
        }
        if ( v83 == 2 )
          goto LABEL_243;
        if ( a1[287] )
        {
          if ( !a1[288] )
          {
            v107 = 2;
            goto LABEL_305;
          }
          if ( v83 == 3 )
            goto LABEL_243;
          if ( a1[293] )
          {
            if ( !a1[294] )
            {
              v107 = 3;
              goto LABEL_305;
            }
            if ( v83 == 4 )
              goto LABEL_243;
            if ( a1[299] )
            {
              if ( !a1[300] )
              {
                v107 = 4;
                goto LABEL_305;
              }
              if ( v83 == 5 )
                goto LABEL_243;
              if ( a1[305] )
              {
                if ( !a1[306] )
                {
                  v107 = 5;
                  goto LABEL_305;
                }
                if ( v83 == 6 )
                  goto LABEL_243;
                if ( a1[311] )
                {
                  if ( a1[312] )
                  {
                    if ( v83 == 7 )
                      goto LABEL_243;
                    if ( a1[317] )
                    {
                      if ( a1[318] )
                      {
                        if ( v83 != 8 )
                          goto LABEL_330;
LABEL_243:
                        v84 = (_DWORD *)(v82 + 620);
                        v85 = v82 + 692;
                        if ( *(_DWORD *)(v82 + 620) )
                        {
                          sde_kms_rect_merge_rectangles((unsigned int *)(v82 + 620), (__int64)&v136);
                          sde_kms_rect_merge_rectangles((unsigned int *)v85, (__int64)&v135);
                          if ( (unsigned __int16)v136 == (unsigned __int16)v135
                            && WORD1(v136) == WORD1(v135)
                            && WORD2(v136) == WORD2(v135)
                            && HIWORD(v136) == HIWORD(v135) )
                          {
                            _drm_dev_dbg(0, 0, 1, "no change in list of ROIs\n");
                          }
                        }
                        else
                        {
                          _drm_dev_dbg(0, 0, 1, "no partial update required\n");
                          *(_QWORD *)(v85 + 56) = 0;
                          *(_QWORD *)(v85 + 64) = 0;
                          *(_QWORD *)(v85 + 40) = 0;
                          *(_QWORD *)(v85 + 48) = 0;
                          *(_QWORD *)(v85 + 24) = 0;
                          *(_QWORD *)(v85 + 32) = 0;
                          *(_QWORD *)(v85 + 8) = 0;
                          *(_QWORD *)(v85 + 16) = 0;
                          *(_QWORD *)v85 = 0;
                        }
                        v87 = *((_DWORD *)a1 + 548);
                        v132 = (_QWORD *)v85;
                        v88 = *(_QWORD *)(*(_QWORD *)(*a1 + 56LL) + 8LL);
                        v138 = 0;
                        v139 = 0;
                        v140 = 0;
                        v141 = 0;
                        v89 = *(_QWORD *)(v88 + 152);
                        v142 = 0;
                        v143 = 0;
                        v144 = 0;
                        v145 = 0;
                        v146 = 0;
                        v147 = 0;
                        v148 = 0;
                        v149 = 0;
                        v150 = 0;
                        v151 = 0;
                        v152 = 0;
                        v153 = 0;
                        v154 = 0;
                        v155 = 0;
                        v156 = 0;
                        v157 = 0;
                        v158 = 0;
                        v159 = 0;
                        v160 = 0;
                        v161 = 0;
                        v162 = 0;
                        if ( v87 )
                        {
                          if ( (unsigned int)(v87 - 9) < 0xFFFFFFF8 )
                            goto LABEL_330;
                          v90 = a1[277] != 0;
                          if ( v87 != 1 )
                          {
                            if ( a1[283] )
                              ++v90;
                            if ( v87 != 2 )
                            {
                              if ( a1[289] )
                                ++v90;
                              if ( v87 != 3 )
                              {
                                if ( a1[295] )
                                  ++v90;
                                if ( v87 != 4 )
                                {
                                  if ( a1[301] )
                                    ++v90;
                                  if ( v87 != 5 )
                                  {
                                    if ( a1[307] )
                                      ++v90;
                                    if ( v87 != 6 )
                                    {
                                      if ( a1[313] )
                                        ++v90;
                                      if ( v87 != 7 && a1[319] )
                                        ++v90;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        else
                        {
                          v90 = 0;
                        }
                        HIDWORD(v140) = v90;
                        v129 = v84;
                        v91 = *(_DWORD *)(v89 + 19940) == 0;
                        v92 = a1[251];
                        v93 = !v91;
                        LOBYTE(v148) = v93;
                        v94 = *v84;
                        HIDWORD(v148) = *(unsigned __int16 *)(v92 + 38);
                        if ( v94 )
                          v95 = v84;
                        else
                          v95 = nullptr;
                        v96 = *(unsigned __int16 *)(v92 + 28);
                        v137 = v95;
                        LODWORD(v138) = 72;
                        LODWORD(v149) = v96;
                        if ( v90 )
                        {
                          v143 = a1[277];
                          if ( v90 != 1 )
                          {
                            v144 = a1[283];
                            if ( v90 != 2 )
                            {
                              v145 = a1[289];
                              if ( v90 != 3 )
                              {
                                v146 = a1[295];
                                if ( v90 != 4 )
                                {
                                  v147 = a1[301];
                                  if ( v90 != 5 )
                                    goto LABEL_330;
                                }
                              }
                            }
                          }
                        }
                        LOBYTE(v2) = 0;
                        v97 = 0;
                        while ( 1 )
                        {
                          v98 = (_DWORD *)set_crtc_pu_feature_wrappers[v97];
                          if ( v98 )
                          {
                            if ( (((unsigned __int64)*((unsigned int *)a1 + 1897) >> v97) & 1) != 0 )
                            {
                              sde_evtlog_log(
                                sde_dbg_base_evtlog,
                                "_sde_cp_crtc_update_pu_features",
                                2168,
                                -1,
                                v97,
                                v149,
                                SHIDWORD(v148),
                                -1059143953,
                                v127);
                              v99 = HIDWORD(v140);
                              if ( HIDWORD(v140) )
                                break;
                            }
                          }
LABEL_291:
                          if ( ++v97 == 3 )
                          {
                            while ( 1 )
                            {
                              v108 = v129[6];
                              v109 = v129[7];
                              v132[8] = v129[8];
                              v132[6] = v108;
                              v132[7] = v109;
                              v110 = v129[3];
                              v132[2] = v129[2];
                              v132[3] = v110;
                              v111 = v129[5];
                              v132[4] = v129[4];
                              v132[5] = v111;
                              v112 = v129[1];
                              *v132 = *v129;
                              v132[1] = v112;
                              sde_cp_dspp_flush_helper(a1, 33);
                              if ( (_QWORD *)a1[573] == a1 + 573 )
                              {
                                v113 = v2 | v134;
                              }
                              else
                              {
                                sde_cp_ad_set_prop(a1, 11);
                                v113 = 1;
                              }
                              v114 = (_QWORD *)a1[571];
                              if ( v114 != a1 + 571 )
                              {
                                do
                                {
                                  v115 = (_QWORD *)*v114;
                                  sde_cp_crtc_commit_feature(v114 - 9, a1);
                                  v114 = v115;
                                }
                                while ( v115 != a1 + 571 );
                                v113 = 1;
                              }
                              v116 = v130;
                              LOBYTE(v1) = v2 | v1;
                              LOBYTE(v2) = v131;
                              v117 = 0;
                              if ( v130 <= 1 )
                                v116 = 1;
                              v118 = 48LL * v116;
                              while ( v117 != 384 )
                              {
                                v119 = a1[v117 / 8 + 276];
                                if ( v119 )
                                {
                                  if ( (v113 & 1) != 0 )
                                  {
                                    if ( v131 > 2 )
                                      break;
                                    v120 = *(void (__fastcall **)(__int64, __int64, __int64))(v119 + 8LL * v131 + 1096);
                                    if ( v120 )
                                    {
                                      v121 = a1[v117 / 8 + 277];
                                      if ( v121 )
                                      {
                                        v122 = *(unsigned int *)(v121 + 64);
                                        v123 = a1[v117 / 8 + 276];
                                        if ( *((_DWORD *)v120 - 1) != -365933170 )
                                          __break(0x8228u);
                                        v120(v123, v122, 1);
                                      }
                                    }
                                  }
                                  if ( (v1 & 1) != 0 )
                                  {
                                    if ( v131 > 2 )
                                      break;
                                    v124 = *(void (__fastcall **)(__int64, __int64, __int64))(v119 + 8LL * v131 + 1072);
                                    if ( v124 )
                                    {
                                      v125 = a1[v117 / 8 + 275];
                                      if ( v125 )
                                      {
                                        v126 = *(unsigned int *)(v125 + 32);
                                        if ( *((_DWORD *)v124 - 1) != -1730422967 )
                                          __break(0x8228u);
                                        v124(v119, v126, 1);
                                      }
                                    }
                                  }
                                }
                                v117 += 48LL;
                                if ( v118 == v117 )
                                  goto LABEL_307;
                              }
LABEL_330:
                              __break(0x5512u);
                            }
                          }
                        }
                        v100 = 0;
                        v101 = a1 + 277;
                        while ( 1 )
                        {
                          if ( v100 == 8 )
                            goto LABEL_330;
                          v102 = *(v101 - 2);
                          v103 = *(v101 - 1);
                          v104 = *v101;
                          v105 = *(_DWORD *)(v102 + 376);
                          v141 = v102;
                          LODWORD(v102) = *(_DWORD *)(v102 + 380);
                          v139 = v103;
                          LODWORD(v142) = v102;
                          HIDWORD(v142) = v105 * v99;
                          if ( *(v98 - 1) != -1802519210 )
                            __break(0x8235u);
                          v106 = ((__int64 (__fastcall *)(__int64, _DWORD **, _QWORD *))v98)(v104, &v137, a1);
                          if ( v106 < 0 )
                            break;
                          if ( !v106 )
                          {
                            sde_cp_dspp_flush_helper(a1, sde_cp_crtc_pu_to_feature[v97]);
                            LOBYTE(v2) = 1;
                          }
                          v99 = HIDWORD(v140);
                          ++v100;
                          v101 += 6;
                          if ( v100 >= HIDWORD(v140) )
                            goto LABEL_291;
                        }
                        _drm_err("failed pu feature %d in mixer %d\n", v97, v100);
                        goto LABEL_306;
                      }
                      v107 = 7;
                      goto LABEL_305;
                    }
                    v86 = 7;
                    goto LABEL_251;
                  }
                  v107 = 6;
LABEL_305:
                  _drm_err("invalid ctl in mixer %d\n", v107);
                  goto LABEL_306;
                }
                v86 = 6;
              }
              else
              {
                v86 = 5;
              }
            }
            else
            {
              v86 = 4;
            }
          }
          else
          {
            v86 = 3;
          }
        }
        else
        {
          v86 = 2;
        }
      }
      else
      {
        v86 = 1;
      }
    }
    else
    {
      v86 = 0;
    }
LABEL_251:
    _drm_err("invalid lm in mixer %d\n", v86);
    goto LABEL_306;
  }
  _drm_dev_dbg(0, 0, 1, "all lists are empty\n");
LABEL_307:
  result = mutex_unlock(a1 + 583);
  if ( (_DWORD)v133 )
    result = sde_cp_disable_features(a1);
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
