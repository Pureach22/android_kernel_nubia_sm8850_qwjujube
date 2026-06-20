__int64 __fastcall ucfg_fwol_get_elna_bypass(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x19
  _QWORD *psoc_obj; // x0
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  const char *v20; // x2

  v12 = *(_QWORD *)(a1 + 216);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v20 = "%s: NULL pointer for psoc";
LABEL_9:
    qdf_trace_msg(0x66u, 2u, v20, a5, a6, a7, a8, a9, a10, a11, a12, "ucfg_fwol_get_elna_bypass");
    return 4;
  }
  psoc_obj = (_QWORD *)fwol_get_psoc_obj(*(_QWORD *)(v12 + 80));
  if ( !psoc_obj )
  {
    v20 = "%s: Failed to get FWOL Obj";
    goto LABEL_9;
  }
  v18 = (__int64 (__fastcall *)(__int64, __int64))psoc_obj[170];
  psoc_obj[165] = a3;
  psoc_obj[166] = a4;
  if ( !v18 )
    return 23;
  if ( *((_DWORD *)v18 - 1) != -220080796 )
    __break(0x8228u);
  return v18(v13, a2);
}
