__int64 __fastcall osif_dp_rx_napi_gro_receive(__int64 a1, _DWORD *a2)
{
  int v2; // w9
  int v3; // w10
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x0

  v2 = *(_DWORD *)((char *)a2 + 129);
  v3 = a2[20];
  StatusReg = _ReadStatusReg(SP_EL0);
  a2[38] = v3;
  *(_DWORD *)((char *)a2 + 129) = v2 & 0xFFFFF9FF | 0x200;
  *(_DWORD *)(StatusReg + 16) += 512;
  v5 = napi_gro_receive();
  local_bh_enable_0(v5);
  return 0;
}
