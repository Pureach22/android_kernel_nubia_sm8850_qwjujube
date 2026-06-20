__int64 __fastcall dp_ipa_op_response(
        _QWORD *a1,
        char a2,
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
  __int64 v11; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  void (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x1

  if ( a2 || (v11 = a1[9]) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: Invalid instance", a4, a5, a6, a7, a8, a9, a10, a11, "dp_ipa_op_response");
    return 16;
  }
  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL)) & 1) == 0 )
    return 0;
  v22 = (void (__fastcall *)(__int64, __int64))a1[2306];
  if ( !v22 )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: IPA callback function is not registered",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_ipa_op_response");
    _qdf_mem_free(a3);
    return 16;
  }
  v23 = a1[2307];
  if ( *((_DWORD *)v22 - 1) != -177782713 )
    __break(0x8228u);
  v22(a3, v23);
  return 0;
}
