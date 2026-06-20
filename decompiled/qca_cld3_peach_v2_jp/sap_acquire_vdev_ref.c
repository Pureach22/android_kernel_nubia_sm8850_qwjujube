__int64 __fastcall sap_acquire_vdev_ref(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 v13; // w19
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( *(_QWORD *)(a2 + 16) )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid vdev obj in sap context",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sap_acquire_vdev_ref");
    return 5;
  }
  else
  {
    v13 = a3;
    v14 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 44);
    if ( v14 )
    {
      *(_QWORD *)(a2 + 16) = v14;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: vdev is NULL for vdev_id: %u",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sap_acquire_vdev_ref",
        v13);
      return 16;
    }
  }
}
