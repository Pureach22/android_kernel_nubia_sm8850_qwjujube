__int64 __fastcall reg_init_channel_map(__int64 result)
{
  unsigned __int8 *v1; // x8
  unsigned __int16 v2; // w9
  int v3; // w11

  if ( (int)result > 3 )
  {
    if ( (int)result <= 5 )
    {
      if ( (_DWORD)result == 4 )
      {
        v1 = (unsigned __int8 *)&channel_map_china;
        goto LABEL_17;
      }
      goto LABEL_13;
    }
    if ( (_DWORD)result != 6 )
    {
      if ( (_DWORD)result != 0xFFFF )
        goto LABEL_22;
LABEL_13:
      v1 = (unsigned __int8 *)&channel_map_global;
      goto LABEL_17;
    }
LABEL_14:
    v1 = (unsigned __int8 *)&channel_map_jp;
    goto LABEL_17;
  }
  if ( (int)result > 1 )
  {
    if ( (_DWORD)result == 2 )
    {
      v1 = (unsigned __int8 *)&channel_map_eu;
      goto LABEL_17;
    }
    goto LABEL_14;
  }
  if ( !(_DWORD)result )
    goto LABEL_13;
  if ( (_DWORD)result != 1 )
  {
LABEL_22:
    v1 = (unsigned __int8 *)channel_map;
    goto LABEL_18;
  }
  v1 = (unsigned __int8 *)&channel_map_us;
LABEL_17:
  channel_map = (__int64)v1;
LABEL_18:
  v2 = 41;
  do
  {
    v3 = v1[12 * v2 + 4];
    if ( !v2 )
      break;
    --v2;
  }
  while ( !v3 );
  g_reg_max_5g_chan_num = v3;
  return result;
}
