__int64 __fastcall hdd_add_wowl_ptrn(__int64 a1, unsigned __int8 *a2)
{
  __int64 *v4; // x19
  __int64 v5; // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int ref; // w0
  char v15; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 vdev_by_user; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  __int64 v35; // x23
  int v36; // w8
  unsigned __int64 v37; // x28
  char *v38; // x22
  __int64 v39; // x26
  __int64 v40; // x19
  unsigned __int64 v41; // x27
  const void *v42; // x25
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int *v51; // x8
  unsigned __int8 *v52; // x26
  char v53; // w25
  char v54; // w25
  int v55; // w8
  __int64 v56; // x10
  unsigned __int8 *v57; // x26
  unsigned __int64 v58; // x20
  char v59; // w25
  char v60; // w0
  unsigned __int64 v61; // x9
  unsigned __int64 v62; // x20
  char v63; // w25
  char v64; // w0
  unsigned __int64 v65; // x9
  __int64 v66; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int *v75; // x8
  void *v76; // x25
  unsigned int v77; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  char v86; // w8
  const char *v87; // x2
  int v88; // w8
  __int64 v89; // x0
  __int64 v90; // [xsp+18h] [xbp-158h]
  unsigned __int8 v91; // [xsp+28h] [xbp-148h]
  unsigned __int8 num_wow_filters; // [xsp+30h] [xbp-140h]
  _BYTE s[296]; // [xsp+38h] [xbp-138h] BYREF
  __int64 v94; // [xsp+160h] [xbp-10h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v4 = *(__int64 **)(a1 + 24);
  v5 = *v4;
  ref = wlan_objmgr_psoc_try_get_ref(*v4, 5u, v6, v7, v8, v9, v10, v11, v12, v13);
  v15 = 0;
  if ( ref )
    goto LABEL_2;
  if ( (unsigned int)cds_get_conparam() == 5 )
    num_wow_filters = 0;
  else
    num_wow_filters = ucfg_pmo_get_num_wow_filters(*v4);
  wlan_objmgr_psoc_release_ref(v5, 5u, v17, v18, v19, v20, v21, v22, v23, v24);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52824), 0x56u, (__int64)"hdd_add_wowl_ptrn");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is null", v26, v27, v28, v29, v30, v31, v32, v33, "hdd_add_wowl_ptrn");
    v15 = 0;
    goto LABEL_2;
  }
  v34 = vdev_by_user;
  v35 = 0;
  v91 = *(_BYTE *)(vdev_by_user + 104);
  v36 = *a2;
  if ( *a2 )
  {
    do
    {
      if ( v36 == 59 )
        break;
      v36 = a2[++v35];
    }
    while ( a2[v35] );
  }
  if ( (int)v35 < 11 )
  {
    v15 = 1;
    goto LABEL_2;
  }
  v90 = 0;
  v37 = (unsigned __int64)v91 << 8;
  v38 = (char *)&g_hdd_wowl_ptrns + v37;
  while ( 1 )
  {
    if ( !num_wow_filters )
      goto LABEL_62;
    if ( v91 > 5u )
      goto LABEL_65;
    v39 = num_wow_filters - 1LL;
    v40 = v34;
    v41 = 0xFFFFFFFFLL;
    do
    {
      if ( (unsigned __int64)(v39 + 1) >= 0x21 )
        goto LABEL_65;
      if ( v37 + 8LL * (unsigned int)v39 > 0x5FF )
        goto LABEL_66;
      v42 = *(const void **)&v38[8 * (unsigned int)v39];
      if ( v42 )
      {
        if ( strlen(*(const char **)&v38[8 * (unsigned int)v39]) == (unsigned int)v35
          && !bcmp(a2, v42, (unsigned int)v35) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: WoWL pattern '%s' already configured for vdev %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "hdd_add_wowl_ptrn",
            *(_QWORD *)&v38[8 * (unsigned int)v39],
            v91);
          v51 = (_DWORD *)(&off_0 + 1);
          v52 = &a2[(unsigned int)v35];
          LOBYTE(v90) = 1;
          goto LABEL_51;
        }
      }
      else
      {
        v41 = (unsigned int)v39;
      }
      --v39;
    }
    while ( (_DWORD)v39 != -1 );
    if ( v41 == 0xFFFFFFFF || (unsigned __int8)g_hdd_wowl_ptrns_count >= (unsigned int)num_wow_filters )
    {
LABEL_62:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Max WoW patterns (%u) reached",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_add_wowl_ptrn",
        num_wow_filters);
      v89 = v34;
      goto LABEL_63;
    }
    if ( a2[2] != 58 || a2[5] != 58 )
    {
      v87 = "%s: Malformed pattern string. Skip!";
LABEL_50:
      qdf_trace_msg(0x33u, 2u, v87, v26, v27, v28, v29, v30, v31, v32, v33, "hdd_add_wowl_ptrn");
      v51 = (_DWORD *)(&off_0 + 1);
      v52 = &a2[(unsigned int)v35];
      BYTE4(v90) = 1;
      goto LABEL_51;
    }
    v53 = hex_to_bin(*a2);
    s[2] = hex_to_bin(a2[1]) + 16 * v53;
    v54 = hex_to_bin(a2[3]);
    LOBYTE(v55) = hex_to_bin(a2[4]) + 16 * v54;
    s[149] = v55;
    if ( s[2] > 0x92u || (v55 = (unsigned __int8)v55, (unsigned __int8)v55 >= 0x14u) )
    {
      v87 = "%s: Invalid length specified. Skip!";
      goto LABEL_50;
    }
    v56 = 2LL * s[2] + 6;
    if ( (unsigned int)v56 >= (unsigned int)v35 || a2[v56] != 58 )
    {
      v87 = "%s: Malformed pattern string..skip!";
      goto LABEL_50;
    }
    if ( 2 * ((unsigned __int8)v55 + s[2]) + 7 != (_DWORD)v35 )
    {
      v87 = "%s: Malformed pattern string...skip!";
      goto LABEL_50;
    }
    v57 = a2 + 6;
    if ( s[2] )
    {
      v58 = 0;
      do
      {
        v59 = hex_to_bin(*v57);
        v60 = hex_to_bin(v57[1]);
        if ( v58 == 146 )
          goto LABEL_65;
        v61 = s[2];
        v57 += 2;
        s[v58++ + 3] = v60 + 16 * v59;
      }
      while ( v58 < v61 );
      v55 = s[149];
    }
    v52 = v57 + 1;
    if ( v55 )
    {
      v62 = 0;
      while ( 1 )
      {
        v63 = hex_to_bin(*v52);
        v64 = hex_to_bin(v52[1]);
        if ( v62 == 146 )
          break;
        v65 = s[149];
        v52 += 2;
        s[v62++ + 150] = v64 + 16 * v63;
        if ( v62 >= v65 )
          goto LABEL_42;
      }
LABEL_65:
      __break(0x5512u);
LABEL_66:
      __break(1u);
    }
