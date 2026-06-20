__int64 __fastcall sde_cp_crtc_check_properties(_QWORD *a1, unsigned __int16 *a2)
{
  __int64 v2; // x25
  const void *v5; // x2
  __int64 v6; // x8
  __int64 v7; // x22
  int v8; // w8
  int v9; // w6
  int v10; // w5
  _DWORD *v11; // x23
  int v12; // w8
  unsigned __int64 v13; // x21
  unsigned __int16 *v14; // x20
  __int64 *v15; // x24
  __int64 v16; // x10
  __int64 v17; // x0
  _DWORD *v18; // x23
  int v19; // w8
  unsigned __int16 *v20; // x20
  __int64 *v21; // x24
  __int64 v22; // x10
  __int64 v23; // x0
  _DWORD *v24; // x23
  int v25; // w8
  unsigned __int16 *v26; // x20
  __int64 *v27; // x22
  __int64 v28; // x10
  __int64 v29; // x0
  __int64 result; // x0
  unsigned int v31; // w20
  __int64 v32; // x1
  unsigned __int16 *v33; // x23
  unsigned __int64 v34; // x8
  unsigned __int16 *v35; // x24
  __int64 v36; // x21
  int v37; // w0
  int v38; // w20
  _DWORD *v39; // x22
  __int64 v40; // x28
  __int64 v41; // x8
  _DWORD *v42; // x2
  _QWORD *v43; // x3
  int v44; // w9
  unsigned __int64 v45; // x26
  int v46; // w8
  int v47; // w5
  int v48; // w6
  unsigned __int16 *v49; // x20
  __int64 v50; // x24
  char *v51; // x8
  __int64 v52; // x9
  int v53; // w10
  int v54; // w11
  __int64 v55; // x27
  int v56; // w9
  unsigned __int64 v57; // x0
  __int64 v58; // x9
  __int64 v59; // x8
  int v60; // w9
  __int64 v61; // x8
  __int64 v62; // t1
  __int64 v63; // x1
  int v64; // w1
  char v65; // [xsp+0h] [xbp-110h]
  unsigned __int16 *v66; // [xsp+28h] [xbp-E8h]
  __int64 v67; // [xsp+30h] [xbp-E0h] BYREF
  __int64 v68; // [xsp+38h] [xbp-D8h]
  __int64 v69; // [xsp+40h] [xbp-D0h]
  __int64 v70; // [xsp+48h] [xbp-C8h]
  __int64 v71; // [xsp+50h] [xbp-C0h]
  __int64 v72; // [xsp+58h] [xbp-B8h]
  __int64 v73; // [xsp+60h] [xbp-B0h]
  __int64 v74; // [xsp+68h] [xbp-A8h]
  __int64 v75; // [xsp+70h] [xbp-A0h]
  __int64 v76; // [xsp+78h] [xbp-98h]
  __int64 v77; // [xsp+80h] [xbp-90h]
  __int64 v78; // [xsp+88h] [xbp-88h]
  __int64 v79; // [xsp+90h] [xbp-80h]
  __int64 v80; // [xsp+98h] [xbp-78h]
  __int64 v81; // [xsp+A0h] [xbp-70h]
  __int64 v82; // [xsp+A8h] [xbp-68h]
  __int64 v83; // [xsp+B0h] [xbp-60h]
  __int64 v84; // [xsp+B8h] [xbp-58h]
  __int64 v85; // [xsp+C0h] [xbp-50h]
  __int64 v86; // [xsp+C8h] [xbp-48h]
  __int64 v87; // [xsp+D0h] [xbp-40h]
  __int64 v88; // [xsp+D8h] [xbp-38h]
  __int64 v89; // [xsp+E0h] [xbp-30h]
  __int64 v90; // [xsp+E8h] [xbp-28h]
  __int64 v91; // [xsp+F0h] [xbp-20h]
  __int64 v92; // [xsp+F8h] [xbp-18h]
  __int64 v93; // [xsp+100h] [xbp-10h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v5 = (const void *)*a1;
    if ( a2 && v5 )
    {
      v6 = a1[251];
      if ( *(unsigned __int16 *)(v6 + 28) != a2[14] || *(unsigned __int16 *)(v6 + 38) != a2[19] )
        sde_cp_crtc_res_change(a1);
      mutex_lock(a1 + 583);
      v7 = a1[251];
      v91 = 0;
      v92 = 0;
      v89 = 0;
      v90 = 0;
      v87 = 0;
      v88 = 0;
      v85 = 0;
      v86 = 0;
      v83 = 0;
      v84 = 0;
      v81 = 0;
      v82 = 0;
      v79 = 0;
      v80 = 0;
      v77 = 0;
      v78 = 0;
      v75 = 0;
      v76 = 0;
      v73 = 0;
      v74 = 0;
      v71 = 0;
      v72 = 0;
      v69 = 0;
      v70 = 0;
      v67 = 0;
      v68 = 0;
      if ( !v7 )
      {
        _drm_err("invalid sde_crtc_state %pK\n", nullptr);
        v31 = -22;
LABEL_112:
        _drm_err("failed check pu features, ret %d\n", v31);
        goto LABEL_138;
      }
      v8 = *((_DWORD *)a1 + 548);
      v66 = a2;
      if ( !v8 )
      {
LABEL_12:
        if ( !*(_DWORD *)(v7 + 620) )
        {
          _drm_dev_dbg(0, 0, 1, "no partial update required\n");
LABEL_53:
          v33 = v66;
          v34 = *((unsigned int *)v66 + 1152);
          if ( (_DWORD)v34 )
          {
            v35 = v66 + 2932;
            v36 = 0;
            while ( 1 )
            {
              if ( v36 == 52 )
                goto LABEL_134;
              v2 = *(unsigned int *)&v35[2 * v36];
              if ( (unsigned int)v2 >= 0x34 )
                goto LABEL_135;
              v39 = (_DWORD *)check_crtc_feature_wrappers[v2];
              if ( v39 )
                break;
LABEL_59:
              if ( ++v36 >= v34 )
                goto LABEL_108;
            }
            v40 = *((unsigned int *)a1 + 548);
            v41 = (__int64)&v66[12 * (unsigned int)v2 + 2308];
            v67 = 0;
            v68 = 0;
            v69 = 0;
            v70 = 0;
            v71 = 0;
            v72 = 0;
            v42 = *(_DWORD **)v41;
            v43 = *(_QWORD **)(v41 + 16);
            v73 = 0;
            v74 = 0;
            v75 = 0;
            v76 = 0;
            v77 = 0;
            v78 = 0;
            v79 = 0;
            v80 = 0;
            v81 = 0;
            v82 = 0;
            v83 = 0;
            v84 = 0;
            v85 = 0;
            v86 = 0;
            v87 = 0;
            v88 = 0;
            v89 = 0;
            v90 = 0;
            v91 = 0;
            v92 = 0;
            if ( v42 && v43 )
            {
              v44 = v42[12];
              if ( (v44 & 0x10) != 0 )
              {
                v57 = drm_property_lookup_blob(*a1, *(unsigned int *)(v41 + 8));
                v45 = v57;
                if ( v57 )
                {
                  v58 = *(_QWORD *)(v57 + 80);
                  LODWORD(v68) = *(_QWORD *)(v57 + 72);
                  v67 = v58;
                  if ( v57 >= 0xFFFFFFFFFFFFF001LL )
                    goto LABEL_136;
                }
                goto LABEL_71;
              }
              if ( (v44 & 2) != 0 )
              {
                if ( v43[2] )
                {
                  v59 = (__int64)&v66[8 * v2 + 3036];
                  v60 = *(_DWORD *)(v59 + 8);
                  v61 = *(_QWORD *)v59;
                }
                else
                {
                  v62 = *(_QWORD *)(v41 + 8);
                  v61 = v41 + 8;
                  if ( !v62 )
                    goto LABEL_70;
                  v60 = 8;
                }
                LODWORD(v68) = v60;
                v45 = 0;
                v67 = v61;
                goto LABEL_71;
              }
              if ( (v44 & 8) != 0 )
              {
                v45 = 0;
                LODWORD(v68) = 8;
                v67 = v41 + 8;
                goto LABEL_71;
              }
              _drm_err("property type is not supported\n");
            }
            else
            {
              _drm_err("invalid feature:%d, property:%pK, prop_node:%pK\n", v2, v42, v43);
            }
LABEL_70:
            v45 = 0;
LABEL_71:
            v46 = *((_DWORD *)a1 + 548);
            v47 = v33[14];
            v48 = v33[19];
            LODWORD(v70) = 0;
            HIDWORD(v70) = v46;
            HIDWORD(v78) = v48;
            LODWORD(v79) = v47;
            if ( (_DWORD)v40 )
            {
              if ( a1[277] )
                v73 = a1[277];
              if ( (_DWORD)v40 == 1 )
                goto LABEL_87;
              if ( a1[283] )
                v74 = a1[283];
              if ( (_DWORD)v40 == 2 )
                goto LABEL_87;
              if ( a1[289] )
                v75 = a1[289];
              if ( (_DWORD)v40 == 3 )
                goto LABEL_87;
              if ( a1[295] )
                v76 = a1[295];
              if ( (_DWORD)v40 == 4 )
                goto LABEL_87;
              if ( a1[301] )
                v77 = a1[301];
              if ( (unsigned int)(v40 - 5) < 4 )
              {
LABEL_87:
                sde_evtlog_log(
                  sde_dbg_base_evtlog,
                  "_sde_cp_crtc_checkfeature",
                  1653,
                  -1,
                  v2,
                  v47,
                  v48,
                  -1059143953,
                  v65);
                v49 = v66 + 281;
                v50 = 0;
                while ( 1 )
                {
                  if ( v50 == 48 )
                    goto LABEL_134;
                  v51 = (char *)&a1[v50];
                  v52 = a1[v50 + 275];
                  if ( !v52 )
                    break;
                  v53 = *(v49 - 1);
                  v54 = *v49;
                  v71 = a1[v50 + 275];
                  v55 = *((_QWORD *)v51 + 277);
                  LODWORD(v72) = v54;
                  HIDWORD(v72) = v40 * v53;
                  v56 = *(_DWORD *)(v52 + 32);
                  v69 = *((_QWORD *)v51 + 276);
                  _drm_dev_dbg(0, 0, 1, "check cp feature %d on mixer %d\n", v2, v56 - 1);
                  if ( *(v39 - 1) != -1802519210 )
                    __break(0x8236u);
                  v37 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD *))v39)(v55, &v67, a1);
                  if ( v37 )
                    goto LABEL_99;
                  v50 += 6;
                  v49 += 4;
                  if ( 6 * v40 == v50 )
                  {
                    v37 = 0;
                    goto LABEL_99;
                  }
                }
                v37 = -22;
LABEL_99:
                v33 = v66;
                v35 = v66 + 2932;
                if ( v45 )
                  goto LABEL_56;
                goto LABEL_57;
              }
              goto LABEL_134;
            }
            sde_evtlog_log(sde_dbg_base_evtlog, "_sde_cp_crtc_checkfeature", 1653, -1, v2, v47, v48, -1059143953, v65);
            v37 = 0;
            if ( v45 )
            {
LABEL_56:
              v38 = v37;
              drm_property_blob_put(v45);
              v37 = v38;
            }
LABEL_57:
            if ( v37 )
              goto LABEL_137;
            v34 = *((unsigned int *)v33 + 1152);
            goto LABEL_59;
          }
          _drm_dev_dbg(0, 0, 1, "State dirty list is empty\n");
LABEL_108:
          v31 = 0;
LABEL_138:
          mutex_unlock(a1 + 583);
          result = v31;
          goto LABEL_139;
        }
        v91 = 0;
        v92 = 0;
        v89 = 0;
        v90 = 0;
        v87 = 0;
        v88 = 0;
        v85 = 0;
        v86 = 0;
        v83 = 0;
        v84 = 0;
        v81 = 0;
        v82 = 0;
        v79 = 0;
        v80 = 0;
        v77 = 0;
        v78 = 0;
        v75 = 0;
        v76 = 0;
        v73 = 0;
        v74 = 0;
        v71 = 0;
        v72 = 0;
        v9 = *(unsigned __int16 *)(v7 + 38);
        v69 = 0;
        LODWORD(v70) = 0;
        HIDWORD(v70) = v8;
        HIDWORD(v78) = v9;
        v10 = *(unsigned __int16 *)(v7 + 28);
        v67 = v7 + 620;
        v68 = 72;
        LODWORD(v79) = v10;
        if ( !v8
          || (v73 = a1[277], v8 == 1)
          || (v74 = a1[283], v8 == 2)
          || (v75 = a1[289], v8 == 3)
          || (v76 = a1[295], v8 == 4)
          || (v77 = a1[301], v8 == 5) )
        {
          v11 = check_crtc_pu_feature_wrappers;
          if ( check_crtc_pu_feature_wrappers )
          {
            if ( (*((_BYTE *)a1 + 7588) & 1) != 0 )
            {
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "_sde_cp_crtc_check_pu_features",
                2002,
                -1,
                0,
                v10,
                v9,
                -1059143953,
                v65);
              v12 = HIDWORD(v70);
              if ( HIDWORD(v70) )
              {
                v13 = 0;
                v14 = (unsigned __int16 *)(v7 + 562);
                v15 = a1 + 277;
                while ( v13 != 8 )
                {
                  v16 = *(v15 - 1);
                  v17 = *v15;
                  v71 = *(v15 - 2);
                  v69 = v16;
                  HIDWORD(v72) = v12 * *(v14 - 1);
                  LODWORD(v72) = *v14;
                  if ( *(v11 - 1) != -1802519210 )
                    __break(0x8237u);
                  if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD *))v11)(v17, &v67, a1) )
                  {
                    v64 = 0;
LABEL_145:
                    _drm_err("failed pu feature %d in mixer %d\n", v64, v13);
                    v31 = -11;
                    goto LABEL_112;
                  }
                  v12 = HIDWORD(v70);
                  ++v13;
                  v14 += 4;
                  v15 += 6;
                  if ( v13 >= HIDWORD(v70) )
                    goto LABEL_28;
                }
                goto LABEL_134;
              }
            }
          }
