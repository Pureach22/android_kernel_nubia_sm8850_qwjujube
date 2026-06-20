__int64 __fastcall tdls_get_correct_vdev(__int64 a1, unsigned __int8 *a2)
{
  int v4; // t1
  unsigned __int8 *ie_ptr_from_eid; // x0
  __int64 v6; // x21
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v8; // x21
  __int64 comp_private_obj; // x0
  unsigned int *v10; // x8
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
  char v28[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)a2;
  v28[0] = 0;
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x65u, a2 + 49, (unsigned __int16)v4 - 29);
  if ( ie_ptr_from_eid )
  {
    v6 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
    if ( v6 )
    {
      if ( (wlan_get_connected_vdev_by_bssid(*(_QWORD *)(*(_QWORD *)a1 + 216LL), ie_ptr_from_eid + 2, v28) & 1) != 0 )
      {
        vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v6, v28[0], 0x11u);
        if ( vdev_by_id_from_pdev )
        {
          v8 = (__int64)vdev_by_id_from_pdev;
          comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj((__int64)vdev_by_id_from_pdev, 0xAu);
          v10 = (unsigned int *)(unsigned __int8)v28[0];
          a1 = comp_private_obj;
          *((_DWORD *)a2 + 2) = (unsigned __int8)v28[0];
          wlan_objmgr_vdev_release_ref(v8, 0x11u, v10, v11, v12, v13, v14, v15, v16, v17, v18);
          qdf_trace_msg(
            0,
            8u,
            "%s: received discovery response on vdev %d",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "tdls_get_correct_vdev",
            *((unsigned int *)a2 + 2));
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a1;
}
