__int64 __fastcall dp_tx_latency_stats_config(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned __int8 v4; // w21
  __int64 ref_by_id_1; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x26
  __int64 v16; // x20
  __int64 v17; // x8
  unsigned __int64 StatusReg; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x27
  __int64 v28; // x25
  unsigned int v29; // w8
  unsigned int v36; // w10
  unsigned __int64 v38; // x9
  _DWORD *v39; // x10
  unsigned int v41; // w9
  __int64 v42; // x8
  __int64 v43; // x8
  unsigned int v44; // w9
  char v45; // w8
  __int64 v46; // x20
  unsigned int v47; // w21
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x23
  unsigned int *v57; // x8

  v4 = a2;
  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 7);
  if ( ref_by_id_1 )
  {
    v15 = (_DWORD *)(ref_by_id_1 + 45056);
    v16 = ref_by_id_1;
    *(_DWORD *)(ref_by_id_1 + 45352) = 0;
    v17 = *(_QWORD *)(ref_by_id_1 + 24);
    if ( !v17 || !*(_QWORD *)(v17 + 8) )
      goto LABEL_29;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(ref_by_id_1 + 136);
      v27 = *(_QWORD *)(v16 + 120);
      while ( v27 )
      {
LABEL_8:
        v28 = v27;
        v27 = *(_QWORD *)(v27 + 56);
        v29 = *(_DWORD *)(v28 + 40);
        while ( v29 )
        {
          _X12 = (unsigned int *)(v28 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v36 = __ldxr(_X12);
            if ( v36 != v29 )
              break;
            if ( !__stlxr(v29 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v36 == v29;
          v29 = v36;
          if ( _ZF )
          {
            _X8 = (unsigned int *)(v28 + 284);
            __asm { PRFM            #0x11, [X8] }
            do
              v41 = __ldxr(_X8);
            while ( __stxr(v41 + 1, _X8) );
            v42 = *(_QWORD *)v28;
            if ( *(_QWORD *)v28 )
            {
              if ( *(_BYTE *)(v42 + 2221) )
              {
                v38 = 0;
                v39 = (_DWORD *)(v42 + 5472);
                do
                {
                  *(v39 - 46) = 0;
                  ++v38;
                  *(v39 - 47) = 0;
                  *(v39 - 45) = 0;
                  *(v39 - 44) = 0;
                  *(v39 - 43) = 0;
                  *(v39 - 42) = 0;
                  *(v39 - 40) = 0;
                  *(v39 - 41) = 0;
                  *(v39 - 39) = 0;
                  *(v39 - 38) = 0;
                  *(v39 - 37) = 0;
                  *(v39 - 36) = 0;
                  *(v39 - 34) = 0;
                  *(v39 - 35) = 0;
                  *(v39 - 33) = 0;
                  *(v39 - 32) = 0;
                  *(v39 - 31) = 0;
                  *(v39 - 30) = 0;
                  *(v39 - 28) = 0;
                  *(v39 - 29) = 0;
                  *(v39 - 27) = 0;
                  *(v39 - 26) = 0;
                  *(v39 - 25) = 0;
                  *(v39 - 24) = 0;
                  *(v39 - 22) = 0;
                  *(v39 - 23) = 0;
                  *(v39 - 21) = 0;
                  *(v39 - 20) = 0;
                  *(v39 - 19) = 0;
                  *(v39 - 18) = 0;
                  *(v39 - 16) = 0;
                  *(v39 - 17) = 0;
                  *(v39 - 15) = 0;
                  *(v39 - 14) = 0;
                  *(v39 - 13) = 0;
                  *(v39 - 12) = 0;
                  *(v39 - 10) = 0;
                  *(v39 - 11) = 0;
                  *(v39 - 9) = 0;
                  *(v39 - 8) = 0;
                  *(v39 - 7) = 0;
                  *(v39 - 6) = 0;
                  *(v39 - 4) = 0;
                  *(v39 - 5) = 0;
                  *(v39 - 3) = 0;
                  *(v39 - 2) = 0;
                  *(v39 - 1) = 0;
                  *v39 = 0;
                  v39 += 814;
                }
                while ( v38 < *(unsigned __int8 *)(v42 + 2221) );
              }
            }
            else
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: no txrx peer, skip",
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                "dp_tx_latency_stats_clear_per_peer");
            }
            dp_peer_unref_delete(v28, 7u, v19, v20, v21, v22, v23, v24, v25, v26);
            break;
          }
        }
      }
    }
    else
    {
      raw_spin_lock_bh(ref_by_id_1 + 136);
      *(_QWORD *)(v16 + 144) |= 1uLL;
      v27 = *(_QWORD *)(v16 + 120);
      if ( v27 )
        goto LABEL_8;
    }
    v43 = *(_QWORD *)(v16 + 144);
    if ( (v43 & 1) != 0 )
    {
      *(_QWORD *)(v16 + 144) = v43 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 136);
      if ( (*a3 & 1) != 0 )
        goto LABEL_30;
      goto LABEL_35;
    }
    raw_spin_unlock(v16 + 136);
LABEL_29:
    if ( (*a3 & 1) != 0 )
    {
LABEL_30:
      v15[75] = a3[1];
      v15[76] = *((_DWORD *)a3 + 2);
      v15[77] = *((_DWORD *)a3 + 3);
      v15[78] = *((_DWORD *)a3 + 4);
      v44 = *((_DWORD *)a3 + 5);
      v15[79] = v44;
      v45 = *a3;
LABEL_36:
      v47 = dp_h2t_tx_latency_stats_cfg_msg_send(a1, v4, v45 & 1, *((_DWORD *)a3 + 1), v44 / 0x3E8);
      if ( v47 )
      {
        v56 = jiffies;
        v57 = (unsigned int *)(dp_tx_latency_stats_config___last_ticks_9 - jiffies);
        if ( dp_tx_latency_stats_config___last_ticks_9 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: failed to send htt msg: %d",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "dp_tx_latency_stats_config",
            v47);
          dp_tx_latency_stats_config___last_ticks_9 = v56;
        }
      }
      else
      {
        v57 = (unsigned int *)*a3;
        v15[74] = (_DWORD)v57;
      }
      dp_vdev_unref_delete(a1, v16, 7u, v57, v48, v49, v50, v51, v52, v53, v54, v55);
      return v47;
    }
LABEL_35:
    v44 = *((_DWORD *)a3 + 5);
    v45 = 0;
    goto LABEL_36;
  }
  v46 = jiffies;
  if ( dp_tx_latency_stats_config___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev %d does not exist",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_tx_latency_stats_config",
      v4);
    dp_tx_latency_stats_config___last_ticks = v46;
  }
  return 16;
}
