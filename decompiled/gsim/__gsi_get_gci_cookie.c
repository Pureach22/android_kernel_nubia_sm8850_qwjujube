__int64 __fastcall _gsi_get_gci_cookie(__int64 a1, unsigned __int16 a2)
{
  _BYTE *v2; // x8
  _BYTE *v3; // x9
  __int64 v4; // x9
  __int64 v5; // x10
  __int64 result; // x0
  __int64 v8; // x9

  v2 = *(_BYTE **)(a1 + 200);
  v3 = &v2[16 * a2];
  if ( (*v3 & 1) != 0 )
  {
    v4 = *(unsigned __int16 *)(a1 + 190);
    v5 = *(_QWORD *)(a1 + 392);
    result = v4 + 1;
    *(_QWORD *)(a1 + 392) = v5 + 1;
    if ( v2[16 * v4 + 16] != 1 )
      goto LABEL_24;
    result = v4 + 2;
    if ( v2[16 * v4 + 32] != 1 )
      goto LABEL_24;
    result = v4 + 3;
    if ( v2[16 * v4 + 48] != 1 )
      goto LABEL_24;
    result = v4 + 4;
    if ( v2[16 * v4 + 64] != 1 )
      goto LABEL_24;
    result = v4 + 5;
    if ( v2[16 * v4 + 80] != 1 )
      goto LABEL_24;
    result = v4 + 6;
    if ( v2[16 * v4 + 96] != 1 )
      goto LABEL_24;
    result = v4 + 7;
    if ( v2[16 * v4 + 112] != 1 )
      goto LABEL_24;
    result = v4 + 8;
    if ( v2[16 * v4 + 128] != 1 )
      goto LABEL_24;
    result = v4 + 9;
    if ( v2[16 * v4 + 144] != 1 )
      goto LABEL_24;
    result = v4 + 10;
    if ( v2[16 * v4 + 160] != 1 )
      goto LABEL_24;
    result = v4 + 11;
    if ( v2[16 * v4 + 176] == 1
      && (result = v4 + 12, v2[16 * v4 + 192] == 1)
      && (result = v4 + 13, v2[16 * v4 + 208] == 1)
      && (result = v4 + 14, v2[16 * v4 + 224] == 1)
      && (result = v4 + 15, v2[16 * v4 + 240] == 1)
      && (result = v4 + 16, v2[16 * v4 + 256] == 1)
      && (result = v4 + 17, v2[16 * v4 + 272] == 1) )
    {
      result = 0;
      v8 = v4 + 1;
      while ( (*v2 & 1) != 0 )
      {
        ++result;
        v2 += 16;
        if ( v8 == result )
        {
          dev_err(
            *(_QWORD *)(gsi_ctx + 8),
            "%s:%d both userdata array and escape buffer is full\n",
            "__gsi_get_gci_cookie",
            4221);
          __break(0x800u);
          goto LABEL_23;
        }
      }
      *v2 = 1;
    }
    else
    {
LABEL_24:
      v2[16 * result] = 1;
    }
  }
  else
  {
LABEL_23:
    *v3 = 1;
    return a2;
  }
  return result;
}
