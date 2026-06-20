__int64 __fastcall wlan_ipa_init_perf_level(
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
  __int64 v10; // x4
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x8
  __int64 v20; // x10
  __int64 (__fastcall *v21)(__int64, __int64, __int64); // x10
  __int64 v22; // x2
  unsigned int v23; // w0
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 (__fastcall *v26)(__int64, __int64, __int64); // x8
  __int64 result; // x0
  const char *v28; // x2

  if ( (**(_BYTE **)(a1 + 1464) & 0x10) != 0 )
    return wlan_ipa_set_perf_level(a1, 0, 0, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: IPA clk scaling disabled. Set perf level to maximum %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_ipa_init_perf_level",
    800);
  v19 = *(__int64 **)(a1 + 1456);
  if ( !v19 || !*v19 || (v20 = *(_QWORD *)(*v19 + 152)) == 0 )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v11, v12, v13, v14, v15, v16, v17, v18, "cdp_ipa_set_perf_level");
    v10 = 16;
    goto LABEL_20;
  }
  v21 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v20 + 168);
  v22 = *(unsigned int *)(a1 + 7460);
  if ( !v21 )
    goto LABEL_11;
  if ( *((_DWORD *)v21 - 1) != 1328438065 )
    __break(0x822Au);
  v23 = v21(11, 800, v22);
  v10 = v23;
  if ( v23 )
  {
LABEL_20:
    v28 = "%s: CONS set perf profile failed: %d";
LABEL_21:
    qdf_trace_msg(0x61u, 2u, v28, v11, v12, v13, v14, v15, v16, v17, v18, "wlan_ipa_init_perf_level", v10);
    return 16;
  }
  v19 = *(__int64 **)(a1 + 1456);
  if ( !v19 )
  {
LABEL_22:
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cdp_ipa_set_perf_level",
      v10);
    v10 = 16;
LABEL_23:
    v28 = "%s: PROD set perf profile failed: %d";
    goto LABEL_21;
  }
  v22 = *(unsigned int *)(a1 + 7460);
LABEL_11:
  v24 = *v19;
  if ( !v24 )
    goto LABEL_22;
  v25 = *(_QWORD *)(v24 + 152);
  if ( !v25 )
    goto LABEL_22;
  v26 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v25 + 168);
  if ( !v26 )
    return 0;
  if ( *((_DWORD *)v26 - 1) != 1328438065 )
    __break(0x8228u);
  result = v26(10, 800, v22);
  v10 = (unsigned int)result;
  if ( (_DWORD)result )
    goto LABEL_23;
  return result;
}
