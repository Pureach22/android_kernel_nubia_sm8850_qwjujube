__int64 __fastcall ttlm_subst_ap_action_inprogress_event(
        __int64 a1,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12)
{
  __int64 result; // x0
  __int64 v14; // x19
  __int64 bsspeer; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  double v26; // d0
  int v27; // w0
  int v28; // w20
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _BOOL4 v36; // w20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  if ( a2 == 3 )
  {
    lim_send_ttlm_action_rsp_frame(
      *(_BYTE *)(a12 + 12),
      *(_DWORD *)(a12 + 8),
      (unsigned __int8 *)(a12 + 13),
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10);
    wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, v38, v39, v40, v41, v42, v43, v44, v45);
    return 1;
  }
  else if ( a2 == 4 )
  {
    result = mlo_get_first_vdev_by_ml_peer(a1);
    if ( result )
    {
      v14 = result;
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(result, 0x5Au);
      if ( bsspeer )
      {
        v25 = bsspeer;
        v26 = ttlm_valid_n_copy_for_rx_req(v14, bsspeer, a12);
        v28 = v27;
        wlan_objmgr_peer_release_ref(v25, 0x5Au, v26, v29, v30, v31, v32, v33, v34, v35);
        v36 = v28 == 0;
      }
      else
      {
        v36 = 0;
      }
      wlan_objmgr_vdev_release_ref(v14, 0x5Au, v16, v17, v18, v19, v20, v21, v22, v23, v24);
      return v36;
    }
  }
  else
  {
    return 0;
  }
  return result;
}
