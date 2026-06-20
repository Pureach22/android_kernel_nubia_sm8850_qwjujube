__int64 __fastcall lim_ndp_delete_peers_by_addr_converged(
        unsigned __int8 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 session_by_vdev_id; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x20
  __int64 v40; // x0
  const char *v41; // x2
  __int16 v42; // [xsp+4h] [xbp-1Ch] BYREF
  int v43; // [xsp+8h] [xbp-18h] BYREF
  __int16 v44; // [xsp+Ch] [xbp-14h]
  int v45; // [xsp+10h] [xbp-10h] BYREF
  __int16 v46; // [xsp+14h] [xbp-Ch]
  __int64 v47; // [xsp+18h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(
                      53,
                      (__int64)"lim_ndp_delete_peers_by_addr_converged",
                      a3,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10);
  if ( result )
  {
    v13 = result;
    v45 = a2;
    v42 = 0;
    v46 = WORD2(a2);
    v44 = 0;
    v43 = 0;
    if ( (unsigned int)qdf_mem_cmp(&v43, &v45, 6u) )
    {
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: deleting peer: %02x:%02x:%02x:**:**:%02x confirm rejected",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_ndp_delete_peer_by_addr",
        (unsigned __int8)v45,
        BYTE1(v45),
        BYTE2(v45),
        HIBYTE(v46));
      session_by_vdev_id = pe_find_session_by_vdev_id(v13, a1, v22, v23, v24, v25, v26, v27, v28, v29);
      if ( !session_by_vdev_id || *(_DWORD *)(session_by_vdev_id + 92) != 4 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: PE session is NULL or non-NDI for sme session %d",
                   v31,
                   v32,
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   "lim_ndp_delete_peer_by_addr",
                   a1);
        goto LABEL_11;
      }
      v39 = session_by_vdev_id;
      v40 = dph_lookup_hash_entry(
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v13,
              (unsigned __int8 *)&v45,
              &v42,
              session_by_vdev_id + 360);
      if ( v40 )
      {
        if ( *(_BYTE *)(v40 + 356) == 5 )
        {
          result = lim_del_sta(v13, v40, 1, v39);
          goto LABEL_11;
        }
        v41 = "%s: Non-NDI Peer ignored";
      }
      else
      {
        v41 = "%s: Unknown NDI Peer";
      }
    }
    else
    {
      v41 = "%s: Failing to delete the peer with all zero mac addr";
    }
    result = qdf_trace_msg(0x35u, 2u, v41, v14, v15, v16, v17, v18, v19, v20, v21, "lim_ndp_delete_peer_by_addr");
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
