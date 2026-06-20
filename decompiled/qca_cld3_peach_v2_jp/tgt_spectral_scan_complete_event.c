__int64 __fastcall tgt_spectral_scan_complete_event(
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
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  const char *v15; // x2

  if ( !a1 )
  {
    v15 = "%s: PDEV is NULL!";
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(a1 + 80)
    || (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 0x13u)) == 0 )
  {
    v15 = "%s: spectral context is NULL!";
LABEL_9:
    qdf_trace_msg(0x56u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_spectral_scan_complete_event");
    return 0xFFFFFFFFLL;
  }
  v13 = *(__int64 (__fastcall **)(__int64, __int64))(comp_private_obj + 232);
  if ( *((_DWORD *)v13 - 1) != -1923167218 )
    __break(0x8228u);
  return v13(a1, a2);
}
