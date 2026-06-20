__int64 __fastcall wlan_cm_get_sae_auth_ta(__int64 a1, unsigned __int8 a2, void *a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 ext_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int *v23; // x8
  __int64 v24; // x21
  unsigned int v25; // w20

  if ( a1 && (vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du)) != nullptr )
  {
    v13 = (__int64)vdev_by_id_from_pdev;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl((__int64)vdev_by_id_from_pdev, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( ext_hdl )
    {
      v23 = (unsigned int *)*(unsigned __int8 *)(ext_hdl + 271);
      if ( *(_BYTE *)(ext_hdl + 271) )
      {
        v24 = ext_hdl;
        qdf_mem_copy(a3, (const void *)(ext_hdl + 265), 6u);
        v25 = 0;
        *(_BYTE *)(v24 + 271) = 0;
      }
      else
      {
        v25 = 6;
      }
    }
    else
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev legacy private object is NULL",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "wlan_cm_get_sae_auth_ta");
      v25 = 4;
    }
    wlan_objmgr_vdev_release_ref(v13, 0x4Du, v23, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  else
  {
    return 4;
  }
  return v25;
}
