__int64 __fastcall cds_set_sub_20_channel_width(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v12; // x8

  if ( a1 > 2 )
    return 4;
  if ( gp_cds_context )
  {
    v12 = *(_QWORD *)(gp_cds_context + 152);
    if ( v12 )
    {
      if ( *(_BYTE *)(v12 + 30) == 1 )
      {
        if ( *(_DWORD *)(v12 + 32) == a1 )
        {
          return 6;
        }
        else
        {
          *(_DWORD *)(v12 + 32) = a1;
          return 0;
        }
      }
      else
      {
        return 11;
      }
    }
    else
    {
      return 28;
    }
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__cds_get_context",
      "cds_set_sub_20_channel_width",
      v9,
      v10);
    return 28;
  }
}
