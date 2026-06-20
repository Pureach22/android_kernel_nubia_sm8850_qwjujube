__int64 __fastcall wlan_spectral_pdev_obj_destroy_handler(
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
  __int64 result; // x0
  const char *v11; // x2
  __int64 v12; // x0
  __int64 comp_private_obj; // x0
  __int64 v14; // x21
  void (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x20

  if ( !a1 )
  {
    v11 = "%s: PDEV is NULL";
LABEL_14:
    qdf_trace_msg(0x56u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_spectral_pdev_obj_destroy_handler");
    return 16;
  }
  if ( (wlan_spectral_is_feature_disabled_pdev(a1) & 1) != 0 )
  {
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: Spectral feature is disabled",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_spectral_pdev_obj_destroy_handler");
    return 39;
  }
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 0x13u)) == 0 )
  {
    v11 = "%s: Spectral context is NULL!";
    goto LABEL_14;
  }
  v14 = comp_private_obj;
  result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x13u);
  if ( result )
  {
    v15 = *(void (__fastcall **)(_QWORD))(v14 + 72);
    v16 = result;
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != 883436542 )
        __break(0x8228u);
      v15(a1);
    }
    *(_QWORD *)(v16 + 16) = 0;
    wlan_objmgr_pdev_component_obj_detach(a1, 0x13u, v16);
    _qdf_mem_free(v16);
    return 0;
  }
  return result;
}
