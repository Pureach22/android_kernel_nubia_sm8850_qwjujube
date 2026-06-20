void __fastcall bitmap_find_best_next_zero_area_off(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        unsigned __int64 *a8,
        char a9)
{
  unsigned __int64 next_zero_area_off; // x0
  unsigned __int64 v16; // x25
  unsigned __int64 v17; // x28
  unsigned __int64 v18; // x27
  __int64 next_bit; // x0
  unsigned __int64 v20; // x8

  if ( (a9 & 1) == 0 )
    return;
  next_zero_area_off = bitmap_find_next_zero_area_off(a2, a3, a4, a5, a6, a7);
  if ( next_zero_area_off >= a3 )
  {
    v18 = a3;
    goto LABEL_11;
  }
  v16 = next_zero_area_off;
  v17 = a3 + 1;
  v18 = a3;
  while ( 1 )
  {
    next_bit = find_next_bit(a2, a3, v16 + a5);
    v20 = next_bit - v16;
    if ( next_bit - v16 >= v17 )
      goto LABEL_4;
    if ( v20 == a3 )
      break;
    v18 = v16;
    v17 = next_bit - v16;
    if ( v20 == a5 )
      return;
LABEL_4:
    v16 = bitmap_find_next_zero_area_off(a2, a3, next_bit + 1, a5, a6, a7);
    if ( v16 >= a3 )
      goto LABEL_11;
  }
  v18 = v16;
LABEL_11:
  *a8 = v18;
}
