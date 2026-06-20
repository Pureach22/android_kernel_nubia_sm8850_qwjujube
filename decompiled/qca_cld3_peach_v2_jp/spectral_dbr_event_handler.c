__int64 __fastcall spectral_dbr_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  void (__fastcall *v13)(__int64, __int64); // x8
  const char *v14; // x2

  if ( !a1 )
  {
    v14 = "%s: PDEV is NULL!";
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(a1 + 80)
    || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 0x13u)) == 0 )
  {
    v14 = "%s: spectral context is NULL!";
LABEL_9:
    qdf_trace_msg(0x56u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "spectral_dbr_event_handler");
    return 1;
  }
  v13 = *(void (__fastcall **)(__int64, __int64))(comp_private_obj + 216);
  if ( *((_DWORD *)v13 - 1) != 1690999366 )
    __break(0x8228u);
  v13(a1, a2);
  return 1;
}
