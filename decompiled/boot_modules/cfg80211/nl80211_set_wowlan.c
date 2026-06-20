__int64 __fastcall nl80211_set_wowlan(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x26
  _WORD *v6; // x2
  __int64 result; // x0
  bool v9; // w8
  __int64 v10; // x20
  __int64 v11; // x21
  __int64 v12; // x8
  _QWORD *v13; // x0
  __int64 v14; // x8
  _DWORD *v15; // x8
  int v16; // w8
  int v17; // w21
  unsigned __int16 *v18; // x9
  unsigned int v19; // w10
  __int64 v20; // x10
  int v21; // w24
  _QWORD *v22; // x8
  int v23; // w28
  unsigned __int16 *v24; // x25
  unsigned int v25; // w10
  int v26; // w0
  size_t v27; // x22
  unsigned __int64 v28; // x23
  int v29; // w8
  unsigned __int64 v30; // x24
  char *v31; // x0
  char *v32; // x25
  __int64 v33; // x8
  __int64 v34; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v36; // x0
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x8
  unsigned int v40; // w19
  __int64 v41; // x20
  __int64 v42; // x21
  _QWORD *v43; // x0
  unsigned __int16 *v44; // [xsp+18h] [xbp-118h]
  int v45; // [xsp+24h] [xbp-10Ch]
  __int64 v46; // [xsp+28h] [xbp-108h]
  __int64 v47; // [xsp+30h] [xbp-100h] BYREF
  __int64 v48; // [xsp+38h] [xbp-F8h]
  _QWORD *v49; // [xsp+40h] [xbp-F0h]
  __int64 v50; // [xsp+48h] [xbp-E8h]
  __int64 v51; // [xsp+50h] [xbp-E0h]
  __int64 v52; // [xsp+58h] [xbp-D8h] BYREF
  _WORD *v53; // [xsp+60h] [xbp-D0h]
  _WORD *v54; // [xsp+68h] [xbp-C8h]
  __int64 v55; // [xsp+70h] [xbp-C0h]
  __int64 v56; // [xsp+78h] [xbp-B8h] BYREF
  __int64 v57; // [xsp+80h] [xbp-B0h]
  __int64 v58; // [xsp+88h] [xbp-A8h]
  __int64 v59; // [xsp+90h] [xbp-A0h]
  _WORD *v60; // [xsp+98h] [xbp-98h]
  __int64 v61; // [xsp+A0h] [xbp-90h]
  __int64 v62; // [xsp+A8h] [xbp-88h]
  __int64 v63; // [xsp+B0h] [xbp-80h]
  __int64 v64; // [xsp+B8h] [xbp-78h]
  __int64 v65; // [xsp+C0h] [xbp-70h]
  __int64 v66; // [xsp+C8h] [xbp-68h]
  __int64 v67; // [xsp+D0h] [xbp-60h]
  __int64 v68; // [xsp+D8h] [xbp-58h]
  __int64 v69; // [xsp+E0h] [xbp-50h]
  __int64 v70; // [xsp+E8h] [xbp-48h]
  __int64 v71; // [xsp+F0h] [xbp-40h]
  __int64 v72; // [xsp+F8h] [xbp-38h]
  __int64 v73; // [xsp+100h] [xbp-30h]
  __int64 v74; // [xsp+108h] [xbp-28h]
  __int64 v75; // [xsp+110h] [xbp-20h]
  __int64 v76; // [xsp+118h] [xbp-18h]
  __int64 v77; // [xsp+120h] [xbp-10h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (_QWORD *)a2[6];
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = nullptr;
  v3 = v2[155];
  v47 = 0;
  if ( !v3 )
  {
    result = 4294967201LL;
    goto LABEL_33;
  }
  v4 = a2[4];
  v75 = 0;
  v76 = 0;
  v5 = v2[156];
  v73 = 0;
  v74 = 0;
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = nullptr;
  v57 = 0;
  v58 = 0;
  v56 = 0;
  v6 = *(_WORD **)(v4 + 936);
  if ( !v6 )
  {
    if ( v5 )
    {
      if ( *(int *)(v5 + 24) < 1 )
      {
        v12 = v5;
      }
      else
      {
        v10 = 0;
        v11 = 0;
        v12 = v5;
        do
        {
          kfree(*(_QWORD *)(*(_QWORD *)(v12 + 8) + v10));
          v12 = v2[156];
          ++v11;
          v10 += 24;
        }
        while ( v11 < *(int *)(v12 + 24) );
      }
      kfree(*(_QWORD *)(v12 + 8));
      v13 = *(_QWORD **)(v2[156] + 16LL);
      if ( v13 && *v13 )
      {
        sock_release(*v13);
        v13 = *(_QWORD **)(v2[156] + 16LL);
      }
      kfree(v13);
      kfree(*(_QWORD *)(v2[156] + 32LL));
      kfree(v2[156]);
    }
    v3 = 0;
    goto LABEL_27;
  }
  result = _nla_parse(&v56, 20, v6 + 2, (unsigned __int16)(*v6 - 4), &nl80211_wowlan_policy, 0, a2[8]);
  if ( (_DWORD)result )
    goto LABEL_33;
  if ( v57 )
  {
    if ( (*(_BYTE *)v3 & 1) == 0 )
      goto LABEL_14;
    LOBYTE(v47) = 1;
  }
  v9 = v58 != 0;
  if ( v58 )
  {
    if ( (*(_BYTE *)v3 & 4) == 0 )
      goto LABEL_14;
    BYTE1(v47) = 1;
  }
  if ( !v59 )
    goto LABEL_13;
  if ( (*(_BYTE *)v3 & 2) == 0 )
  {
LABEL_14:
    result = 4294967274LL;
    goto LABEL_33;
  }
  v9 = 1;
  BYTE2(v47) = 1;
LABEL_13:
  if ( v61 )
    goto LABEL_14;
  if ( v62 )
  {
    if ( (*(_BYTE *)v3 & 0x10) == 0 )
      goto LABEL_14;
    v9 = 1;
    BYTE3(v47) = 1;
  }
  if ( v63 )
  {
    if ( (*(_BYTE *)v3 & 0x20) == 0 )
      goto LABEL_14;
    v9 = 1;
    BYTE4(v47) = 1;
  }
  if ( v64 )
  {
    if ( (*(_BYTE *)v3 & 0x40) == 0 )
      goto LABEL_14;
    v9 = 1;
    BYTE5(v47) = 1;
  }
  if ( v65 )
  {
    if ( (*(_BYTE *)v3 & 0x80) == 0 )
      goto LABEL_14;
    v9 = 1;
    BYTE6(v47) = 1;
  }
  if ( v60 )
  {
    v54 = nullptr;
    v55 = 0;
    v52 = 0;
    v53 = nullptr;
    v16 = (unsigned __int16)(*v60 - 4);
    if ( (unsigned int)v16 < 4 )
    {
      v17 = 0;
    }
    else
    {
      v17 = 0;
      v18 = v60 + 2;
      do
      {
        v19 = *v18;
        if ( v19 < 4 )
          break;
        if ( v16 < v19 )
          break;
        ++v17;
        v20 = (v19 + 3) & 0x1FFFC;
        v16 -= v20;
        v18 = (unsigned __int16 *)((char *)v18 + v20);
      }
      while ( v16 > 3 );
    }
    if ( v17 > *(_DWORD *)(v3 + 4) )
      goto LABEL_14;
    if ( !is_mul_ok(v17, 0x18u) || (v48 = _kmalloc_noprof(24LL * v17, 3520)) == 0 )
    {
      result = 4294967284LL;
      goto LABEL_33;
    }
    LODWORD(v50) = v17;
    v21 = (unsigned __int16)(*v60 - 4);
    if ( (unsigned int)v21 >= 4 )
    {
      v22 = a2;
      v23 = 0;
      v24 = v60 + 2;
      _ReadStatusReg(SP_EL0);
      do
      {
        v25 = *v24;
        if ( v25 < 4 || v21 < v25 )
          break;
        v26 = _nla_parse(&v52, 3, v24 + 2, (unsigned __int16)(v25 - 4), &nl80211_packet_pattern_policy, 0, v22[8]);
        if ( v26 )
          goto LABEL_93;
        v26 = -22;
        if ( !v53 )
          goto LABEL_93;
        if ( !v54 )
          goto LABEL_93;
        v27 = (unsigned __int16)(*v54 - 4);
        v28 = (unsigned int)(v27 + 7) >> 3;
        if ( (_DWORD)v28 != (unsigned __int16)(*v53 - 4)
          || *(_DWORD *)(v3 + 8) < (int)v27
          || *(_DWORD *)(v3 + 12) > (int)v27 )
        {
          goto LABEL_93;
        }
        v29 = v55;
        if ( v55 )
          v29 = *(_DWORD *)(v55 + 4);
        if ( v29 > *(_DWORD *)(v3 + 16) )
          goto LABEL_93;
        v44 = v24;
        v45 = v21;
        v46 = v48;
        *(_DWORD *)(v48 + 24LL * v23 + 20) = v29;
        v30 = (unsigned int)(v28 + v27);
        v31 = (char *)_kmalloc_noprof(v30, 3264);
        v32 = v31;
        if ( !v31 )
          goto LABEL_92;
        *(_QWORD *)(v46 + 24LL * v23) = v31;
        if ( v30 < v28 )
          goto LABEL_88;
        memcpy(v31, v53 + 2, (unsigned int)(v27 + 7) >> 3);
        v33 = v48 + 24LL * v23;
        *(_QWORD *)(v33 + 8) = &v32[v28];
        *(_DWORD *)(v33 + 16) = v27;
        if ( v30 - v28 < v27 )
        {
          _fortify_panic(17, v30 - v28);
LABEL_88:
          _fortify_panic(17, (unsigned int)(v28 + v27));
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                           + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
              & 1) != 0 )
          {
            ++*(_DWORD *)(StatusReg + 16);
            v36 = _traceiter_rdev_set_wakeup(0, v2 + 124, v3 != 0);
            v39 = *(_QWORD *)(StatusReg + 16) - 1LL;
            *(_DWORD *)(StatusReg + 16) = v39;
            if ( !v39 || !*(_QWORD *)(StatusReg + 16) )
              preempt_schedule_notrace(v36, v37, v38);
          }
          goto LABEL_29;
        }
        memcpy(&v32[v28], v54 + 2, v27);
        ++v23;
        v34 = (*v44 + 3) & 0x1FFFC;
        v21 = v45 - v34;
        v24 = (unsigned __int16 *)((char *)v44 + v34);
        v22 = a2;
      }
      while ( v21 > 3 );
    }
    v9 = 1;
  }
  if ( v70 )
  {
    v26 = nl80211_parse_wowlan_tcp(v2, v70, &v47);
    if ( v26 )
      goto LABEL_93;
    v9 = 1;
  }
  if ( !v74 )
    goto LABEL_81;
  v26 = nl80211_parse_wowlan_nd(v2, v3, v74, &v47);
  if ( v26 )
  {
LABEL_93:
    v40 = v26;
    if ( (int)v50 >= 1 )
    {
      v41 = 0;
      v42 = 0;
      do
      {
        kfree(*(_QWORD *)(v48 + v41));
        ++v42;
        v41 += 24;
      }
      while ( v42 < (int)v50 );
    }
    kfree(v48);
    v43 = v49;
    if ( v49 && *v49 )
    {
      sock_release(*v49);
      v43 = v49;
    }
    kfree(v43);
    kfree(v51);
    result = v40;
    goto LABEL_33;
  }
  v9 = 1;
LABEL_81:
  if ( (unsigned __int8)v47 == 1 && v9 )
  {
    v26 = -22;
    goto LABEL_93;
  }
  v3 = kmemdup_noprof(&v47, 40, 3264);
  if ( !v3 )
  {
LABEL_92:
    v26 = -12;
    goto LABEL_93;
  }
  cfg80211_rdev_free_wowlan(v2);
LABEL_27:
  v14 = *v2;
  v2[156] = v3;
  if ( *(_QWORD *)(v14 + 16) && (v5 == 0) == (v3 != 0) )
  {
LABEL_29:
    v15 = *(_DWORD **)(*v2 + 16LL);
    if ( *(v15 - 1) != -1552247882 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, bool))v15)(v2 + 124, v3 != 0);
  }
  result = 0;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
