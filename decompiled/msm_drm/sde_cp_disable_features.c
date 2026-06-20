__int64 __fastcall sde_cp_disable_features(__int64 a1)
{
  int v2; // w8
  unsigned int v3; // w20
  __int64 v4; // x21
  int v5; // w26
  __int64 v6; // x25
  __int64 (__fastcall *v7)(__int64, __int64 *, __int64); // x27
  __int64 *v8; // x28
  unsigned __int64 i; // x22
  __int64 v10; // x24
  int v11; // w8
  int v12; // w9
  __int64 v13; // x10
  __int64 v14; // x0
  __int64 v15; // x9
  int v16; // w11
  __int64 v17; // x8
  __int64 v18; // x12
  int *v19; // x9
  int *v20; // x13
  _DWORD *v21; // x14
  int *v22; // x10
  __int64 v23; // x15
  int *v24; // x11
  unsigned int v25; // w8
  int *v26; // x11
  int **v27; // x0
  int **v28; // x1
  int **v29; // x8
  int *v30; // x16
  __int64 result; // x0
  char v32; // [xsp+0h] [xbp-F0h]
  unsigned int v33; // [xsp+4h] [xbp-ECh]
  __int64 *v34; // [xsp+8h] [xbp-E8h]
  __int64 v35; // [xsp+10h] [xbp-E0h] BYREF
  __int64 v36; // [xsp+18h] [xbp-D8h]
  __int64 v37; // [xsp+20h] [xbp-D0h]
  __int64 v38; // [xsp+28h] [xbp-C8h]
  __int64 v39; // [xsp+30h] [xbp-C0h]
  __int64 v40; // [xsp+38h] [xbp-B8h]
  __int64 v41; // [xsp+40h] [xbp-B0h]
  __int64 v42; // [xsp+48h] [xbp-A8h]
  __int64 v43; // [xsp+50h] [xbp-A0h]
  __int64 v44; // [xsp+58h] [xbp-98h]
  __int64 v45; // [xsp+60h] [xbp-90h]
  __int64 v46; // [xsp+68h] [xbp-88h]
  __int64 v47; // [xsp+70h] [xbp-80h]
  __int64 v48; // [xsp+78h] [xbp-78h]
  __int64 v49; // [xsp+80h] [xbp-70h]
  __int64 v50; // [xsp+88h] [xbp-68h]
  __int64 v51; // [xsp+90h] [xbp-60h]
  __int64 v52; // [xsp+98h] [xbp-58h]
  __int64 v53; // [xsp+A0h] [xbp-50h]
  __int64 v54; // [xsp+A8h] [xbp-48h]
  __int64 v55; // [xsp+B0h] [xbp-40h]
  __int64 v56; // [xsp+B8h] [xbp-38h]
  __int64 v57; // [xsp+C0h] [xbp-30h]
  __int64 v58; // [xsp+C8h] [xbp-28h]
  __int64 v59; // [xsp+D0h] [xbp-20h]
  __int64 v60; // [xsp+D8h] [xbp-18h]
  __int64 v61; // [xsp+E0h] [xbp-10h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 2192);
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  if ( v2 )
  {
    if ( (unsigned int)(v2 - 9) < 0xFFFFFFF8 )
LABEL_88:
      __break(0x5512u);
    v3 = *(_QWORD *)(a1 + 2216) != 0;
    if ( v2 != 1 )
    {
      if ( *(_QWORD *)(a1 + 2264) )
        ++v3;
      if ( v2 != 2 )
      {
        if ( *(_QWORD *)(a1 + 2312) )
          ++v3;
        if ( v2 != 3 )
        {
          if ( *(_QWORD *)(a1 + 2360) )
            ++v3;
          if ( v2 != 4 )
          {
            if ( *(_QWORD *)(a1 + 2408) )
              ++v3;
            if ( v2 != 5 )
            {
              if ( *(_QWORD *)(a1 + 2456) )
                ++v3;
              if ( v2 != 6 )
              {
                if ( *(_QWORD *)(a1 + 2504) )
                  ++v3;
                if ( v2 != 7 && *(_QWORD *)(a1 + 2552) )
                  ++v3;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v3 = 0;
  }
  v4 = 0;
  v5 = 0;
  v34 = (__int64 *)(a1 + 2216);
  do
  {
    v6 = dword_29D19C[v4];
    v7 = (__int64 (__fastcall *)(__int64, __int64 *, __int64))set_crtc_feature_wrappers[v6];
    if ( v7 )
    {
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_cp_disable_features", 2924, -1, v4, v6, v3, -1059143953, v32);
      _drm_dev_dbg(0, 0, 0, "Disable feature %d\n", v6);
      mutex_lock(a1 + 4664);
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = 0;
      v52 = 0;
      v49 = 0;
      v50 = 0;
      v47 = 0;
      v48 = 0;
      v45 = 0;
      v46 = 0;
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      v39 = 0;
      v40 = 0;
      v37 = 0;
      v38 = 0;
      v35 = 0;
      v36 = 0;
      if ( v3 )
      {
        if ( *(_QWORD *)(a1 + 2216) )
          v41 = *(_QWORD *)(a1 + 2216);
        if ( v3 != 1 )
        {
          if ( *(_QWORD *)(a1 + 2264) )
            v42 = *(_QWORD *)(a1 + 2264);
          if ( v3 != 2 )
          {
            if ( *(_QWORD *)(a1 + 2312) )
              v43 = *(_QWORD *)(a1 + 2312);
            if ( v3 != 3 )
            {
              if ( *(_QWORD *)(a1 + 2360) )
                v44 = *(_QWORD *)(a1 + 2360);
              if ( v3 != 4 )
              {
                if ( *(_QWORD *)(a1 + 2408) )
                  v45 = *(_QWORD *)(a1 + 2408);
                if ( v33 > 3 )
                  goto LABEL_88;
              }
            }
          }
        }
        v35 = 0;
        if ( !v5 )
        {
          v8 = v34;
          for ( i = 1; ; ++i )
          {
            if ( i == 9 )
              goto LABEL_88;
            v10 = *(v8 - 2);
            if ( !v10 )
              break;
            v11 = *(_DWORD *)(v10 + 376);
            v12 = *(_DWORD *)(v10 + 380);
            v13 = *(_QWORD *)(a1 + 2008);
            v39 = *(v8 - 2);
            HIDWORD(v38) = v3;
            LODWORD(v40) = v12;
            HIDWORD(v40) = v11 * v3;
            v15 = *(v8 - 1);
            v14 = *v8;
            HIDWORD(v46) = *(unsigned __int16 *)(v13 + 38);
            LODWORD(v13) = *(unsigned __int16 *)(v13 + 28);
            v16 = sde_cp_crtc_feat_to_hfi_prop_id[v6];
            v17 = *(_QWORD *)(a1 + 8032);
            v37 = v15;
            LODWORD(v47) = v13;
            LODWORD(v55) = v16;
            if ( v17 )
              v54 = *(_QWORD *)(v17 + 64);
            if ( *((_DWORD *)v7 - 1) != -1802519210 )
              __break(0x823Bu);
            v5 = v7(v14, &v35, a1);
            if ( v5 )
              goto LABEL_29;
            sde_cp_dspp_flush_helper(a1, v6);
            if ( i >= v3 )
              goto LABEL_29;
            v8 += 6;
          }
          v5 = -22;
        }
      }
LABEL_29:
      mutex_unlock(a1 + 4664);
    }
    else
    {
      _drm_dev_dbg(0, 0, 0, "unsupported feature:%d\n", v6);
    }
    ++v4;
  }
  while ( v4 != 4 );
  mutex_lock(a1 + 4664);
  v18 = 0;
  v19 = (int *)(a1 + 4552);
  v20 = (int *)(a1 + 4536);
  v21 = &unk_289B7C;
  v22 = (int *)(a1 + 4568);
  v23 = 1;
  do
  {
    v25 = v21[v18];
    v26 = v19;
    do
    {
      v26 = *(int **)v26;
      if ( v26 == v19 )
      {
        v24 = v20;
        do
        {
          v24 = *(int **)v24;
          if ( v24 == v20 )
            goto LABEL_62;
        }
        while ( *(v24 - 12) != v25 );
        if ( v24 == &dword_38 )
          break;
        if ( v25 <= 0x2B && ((v23 << v25) & 0x7F8000) != 0 )
        {
          v27 = (int **)(v24 + 4);
          v28 = *(int ***)(a1 + 4576);
          if ( v24 + 4 != v22 && v27 != v28 && *v28 == v22 )
          {
            *(_QWORD *)(a1 + 4576) = v27;
            *((_QWORD *)v24 + 2) = v22;
            goto LABEL_81;
          }
LABEL_85:
          _list_add_valid_or_report(v27, v28);
        }
        else
        {
          v27 = (int **)(v24 + 4);
          v28 = *(int ***)(a1 + 4560);
          if ( v24 + 4 == v19 || v27 == v28 || *v28 != v19 )
            goto LABEL_85;
          *(_QWORD *)(a1 + 4560) = v27;
          *((_QWORD *)v24 + 2) = v19;
LABEL_81:
          *((_QWORD *)v24 + 3) = v28;
          *v28 = (int *)v27;
        }
        v29 = *((int ***)v24 + 1);
        if ( *v29 == v24 && (v30 = *(int **)v24, *(int **)(*(_QWORD *)v24 + 8LL) == v24) )
        {
          *((_QWORD *)v30 + 1) = v29;
          *v29 = v30;
        }
        else
        {
          _list_del_entry_valid_or_report(v24);
        }
        *(_QWORD *)v24 = v24;
        *((_QWORD *)v24 + 1) = v24;
        break;
      }
    }
    while ( *(v26 - 16) != v25 );
LABEL_62:
    ++v18;
  }
  while ( v18 != 3 );
  result = mutex_unlock(a1 + 4664);
  _ReadStatusReg(SP_EL0);
  return result;
}
