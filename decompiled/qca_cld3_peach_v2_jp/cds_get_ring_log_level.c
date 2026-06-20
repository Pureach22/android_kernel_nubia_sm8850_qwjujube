__int64 __fastcall cds_get_ring_log_level(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int *v5; // x8
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v5 = (unsigned int *)gp_cds_context;
  if ( gp_cds_context
    || (printk(&unk_94D98D, "cds_get_global_context", a3, a4), (v5 = (unsigned int *)gp_cds_context) != nullptr) )
  {
    result = 0;
    if ( a1 <= 1 )
    {
      if ( a1 )
      {
        if ( a1 == 1 )
          return v5[23];
      }
      else
      {
        return v5[22];
      }
    }
    else
    {
      switch ( a1 )
      {
        case 2:
          return v5[24];
        case 3:
          return v5[25];
        case 4:
          return v5[26];
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context is Invalid",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cds_get_ring_log_level");
    return 0;
  }
  return result;
}
