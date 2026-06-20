__int64 __fastcall rmnet_map_command(__int64 a1, __int64 a2)
{
  int v2; // w8
  unsigned __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x9
  int v8; // w8
  __int64 v9; // x2
  __int64 result; // x0
  char v11; // w8
  __int64 v12; // x20
  unsigned int v13; // w8
  unsigned int v14; // w1
  int v15; // w8
  int v16; // w9
  int v17; // w8
  __int64 v18; // x8
  unsigned __int64 v19; // x9
  __int64 v20; // x10
  void (__fastcall *v21)(__int64, __int64); // x8

  v2 = *(_DWORD *)(a1 + 116);
  if ( v2 && *(_DWORD *)(a1 + 112) == v2 )
  {
    v5 = 0;
    v6 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v7 = *(_QWORD *)(v6 + 88);
    if ( v7 && (v7 & 1) == 0 )
      v5 = (((v7 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + *(unsigned int *)(v6 + 100);
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 224);
  }
  v8 = *(unsigned __int8 *)(v5 + 4);
  if ( v8 == 2 )
  {
    v9 = 1;
  }
  else
  {
    if ( v8 != 1 )
      return sk_skb_reason_drop(0, a1, 2);
    v9 = 0;
  }
  result = rmnet_map_do_flow_control(a1, a2, v9);
  if ( (unsigned __int8)result == 1 )
  {
    v11 = *(_BYTE *)(a2 + 8);
    v12 = *(_QWORD *)(a1 + 16);
    if ( (v11 & 4) != 0 )
    {
      v13 = *(_DWORD *)(a1 + 112);
      v14 = v13 - 8;
      if ( v13 >= 8 )
      {
        if ( *(_DWORD *)(a1 + 116) )
        {
          __pskb_trim(a1);
        }
        else
        {
          v15 = *(_DWORD *)(a1 + 224);
          v16 = *(_DWORD *)(a1 + 216);
          *(_DWORD *)(a1 + 112) = v14;
          *(_DWORD *)(a1 + 208) = v14 + v15 - v16;
        }
      }
    }
    v17 = *(_DWORD *)(a1 + 116);
    *(_WORD *)(a1 + 180) = -1792;
    if ( v17 && *(_DWORD *)(a1 + 112) == v17 )
    {
      v18 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
      v19 = 0;
      v20 = *(_QWORD *)(v18 + 88);
      if ( v20 && (v20 & 1) == 0 )
        v19 = (((v20 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
            + *(unsigned int *)(v18 + 100);
    }
    else
    {
      v19 = *(_QWORD *)(a1 + 224);
    }
    *(_BYTE *)(v19 + 5) = *(_BYTE *)(v19 + 5) & 0xFC | 1;
    netif_tx_lock(v12);
    v21 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v12 + 8) + 32LL);
    if ( *((_DWORD *)v21 - 1) != -998155505 )
      __break(0x8228u);
    v21(a1, v12);
    return netif_tx_unlock(v12);
  }
  return result;
}
