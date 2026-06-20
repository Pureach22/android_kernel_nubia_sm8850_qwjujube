__int64 __fastcall dp_rx_skip_tlvs(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x9
  __int64 v5; // x1

  *(_DWORD *)(a2 + 48) = *(_DWORD *)(a2 + 48) & 0xFFFFFF8F | (16 * (a3 & 7));
  v4 = *(_QWORD *)(a2 + 40);
  v5 = (unsigned int)*(unsigned __int16 *)(a1 + 1138) + a3;
  if ( v4 )
    *(_QWORD *)(a2 + 40) = v4 + (unsigned int)v5;
  return skb_pull(a2, v5);
}
