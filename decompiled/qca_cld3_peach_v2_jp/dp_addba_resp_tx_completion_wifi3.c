__int64 __fastcall dp_addba_resp_tx_completion_wifi3(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        int a5)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  __int64 v18; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x9
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v39; // w9
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  int v48; // w8
  __int16 v49; // w8
  __int64 v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
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
  __int64 v76; // x8
  unsigned __int64 v77; // x20
  unsigned __int64 v78; // x23
  __int64 i; // x22
  _BYTE *v80; // x8
  __int64 v81; // x9
  __int64 v82; // x26
  char v83; // w10
  __int64 v84; // x9
  __int64 v85; // x9
  __int64 v86; // x10
  _DWORD *v87; // x8
  __int64 v88; // x0
  __int64 v89; // x1

  v8 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( v8 )
  {
    v17 = *(_QWORD *)(v8 + 88) + 144LL * a4;
    v18 = v8;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v17 + 88);
      if ( a5 )
      {
LABEL_6:
        v20 = *(_QWORD *)(v17 + 32);
        ++*(_DWORD *)(v17 + 20);
        if ( v20 )
          dp_rx_tid_update_wifi3(v18, a4, 1u, 0x1000u, 0);
        v21 = *(_QWORD *)(v17 + 96);
        *(_DWORD *)(v17 + 68) = 0;
        if ( (v21 & 1) != 0 )
        {
          *(_QWORD *)(v17 + 96) = v21 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v17 + 88);
        }
        else
        {
          raw_spin_unlock(v17 + 88);
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: RxTid- %d addba rsp tx completion failed",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "dp_addba_resp_tx_completion_wifi3",
          a4);
        goto LABEL_11;
      }
    }
    else
    {
      raw_spin_lock_bh(v17 + 88);
      *(_QWORD *)(v17 + 96) |= 1uLL;
      if ( a5 )
        goto LABEL_6;
    }
    v39 = *(_DWORD *)(v17 + 68);
    ++*(_DWORD *)(v17 + 16);
    if ( v39 )
    {
      if ( *(_DWORD *)(v18 + 232) )
      {
        if ( (unsigned int)dp_rx_tid_update_wifi3(
                             v18,
                             a4,
                             *(unsigned __int16 *)(v17 + 72),
                             *(unsigned __int16 *)(v17 + 74),
                             0) )
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Failed update REO SSN",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "dp_addba_resp_tx_completion_wifi3");
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: tid %u window_size %u start_seq_num %u",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "dp_addba_resp_tx_completion_wifi3",
          a4,
          *(unsigned __int16 *)(v17 + 72),
          *(unsigned __int16 *)(v17 + 74));
        if ( !*(_WORD *)(v18 + 224) )
        {
          v48 = *(unsigned __int16 *)(v17 + 72);
          if ( (unsigned int)(v48 - 65) > 0xBF )
          {
            if ( (unsigned int)(v48 - 257) > 0x2FF )
              v49 = 64;
            else
              v49 = 1024;
          }
          else
          {
            v49 = 256;
          }
          *(_WORD *)(v18 + 226) = v49;
        }
        *(_DWORD *)(v17 + 68) = 1;
        ++*(_WORD *)(v18 + 224);
        v76 = *(_QWORD *)(v17 + 96);
        if ( (v76 & 1) != 0 )
        {
          *(_QWORD *)(v17 + 96) = v76 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v17 + 88);
          if ( !*(_BYTE *)(v18 + 228) )
            goto LABEL_11;
        }
        else
        {
          raw_spin_unlock(v17 + 88);
          if ( !*(_BYTE *)(v18 + 228) )
            goto LABEL_11;
        }
        v77 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v18 + 24) + 24LL) + 8LL) + 18649LL);
        if ( v77 <= 0x10 )
        {
          v78 = _ReadStatusReg(SP_EL0);
          for ( i = 144LL * (unsigned int)v77 + 120; i != 2568; i += 144 )
          {
            v82 = *(_QWORD *)(v18 + 88);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v78 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v78 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v82 + i - 32);
            }
            else
            {
              raw_spin_lock_bh(v82 + i - 32);
              *(_QWORD *)(v82 + i - 24) |= 1uLL;
            }
            v80 = (_BYTE *)(v82 + i);
            if ( *(unsigned __int16 *)(v82 + i - 48) > 0x40u )
            {
              if ( (unsigned int)(*((_DWORD *)v80 - 13) - 1) > 1 )
              {
                v80 = (_BYTE *)(v82 + i);
              }
              else
              {
                v80 = (_BYTE *)(v82 + i);
                if ( !*(_BYTE *)(v82 + i - 12) )
                {
                  v83 = *(v80 - 11);
                  v84 = *((_QWORD *)v80 - 3);
                  *(v80 - 12) = 1;
                  *v80 = 38;
                  *(v80 - 11) = v83 + 1;
                  if ( (v84 & 1) != 0 )
                  {
                    *((_QWORD *)v80 - 3) = v84 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(v82 + i - 32);
                  }
                  else
                  {
                    raw_spin_unlock(v82 + i - 32);
                  }
                  v85 = *(_QWORD *)(v18 + 24);
                  v86 = *(_QWORD *)(*(_QWORD *)(v85 + 24) + 8LL);
                  v87 = *(_DWORD **)(*(_QWORD *)(v86 + 8) + 168LL);
                  if ( v87 )
                  {
                    v88 = *(_QWORD *)(v86 + 16);
                    v89 = *(unsigned __int8 *)(v85 + 59);
                    if ( *(v87 - 1) != -1677196783 )
                      __break(0x8228u);
                    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD))v87)(
                      v88,
                      v89,
                      v18 + 44,
                      (unsigned int)v77,
                      38,
                      0);
                  }
                  goto LABEL_42;
                }
              }
            }
            v81 = *((_QWORD *)v80 - 3);
            if ( (v81 & 1) != 0 )
            {
              *((_QWORD *)v80 - 3) = v81 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v82 + i - 32);
            }
            else
            {
              raw_spin_unlock(v82 + i - 32);
            }
