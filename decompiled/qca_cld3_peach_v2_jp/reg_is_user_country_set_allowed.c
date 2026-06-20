__int64 __fastcall reg_is_user_country_set_allowed(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 psoc_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20

  psoc_obj = reg_get_psoc_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( psoc_obj )
  {
    if ( (*(_BYTE *)(psoc_obj + 91164) & 1) != 0 || *(_BYTE *)(psoc_obj + 91150) != 1 )
    {
      return 1;
    }
    else
    {
      v18 = jiffies;
      if ( reg_is_user_country_set_allowed___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: country set from userspace is not allowed",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "reg_is_user_country_set_allowed");
        reg_is_user_country_set_allowed___last_ticks = v18;
      }
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: psoc reg component is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "reg_is_user_country_set_allowed");
    return 0;
  }
}
