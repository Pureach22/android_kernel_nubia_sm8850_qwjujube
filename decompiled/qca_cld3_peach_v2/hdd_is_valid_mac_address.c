bool __fastcall hdd_is_valid_mac_address(_BYTE *a1)
{
  unsigned int v1; // w12
  int v2; // w9
  int v3; // w8
  unsigned __int8 *v4; // x10
  unsigned int v5; // t1
  _BOOL8 result; // x0
  int v7; // w12
  unsigned int v8; // t1
  _BOOL4 v10; // w9

  v1 = (unsigned __int8)*a1;
  if ( !*a1 )
    return 0;
  v2 = 0;
  v3 = 0;
  v4 = a1 + 1;
  do
  {
    while ( (*((_BYTE *)&ctype + v1) & 0x44) != 0 )
    {
      ++v3;
      v5 = *v4++;
      v1 = v5;
      if ( !v5 )
        goto LABEL_12;
    }
    result = 0;
    if ( v1 != 58 || !v3 )
      return result;
    if ( v3 >= 0 )
      v7 = v3;
    else
      v7 = v3 + 1;
    if ( (v7 >> 1) - 1 != v2 )
      break;
    ++v2;
    v8 = *v4++;
    v1 = v8;
  }
  while ( v8 );
LABEL_12:
  v10 = v2 == 5 || v2 == 0;
  return v3 == 12 && v10;
}
