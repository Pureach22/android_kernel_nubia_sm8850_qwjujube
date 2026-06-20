__int64 __fastcall qdf_nbuf_classify_pkt(__int64 result)
{
  __int64 v1; // x8
  char v2; // w9
  int v3; // w9
  char v4; // w8
  __int64 v5; // x10
  __int64 v6; // x10
  unsigned __int16 *v7; // x10
  int v8; // w11
  int v9; // w10
  __int64 v10; // x10
  int v11; // w10
  __int64 v12; // x10

  v1 = *(_QWORD *)(result + 224);
  if ( (unsigned __int16)(*(_WORD *)(v1 + 2) & *(_WORD *)v1 & *(_WORD *)(v1 + 4)) == 0xFFFF )
  {
    v2 = 2;
  }
  else
  {
    if ( (*(_BYTE *)v1 & 1) == 0 )
      goto LABEL_6;
    v2 = 4;
  }
  *(_BYTE *)(result + 71) |= v2;
LABEL_6:
  v3 = *(unsigned __int16 *)(v1 + 12);
  switch ( v3 )
  {
    case 129:
      v5 = 16;
      goto LABEL_12;
    case 43144:
      v5 = 20;
LABEL_12:
      if ( *(_WORD *)(v1 + v5) == 1544 )
        goto LABEL_9;
      break;
    case 1544:
LABEL_9:
      v4 = 16;
      goto LABEL_34;
  }
  if ( v3 == 129 )
  {
    v10 = 16;
    goto LABEL_27;
  }
  if ( v3 == 43144 )
  {
    v10 = 20;
LABEL_27:
    if ( *(_WORD *)(v1 + v10) != 8 )
      goto LABEL_28;
    goto LABEL_16;
  }
  if ( v3 != 8 )
    goto LABEL_28;
LABEL_16:
  v6 = 14;
  if ( v3 == 43144 )
    v6 = 22;
  if ( v3 == 129 )
    v6 = 18;
  v7 = (unsigned __int16 *)(v1 + v6 + 4LL * (*(_BYTE *)(v1 + v6) & 0xF));
  v8 = *v7;
  v9 = v7[1];
  if ( v8 == 17152 && v9 == 17408 || v8 == 17408 && v9 == 17152 )
  {
    v4 = 32;
    goto LABEL_34;
  }
LABEL_28:
  if ( v3 == 129 )
  {
    v12 = 16;
  }
  else
  {
    v11 = *(unsigned __int16 *)(v1 + 12);
    if ( v3 != 43144 )
      goto LABEL_30;
    v12 = 20;
  }
  v11 = *(unsigned __int16 *)(v1 + v12);
LABEL_30:
  if ( v11 == 36488 )
  {
    v4 = 8;
  }
  else
  {
    if ( v3 != 46216 )
      return result;
    v4 = 24;
  }
LABEL_34:
  *(_BYTE *)(result + 71) = *(_BYTE *)(result + 71) & 0x87 | v4;
  return result;
}
