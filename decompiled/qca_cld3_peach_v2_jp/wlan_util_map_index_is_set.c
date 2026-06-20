__int64 __fastcall wlan_util_map_index_is_set(__int64 a1, unsigned int a2)
{
  return (*(_QWORD *)(a1 + ((a2 >> 3) & 0x18LL)) >> a2) & 1LL;
}
