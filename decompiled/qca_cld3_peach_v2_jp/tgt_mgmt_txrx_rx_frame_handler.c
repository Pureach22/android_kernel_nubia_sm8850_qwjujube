__int64 __fastcall tgt_mgmt_txrx_rx_frame_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *v13; // x24
  __int16 v15; // w26
  __int64 result; // x0
  unsigned __int8 v17; // w27
  int v18; // w23
  unsigned __int8 *v19; // x22
  _BOOL4 v20; // w28
  const char *v21; // x2
  unsigned int v22; // w1
  __int64 v23; // x4
  int v24; // w8
  _BOOL4 v25; // w9
  __int64 v26; // x21
  int v27; // w9
  int v28; // w10
  int v29; // w11
  int v30; // w10
  int v31; // w12
  __int64 v32; // x9
  unsigned __int8 *v33; // x11
  unsigned int v34; // w28
  __int64 v35; // x8
  unsigned __int8 *v36; // x25
  unsigned __int16 v37; // w13
  __int64 v38; // x22
  int v39; // w28
  __int64 v41; // x8
  unsigned int v42; // w25
  __int64 comp_private_obj; // x0
  __int64 v44; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v46; // x28
  _QWORD *v47; // x25
  _QWORD *v48; // x22
  _QWORD *v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _QWORD *v58; // x26
  unsigned int v59; // w26
  unsigned int frm_type; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x6
  __int64 v70; // x7
  int v71; // w8
  int v72; // w9
  __int64 v73; // x21
  __int64 v74; // x8
  __int64 v75; // x0
  unsigned int v76; // w0
  unsigned int v77; // w20
  __int64 v78; // x21
  __int64 v79; // x8
  __int64 peer; // x22
  __int64 v81; // x0
  _DWORD *v82; // x8
  _DWORD *v83; // x8
  unsigned int v84; // w19
  __int64 v85; // x0
  __int64 v86; // x20
  int v87; // w9
  int v88; // w10
  int v89; // w11
  void *v90; // x0
  const void *v91; // x1
  __int64 v92; // [xsp+0h] [xbp-70h]
  __int64 v93; // [xsp+8h] [xbp-68h]
  __int64 v94; // [xsp+10h] [xbp-60h]
  __int64 v95; // [xsp+18h] [xbp-58h]
  unsigned int v96; // [xsp+30h] [xbp-40h]
  int v97; // [xsp+34h] [xbp-3Ch]
  __int16 v98; // [xsp+34h] [xbp-3Ch]
  _BOOL4 v99; // [xsp+34h] [xbp-3Ch]
  unsigned __int8 *v100; // [xsp+38h] [xbp-38h]
  unsigned __int8 *v101; // [xsp+40h] [xbp-30h]
  unsigned __int16 v102; // [xsp+40h] [xbp-30h]
  __int64 v103; // [xsp+40h] [xbp-30h]
  _QWORD *v104; // [xsp+48h] [xbp-28h] BYREF
  _QWORD v105[4]; // [xsp+50h] [xbp-20h] BYREF

  v105[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v104 = nullptr;
  v105[0] = 0;
  if ( !a2 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: buffer passed is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "tgt_mgmt_txrx_rx_frame_handler");
    result = 4;
    goto LABEL_45;
  }
  if ( !a1 )
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: psoc_ctx passed is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "tgt_mgmt_txrx_rx_frame_handler");
    _qdf_nbuf_free(a2);
    result = 4;
    goto LABEL_45;
  }
  v13 = *(unsigned __int8 **)(a2 + 224);
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v15 = *(_WORD *)(a2 + 66);
  else
    v15 = 0;
  v17 = *v13;
  v18 = *v13 & 0xC;
  if ( (*v13 & 8 | 4) != 4 )
  {
    v21 = "%s: Rx event doesn't contain a mgmt/ctrl packet, %d";
    v22 = 2;
    v23 = *v13 & 0xC;
LABEL_12:
    qdf_trace_msg(0x4Bu, v22, v21, a4, a5, a6, a7, a8, a9, a10, a11, "tgt_mgmt_txrx_rx_frame_handler", v23);
LABEL_44:
    _qdf_nbuf_free(a2);
    result = 16;
    goto LABEL_45;
  }
  v19 = v13 + 10;
  v20 = (v13[10] & 1) == 0 && (*(_DWORD *)(v13 + 10) | *((unsigned __int16 *)v13 + 7)) != 0;
  v24 = v13[16];
  if ( (v24 & 1) != 0 )
  {
    v25 = 0;
    if ( !v20 )
    {
LABEL_16:
      v26 = jiffies;
      if ( tgt_mgmt_txrx_rx_frame_handler___last_ticks - jiffies + 125 < 0 )
      {
        if ( v13 == (unsigned __int8 *)-16LL )
        {
          v28 = 0;
          v24 = 0;
          v27 = 0;
          v29 = 0;
        }
        else
        {
          v27 = v13[17];
          v28 = v13[18];
          v29 = v13[21];
        }
        qdf_trace_msg(
          0x4Bu,
          8u,
          "%s: from addr %02x:%02x:%02x:**:**:%02x bssid addr %02x:%02x:%02x:**:**:%02x both not valid, dropping them",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "tgt_mgmt_txrx_rx_frame_handler",
          v24,
          v27,
          v28,
          v29);
        tgt_mgmt_txrx_rx_frame_handler___last_ticks = v26;
      }
      goto LABEL_44;
    }
  }
  else
  {
    v25 = (*((_DWORD *)v13 + 4) | *((unsigned __int16 *)v13 + 10)) != 0;
    if ( !v20 && !v25 )
      goto LABEL_16;
  }
  v30 = *(_DWORD *)(a2 + 112);
  v31 = v17 & 0xF0;
  if ( (*v13 & 0xC) == 0 && (v31 == 128 || v31 == 80) && (!v20 || !v25) )
  {
    v97 = *(_DWORD *)(a2 + 112);
    if ( tgt_mgmt_txrx_rx_frame_handler___last_ticks_9 - jiffies + 125 < 0 )
    {
      v103 = jiffies;
      if ( v13 == (unsigned __int8 *)-16LL )
      {
        v88 = 0;
        v24 = 0;
        v87 = 0;
        v89 = 0;
      }
      else
      {
        v87 = v13[17];
        v88 = v13[18];
        v89 = v13[21];
      }
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: from addr %02x:%02x:%02x:**:**:%02x bssid addr %02x:%02x:%02x:**:**:%02x not valid, modifying them",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "tgt_mgmt_txrx_rx_frame_handler",
        v24,
        v87,
        v88,
        v89);
      tgt_mgmt_txrx_rx_frame_handler___last_ticks_9 = v103;
    }
    if ( v20 )
    {
      v90 = v13 + 16;
      v91 = v13 + 10;
    }
    else
    {
      v90 = v13 + 10;
      v91 = v13 + 16;
    }
    qdf_mem_copy(v90, v91, 6u);
    v31 = v17 & 0xF0;
    LOWORD(v30) = v97;
  }
  v32 = *(_QWORD *)(a2 + 224);
  v33 = v13 + 4;
  v100 = v13 + 4;
  v34 = v13[1];
  if ( (char)v13[1] < 0 )
  {
    v38 = jiffies;
    v36 = (unsigned __int8 *)(v32 + 28);
    if ( tgt_mgmt_txrx_rx_frame_handler___last_ticks_11 - jiffies + 125 < 0 )
    {
      v39 = v31;
      v98 = v30;
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: HT control field present!",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "tgt_mgmt_txrx_rx_frame_handler");
      LOWORD(v30) = v98;
      v31 = v39;
      tgt_mgmt_txrx_rx_frame_handler___last_ticks_11 = v38;
      v33 = v13 + 4;
      v34 = v13[1];
    }
    v19 = v13 + 10;
    v35 = 4;
    v37 = v30 + v15;
    if ( (v34 & 0x40) == 0 )
      goto LABEL_48;
  }
  else
  {
    v35 = 0;
    v36 = (unsigned __int8 *)(v32 + 24);
    v37 = v30 + v15;
    if ( (v34 & 0x40) == 0 )
      goto LABEL_48;
  }
  if ( (*v33 & 1) != 0 )
    goto LABEL_48;
  if ( *(_DWORD *)v33 == -1 && *((__int16 *)v33 + 2) == -1 )
    goto LABEL_48;
  if ( v37 < 0x1Du || (v41 = (__int64)&v13[v35 + 24]) == 0 )
  {
    if ( v37 <= 0x1Cu )
      goto LABEL_44;
    goto LABEL_47;
  }
  if ( (*(_BYTE *)(v41 + 3) & 0x20) == 0 )
  {
LABEL_47:
    v36 += 4;
    goto LABEL_48;
  }
  if ( v37 <= 0x20u )
    goto LABEL_44;
  v36 += 8;
