__int64 __fastcall mlo_mgr_link_switch_get_assoc_vdev(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  unsigned int v3; // w21
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x0

  if ( result )
  {
    v1 = *(_QWORD *)(result + 1360);
    if ( v1 )
    {
      v2 = result;
      qdf_mutex_acquire(v1 + 1656);
      v3 = *(_DWORD *)(*(_QWORD *)(v1 + 3880) + 164LL);
      qdf_mutex_release(v1 + 1656);
      if ( v3 >= 2 )
      {
        v12 = *(_QWORD *)(*(_QWORD *)(v2 + 1360) + 3880LL);
        if ( *(_BYTE *)(v12 + 172) == 1 )
        {
          v13 = *(_QWORD *)(v2 + 216);
          if ( v13 )
          {
            v14 = *(_QWORD *)(v13 + 80);
            if ( v14 )
              return ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                       v14,
                       *(unsigned __int8 *)(v12 + 144),
                       90);
          }
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: PSOC NULL",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "mlo_mgr_link_switch_get_assoc_vdev");
        }
      }
    }
    return 0;
  }
  return result;
}
