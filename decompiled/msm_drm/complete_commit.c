__int64 __fastcall complete_commit(__int64 a1)
{
  __int64 v3; // x22
  __int64 v4; // x21
  void (__fastcall *v5)(__int64, __int64); // x8
  __int64 *v6; // x24
  __int64 i; // x23
  __int64 *v8; // x8
  __int64 v9; // x26
  __int64 v10; // x27
  __int64 **conn_state; // x0
  __int64 v12; // x28
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 (__fastcall *v15)(_QWORD); // x21
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x10
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 (__fastcall *v24)(_QWORD); // x8
  __int64 v25; // x0
  __int64 v26; // x11
  __int64 v27; // x21
  long double v28; // q0
  void (__fastcall *v29)(__int64, __int64, long double); // x8
  __int64 v30; // x8
  __int64 (__fastcall *v31)(_QWORD); // x21
  __int64 v32; // x0
  __int64 v33; // x0
  void (__fastcall *v34)(_QWORD, long double); // x8
  __int64 v35; // x23
  __int64 v36; // x28
  int v37; // w27
  __int64 v38; // x26
  __int64 v39; // x21
  long double v40; // q0
  __int64 v41; // x9
  __int64 v42; // x0
  void (__fastcall *v43)(_QWORD); // x8
  __int64 v44; // x8
  __int64 v45; // x21
  __int64 v46; // x8
  __int64 v47; // x26
  __int64 **v48; // x0
  int v49; // w8
  __int64 v50; // x8
  __int64 v51; // x8
  __int64 v52; // x8
  __int64 v53; // x8
  __int64 v54; // x8
  __int64 (__fastcall *v55)(_QWORD); // x8
  __int64 v56; // x0
  bool v57; // w21
  long double v58; // q0
  void (__fastcall *v59)(__int64 *, __int64, long double); // x8
  __int64 v60; // x25
  __int64 v61; // x23
  __int64 v62; // x26
  __int64 v63; // x21
  long double v64; // q0
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x27
  __int64 v69; // x8
  __int64 v70; // x25
  __int64 **v71; // x0
  int v72; // w8
  __int64 v73; // x8
  __int64 v74; // x8
  __int64 v75; // x8
  __int64 v76; // x8
  __int64 v77; // x8
  __int64 (__fastcall *v78)(_QWORD); // x8
  __int64 v79; // x0
  __int64 v80; // x8
  __int64 v81; // x21
  __int64 v82; // x24
  __int64 v83; // x23
  __int64 v84; // x9
  void (__fastcall *v85)(_QWORD); // x8
  void (__fastcall *v86)(__int64, __int64); // x8
  int v92; // w8
  int v93; // w20
  int v94; // w22
  __int64 v95; // x21
  double v96; // d0
  int v97; // w9
  __int64 result; // x0
  __int64 v99; // [xsp+8h] [xbp-8h]

  _X20 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(_X20 + 8);
  v4 = *(_QWORD *)(*(_QWORD *)(v3 + 56) + 8LL);
  drm_atomic_helper_wait_for_fences(v3, _X20, 0);
  v99 = v4;
  v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v4 + 56LL);
  if ( *((_DWORD *)v5 - 1) != 1690549992 )
    __break(0x8228u);
  v5(v4, _X20);
  msm_atomic_helper_commit_modeset_disables(v3, _X20);
  drm_atomic_helper_commit_planes(v3, _X20, 1);
  v6 = *(__int64 **)(*(_QWORD *)(v3 + 56) + 8LL);
  _ReadStatusReg(SP_EL0);
  if ( *(int *)(*(_QWORD *)(_X20 + 8) + 860LL) >= 1 )
  {
    for ( i = 0; i < *(int *)(*(_QWORD *)(_X20 + 8) + 860LL); ++i )
    {
      v8 = (__int64 *)(*(_QWORD *)(_X20 + 32) + 56 * i);
      v9 = *v8;
      if ( !*v8 )
        continue;
      v10 = v8[3];
      conn_state = (__int64 **)msm_get_conn_state(v10);
      if ( (*(_BYTE *)(v10 + 10) & 0xE) == 0 )
      {
        if ( !conn_state )
          continue;
        if ( !*conn_state )
          continue;
        v21 = **conn_state;
        if ( !v21 )
          continue;
        v22 = *(_QWORD *)(v21 + 56);
        if ( !v22 )
          continue;
        v23 = *(_QWORD *)(v22 + 8);
        if ( !v23 )
          continue;
        v24 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v23 + 80LL);
        if ( !v24 )
          continue;
        if ( *((_DWORD *)v24 - 1) != -1440990782 )
          __break(0x8228u);
        v25 = v24(conn_state);
        if ( !v25 || (*(_WORD *)(v25 + 8) & 0x1D4) == 0 )
          continue;
      }
      if ( *(_BYTE *)(v10 + 9) != 1 )
        continue;
      v12 = *(_QWORD *)(v9 + 2008);
      if ( (*(_BYTE *)(v12 + 10) & 4) == 0 )
      {
        v13 = *(_QWORD *)(*(_QWORD *)(_X20 + 8) + 56LL);
        if ( v13 )
        {
          v14 = *(_QWORD *)(v13 + 8);
          if ( v14 )
          {
            v15 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v14 + 80LL);
            if ( v15 )
            {
              v16 = msm_get_conn_state(*(_QWORD *)(v9 + 2008));
              if ( *((_DWORD *)v15 - 1) != -1440990782 )
                __break(0x8235u);
              v17 = v15(v16);
              if ( v17 )
              {
                if ( (*(_BYTE *)(v17 + 8) & 0xF8) != 0 )
                  continue;
                if ( (*(_BYTE *)(v12 + 10) & 0xA) == 8 && *(_BYTE *)(v12 + 9) == 1 )
                {
                  v18 = *(unsigned int *)(_X20 + 40);
                  if ( (int)v18 >= 1 )
                  {
                    v19 = 0;
                    v20 = *(_QWORD *)(_X20 + 48) + 16LL;
                    do
                    {
                      v26 = *(_QWORD *)(v20 - 16);
                      if ( v26 )
                      {
                        if ( *(_QWORD *)(*(_QWORD *)v20 + 8LL) == *(_QWORD *)v12
                          || *(_QWORD *)(*(_QWORD *)(v26 + 2512) + 8LL) == *(_QWORD *)v12 )
                        {
                          ++v19;
                        }
                        if ( v19 > 1 )
                          goto LABEL_5;
                      }
                      --v18;
                      v20 += 40;
                    }
                    while ( v18 );
                  }
                }
              }
            }
          }
        }
      }
      if ( *(_BYTE *)(*(_QWORD *)(v9 + 2008) + 8LL) == 1 )
      {
        v27 = *(_QWORD *)(v9 + 448);
        *(double *)&v28 = _drm_dev_dbg(0, 0, 4, "enabling [CRTC:%d]\n", *(_DWORD *)(v9 + 112));
        v29 = *(void (__fastcall **)(__int64, __int64, long double))(v27 + 104);
        if ( !v29 )
        {
          v34 = *(void (__fastcall **)(_QWORD, long double))(v27 + 16);
          if ( *((_DWORD *)v34 - 1) != -1434212794 )
            __break(0x8228u);
          v34(v9, v28);
          v30 = *v6;
          if ( !*v6 )
            continue;
LABEL_45:
          v31 = *(__int64 (__fastcall **)(_QWORD))(v30 + 80);
          if ( v31 )
          {
            v32 = msm_get_conn_state(v10);
            if ( *((_DWORD *)v31 - 1) != -1440990782 )
              __break(0x8235u);
            v33 = v31(v32);
            if ( v33 && (*(_BYTE *)(v33 + 8) & 2) != 0 )
              drm_crtc_wait_one_vblank(v9);
          }
          continue;
        }
        if ( *((_DWORD *)v29 - 1) != -1506053658 )
          __break(0x8228u);
        v29(v9, _X20, v28);
      }
      v30 = *v6;
      if ( *v6 )
        goto LABEL_45;
