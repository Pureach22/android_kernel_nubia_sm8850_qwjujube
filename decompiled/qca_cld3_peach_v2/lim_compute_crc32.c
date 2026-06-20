unsigned int *__fastcall lim_compute_crc32(unsigned int *result, unsigned __int8 *a2, __int16 a3)
{
  unsigned int v3; // w9
  int v4; // t1
  unsigned int v5; // w9
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w9
  unsigned int v10; // w9
  unsigned int v11; // w9
  unsigned int v12; // w9

  if ( a3 )
  {
    v3 = -1;
    do
    {
      v4 = *a2++;
      --a3;
      v5 = v3 ^ v4;
      if ( (v5 & 1) != 0 )
        v6 = (v5 >> 1) ^ 0xEDB88320;
      else
        v6 = v5 >> 1;
      if ( (v6 & 1) != 0 )
        v7 = (v6 >> 1) ^ 0xEDB88320;
      else
        v7 = v6 >> 1;
      if ( (v7 & 1) != 0 )
        v8 = (v7 >> 1) ^ 0xEDB88320;
      else
        v8 = v7 >> 1;
      if ( (v8 & 1) != 0 )
        v9 = (v8 >> 1) ^ 0xEDB88320;
      else
        v9 = v8 >> 1;
      if ( (v9 & 1) != 0 )
        v10 = (v9 >> 1) ^ 0xEDB88320;
      else
        v10 = v9 >> 1;
      if ( (v10 & 1) != 0 )
        v11 = (v10 >> 1) ^ 0xEDB88320;
      else
        v11 = v10 >> 1;
      if ( (v11 & 1) != 0 )
        v12 = (v11 >> 1) ^ 0xEDB88320;
      else
        v12 = v11 >> 1;
      if ( (v12 & 1) != 0 )
        v3 = (v12 >> 1) ^ 0xEDB88320;
      else
        v3 = v12 >> 1;
    }
    while ( a3 );
    *result = ~v3;
  }
  else
  {
    *result = 0;
  }
  return result;
}
