__int64 __fastcall wma_get_eht_rate_flags(int a1)
{
  unsigned int v1; // w8

  if ( a1 )
    v1 = 24576;
  else
    v1 = 0x2000;
  if ( a1 == 2 )
    v1 = 57344;
  if ( (unsigned int)(a1 - 3) < 2 )
    v1 = 122880;
  if ( a1 == 7 )
    return 253952;
  else
    return v1;
}
