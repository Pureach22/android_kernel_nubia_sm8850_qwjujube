__int64 __fastcall tdls_discovery_timeout_peer_cb(
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
  __int64 v9; // x8
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x26
  __int64 v14; // x27
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x25
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x4
  __int64 v37; // x5
  __int64 v38; // x6
  __int64 v39; // x7
  const char *v40; // x2
  const char *v41; // x3
  __int64 v42; // [xsp+0h] [xbp-30h]
  __int64 v43; // [xsp+8h] [xbp-28h]
  __int64 v44; // [xsp+18h] [xbp-18h]
  _QWORD *v45[2]; // [xsp+20h] [xbp-10h] BYREF

  v45[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v45[0] = nullptr;
  if ( !a1 )
  {
    v40 = "%s: discovery time out vdev is null";
    v41 = "tdls_discovery_timeout_peer_cb";
    goto LABEL_21;
  }
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v11 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v40 = "%s: can't get psoc";
    v41 = "wlan_vdev_get_tdls_soc_obj";
LABEL_21:
    result = qdf_trace_msg(0, 2u, v40, a2, a3, a4, a5, a6, a7, a8, a9, v41);
    goto LABEL_22;
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(v11, 0xAu);
  if ( result )
  {
    result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu);
    if ( result )
    {
      v13 = 0;
      v14 = result + 8;
      v44 = result;
      do
      {
        for ( result = qdf_list_peek_front((_QWORD *)(v14 + 24 * v13), v45);
              !(_DWORD)result;
              result = qdf_list_peek_next((_QWORD *)(v14 + 24 * v13), v45[0], v45) )
        {
          while ( 1 )
          {
            v23 = v45[0];
            if ( v45[0] == (_QWORD *)-24LL )
            {
              v26 = 0;
              v24 = 0;
              v25 = 0;
              v27 = 0;
            }
            else
            {
              v24 = *((unsigned __int8 *)v45[0] + 24);
              v25 = *((unsigned __int8 *)v45[0] + 25);
              v26 = *((unsigned __int8 *)v45[0] + 26);
              v27 = *((unsigned __int8 *)v45[0] + 29);
            }
            LODWORD(v43) = *(unsigned __int8 *)(a1 + 104);
            LODWORD(v42) = *((_DWORD *)v45[0] + 9);
            qdf_trace_msg(
              0,
              8u,
              "%s: Peer: %02x:%02x:%02x:**:**:%02x link status %d, vdev id %d",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "tdls_discovery_timeout_peer_cb",
              v24,
              v25,
              v26,
              v27,
              v42,
              v43);
            if ( *((_DWORD *)v23 + 9) != 1 )
              break;
            if ( v23 == (_QWORD *)-24LL )
            {
              v38 = 0;
              v36 = 0;
              v37 = 0;
              v39 = 0;
            }
            else
            {
              v36 = *((unsigned __int8 *)v23 + 24);
              v37 = *((unsigned __int8 *)v23 + 25);
              v38 = *((unsigned __int8 *)v23 + 26);
              v39 = *((unsigned __int8 *)v23 + 29);
            }
            qdf_trace_msg(
              0,
              8u,
              "%s: %02x:%02x:%02x:**:**:%02x to idle state",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "tdls_discovery_timeout_peer_cb",
              v36,
              v37,
              v38,
              v39);
            tdls_set_peer_link_status(v23, 0, 4294967294LL);
          }
        }
        ++v13;
      }
      while ( v13 != 16 );
      *(_DWORD *)(v44 + 768) = 0;
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
