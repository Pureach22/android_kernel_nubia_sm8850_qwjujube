_BYTE *__fastcall geni_i2c_get_immediate_dma_data(_BYTE *result, int a2, char *a3)
{
  __int64 v3; // x8
  char v4; // t1

  if ( a2 >= 1 )
  {
    v3 = (unsigned int)a2;
    do
    {
      v4 = *a3++;
      --v3;
      *result++ = v4;
    }
    while ( v3 );
  }
  return result;
}
