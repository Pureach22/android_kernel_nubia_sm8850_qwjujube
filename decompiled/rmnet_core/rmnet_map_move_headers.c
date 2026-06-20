__int64 __fastcall rmnet_map_move_headers(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  unsigned __int8 *v3; // x21
  __int64 v4; // x8
  __int64 v5; // x9
  unsigned int v6; // w8
  unsigned __int16 v7; // w20
  int v8; // w8
  int v9; // w21
  unsigned __int8 v10; // w8
  unsigned __int16 v11; // w0
  __int64 v12; // x8
  unsigned __int8 v13[4]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(result + 116);
  if ( !v1 )
    goto LABEL_20;
  v2 = result;
  if ( *(_DWORD *)(result + 112) == v1 )
  {
    v3 = nullptr;
    v4 = *(_QWORD *)(result + 216) + *(unsigned int *)(result + 212);
    v5 = *(_QWORD *)(v4 + 88);
    if ( v5 && (v5 & 1) == 0 )
      v3 = (unsigned __int8 *)((((v5 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                             + *(unsigned int *)(v4 + 100));
  }
  else
  {
    v3 = *(unsigned __int8 **)(result + 224);
  }
  v6 = *v3;
  if ( v6 >> 4 == 6 )
  {
    v10 = v3[6];
    v14 = 0;
    v13[0] = v10;
    v11 = ipv6_skip_exthdr(result, 40, v13, &v14);
    v8 = v13[0];
    v7 = v11;
    if ( v13[0] == 44 )
      goto LABEL_11;
  }
  else
  {
    if ( v6 >> 4 != 4 )
      goto LABEL_20;
    v7 = 4 * (v6 & 0x3F);
    if ( (*((_WORD *)v3 + 3) & 0xFF1F) != 0 )
    {
LABEL_16:
      v9 = 0;
      goto LABEL_18;
    }
    v8 = v3[9];
    if ( v8 == 44 )
    {
LABEL_11:
      v9 = 0;
      v7 += 8;
      goto LABEL_18;
    }
  }
  if ( v8 != 17 )
  {
    if ( v8 == 6 )
    {
      v9 = (*(unsigned __int16 *)&v3[v7 + 12] >> 2) & 0x3C;
      goto LABEL_18;
    }
    goto LABEL_16;
  }
  v9 = 8;
LABEL_18:
  result = _pskb_pull_tail(v2, v9 + (unsigned int)v7);
  v12 = *(_QWORD *)(v2 + 224) - *(_QWORD *)(v2 + 216);
  *(_WORD *)(v2 + 184) = v12;
  if ( v9 )
    *(_WORD *)(v2 + 182) = v7 + v12;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
