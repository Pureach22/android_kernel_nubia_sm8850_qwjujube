__int64 __fastcall msm_get_src_bpc(int a1, int a2)
{
  int v3; // w8

  if ( a1 == 2 )
  {
    if ( a2 >= 0 )
      v3 = a2;
    else
      v3 = a2 + 1;
    return (v3 & 0xFFFFFFFE)
         + (v3 >> 1)
         + ((char)(3 * (a2 - (v3 & 0xFE)) + (((3 * (a2 - (v3 & 0xFFFFFFFE))) & 0x80) >> 7)) >> 1);
  }
  else if ( a1 == 1 )
  {
    return (unsigned int)(2 * a2);
  }
  else
  {
    return (unsigned int)(3 * a2);
  }
}
