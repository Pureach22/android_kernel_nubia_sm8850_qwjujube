__int64 __fastcall extract_dpd_status_ev_param_tlv(
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
  int v14; // w8

  if ( a2 )
  {
    v11 = *a2;
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3688LL);
    if ( *((_DWORD *)v13 - 1) != -2112860426 )
      __break(0x8228u);
    v14 = v13();
    *a3 = v14;
    a3[1] = *(_DWORD *)(v11 + 8);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid get dpd_status event",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_dpd_status_ev_param_tlv");
    return 4;
  }
}
