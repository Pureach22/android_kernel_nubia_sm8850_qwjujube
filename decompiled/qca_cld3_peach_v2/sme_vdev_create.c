__int64 __fastcall sme_vdev_create(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v39; // [xsp+0h] [xbp-10h]

  v39 = *(_DWORD *)a2;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: addr:%02x:%02x:%02x:**:**:%02x opmode:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sme_vdev_create",
    *(unsigned __int8 *)(a2 + 24),
    *(unsigned __int8 *)(a2 + 25),
    *(unsigned __int8 *)(a2 + 26),
    *(unsigned __int8 *)(a2 + 29),
    v39);
  v20 = wlan_objmgr_vdev_obj_create(*(_QWORD *)(a1 + 21632), a2, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( v20 )
  {
    v29 = v20;
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v20, 0xBu, v21, v22, v23, v24, v25, v26, v27, v28) )
    {
      wlan_objmgr_vdev_obj_delete(v29, v30, v31, v32, v33, v34, v35, v36, v37);
      return 0;
    }
    else
    {
      qdf_trace(52, 0x30u, *(unsigned __int8 *)(v29 + 168), 0);
      return v29;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to create vdev object",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "sme_vdev_create");
    return 0;
  }
}
