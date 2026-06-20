__int64 __fastcall rmnet_deliver_skb_wq(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x22
  int v7; // w9
  __int64 v8; // x1
  int v9; // w8
  int v10; // w9
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 16);
  v7 = *(_DWORD *)(a1 + 216);
  v8 = *(unsigned int *)(a1 + 112);
  v9 = *(_DWORD *)(a1 + 224) - v7;
  *(_WORD *)(a1 + 182) = *(_WORD *)(a1 + 224) - v7;
  *(_WORD *)(a1 + 184) = v9;
  rmnet_vnd_rx_fixup(v3, v8);
  v10 = *(_DWORD *)(a1 + 224) - *(_DWORD *)(a1 + 216);
  *(_BYTE *)(a1 + 128) &= 0xF8u;
  *(_WORD *)(a1 + 186) = v10;
  if ( a3 )
    return gro_cells_receive(v3 + 2712, a1);
  result = rmnet_module_hook_shs_skb_entry(0, a1, a2 + 2768);
  if ( !(_DWORD)result )
    return netif_receive_skb(a1);
  return result;
}
