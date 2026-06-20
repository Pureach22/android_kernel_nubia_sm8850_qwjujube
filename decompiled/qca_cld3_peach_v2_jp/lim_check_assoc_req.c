_QWORD *__fastcall lim_check_assoc_req(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x4
  __int64 v13; // x7
  int v14; // w8
  int v15; // w9
  int v16; // w10
  __int64 v20; // x5
  __int64 v21; // x6
  int v22; // w9
  const char *v23; // x2
  _QWORD *result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  int v34; // w8
  unsigned __int8 *v35; // x9
  __int64 v36; // x19
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // [xsp+8h] [xbp-18h]
  int v50; // [xsp+10h] [xbp-10h]

  if ( *(_QWORD *)(a4 + 16) )
  {
    if ( *(_DWORD *)(a4 + 88) == 2 )
    {
      v12 = *(unsigned __int16 *)(a4 + 8);
      if ( a3 )
      {
        v13 = *a3;
        v14 = a3[1];
        v15 = a3[2];
        v16 = a3[5];
      }
      else
      {
        v15 = 0;
        v13 = 0;
        v14 = 0;
        v16 = 0;
      }
      v23 = "%s: Rcvd unexpected ASSOC REQ, sessionid: %d sys sub_type: %d for role: %d from: %02x:%02x:%02x:**:**:%02x";
      v50 = v16;
      v49 = v15;
      v20 = a2;
      v21 = 2;
      goto LABEL_22;
    }
    if ( wlan_ser_is_non_scan_cmd_type_in_vdev_queue(*(_QWORD *)(a4 + 16), 0x16u, a5, a6, a7, a8, a9, a10, a11, a12) )
    {
      v12 = *(unsigned __int8 *)(a4 + 10);
      v20 = *(unsigned int *)(a4 + 88);
      if ( a3 )
      {
        v21 = *a3;
        v13 = a3[1];
        v14 = a3[2];
        v22 = a3[5];
      }
      else
      {
        v14 = 0;
        v21 = 0;
        v13 = 0;
        v22 = 0;
      }
      v23 = "%s: drop ASSOC REQ on vdev %d role: %d from: %02x:%02x:%02x:**:**:%02x when stop bss pending";
LABEL_21:
      v49 = v22;
LABEL_22:
      qdf_trace_msg(
        0x35u,
        2u,
        v23,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "lim_check_assoc_req",
        v12,
        v20,
        v21,
        v13,
        v14,
        v49,
        v50);
      return &off_0 + 4;
    }
    if ( *(_DWORD *)(a4 + 72) == 17 )
    {
      v12 = *(unsigned __int16 *)(a4 + 8);
      v20 = *(unsigned int *)(a4 + 88);
      if ( a3 )
      {
        v21 = *a3;
        v13 = a3[1];
        v14 = a3[2];
        v22 = a3[5];
      }
      else
      {
        v14 = 0;
        v21 = 0;
        v13 = 0;
        v22 = 0;
      }
      v23 = "%s: drop ASSOC REQ on sessionid: %d role: %d from: %02x:%02x:%02x:**:**:%02x in limMlmState: %d";
      v50 = 17;
      goto LABEL_21;
    }
    result = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21552), a3, 7u);
    if ( !result )
      return result;
    v33 = result[11];
    if ( (*(_DWORD *)(v33 + 16) & 0xFFFFFFFD) != 0 )
    {
      wlan_objmgr_peer_release_ref((__int64)result, 7u, v25, v26, v27, v28, v29, v30, v31, v32);
      return nullptr;
    }
    v34 = *(unsigned __int8 *)(v33 + 104);
    if ( a3 )
    {
      v35 = a3;
      v36 = (__int64)result;
      v37 = *v35;
      v38 = v35[1];
      v39 = v35[2];
      v40 = v35[5];
    }
    else
    {
      v36 = (__int64)result;
      v39 = 0;
      v37 = 0;
      v38 = 0;
      v40 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: duplicate mac detected!!! Peer %02x:%02x:%02x:**:**:%02x present on STA vdev %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_peer_present_on_any_sta",
      v37,
      v38,
      v39,
      v40,
      v34);
    wlan_objmgr_peer_release_ref(v36, 7u, v41, v42, v43, v44, v45, v46, v47, v48);
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: vdev is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "lim_check_assoc_req");
  }
  return &off_0 + 4;
}
