__int64 __fastcall target_if_coap_offload_periodic_tx_disable(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v11; // x8
  __int64 v12; // x8
  __int64 (__fastcall *v13)(__int64, __int64, __int64); // x9
  __int64 v14; // x2
  __int64 v15; // x1

  v10 = *(_QWORD *)(a1 + 216);
  if ( v10 && (v11 = *(__int64 **)(v10 + 1240)) != nullptr && (v12 = *v11) != 0 )
  {
    v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v12 + 728) + 4976LL);
    if ( v13 )
    {
      v14 = a2;
      v15 = *(unsigned __int8 *)(a1 + 168);
      if ( *((_DWORD *)v13 - 1) != -1310025745 )
        __break(0x8229u);
      return v13(v12, v15, v14);
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
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_coap_offload_periodic_tx_disable");
    return 16;
  }
}
