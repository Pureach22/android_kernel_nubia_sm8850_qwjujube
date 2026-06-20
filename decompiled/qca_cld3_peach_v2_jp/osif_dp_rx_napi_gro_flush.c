__int64 __fastcall osif_dp_rx_napi_gro_flush(__int64 a1, _DWORD *a2, _BYTE *a3)
{
  int v3; // w9
  int v4; // w10
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x0

  v3 = *(_DWORD *)((char *)a2 + 129);
  v4 = a2[20];
  StatusReg = _ReadStatusReg(SP_EL0);
  a2[38] = v4;
  *(_DWORD *)((char *)a2 + 129) = v3 & 0xFFFFF9FF | 0x200;
  *(_DWORD *)(StatusReg + 16) += 512;
  v8 = napi_gro_receive();
  *a3 = 1;
  if ( *(_QWORD *)(a1 + 40) )
  {
    v8 = napi_gro_flush(a1, 0);
    if ( *(_DWORD *)(a1 + 280) )
    {
      v8 = netif_receive_skb_list(a1 + 264);
      *(_QWORD *)(a1 + 264) = a1 + 264;
      *(_QWORD *)(a1 + 272) = a1 + 264;
      *(_DWORD *)(a1 + 280) = 0;
    }
  }
  local_bh_enable_0(v8);
  return 0;
}
