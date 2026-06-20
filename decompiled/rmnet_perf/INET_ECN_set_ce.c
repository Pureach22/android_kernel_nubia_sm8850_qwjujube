__int64 __fastcall INET_ECN_set_ce(__int64 result)
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
  int v15; // w11
  __int64 v16; // x9
  unsigned int *v17; // x8
  unsigned int v18; // w10
  unsigned int v19; // w9
  unsigned int v20; // w8
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int16 *)(result + 180);
  v2 = *(unsigned __int16 *)(result + 120);
  if ( v1 == 43144 || v1 == 129 )
  {
    if ( *(_WORD *)(result + 120) )
    {
      if ( (unsigned int)v2 <= 3 )
      {
        __break(0x800u);
        goto LABEL_32;
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
      v6 = *(_DWORD *)(result + 112);
      v7 = *(_DWORD *)(result + 116);
      v21 = 0;
      if ( v5 + v4 + v6 - v7 < 4 )
      {
        if ( !result )
          goto LABEL_32;
        v9 = result;
        v10 = skb_copy_bits(result, (unsigned int)v3, &v21, 4);
        result = v9;
        v8 = v10 >= 0 ? &v21 : nullptr;
        if ( !v8 )
          goto LABEL_32;
      }
      else
      {
        v8 = (int *)(*(_QWORD *)(result + 224) + v3);
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
    v16 = *(_QWORD *)(result + 216);
    v17 = (unsigned int *)(v16 + *(unsigned __int16 *)(result + 184));
    if ( (unsigned __int64)(v17 + 10) <= v16 + (unsigned __int64)*(unsigned int *)(result + 208)
      && (*(_WORD *)v17 & 0x3000) != 0 )
    {
      v18 = *v17;
      v19 = *v17 | 0x3000;
      *v17 = v19;
      if ( (*(_BYTE *)(result + 128) & 0x60) == 0x40 )
      {
        v20 = v19 + __CFADD__(*(_DWORD *)(result + 140), ~v18) + *(_DWORD *)(result + 140) + ~v18;
        if ( v20 < v19 )
          ++v20;
        *(_DWORD *)(result + 140) = v20;
      }
    }
  }
  else if ( v1 == 8 )
  {
    v11 = *(_QWORD *)(result + 216);
    v12 = v11 + *(unsigned __int16 *)(result + 184);
    if ( v12 + 20 <= v11 + (unsigned __int64)*(unsigned int *)(result + 208) )
    {
      v13 = *(_BYTE *)(v12 + 1);
      v14 = (v13 + 1) & 3;
      if ( v14 >= 2 )
      {
        v15 = *(unsigned __int16 *)(v12 + 10);
        *(_BYTE *)(v12 + 1) = v13 | 3;
        *(_WORD *)(v12 + 10) = v15
                             + ((_WORD)v14 << 8)
                             - 1025
                             + ((v15 + (unsigned int)(unsigned __int16)(((_WORD)v14 << 8) - 1025)) >> 16);
      }
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
