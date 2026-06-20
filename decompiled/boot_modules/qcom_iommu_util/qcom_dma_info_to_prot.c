__int64 __fastcall qcom_dma_info_to_prot(int a1, char a2, unsigned int a3)
{
  int v3; // w9
  int v4; // w9
  unsigned int v5; // w8

  if ( (a2 & 1) != 0 )
    v3 = 4;
  else
    v3 = 0;
  v4 = (a3 >> 4) & 0x20 | v3;
  if ( a1 == 2 )
  {
    return v4 | 2u;
  }
  else
  {
    if ( a1 == 1 )
      return v4 | 1u;
    v5 = 0;
    if ( !a1 )
      return v4 | 3u;
  }
  return v5;
}
