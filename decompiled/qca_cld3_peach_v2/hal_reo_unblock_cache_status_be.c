__int64 __fastcall hal_reo_unblock_cache_status_be(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  __int64 result; // x0
  int v9; // w9
  int v10; // w8

  v3 = a2 + 73728;
  v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a2 + 74392) + 432LL);
  if ( *((_DWORD *)v7 - 1) != -386617991 )
    __break(0x8228u);
  result = v7(a1, 288);
  v9 = *(_DWORD *)(a1 + 16);
  *(_BYTE *)(a3 + 12) = v9 & 1;
  v10 = (*(_DWORD *)(a1 + 16) >> 1) & 1;
  *(_DWORD *)(a3 + 16) = v10;
  if ( (v9 & 1) == 0 && !v10 )
    *(_QWORD *)(a2 + (((unsigned __int64)*(unsigned __int8 *)(v3 + 321) >> 3) & 0x18) + 74048) &= ~(1LL << *(_BYTE *)(v3 + 321));
  return result;
}
