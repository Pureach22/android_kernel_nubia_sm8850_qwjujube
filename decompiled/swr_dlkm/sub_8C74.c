__int64 __fastcall sub_8C74(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _OWORD *v5; // x27
  __int128 v6; // q14
  __int128 v7; // q31

  *v5 = v7;
  v5[1] = v6;
  return swr_bulk_write(a1, a2, a3, a4, a5);
}
