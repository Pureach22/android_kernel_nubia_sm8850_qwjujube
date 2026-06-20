__int64 __fastcall lim_add_ndi_peer_converged(
        unsigned int a1,
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
  _QWORD *context; // x0
  __int64 v13; // x19
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 session_by_vdev_id; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 result; // x0
  __int64 v50; // x20
  const char *v51; // x2
  const char *v52; // x2
  __int64 v53; // x4
  unsigned __int16 v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x0
  __int16 v64; // [xsp+4h] [xbp-1Ch] BYREF
  int v65; // [xsp+8h] [xbp-18h] BYREF
  __int16 v66; // [xsp+Ch] [xbp-14h]
  int v67; // [xsp+10h] [xbp-10h] BYREF
  __int16 v68; // [xsp+14h] [xbp-Ch]
  __int64 v69; // [xsp+18h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"lim_add_ndi_peer_converged", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    result = 29;
    goto LABEL_15;
  }
  v13 = (__int64)context;
  v14 = context[2695];
  v67 = a2;
  v64 = 0;
  v68 = WORD2(a2);
  v66 = 0;
  v65 = 0;
  if ( !wlan_is_vdev_id_up(v14, a1) )
  {
    v50 = jiffies;
    if ( lim_add_ndi_peer___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x35u, 2u, "%s: NDI vdev is not up", v15, v16, v17, v18, v19, v20, v21, v22, "lim_add_ndi_peer");
      lim_add_ndi_peer___last_ticks = v50;
    }
    goto LABEL_14;
  }
  if ( !(unsigned int)qdf_mem_cmp(&v65, &v67, 6u) )
  {
    v51 = "%s: Failing to add peer with all zero mac addr";
    goto LABEL_11;
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(v13, a1, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( !session_by_vdev_id )
  {
    v52 = "%s: Session not found for vdev_id: %d";
    v53 = a1;
LABEL_13:
    qdf_trace_msg(0x35u, 2u, v52, v32, v33, v34, v35, v36, v37, v38, v39, "lim_add_ndi_peer", v53);
    goto LABEL_14;
  }
  v40 = session_by_vdev_id;
  if ( !dph_lookup_hash_entry(
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v13,
          (unsigned __int8 *)&v67,
          &v64,
          session_by_vdev_id + 360) )
  {
    qdf_trace_msg(
      0x35u,
      4u,
      "%s: Need to create NDI Peer :%02x:%02x:%02x:**:**:%02x",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "lim_add_ndi_peer",
      (unsigned __int8)v67,
      BYTE1(v67),
      BYTE2(v67),
      HIBYTE(v68));
    v54 = lim_assign_peer_idx(v13, v40);
    if ( !v54 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid peer_idx: %d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "lim_add_ndi_peer",
        0);
      result = 0;
      goto LABEL_15;
    }
    v63 = dph_add_hash_entry(v55, v56, v57, v58, v59, v60, v61, v62, v13, (unsigned __int8 *)&v67, v54, v40 + 360);
    if ( v63 )
    {
      *(_BYTE *)(v63 + 344) = 5;
      result = lim_add_sta(v13, (unsigned __int16 *)v63, 0, v40);
      if ( !(_DWORD)result )
        goto LABEL_15;
      v53 = (unsigned int)result;
      v52 = "%s: limAddSta failed status: %d";
      goto LABEL_13;
    }
    v51 = "%s: Couldn't add dph entry";
LABEL_11:
    qdf_trace_msg(0x35u, 2u, v51, v23, v24, v25, v26, v27, v28, v29, v30, "lim_add_ndi_peer");
LABEL_14:
    result = 16;
    goto LABEL_15;
  }
  qdf_trace_msg(0x35u, 2u, "%s: NDI Peer already exists!!", v41, v42, v43, v44, v45, v46, v47, v48, "lim_add_ndi_peer");
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
