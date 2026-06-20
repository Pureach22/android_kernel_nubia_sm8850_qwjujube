__int64 __fastcall hal_reo_rx_update_queue_status_be(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x9

  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a3 + 74392) + 432LL);
  if ( *((_DWORD *)v3 - 1) != -386617991 )
    __break(0x8229u);
  return v3(a1, 172, a2);
}
