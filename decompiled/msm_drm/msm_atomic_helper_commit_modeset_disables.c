void __fastcall msm_atomic_helper_commit_modeset_disables(__int64 a1, __int64 a2)
{
  __int64 v4; // x25
  __int64 v5; // x26
  void (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x8
  _QWORD *v8; // x20
  __int64 v9; // x24
  __int64 v10; // x8
  __int64 v11; // x23
  __int64 **conn_state; // x0
  __int64 v13; // x23
  __int64 v14; // x10
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 (__fastcall *v19)(_QWORD); // x24
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x28
  long double v23; // q0
  __int64 v24; // x9
  __int64 v25; // x24
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 (*v29)(void); // x8
  __int64 v30; // x0
  void (__fastcall *v31)(__int64, __int64); // x8
  __int64 v32; // x25
  void (__fastcall *v33)(_QWORD); // x8
  __int64 *v34; // x8
  __int64 v35; // x23
  __int64 v36; // x24
  __int64 v37; // x20
  __int64 **v38; // x0
  __int64 v39; // x24
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 (__fastcall *v42)(_QWORD); // x20
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  int v46; // w9
  __int64 v47; // x10
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 (*v51)(void); // x8
  __int64 v52; // x0
  void (__fastcall *v53)(__int64, __int64); // x8
  __int64 v54; // x11
  __int64 v55; // x20
  __int64 v56; // x8
  __int64 v57; // x20
  __int64 v58; // x23
  __int64 v59; // x22
  __int64 v60; // x9
  __int64 v61; // x24
  long double v62; // q0
  void (__fastcall *v63)(_QWORD, long double); // x8
  __int64 v64; // x26
  __int64 v65; // x27
  __int64 v66; // x8
  _QWORD *v67; // x20
  __int64 v68; // x9
  __int64 v69; // x23
  __int64 v70; // x9
  __int64 v71; // x21
  __int64 v72; // x22
  __int64 v73; // x8
  __int64 v74; // x24
  __int64 v75; // x8
  __int64 v76; // x0
  __int64 (__fastcall *v77)(_QWORD); // x8
  char v78; // w25
  __int64 v79; // x10
  __int64 v80; // x0
  __int64 v81; // x8
  __int64 v82; // x11
  int v83; // w8
  __int64 **v84; // x0
  __int64 v85; // x8
  __int64 v86; // x8
  __int64 v87; // x8
  __int64 (*v88)(void); // x8
  __int64 v89; // x0
  __int64 v90; // x8
  __int64 (__fastcall *v91)(_QWORD); // x20
  __int64 v92; // x0
  __int64 v93; // x0
  unsigned int v94; // w8
  long double v95; // q0
  void (__fastcall *v96)(__int64, __int64, __int64, long double); // x8
  __int64 v97; // t1
  __int64 v98; // x9
  __int64 v99; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(int *)(a2 + 40) >= 1 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v7 = *(_QWORD *)(a2 + 48);
      v8 = *(_QWORD **)(v7 + v4);
      if ( v8 )
      {
        v9 = *(_QWORD *)(v7 + v4 + 16);
        v10 = *(_QWORD *)(v9 + 8);
        if ( v10 )
        {
          if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a2 + 32) + 56LL * *(unsigned int *)(v10 + 160) + 16) + 9LL) == 1 )
          {
            v11 = *(_QWORD *)(v10 + 2008);
            conn_state = (__int64 **)msm_get_conn_state(v11);
            if ( (*(_BYTE *)(v11 + 10) & 0xE) != 0 )
              goto LABEL_13;
            if ( conn_state )
            {
              if ( *conn_state )
              {
                v26 = **conn_state;
                if ( v26 )
                {
                  v27 = *(_QWORD *)(v26 + 56);
                  if ( v27 )
                  {
                    v28 = *(_QWORD *)(v27 + 8);
                    if ( v28 )
                    {
                      v29 = *(__int64 (**)(void))(*(_QWORD *)v28 + 80LL);
                      if ( v29 )
                      {
                        if ( *((_DWORD *)v29 - 1) != -1440990782 )
                          __break(0x8228u);
                        v30 = v29();
                        if ( v30 )
                        {
                          if ( (*(_WORD *)(v30 + 8) & 0x1D4) != 0 )
                          {
LABEL_13:
                            v13 = *(_QWORD *)(v9 + 16);
                            if ( v13 )
                            {
                              if ( !v9 )
                                goto LABEL_27;
                              v14 = *(_QWORD *)(v9 + 8);
                              if ( !v14 )
                                goto LABEL_27;
                              v15 = *(_QWORD *)(v14 + 2008);
                              v16 = *(_QWORD *)(*v8 + 56LL);
                              v17 = *(_QWORD *)(v8[314] + 8LL);
                              if ( (*(_BYTE *)(v15 + 10) & 0xE) != 8 || v14 != v17 )
                              {
                                if ( !v17 && (*(_BYTE *)(v15 + 10) & 8) != 0 )
                                  goto LABEL_27;
                                if ( !v16 )
                                  goto LABEL_27;
                                v18 = *(_QWORD *)(v16 + 8);
                                if ( !v18 )
                                  goto LABEL_27;
                                v19 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v18 + 80LL);
                                if ( !v19 )
                                  goto LABEL_27;
                                v20 = msm_get_conn_state(v15);
                                if ( *((_DWORD *)v19 - 1) != -1440990782 )
                                  __break(0x8238u);
                                v21 = v19(v20);
                                if ( !v21 || (*(_BYTE *)(v21 + 8) & 0x3C) == 0 )
                                {
LABEL_27:
                                  v22 = *(_QWORD *)(v13 + 112);
                                  *(double *)&v23 = _drm_dev_dbg(
                                                      0,
                                                      0,
                                                      4,
                                                      "disabling [ENCODER:%d:%s]\n",
                                                      *(_DWORD *)(v13 + 24),
                                                      *(const char **)(v13 + 56));
                                  v24 = *(_QWORD *)(v13 + 88);
                                  if ( v24 == v13 + 88 )
                                    v25 = 0;
                                  else
                                    v25 = v24 - 120;
                                  drm_atomic_bridge_chain_disable(v25, a2, v23);
                                  if ( *(_QWORD *)(v8[314] + 8LL)
                                    && (v6 = *(void (__fastcall **)(_QWORD))(v22 + 24)) != nullptr
                                    || (v6 = *(void (__fastcall **)(_QWORD))(v22 + 80)) != nullptr )
                                  {
                                    if ( *((_DWORD *)v6 - 1) != -781534014 )
                                      __break(0x8228u);
                                    v6(v13);
                                  }
                                  else
                                  {
                                    v31 = *(void (__fastcall **)(__int64, __int64))v22;
                                    if ( *(_DWORD *)(*(_QWORD *)v22 - 4LL) != 677456574 )
                                      __break(0x8228u);
                                    v31(v13, 3);
                                  }
                                  drm_atomic_bridge_chain_post_disable(v25, a2);
                                }
                              }
                            }
                            else
                            {
                              __break(0x800u);
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
        }
      }
      ++v5;
      v4 += 40;
    }
    while ( v5 < *(int *)(a2 + 40) );
  }
  if ( *(int *)(*(_QWORD *)(a2 + 8) + 860LL) >= 1 )
  {
    v32 = 0;
    while ( 1 )
    {
      v34 = (__int64 *)(*(_QWORD *)(a2 + 32) + 56 * v32);
      v35 = *v34;
      if ( !*v34 )
        goto LABEL_54;
      v36 = *(_QWORD *)(v35 + 2008);
      v37 = v34[2];
      v38 = (__int64 **)msm_get_conn_state(v36);
      if ( (*(_BYTE *)(v36 + 10) & 0xE) == 0 )
      {
        if ( !v38 )
          goto LABEL_54;
        if ( !*v38 )
          goto LABEL_54;
        v48 = **v38;
        if ( !v48 )
          goto LABEL_54;
        v49 = *(_QWORD *)(v48 + 56);
        if ( !v49 )
          goto LABEL_54;
        v50 = *(_QWORD *)(v49 + 8);
        if ( !v50 )
          goto LABEL_54;
        v51 = *(__int64 (**)(void))(*(_QWORD *)v50 + 80LL);
        if ( !v51 )
          goto LABEL_54;
        if ( *((_DWORD *)v51 - 1) != -1440990782 )
          __break(0x8228u);
        v52 = v51();
        if ( !v52 || (*(_WORD *)(v52 + 8) & 0x1D4) == 0 )
          goto LABEL_54;
      }
      if ( *(_BYTE *)(v37 + 9) != 1 )
        goto LABEL_54;
      v39 = *(_QWORD *)(v35 + 2008);
      if ( (*(_BYTE *)(v39 + 10) & 4) != 0 )
        goto LABEL_91;
      v40 = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 56LL);
      if ( !v40 )
        goto LABEL_91;
      v41 = *(_QWORD *)(v40 + 8);
      if ( !v41 )
        goto LABEL_91;
      v42 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v41 + 80LL);
      if ( !v42 )
        goto LABEL_91;
      v43 = msm_get_conn_state(*(_QWORD *)(v35 + 2008));
      if ( *((_DWORD *)v42 - 1) != -1440990782 )
        __break(0x8234u);
      v44 = v42(v43);
      if ( !v44 )
        goto LABEL_91;
      if ( (*(_BYTE *)(v44 + 8) & 0xFC) == 0 )
        break;
LABEL_54:
      if ( ++v32 >= *(int *)(*(_QWORD *)(a2 + 8) + 860LL) )
        goto LABEL_94;
    }
    if ( (*(_BYTE *)(v39 + 10) & 0xA) == 8 && *(_BYTE *)(v39 + 9) == 1 )
    {
      v45 = *(unsigned int *)(a2 + 40);
      if ( (int)v45 >= 1 )
      {
        v46 = 0;
        v47 = *(_QWORD *)(a2 + 48) + 16LL;
        do
        {
          v54 = *(_QWORD *)(v47 - 16);
          if ( v54 )
          {
            if ( *(_QWORD *)(*(_QWORD *)v47 + 8LL) == *(_QWORD *)v39
              || *(_QWORD *)(*(_QWORD *)(v54 + 2512) + 8LL) == *(_QWORD *)v39 )
            {
              ++v46;
            }
            if ( v46 > 1 )
              goto LABEL_54;
          }
          --v45;
          v47 += 40;
        }
        while ( v45 );
      }
    }
LABEL_91:
    v55 = *(_QWORD *)(v35 + 448);
    _drm_dev_dbg(0, 0, 4, "disabling [CRTC:%d]\n", *(_DWORD *)(v35 + 112));
    if ( *(_BYTE *)(*(_QWORD *)(v35 + 2008) + 8LL) == 1 && (v33 = *(void (__fastcall **)(_QWORD))(v55 + 8)) != nullptr
      || (v33 = *(void (__fastcall **)(_QWORD))(v55 + 72)) != nullptr )
    {
      if ( *((_DWORD *)v33 - 1) != -1434212794 )
        __break(0x8228u);
      v33(v35);
    }
    else
    {
      v53 = *(void (__fastcall **)(__int64, __int64))v55;
      if ( *(_DWORD *)(*(_QWORD *)v55 - 4LL) != 1188254974 )
        __break(0x8228u);
      v53(v35, 3);
    }
    goto LABEL_54;
  }
LABEL_94:
  drm_atomic_helper_update_legacy_modeset_state(a1, a2);
  v56 = *(_QWORD *)(a2 + 8);
  if ( *(int *)(v56 + 860) >= 1 )
  {
    v57 = 0;
    v58 = 0;
    do
    {
      v59 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + v57);
      if ( v59 )
      {
        v60 = *(_QWORD *)(v59 + 2008);
        if ( (*(_BYTE *)(v60 + 10) & 2) != 0 && *(_BYTE *)(v60 + 8) == 1 )
        {
          v61 = *(_QWORD *)(v59 + 448);
          if ( *(_QWORD *)(v61 + 48) )
          {
            *(double *)&v62 = _drm_dev_dbg(0, 0, 4, "modeset on [CRTC:%d]\n", *(_DWORD *)(v59 + 112));
            v63 = *(void (__fastcall **)(_QWORD, long double))(v61 + 48);
            if ( *((_DWORD *)v63 - 1) != -1434212794 )
              __break(0x8228u);
            v63(v59, v62);
            v56 = *(_QWORD *)(a2 + 8);
          }
        }
      }
      ++v58;
      v57 += 56;
    }
    while ( v58 < *(int *)(v56 + 860) );
  }
  if ( *(int *)(a2 + 40) >= 1 )
  {
    v64 = 0;
    v65 = 0;
    while ( 1 )
    {
      v66 = *(_QWORD *)(a2 + 48);
      v67 = *(_QWORD **)(v66 + v64);
      if ( !v67 )
        goto LABEL_106;
      v68 = v67[314];
      v69 = *(_QWORD *)(v68 + 16);
      if ( !v69 )
        goto LABEL_106;
      v70 = *(_QWORD *)(v68 + 8);
      v71 = *(_QWORD *)(v66 + v64 + 16);
      v72 = *(_QWORD *)(v69 + 112);
      v73 = *(_QWORD *)(*v67 + 56LL);
      v74 = *(_QWORD *)(v70 + 2008);
      if ( v73 && (v75 = *(_QWORD *)(v73 + 8)) != 0 )
      {
        v76 = *(_QWORD *)(v70 + 2008);
        v77 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v75 + 312LL);
        if ( *((_DWORD *)v77 - 1) != -1810138955 )
          __break(0x8228u);
        v78 = v77(v76);
      }
      else
      {
        v78 = 0;
      }
      if ( *(_BYTE *)(v74 + 9) != 1 )
        goto LABEL_106;
      if ( (*(_BYTE *)(v74 + 10) & 0xA) != 8 )
        break;
      if ( !v71 )
        goto LABEL_146;
      v79 = *(_QWORD *)(v71 + 8);
      if ( !v79 )
        goto LABEL_146;
      v80 = *(_QWORD *)(v79 + 2008);
      v81 = *(_QWORD *)(*v67 + 56LL);
      v82 = *(_QWORD *)(v67[314] + 8LL);
      if ( (*(_BYTE *)(v80 + 10) & 0xE) == 8 && v79 == v82 )
        goto LABEL_121;
      if ( !v82 && (*(_BYTE *)(v80 + 10) & 8) != 0 )
        goto LABEL_146;
      if ( !v81 )
        goto LABEL_146;
      v90 = *(_QWORD *)(v81 + 8);
      if ( !v90 )
        goto LABEL_146;
      v91 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v90 + 80LL);
      if ( !v91 )
        goto LABEL_146;
      v92 = msm_get_conn_state(v80);
      if ( *((_DWORD *)v91 - 1) != -1440990782 )
        __break(0x8234u);
      v93 = v91(v92);
      if ( !v93 )
        goto LABEL_146;
      v94 = *(_DWORD *)(v93 + 8);
      if ( (v94 & 0x38) != 0 )
LABEL_121:
        LOBYTE(v83) = 1;
      else
        v83 = (v94 >> 2) & 1;
      if ( v78 & 1 | ((v83 & 1) == 0) )
        goto LABEL_146;
LABEL_106:
      ++v65;
      v64 += 40;
      if ( v65 >= *(int *)(a2 + 40) )
        return;
    }
    if ( (*(_BYTE *)(v74 + 10) & 2) == 0 )
    {
      v84 = (__int64 **)msm_get_conn_state(*(_QWORD *)(*(_QWORD *)(v71 + 8) + 2008LL));
      if ( !v84 )
        goto LABEL_106;
      if ( !*v84 )
        goto LABEL_106;
      v85 = **v84;
      if ( !v85 )
        goto LABEL_106;
      v86 = *(_QWORD *)(v85 + 56);
      if ( !v86 )
        goto LABEL_106;
      v87 = *(_QWORD *)(v86 + 8);
      if ( !v87 )
        goto LABEL_106;
      v88 = *(__int64 (**)(void))(*(_QWORD *)v87 + 80LL);
      if ( !v88 )
        goto LABEL_106;
      if ( *((_DWORD *)v88 - 1) != -1440990782 )
        __break(0x8228u);
      v89 = v88();
      if ( !v89 || (*(_WORD *)(v89 + 8) & 0x1D4) == 0 )
        goto LABEL_106;
    }
LABEL_146:
    *(double *)&v95 = _drm_dev_dbg(
                        0,
                        0,
                        4,
                        "modeset on [ENCODER:%d:%s]\n",
                        *(_DWORD *)(v69 + 24),
                        *(const char **)(v69 + 56));
    v96 = *(void (__fastcall **)(__int64, __int64, __int64, long double))(v72 + 40);
    if ( v96 )
    {
      if ( *((_DWORD *)v96 - 1) != -1627935242 )
        __break(0x8228u);
      v96(v69, v74 + 144, v74 + 24, v95);
    }
    if ( (v78 & 1) == 0 )
    {
      v97 = *(_QWORD *)(v69 + 88);
      v98 = v97 - 120;
      if ( v97 == v69 + 88 )
        v99 = 0;
      else
        v99 = v98;
      drm_bridge_chain_mode_set(v99, v74 + 144, v74 + 24);
    }
    goto LABEL_106;
  }
}
