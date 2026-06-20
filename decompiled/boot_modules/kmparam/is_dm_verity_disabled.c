__int64 is_dm_verity_disabled()
{
  return ((unsigned __int8)debug_policy >> 1) & 1;
}
