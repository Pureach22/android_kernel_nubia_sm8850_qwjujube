bool __fastcall wlan_util_map_is_any_index_set(__int64 a1, int a2)
{
  return find_first_bit(a1, (unsigned int)(8 * a2)) != 8 * a2;
}
