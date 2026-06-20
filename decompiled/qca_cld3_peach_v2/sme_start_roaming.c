__int64 __fastcall sme_start_roaming(__int64 a1, __int64 a2, char a3, unsigned int a4)
{
  unsigned int v7; // w19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  int rso_pending_disable_req_bitmap; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  v7 = a2;
  v8 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *(_QWORD *)(a1 + 21624),
         a2,
         77);
  if ( v8 )
  {
    v17 = v8;
    rso_pending_disable_req_bitmap = mlme_get_rso_pending_disable_req_bitmap(*(_QWORD *)(a1 + 21624), v7);
    if ( ((unsigned __int8)rso_pending_disable_req_bitmap & (unsigned __int8)a4) != 0 )
    {
      mlme_set_rso_pending_disable_req_bitmap(*(_QWORD *)(a1 + 21624), v7, a4, 1);
      wlan_objmgr_vdev_release_ref(v17, 0x4Du, v27, v28, v29, v30, v31, v32, v33, v34, v35);
      return 0;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(
        v17,
        0x4Du,
        (unsigned int *)(rso_pending_disable_req_bitmap & a4),
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26);
      return wlan_cm_enable_rso(*(_QWORD *)(a1 + 21632), v7, a4, a3, v37, v38, v39, v40, v41, v42, v43, v44);
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: vdev object is NULL for vdev %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "sme_start_roaming",
      (unsigned __int8)v7);
    return 4;
  }
}
