__int64 __fastcall wlan_spectral_psoc_close(
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
  __int64 comp_private_obj; // x0
  void (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x19
  const char *v14; // x2
  const char *v15; // x3

  if ( !a1 )
  {
    v14 = "%s: psoc is null";
    v15 = "wlan_spectral_psoc_close";
LABEL_12:
    qdf_trace_msg(0x56u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, v15);
    return 4;
  }
  if ( (*(_BYTE *)(a1 + 30) & 0x80) != 0 )
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
      "wlan_spectral_psoc_close");
    return 39;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x13u);
  if ( !comp_private_obj )
  {
    v14 = "%s: Spectral context is null";
    v15 = "wlan_spectral_psoc_target_detach";
    goto LABEL_12;
  }
  v11 = *(void (__fastcall **)(_QWORD))(comp_private_obj + 88);
  v12 = comp_private_obj;
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != 1588979751 )
      __break(0x8228u);
    v11(a1);
  }
  *(_QWORD *)(v12 + 8) = 0;
  return 0;
}
