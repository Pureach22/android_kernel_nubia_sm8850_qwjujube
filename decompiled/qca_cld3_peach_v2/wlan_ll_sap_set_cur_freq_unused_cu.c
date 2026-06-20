__int64 __fastcall wlan_ll_sap_set_cur_freq_unused_cu(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 105);
  if ( v5 )
  {
    v14 = v5;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v5, 0x34u);
    if ( comp_private_obj )
    {
      *(_DWORD *)(comp_private_obj + 32) = a3;
      qdf_trace_msg(
        0xA1u,
        8u,
        "%s: vdev %d set unused CU to %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "ll_sap_set_cur_freq_unused_cu",
        v4,
        a3);
      wlan_objmgr_vdev_release_ref(v14, 0x69u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: ll_sap obj null ref by vdev: %u",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "ll_sap_set_cur_freq_unused_cu",
        v4);
      wlan_objmgr_vdev_release_ref(v14, 0x69u, v33, v34, v35, v36, v37, v38, v39, v40, v41);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d is null",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "ll_sap_set_cur_freq_unused_cu",
      v4);
  }
  return a3;
}