LABEL_5:
      ;
    }
  }
  if ( *(int *)(_X20 + 40) < 1 )
  {
    v57 = 1;
    if ( !v6 )
      goto LABEL_95;
    goto LABEL_90;
  }
  v35 = 0;
  v36 = 0;
  v37 = 0;
  do
  {
    v44 = *(_QWORD *)(_X20 + 48);
    v45 = *(_QWORD *)(v44 + v35);
    if ( v45 )
    {
      v46 = *(_QWORD *)(v44 + v35 + 24);
      if ( *(_QWORD *)(v46 + 16) )
      {
        v47 = *(_QWORD *)(*(_QWORD *)(v46 + 8) + 2008LL);
        if ( *(_BYTE *)(v47 + 9) == 1 )
        {
          v48 = (__int64 **)msm_get_conn_state(v47);
          if ( (*(_BYTE *)(v47 + 10) & 0xE) != 0 )
            goto LABEL_70;
          if ( v48 )
          {
            if ( *v48 )
            {
              v52 = **v48;
              if ( v52 )
              {
                v53 = *(_QWORD *)(v52 + 56);
                if ( v53 )
                {
                  v54 = *(_QWORD *)(v53 + 8);
                  if ( v54 )
                  {
                    v55 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v54 + 80LL);
                    if ( v55 )
                    {
                      if ( *((_DWORD *)v55 - 1) != -1440990782 )
                        __break(0x8228u);
                      v56 = v55(v48);
                      if ( v56 )
                      {
                        if ( (*(_WORD *)(v56 + 8) & 0x1D4) != 0 )
                        {
LABEL_70:
                          v49 = *(_DWORD *)(v45 + 152);
                          if ( v49 >= *(_DWORD *)(_X20 + 40)
                            || (v50 = *(_QWORD *)(*(_QWORD *)(_X20 + 48) + 40LL * v49 + 16)) == 0
                            || (v51 = *(_QWORD *)(v50 + 8)) == 0
                            || (*(_BYTE *)(*(_QWORD *)(v51 + 2008) + 10LL) & 0xE) != 8
                            || v51 != *(_QWORD *)(*(_QWORD *)(v45 + 2512) + 8LL) )
                          {
                            v38 = *(_QWORD *)(*(_QWORD *)(v45 + 2512) + 16LL);
                            v39 = *(_QWORD *)(v38 + 112);
                            *(double *)&v40 = _drm_dev_dbg(
                                                0,
                                                0,
                                                4,
                                                "enabling [ENCODER:%d:%s]\n",
                                                *(_DWORD *)(v38 + 24),
                                                *(const char **)(v38 + 56));
                            v41 = *(_QWORD *)(v38 + 88);
                            if ( v41 == v38 + 88 )
                              v42 = 0;
                            else
                              v42 = v41 - 120;
                            drm_atomic_bridge_chain_pre_enable(v42, _X20, v40);
                            v43 = *(void (__fastcall **)(_QWORD))(v39 + 88);
                            if ( !v43 )
                              v43 = *(void (__fastcall **)(_QWORD))(v39 + 32);
                            ++v37;
                            if ( *((_DWORD *)v43 - 1) != -781534014 )
                              __break(0x8228u);
                            v43(v38);
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
    ++v36;
    v35 += 40;
  }
  while ( v36 < *(int *)(_X20 + 40) );
  v57 = v37 == 0;
  if ( v6 )
  {
LABEL_90:
    if ( *v6 && *(_QWORD *)(*v6 + 64) )
    {
      *(double *)&v58 = _drm_dev_dbg(0, 0, 4, "triggering commit\n");
      v59 = *(void (__fastcall **)(__int64 *, __int64, long double))(*v6 + 64);
      if ( *((_DWORD *)v59 - 1) != 1690549992 )
        __break(0x8228u);
      v59(v6, _X20, v58);
    }
  }
LABEL_95:
  if ( v57 )
  {
    v60 = v99;
  }
  else
  {
    if ( *(int *)(_X20 + 40) >= 1 )
    {
      v61 = 0;
      v62 = 0;
      do
      {
        v67 = *(_QWORD *)(_X20 + 48);
        v68 = *(_QWORD *)(v67 + v61);
        if ( v68 )
        {
          v69 = *(_QWORD *)(v67 + v61 + 24);
          if ( *(_QWORD *)(v69 + 16) )
          {
            v70 = *(_QWORD *)(*(_QWORD *)(v69 + 8) + 2008LL);
            if ( *(_BYTE *)(v70 + 9) == 1 )
            {
              v71 = (__int64 **)msm_get_conn_state(v70);
              if ( (*(_BYTE *)(v70 + 10) & 0xE) != 0 )
                goto LABEL_108;
              if ( v71 )
              {
                if ( *v71 )
                {
                  v75 = **v71;
                  if ( v75 )
                  {
                    v76 = *(_QWORD *)(v75 + 56);
                    if ( v76 )
                    {
                      v77 = *(_QWORD *)(v76 + 8);
                      if ( v77 )
                      {
                        v78 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v77 + 80LL);
                        if ( v78 )
                        {
                          if ( *((_DWORD *)v78 - 1) != -1440990782 )
                            __break(0x8228u);
                          v79 = v78(v71);
                          if ( v79 )
                          {
                            if ( (*(_WORD *)(v79 + 8) & 0x1D4) != 0 )
                            {
LABEL_108:
                              v72 = *(_DWORD *)(v68 + 152);
                              if ( v72 >= *(_DWORD *)(_X20 + 40)
                                || (v73 = *(_QWORD *)(*(_QWORD *)(_X20 + 48) + 40LL * v72 + 16)) == 0
                                || (v74 = *(_QWORD *)(v73 + 8)) == 0
                                || (*(_BYTE *)(*(_QWORD *)(v74 + 2008) + 10LL) & 0xE) != 8
                                || v74 != *(_QWORD *)(*(_QWORD *)(v68 + 2512) + 8LL) )
                              {
                                v63 = *(_QWORD *)(*(_QWORD *)(v68 + 2512) + 16LL);
                                *(double *)&v64 = _drm_dev_dbg(
                                                    0,
                                                    0,
                                                    4,
                                                    "bridge enable enabling [ENCODER:%d:%s]\n",
                                                    *(_DWORD *)(v63 + 24),
                                                    *(const char **)(v63 + 56));
                                v65 = *(_QWORD *)(v63 + 88);
                                if ( v65 == v63 + 88 )
                                  v66 = 0;
                                else
                                  v66 = v65 - 120;
                                drm_atomic_bridge_chain_enable(v66, _X20, v64);
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
        ++v62;
        v61 += 40;
      }
      while ( v62 < *(int *)(_X20 + 40) );
    }
    v60 = v99;
  }
  v80 = *(_QWORD *)(_X20 + 8);
  if ( *(int *)(v80 + 860) >= 1 )
  {
    v81 = 0;
    v82 = 0;
    v83 = *(_QWORD *)(*(_QWORD *)(v80 + 56) + 8LL);
    do
    {
      v84 = *(_QWORD *)(_X20 + 32);
      if ( *(_QWORD *)(v84 + v81) && *(_BYTE *)(*(_QWORD *)(v84 + v81 + 24) + 9LL) == 1 )
      {
        v85 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v83 + 88LL);
        if ( *((_DWORD *)v85 - 1) != 1715898470 )
          __break(0x8228u);
        v85(v83);
        v80 = *(_QWORD *)(_X20 + 8);
      }
      ++v82;
      v81 += 56;
    }
    while ( v82 < *(int *)(v80 + 860) );
  }
  drm_atomic_helper_cleanup_planes(v3, _X20);
  v86 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v60 + 72LL);
  if ( *((_DWORD *)v86 - 1) != 1690549992 )
    __break(0x8228u);
  v86(v60, _X20);
  __asm { PRFM            #0x11, [X20] }
  do
    v92 = __ldxr((unsigned int *)_X20);
  while ( __stlxr(v92 - 1, (unsigned int *)_X20) );
  if ( v92 == 1 )
  {
    __dmb(9u);
    _drm_atomic_state_free(_X20);
  }
  else if ( v92 <= 0 )
  {
    refcount_warn_saturate(_X20, 3);
  }
  v93 = *(_DWORD *)(a1 + 16);
  v94 = *(_DWORD *)(a1 + 20);
  v95 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  raw_spin_lock(v95 + 704);
  v96 = _drm_dev_dbg(0, 0, 1, "end: %08x\n", v93);
  v97 = *(_DWORD *)(v95 + 700) & ~v94;
  *(_DWORD *)(v95 + 696) &= ~v93;
  *(_DWORD *)(v95 + 700) = v97;
  _wake_up_locked(v95 + 704, 3, 0, v96);
  result = raw_spin_unlock(v95 + 704);
  if ( *(_BYTE *)(a1 + 24) == 1 )
    return kfree(a1);
  return result;
}
