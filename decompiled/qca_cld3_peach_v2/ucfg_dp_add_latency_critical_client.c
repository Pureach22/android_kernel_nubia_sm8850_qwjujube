__int64 __fastcall ucfg_dp_add_latency_critical_client(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 (*v32)(void); // x8
  unsigned int v38; // w9

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: No dp_link for objmgr vdev %pK",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "dp_add_latency_critical_client",
             a1);
  }
  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !result )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: No dp_link for objmgr vdev %pK",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "dp_add_latency_critical_client",
             a1);
  v21 = *(_QWORD **)(result + 32);
  if ( !v21 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Invalid dp_intf for dp_link %pK (%02x:%02x:%02x:**:**:%02x)",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "dp_add_latency_critical_client",
             result,
             *(unsigned __int8 *)(result + 25),
             *(unsigned __int8 *)(result + 26),
             *(unsigned __int8 *)(result + 27),
             *(unsigned __int8 *)(result + 30));
  if ( (a2 | 2) == 3 )
  {
    _X8 = (unsigned int *)(*v21 + 876LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr(_X8);
    while ( __stxr(v38 + 1, _X8) );
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: Adding latency critical connection for vdev %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_add_latency_critical_client",
      *(unsigned __int8 *)(result + 24));
    result = _cds_get_context(71, "dp_add_latency_critical_client");
    if ( result && *(_QWORD *)result && (v31 = *(_QWORD *)(*(_QWORD *)result + 64LL)) != 0 )
    {
      v32 = *(__int64 (**)(void))(v31 + 256);
      if ( v32 )
      {
        if ( *((_DWORD *)v32 - 1) != 1845374433 )
          __break(0x8228u);
        return v32();
      }
    }
    else
    {
      return qdf_trace_msg(
               0x89u,
               8u,
               "%s: Invalid Instance:",
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "cdp_vdev_inform_ll_conn");
    }
  }
  return result;
}
