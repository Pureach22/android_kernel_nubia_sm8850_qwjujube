__int64 __fastcall qdf_ssr_driver_dump_retrieve_regions(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w22
  const char *v11; // x2
  __int64 v14; // x21
  _QWORD *v15; // x22
  __int64 v16; // x23

  v10 = 29;
  v11 = "%s: null input_array or num_entries_loaded";
  if ( !a1 || !a2 )
    goto LABEL_14;
  if ( (unsigned int)qdf_mutex_acquire((__int64)&region_list_mutex) )
  {
    v10 = 1;
    v11 = "%s: couldn't acquire lock";
LABEL_14:
    qdf_trace_msg(0x38u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, "qdf_ssr_driver_dump_retrieve_regions");
    return v10;
  }
  v14 = 0;
  v15 = &dump_entry_list;
  v16 = 114;
  do
  {
    if ( v15[4] )
      qdf_mem_copy((void *)(a1 + 48 * v14++), v15, 0x30u);
    --v16;
    v15 += 6;
  }
  while ( v16 );
  if ( v14 == num_of_regions_registered )
  {
    v10 = 0;
    *a2 = v14;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: num entries mismatch index:%zu num reg registered:%zu",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "qdf_ssr_driver_dump_retrieve_regions",
      v14);
    v10 = 4;
  }
  if ( (unsigned int)qdf_mutex_release((__int64)&region_list_mutex) )
  {
    v10 = 1;
    v11 = "%s: error releasing lock";
    goto LABEL_14;
  }
  return v10;
}