LABEL_42:
            LODWORD(v77) = v77 + 1;
          }
        }
        *(_BYTE *)(v18 + 228) = 0;
LABEL_11:
        dp_peer_unref_delete(v18, 7u, v30, v31, v32, v33, v34, v35, v36, v37);
        return 0;
      }
      v67 = *(_QWORD *)(v17 + 96);
      if ( (v67 & 1) != 0 )
      {
        *(_QWORD *)(v17 + 96) = v67 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v17 + 88);
      }
      else
      {
        raw_spin_unlock(v17 + 88);
      }
      qdf_trace_msg(
        0x81u,
        8u,
        "%s: %pK: default route is not set for peer: %02x:%02x:%02x:**:**:%02x",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "dp_addba_resp_tx_completion_wifi3",
        a1,
        *(unsigned __int8 *)(v18 + 44),
        *(unsigned __int8 *)(v18 + 45),
        *(unsigned __int8 *)(v18 + 46),
        *(unsigned __int8 *)(v18 + 49));
    }
    else
    {
      v50 = *(_QWORD *)(v17 + 96);
      if ( (v50 & 1) != 0 )
      {
        *(_QWORD *)(v17 + 96) = v50 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v17 + 88);
      }
      else
      {
        raw_spin_unlock(v17 + 88);
      }
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: Rx Tid- %d hw qdesc is not in IN_PROGRESS",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "dp_addba_resp_tx_completion_wifi3",
        a1,
        a4);
    }
    dp_peer_unref_delete(v18, 7u, v59, v60, v61, v62, v63, v64, v65, v66);
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: Peer is NULL!",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_addba_resp_tx_completion_wifi3",
      a1);
  }
  return 16;
}
