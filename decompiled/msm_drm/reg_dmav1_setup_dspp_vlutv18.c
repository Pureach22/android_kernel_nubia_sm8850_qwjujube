unsigned __int64 __fastcall reg_dmav1_setup_dspp_vlutv18(unsigned int *a1, _QWORD **a2)
{
  unsigned int *v2; // x20
  __int64 v3; // x8
  unsigned int v4; // w4
  unsigned __int64 result; // x0
  _QWORD *v7; // x19
  unsigned __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x9
  unsigned __int64 *v11; // x8
  void (__fastcall *v12)(_QWORD); // x9
  unsigned __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 (__fastcall *v16)(_QWORD); // x8
  int v17; // w0
  _QWORD *v18; // x10
  int v19; // w1
  _DWORD *v20; // x22
  __int64 v21; // x26
  __int64 v22; // x8
  _DWORD *v23; // x9
  __int64 v24; // x10
  int v25; // w11
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 (__fastcall *v28)(_QWORD); // x9
  unsigned int v29; // w0
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 (__fastcall *v32)(_QWORD); // x9
  unsigned int v33; // w0
  __int64 v34; // x4
  _QWORD *v35; // x8
  __int64 v36; // x5
  _QWORD *v37; // x10
  int v38; // w6
  int v39; // w8
  __int64 v40; // x10
  unsigned __int64 v41; // x8
  unsigned int v42; // w9
  __int64 v43; // x8
  _DWORD *v44; // x8
  __int64 v45; // x1
  unsigned int v46; // w0
  __int64 v47; // x8
  _DWORD *v48; // x8
  __int64 v49; // x1
  __int64 v50; // x8
  _DWORD *v51; // x8
  __int64 v52; // x1
  __int64 v53; // x8
  _DWORD *v54; // x8
  __int64 v55; // x1
  __int64 v56; // x8
  _DWORD *v57; // x8
  __int64 v58; // x1
  __int64 v59; // x8
  _DWORD *v60; // x8
  __int64 v61; // x1
  __int64 v62; // x8
  __int64 v63; // x8
  __int64 (__fastcall *v64)(_QWORD); // x8
  unsigned int v65; // w0
  __int64 v66; // x8
  __int64 v67; // x8
  __int64 (__fastcall *v68)(_QWORD); // x8
  int v69; // w8
  _QWORD *v70; // x9
  int v71; // w8
  __int64 v72; // x4
  __int64 v73; // x5
  _QWORD *v74; // x11
  int v75; // w6
  unsigned int v76; // w10
  unsigned __int64 v77; // x9
  __int64 v78; // x8
  _DWORD *v79; // x8
  __int64 v80; // x1
  unsigned int v81; // w0
  unsigned __int64 StatusReg; // x26
  __int64 v83; // x27
  int v84; // [xsp+Ch] [xbp-D4h] BYREF
  unsigned int v85; // [xsp+10h] [xbp-D0h] BYREF
  int v86; // [xsp+14h] [xbp-CCh] BYREF
  _QWORD *v87; // [xsp+18h] [xbp-C8h] BYREF
  __int64 v88; // [xsp+20h] [xbp-C0h]
  unsigned __int64 v89; // [xsp+28h] [xbp-B8h]
  __int64 v90; // [xsp+30h] [xbp-B0h]
  __int64 v91; // [xsp+38h] [xbp-A8h]
  __int64 v92; // [xsp+40h] [xbp-A0h]
  _QWORD *v93; // [xsp+48h] [xbp-98h]
  __int128 v94; // [xsp+50h] [xbp-90h]
  unsigned __int64 v95; // [xsp+60h] [xbp-80h]
  __int64 v96; // [xsp+68h] [xbp-78h] BYREF
  __int128 v97; // [xsp+70h] [xbp-70h]
  unsigned __int64 v98; // [xsp+80h] [xbp-60h]
  int *v99; // [xsp+88h] [xbp-58h]
  __int64 v100; // [xsp+90h] [xbp-50h]
  __int64 v101; // [xsp+98h] [xbp-48h]
  __int64 v102; // [xsp+A0h] [xbp-40h]
  unsigned int *dest; // [xsp+A8h] [xbp-38h] BYREF
  __int64 v104; // [xsp+B0h] [xbp-30h]
  __int64 v105; // [xsp+B8h] [xbp-28h]
  __int64 v106; // [xsp+C0h] [xbp-20h]
  __int64 v107; // [xsp+C8h] [xbp-18h]
  __int64 v108; // [xsp+D0h] [xbp-10h]

  v2 = a1;
  v108 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = nullptr;
  v97 = 0u;
  v95 = 0;
  v96 = 0;
  v94 = 0u;
  v92 = 0;
  v93 = nullptr;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v87 = nullptr;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  dest = nullptr;
  v86 = 0;
  v84 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
    goto LABEL_89;
  }
  v3 = a1[16];
  v4 = a1[374];
  if ( !a2[2] || (unsigned int)v3 > 4 || v4 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", a2[2], v3, 4, v4);
    goto LABEL_89;
  }
  if ( &dspp_buf[2 * v3] == (unsigned __int64 *)-320LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_89;
  }
  v85 = 0;
  result = reg_dmav1_get_dspp_blk(a2, (unsigned int)v3, &v84, &v85);
  if ( (_DWORD)result != -114 )
  {
    if ( (_DWORD)result == -22 )
    {
      result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
      goto LABEL_89;
    }
    if ( v85 >= 6 )
    {
      result = _drm_err("unable to process more than %d DSPP blocks\n", 5);
      goto LABEL_89;
    }
    if ( v85 < 2 )
      dest = v2;
    else
      memcpy(&dest, a2 + 6, 8LL * v85);
    v7 = a2[2];
    result = sde_reg_dma_get_ops(v2[374]);
    if ( result )
    {
      v8 = result;
      if ( result <= 0xFFFFFFFFFFFFF000LL )
      {
        v9 = v2[16];
        if ( (unsigned int)v9 > 4 )
          goto LABEL_99;
        v10 = v2[374];
        if ( (unsigned int)v10 > 1 )
          goto LABEL_99;
        if ( (unsigned __int64)(16 * v9 + 8 * v10 + 320) > 0x7D0 )
          goto LABEL_100;
        v11 = &dspp_buf[2 * v9 + v10];
        v12 = *(void (__fastcall **)(_QWORD))(result + 64);
        v13 = v11[40];
        if ( *((_DWORD *)v12 - 1) != -870478129 )
          __break(0x8229u);
        v12(v13);
        v14 = v2[16];
        LODWORD(v96) = 0;
        v98 = 0;
        v99 = nullptr;
        v100 = 0;
        v101 = 0;
        v102 = 0;
        HIDWORD(v96) = v84;
        v97 = 4u;
        if ( (unsigned int)v14 > 4 )
          goto LABEL_99;
        v15 = v2[374];
        if ( (unsigned int)v15 > 1 )
          goto LABEL_99;
        if ( (unsigned __int64)(16 * v14 + 8 * v15 + 320) > 0x7D0 )
          goto LABEL_100;
        HIDWORD(v97) = 0;
        DWORD1(v97) = 0;
        v100 = 0;
        v98 = dspp_buf[2 * v14 + 40 + v15];
        v99 = nullptr;
        v16 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
        if ( *((_DWORD *)v16 - 1) != -1839634494 )
          __break(0x8228u);
        v17 = v16(&v96);
        if ( v17 )
        {
          result = _drm_err("write decode select failed ret %d\n", v17);
          goto LABEL_89;
        }
        v18 = *a2;
        *((_DWORD *)a2 + 40) = (_DWORD)a2[20] & 0xFF0F0FFF | 0x801000;
        *((_DWORD *)a2 + 42) = 2;
        if ( v18 )
        {
          v19 = *((_DWORD *)a2 + 2);
          if ( v19 != 1032 )
          {
            result = _drm_err("invalid size of payload len %d exp %zd\n", v19, 0x408u);
            goto LABEL_89;
          }
          result = _kvmalloc_node_noprof(512, 0, 3520, 0xFFFFFFFFLL);
          v20 = (_DWORD *)result;
          if ( result )
          {
            while ( 1 )
            {
              v21 = (__int64)*a2;
              _drm_dev_dbg(0, 0, 1, "Enable vlut feature flags %llx\n", **a2);
              v22 = 0;
              v23 = v20;
              v86 = 0;
              do
              {
                v24 = v21 + 4 * v22;
                v22 += 2;
                v25 = *(_DWORD *)(v24 + 8);
                LODWORD(v24) = *(_DWORD *)(v24 + 12);
                v86 = v22;
                *v23++ = v25 & 0x3FF | ((v24 & 0x3FF) << 16);
              }
              while ( v22 != 256 );
              v26 = *((_QWORD *)v2 + 9);
              v99 = v20;
              *(_QWORD *)((char *)&v97 + 4) = 0;
              v27 = *(_QWORD *)(v26 + 48);
              v100 = 0x20000000000LL;
              HIDWORD(v97) = *(_DWORD *)(v27 + 488);
              v28 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
              LODWORD(v96) = 2;
              if ( *((_DWORD *)v28 - 1) != -1839634494 )
                __break(0x8229u);
              v29 = v28(&v96);
              if ( v29 )
              {
                _drm_err("write pa vlut failed ret %d\n", v29);
                goto LABEL_88;
              }
              v62 = *((_QWORD *)v2 + 9);
              *(_QWORD *)((char *)&v97 + 4) = 0;
              v63 = *(_QWORD *)(v62 + 48);
              v99 = &v86;
              v100 = 0x400000000LL;
              LODWORD(v63) = *(_DWORD *)(v63 + 308);
              v86 = 1;
              LODWORD(v96) = 1;
              HIDWORD(v97) = v63 + 76;
              v64 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
              if ( *((_DWORD *)v64 - 1) != -1839634494 )
                __break(0x8228u);
              v65 = v64(&v96);
              if ( v65 )
                goto LABEL_87;
              v66 = *((_QWORD *)v2 + 9);
              v99 = &v86;
              *(_QWORD *)((char *)&v97 + 4) = 0;
              v67 = *(_QWORD *)(v66 + 48);
              v100 = 0x400000000LL;
              LODWORD(v96) = 1;
              HIDWORD(v97) = *(_DWORD *)(v67 + 308) + 24;
              v68 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
              if ( *((_DWORD *)v68 - 1) != -1839634494 )
                __break(0x8228u);
              v65 = v68(&v96);
              if ( v65 )
              {
LABEL_87:
                _drm_err("opmode write single reg failed ret %d\n", v65);
                goto LABEL_88;
              }
              v69 = *((_DWORD *)a2 + 42);
              v70 = a2[2];
              v89 = 0;
              v90 = 0;
              v91 = 0;
              v92 = 0;
              v71 = v69 | 1;
              v87 = v70;
              v88 = 0;
              *((_DWORD *)a2 + 42) = v71;
              v72 = v2[16];
              v93 = nullptr;
              v94 = 0u;
              v95 = 0;
              if ( (unsigned int)v72 > 4 )
                goto LABEL_99;
              v73 = v2[374];
              if ( (unsigned int)v73 > 1 )
                goto LABEL_99;
              if ( (unsigned __int64)(16 * v72 + 8 * v73 + 320) <= 0x7D0 )
                break;
LABEL_100:
              __break(1u);
              StatusReg = _ReadStatusReg(SP_EL0);
              v83 = *(_QWORD *)(StatusReg + 80);
              *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_dspp_vlutv18__alloc_tag;
              result = _kvmalloc_node_noprof(512, 0, 3520, 0xFFFFFFFFLL);
              v20 = (_DWORD *)result;
              *(_QWORD *)(StatusReg + 80) = v83;
              if ( !result )
                goto LABEL_89;
            }
            v74 = a2[19];
            LODWORD(v88) = 1;
            v75 = v2[7];
            LODWORD(v92) = 4;
            v93 = v74;
            v76 = *((_DWORD *)a2 + 40);
            LODWORD(v74) = *((_DWORD *)a2 + 41);
            v77 = dspp_buf[2 * v72 + 40 + v73];
            LODWORD(v91) = 0;
            *(_QWORD *)&v94 = __PAIR64__((unsigned int)v74, v76);
            v89 = v77;
            LODWORD(v77) = *((_DWORD *)a2 + 44);
            LODWORD(v95) = *((_DWORD *)a2 + 43);
            HIDWORD(v95) = v77;
            *((_QWORD *)&v94 + 1) = __PAIR64__(*((_DWORD *)a2 + 7), v71);
            sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dspp_vlutv18", 855, -1, v72, v73, v75, 1, 239);
            v78 = v2[7];
            if ( (unsigned int)v78 <= 2 )
            {
              v79 = *(_DWORD **)(v8 + 8 * v78 + 16);
              if ( v79 )
              {
                v80 = v2[374];
                if ( *(v79 - 1) != 1772228465 )
                  __break(0x8228u);
                v81 = ((__int64 (__fastcall *)(_QWORD **, __int64))v79)(&v87, v80);
                if ( v81 )
                {
                  _drm_err("failed to kick off ret %d\n", v81);
                  goto LABEL_88;
                }
              }
LABEL_57:
              result = kvfree(v20);
              if ( !v7 )
                goto LABEL_89;
              v47 = *((unsigned int *)v7 + 7);
              if ( (unsigned int)v47 <= 2 )
              {
                v8 = (unsigned __int64)(v7 + 140);
                v48 = (_DWORD *)v7[v47 + 140];
                if ( !v48 )
                  goto LABEL_89;
                v2 = (unsigned int *)v85;
                if ( !v85 )
                  goto LABEL_89;
                v49 = dest[16];
                if ( *(v48 - 1) != -365933170 )
                  __break(0x8228u);
                result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v48)(v7, v49, 1);
                if ( (_DWORD)v2 == 1 )
                  goto LABEL_89;
                v50 = *((unsigned int *)v7 + 7);
                if ( (unsigned int)v50 <= 2 )
                {
                  v51 = *(_DWORD **)(v8 + 8 * v50);
                  v52 = *(unsigned int *)(v104 + 64);
                  if ( *(v51 - 1) != -365933170 )
                    __break(0x8228u);
                  result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v51)(v7, v52, 1);
                  if ( (_DWORD)v2 == 2 )
                    goto LABEL_89;
                  v53 = *((unsigned int *)v7 + 7);
                  if ( (unsigned int)v53 <= 2 )
                  {
                    v54 = *(_DWORD **)(v8 + 8 * v53);
                    v55 = *(unsigned int *)(v105 + 64);
                    if ( *(v54 - 1) != -365933170 )
                      __break(0x8228u);
                    result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v54)(v7, v55, 1);
                    if ( (_DWORD)v2 == 3 )
                      goto LABEL_89;
                    v56 = *((unsigned int *)v7 + 7);
                    if ( (unsigned int)v56 <= 2 )
                    {
                      v57 = *(_DWORD **)(v8 + 8 * v56);
                      v58 = *(unsigned int *)(v106 + 64);
                      if ( *(v57 - 1) != -365933170 )
                        __break(0x8228u);
                      result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v57)(v7, v58, 1);
                      if ( (_DWORD)v2 == 4 )
                        goto LABEL_89;
                      v59 = *((unsigned int *)v7 + 7);
                      if ( (unsigned int)v59 <= 2 )
                      {
                        v60 = *(_DWORD **)(v8 + 8 * v59);
                        v61 = *(unsigned int *)(v107 + 64);
                        if ( *(v60 - 1) != -365933170 )
                          __break(0x8228u);
                        result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v60)(v7, v61, 1);
                        if ( (_DWORD)v2 == 5 )
                          goto LABEL_89;
                      }
                    }
                  }
                }
              }
            }
