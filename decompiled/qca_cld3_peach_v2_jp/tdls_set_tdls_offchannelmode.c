__int64 __fastcall tdls_set_tdls_offchannelmode(__int64 a1, unsigned int a2)
{
  __int64 v4; // x22
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x6
  const char *v23; // x5
  __int64 first_connected_peer; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  __int64 v34; // x23
  _BYTE *v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x21
  __int64 v45; // x8
  unsigned int v46; // w1
  unsigned __int8 opclass_from_bandwidth; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned __int8 v56; // w1
  int v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned __int16 v74; // w0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x25
  __int64 v84; // x1
  __int64 v85; // [xsp+0h] [xbp-50h]
  __int64 v86; // [xsp+8h] [xbp-48h]
  __int64 v87; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v88[2]; // [xsp+40h] [xbp-10h] BYREF

  v88[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v87 = 0;
  v88[0] = 0;
  if ( (unsigned int)tdls_get_vdev_objects(a1, v88, &v87) )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev:%d Unable to fetch vdev objects",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tdls_set_tdls_offchannelmode",
      *(unsigned __int8 *)(a1 + 104));
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( a2 - 4 <= 0xFFFFFFFC )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev:%d Invalid tdls off channel mode %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "tdls_set_tdls_offchannelmode",
      *(unsigned __int8 *)(a1 + 104),
      a2);
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev:%d tdls off channel req in not associated state %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tdls_set_tdls_offchannelmode",
      *(unsigned __int8 *)(a1 + 104),
      a2);
    result = 0xFFFFFFFFLL;
    goto LABEL_12;
  }
  v22 = *(unsigned int *)(v87 + 8);
  if ( (*(_BYTE *)(v87 + 156) & 1) == 0 )
  {
    v23 = "Off-Channel ";
LABEL_11:
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev:%d TDLS %sis not enabled. current_mode:%d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "tdls_set_tdls_offchannelmode",
      *(unsigned __int8 *)(a1 + 104),
      v23,
      v22);
    result = 4294966772LL;
    goto LABEL_12;
  }
  if ( (unsigned int)v22 <= 1 )
  {
    v23 = (const char *)&unk_8B9E43;
    goto LABEL_11;
  }
  first_connected_peer = tdls_find_first_connected_peer(v88[0]);
  v33 = *(unsigned __int8 *)(a1 + 104);
  if ( !first_connected_peer )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: vdev:%d No TDLS Connected Peer",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "tdls_set_tdls_offchannelmode",
      v33);
    result = 0xFFFFFFFFLL;
    goto LABEL_12;
  }
  v34 = first_connected_peer;
  qdf_trace_msg(
    0,
    4u,
    "%s: vdev:%d TDLS off_chan_mode=%d tdls_off_channel %d offchanoffset %d peer_off_chan_cap:%d peer_pref_off_chan_freq:%d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "tdls_set_tdls_offchannelmode",
    v33,
    a2,
    *(unsigned __int8 *)(v87 + 204),
    *(unsigned __int16 *)(v87 + 206),
    *(unsigned __int8 *)(first_connected_peer + 51),
    *(_DWORD *)(first_connected_peer + 492));
  v35 = (_BYTE *)_qdf_mem_malloc(0x418u, "tdls_set_tdls_offchannelmode", 1382);
  if ( !v35 )
  {
    result = 4294967284LL;
    goto LABEL_12;
  }
  v44 = (__int64)v35;
  if ( a2 == 1 )
  {
    v45 = v87;
    if ( *(_BYTE *)(v87 + 204) && *(_WORD *)(v87 + 206) != 255 )
    {
      v35[11] = *(_BYTE *)(v87 + 204);
      v35[10] = *(_BYTE *)(v45 + 206);
      tdls_update_opclass(*(_QWORD *)(v4 + 80), v35);
      v56 = *(_BYTE *)(v44 + 13);
    }
    else
    {
      if ( !*(_BYTE *)(v34 + 51) || (v46 = *(_DWORD *)(v34 + 492)) == 0 )
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: vdev:%d TDLS off-channel params are not set yet",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "tdls_set_tdls_offchannelmode",
          *(unsigned __int8 *)(a1 + 104));
LABEL_33:
        _qdf_mem_free(v44);
        result = 4294967274LL;
        goto LABEL_12;
      }
      v35[11] = wlan_reg_freq_to_chan(v4, v46, v36, v37, v38, v39, v40, v41, v42, v43);
      opclass_from_bandwidth = tdls_get_opclass_from_bandwidth(
                                 a1,
                                 *(unsigned int *)(v34 + 492),
                                 *(unsigned __int8 *)(v34 + 496),
                                 v44 + 10);
      *(_BYTE *)(v44 + 13) = opclass_from_bandwidth;
      v56 = opclass_from_bandwidth;
      *(_DWORD *)(v44 + 16) = *(_DWORD *)(v34 + 492);
    }
    v74 = wlan_reg_chan_opclass_to_freq(*(_BYTE *)(v44 + 11), v56, 0, v48, v49, v50, v51, v52, v53, v54, v55);
    *(_DWORD *)(v34 + 492) = v74;
    if ( !v74 )
    {
      v83 = jiffies;
      if ( tdls_set_tdls_offchannelmode___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0,
          8u,
          "%s: Invalid op_class %d",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "tdls_set_tdls_offchannelmode",
          *(unsigned __int8 *)(v44 + 13));
        tdls_set_tdls_offchannelmode___last_ticks = v83;
      }
    }
    v84 = v87;
    *(_BYTE *)(v34 + 490) = *(_BYTE *)(v44 + 13);
    if ( (unsigned int)tdls_update_peer_off_channel_list(v4, v84, a1, v34, v44) )
      goto LABEL_33;
  }
  else
  {
    *((_WORD *)v35 + 5) = 0;
    v35[13] = 0;
  }
  v57 = *(unsigned __int8 *)(v88[0] + 968LL);
  *(_BYTE *)(v44 + 12) = a2;
  *(_DWORD *)v44 = v57;
  *(_BYTE *)(v44 + 14) = *(_BYTE *)(v34 + 40);
  qdf_mem_copy((void *)(v44 + 4), (const void *)(v34 + 24), 6u);
  LODWORD(v86) = *(unsigned __int8 *)(v44 + 11);
  LODWORD(v85) = *(_DWORD *)v44;
  qdf_trace_msg(
    0,
    4u,
    "%s: Peer %02x:%02x:%02x:**:**:%02x vdevId: %d, off channel: %d, offset: %d, num_allowed_off_chan:%d mode: %d, is_responder: %d",
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    "tdls_set_tdls_offchannelmode",
    *(unsigned __int8 *)(v44 + 4),
    *(unsigned __int8 *)(v44 + 5),
    *(unsigned __int8 *)(v44 + 6),
    *(unsigned __int8 *)(v44 + 9),
    v85,
    v86,
    *(unsigned __int8 *)(v44 + 10),
    *(unsigned __int16 *)(v44 + 20),
    *(unsigned __int8 *)(v44 + 12),
    *(unsigned __int8 *)(v44 + 14));
  if ( (unsigned int)tgt_tdls_set_offchan_mode(*(_QWORD *)v87, v44) )
  {
    _qdf_mem_free(v44);
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to send channel switch request to wmi",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "tdls_set_tdls_offchannelmode");
    result = 4294967274LL;
  }
  else
  {
    *(_DWORD *)(v87 + 208) = a2;
    _qdf_mem_free(v44);
    result = 0;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
