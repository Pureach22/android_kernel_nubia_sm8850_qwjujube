__int64 __fastcall dp_peer_delete_wifi3(
        _QWORD *a1,
        unsigned int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        int a13)
{
  __int64 v17; // x20
  _DWORD *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  __int64 v32; // x21
  void (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x0
  __int64 v35; // x6
  __int64 v36; // x7
  int v37; // w8
  int v38; // w9
  unsigned __int64 StatusReg; // x8
  __int64 v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x4
  __int64 v50; // x5
  __int64 v51; // x6
  __int64 v52; // x7
  __int64 v53; // x22
  __int64 v54; // x21
  unsigned __int64 v55; // x8
  int v56; // w23
  __int64 v57; // x8
  char v58; // w24
  __int64 v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  const char *v68; // x4
  __int64 v69; // x3
  __int64 v70; // x8
  unsigned __int64 v71; // x8
  __int64 *v72; // x8
  __int64 v73; // x8
  __int64 v74; // [xsp+0h] [xbp-50h]
  __int64 v75; // [xsp+0h] [xbp-50h]
  __int64 v76; // [xsp+8h] [xbp-48h]

  if ( (a13 | 2) != 3 || (v17 = dp_peer_find_hash_find((int)a1, (int)a3)) == 0 )
  {
    if ( (a13 & 0xFFFFFFFE) != 2 )
      goto LABEL_11;
    v18 = (_DWORD *)a1[192];
    if ( !v18 )
      goto LABEL_11;
    if ( *(v18 - 1) != 69695039 )
      __break(0x8228u);
    v17 = ((__int64 (__fastcall *)(_QWORD *, unsigned __int8 *, _QWORD, __int64, _QWORD))v18)(a1, a3, 0, 7, a2);
    if ( !v17 )
    {
LABEL_11:
      qdf_trace_msg(0x3Fu, 8u, "%s: Invalid peer\n", a4, a5, a6, a7, a8, a9, a10, a11, "dp_peer_delete_wifi3");
      return 16;
    }
  }
  if ( (*(_BYTE *)(v17 + 120) & 4) == 0 )
  {
    dp_peer_unref_delete(v17, 7);
    if ( a3 )
    {
      v27 = *a3;
      v28 = a3[1];
      v29 = a3[2];
      v30 = a3[5];
    }
    else
    {
      v29 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Invalid peer: %02x:%02x:%02x:**:**:%02x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "dp_peer_delete_wifi3",
      v27,
      v28,
      v29,
      v30);
    return 6;
  }
  v32 = *(_QWORD *)(v17 + 24);
  if ( !v32 )
  {
    dp_peer_unref_delete(v17, 7);
    return 16;
  }
  *(_BYTE *)(v17 + 120) &= ~4u;
  v33 = *(void (__fastcall **)(_QWORD))(a1[1] + 368LL);
  if ( v33 )
  {
    v34 = *(unsigned __int16 *)(v17 + 16);
    if ( *((_DWORD *)v33 - 1) != 1311034697 )
      __break(0x8228u);
    v33(v34);
  }
  if ( v17 == -44 )
  {
    v37 = 0;
    v35 = 0;
    v36 = 0;
    v38 = 0;
  }
  else
  {
    v35 = *(unsigned __int8 *)(v17 + 44);
    v36 = *(unsigned __int8 *)(v17 + 45);
    v37 = *(unsigned __int8 *)(v17 + 46);
    v38 = *(unsigned __int8 *)(v17 + 49);
  }
  qdf_trace_msg(
    0x7Cu,
    5u,
    "%s: %pK: peer %pK (%02x:%02x:%02x:**:**:%02x) pending-refs %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_peer_delete_wifi3",
    a1,
    v17,
    v35,
    v36,
    v37,
    v38,
    *(_DWORD *)(v17 + 40));
  dp_local_peer_id_free(*(_QWORD *)(*(_QWORD *)(v17 + 24) + 24LL), v17);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v17 + 136);
    v40 = *(_QWORD *)(v17 + 144);
  }
  else
  {
    raw_spin_lock_bh(v17 + 136);
    v40 = *(_QWORD *)(v17 + 144) | 1LL;
    *(_QWORD *)(v17 + 144) = v40;
  }
  *(_DWORD *)(v17 + 124) = 1;
  if ( (v40 & 1) != 0 )
  {
    *(_QWORD *)(v17 + 144) = v40 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v17 + 136);
  }
  else
  {
    raw_spin_unlock(v17 + 136);
  }
  dp_rx_flush_rx_cached(v17, 1);
  dp_peer_multipass_list_remove(v17);
  dp_peer_find_hash_remove(a1, v17);
  dp_peer_vdev_list_remove(a1, v32, v17);
  if ( v17 == -44 )
  {
    v51 = 0;
    v49 = 0;
    v50 = 0;
    v52 = 0;
  }
  else
  {
    v49 = *(unsigned __int8 *)(v17 + 44);
    v50 = *(unsigned __int8 *)(v17 + 45);
    v51 = *(unsigned __int8 *)(v17 + 46);
    v52 = *(unsigned __int8 *)(v17 + 49);
  }
  LODWORD(v74) = *(_DWORD *)(v17 + 408);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: peer %02x:%02x:%02x:**:**:%02x type %d",
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    "dp_peer_mlo_delete",
    v49,
    v50,
    v51,
    v52,
    v74);
  if ( *(_DWORD *)(v17 + 408) == 1 )
  {
    v53 = *(_QWORD *)(v17 + 416);
    if ( v53 )
    {
      v54 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v53 + 24) + 24LL) + 8LL);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v55 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v55 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v55 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v53 + 480);
        if ( !*(_BYTE *)(v53 + 437) )
          goto LABEL_44;
      }
      else
      {
        raw_spin_lock_bh(v53 + 480);
        *(_QWORD *)(v53 + 488) |= 1uLL;
        if ( !*(_BYTE *)(v53 + 437) )
          goto LABEL_44;
      }
      if ( *(_DWORD *)(v17 + 44) == *(_DWORD *)(v53 + 428)
        && *(unsigned __int16 *)(v17 + 48) == *(unsigned __int16 *)(v53 + 432) )
      {
        v56 = 0;
        v57 = v53 + 428;
        goto LABEL_56;
      }
