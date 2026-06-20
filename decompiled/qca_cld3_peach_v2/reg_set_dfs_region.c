__int64 __fastcall reg_set_dfs_region(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int8 *v20; // x8
  unsigned __int16 v21; // w9
  int v22; // w11

  result = reg_get_pdev_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    return qdf_trace_msg(
             0x51u,
             2u,
             "%s: psoc reg component is NULL",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "reg_set_dfs_region");
  *(_DWORD *)(result + 56716) = a2;
  if ( a2 > 3 )
  {
    if ( a2 <= 5 )
    {
      if ( a2 == 4 )
      {
        v20 = (unsigned __int8 *)&channel_map_china;
        goto LABEL_19;
      }
      goto LABEL_15;
    }
    if ( a2 != 6 )
    {
      if ( a2 != 0xFFFF )
        goto LABEL_24;
LABEL_15:
      v20 = (unsigned __int8 *)&channel_map_global;
      goto LABEL_19;
    }
LABEL_16:
    v20 = (unsigned __int8 *)&channel_map_jp;
    goto LABEL_19;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v20 = (unsigned __int8 *)&channel_map_eu;
      goto LABEL_19;
    }
    goto LABEL_16;
  }
  if ( !a2 )
    goto LABEL_15;
  if ( a2 == 1 )
  {
    v20 = (unsigned __int8 *)&channel_map_us;
LABEL_19:
    channel_map = (__int64)v20;
    goto LABEL_20;
  }
LABEL_24:
  v20 = (unsigned __int8 *)channel_map;
LABEL_20:
  v21 = 41;
  do
  {
    v22 = v20[12 * v21 + 4];
    if ( !v21 )
      break;
    --v21;
  }
  while ( !v22 );
  g_reg_max_5g_chan_num = v22;
  return result;
}
