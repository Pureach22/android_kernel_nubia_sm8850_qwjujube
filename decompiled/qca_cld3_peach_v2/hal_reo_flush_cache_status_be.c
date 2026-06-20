__int64 __fastcall hal_reo_flush_cache_status_be(__int64 a1, _BYTE *a2, __int64 a3)
{
  __int64 v3; // x22
  _DWORD *v7; // x8
  __int64 result; // x0
  int v9; // w8

  v3 = a3 + 73728;
  v7 = *(_DWORD **)(*(_QWORD *)(a3 + 74392) + 432LL);
  if ( *(v7 - 1) != -386617991 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _BYTE *))v7)(a1, 287, a2);
  a2[12] = *(_BYTE *)(a1 + 16) & 1;
  v9 = (*(_DWORD *)(a1 + 16) >> 1) & 3;
  a2[13] = (*(_DWORD *)(a1 + 16) >> 1) & 3;
  if ( !v9 )
    *(_QWORD *)(a3 + (((unsigned __int64)*(unsigned __int8 *)(v3 + 321) >> 3) & 0x18) + 74048) |= 1LL << *(_BYTE *)(v3 + 321);
  a2[14] = *(_BYTE *)(a1 + 17) & 1;
  a2[15] = (*(_DWORD *)(a1 + 16) >> 9) & 7;
  a2[16] = *(_DWORD *)(a1 + 16) >> 18;
  return result;
}