LABEL_99:
            __break(0x5512u);
            goto LABEL_100;
          }
        }
        else
        {
          v30 = *((_QWORD *)v2 + 9);
          *(_QWORD *)((char *)&v97 + 4) = 0;
          v99 = &v86;
          v31 = *(_QWORD *)(v30 + 48);
          v100 = 0x400000000LL;
          v86 = 0;
          HIDWORD(v97) = *(_DWORD *)(v31 + 308) + 76;
          v32 = *(__int64 (__fastcall **)(_QWORD))(v8 + 8);
          LODWORD(v96) = 1;
          if ( *((_DWORD *)v32 - 1) != -1839634494 )
            __break(0x8229u);
          v33 = v32(&v96);
          if ( v33 )
          {
            _drm_err("opmode write single reg failed ret %d\n", v33);
          }
          else
          {
            v34 = v2[16];
            v35 = a2[2];
            v95 = 0;
            v93 = nullptr;
            v94 = 0u;
            v91 = 0;
            v92 = 0;
            v89 = 0;
            v90 = 0;
            v87 = v35;
            v88 = 0;
            if ( (unsigned int)v34 > 4 )
              goto LABEL_99;
            v36 = v2[374];
            if ( (unsigned int)v36 > 1 )
              goto LABEL_99;
            if ( (unsigned __int64)(16 * v34 + 8 * v36 + 320) > 0x7D0 )
              goto LABEL_100;
            v37 = a2[19];
            LODWORD(v88) = 1;
            v38 = v2[7];
            LODWORD(v92) = 4;
            v39 = *((_DWORD *)a2 + 40);
            v93 = v37;
            v40 = *(__int64 *)((char *)a2 + 164);
            LODWORD(v94) = v39;
            v41 = dspp_buf[2 * v34 + 40 + v36];
            *(_QWORD *)((char *)&v94 + 4) = v40;
            LODWORD(v40) = *((_DWORD *)a2 + 43);
            v42 = *((_DWORD *)a2 + 44);
            v89 = v41;
            LODWORD(v41) = *((_DWORD *)a2 + 7);
            LODWORD(v91) = 0;
            v95 = __PAIR64__(v42, v40);
            HIDWORD(v94) = v41;
            sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dspp_vlutv18", 797, -1, v34, v36, v38, 0, 239);
            v43 = v2[7];
            if ( (unsigned int)v43 > 2 )
              goto LABEL_99;
            v44 = *(_DWORD **)(v8 + 8 * v43 + 16);
            if ( !v44 )
              goto LABEL_56;
            v45 = v2[374];
            if ( *(v44 - 1) != 1772228465 )
              __break(0x8228u);
            v46 = ((__int64 (__fastcall *)(_QWORD **, __int64))v44)(&v87, v45);
            if ( !v46 )
            {
LABEL_56:
              v20 = nullptr;
              goto LABEL_57;
            }
            _drm_err("failed to kick off ret %d\n", v46);
          }
          v20 = nullptr;
LABEL_88:
          result = kvfree(v20);
        }
      }
    }
  }
LABEL_89:
  _ReadStatusReg(SP_EL0);
  return result;
}
