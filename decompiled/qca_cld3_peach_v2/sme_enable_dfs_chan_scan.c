__int64 __fastcall sme_enable_dfs_chan_scan(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 )
  {
    *(_BYTE *)(a1 + 17184) = a2;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: mac_handle is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_enable_dfs_chan_scan",
      v10,
      v11);
    return 4;
  }
}
