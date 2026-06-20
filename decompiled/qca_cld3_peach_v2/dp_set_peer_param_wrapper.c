__int64 __fastcall dp_set_peer_param_wrapper(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        int a4,
        unsigned __int8 *a5)
{
  __int64 v7; // x22
  __int64 (*v8)(void); // x8
  unsigned __int8 v9; // w21
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
  unsigned int v20; // w24
  __int64 v21; // x23
  __int64 v22; // x21
  __int64 v23; // x8
  unsigned int v24; // w9
  unsigned int v31; // w11
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 v37; // x24
  __int64 v38; // x25
  __int64 v39; // x19
  char v40; // w8
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w8
  __int64 *v51; // x8
  __int64 v52; // x22
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  __int64 v56; // x7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x4
  __int64 v66; // x5
  __int64 v67; // x6
  __int64 v68; // x7
  __int64 v69; // x4
  __int64 v70; // x5
  __int64 v71; // x6
  __int64 v72; // x7
  char v73; // w9
  unsigned int v76; // w9
  __int64 v77; // [xsp+0h] [xbp-10h]

  v7 = a1;
  if ( a4 == 4 )
  {
    v8 = *(__int64 (**)(void))(a1 + 1536);
    if ( v8 )
    {
      v9 = *a5;
      if ( *((_DWORD *)v8 - 1) != 69695039 )
        __break(0x8228u);
      v10 = v8();
      if ( v10 )
      {
        v19 = v10;
        if ( *(_QWORD *)v10 )
        {
          dp_mld_peer_change_vdev(v7, v10, v9, v11, v12, v13, v14, v15, v16, v17, v18);
          v20 = 0;
          v10 = v19;
        }
        else
        {
          v20 = 16;
        }
        goto LABEL_71;
      }
    }
    return 16;
  }
  LODWORD(v21) = a4;
  LODWORD(v22) = *(_DWORD *)a5;
  v10 = dp_peer_find_hash_find(a1, (int)a3);
  if ( !v10 )
  {
    if ( a3 )
    {
      v32 = *a3;
      v33 = a3[1];
      v34 = a3[2];
      v35 = a3[5];
    }
    else
    {
      v34 = 0;
      v32 = 0;
      v33 = 0;
      v35 = 0;
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
      v32,
      v33,
      v34,
      v35,
      a2);
    return 16;
  }
  if ( *(_DWORD *)(v10 + 408) != 1 )
    goto LABEL_24;
  v23 = *(_QWORD *)(v10 + 416);
  if ( !v23 )
    goto LABEL_24;
  v24 = *(_DWORD *)(v23 + 40);
  do
  {
    if ( !v24 )
    {
LABEL_30:
      dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
      return 16;
    }
    _X13 = (unsigned int *)(v23 + 40);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v31 = __ldxr(_X13);
      if ( v31 != v24 )
        break;
      if ( !__stlxr(v24 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v31 == v24;
    v24 = v31;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v23 + 292);
  while ( 1 )
  {
    __asm { PRFM            #0x11, [X8] }
    do
      v76 = __ldxr(_X8);
    while ( __stxr(v76 + 1, _X8) );
    v37 = *(_QWORD *)(v10 + 416);
    dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
    v10 = v37;
    if ( !v37 )
      return 16;
LABEL_24:
    v38 = *(_QWORD *)v10;
    if ( !*(_QWORD *)v10 )
      goto LABEL_30;
    v20 = 0;
    if ( (int)v21 <= 4 )
    {
      if ( (_DWORD)v21 )
      {
        if ( (_DWORD)v21 == 2 )
        {
          v52 = v10;
          if ( a3 )
          {
            v53 = *a3;
            v54 = a3[1];
            v55 = a3[2];
            v56 = a3[5];
          }
          else
          {
            v55 = 0;
            v53 = 0;
            v54 = 0;
            v56 = 0;
          }
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Peer %02x:%02x:%02x:**:**:%02x vdev_id %d, isolation %d",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "dp_set_peer_param",
            v53,
            v54,
            v55,
            v56,
            a2,
            (unsigned __int8)v22);
          if ( *(_WORD *)(v38 + 168) )
          {
            if ( (v22 & 1) != 0 )
              v73 = 4;
            else
              v73 = 0;
            v20 = 0;
            v10 = v52;
            *(_BYTE *)(v38 + 88) = *(_BYTE *)(v38 + 88) & 0xFB | v73;
          }
          else
          {
            v20 = 0;
            v10 = v52;
          }
        }
        else if ( (_DWORD)v21 == 3 )
        {
          v20 = 0;
          *(_BYTE *)(v38 + 10) = (*(_BYTE *)(v38 + 10) & 0xFD) + 2 * v22;
        }
        goto LABEL_71;
      }
      v20 = 0;
      v40 = *(_BYTE *)(v38 + 88) & 0xFE | v22;
      goto LABEL_53;
    }
    if ( (_DWORD)v21 != 5 )
    {
      if ( (_DWORD)v21 != 6 )
      {
        if ( (_DWORD)v21 == 9 )
        {
          v39 = v10;
          dp_peer_set_bw(v7, v38, (unsigned int)v22);
          v10 = v39;
          v20 = 0;
        }
        goto LABEL_71;
      }
      v20 = 0;
      v40 = (*(_BYTE *)(v38 + 88) & 0xEF) + 16 * v22;
LABEL_53:
      *(_BYTE *)(v38 + 88) = v40;
      goto LABEL_71;
    }
    v21 = v10;
    v41 = dp_peer_find_hash_find(v7, (int)a3);
    if ( !v41 )
    {
      if ( a3 )
      {
        v69 = *a3;
        v70 = a3[1];
        v71 = a3[2];
        v72 = a3[5];
      }
      else
      {
        v71 = 0;
        v69 = 0;
        v70 = 0;
        v72 = 0;
      }
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: peer NULL,MAC %02x:%02x:%02x:**:**:%02x, vdev_id %u",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dp_set_peer_freq",
        v69,
        v70,
        v71,
        v72,
        a2);
      v20 = 16;
      goto LABEL_70;
    }
    v50 = *(unsigned __int8 *)(v41 + 425);
    v7 = v41;
    *(_DWORD *)(v41 + 500) = v22;
    if ( v50 == 1 )
      ((void (__fastcall *)(__int64))dp_map_link_id_band)(v41);
    if ( *(_DWORD *)(v7 + 408) != 1 || (v51 = *(__int64 **)(v7 + 416)) == nullptr )
      v51 = (__int64 *)v7;
    v22 = *v51;
    if ( !*v51 || !*(_BYTE *)(v7 + 426) )
      break;
    v10 = dp_freq_to_band(*(unsigned int *)(v7 + 500));
    _X8 = (unsigned int *)*(unsigned __int8 *)(v7 + 426);
    if ( (unsigned __int64)_X8 < 5 )
    {
      *((_BYTE *)_X8 + v22 + 2276) = v10;
      goto LABEL_55;
    }
    __break(0x5512u);
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: txrx_peer NULL or local link id not set: %u %02x:%02x:%02x:**:**:%02x",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "dp_map_local_link_id_band",
    *(unsigned __int8 *)(v7 + 426),
    *(unsigned __int8 *)(v7 + 44),
    *(unsigned __int8 *)(v7 + 45),
    *(unsigned __int8 *)(v7 + 46),
    *(unsigned __int8 *)(v7 + 49));
LABEL_55:
  dp_peer_unref_delete(v7, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( a3 )
  {
    v65 = *a3;
    v66 = a3[1];
    v67 = a3[2];
    v68 = a3[5];
  }
  else
  {
    v67 = 0;
    v65 = 0;
    v66 = 0;
    v68 = 0;
  }
  LODWORD(v77) = a2;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Peer %02x:%02x:%02x:**:**:%02x vdev_id %u, frequency %u",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "dp_set_peer_freq",
    v65,
    v66,
    v67,
    v68,
    v77,
    *(_DWORD *)(v7 + 500));
  v20 = 0;
LABEL_70:
  v10 = v21;
LABEL_71:
  dp_peer_unref_delete(v10, 7u, v11, v12, v13, v14, v15, v16, v17, v18);
  return v20;
}
