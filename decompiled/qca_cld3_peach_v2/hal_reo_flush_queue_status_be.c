__int64 __fastcall hal_reo_flush_queue_status_be(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 result; // x0

  v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a3 + 74392) + 432LL);
  if ( *((_DWORD *)v5 - 1) != -386617991 )
    __break(0x8228u);
  result = v5(a1, 286, a2);
  *(_BYTE *)(a2 + 12) = *(_BYTE *)(a1 + 16) & 1;
  return result;
}
