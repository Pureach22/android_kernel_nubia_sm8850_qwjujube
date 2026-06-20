__int64 __fastcall ucfg_fwol_set_mdns_config(
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
  __int64 psoc_obj; // x0
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  const char *v15; // x2

  if ( !a1 )
  {
    v15 = "%s: NULL pointer for psoc";
LABEL_9:
    qdf_trace_msg(0x66u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_fwol_set_mdns_config");
    return 4;
  }
  psoc_obj = fwol_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v15 = "%s: Failed to get FWOL Obj";
    goto LABEL_9;
  }
  v13 = *(__int64 (__fastcall **)(__int64, __int64))(psoc_obj + 1384);
  if ( !v13 )
    return 23;
  if ( *((_DWORD *)v13 - 1) != -113091191 )
    __break(0x8228u);
  return v13(a1, a2);
}