LABEL_48:
  if ( v18 )
  {
    v42 = 123;
    v99 = v31 == 128;
  }
  else
  {
    v102 = v37;
    v59 = v31;
    frm_type = mgmt_txrx_get_frm_type(v31, v36);
    if ( frm_type == -1 )
    {
      v78 = jiffies;
      if ( tgt_mgmt_txrx_rx_frame_handler___last_ticks_13 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Bu,
          8u,
          "%s: Unspecified mgmt frame type fc: %x %x",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "tgt_mgmt_txrx_rx_frame_handler",
          *v13,
          v34);
        tgt_mgmt_txrx_rx_frame_handler___last_ticks_13 = v78;
      }
      goto LABEL_44;
    }
    v42 = frm_type;
    v99 = v59 == 128;
    if ( v59 != 128 && (v17 & 0xE0) != 0x40 )
    {
      if ( v19 )
      {
        v69 = v13[10];
        v70 = v13[11];
        v71 = v13[12];
        v72 = v13[15];
      }
      else
      {
        v71 = 0;
        v69 = 0;
        v70 = 0;
        v72 = 0;
      }
      LODWORD(v95) = *(_DWORD *)(a3 + 36);
      LODWORD(v94) = *((unsigned __int16 *)v13 + 11) >> 4;
      LODWORD(v93) = v72;
      LODWORD(v92) = v71;
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: Rcvd mgmt frame subtype %x (frame type %u) from %02x:%02x:%02x:**:**:%02x, seq_num = %d, rssi = %d tsf_delta: %u",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "tgt_mgmt_txrx_rx_frame_handler",
        v59,
        frm_type,
        v69,
        v70,
        v92,
        v93,
        v94,
        v95,
        *(_DWORD *)(a3 + 40));
    }
    if ( (*(_BYTE *)(a3 + 28) & 0xB9) != 0 )
    {
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: Current PN=0x%llx Previous PN=0x%llx. Packet dumped below",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "tgt_mgmt_txrx_rx_frame_handler",
        *(_QWORD *)(a3 + 64),
        *(_QWORD *)(a3 + 72));
      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(75, 8, v13, v102);
    }
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 1);
  v44 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1120);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 1120);
    *(_QWORD *)(v44 + 1128) |= 1uLL;
  }
  v46 = *(_QWORD *)(v44 + 8LL * v42 + 8);
  if ( v46 )
  {
    v96 = v42;
    v47 = nullptr;
    v101 = v19;
    v48 = nullptr;
    do
    {
      v49 = qdf_mem_malloc_atomic_fl(0x18u, (__int64)"wlan_mgmt_txrx_rx_handler_list_copy", 0x535u);
      if ( !v49 )
      {
        v105[0] = v47;
        v73 = jiffies;
        if ( wlan_mgmt_txrx_rx_handler_list_copy___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Bu,
            2u,
            "%s: Couldn't allocate memory for rx handler node",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "wlan_mgmt_txrx_rx_handler_list_copy");
          wlan_mgmt_txrx_rx_handler_list_copy___last_ticks = v73;
        }
        v74 = *(_QWORD *)(v44 + 1128);
        if ( (v74 & 1) != 0 )
        {
          *(_QWORD *)(v44 + 1128) = v74 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v44 + 1120);
        }
        else
        {
          raw_spin_unlock(v44 + 1120);
        }
        _qdf_nbuf_free(a2);
        result = 2;
        goto LABEL_103;
      }
      v58 = v49;
      *(_DWORD *)v49 = *(_DWORD *)v46;
      v49[1] = *(_QWORD *)(v46 + 8);
      v49[2] = 0;
      if ( v47 )
      {
        v58 = v47;
        v48[2] = v49;
      }
      v46 = *(_QWORD *)(v46 + 16);
      v48 = v49;
      v47 = v58;
    }
    while ( v46 );
    v19 = v101;
    v42 = v96;
    v104 = v49;
    v105[0] = v58;
    if ( v18 )
      goto LABEL_79;
  }
  else
  {
    v58 = nullptr;
    if ( v18 )
      goto LABEL_79;
  }
  v75 = *(_QWORD *)(v44 + 984);
  if ( v75 )
  {
    v76 = wlan_mgmt_txrx_rx_handler_list_copy(v75, v105, &v104);
    if ( v76 )
    {
      v77 = v76;
      qdf_spin_unlock_bh_1(v44 + 1120);
      _qdf_nbuf_free(a2);
      result = v77;
      goto LABEL_103;
    }
    v58 = (_QWORD *)v105[0];
  }
