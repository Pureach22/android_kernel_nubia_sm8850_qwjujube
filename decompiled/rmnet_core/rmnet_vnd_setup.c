__int64 __fastcall rmnet_vnd_setup(__int64 a1)
{
  __int64 result; // x0
  char v3; // w8
  int v4; // w9

  *(_QWORD *)(a1 + 8) = rmnet_vnd_ops;
  *(_DWORD *)(a1 + 56) = 1500;
  *(_WORD *)(a1 + 60) = 16;
  result = get_random_bytes(a1 + 791, 6);
  v3 = *(_BYTE *)(a1 + 791);
  *(_DWORD *)(a1 + 1112) = 1000;
  v4 = *(_DWORD *)(a1 + 176);
  *(_WORD *)(a1 + 544) = 519;
  *(_QWORD *)(a1 + 16) = 0;
  *(_BYTE *)(a1 + 791) = v3 & 0xFC | 2;
  *(_BYTE *)(a1 + 1348) = 1;
  *(_WORD *)(a1 + 180) = 0;
  *(_DWORD *)(a1 + 176) = v4 & 0xFFFFEFFD;
  *(_QWORD *)(a1 + 768) = &rmnet_ethtool_ops;
  return result;
}
