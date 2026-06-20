__int64 __fastcall cam_sync_util_find_and_set_empty_row(__int64 a1, __int64 *a2)
{
  __int64 first_zero_bit; // x0
  unsigned int v5; // w20
  unsigned __int64 v13; // x10

  mutex_lock(a1 + 8328);
  first_zero_bit = find_first_zero_bit(a1 + 8416, 2048);
  *a2 = first_zero_bit;
  if ( first_zero_bit > 2047 )
  {
    v5 = -1;
  }
  else
  {
    _X9 = (unsigned __int64 *)(a1 + 8416 + 8LL * ((unsigned int)first_zero_bit >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v13 = __ldxr(_X9);
    while ( __stxr(v13 | (1LL << first_zero_bit), _X9) );
    v5 = 0;
  }
  mutex_unlock(a1 + 8328);
  return v5;
}
