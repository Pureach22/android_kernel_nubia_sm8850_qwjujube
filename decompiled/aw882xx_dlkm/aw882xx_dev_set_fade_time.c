__int64 __fastcall aw882xx_dev_set_fade_time(__int64 result, char a2)
{
  int *v2; // x8

  v2 = &g_fade_out_time;
  if ( (a2 & 1) != 0 )
    v2 = &g_fade_in_time;
  *v2 = result;
  return result;
}
