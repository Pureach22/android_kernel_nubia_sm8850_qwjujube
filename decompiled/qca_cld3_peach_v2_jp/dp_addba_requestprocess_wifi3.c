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
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w27
  __int64 v23; // x26
  __int64 v24; // x19
  unsigned __int64 StatusReg; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w20
  unsigned __int8 v53; // w20
  int v54; // w24
  __int64 v55; // x0
  __int64 v56; // x28
  unsigned __int16 (__fastcall *v57)(_QWORD); // x8
  unsigned int v58; // w22
  unsigned int v59; // w23
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x24
  unsigned __int16 v85; // w21
  int v86; // w8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // w10
  __int16 v96; // w9
  __int64 v97; // x8
  __int64 v99; // x0
  unsigned __int16 v100; // [xsp+2Ch] [xbp-4h]

  v13 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( v13 )
  {
    v22 = a5;
    v23 = *(_QWORD *)(v13 + 88) + 144LL * a5;
    v24 = v13;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v23 + 88);
    }
    else
    {
      raw_spin_lock_bh(v23 + 88);
      *(_QWORD *)(v23 + 96) |= 1uLL;
    }
    v34 = *(_DWORD *)(v23 + 68);
    ++*(_DWORD *)(v23 + 4);
    if ( v34 == 1 )
    {
      if ( !*(_QWORD *)(v23 + 32) )
        goto LABEL_13;
      dp_rx_tid_update_wifi3(v24, a5, 1u, 0x1000u, 0);
      *(_DWORD *)(v23 + 68) = 0;
      --*(_WORD *)(v24 + 224);
      qdf_trace_msg(
        0x81u,
        8u,
        "%s: %pK: Rx Tid- %d hw qdesc is already setup",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "dp_addba_requestprocess_wifi3",
        a1,
        a5);
      v34 = *(_DWORD *)(v23 + 68);
    }
    if ( v34 == 2 )
    {
      v43 = *(_QWORD *)(v23 + 96);
      if ( (v43 & 1) == 0 )
      {
LABEL_11:
        raw_spin_unlock(v23 + 88);
        v52 = 16;
LABEL_41:
        dp_peer_unref_delete(v24, 7u, v44, v45, v46, v47, v48, v49, v50, v51);
        return v52;
      }
LABEL_35:
      *(_QWORD *)(v23 + 96) = v43 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v23 + 88);
      v52 = 16;
      goto LABEL_41;
    }
LABEL_13:
    v100 = a8;
    v53 = a4;
    if ( *(_WORD *)(v23 + 122) )
    {
      if ( *(_WORD *)(v23 + 122) == 1 )
      {
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: %pK: disable BA session",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
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
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "dp_addba_requestprocess_wifi3",
          a1);
        a7 = *(_WORD *)(v23 + 122);
      }
    }
    else
    {
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: %pK: restore BA win %d based on addba req",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "dp_addba_requestprocess_wifi3",
        a1,
        a7);
    }
    v54 = a5;
    v55 = a5;
    v56 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v24 + 24) + 24LL) + 8LL);
    v57 = *(unsigned __int16 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v56 + 1128) + 74392LL) + 1160LL);
    if ( *((_DWORD *)v57 - 1) != 769334334 )
      __break(0x8228u);
    v58 = a7;
    v59 = v57(v55);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Input buffersize %d, max dp allowed %d",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "dp_check_ba_buffersize",
      v58,
      v59);
    if ( v58 >= v59 )
      v58 = v59;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: %02x:%02x:%02x:**:**:%02x per_tid_basize_max_tid %d tid %d buffersize %d hw_buffer_size %d",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "dp_check_ba_buffersize",
      *(unsigned __int8 *)(v24 + 44),
      *(unsigned __int8 *)(v24 + 45),
      *(unsigned __int8 *)(v24 + 46),
      *(unsigned __int8 *)(v24 + 49),
      *(unsigned __int8 *)(v56 + 18649),
      v54,
      v58,
      *(unsigned __int16 *)(v24 + 226));
    v84 = *(_QWORD *)(v24 + 88) + 144LL * v22;
    if ( *(unsigned __int8 *)(v56 + 18649) > v22 )
    {
      v85 = v100;
      *(_WORD *)(v84 + 72) = v58;
      goto LABEL_33;
    }
    v85 = v100;
    if ( !*(_WORD *)(v24 + 224) )
      goto LABEL_32;
    v86 = *(unsigned __int16 *)(v24 + 226);
    if ( v86 == 256 )
    {
      *(_WORD *)(v84 + 72) = v58;
      if ( v58 <= 0x40 )
      {
        *(_WORD *)(v24 + 226) = 64;
        *(_BYTE *)(v24 + 228) = 1;
      }
    }
    else
    {
      if ( v86 == 64 )
      {
        if ( v58 > 0x40 )
        {
          *(_WORD *)(v84 + 72) = 64;
          goto LABEL_33;
        }
        goto LABEL_32;
      }
      if ( v58 <= 0x400 )
      {
LABEL_32:
        *(_WORD *)(v84 + 72) = v58;
        goto LABEL_33;
      }
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Invalid buffer size %d",
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        "dp_check_ba_buffersize",
        v58);
      v99 = printk(
              &unk_9BB309,
              "0",
              "dp_check_ba_buffersize",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_tid.c");
      dump_stack(v99);
    }
LABEL_33:
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: rx_tid->ba_win_size %d peer->hw_buffer_size %d peer->kill_256_sessions %d",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "dp_check_ba_buffersize",
      *(unsigned __int16 *)(v84 + 72),
      *(unsigned __int16 *)(v24 + 226),
      *(unsigned __int8 *)(v24 + 228));
    if ( !(unsigned int)dp_rx_tid_setup_wifi3(
                          v24,
                          1LL << v22,
                          *(unsigned __int16 *)(v23 + 72),
                          v85,
                          v87,
                          v88,
                          v89,
                          v90,
                          v91,
                          v92,
                          v93,
                          v94) )
    {
      v95 = *(unsigned __int16 *)(v23 + 122);
      *(_WORD *)(v23 + 76) = v53;
      v96 = *(_WORD *)(v23 + 80);
      *(_DWORD *)(v23 + 68) = 2;
      v97 = *(_QWORD *)(v23 + 96);
      if ( v95 == 1 )
        v96 = 37;
      *(_WORD *)(v23 + 74) = v85;
      *(_WORD *)(v23 + 78) = v96;
      if ( (v97 & 1) != 0 )
      {
        *(_QWORD *)(v23 + 96) = v97 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v23 + 88);
      }
      else
      {
        raw_spin_unlock(v23 + 88);
      }
      v52 = 0;
      goto LABEL_41;
    }
    v43 = *(_QWORD *)(v23 + 96);
    *(_DWORD *)(v23 + 68) = 0;
    if ( (v43 & 1) == 0 )
      goto LABEL_11;
    goto LABEL_35;
  }
  qdf_trace_msg(
    0x81u,
    8u,
    "%s: %pK: Peer is NULL!",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "dp_addba_requestprocess_wifi3",
    a1);
  return 16;
}
