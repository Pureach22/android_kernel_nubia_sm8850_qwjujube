__int64 __fastcall dp_addba_resp_tx_completion_wifi3(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        int a5)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 v20; // x8
  unsigned int v21; // w9
  unsigned int v28; // w11
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  __int64 v34; // x23
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x23
  unsigned __int64 StatusReg; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x9
  __int64 v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v72; // w9
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w8
  __int16 v82; // w8
  __int64 v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x8
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x5
  __int64 v110; // x6
  __int64 v111; // x7
  int v112; // w8
  __int64 v113; // x8
  unsigned __int64 v114; // x20
  unsigned __int64 v115; // x23
  __int64 i; // x22
  _BYTE *v117; // x8
  __int64 v118; // x9
  __int64 v119; // x26
  char v120; // w10
  __int64 v121; // x9
  __int64 v122; // x9
  __int64 v123; // x10
  _DWORD *v124; // x8
  __int64 v125; // x0
  __int64 v126; // x1
  unsigned int v128; // w9

  v10 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( v10 )
  {
    v19 = v10;
    if ( *(_DWORD *)(v10 + 408) == 1 )
    {
      v20 = *(_QWORD *)(v10 + 416);
      if ( v20 )
      {
        v21 = *(_DWORD *)(v20 + 40);
        do
        {
          if ( !v21 )
          {
            dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
            goto LABEL_29;
          }
          _X13 = (unsigned int *)(v20 + 40);
          __asm { PRFM            #0x11, [X13] }
          while ( 1 )
          {
            v28 = __ldxr(_X13);
            if ( v28 != v21 )
              break;
            if ( !__stlxr(v21 + 1, _X13) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v28 == v21;
          v21 = v28;
        }
        while ( !_ZF );
        _X8 = (unsigned int *)(v20 + 292);
        __asm { PRFM            #0x11, [X8] }
        do
          v128 = __ldxr(_X8);
        while ( __stxr(v128 + 1, _X8) );
        v34 = *(_QWORD *)(v10 + 416);
        dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
        v19 = v34;
        if ( v34 )
          goto LABEL_17;
        goto LABEL_29;
      }
    }
LABEL_17:
    v43 = *(_QWORD *)(v19 + 88) + 144LL * a4;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v43 + 88);
      if ( a5 )
      {
LABEL_21:
        v53 = *(_QWORD *)(v43 + 32);
        ++*(_DWORD *)(v43 + 20);
        if ( v53 )
          dp_rx_tid_update_wifi3(v19, a4, 1u, 0x1000u, 0, v45, v46, v47, v48, v49, v50, v51, v52);
        v54 = *(_QWORD *)(v43 + 96);
        *(_DWORD *)(v43 + 68) = 0;
        if ( (v54 & 1) != 0 )
        {
          *(_QWORD *)(v43 + 96) = v54 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v43 + 88);
        }
        else
        {
          raw_spin_unlock(v43 + 88);
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: RxTid- %d addba rsp tx completion failed",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "dp_addba_resp_tx_completion_wifi3",
          a4);
        goto LABEL_26;
      }
    }
    else
    {
      raw_spin_lock_bh(v43 + 88);
      *(_QWORD *)(v43 + 96) |= 1uLL;
      if ( a5 )
        goto LABEL_21;
    }
    v72 = *(_DWORD *)(v43 + 68);
    ++*(_DWORD *)(v43 + 16);
    if ( !v72 )
    {
      v83 = *(_QWORD *)(v43 + 96);
      if ( (v83 & 1) != 0 )
      {
        *(_QWORD *)(v43 + 96) = v83 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v43 + 88);
      }
      else
      {
        raw_spin_unlock(v43 + 88);
      }
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: Rx Tid- %d hw qdesc is not in IN_PROGRESS",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "dp_addba_resp_tx_completion_wifi3",
        a1,
        a4);
      goto LABEL_81;
    }
    if ( *(_DWORD *)(v19 + 240) )
    {
      if ( (unsigned int)dp_rx_tid_update_wifi3(
                           v19,
                           a4,
                           *(unsigned __int16 *)(v43 + 72),
                           *(unsigned __int16 *)(v43 + 74),
                           0,
                           v45,
                           v46,
                           v47,
                           v48,
                           v49,
                           v50,
                           v51,
                           v52) )
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Failed update REO SSN",
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          "dp_addba_resp_tx_completion_wifi3");
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: tid %u window_size %u start_seq_num %u",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "dp_addba_resp_tx_completion_wifi3",
        a4,
        *(unsigned __int16 *)(v43 + 72),
        *(unsigned __int16 *)(v43 + 74));
      if ( !*(_WORD *)(v19 + 232) )
      {
        v81 = *(unsigned __int16 *)(v43 + 72);
        if ( (unsigned int)(v81 - 65) > 0xBF )
        {
          if ( (unsigned int)(v81 - 257) > 0x2FF )
            v82 = 64;
          else
            v82 = 1024;
        }
        else
        {
          v82 = 256;
        }
        *(_WORD *)(v19 + 234) = v82;
      }
      *(_DWORD *)(v43 + 68) = 1;
      ++*(_WORD *)(v19 + 232);
      v113 = *(_QWORD *)(v43 + 96);
      if ( (v113 & 1) != 0 )
      {
        *(_QWORD *)(v43 + 96) = v113 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v43 + 88);
        if ( !*(_BYTE *)(v19 + 236) )
          goto LABEL_26;
      }
      else
      {
        raw_spin_unlock(v43 + 88);
        if ( !*(_BYTE *)(v19 + 236) )
          goto LABEL_26;
      }
      v114 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v19 + 24) + 24LL) + 8LL) + 18705LL);
      if ( v114 <= 0x10 )
      {
        v115 = _ReadStatusReg(SP_EL0);
        for ( i = 144LL * (unsigned int)v114 + 120; i != 2568; i += 144 )
        {
          v119 = *(_QWORD *)(v19 + 88);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v115 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v115 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v119 + i - 32);
          }
          else
          {
            raw_spin_lock_bh(v119 + i - 32);
            *(_QWORD *)(v119 + i - 24) |= 1uLL;
          }
          v117 = (_BYTE *)(v119 + i);
          if ( *(unsigned __int16 *)(v119 + i - 48) > 0x40u )
          {
            if ( (unsigned int)(*((_DWORD *)v117 - 13) - 1) > 1 )
            {
              v117 = (_BYTE *)(v119 + i);
            }
            else
            {
              v117 = (_BYTE *)(v119 + i);
              if ( !*(_BYTE *)(v119 + i - 12) )
              {
                v120 = *(v117 - 11);
                v121 = *((_QWORD *)v117 - 3);
                *(v117 - 12) = 1;
                *v117 = 38;
                *(v117 - 11) = v120 + 1;
                if ( (v121 & 1) != 0 )
                {
                  *((_QWORD *)v117 - 3) = v121 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v119 + i - 32);
                }
                else
                {
                  raw_spin_unlock(v119 + i - 32);
                }
                v122 = *(_QWORD *)(v19 + 24);
                v123 = *(_QWORD *)(*(_QWORD *)(v122 + 24) + 8LL);
                v124 = *(_DWORD **)(*(_QWORD *)(v123 + 8) + 168LL);
                if ( v124 )
                {
                  v125 = *(_QWORD *)(v123 + 16);
                  v126 = *(unsigned __int8 *)(v122 + 59);
                  if ( *(v124 - 1) != -1677196783 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD))v124)(
                    v125,
                    v126,
                    v19 + 44,
                    (unsigned int)v114,
                    38,
                    0);
                }
                goto LABEL_57;
              }
            }
          }
          v118 = *((_QWORD *)v117 - 3);
          if ( (v118 & 1) != 0 )
          {
            *((_QWORD *)v117 - 3) = v118 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v119 + i - 32);
          }
          else
          {
            raw_spin_unlock(v119 + i - 32);
          }
