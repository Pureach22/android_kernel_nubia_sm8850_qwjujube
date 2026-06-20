__int64 __fastcall rmnet_set_skb_proto(__int64 result)
{
  int v1; // w8
  _BYTE *v2; // x10
  __int64 v3; // x8
  __int64 v4; // x9
  int v5; // w8
  __int16 v6; // w9
  __int16 v7; // w8

  v1 = *(_DWORD *)(result + 116);
  if ( v1 && *(_DWORD *)(result + 112) == v1 )
  {
    v2 = nullptr;
    v3 = *(_QWORD *)(result + 216) + *(unsigned int *)(result + 212);
    v4 = *(_QWORD *)(v3 + 88);
    if ( v4 && (v4 & 1) == 0 )
      v2 = (_BYTE *)((((v4 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                   + *(unsigned int *)(v3 + 100));
  }
  else
  {
    v2 = *(_BYTE **)(result + 224);
  }
  v5 = *v2 & 0xF0;
  if ( v5 == 96 )
    v6 = -8826;
  else
    v6 = -1792;
  if ( v5 == 64 )
    v7 = 8;
  else
    v7 = v6;
  *(_WORD *)(result + 180) = v7;
  return result;
}
