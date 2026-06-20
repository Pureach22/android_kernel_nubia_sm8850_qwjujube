__int64 __fastcall qdf_ssr_driver_dump_unregister_region(
        const char *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w19
  const char *v11; // x2
  const char *v12; // x20
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( !a1 )
  {
    v10 = 29;
    v11 = "%s: null region_name";
    goto LABEL_14;
  }
  if ( (unsigned int)qdf_mutex_acquire((__int64)&region_list_mutex) )
  {
    v10 = 1;
    v11 = "%s: couldn't acquire lock";
LABEL_14:
    qdf_trace_msg(0x38u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "qdf_ssr_driver_dump_unregister_region");
    return v10;
  }
  v12 = (const char *)&dump_entry_list;
  v13 = 114;
  while ( strcmp(v12, a1) || !*((_QWORD *)v12 + 4) )
  {
    --v13;
    v12 += 48;
    if ( !v13 )
      goto LABEL_11;
  }
  if ( v12 )
  {
    v10 = 0;
    *((_QWORD *)v12 + 4) = 0;
    --num_of_regions_registered;
    goto LABEL_12;
  }
LABEL_11:
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: couldn't find entry: %s",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "qdf_ssr_driver_dump_unregister_region",
    a1);
  v10 = 4;
LABEL_12:
  if ( (unsigned int)qdf_mutex_release((__int64)&region_list_mutex) )
  {
    v10 = 1;
    v11 = "%s: error releasing lock";
    goto LABEL_14;
  }
  return v10;
}
