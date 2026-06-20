__int64 __fastcall os_if_spectral_netlink_deinit(
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
  const char *v10; // x2
  __int64 v11; // x0
  __int64 comp_private_obj; // x0
  __int64 v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  __int64 (__fastcall *v31)(_QWORD); // x8

  if ( !a1 )
  {
    v10 = "%s: PDEV is NULL!";
    return qdf_trace_msg(0x48u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "os_if_spectral_netlink_deinit");
  }
  if ( wlan_spectral_is_feature_disabled_pdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: Spectral feature is disabled";
    return qdf_trace_msg(0x48u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "os_if_spectral_netlink_deinit");
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v11, 0x13u)) == 0 )
  {
    v10 = "%s: Spectral context is NULL!";
    return qdf_trace_msg(0x48u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "os_if_spectral_netlink_deinit");
  }
  v13 = comp_private_obj;
  os_if_spectral_free_skb(a1, 0, a2, a3, a4, a5, a6, a7, a8, a9);
  os_if_spectral_free_skb(a1, 1u, v14, v15, v16, v17, v18, v19, v20, v21);
  result = os_if_spectral_free_skb(a1, 2u, v22, v23, v24, v25, v26, v27, v28, v29);
  v31 = *(__int64 (__fastcall **)(_QWORD))(v13 + 208);
  if ( v31 )
  {
    if ( *((_DWORD *)v31 - 1) != 883436542 )
      __break(0x8228u);
    return v31(a1);
  }
  return result;
}
