__int64 __fastcall target_if_coap_offload_periodic_tx_enable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 (*v11)(void); // x8

  v9 = *(_QWORD *)(a1 + 216);
  if ( v9 && (v10 = *(_QWORD *)(v9 + 1240)) != 0 && *(_QWORD *)v10 )
  {
    v11 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)v10 + 728LL) + 4968LL);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != -66533182 )
        __break(0x8228u);
      return v11();
    }
    else
    {
      return 11;
    }
  }
  else
  {
    qdf_trace_msg(
      0x9Cu,
      2u,
      "%s: Invalid PDEV WMI handle",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_coap_offload_periodic_tx_enable");
    return 16;
  }
}
