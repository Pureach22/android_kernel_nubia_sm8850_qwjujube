// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_65DFD4(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        const char *a11)
{
  int v11; // w19

  if ( !v11 )
    return ucfg_fwol_get_all_allowlist_params();
  qdf_trace_msg(0x49u, 2u, a11, a1, a2, a3, a4, a5, a6, a7, a8, "target_process_bang_radar_cmd");
  _ReadStatusReg(SP_EL0);
  return 16;
}
