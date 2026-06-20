__int64 __fastcall extract_esp_estimation_ev_param_tlv(
        __int64 a1,
        __int64 *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  int v13; // w8
  int v16; // w8

  if ( !a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid ESP Estimate Event buffer",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_esp_estimation_ev_param_tlv");
    return 4;
  }
  v11 = *a2;
  *a3 = *(_DWORD *)(*a2 + 8);
  v12 = *(unsigned int *)(v11 + 4);
  if ( (unsigned int)(v12 - 1) > 2 )
  {
    if ( (_DWORD)v12 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid pdev_id",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "convert_target_pdev_id_to_host_pdev_id");
      a3[1] = -1;
      return 16;
    }
    v16 = 255;
  }
  else
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 760) + 7748LL) & 1) != 0 )
    {
      v13 = *(_DWORD *)(*(_QWORD *)(a1 + 864) + 4 * v12 - 4);
      a3[1] = v13;
      if ( v13 != -1 )
        return 0;
      return 16;
    }
    v16 = v12 - 1;
  }
  a3[1] = v16;
  return 0;
}
