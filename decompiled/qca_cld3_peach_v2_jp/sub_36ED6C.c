// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_36ED6C@<X0>(
        unsigned int a1@<W8>,
        double a2@<D0>,
        double a3@<D1>,
        double a4@<D2>,
        double a5@<D3>,
        double a6@<D4>,
        double a7@<D5>,
        double a8@<D6>,
        double a9@<D7>)
{
  unsigned int v9; // w9
  __int64 v10; // x19
  __int64 v11; // x10
  unsigned __int64 v12; // x20
  const char *v13; // x2

  v11 = *(_QWORD *)(v10 + 24);
  v12 = v11 + a1 * (unsigned __int64)v9 + 1880;
  *(_QWORD *)(v11 + a1 * (unsigned __int64)v9 + 1980) = 0;
  if ( *(_BYTE *)(v10 + 76) == 1 )
  {
    *(_BYTE *)(v10 + 76) = 0;
    if ( (unsigned int)qdf_mc_timer_stop(v11 + a1 * (unsigned __int64)v9 + 1992) )
    {
      v13 = "%s: Failed to stop inactivity timer";
LABEL_6:
      qdf_trace_msg(0x33u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wmm_disable_inactivity_timer");
      goto LABEL_7;
    }
    if ( (unsigned int)qdf_mc_timer_destroy(v12 + 112) )
    {
      v13 = "%s: Failed to destroy inactivity timer:Timer started";
      goto LABEL_6;
    }
  }
LABEL_7:
  hdd_wmm_free_context(v10, a2, a3, a4, a5, a6, a7, a8, a9);
  return 5;
}
