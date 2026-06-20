__int64 __fastcall dp_request_rx_hw_stats(__int64 a1, unsigned __int8 a2)
{
  __int64 ref_by_id_0; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  __int64 v14; // x22
  unsigned int *v15; // x8
  unsigned int v16; // w22
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x21
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int64 StatusReg; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w26
  int v46; // w27
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w23
  __int64 v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int *v75; // x8
  __int64 v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x8

  ref_by_id_0 = dp_vdev_get_ref_by_id_0(a1, a2);
  v13 = ref_by_id_0;
  if ( !*(_QWORD *)(a1 + 18640) )
  {
    if ( !ref_by_id_0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: vdev is null for vdev_id: %u",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "dp_request_rx_hw_stats",
        a2);
      v16 = 4;
      goto LABEL_35;
    }
    v17 = dp_vdev_bss_peer_ref_n_get(a1, ref_by_id_0, 7u);
    if ( !v17 )
    {
      qdf_trace_msg(0x45u, 2u, "%s: Peer is NULL", v18, v19, v20, v21, v22, v23, v24, v25, "dp_request_rx_hw_stats");
      v16 = 4;
LABEL_34:
      dp_vdev_unref_delete(a1, v13, 7u, v15, v5, v6, v7, v8, v9, v10, v11, v12);
      goto LABEL_35;
    }
    v26 = v17;
    v27 = _qdf_mem_malloc(8u, "dp_request_rx_hw_stats", 3402);
    *(_QWORD *)(a1 + 18640) = v27;
    if ( v27 )
    {
      qdf_event_reset(a1 + 18576);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 18616);
      }
      else
      {
        raw_spin_lock_bh(a1 + 18616);
        *(_QWORD *)(a1 + 18624) |= 1uLL;
      }
      v45 = *(_DWORD *)(a1 + 18568);
      v46 = *(_DWORD *)(a1 + 18572);
      *(_QWORD *)(a1 + 18568) = 0;
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: HW stats query start",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "dp_request_rx_hw_stats");
      v47 = dp_peer_rxtid_stats(v26, dp_rx_hw_stats_cb, *(_QWORD *)(a1 + 18640));
      if ( v47 )
      {
        v56 = v47;
        **(_DWORD **)(a1 + 18640) = v47;
        *(_BYTE *)(*(_QWORD *)(a1 + 18640) + 4LL) = 0;
        v57 = *(_QWORD *)(a1 + 18624);
        *(_BYTE *)(a1 + 18632) = 1;
        if ( (v57 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 18624) = v57 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 18616);
        }
        else
        {
          raw_spin_unlock(a1 + 18616);
        }
        v16 = qdf_wait_single_event(a1 + 18576, 0x64u);
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: HW stats query end with %d",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "dp_request_rx_hw_stats",
          v56);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v66 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v66 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v66 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 18616);
          if ( v16 )
            goto LABEL_20;
        }
        else
        {
          raw_spin_lock_bh(a1 + 18616);
          *(_QWORD *)(a1 + 18624) |= 1uLL;
          if ( v16 )
          {
LABEL_20:
            v75 = *(unsigned int **)(a1 + 18640);
            if ( v75 )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: partial rx hw stats event collected with %d",
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                "dp_request_rx_hw_stats",
                *v75);
              if ( *(_BYTE *)(a1 + 18632) == 1 )
                *(_BYTE *)(*(_QWORD *)(a1 + 18640) + 4LL) = 1;
            }
            *(_DWORD *)(a1 + 18568) = v45;
            *(_DWORD *)(a1 + 18572) = v46;
            if ( a1 )
              ++*(_DWORD *)(a1 + 13676);
          }
        }
        v76 = *(_QWORD *)(a1 + 18624);
        if ( (v76 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 18624) = v76 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 18616);
        }
        else
        {
          raw_spin_unlock(a1 + 18616);
        }
        goto LABEL_33;
      }
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: no tid stats sent successfully",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "dp_request_rx_hw_stats");
      _qdf_mem_free(*(_QWORD *)(a1 + 18640));
      v85 = *(_QWORD *)(a1 + 18624);
      *(_QWORD *)(a1 + 18640) = 0;
      if ( (v85 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18624) = v85 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18616);
      }
      else
      {
        raw_spin_unlock(a1 + 18616);
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: malloc failed for hw stats structure",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "dp_request_rx_hw_stats");
    }
    v16 = 4;
LABEL_33:
    dp_peer_unref_delete(v26, 7u, v77, v78, v79, v80, v81, v82, v83, v84);
    goto LABEL_34;
  }
  v14 = jiffies;
  v15 = (unsigned int *)(dp_request_rx_hw_stats___last_ticks - jiffies);
  if ( dp_request_rx_hw_stats___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Stats already requested", v5, v6, v7, v8, v9, v10, v11, v12, "dp_request_rx_hw_stats");
    dp_request_rx_hw_stats___last_ticks = v14;
  }
  v16 = 6;
  if ( v13 )
    goto LABEL_34;
LABEL_35:
  if ( a1 )
    ++*(_DWORD *)(a1 + 13672);
  return v16;
}
