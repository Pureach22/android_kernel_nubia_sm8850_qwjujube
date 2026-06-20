bool __fastcall drm_dp_read_sink_count_cap(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  return *(_DWORD *)(a1 + 156) != 14 && *a2 >= 0x11u && (a2[5] & 1) != 0 && (*(_BYTE *)(a3 + 12) & 4) == 0;
}