LABEL_44:
      if ( *(_BYTE *)(v53 + 449)
        && *(_DWORD *)(v17 + 44) == *(_DWORD *)(v53 + 440)
        && *(unsigned __int16 *)(v17 + 48) == *(unsigned __int16 *)(v53 + 444) )
      {
        v57 = v53 + 440;
        v56 = 1;
      }
      else if ( *(_BYTE *)(v53 + 461)
             && *(_DWORD *)(v17 + 44) == *(_DWORD *)(v53 + 452)
             && *(unsigned __int16 *)(v17 + 48) == *(unsigned __int16 *)(v53 + 456) )
      {
        v57 = v53 + 452;
        v56 = 2;
      }
      else
      {
        if ( !*(_BYTE *)(v53 + 473)
          || *(_DWORD *)(v17 + 44) != *(_DWORD *)(v53 + 464)
          || *(unsigned __int16 *)(v17 + 48) != *(unsigned __int16 *)(v53 + 468) )
        {
          v58 = *(_BYTE *)(v53 + 476);
          v56 = 4;
          v59 = *(_QWORD *)(v53 + 488);
          if ( (v59 & 1) == 0 )
            goto LABEL_57;
          goto LABEL_73;
        }
        v57 = v53 + 464;
        v56 = 3;
      }
LABEL_56:
      *(_BYTE *)(v57 + 9) = 0;
      v58 = *(_BYTE *)(v53 + 476) - 1;
      *(_BYTE *)(v53 + 476) = v58;
      v59 = *(_QWORD *)(v53 + 488);
      if ( (v59 & 1) == 0 )
      {
LABEL_57:
        raw_spin_unlock(v53 + 480);
        goto LABEL_58;
      }
LABEL_73:
      *(_QWORD *)(v53 + 488) = v59 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v53 + 480);
LABEL_58:
      if ( v56 == 4 )
        v68 = "Failed";
      else
        v68 = "Successful";
      LODWORD(v76) = *(unsigned __int8 *)(v17 + 49);
      LODWORD(v75) = *(unsigned __int8 *)(v17 + 46);
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: %s deletion of link peer %pK (%02x:%02x:%02x:**:**:%02x) from MLD peer %pK (%02x:%02x:%02x:**:**:%02x), idx %u num_links %u",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "dp_mld_peer_del_link_peer",
        v68,
        v17,
        *(unsigned __int8 *)(v17 + 44),
        *(unsigned __int8 *)(v17 + 45),
        v75,
        v76,
        v53,
        *(unsigned __int8 *)(v53 + 44),
        *(unsigned __int8 *)(v53 + 45),
        *(unsigned __int8 *)(v53 + 46),
        *(unsigned __int8 *)(v53 + 49),
        v56,
        *(unsigned __int8 *)(v53 + 476));
      if ( !v58 )
      {
        v70 = *(_QWORD *)(v17 + 416);
        if ( (*(_BYTE *)(v70 + 120) & 4) != 0 )
          dp_peer_delete_wifi3(
            v54,
            *(unsigned __int8 *)(*(_QWORD *)(v70 + 24) + 59LL),
            v70 + 44,
            v69,
            *(unsigned int *)(v70 + 408));
      }
    }
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v71 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v71 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v71 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2367);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2367);
    a1[2368] |= 1uLL;
  }
  *(_QWORD *)(v17 + 248) = 0;
  v72 = (__int64 *)a1[2366];
  *(_QWORD *)(v17 + 256) = v72;
  *v72 = v17;
  v73 = a1[2368];
  a1[2366] = v17 + 248;
  if ( (v73 & 1) != 0 )
  {
    a1[2368] = v73 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2367);
  }
  else
  {
    raw_spin_unlock(a1 + 2367);
  }
  dp_peer_unref_delete(v17, 12);
  dp_peer_unref_delete(v17, 7);
  return 0;
}