LABEL_79:
  v79 = *(_QWORD *)(v44 + 1128);
  if ( !v58 )
  {
    if ( (v79 & 1) != 0 )
    {
      *(_QWORD *)(v44 + 1128) = v79 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v44 + 1120);
    }
    else
    {
      raw_spin_unlock(v44 + 1120);
    }
    v21 = "%s: No rx callback registered for frm_type: %d";
    v22 = 8;
    v23 = v42;
    goto LABEL_12;
  }
  if ( (v79 & 1) != 0 )
  {
    *(_QWORD *)(v44 + 1128) = v79 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v44 + 1120);
    if ( v99 )
      goto LABEL_82;
LABEL_83:
    peer = wlan_objmgr_get_peer(a1, *(unsigned __int8 *)(a3 + 48), v19, 3);
    if ( !peer )
    {
      if ( (qdf_is_macaddr_broadcast(v100) & 1) != 0 )
        peer = 0;
      else
        peer = wlan_objmgr_get_peer(a1, *(unsigned __int8 *)(a3 + 48), v100, 3);
    }
    while ( v58[2] )
    {
      v81 = _qdf_nbuf_clone(a2);
      if ( v81 )
      {
        v82 = (_DWORD *)v58[1];
        if ( *(v82 - 1) != -1994098867 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))v82)(a1, peer, v81, a3, v42);
      }
      v58 = (_QWORD *)v58[2];
    }
    v83 = (_DWORD *)v58[1];
    if ( *(v83 - 1) != -1994098867 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))v83)(a1, peer, a2, a3, v42);
    if ( peer )
      wlan_objmgr_peer_release_ref(peer, 3);
    result = 0;
    goto LABEL_103;
  }
  raw_spin_unlock(v44 + 1120);
  if ( !v99 )
    goto LABEL_83;
LABEL_82:
  if ( *(_BYTE *)(a3 + 89) || !(unsigned int)wlan_mgmt_rx_beacon_rate_limit(a1, a3) )
    goto LABEL_83;
  _qdf_nbuf_free(a2);
  result = 1;
LABEL_103:
  if ( v105[0] )
  {
    v84 = result;
    v85 = v105[0];
    do
    {
      v86 = *(_QWORD *)(v85 + 16);
      _qdf_mem_free(v85);
      v85 = v86;
    }
    while ( v86 );
    result = v84;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
