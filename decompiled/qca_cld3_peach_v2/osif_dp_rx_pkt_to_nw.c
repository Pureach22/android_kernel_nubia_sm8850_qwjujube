__int64 __fastcall osif_dp_rx_pkt_to_nw(__int64 a1, int a2)
{
  unsigned __int64 StatusReg; // x8
  int v3; // w19
  int v4; // w0

  switch ( a2 )
  {
    case 0:
      goto LABEL_5;
    case 1:
      v4 = netif_receive_skb();
      return 16 * (unsigned int)(v4 != 0);
    case 2:
      StatusReg = _ReadStatusReg(SP_EL0);
      *(_DWORD *)(StatusReg + 16) += 512;
      v3 = netif_receive_skb();
      local_bh_enable_0();
      v4 = v3;
      break;
    default:
LABEL_5:
      v4 = netif_rx();
      break;
  }
  return 16 * (unsigned int)(v4 != 0);
}
