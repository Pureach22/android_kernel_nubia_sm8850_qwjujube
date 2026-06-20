__int64 __fastcall ucfg_p2p_extract_ap_assist_dfs_params(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        char a4,
        unsigned int a5,
        char a6)
{
  unsigned int v6; // w6

  v6 = 0;
  if ( a2 && a3 )
    return (unsigned int)p2p_extract_ap_assist_dfs_params(a1, a2, a3, a4 & 1, a5, a6 & 1);
  return v6;
}
