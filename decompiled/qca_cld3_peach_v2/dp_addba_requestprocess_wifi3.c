__int64 __fastcall dp_addba_requestprocess_wifi3(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int16 a5,
        __int64 a6,
        unsigned __int16 a7,
        unsigned __int16 a8)
{
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x19
  __int64 v25; // x8
  unsigned int v26; // w9
  unsigned int v33; // w11
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x7
  __int64 v39; // x25
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x26
  unsigned __int64 StatusReg; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  int v58; // w8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w20
  unsigned __int8 v77; // w20
  __int64 v78; // x28
  unsigned __int16 (__fastcall *v79)(_QWORD); // x8
  unsigned int v80; // w22
  unsigned int v81; // w24
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x24
  unsigned __int16 v107; // w21
  int v108; // w8
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  int v117; // w10
  __int16 v118; // w9
  __int64 v119; // x8
  __int64 v121; // x0
  unsigned int v123; // w9
  unsigned __int16 v124; // [xsp+2Ch] [xbp-4h]

  v15 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( v15 )
  {
    v24 = v15;
    if ( *(_DWORD *)(v15 + 408) != 1 )
      goto LABEL_17;
    v25 = *(_QWORD *)(v15 + 416);
    if ( !v25 )
      goto LABEL_17;
    v26 = *(_DWORD *)(v25 + 40);
    do
    {
      if ( !v26 )
      {
        dp_peer_unref_delete(v15, 7u, v16, v17, v18, v19, v20, v21, v22, v23);
        goto LABEL_32;
      }
      _X13 = (unsigned int *)(v25 + 40);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v33 = __ldxr(_X13);
        if ( v33 != v26 )
          break;
        if ( !__stlxr(v26 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v33 == v26;
      v26 = v33;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v25 + 292);
    __asm { PRFM            #0x11, [X8] }
    do
      v123 = __ldxr(_X8);
    while ( __stxr(v123 + 1, _X8) );
    v39 = *(_QWORD *)(v15 + 416);
    dp_peer_unref_delete(v15, 7u, v16, v17, v18, v19, v20, v21, v22, v23);
    v24 = v39;
    if ( v39 )
    {
LABEL_17:
      v48 = *(_QWORD *)(v24 + 88) + 144LL * a5;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v48 + 88);
      }
      else
      {
        raw_spin_lock_bh(v48 + 88);
        *(_QWORD *)(v48 + 96) |= 1uLL;
      }
      v58 = *(_DWORD *)(v48 + 68);
      ++*(_DWORD *)(v48 + 4);
      if ( v58 == 1 )
      {
        if ( !*(_QWORD *)(v48 + 32) )
          goto LABEL_27;
        dp_rx_tid_update_wifi3(v24, a5, 1u, 0x1000u, 0, v50, v51, v52, v53, v54, v55, v56, v57);
        *(_DWORD *)(v48 + 68) = 0;
        --*(_WORD *)(v24 + 232);
        qdf_trace_msg(
          0x81u,
          8u,
          "%s: %pK: Rx Tid- %d hw qdesc is already setup",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "dp_addba_requestprocess_wifi3",
          a1,
          a5);
        v58 = *(_DWORD *)(v48 + 68);
      }
      if ( v58 == 2 )
      {
        v67 = *(_QWORD *)(v48 + 96);
        if ( (v67 & 1) == 0 )
        {
LABEL_26:
          raw_spin_unlock(v48 + 88);
          v76 = 16;
LABEL_58:
          dp_peer_unref_delete(v24, 7u, v68, v69, v70, v71, v72, v73, v74, v75);
          return v76;
        }
LABEL_52:
        *(_QWORD *)(v48 + 96) = v67 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v48 + 88);
        v76 = 16;
        goto LABEL_58;
      }
LABEL_27:
      v124 = a8;
      v77 = a4;
      if ( *(_WORD *)(v48 + 122) )
      {
        if ( *(_WORD *)(v48 + 122) == 1 )
        {
          qdf_trace_msg(
            0x81u,
            5u,
            "%s: %pK: disable BA session",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "dp_addba_requestprocess_wifi3",
            a1);
          a7 = 1;
        }
        else
        {
          qdf_trace_msg(
            0x81u,
            5u,
            "%s: %pK: override BA win to %d",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "dp_addba_requestprocess_wifi3",
            a1);
          a7 = *(_WORD *)(v48 + 122);
        }
      }
      else
      {
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: %pK: restore BA win %d based on addba req",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "dp_addba_requestprocess_wifi3",
          a1,
          a7);
      }
      v78 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v24 + 24) + 24LL) + 8LL);
      v79 = *(unsigned __int16 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v78 + 1128) + 74392LL) + 1160LL);
      if ( *((_DWORD *)v79 - 1) != 769334334 )
        __break(0x8228u);
      v80 = a7;
      v81 = v79(a5);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Input buffersize %d, max dp allowed %d",
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        "dp_check_ba_buffersize",
        v80,
        v81);
      if ( v80 >= v81 )
        v80 = v81;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: %02x:%02x:%02x:**:**:%02x per_tid_basize_max_tid %d tid %d buffersize %d hw_buffer_size %d",
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        "dp_check_ba_buffersize",
        *(unsigned __int8 *)(v24 + 44),
        *(unsigned __int8 *)(v24 + 45),
        *(unsigned __int8 *)(v24 + 46),
        *(unsigned __int8 *)(v24 + 49),
        *(unsigned __int8 *)(v78 + 18705),
        a5,
        v80,
        *(unsigned __int16 *)(v24 + 234));
      v106 = *(_QWORD *)(v24 + 88) + 144LL * a5;
      if ( *(unsigned __int8 *)(v78 + 18705) > (unsigned int)a5 )
      {
        v107 = v124;
        *(_WORD *)(v106 + 72) = v80;
        goto LABEL_50;
      }
      v107 = v124;
      if ( !*(_WORD *)(v24 + 232) )
        goto LABEL_49;
      v108 = *(unsigned __int16 *)(v24 + 234);
      if ( v108 == 256 )
      {
        *(_WORD *)(v106 + 72) = v80;
        if ( v80 <= 0x40 )
        {
          *(_WORD *)(v24 + 234) = 64;
          *(_BYTE *)(v24 + 236) = 1;
        }
      }
      else
      {
        if ( v108 == 64 )
        {
          if ( v80 > 0x40 )
          {
            *(_WORD *)(v106 + 72) = 64;
            goto LABEL_50;
          }
          goto LABEL_49;
        }
        if ( v80 <= 0x400 )
        {
LABEL_49:
          *(_WORD *)(v106 + 72) = v80;
          goto LABEL_50;
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Invalid buffer size %d",
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "dp_check_ba_buffersize",
          v80);
        v121 = printk(
                 &unk_AAA255,
                 "0",
                 "dp_check_ba_buffersize",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_tid.c");
        dump_stack(v121);
      }
LABEL_50:
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: rx_tid->ba_win_size %d peer->hw_buffer_size %d peer->kill_256_sessions %d",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "dp_check_ba_buffersize",
        *(unsigned __int16 *)(v106 + 72),
        *(unsigned __int16 *)(v24 + 234),
        *(unsigned __int8 *)(v24 + 236));
      if ( !(unsigned int)dp_rx_tid_setup_wifi3(
                            v24,
                            1LL << a5,
                            *(unsigned __int16 *)(v48 + 72),
                            v107,
                            v109,
                            v110,
                            v111,
                            v112,
                            v113,
                            v114,
                            v115,
                            v116) )
      {
        v117 = *(unsigned __int16 *)(v48 + 122);
        *(_WORD *)(v48 + 76) = v77;
        v118 = *(_WORD *)(v48 + 80);
        *(_DWORD *)(v48 + 68) = 2;
        v119 = *(_QWORD *)(v48 + 96);
        if ( v117 == 1 )
          v118 = 37;
        *(_WORD *)(v48 + 74) = v107;
        *(_WORD *)(v48 + 78) = v118;
        if ( (v119 & 1) != 0 )
        {
          *(_QWORD *)(v48 + 96) = v119 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v48 + 88);
        }
        else
        {
          raw_spin_unlock(v48 + 88);
        }
        v76 = 0;
        goto LABEL_58;
      }
      v67 = *(_QWORD *)(v48 + 96);
      *(_DWORD *)(v48 + 68) = 0;
      if ( (v67 & 1) == 0 )
        goto LABEL_26;
      goto LABEL_52;
    }
  }
  else
  {
    if ( a2 )
    {
      v34 = *(unsigned __int8 *)a2;
      v35 = *((unsigned __int8 *)a2 + 1);
      v36 = *((unsigned __int8 *)a2 + 2);
      v37 = *((unsigned __int8 *)a2 + 5);
    }
    else
    {
      v36 = 0;
      v34 = 0;
      v35 = 0;
      v37 = 0;
    }
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_peer_get_tgt_peer_hash_find",
      v34,
      v35,
      v36,
      v37,
      a3);
  }
LABEL_32:
  qdf_trace_msg(
    0x81u,
    8u,
    "%s: %pK: Peer is NULL!",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "dp_addba_requestprocess_wifi3",
    a1);
  return 16;
}
