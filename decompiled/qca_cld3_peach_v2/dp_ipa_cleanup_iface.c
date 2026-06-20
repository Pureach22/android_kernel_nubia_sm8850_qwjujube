__int64 __fastcall dp_ipa_cleanup_iface(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = ipa_wdi_dereg_intf_per_inst(a1, a3);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: ipa_wdi_dereg_intf: IPA pipe deregistration failed: ret=%d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_ipa_cleanup_iface",
      (unsigned int)result);
    return 16;
  }
  return result;
}
