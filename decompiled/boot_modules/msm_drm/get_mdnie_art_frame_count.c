int *__fastcall get_mdnie_art_frame_count(
        int *result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  int v8; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    v8 = (1 << (BYTE2(a2) & 0xF)) + 1;
    *result = v8;
    return (int *)sde_evtlog_log(
                    sde_dbg_base_evtlog,
                    "get_mdnie_art_frame_count",
                    131,
                    -1,
                    v8,
                    -1059143953,
                    a7,
                    a8,
                    vars0);
  }
  return result;
}