LABEL_28:
          v18 = off_293DB8;
          if ( off_293DB8 )
          {
            if ( (*((_BYTE *)a1 + 7588) & 2) != 0 )
            {
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "_sde_cp_crtc_check_pu_features",
                2002,
                -1,
                1,
                v79,
                SHIDWORD(v78),
                -1059143953,
                v65);
              v19 = HIDWORD(v70);
              if ( HIDWORD(v70) )
              {
                v13 = 0;
                v20 = (unsigned __int16 *)(v7 + 562);
                v21 = a1 + 277;
                while ( v13 != 8 )
                {
                  v22 = *(v21 - 1);
                  v23 = *v21;
                  v71 = *(v21 - 2);
                  v69 = v22;
                  HIDWORD(v72) = v19 * *(v20 - 1);
                  LODWORD(v72) = *v20;
                  if ( *(v18 - 1) != -1802519210 )
                    __break(0x8237u);
                  if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD *))v18)(v23, &v67, a1) )
                  {
                    v64 = 1;
                    goto LABEL_145;
                  }
                  v19 = HIDWORD(v70);
                  ++v13;
                  v20 += 4;
                  v21 += 6;
                  if ( v13 >= HIDWORD(v70) )
                    goto LABEL_37;
                }
                goto LABEL_134;
              }
            }
          }
