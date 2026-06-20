__int64 __fastcall tgt_if_regulatory_is_11d_offloaded(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 rx_ops; // x0
  __int64 (__fastcall *v5)(_QWORD); // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  char v14; // w0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 2800)) != 0 )
  {
    v2 = *(_QWORD *)(v1 + 16);
    rx_ops = target_if_regulatory_get_rx_ops();
    if ( v2 )
    {
      if ( !rx_ops )
        goto LABEL_13;
      v5 = *(__int64 (__fastcall **)(_QWORD))(rx_ops + 168);
      if ( !v5 )
        goto LABEL_13;
      if ( *((_DWORD *)v5 - 1) != -1548408 )
        __break(0x8228u);
      if ( (v5(a1) & 1) == 0 )
      {
LABEL_13:
        v14 = wmi_service_enabled(v2, 132);
        return v14 & 1;
      }
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: Ignore fw reg 11d offload indication",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "tgt_if_regulatory_is_11d_offloaded");
    }
  }
  else
  {
    target_if_regulatory_get_rx_ops();
  }
  v14 = 0;
  return v14 & 1;
}
