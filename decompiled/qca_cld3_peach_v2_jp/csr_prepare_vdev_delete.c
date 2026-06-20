__int64 __fastcall csr_prepare_vdev_delete(
        __int64 *a1,
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
  __int64 v10; // x19
  __int64 v11; // x9
  __int64 result; // x0
  __int64 *v14; // x21
  char *v15; // x8
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v10 = *(unsigned __int8 *)(a2 + 104);
  if ( (unsigned int)v10 > 5 )
    return 4;
  v11 = a1[2153];
  result = 4;
  if ( v11
    && a1
    && v11 + 96LL * *(unsigned __int8 *)(a2 + 104)
    && *(_BYTE *)(v11 + 96LL * *(unsigned __int8 *)(a2 + 104) + 1) == 1 )
  {
    v14 = a1;
    v15 = (char *)a1 + 4 * v10;
    if ( *((_DWORD *)v15 + 4293) == 3 && *((_DWORD *)v15 + 4299) == 5 )
    {
      v16 = a2;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Stop Wait for key timer and change substate to eCSR_ROAM_SUBSTATE_NONE",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "csr_prepare_vdev_delete");
      cm_stop_wait_for_key_timer(v14[2694], (unsigned int)v10);
      csr_roam_substate_change((__int64)v14, 0, v10, v17, v18, v19, v20, v21, v22, v23, v24);
      a2 = v16;
    }
    wlan_ser_vdev_queue_disable(a2, a3, a4, a5, a6, a7, a8, a9, a10);
    wlan_serialization_purge_all_cmd_by_vdev_id(v14[2695], v10, v25, v26, v27, v28, v29, v30, v31, v32);
    if ( v14[2745] )
    {
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: no close session callback registered",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "csr_prepare_vdev_delete");
      return 16;
    }
  }
  return result;
}
