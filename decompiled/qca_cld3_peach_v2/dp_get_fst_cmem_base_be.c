__int64 __fastcall dp_get_fst_cmem_base_be(
        _QWORD *a1,
        unsigned __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 v20; // x4
  __int64 v21; // x21

  qdf_trace_msg(
    0x45u,
    5u,
    "%s: cmem base 0x%llx, total size 0x%llx avail_size 0x%llx",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_get_cmem_chunk",
    a1[2509],
    a1[2510],
    a1[2511]);
  v20 = a1[2511];
  if ( v20 >= a2 )
  {
    v21 = a1[2510] - v20 + a1[2509];
    a1[2511] = v20 - a2;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Reserved cmem space 0x%llx, size 0x%llx for client %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_get_cmem_chunk",
      v21,
      a2,
      1);
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: cmem_size 0x%llx bytes < requested size 0x%llx bytes",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_get_cmem_chunk");
    return 0;
  }
  return v21;
}
