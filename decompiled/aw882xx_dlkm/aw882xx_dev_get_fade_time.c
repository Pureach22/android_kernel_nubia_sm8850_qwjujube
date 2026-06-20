int *__fastcall aw882xx_dev_get_fade_time(int *result, char a2)
{
  int *v2; // x8

  v2 = &g_fade_in_time;
  if ( (a2 & 1) == 0 )
    v2 = &g_fade_out_time;
  *result = *v2;
  return result;
}
