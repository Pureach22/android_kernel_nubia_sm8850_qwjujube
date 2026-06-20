__int64 __fastcall tdls_disable_offchan_and_teardown_links(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  int v11; // w20
  __int64 is_progress; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  __int64 v22; // x21
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x25
  __int64 v33; // x27
  unsigned __int8 *all_peer; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int8 *v44; // x24
  unsigned __int8 *v45; // x23
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // [xsp+0h] [xbp-20h]
  __int64 v63; // [xsp+8h] [xbp-18h] BYREF
  __int64 *v64[2]; // [xsp+10h] [xbp-10h] BYREF

  v64[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  v64[0] = nullptr;
  if ( (unsigned int)tdls_get_vdev_objects(a1, v64, &v63) )
  {
    result = qdf_trace_msg(
               0,
               2u,
               "%s: tdls objects are NULL ",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "tdls_disable_offchan_and_teardown_links");
  }
  else
  {
    v11 = *(unsigned __int16 *)(v63 + 202);
    is_progress = tdls_is_progress(v64[0], 0, 0);
    if ( v11 || is_progress )
    {
      v22 = v63;
      if ( (*(_BYTE *)(v63 + 156) & 1) != 0 && (unsigned int)(*(_DWORD *)(v63 + 8) - 2) <= 2 )
      {
        v23 = *(_DWORD *)(v63 + 160);
        if ( v23 - 166 > 0xFFFFFF5A )
        {
          qdf_trace_msg(
            0,
            4u,
            "%s: change tdls off channel from %d to %d",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "tdls_set_tdls_offchannel",
            *(unsigned __int8 *)(v63 + 204),
            v23);
          *(_BYTE *)(v22 + 204) = v23;
        }
        else
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: Invalid tdls off channel %u",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            "tdls_set_tdls_offchannel",
            v23);
        }
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: Either TDLS or TDLS Off-channel is not enabled",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "tdls_set_tdls_offchannel");
      }
      if ( (*(_BYTE *)(v63 + 156) & 1) != 0 && *(_DWORD *)(v63 + 8) > 1u )
      {
        *(_WORD *)(v63 + 206) = 3;
        qdf_trace_msg(
          0,
          4u,
          "%s: change tdls secondary off channel offset to 0x%x",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "tdls_set_tdls_secoffchanneloffset",
          3);
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: Either TDLS or TDLS Off-channel is not enabled",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "tdls_set_tdls_secoffchanneloffset");
      }
      tdls_set_tdls_offchannelmode(a1, 3u);
      tdls_delete_all_tdls_peers(a1, v63);
      result = v63;
      if ( *(_WORD *)(v63 + 200) )
      {
        v32 = 35;
        v33 = 1;
        do
        {
          if ( v32 == 107 )
            __break(0x5512u);
          if ( *(_BYTE *)(result + v32 - 2) == 1
            && *(unsigned __int8 *)(result + v32 - 3) == *(unsigned __int8 *)(a1 + 104) )
          {
            all_peer = (unsigned __int8 *)tdls_find_all_peer(result, result + v32);
            if ( all_peer )
            {
              v44 = all_peer + 24;
              v45 = all_peer;
              LODWORD(v62) = all_peer[29];
              qdf_trace_msg(
                0,
                4u,
                "%s: vdev %d indicate TDLS teardown %02x:%02x:%02x:**:**:%02x",
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                "tdls_disable_offchan_and_teardown_links",
                *(unsigned __int8 *)(*v64[0] + 104),
                all_peer[24],
                all_peer[25],
                all_peer[26],
                v62);
              if ( (unsigned int)tdls_indicate_teardown(v64[0], v45, 0x1Au, v46, v47, v48, v49, v50, v51, v52, v53) )
              {
                LODWORD(v62) = v45[29];
                qdf_trace_msg(
                  0,
                  2u,
                  "%s: vdev %d teardown indication failed for peer %02x:%02x:%02x:**:**:%02x",
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  "tdls_disable_offchan_and_teardown_links",
                  *(unsigned __int8 *)(*v64[0] + 104),
                  v45[24],
                  v45[25],
                  v45[26],
                  v62);
              }
              else
              {
                tdls_decrement_peer_count(a1, v63, v54, v55, v56, v57, v58, v59, v60, v61);
                tdls_reset_peer(v64[0], v44);
                *(_WORD *)(v63 + v32 - 3) = 255;
                *(_BYTE *)(v63 + v32 - 1) = -1;
                qdf_mem_set((void *)(v63 + v32), 6u, 0);
              }
            }
          }
          result = v63;
          v32 += 9;
        }
        while ( *(unsigned __int16 *)(v63 + 200) > (unsigned int)(unsigned __int16)v33++ );
      }
    }
    else
    {
      v21 = *(unsigned __int8 *)(a1 + 104);
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev:%d is_ml_vdev:%d tdls_in_prog:%d conn_peers:%d Disable tdls at FW as second interface is coming up",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "tdls_disable_offchan_and_teardown_links",
        v21,
        0,
        0,
        0);
      result = tdls_send_update_to_fw(v64[0], v63, 1, 1, 0, v21);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
