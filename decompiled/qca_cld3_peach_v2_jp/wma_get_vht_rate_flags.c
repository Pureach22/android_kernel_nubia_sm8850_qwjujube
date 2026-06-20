__int64 __fastcall wma_get_vht_rate_flags(int a1)
{
  unsigned int v1; // w8

  if ( (unsigned int)(a1 - 3) >= 2 )
    v1 = 96;
  else
    v1 = 4320;
  if ( a1 == 2 )
    v1 = 224;
  if ( a1 )
    return v1;
  else
    return 32;
}
