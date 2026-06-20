__int64 __fastcall extract_halphy_cal_ev_param_tlv(
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
  __int64 v11; // x20
  __int64 (*v13)(void); // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w4

  if ( a2 )
  {
    v11 = *a2;
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3672LL);
    if ( *((_DWORD *)v13 - 1) != -2112860426 )
      __break(0x8228u);
    *a3 = v13();
    v22 = *(_DWORD *)(v11 + 8);
    if ( v22 >= 2 )
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Unknown set halphy status code(%u) from WMI",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "set_halphy_cal_fw_status_to_host_status");
      v22 = 1;
    }
    a3[1] = v22;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid set halphy_status event",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_halphy_cal_ev_param_tlv");
    return 4;
  }
}
