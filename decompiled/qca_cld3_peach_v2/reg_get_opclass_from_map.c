__int64 __fastcall reg_get_opclass_from_map(char **a1, char a2)
{
  char *v2; // x9

  v2 = &global_op_class;
  if ( (a2 & 1) == 0 )
  {
    if ( (_UNKNOWN *)channel_map == &channel_map_us )
    {
      v2 = &us_op_class;
    }
    else if ( (_UNKNOWN *)channel_map == &channel_map_eu )
    {
      v2 = &euro_op_class;
    }
    else if ( (_UNKNOWN *)channel_map == &channel_map_china )
    {
      v2 = &china_op_class;
    }
    else if ( (_UNKNOWN *)channel_map == &channel_map_jp )
    {
      v2 = &japan_op_class;
    }
  }
  *a1 = v2;
  return 0;
}
