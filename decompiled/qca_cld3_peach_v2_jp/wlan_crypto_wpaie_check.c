__int64 __fastcall wlan_crypto_wpaie_check(__int64 a1, __int64 a2, int *a3)
{
  unsigned int v3; // w8
  int v4; // w8
  int v5; // w9
  char v6; // w9
  unsigned __int8 v8; // w8
  int v9; // w10
  int v10; // w12
  unsigned __int8 *v11; // x9
  int v12; // w11
  char v13; // w10
  int v14; // w11
  char v15; // w15
  int v16; // w15
  int v17; // w10
  int v18; // w11
  unsigned __int8 v19; // w8
  int v20; // w12
  _WORD *v21; // x9
  int v22; // w11
  char v23; // w15
  int v24; // w15

  v3 = *(unsigned __int8 *)(a2 + 1);
  *(_DWORD *)a1 |= 0x20u;
  if ( v3 <= 0xD )
    goto LABEL_2;
  if ( *(_WORD *)(a2 + 6) != 1 )
  {
    if ( a3 )
    {
      v4 = 44;
      goto LABEL_11;
    }
    return 4;
  }
  v5 = *(_DWORD *)(a2 + 8);
  switch ( v5 )
  {
    case 15880192:
      v6 = 17;
      break;
    case 49434624:
      v6 = 1;
      break;
    case 82989056:
      v6 = 3;
      break;
    default:
      if ( a3 )
      {
        v4 = 41;
        goto LABEL_11;
      }
      return 4;
  }
  v8 = v3 - 12;
  *(_DWORD *)(a1 + 8) |= 1 << v6;
  v9 = *(unsigned __int8 *)(a2 + 12);
  v10 = (unsigned __int8)v9 | (*(unsigned __int8 *)(a2 + 13) << 8);
  if ( ((4 * v10) | 2u) > v8 )
    goto LABEL_2;
  v11 = (unsigned __int8 *)(a2 + 14);
  if ( !v10 )
    goto LABEL_28;
  v12 = (*(unsigned __int8 *)(a2 + 13) << 8) + v9;
  v13 = 4 * v9;
  v14 = v12 + 1;
  do
  {
    v16 = *(_DWORD *)v11;
    if ( *(_DWORD *)v11 == 15880192 )
    {
      v15 = 17;
      goto LABEL_18;
    }
    if ( v16 == 49434624 )
    {
      v15 = 1;
LABEL_18:
      *(_DWORD *)(a1 + 4) |= 1 << v15;
      goto LABEL_19;
    }
    if ( v16 == 82989056 )
    {
      v15 = 3;
      goto LABEL_18;
    }
LABEL_19:
    --v14;
    v11 += 4;
  }
  while ( v14 > 1 );
  v8 -= v13;
LABEL_28:
  if ( !*(_DWORD *)(a1 + 4) )
  {
    if ( a3 )
    {
      v4 = 42;
      goto LABEL_11;
    }
    return 4;
  }
  v17 = *v11;
  v18 = v11[1];
  v19 = v8 - 2;
  v20 = (unsigned __int8)v17 | (v18 << 8);
  if ( 4 * v20 > (unsigned int)v19 )
  {
LABEL_2:
    if ( a3 )
    {
      v4 = 40;
      goto LABEL_11;
    }
    return 4;
  }
  v21 = v11 + 2;
  if ( !v20 )
  {
LABEL_44:
    if ( v19 >= 2u )
      *(_WORD *)(a1 + 152) = *v21;
    return 0;
  }
  v19 -= 4 * v17;
  v22 = (v18 << 8) + v17 + 1;
  while ( 2 )
  {
    v24 = *(_DWORD *)v21;
    if ( *(int *)v21 <= 32657407 )
    {
      if ( v24 == 9846784 )
      {
        v23 = 14;
      }
      else
      {
        if ( v24 != 15880192 )
          goto LABEL_47;
        v23 = 2;
      }
      goto LABEL_33;
    }
    if ( v24 == 32657408 )
    {
      v23 = 0;
LABEL_33:
      --v22;
      v21 += 2;
      *(_DWORD *)(a1 + 20) |= 1 << v23;
      if ( v22 <= 1 )
        goto LABEL_44;
      continue;
    }
    break;
  }
  if ( v24 == 49434624 )
  {
    v23 = 1;
    goto LABEL_33;
  }
LABEL_47:
  if ( !a3 )
    return 4;
  v4 = 43;
LABEL_11:
  *a3 = v4;
  return 4;
}
