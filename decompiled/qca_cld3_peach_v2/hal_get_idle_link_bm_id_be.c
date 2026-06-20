__int64 __fastcall hal_get_idle_link_bm_id_be(unsigned __int8 a1)
{
  if ( a1 <= 3u )
    return wbm_idle_link_bm_map[a1];
  else
    return 0;
}
