__int64 __fastcall hdd_is_link_adapter(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x2

  if ( !a1 )
  {
    v10 = "%s: hdd_ctx is null";
    goto LABEL_5;
  }
  if ( !hdd_get_link_info_by_vdev(a1, a2) )
  {
    v10 = "%s: Invalid vdev";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v10, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_is_link_adapter");
  }
  return 0;
}
