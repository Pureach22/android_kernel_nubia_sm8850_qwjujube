__int64 __fastcall osif_dp_rxthread_napi_normal_gro_flush(__int64 a1)
{
  unsigned __int64 StatusReg; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  if ( *(_QWORD *)(a1 + 5496) )
  {
    napi_gro_flush(a1 + 5456, 0);
    if ( *(_DWORD *)(a1 + 5736) )
    {
      netif_receive_skb_list(a1 + 5720);
      *(_QWORD *)(a1 + 5720) = a1 + 5720;
      *(_QWORD *)(a1 + 5728) = a1 + 5720;
      *(_DWORD *)(a1 + 5736) = 0;
    }
  }
  return local_bh_enable_0();
}
