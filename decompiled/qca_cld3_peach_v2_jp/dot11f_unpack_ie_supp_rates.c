__int64 __fastcall dot11f_unpack_ie_supp_rates(__int64 a1, char *a2, unsigned __int8 a3, _BYTE *a4)
{
  unsigned int v5; // w8
  __int64 v6; // x10
  char v7; // w13
  char v8; // t1
  unsigned int v9; // w14
  __int64 v10; // x15
  bool v11; // zf

  if ( *a4 )
    return 32;
  *a4 = 1;
  if ( !a3 )
    goto LABEL_20;
  v5 = 0;
  v6 = a3;
  do
  {
    v8 = *a2++;
    v7 = v8;
    v9 = v8 & 0x7F;
    v10 = (1LL << (v8 & 0x7F)) & 0x1001001441814LL;
    v11 = v9 > 0x30 || v10 == 0;
    if ( !v11 || v9 == 72 || v9 == 96 )
    {
      if ( v5 <= 0xB )
        goto LABEL_5;
    }
    else if ( v9 == 108 && v5 < 0xC )
    {
LABEL_5:
      a4[v5++ + 2] = v7;
    }
    --v6;
  }
  while ( v6 );
  if ( v5 )
  {
    a4[1] = v5;
    return 0;
  }
LABEL_20:
  *a4 = 0;
  return 8;
}
