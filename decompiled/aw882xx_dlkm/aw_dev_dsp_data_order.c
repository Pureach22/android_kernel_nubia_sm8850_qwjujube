__int64 __fastcall aw_dev_dsp_data_order(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int i; // w8
  char v4; // w10

  if ( (a3 & 1) != 0 )
    return 4294967274LL;
  if ( a3 )
  {
    for ( i = 0; i < a3; i += 2 )
    {
      v4 = *(_BYTE *)(a2 + (int)(i + 1));
      *(_BYTE *)(a2 + (int)(i + 1)) = *(_BYTE *)(a2 + (int)i);
      *(_BYTE *)(a2 + (int)i) = v4;
    }
  }
  return 0;
}
