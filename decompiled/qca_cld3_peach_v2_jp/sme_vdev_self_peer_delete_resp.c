__int64 __fastcall sme_vdev_self_peer_delete_resp(
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
  unsigned int *v9; // x8
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  unsigned int v20; // w19

  v9 = *(unsigned int **)(a1 + 16);
  if ( v9 )
  {
    v10 = a1;
    if ( v9[316] == 6 )
    {
      wlan_objmgr_vdev_release_ref(*(_QWORD *)(a1 + 16), 0xBu, v9, a2, a3, a4, a5, a6, a7, a8, a9);
      v19 = "%s: vdev delete";
    }
    else
    {
      wlan_vdev_mlme_notify_set_mac_addr_response();
      v19 = "%s: mac update";
    }
    qdf_trace_msg(0x36u, 8u, v19, v11, v12, v13, v14, v15, v16, v17, v18, "sme_vdev_self_peer_delete_resp");
    a1 = v10;
    v20 = *(_DWORD *)(v10 + 8);
  }
  else
  {
    v20 = 4;
  }
  _qdf_mem_free(a1);
  return v20;
}
