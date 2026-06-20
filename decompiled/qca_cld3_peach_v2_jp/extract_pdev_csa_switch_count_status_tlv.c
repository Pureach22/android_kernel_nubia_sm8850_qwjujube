__int64 __fastcall extract_pdev_csa_switch_count_status_tlv(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
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
  __int64 (*v14)(void); // x9
  int v15; // w8

  if ( a2 )
  {
    v11 = *a2;
    v14 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3672LL);
    if ( *((_DWORD *)v14 - 1) != -2112860426 )
      __break(0x8229u);
    v15 = v14();
    *(_DWORD *)a3 = v15;
    *(_DWORD *)(a3 + 4) = *(_DWORD *)(v11 + 8);
    *(_DWORD *)(a3 + 8) = *(_DWORD *)(v11 + 12);
    *(_QWORD *)(a3 + 16) = a2[2];
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid CSA status event",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_pdev_csa_switch_count_status_tlv");
    return 4;
  }
}
