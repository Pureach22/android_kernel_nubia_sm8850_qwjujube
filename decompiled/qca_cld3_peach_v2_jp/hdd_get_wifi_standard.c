__int64 __fastcall hdd_get_wifi_standard(__int64 a1, int a2, char a3)
{
  int v3; // w11
  _BOOL4 v4; // w9
  unsigned int v5; // w8

  if ( (a3 & 4) != 0 )
    v3 = 3;
  else
    v3 = 2;
  if ( (unsigned int)(a2 - 11) <= 1 )
    v4 = v3;
  else
    v4 = (a2 & 0xFFFFFFFE) == 8;
  if ( (a3 & 4) != 0 )
    v5 = 3;
  else
    v5 = 2;
  if ( a2 )
    return v4;
  else
    return v5;
}