LABEL_37:
          v24 = off_293DC0;
          if ( off_293DC0 )
          {
            if ( (*((_BYTE *)a1 + 7588) & 4) != 0 )
            {
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "_sde_cp_crtc_check_pu_features",
                2002,
                -1,
                2,
                v79,
                SHIDWORD(v78),
                -1059143953,
                v65);
              v25 = HIDWORD(v70);
              if ( HIDWORD(v70) )
              {
                v13 = 0;
                v26 = (unsigned __int16 *)(v7 + 562);
                v27 = a1 + 277;
                while ( v13 != 8 )
                {
                  v28 = *(v27 - 1);
                  v29 = *v27;
                  v71 = *(v27 - 2);
                  v69 = v28;
                  HIDWORD(v72) = v25 * *(v26 - 1);
                  LODWORD(v72) = *v26;
                  if ( *(v24 - 1) != -1802519210 )
                    __break(0x8237u);
                  if ( ((unsigned int (__fastcall *)(__int64, __int64 *, _QWORD *))v24)(v29, &v67, a1) )
                  {
                    v64 = 2;
                    goto LABEL_145;
                  }
                  v25 = HIDWORD(v70);
                  ++v13;
                  v26 += 4;
                  v27 += 6;
                  if ( v13 >= HIDWORD(v70) )
                    goto LABEL_53;
                }
                goto LABEL_134;
              }
            }
          }
          goto LABEL_53;
        }
