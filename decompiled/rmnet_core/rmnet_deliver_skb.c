__int64 __fastcall rmnet_deliver_skb(__int64 a1, __int64 a2)
{
  int v4; // w9
  __int64 v5; // x0
  __int64 v6; // x1
  int v7; // w9
  __int64 result; // x0
  int v9; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v4 = *(_DWORD *)(a1 + 216);
  v5 = *(_QWORD *)(a1 + 16);
  v6 = *(unsigned int *)(a1 + 112);
  *(_WORD *)(a1 + 184) = *(_WORD *)(a1 + 224) - v4;
  rmnet_vnd_rx_fixup(v5, v6);
  v7 = *(_DWORD *)(a1 + 224) - *(_DWORD *)(a1 + 216);
  *(_BYTE *)(a1 + 128) &= 0xF8u;
  *(_WORD *)(a1 + 186) = v7;
  result = rmnet_module_hook_perf_ecn_ingress(&v9, a1);
  if ( !(_DWORD)result || !v9 )
  {
    if ( *(_DWORD *)(a1 + 144) == 55834 || (result = rmnet_module_hook_shs_skb_entry(0, a1, a2 + 2768), !(_DWORD)result) )
    {
      result = rmnet_module_hook_shs_skb_ll_entry(0, a1, a2 + 2768);
      if ( !(_DWORD)result )
        result = netif_receive_skb(a1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
