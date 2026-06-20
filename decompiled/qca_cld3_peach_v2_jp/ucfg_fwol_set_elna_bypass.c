__int64 __fastcall ucfg_fwol_set_elna_bypass(
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
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 psoc_obj; // x0
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  const char *v16; // x2

  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v16 = "%s: NULL pointer for psoc";
LABEL_9:
    qdf_trace_msg(0x66u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "ucfg_fwol_set_elna_bypass");
    return 4;
  }
  psoc_obj = fwol_get_psoc_obj(*(_QWORD *)(v10 + 80));
  if ( !psoc_obj )
  {
    v16 = "%s: Failed to get FWOL Obj";
    goto LABEL_9;
  }
  v14 = *(__int64 (__fastcall **)(__int64, __int64))(psoc_obj + 1352);
  if ( !v14 )
    return 23;
  if ( *((_DWORD *)v14 - 1) != 128109696 )
    __break(0x8228u);
  return v14(v11, a2);
}
