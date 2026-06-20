__int64 __fastcall tgt_if_regulatory_set_tpc_power(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w20
  unsigned int pdev_id_from_vdev_id; // w0
  __int64 pdev_by_id; // x0
  __int64 *v8; // x8
  __int64 v9; // x8
  __int64 v10; // x21
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v4 = a2;
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(a1, a2, 22);
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, pdev_id_from_vdev_id, 22);
  if ( pdev_by_id && (v8 = *(__int64 **)(pdev_by_id + 1240)) != nullptr && (v9 = *v8) != 0 )
  {
    v10 = pdev_by_id;
    v11 = wmi_unified_send_set_tpc_power_cmd(v9, v4, a3);
    if ( v11 )
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: send tpc power cmd failed, status: %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "tgt_if_regulatory_set_tpc_power",
        v11);
    pdev_by_id = v10;
  }
  else
  {
    v11 = 16;
  }
  wlan_objmgr_pdev_release_ref(pdev_by_id, 22);
  return v11;
}
