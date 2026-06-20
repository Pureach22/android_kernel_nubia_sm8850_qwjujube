__int64 __fastcall tdls_disable_offchan_and_teardown_links(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char is_mlo_vdev; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  int v28; // w21
  __int64 is_progress; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  __int64 v39; // x21
  unsigned int v40; // w20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x25
  __int64 v50; // x27
  unsigned __int8 *all_peer; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned __int8 *v61; // x24
  unsigned __int8 *v62; // x23
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // [xsp+0h] [xbp-20h]
  __int64 v80; // [xsp+8h] [xbp-18h] BYREF
  __int64 *v81[2]; // [xsp+10h] [xbp-10h] BYREF

  v81[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v80 = 0;
  v81[0] = nullptr;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (is_mlo_vdev & 1) != 0 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: try to set ml vdev %d to unforce",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "tdls_disable_offchan_and_teardown_links",
      *(unsigned __int8 *)(a1 + 168));
    tdls_set_link_unforce(a1);
  }
  if ( (unsigned int)tdls_get_vdev_objects(a1, v81, &v80) )
  {
    result = qdf_trace_msg(
               0,
               2u,
               "%s: tdls objects are NULL ",
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "tdls_disable_offchan_and_teardown_links");
  }
  else
  {
    v28 = *(unsigned __int16 *)(v80 + 202);
    is_progress = tdls_is_progress(v81[0], 0, 0);
    if ( v28 || is_progress )
    {
      v39 = v80;
      if ( (*(_BYTE *)(v80 + 156) & 1) != 0 && (unsigned int)(*(_DWORD *)(v80 + 8) - 2) <= 2 )
      {
        v40 = *(_DWORD *)(v80 + 160);
        if ( v40 - 166 > 0xFFFFFF5A )
        {
          qdf_trace_msg(
            0,
            4u,
            "%s: change tdls off channel from %d to %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "tdls_set_tdls_offchannel",
            *(unsigned __int8 *)(v80 + 204),
            v40);
          *(_BYTE *)(v39 + 204) = v40;
        }
        else
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: Invalid tdls off channel %u",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "tdls_set_tdls_offchannel",
            v40);
        }
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: Either TDLS or TDLS Off-channel is not enabled",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "tdls_set_tdls_offchannel");
      }
      if ( (*(_BYTE *)(v80 + 156) & 1) != 0 && *(_DWORD *)(v80 + 8) > 1u )
      {
        *(_WORD *)(v80 + 206) = 3;
        qdf_trace_msg(
          0,
          4u,
          "%s: change tdls secondary off channel offset to 0x%x",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "tdls_set_tdls_secoffchanneloffset",
          3);
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: Either TDLS or TDLS Off-channel is not enabled",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "tdls_set_tdls_secoffchanneloffset");
      }
      tdls_set_tdls_offchannelmode(a1, 3u);
      tdls_delete_all_tdls_peers(a1, v80);
      result = v80;
      if ( *(_WORD *)(v80 + 200) )
      {
        v49 = 35;
        v50 = 1;
        do
        {
          if ( v49 == 107 )
            __break(0x5512u);
          if ( *(_BYTE *)(result + v49 - 2) == 1
            && *(unsigned __int8 *)(result + v49 - 3) == *(unsigned __int8 *)(a1 + 168) )
          {
            all_peer = (unsigned __int8 *)tdls_find_all_peer(result, result + v49);
            if ( all_peer )
            {
              v61 = all_peer + 24;
              v62 = all_peer;
              LODWORD(v79) = all_peer[29];
              qdf_trace_msg(
                0,
                4u,
                "%s: vdev %d indicate TDLS teardown %02x:%02x:%02x:**:**:%02x",
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                "tdls_disable_offchan_and_teardown_links",
                *(unsigned __int8 *)(*v81[0] + 168),
                all_peer[24],
                all_peer[25],
                all_peer[26],
                v79);
              if ( (unsigned int)tdls_indicate_teardown(v81[0], v62, 0x1Au, v63, v64, v65, v66, v67, v68, v69, v70) )
              {
                LODWORD(v79) = v62[29];
                qdf_trace_msg(
                  0,
                  2u,
                  "%s: vdev %d teardown indication failed for peer %02x:%02x:%02x:**:**:%02x",
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  "tdls_disable_offchan_and_teardown_links",
                  *(unsigned __int8 *)(*v81[0] + 168),
                  v62[24],
                  v62[25],
                  v62[26],
                  v79);
              }
              else
              {
                tdls_decrement_peer_count(a1, v80, v71, v72, v73, v74, v75, v76, v77, v78);
                tdls_reset_peer(v81[0], v61);
                *(_WORD *)(v80 + v49 - 3) = 255;
                *(_BYTE *)(v80 + v49 - 1) = -1;
                qdf_mem_set((void *)(v80 + v49), 6u, 0);
              }
            }
          }
          result = v80;
          v49 += 9;
        }
        while ( *(unsigned __int16 *)(v80 + 200) > (unsigned int)(unsigned __int16)v50++ );
      }
    }
    else
    {
      v38 = *(unsigned __int8 *)(a1 + 168);
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev:%d is_ml_vdev:%d tdls_in_prog:%d conn_peers:%d Disable tdls at FW as second interface is coming up",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "tdls_disable_offchan_and_teardown_links",
        v38,
        is_mlo_vdev & 1,
        0,
        0);
      result = tdls_send_update_to_fw(v81[0], v80, 1, 1, 0, v38);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
