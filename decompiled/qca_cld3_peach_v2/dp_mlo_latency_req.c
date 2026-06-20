__int64 __fastcall dp_mlo_latency_req(__int64 a1, unsigned __int8 a2, unsigned __int16 a3, char a4)
{
  __int64 ref_by_id_1; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  unsigned int v28; // w9
  unsigned int v35; // w11
  __int64 v38; // x24
  unsigned int *v39; // x8
  __int64 v40; // x22
  int v41; // w8
  unsigned int *v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
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
  unsigned int v68; // w9

  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 0xDu);
  if ( !ref_by_id_1 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable find vdev for id: %d",
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             "dp_mlo_latency_req",
             a2);
  v17 = ref_by_id_1;
  v18 = dp_sta_vdev_link_peer_ref_n_get(a1, ref_by_id_1, 0xDu);
  if ( v18 )
  {
    v27 = *(_QWORD *)(v18 + 416);
    if ( v27 )
    {
      v28 = *(_DWORD *)(v27 + 40);
      do
      {
        if ( !v28 )
          goto LABEL_19;
        _X13 = (unsigned int *)(v27 + 40);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v35 = __ldxr(_X13);
          if ( v35 != v28 )
            break;
          if ( !__stlxr(v28 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v35 == v28;
        v28 = v35;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v27 + 316);
      __asm { PRFM            #0x11, [X8] }
      do
        v68 = __ldxr(_X8);
      while ( __stxr(v68 + 1, _X8) );
      v38 = *(_QWORD *)(v18 + 416);
      dp_peer_unref_delete(v18, 0xDu, v19, v20, v21, v22, v23, v24, v25, v26);
      if ( v38 )
      {
        dp_vdev_unref_delete(a1, v17, 0xDu, v39, v19, v20, v21, v22, v23, v24, v25, v26);
        v40 = *(_QWORD *)(v38 + 24);
        *(_DWORD *)(v40 + 43576) = a4 & 1;
        *(_WORD *)(v40 + 43580) = a3;
        raw_spin_lock(v40 + 43536);
        *(_BYTE *)(v40 + 43565) = a4 & 1;
        if ( (a4 & 1) != 0 )
        {
          v41 = 1;
        }
        else
        {
          if ( (*(_BYTE *)(v40 + 43564) & 1) != 0 || (*(_BYTE *)(v40 + 43566) & 1) != 0 )
            goto LABEL_23;
          v41 = 0;
        }
        *(_DWORD *)(v40 + 43552) = v41;
LABEL_23:
        raw_spin_unlock(v40 + 43536);
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Vdev: %d interval: %d enable %d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "dp_mlo_latency_req",
          *(unsigned __int8 *)(v40 + 59),
          a3,
          a4 & 1);
        return dp_peer_unref_delete(v38, 0xDu, v59, v60, v61, v62, v63, v64, v65, v66);
      }
    }
    else
    {
LABEL_19:
      dp_peer_unref_delete(v18, 0xDu, v19, v20, v21, v22, v23, v24, v25, v26);
    }
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Unable find peer for vdev: %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "dp_mlo_latency_req",
    a2);
  return dp_vdev_unref_delete(a1, v17, 0xDu, v42, v43, v44, v45, v46, v47, v48, v49, v50);
}
