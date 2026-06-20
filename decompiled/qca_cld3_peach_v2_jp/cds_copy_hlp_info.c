void *__fastcall cds_copy_hlp_info(
        int *a1,
        int *a2,
        unsigned __int16 a3,
        const void *a4,
        __int64 a5,
        __int64 a6,
        unsigned __int16 *a7,
        void *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  int v16; // w9
  int v17; // w9
  const char *v19; // x2

  if ( a3 )
  {
    if ( a1 )
    {
      if ( a2 )
      {
        v16 = *a1;
        *(_WORD *)(a5 + 4) = *((_WORD *)a1 + 2);
        *(_DWORD *)a5 = v16;
        v17 = *a2;
        *(_WORD *)(a6 + 4) = *((_WORD *)a2 + 2);
        *(_DWORD *)a6 = v17;
        *a7 = a3;
        return qdf_mem_copy(a8, a4, a3);
      }
      v19 = "%s: HLP source mac NULL";
    }
    else
    {
      v19 = "%s: HLP destination mac NULL";
    }
  }
  else
  {
    v19 = "%s: Input HLP data len zero\n";
  }
  return (void *)qdf_trace_msg(0x38u, 8u, v19, a9, a10, a11, a12, a13, a14, a15, a16, "cds_copy_hlp_info");
}
