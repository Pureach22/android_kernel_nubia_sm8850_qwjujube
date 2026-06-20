__int64 __fastcall sde_cp_crtc_commit_feature(int *a1, __int64 a2)
{
  __int64 v2; // x23
  int v3; // w9
  __int64 v4; // x8
  __int64 result; // x0
  int *v8; // x8
  __int64 v9; // x9
  _BOOL4 v10; // w7
  int v11; // w8
  int *v12; // x9
  __int64 v13; // x10
  __int64 v14; // x9
  unsigned int v15; // w22
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x11
  int v20; // w4
  int v21; // w6
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x9
  int v25; // w8
  int v26; // w8
  __int64 v27; // x10
  __int64 v28; // x9
  __int64 v29; // x9
  __int64 v30; // x9
  __int64 v31; // x8
  unsigned int (*v32)(void); // x24
  __int64 *v33; // x25
  unsigned __int64 v34; // x28
  __int64 v35; // x21
  __int64 v36; // x0
  __int64 v37; // x8
  int v38; // w9
  int v39; // w11
  __int64 v40; // x8
  int v41; // w10
  __int64 v42; // x9
  bool v43; // cf
  int v44; // w4
  unsigned int v45; // w8
  __int64 *v46; // x1
  __int64 v47; // x2
  int **v48; // x8
  __int64 *v49; // x9
  __int64 v50; // x10
  int **v51; // x8
  __int64 *v52; // x9
  __int64 v53; // x10
  const char *v54; // x1
  __int64 v55; // x8
  __int64 (__fastcall *v56)(__int64, int **, __int64); // x21
  __int64 *v57; // x24
  unsigned __int64 v58; // x25
  __int64 v59; // x8
  int v60; // w9
  __int64 v61; // x0
  __int64 v62; // x10
  _BOOL4 v63; // [xsp+Ch] [xbp-E4h]
  int *v64; // [xsp+10h] [xbp-E0h] BYREF
  __int64 v65; // [xsp+18h] [xbp-D8h]
  __int64 v66; // [xsp+20h] [xbp-D0h]
  __int64 v67; // [xsp+28h] [xbp-C8h]
  __int64 v68; // [xsp+30h] [xbp-C0h]
  __int64 v69; // [xsp+38h] [xbp-B8h]
  __int64 v70; // [xsp+40h] [xbp-B0h]
  __int64 v71; // [xsp+48h] [xbp-A8h]
  __int64 v72; // [xsp+50h] [xbp-A0h]
  __int64 v73; // [xsp+58h] [xbp-98h]
  __int64 v74; // [xsp+60h] [xbp-90h]
  __int64 v75; // [xsp+68h] [xbp-88h]
  _QWORD v76[6]; // [xsp+70h] [xbp-80h] BYREF
  __int64 v77; // [xsp+A0h] [xbp-50h]
  __int64 v78; // [xsp+A8h] [xbp-48h]
  __int64 v79; // [xsp+B0h] [xbp-40h]
  __int64 v80; // [xsp+B8h] [xbp-38h]
  __int64 v81; // [xsp+C0h] [xbp-30h]
  __int64 v82; // [xsp+C8h] [xbp-28h]
  __int64 v83; // [xsp+D0h] [xbp-20h]
  __int64 v84; // [xsp+D8h] [xbp-18h]
  __int64 v85; // [xsp+E0h] [xbp-10h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 2008);
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  memset(v76, 0, sizeof(v76));
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = nullptr;
  v65 = 0;
  if ( !v2 )
  {
    result = _drm_err("sde_crtc_state is null\n");
    goto LABEL_98;
  }
  v3 = a1[1];
  v4 = *((_QWORD *)a1 + 2);
  v83 = 0;
  v84 = 0;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  memset(v76, 0, sizeof(v76));
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = nullptr;
  v65 = 0;
  if ( (v3 & 0x10) != 0 )
  {
    if ( v4 )
    {
      v9 = *(_QWORD *)(v4 + 72);
      v8 = *(int **)(v4 + 80);
      v10 = 1;
      LODWORD(v65) = v9;
      v64 = v8;
      v11 = *(_DWORD *)(a2 + 2192);
      if ( !v11 )
        goto LABEL_18;
      goto LABEL_20;
    }
    goto LABEL_19;
  }
  if ( (v3 & 2) != 0 )
  {
    v12 = a1 + 6;
    v13 = *((_QWORD *)a1 + 3);
    if ( v4 )
    {
      if ( v13 )
      {
        v12 = *(int **)(v4 + 80);
        LODWORD(v65) = *(_QWORD *)(v4 + 72);
        goto LABEL_17;
      }
    }
    else if ( v13 )
    {
      LODWORD(v65) = 8;
LABEL_17:
      v64 = v12;
      v10 = 1;
      v11 = *(_DWORD *)(a2 + 2192);
      if ( !v11 )
        goto LABEL_18;
      goto LABEL_20;
    }
LABEL_19:
    v10 = 0;
    v11 = *(_DWORD *)(a2 + 2192);
    if ( v11 )
      goto LABEL_20;
LABEL_18:
    v15 = 0;
    goto LABEL_42;
  }
  if ( (v3 & 8) == 0 )
  {
    _drm_err("property type is not supported\n");
    goto LABEL_19;
  }
  v14 = *((_QWORD *)a1 + 3);
  LODWORD(v65) = 8;
  v64 = a1 + 6;
  v10 = v14 != 0;
  v11 = *(_DWORD *)(a2 + 2192);
  if ( !v11 )
    goto LABEL_18;
LABEL_20:
  if ( (unsigned int)(v11 - 9) < 0xFFFFFFF8 )
    goto LABEL_115;
  v15 = *(_QWORD *)(a2 + 2216) != 0;
  if ( v11 != 1 )
  {
    if ( *(_QWORD *)(a2 + 2264) )
      ++v15;
    if ( v11 != 2 )
    {
      if ( *(_QWORD *)(a2 + 2312) )
        ++v15;
      if ( v11 != 3 )
      {
        if ( *(_QWORD *)(a2 + 2360) )
          ++v15;
        if ( v11 != 4 )
        {
          if ( *(_QWORD *)(a2 + 2408) )
            ++v15;
          if ( v11 != 5 )
          {
            if ( *(_QWORD *)(a2 + 2456) )
              ++v15;
            if ( v11 != 6 )
            {
              if ( *(_QWORD *)(a2 + 2504) )
                ++v15;
              if ( v11 != 7 && *(_QWORD *)(a2 + 2552) )
                ++v15;
            }
          }
        }
      }
    }
  }
LABEL_42:
  v16 = *(_QWORD *)(a2 + 2008);
  LODWORD(v67) = 0;
  HIDWORD(v67) = v15;
  v17 = *(_QWORD *)(a2 + 7976);
  v18 = *(_QWORD *)(a2 + 8008);
  v19 = *(_QWORD *)(a2 + 8000);
  v20 = a1[2];
  v63 = v10;
  LODWORD(v76[0]) = *(unsigned __int16 *)(v16 + 28);
  v21 = *(unsigned __int16 *)(v16 + 38);
  v22 = *(_QWORD *)(a2 + 7992);
  *(_QWORD *)((char *)v76 + 4) = v17;
  v23 = *(_QWORD *)(a2 + 7984);
  *(_QWORD *)((char *)&v76[4] + 4) = v18;
  LODWORD(v18) = *(unsigned __int16 *)(v2 + 626);
  *(_QWORD *)((char *)&v76[2] + 4) = v22;
  LODWORD(v22) = *(unsigned __int16 *)(v2 + 662);
  *(_QWORD *)((char *)&v76[1] + 4) = v23;
  LODWORD(v23) = *(_DWORD *)(v2 + 2048);
  LODWORD(v22) = v22 - v18;
  *(_QWORD *)((char *)&v76[3] + 4) = v19;
  LODWORD(v18) = *(unsigned __int16 *)(v2 + 630);
  LODWORD(v19) = *(unsigned __int16 *)(v2 + 666);
  HIDWORD(v76[5]) = v23;
  LODWORD(v77) = v22;
  HIDWORD(v75) = v21;
  HIDWORD(v77) = v18 - v19;
  sde_evtlog_log(sde_dbg_base_evtlog, "_sde_cp_crtc_commit_feature", 1728, -1, v20, v76[0], v21, v10, 239);
  if ( v15 )
  {
    v24 = *(_QWORD *)(a2 + 2216);
    if ( v24 )
    {
      v25 = *(_DWORD *)(v24 + 64);
      v70 = *(_QWORD *)(a2 + 2216);
      HIDWORD(v80) = v25;
      v26 = 1;
      if ( v15 == 1 )
        goto LABEL_66;
    }
    else
    {
      v26 = 0;
      if ( v15 == 1 )
        goto LABEL_66;
    }
    v27 = *(_QWORD *)(a2 + 2264);
    if ( v27 )
    {
      v71 = *(_QWORD *)(a2 + 2264);
      if ( !v24 )
        HIDWORD(v80) = *(_DWORD *)(v27 + 64);
      v26 = 1;
    }
    if ( v15 != 2 )
    {
      v28 = *(_QWORD *)(a2 + 2312);
      if ( v28 )
      {
        v72 = *(_QWORD *)(a2 + 2312);
        if ( !v26 )
          HIDWORD(v80) = *(_DWORD *)(v28 + 64);
        v26 = 1;
      }
      if ( v15 != 3 )
      {
        v29 = *(_QWORD *)(a2 + 2360);
        if ( v29 )
        {
          v73 = *(_QWORD *)(a2 + 2360);
          if ( !v26 )
            HIDWORD(v80) = *(_DWORD *)(v29 + 64);
          v26 = 1;
        }
        if ( v15 != 4 )
        {
          v30 = *(_QWORD *)(a2 + 2408);
          if ( v30 )
          {
            v74 = *(_QWORD *)(a2 + 2408);
            if ( !v26 )
              HIDWORD(v80) = *(_DWORD *)(v30 + 64);
          }
          if ( v15 - 5 > 3 )
            goto LABEL_115;
        }
      }
    }
  }
LABEL_66:
  v31 = (unsigned int)a1[2];
  if ( (unsigned int)v31 > 0x33
    || (v32 = (unsigned int (*)(void))set_crtc_feature_wrappers[v31]) == nullptr
    || (LOBYTE(v75) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a2 + 56LL) + 8LL) + 152LL) + 19940LL) != 0,
        !v15) )
  {
LABEL_81:
    v44 = *a1;
    if ( !v63 )
    {
      result = _drm_dev_dbg(0, 0, 1, "remove feature from active list %d\n", v44);
LABEL_89:
      v48 = *((int ***)a1 + 8);
      v49 = (__int64 *)(a1 + 14);
      if ( *v48 == a1 + 14 && (v50 = *v49, *(__int64 **)(*v49 + 8) == v49) )
      {
        *(_QWORD *)(v50 + 8) = v48;
        *v48 = (int *)v50;
      }
      else
      {
        result = _list_del_entry_valid_or_report(a1 + 14);
      }
      *((_QWORD *)a1 + 7) = a1 + 14;
      *((_QWORD *)a1 + 8) = v49;
      goto LABEL_94;
    }
    result = _drm_dev_dbg(0, 0, 1, "Add feature to active list %d\n", v44);
    v45 = a1[2];
    if ( v45 <= 0x2B )
    {
      if ( ((1LL << v45) & 0x7F8000) != 0 )
      {
        result = (__int64)(a1 + 14);
        v46 = *(__int64 **)(a2 + 4592);
        v47 = a2 + 4584;
        if ( a1 + 14 == (int *)(a2 + 4584) || (__int64 *)result == v46 || *v46 != v47 )
        {
          result = _list_add_valid_or_report(result, v46);
        }
        else
        {
          *(_QWORD *)(a2 + 4592) = result;
          *((_QWORD *)a1 + 7) = v47;
          *((_QWORD *)a1 + 8) = v46;
          *v46 = result;
        }
LABEL_94:
        v51 = *((int ***)a1 + 10);
        v52 = (__int64 *)(a1 + 18);
        if ( *v51 == a1 + 18 && (v53 = *v52, *(__int64 **)(*v52 + 8) == v52) )
        {
          *(_QWORD *)(v53 + 8) = v51;
          *v51 = (int *)v53;
        }
        else
        {
          result = _list_del_entry_valid_or_report(a1 + 18);
        }
        *((_QWORD *)a1 + 9) = a1 + 18;
        *((_QWORD *)a1 + 10) = v52;
        goto LABEL_98;
      }
      if ( ((1LL << v45) & 0x800F0000000LL) != 0 )
        goto LABEL_94;
    }
    result = _list_add(a1 + 14, *(_QWORD *)(a2 + 4544), a2 + 4536);
    goto LABEL_94;
  }
  v33 = (__int64 *)(a2 + 2216);
  v34 = 1;
  while ( 1 )
  {
    if ( v34 == 9 )
      goto LABEL_115;
    v35 = *(v33 - 2);
    if ( !v35 )
      break;
    v37 = *(v33 - 1);
    v36 = *v33;
    v38 = *(_DWORD *)(v35 + 376);
    v39 = *(_DWORD *)(v35 + 380);
    v68 = *(v33 - 2);
    v66 = v37;
    v40 = (unsigned int)a1[2];
    v41 = *(_DWORD *)(v36 + 64);
    v84 = a2 + 8448;
    LODWORD(v81) = v41;
    LODWORD(v69) = v39;
    HIDWORD(v69) = v38 * v15;
    if ( (unsigned int)v40 >= 0x34 )
      goto LABEL_115;
    v42 = *(_QWORD *)(a2 + 8032);
    LODWORD(v79) = sde_cp_crtc_feat_to_hfi_prop_id[v40];
    if ( v42 )
    {
      v78 = *(_QWORD *)(v42 + 64);
      if ( (_DWORD)v40 == 37 )
        v82 = v42 + 88;
    }
    if ( *((_DWORD *)v32 - 1) != -1802519210 )
      __break(0x8238u);
    if ( v32() )
      break;
    v43 = v34++ >= v15;
    v33 += 6;
    if ( v43 )
      goto LABEL_81;
  }
  if ( v63 )
    v54 = "enable";
  else
    v54 = "disable";
  result = _drm_err("failed to %s feature %d\n", v54, (unsigned int)a1[2]);
  v55 = (unsigned int)a1[2];
  if ( (unsigned int)v55 > 0x33 )
LABEL_115:
    __break(0x5512u);
  v56 = (__int64 (__fastcall *)(__int64, int **, __int64))crtc_feature_disable_wrappers[v55];
  if ( v56 )
  {
    v57 = (__int64 *)(a2 + 2216);
    v58 = 1;
    while ( v58 != 9 )
    {
      v59 = *(v57 - 2);
      if ( v59 )
      {
        v60 = *(_DWORD *)(v59 + 376);
        v62 = *(v57 - 1);
        v61 = *v57;
        v68 = *(v57 - 2);
        v66 = v62;
        LODWORD(v69) = *(_DWORD *)(v59 + 380);
        HIDWORD(v69) = v60 * v15;
        if ( *((_DWORD *)v56 - 1) != -1802519210 )
          __break(0x8235u);
        result = v56(v61, &v64, a2);
        if ( v58 < v15 )
        {
          ++v58;
          v57 += 6;
          if ( !(_DWORD)result )
            continue;
        }
      }
      goto LABEL_89;
    }
    goto LABEL_115;
  }
LABEL_98:
  _ReadStatusReg(SP_EL0);
  return result;
}
