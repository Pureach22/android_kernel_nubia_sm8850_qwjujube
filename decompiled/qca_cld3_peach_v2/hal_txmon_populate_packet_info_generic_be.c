__int64 __fastcall hal_txmon_populate_packet_info_generic_be(__int64 result, __int64 a2)
{
  int v2; // w9
  int v3; // w8
  unsigned int v4; // w8

  v2 = *(unsigned __int16 *)(a2 + 10);
  *(_QWORD *)a2 = *(_QWORD *)result;
  v3 = (*(_DWORD *)(result + 8) & 0xFFF | (v2 << 16)) + 1;
  *(_DWORD *)(a2 + 8) = v3;
  v4 = v3 & 0xFFFE1FFF | *(_DWORD *)(result + 8) & 0x10000;
  *(_DWORD *)(a2 + 8) = v4;
  *(_DWORD *)(a2 + 8) = v4 & 0xFFFDFFFF | *(_DWORD *)(result + 8) & 0x20000;
  return result;
}
