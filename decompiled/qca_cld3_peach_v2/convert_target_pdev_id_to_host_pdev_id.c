__int64 __fastcall convert_target_pdev_id_to_host_pdev_id(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  unsigned int v12; // w8

  v12 = a2 - 1;
  if ( a2 - 1 <= 2 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 760) + 7844LL) & 1) != 0 )
      return *(unsigned int *)(*(_QWORD *)(a1 + 864) + 4LL * a2 - 4);
    return v12;
  }
  if ( a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid pdev_id",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "convert_target_pdev_id_to_host_pdev_id",
      v10,
      v11);
    return (unsigned int)-1;
  }
  return 255;
}
