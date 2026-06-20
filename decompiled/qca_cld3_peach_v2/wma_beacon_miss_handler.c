__int64 __fastcall wma_beacon_miss_handler(
        __int64 *a1,
        unsigned int a2,
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
  _QWORD *context; // x23
  __int64 result; // x0
  __int64 v16; // x22
  _DWORD *v17; // x8
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x2

  context = _cds_get_context(53, (__int64)"wma_beacon_miss_handler", a4, a5, a6, a7, a8, a9, a10, a11);
  result = _qdf_mem_malloc(0xCu, "wma_beacon_miss_handler", 3100);
  if ( result )
  {
    v16 = result;
    if ( context )
    {
      v17 = (_DWORD *)context[1810];
      if ( v17 )
      {
        v18 = context[1604];
        if ( *(v17 - 1) != 2083539300 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v17)(v18, a2, 1, 1);
      }
    }
    *(_BYTE *)(v16 + 4) = a2;
    *(_DWORD *)v16 = 790594;
    *(_DWORD *)(v16 + 8) = a3;
    wma_send_msg((__int64)a1, 0x1042u, v16, 0);
    if ( (wmi_service_enabled(*a1, 0xACu, v19, v20, v21, v22, v23, v24, v25, v26) & 1) != 0 )
      v27 = a3;
    else
      v27 = a3 - 96;
    return wma_lost_link_info_handler(a1, a2, v27);
  }
  return result;
}
