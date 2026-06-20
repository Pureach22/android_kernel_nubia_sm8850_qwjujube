void *__fastcall lim_mlo_save_mlo_info(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a1 )
    return qdf_mem_copy((void *)(a1 + 1088), a2, 0xB0u);
  else
    return (void *)qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: sta ds is null",
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     "lim_mlo_save_mlo_info");
}
