bool __fastcall point_is_in_limit_area(unsigned __int16 a1, unsigned __int16 a2)
{
  int v2; // w12
  unsigned int v3; // w8
  _BOOL8 result; // x0
  int v5; // w11
  unsigned int v6; // w9

  v2 = *(_DWORD *)(tpd_cdev + 16);
  v3 = a1;
  if ( (v2 | 2) == 3 )
  {
    if ( *(unsigned __int8 *)(tpd_cdev + 39) > (unsigned int)a1 )
      return 1;
    if ( *(unsigned __int16 *)(tpd_cdev + 1090) - *(unsigned __int8 *)(tpd_cdev + 40) < a1 )
      return 1;
    if ( *(unsigned __int8 *)(tpd_cdev + 41) > (unsigned int)a2 )
      return 1;
    return *(unsigned __int16 *)(tpd_cdev + 1092) - *(unsigned __int8 *)(tpd_cdev + 42) < a2;
  }
  if ( *(unsigned __int8 *)(tpd_cdev + 39) > (unsigned int)a1 )
    return 1;
  v5 = *(unsigned __int16 *)(tpd_cdev + 1090);
  if ( v5 - *(unsigned __int8 *)(tpd_cdev + 40) < a1 )
    return 1;
  if ( !v2
    && (a1 < (3 * (unsigned int)*(unsigned __int8 *)(tpd_cdev + 52)) >> 1
     || (int)(v5 - ((3 * (unsigned int)*(unsigned __int8 *)(tpd_cdev + 53)) >> 1)) < a1)
    && ((byte_30EFB & 1) != 0
     || (byte_30F83 & 1) != 0
     || (byte_3100B & 1) != 0
     || (byte_31093 & 1) != 0
     || (byte_3111B & 1) != 0
     || (byte_311A3 & 1) != 0
     || (byte_3122B & 1) != 0
     || (byte_312B3 & 1) != 0
     || (byte_3133B & 1) != 0
     || byte_313C3 == 1) )
  {
    printk(&unk_353E5, a1, a2);
    return 1;
  }
  if ( !*(_BYTE *)(tpd_cdev + 56) )
    return 0;
  if ( *(unsigned __int16 *)(tpd_cdev + 46) >= (unsigned int)a2 )
    return 0;
  v6 = *(unsigned __int16 *)(tpd_cdev + 44);
  result = 1;
  if ( v6 <= v3 && (int)(v5 - v6) >= (int)v3 )
    return 0;
  return result;
}
