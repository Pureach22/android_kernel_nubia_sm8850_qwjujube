bool __fastcall lim_set_rnr_ie_from_start_bss_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v11; // x2

  if ( !*(_WORD *)a2 )
    return 1;
  if ( *(unsigned __int8 *)(a2 + 2) != 201 )
  {
    v11 = "%s: EID: %d is not rnr";
    goto LABEL_7;
  }
  if ( *(unsigned __int8 *)(a2 + 3) <= 1u )
  {
    v11 = "%s: invalid RNR IE len: %d";
LABEL_7:
    qdf_trace_msg(0x35u, 8u, v11, a4, a5, a6, a7, a8, a9, a10, a11, "lim_set_rnr_ie_from_start_bss_req");
    return 0;
  }
  return (unsigned int)lim_populate_rnr_entry(a1, a3, a2 + 2) == 0;
}