LABEL_134:
        __break(0x5512u);
LABEL_135:
        _drm_err("invalid feature %d\n", v2);
        LODWORD(v45) = -22;
LABEL_136:
        v37 = v45;
LABEL_137:
        v31 = v37;
        _drm_err("failed check on cp properties\n");
        goto LABEL_138;
      }
      if ( a1[275] )
      {
        if ( a1[276] )
        {
          if ( v8 == 1 )
            goto LABEL_12;
          if ( !a1[281] )
          {
            v32 = 1;
            goto LABEL_51;
          }
          if ( a1[282] )
          {
            if ( v8 == 2 )
              goto LABEL_12;
            if ( !a1[287] )
            {
              v32 = 2;
              goto LABEL_51;
            }
            if ( a1[288] )
            {
              if ( v8 == 3 )
                goto LABEL_12;
              if ( !a1[293] )
              {
                v32 = 3;
                goto LABEL_51;
              }
              if ( a1[294] )
              {
                if ( v8 == 4 )
                  goto LABEL_12;
                if ( !a1[299] )
                {
                  v32 = 4;
                  goto LABEL_51;
                }
                if ( a1[300] )
                {
                  if ( v8 == 5 )
                    goto LABEL_12;
                  if ( !a1[305] )
                  {
                    v32 = 5;
                    goto LABEL_51;
                  }
                  if ( a1[306] )
                  {
                    if ( v8 == 6 )
                      goto LABEL_12;
                    if ( !a1[311] )
                    {
                      v32 = 6;
                      goto LABEL_51;
                    }
                    if ( a1[312] )
                    {
                      if ( v8 == 7 )
                        goto LABEL_12;
                      if ( a1[317] )
                      {
                        if ( a1[318] )
                        {
                          if ( v8 != 8 )
                            goto LABEL_134;
                          goto LABEL_12;
                        }
                        v63 = 7;
                        goto LABEL_110;
                      }
                      v32 = 7;
LABEL_51:
                      _drm_err("invalid lm in mixer %d\n", v32);
LABEL_111:
                      v31 = -22;
                      goto LABEL_112;
                    }
                    v63 = 6;
                  }
                  else
                  {
                    v63 = 5;
                  }
                }
                else
                {
                  v63 = 4;
                }
              }
              else
              {
                v63 = 3;
              }
            }
            else
            {
              v63 = 2;
            }
          }
          else
          {
            v63 = 1;
          }
        }
        else
        {
          v63 = 0;
        }
LABEL_110:
        _drm_err("invalid ctl in mixer %d\n", v63);
        goto LABEL_111;
      }
      v32 = 0;
      goto LABEL_51;
    }
  }
  else
  {
    v5 = nullptr;
  }
  _drm_err("invalid crtc %pK dev %pK state %pK\n", a1, v5, a2);
  result = 4294967274LL;
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return result;
}
