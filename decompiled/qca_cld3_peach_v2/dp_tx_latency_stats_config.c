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
  __int64 *v38; // x8
  __int64 v39; // x8
  unsigned __int64 v40; // x9
  _DWORD *v41; // x10
  unsigned int v43; // w9
  __int64 v44; // x20
  unsigned int v45; // w21
  __int64 v46; // x8
  unsigned int v47; // w9
  char v48; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x23
  unsigned int *v58; // x8

  v4 = a2;
  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 7);
  if ( ref_by_id_1 )
  {
    v15 = (_DWORD *)(ref_by_id_1 + 45056);
    v16 = ref_by_id_1;
    *(_DWORD *)(ref_by_id_1 + 46176) = 0;
    v17 = *(_QWORD *)(ref_by_id_1 + 24);
    if ( !v17 || !*(_QWORD *)(v17 + 8) )
      goto LABEL_38;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(ref_by_id_1 + 144);
      v27 = *(_QWORD *)(v16 + 128);
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
            _X8 = (unsigned int *)(v28 + 292);
            __asm { PRFM            #0x11, [X8] }
            do
              v43 = __ldxr(_X8);
            while ( __stxr(v43 + 1, _X8) );
            if ( *(_DWORD *)(v28 + 408) == 1 && (v38 = *(__int64 **)(v28 + 416)) != nullptr )
            {
              v39 = *v38;
              if ( v39 )
              {
LABEL_21:
                if ( *(_BYTE *)(v39 + 2281) )
                {
                  v40 = 0;
                  v41 = (_DWORD *)(v39 + 6352);
                  do
                  {
                    *(v41 - 46) = 0;
                    ++v40;
                    *(v41 - 47) = 0;
                    *(v41 - 45) = 0;
                    *(v41 - 44) = 0;
                    *(v41 - 43) = 0;
                    *(v41 - 42) = 0;
                    *(v41 - 40) = 0;
                    *(v41 - 41) = 0;
                    *(v41 - 39) = 0;
                    *(v41 - 38) = 0;
                    *(v41 - 37) = 0;
                    *(v41 - 36) = 0;
                    *(v41 - 34) = 0;
                    *(v41 - 35) = 0;
                    *(v41 - 33) = 0;
                    *(v41 - 32) = 0;
                    *(v41 - 31) = 0;
                    *(v41 - 30) = 0;
                    *(v41 - 28) = 0;
                    *(v41 - 29) = 0;
                    *(v41 - 27) = 0;
                    *(v41 - 26) = 0;
                    *(v41 - 25) = 0;
                    *(v41 - 24) = 0;
                    *(v41 - 22) = 0;
                    *(v41 - 23) = 0;
                    *(v41 - 21) = 0;
                    *(v41 - 20) = 0;
                    *(v41 - 19) = 0;
                    *(v41 - 18) = 0;
                    *(v41 - 16) = 0;
                    *(v41 - 17) = 0;
                    *(v41 - 15) = 0;
                    *(v41 - 14) = 0;
                    *(v41 - 13) = 0;
                    *(v41 - 12) = 0;
                    *(v41 - 10) = 0;
                    *(v41 - 11) = 0;
                    *(v41 - 9) = 0;
                    *(v41 - 8) = 0;
                    *(v41 - 7) = 0;
                    *(v41 - 6) = 0;
                    *(v41 - 4) = 0;
                    *(v41 - 5) = 0;
                    *(v41 - 3) = 0;
                    *(v41 - 2) = 0;
                    *(v41 - 1) = 0;
                    *v41 = 0;
                    v41 += 1018;
                  }
                  while ( v40 < *(unsigned __int8 *)(v39 + 2281) );
                }
                goto LABEL_27;
              }
            }
            else
            {
              v39 = *(_QWORD *)v28;
              if ( *(_QWORD *)v28 )
                goto LABEL_21;
            }
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
LABEL_27:
            dp_peer_unref_delete(v28, 7u, v19, v20, v21, v22, v23, v24, v25, v26);
            break;
          }
        }
      }
    }
    else
    {
      raw_spin_lock_bh(ref_by_id_1 + 144);
      *(_QWORD *)(v16 + 152) |= 1uLL;
      v27 = *(_QWORD *)(v16 + 128);
      if ( v27 )
        goto LABEL_8;
    }
    v46 = *(_QWORD *)(v16 + 152);
    if ( (v46 & 1) != 0 )
    {
      *(_QWORD *)(v16 + 152) = v46 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 144);
      if ( (*a3 & 1) != 0 )
        goto LABEL_39;
      goto LABEL_41;
    }
    raw_spin_unlock(v16 + 144);
LABEL_38:
    if ( (*a3 & 1) != 0 )
    {
LABEL_39:
      v15[281] = a3[1];
      v15[282] = *((_DWORD *)a3 + 2);
      v15[283] = *((_DWORD *)a3 + 3);
      v15[284] = *((_DWORD *)a3 + 4);
      v47 = *((_DWORD *)a3 + 5);
      v15[285] = v47;
      v48 = *a3;
LABEL_42:
      v45 = dp_h2t_tx_latency_stats_cfg_msg_send(a1, v4, v48 & 1, *((_DWORD *)a3 + 1), v47 / 0x3E8);
      if ( v45 )
      {
        v57 = jiffies;
        v58 = (unsigned int *)(dp_tx_latency_stats_config___last_ticks_9 - jiffies);
        if ( dp_tx_latency_stats_config___last_ticks_9 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: failed to send htt msg: %d",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "dp_tx_latency_stats_config",
            v45);
          dp_tx_latency_stats_config___last_ticks_9 = v57;
        }
      }
      else
      {
        v58 = (unsigned int *)*a3;
        v15[280] = (_DWORD)v58;
      }
      dp_vdev_unref_delete(a1, v16, 7u, v58, v49, v50, v51, v52, v53, v54, v55, v56);
      return v45;
    }
LABEL_41:
    v47 = *((_DWORD *)a3 + 5);
    v48 = 0;
    goto LABEL_42;
  }
  v44 = jiffies;
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
    dp_tx_latency_stats_config___last_ticks = v44;
  }
  return 16;
}
