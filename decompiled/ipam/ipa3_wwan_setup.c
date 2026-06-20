__int64 __fastcall ipa3_wwan_setup(__int64 a1)
{
  __int64 result; // x0
  int v3; // w9

  *(_QWORD *)(a1 + 8) = &ipa3_wwan_ops_ip;
  result = ether_setup();
  v3 = *(_DWORD *)(a1 + 176);
  *(_QWORD *)(a1 + 16) = 0;
  *(_WORD *)(a1 + 544) = 519;
  *(_DWORD *)(a1 + 56) = 9216;
  *(_WORD *)(a1 + 180) = 0;
  *(_DWORD *)(a1 + 176) = v3 & 0xFFFFEFFD;
  *(_WORD *)(a1 + 60) = 8;
  *(_BYTE *)(a1 + 824) = 0;
  *(_WORD *)(a1 + 490) = 0;
  *(_DWORD *)(a1 + 1296) = 2500;
  return result;
}
