__int64 __fastcall sme_set_auto_rate_ldpc(__int64 a1, unsigned __int8 a2, char a3)
{
  unsigned int v3; // w20
  unsigned int v4; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v3 = *(_DWORD *)(a1 + 21704) & 0xFFFEFFFF | ((a3 & 1) << 16);
  *(_DWORD *)(a1 + 21704) = v3;
  v4 = wma_cli_set_command(a2, 128, v3, 1);
  if ( v4 )
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: failed to set auto rate LDPC cfg",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sme_set_auto_rate_ldpc");
  else
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: auto rate misc cfg set to 0x%08X",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sme_set_auto_rate_ldpc",
      v3);
  return v4;
}