LABEL_57:
          LODWORD(v114) = v114 + 1;
        }
      }
      *(_BYTE *)(v19 + 236) = 0;
LABEL_26:
      dp_peer_unref_delete(v19, 7u, v63, v64, v65, v66, v67, v68, v69, v70);
      return 0;
    }
    v100 = *(_QWORD *)(v43 + 96);
    if ( (v100 & 1) != 0 )
    {
      *(_QWORD *)(v43 + 96) = v100 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v43 + 88);
      if ( v19 != -44 )
        goto LABEL_45;
    }
    else
    {
      raw_spin_unlock(v43 + 88);
      if ( v19 != -44 )
      {
LABEL_45:
        v109 = *(unsigned __int8 *)(v19 + 44);
        v110 = *(unsigned __int8 *)(v19 + 45);
        v111 = *(unsigned __int8 *)(v19 + 46);
        v112 = *(unsigned __int8 *)(v19 + 49);
LABEL_80:
        qdf_trace_msg(
          0x81u,
          8u,
          "%s: %pK: default route is not set for peer: %02x:%02x:%02x:**:**:%02x",
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          "dp_addba_resp_tx_completion_wifi3",
          a1,
          v109,
          v110,
          v111,
          v112);
LABEL_81:
        dp_peer_unref_delete(v19, 7u, v92, v93, v94, v95, v96, v97, v98, v99);
        return 16;
      }
    }
    v111 = 0;
    v109 = 0;
    v110 = 0;
    v112 = 0;
    goto LABEL_80;
  }
  if ( a2 )
  {
    v29 = *(unsigned __int8 *)a2;
    v30 = *((unsigned __int8 *)a2 + 1);
    v31 = *((unsigned __int8 *)a2 + 2);
    v32 = *((unsigned __int8 *)a2 + 5);
  }
  else
  {
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v32 = 0;
  }
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "dp_peer_get_tgt_peer_hash_find",
    v29,
    v30,
    v31,
    v32,
    a3);
LABEL_29:
  qdf_trace_msg(
    0x81u,
    8u,
    "%s: %pK: Peer is NULL!",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "dp_addba_resp_tx_completion_wifi3",
    a1);
  return 16;
}
