void __fastcall hal_txmon_get_frame_timestamp_peach(__int64 a1, _QWORD *a2, __int64 a3)
{
  *(_DWORD *)(a3 + 40) = *a2;
}
