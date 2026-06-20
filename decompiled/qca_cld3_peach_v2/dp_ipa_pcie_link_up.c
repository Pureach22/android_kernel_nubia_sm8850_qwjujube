__int64 __fastcall dp_ipa_pcie_link_up(__int64 a1)
{
  __int64 *v1; // x20
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  int v12; // w3
  int v13; // w4
  int v14; // w5
  int v15; // w6
  int v16; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *(__int64 **)(a1 + 1128);
  v2 = hif_disable_rtpm();
  if ( v2 )
  {
    v11 = v2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: disable runtime failed: %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_ipa_pcie_link_up",
      v2);
    wlan_ipa_log_message(
      (int)"dp_ipa_pcie_link_up",
      (int)"disable runtime failed: %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      vars0);
  }
  else
  {
    return (unsigned int)hif_prevent_l1(*v1);
  }
  return v11;
}
