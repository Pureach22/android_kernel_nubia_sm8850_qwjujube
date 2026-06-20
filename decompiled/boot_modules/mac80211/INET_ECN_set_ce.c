__int64 __fastcall INET_ECN_set_ce(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x9
  __int64 v3; // x19
  int v4; // w21
  int v5; // w22
  int v6; // w8
  int v7; // w9
  int *v8; // x8
  __int64 v9; // x20
  int v10; // w8
  __int64 v11; // x9
  __int64 v12; // x8
  char v13; // w9
  unsigned int v14; // w10
  __int64 result; // x0
  __int64 v16; // x9
  unsigned int *v17; // x8
  unsigned int v18; // w10
  unsigned int v19; // w9
  unsigned int v20; // w8
  int v21; // w11
  int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int16 *)(a1 + 180);
  v2 = *(unsigned __int16 *)(a1 + 120);
  if ( v1 == 43144 || v1 == 129 )
  {
    if ( *(_WORD *)(a1 + 120) )
    {
      if ( (unsigned int)v2 <= 3 )
      {
        result = 0;
        __break(0x800u);
        goto LABEL_35;
      }
      v3 = v2 - 4;
    }
    else
    {
      v3 = 14;
    }
    v4 = 0;
    v5 = -(int)v3;
    while ( 1 )
    {
      v6 = *(_DWORD *)(a1 + 112);
      v7 = *(_DWORD *)(a1 + 116);
      v22 = 0;
      if ( v5 + v4 + v6 - v7 < 4 )
      {
        if ( !a1 )
          goto LABEL_32;
        v9 = a1;
        v10 = skb_copy_bits(a1, (unsigned int)v3, &v22, 4);
        a1 = v9;
        v8 = v10 >= 0 ? &v22 : nullptr;
        if ( !v8 )
          goto LABEL_32;
      }
      else
      {
        v8 = (int *)(*(_QWORD *)(a1 + 224) + v3);
        if ( !v8 )
          goto LABEL_32;
      }
      if ( v4 == -28 )
        goto LABEL_32;
      v1 = *((unsigned __int16 *)v8 + 1);
      if ( v1 != 43144 && v1 != 129 )
        break;
      v3 += 4;
      v4 -= 4;
    }
  }
  if ( v1 == 56710 )
  {
    v16 = *(_QWORD *)(a1 + 216);
    v17 = (unsigned int *)(v16 + *(unsigned __int16 *)(a1 + 184));
    if ( (unsigned __int64)(v17 + 10) <= v16 + (unsigned __int64)*(unsigned int *)(a1 + 208)
      && (*(_WORD *)v17 & 0x3000) != 0 )
    {
      v18 = *v17;
      v19 = *v17 | 0x3000;
      *v17 = v19;
      if ( (*(_BYTE *)(a1 + 128) & 0x60) == 0x40 )
      {
        v20 = v19 + __CFADD__(*(_DWORD *)(a1 + 140), ~v18) + *(_DWORD *)(a1 + 140) + ~v18;
        if ( v20 < v19 )
          ++v20;
        *(_DWORD *)(a1 + 140) = v20;
      }
      goto LABEL_34;
    }
LABEL_32:
    result = 0;
    goto LABEL_35;
  }
  if ( v1 != 8 )
    goto LABEL_32;
  v11 = *(_QWORD *)(a1 + 216);
  v12 = v11 + *(unsigned __int16 *)(a1 + 184);
  if ( v12 + 20 > v11 + (unsigned __int64)*(unsigned int *)(a1 + 208) )
    goto LABEL_32;
  v13 = *(_BYTE *)(v12 + 1);
  v14 = (v13 + 1) & 3;
  if ( v14 > 1 )
  {
    v21 = *(unsigned __int16 *)(v12 + 10);
    *(_BYTE *)(v12 + 1) = v13 | 3;
    *(_WORD *)(v12 + 10) = v21
                         + ((_WORD)v14 << 8)
                         - 1025
                         + ((v21 + (unsigned int)(unsigned __int16)(((_WORD)v14 << 8) - 1025)) >> 16);
LABEL_34:
    result = 1;
    goto LABEL_35;
  }
  result = v14 ^ 1;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
