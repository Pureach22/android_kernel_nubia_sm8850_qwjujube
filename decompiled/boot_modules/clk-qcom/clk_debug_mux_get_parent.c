__int64 __fastcall clk_debug_mux_get_parent(__int64 a1)
{
  int num_parents; // w21
  __int64 parent; // x0
  unsigned int i; // w19
  __int64 v5; // x22
  __int64 parent_by_index; // x0
  const char *name; // x23
  const char *v8; // x0

  num_parents = clk_hw_get_num_parents(a1);
  parent = clk_hw_get_parent(a1);
  i = 255;
  if ( parent && num_parents >= 1 )
  {
    v5 = parent;
    for ( i = 0; i != num_parents; ++i )
    {
      parent_by_index = clk_hw_get_parent_by_index(a1, i);
      if ( !parent_by_index )
        break;
      name = (const char *)clk_hw_get_name(parent_by_index);
      v8 = (const char *)clk_hw_get_name(v5);
      if ( !strcmp(name, v8) )
        return i;
    }
    return 255;
  }
  return i;
}
