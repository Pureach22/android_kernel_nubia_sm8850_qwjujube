char *__fastcall reg_get_class_from_country(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char *v9; // x19
  __int64 v11; // x22

  v9 = &global_op_class;
  if ( a1 )
  {
    v11 = jiffies;
    if ( reg_get_class_from_country___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Country %c%c 0x%x",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "reg_get_class_from_country",
        *a1,
        a1[1],
        a1[2]);
      reg_get_class_from_country___last_ticks = v11;
    }
    if ( (unsigned int)a1[2] - 1 >= 5 )
    {
      if ( (unsigned int)qdf_mem_cmp(a1, "US", 2u) )
      {
        if ( (unsigned int)qdf_mem_cmp(a1, "EU", 2u) )
        {
          if ( (unsigned int)qdf_mem_cmp(a1, "JP", 2u) )
          {
            if ( !(unsigned int)qdf_mem_cmp(a1, "CN", 2u) )
              return &china_op_class;
          }
          else
          {
            return &japan_op_class;
          }
        }
        else
        {
          return &euro_op_class;
        }
      }
      else
      {
        return &us_op_class;
      }
    }
    else
    {
      return off_9E4948[(unsigned __int8)(a1[2] - 1)];
    }
  }
  return v9;
}
