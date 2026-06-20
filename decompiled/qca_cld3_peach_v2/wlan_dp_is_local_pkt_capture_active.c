__int64 wlan_dp_is_local_pkt_capture_active()
{
  __int64 context; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x8
  unsigned int (*v10)(void); // x8
  __int64 **v11; // x19
  __int64 v12; // x8
  unsigned int (__fastcall *v13)(__int64 **, __int64); // x8
  __int64 result; // x0
  const char *v15; // x2
  const char *v16; // x3
  unsigned int v17; // w0
  unsigned int v18; // w1
  __int64 v19; // [xsp+0h] [xbp-20h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, "wlan_dp_is_local_pkt_capture_active");
  v19 = 0;
  if ( !context || !*(_QWORD *)context )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "cdp_txrx_get_psoc_param",
      0,
      0,
      0,
      v20);
LABEL_16:
    v15 = "%s: Unable to fetch monitor flags.";
    v16 = "wlan_dp_is_local_pkt_capture_active";
    v17 = 69;
    v18 = 2;
LABEL_17:
    qdf_trace_msg(v17, v18, v15, v1, v2, v3, v4, v5, v6, v7, v8, v16, v19);
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  v9 = *(_QWORD *)(*(_QWORD *)context + 8LL);
  if ( !v9 )
    goto LABEL_16;
  v10 = *(unsigned int (**)(void))(v9 + 192);
  if ( !v10 )
    goto LABEL_16;
  v11 = (__int64 **)context;
  if ( *((_DWORD *)v10 - 1) != 875927212 )
    __break(0x8228u);
  if ( v10() )
    goto LABEL_16;
  if ( !*v11 )
  {
    v15 = "%s: Invalid Instance";
    v16 = "cdp_cfg_get";
    v17 = 137;
    v18 = 8;
    goto LABEL_17;
  }
  v12 = **v11;
  if ( !v12 )
    goto LABEL_18;
  v13 = *(unsigned int (__fastcall **)(__int64 **, __int64))(v12 + 264);
  if ( !v13 )
    goto LABEL_18;
  if ( *((_DWORD *)v13 - 1) != -1095293032 )
    __break(0x8228u);
  if ( !v13(v11, 22) )
    goto LABEL_18;
  result = 1;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
