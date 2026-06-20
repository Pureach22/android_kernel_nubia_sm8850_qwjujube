__int64 __fastcall populate_dot11f_wsc_registrar_info_in_probe_res(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  char v3; // w10
  char v4; // w10
  __int64 v5; // x10

  v2 = a1 + 0x2000;
  *(_BYTE *)(a2 + 5) = 1;
  v3 = *(_BYTE *)(a1 + 12244);
  *(_BYTE *)(a2 + 7) = 1;
  *(_BYTE *)(a2 + 6) = v3;
  v4 = *(_BYTE *)(a1 + 12245);
  *(_BYTE *)(a2 + 10) = 1;
  *(_BYTE *)(a2 + 8) = v4;
  v5 = *(_QWORD *)(a1 + 8);
  LODWORD(v5) = *(_DWORD *)(v5 + 5820);
  *(_BYTE *)(a2 + 14) = 1;
  *(_WORD *)(a2 + 12) = v5;
  *(_WORD *)(a2 + 16) = *(_WORD *)(v2 + 4054);
  return 0;
}
