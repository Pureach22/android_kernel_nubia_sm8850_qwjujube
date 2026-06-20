__int64 __fastcall wlan_dp_spm_intf_ctx_init(
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
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( !*(_QWORD *)(*(_QWORD *)a1 + 2952LL) || *(_DWORD *)(a1 + 28) )
    return 11;
  if ( *(_QWORD *)(a1 + 3736) )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Module already initialized!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_dp_spm_intf_ctx_init");
    return 6;
  }
  else
  {
    v11 = _qdf_mem_malloc(0x1A18u, "wlan_dp_spm_intf_ctx_init", 1068);
    if ( v11 )
    {
      v20 = (_QWORD *)v11;
      qdf_mem_set((void *)(v11 + 528), 0x1800u, 0);
      *v20 = 0;
      *(_QWORD *)(a1 + 3736) = v20;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: SPM interface created",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_dp_spm_intf_ctx_init");
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Unable to allocate spm interface",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_dp_spm_intf_ctx_init");
      return 2;
    }
  }
}
