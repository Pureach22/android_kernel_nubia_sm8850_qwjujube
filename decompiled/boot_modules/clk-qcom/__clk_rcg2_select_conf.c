unsigned __int8 *__fastcall _clk_rcg2_select_conf(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 name; // x0
  __int64 v7; // x8
  const char *v8; // x21
  __int64 v9; // x23
  unsigned __int8 *v10; // x24
  unsigned __int64 v11; // x25
  int v12; // w26
  unsigned int src_index; // w0
  __int64 parent_by_index; // x0
  unsigned __int64 rate; // x0
  unsigned __int64 v17; // x8

  name = clk_hw_get_name(a1);
  v7 = *(_QWORD *)(a2 + 8);
  v8 = (const char *)name;
  if ( !v7 )
  {
LABEL_20:
    _warn_printk("%s: can't find a configuration for rate %lu\n", v8, a3);
    v9 = -22;
    __break(0x800u);
    return (unsigned __int8 *)v9;
  }
  if ( v7 != 1 )
  {
    v10 = *(unsigned __int8 **)(a2 + 16);
    v9 = 0;
    v11 = -1;
    v12 = 1;
    do
    {
      src_index = qcom_find_src_index(a1, *(_QWORD *)(a1 - 40), *v10);
      if ( (src_index & 0x80000000) == 0 )
      {
        parent_by_index = clk_hw_get_parent_by_index(a1, src_index);
        if ( parent_by_index )
        {
          rate = clk_hw_get_rate(parent_by_index);
          if ( v10[1] )
            rate = 2 * ((rate % ((unsigned __int64)v10[1] + 1)) & 0x7FFF) / ((unsigned int)v10[1] + 1)
                 + 2 * (rate / ((unsigned __int64)v10[1] + 1));
          if ( *((_WORD *)v10 + 2) )
            rate = rate % *((unsigned __int16 *)v10 + 1)
                 * *((unsigned __int16 *)v10 + 2)
                 / *((unsigned __int16 *)v10 + 1)
                 + rate / *((unsigned __int16 *)v10 + 1) * *((unsigned __int16 *)v10 + 2);
          if ( rate == a3 )
            return v10;
          v17 = a3 - rate;
          if ( rate >= a3 )
            v17 = rate - a3;
          if ( v17 < v11 )
          {
            v9 = (__int64)v10;
            v11 = v17;
          }
        }
      }
      v10 += 6;
    }
    while ( *(_QWORD *)(a2 + 8) > (unsigned __int64)v12++ );
    if ( v9 )
      return (unsigned __int8 *)v9;
    goto LABEL_20;
  }
  return *(unsigned __int8 **)(a2 + 16);
}
