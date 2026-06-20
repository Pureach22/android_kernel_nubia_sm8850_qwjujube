__int64 __fastcall qcom_find_src_index(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  int num_parents; // w0
  int v6; // w8
  __int64 result; // x0
  int v8; // t1

  num_parents = clk_hw_get_num_parents(a1);
  if ( num_parents < 1 )
    return 4294967294LL;
  v6 = num_parents;
  result = 0;
  while ( 1 )
  {
    v8 = *a2;
    a2 += 2;
    if ( v8 == a3 )
      break;
    if ( v6 == ++result )
      return 4294967294LL;
  }
  return result;
}
