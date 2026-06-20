__int64 __fastcall hdcp1_count_ones(unsigned __int8 *a1, unsigned __int8 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x9
  unsigned int v4; // t1

  if ( !a2 )
    return 0;
  v2 = 0;
  v3 = a2;
  do
  {
    v4 = *a1++;
    --v3;
    v2 += ((v4 >> 6) & 1)
        + ((v4 >> 5) & 1)
        + ((v4 >> 4) & 1)
        + ((v4 >> 3) & 1)
        + ((v4 >> 2) & 1)
        + ((v4 >> 1) & 1)
        + (v4 & 1)
        + (v4 >> 7);
  }
  while ( v3 );
  return v2;
}
