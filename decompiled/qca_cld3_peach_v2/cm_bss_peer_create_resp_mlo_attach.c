__int64 __fastcall cm_bss_peer_create_resp_mlo_attach(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  __int64 v13; // x0
  _QWORD *peer_by_mac; // x0
  __int64 v15; // x20
  unsigned int v16; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  __int64 result; // x0
  __int64 v30; // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v31[22]; // [xsp+10h] [xbp-B0h] BYREF

  v31[21] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  memset(v31, 0, 168);
  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v12 = *(_QWORD *)(a1 + 216);
    if ( v12
      && (v13 = *(_QWORD *)(v12 + 80)) != 0
      && (peer_by_mac = wlan_objmgr_get_peer_by_mac(v13, a2, 0x4Du)) != nullptr )
    {
      v15 = (__int64)peer_by_mac;
      LOBYTE(v30) = 1;
      qdf_mem_copy(v31, (const void *)(a1 + 74), 6u);
      BYTE6(v31[0]) = *(_BYTE *)(a1 + 93);
      v16 = wlan_mlo_peer_create(a1, v15, &v30, 0, 0);
      if ( v16 )
      {
        if ( a2 )
        {
          v25 = *a2;
          v26 = a2[1];
          v27 = a2[2];
          v28 = a2[5];
        }
        else
        {
          v27 = 0;
          v25 = 0;
          v26 = 0;
          v28 = 0;
        }
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Failed to attach MLO peer %02x:%02x:%02x:**:**:%02x",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "cm_bss_peer_create_resp_mlo_attach",
          v25,
          v26,
          v27,
          v28);
      }
      wlan_objmgr_peer_release_ref(v15, 0x4Du, v17, v18, v19, v20, v21, v22, v23, v24);
      result = v16;
    }
    else
    {
      result = 29;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