LABEL_42:
    v66 = _qdf_mem_malloc((unsigned int)(v35 + 1), "hdd_add_wowl_ptrn", 234);
    if ( v91 > 5u || v41 > 0x1F )
      goto LABEL_65;
    v75 = (unsigned int *)(v37 | (8 * v41));
    if ( (unsigned __int64)v75 > 0x5FF )
      goto LABEL_66;
    v34 = v40;
    *(_QWORD *)&v38[8 * v41] = v66;
    if ( !v66 )
      break;
    v76 = *(void **)&v38[8 * v41];
    memcpy(v76, a2, (unsigned int)v35);
    *((_BYTE *)v76 + (unsigned int)v35) = 0;
    s[0] = v41;
    s[1] = 0;
    ++g_hdd_wowl_ptrns_count;
    v77 = ucfg_pmo_add_wow_user_pattern(v40, s);
    if ( v77 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: sme_wowl_add_bcast_pattern failed with error code (%d)",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "hdd_add_wowl_ptrn",
        v77);
      _qdf_mem_free(*(_QWORD *)&v38[8 * v41]);
      v86 = g_hdd_wowl_ptrns_count;
      *(_QWORD *)&v38[8 * v41] = 0;
      g_hdd_wowl_ptrns_count = v86 - 1;
    }
    dump_hdd_wowl_ptrn(s);
LABEL_51:
    _hdd_objmgr_put_vdev_by_user(v34, 0x56u, (__int64)"hdd_add_wowl_ptrn", v51, v43, v44, v45, v46, v47, v48, v49, v50);
    if ( *v52 == 59 )
    {
      v35 = 0;
      a2 = v52 + 1;
      v88 = v52[1];
      if ( v52[1] )
      {
        do
        {
          if ( v88 == 59 )
            break;
          v88 = a2[++v35];
        }
        while ( a2[v35] );
      }
      if ( (int)v35 > 10 )
        continue;
    }
    v15 = (BYTE4(v90) | v90) ^ 1;
    goto LABEL_2;
  }
  v89 = v40;
LABEL_63:
  _hdd_objmgr_put_vdev_by_user(v89, 0x56u, (__int64)"hdd_add_wowl_ptrn", v75, v67, v68, v69, v70, v71, v72, v73, v74);
  v15 = 0;
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return v15 & 1;
}
