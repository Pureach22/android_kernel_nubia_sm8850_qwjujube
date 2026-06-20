__int64 __fastcall wma_init_max_no_of_peers(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _BYTE *v11; // x20
  _QWORD *context; // x0
  _DWORD *target_info_handle; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  __int64 result; // x0

  if ( a1 )
  {
    v11 = (_BYTE *)(a1 + 3360);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__wma_validate_handle",
      "wma_get_ini_handle");
    v11 = nullptr;
  }
  context = _cds_get_context(61, (__int64)"wma_init_max_no_of_peers", a3, a4, a5, a6, a7, a8, a9, a10);
  target_info_handle = (_DWORD *)hif_get_target_info_handle((__int64)context);
  if ( v11 )
  {
    if ( *target_info_handle == 83886081 )
      v22 = 14;
    else
      v22 = 32;
    if ( v22 >= a2 )
      result = a2;
    else
      result = v22;
    *v11 = result;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: NULL WMA ini handle",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wma_init_max_no_of_peers");
    return 0;
  }
  return result;
}
