__int64 __fastcall dot11f_get_packed_ietclas(__int64 a1, _BYTE *a2, int *a3)
{
  int v3; // w8
  int v4; // w9
  int v5; // w9
  int v6; // w9

  if ( *a2 )
  {
    v3 = *a3;
    *a3 += 3;
    v4 = (unsigned __int8)a2[2];
    if ( !a2[2] )
    {
      v6 = 17;
      goto LABEL_11;
    }
    if ( v4 == 2 )
    {
      v6 = 5;
      goto LABEL_11;
    }
    if ( v4 == 1 )
    {
      *a3 = v3 + 4;
      v5 = (unsigned __int8)a2[4];
      if ( v5 == 4 )
      {
        v6 = 19;
        goto LABEL_11;
      }
      if ( v5 == 6 )
      {
        v6 = 43;
LABEL_11:
        *a3 = v3 + v6;
      }
    }
  }
  return 0;
}
