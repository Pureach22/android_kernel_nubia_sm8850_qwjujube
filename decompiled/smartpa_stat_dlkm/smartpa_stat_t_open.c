__int64 __fastcall smartpa_stat_t_open(__int64 a1, __int64 a2)
{
  return single_open(a2, smartpa_stat_t_show, 0);
}
