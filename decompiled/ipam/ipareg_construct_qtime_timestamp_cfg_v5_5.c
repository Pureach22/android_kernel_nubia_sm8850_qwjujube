void __fastcall ipareg_construct_qtime_timestamp_cfg_v5_5(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8

  v3 = ((*(_DWORD *)(a2 + 8) & 0x1F) << 8) | *a3;
  *a3 = v3;
  *a3 = ((*(_DWORD *)(a2 + 12) & 0x1F) << 16) | v3;
}
