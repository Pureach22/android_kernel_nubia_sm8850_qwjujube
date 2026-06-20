__int64 __fastcall tdls_ct_idle_handler(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x4
  __int64 v10; // x20
  __int64 vdev; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 peer; // x0
  __int64 v31; // x20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  __int64 v50; // [xsp+18h] [xbp-18h] BYREF
  __int64 *v51[2]; // [xsp+20h] [xbp-10h] BYREF

  v51[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v9 = *(unsigned __int8 *)(result + 2);
    if ( (unsigned int)v9 >= 8 )
    {
      result = qdf_trace_msg(
                 0,
                 8u,
                 "%s: invalid peer index %d%02x:%02x:%02x:**:**:%02x",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "tdls_ct_idle_handler",
                 *(unsigned __int8 *)(result + 8));
      goto LABEL_17;
    }
    v10 = result;
    vdev = tdls_get_vdev(*(_QWORD *)(result - 9 * v9 - 32), 17);
    if ( !vdev )
    {
      result = qdf_trace_msg(
                 0,
                 2u,
                 "%s: Unable to fetch the vdev",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "tdls_ct_idle_handler");
      goto LABEL_17;
    }
    v20 = vdev;
    v51[0] = nullptr;
    v50 = 0;
    if ( !(unsigned int)tdls_get_vdev_objects(vdev, v51, &v50) )
    {
      if ( (*(_BYTE *)(v10 + 1) & 1) != 0 )
      {
        peer = tdls_find_peer(v51[0], v10 + 3);
        if ( peer )
        {
          v31 = peer;
          qdf_trace_msg(
            0,
            8u,
            "%s: %02x:%02x:%02x:**:**:%02x tx_pkt: %d, rx_pkt: %d, idle_packet_n: %d",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "tdls_ct_process_idle_handler",
            *(unsigned __int8 *)(peer + 24),
            *(unsigned __int8 *)(peer + 25),
            *(unsigned __int8 *)(peer + 26),
            *(unsigned __int8 *)(peer + 29),
            *(unsigned __int16 *)(peer + 44),
            *(unsigned __int16 *)(peer + 46),
            *(_DWORD *)((char *)v51[0] + (unsigned __int64)&qword_2E8 + 4));
          v40 = *(_DWORD *)((char *)v51[0] + (unsigned __int64)&qword_2E8 + 4);
          if ( v40 <= *(unsigned __int16 *)(v31 + 44) || v40 <= *(unsigned __int16 *)(v31 + 46) )
          {
            qdf_trace_msg(
              0,
              8u,
              "%s: tdls link to %02x:%02x:%02x:**:**:%02x back to normal, will stay",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "tdls_ct_process_idle_handler",
              *(unsigned __int8 *)(v31 + 24),
              *(unsigned __int8 *)(v31 + 25),
              *(unsigned __int8 *)(v31 + 26),
              *(unsigned __int8 *)(v31 + 29));
          }
          else
          {
            qdf_trace_msg(
              0,
              4u,
              "%s: trigger tdls link to %02x:%02x:%02x:**:**:%02x down",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "tdls_ct_process_idle_handler",
              *(unsigned __int8 *)(v31 + 24),
              *(unsigned __int8 *)(v31 + 25),
              *(unsigned __int8 *)(v31 + 26),
              *(unsigned __int8 *)(v31 + 29));
            tdls_indicate_teardown(v51[0], (unsigned __int8 *)v31, 0x1Au, v41, v42, v43, v44, v45, v46, v47, v48);
          }
          goto LABEL_16;
        }
        v49 = "%s: Invalid tdls idle timer expired";
      }
      else
      {
        v49 = "%s: peer doesn't exists";
      }
      qdf_trace_msg(0, 2u, v49, v22, v23, v24, v25, v26, v27, v28, v29, "tdls_ct_process_idle_handler");
    }
LABEL_16:
    result = wlan_objmgr_vdev_release_ref(v20, 0x11u, v21, v22, v23, v24, v25, v26, v27, v28, v29);
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
