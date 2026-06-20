__int64 __fastcall lim_check_ap_assist_dfs_p2p_group(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x21
  unsigned __int8 v21; // w22
  __int64 v22; // x25

  result = (__int64)_cds_get_context(53, (__int64)"lim_check_ap_assist_dfs_p2p_group", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v19 = result;
    if ( *(_WORD *)(result + 3992) )
    {
      v20 = *(_QWORD *)(result + 21560);
      v21 = 0;
      do
      {
        v22 = *(_QWORD *)(v19 + 12264) + 10792LL * v21;
        if ( *(_BYTE *)(v22 + 70) )
        {
          if ( (*(_DWORD *)(v22 + 7036) & 0xFFFFFFFE) == 2 )
          {
            result = wlan_reg_is_dfs_for_freq(v20, *(_DWORD *)(v22 + 284), v11, v12, v13, v14, v15, v16, v17, v18);
            if ( (result & 1) != 0
              && (*(_BYTE *)(v22 + 10080) & 1) != 0
              && ((a1 & 1) == 0 || *(_DWORD *)(v22 + 7036) == 2) )
            {
              result = wlan_p2p_validate_ap_assist_dfs_group(*(_QWORD *)(v22 + 16));
            }
          }
        }
        ++v21;
      }
      while ( *(unsigned __int16 *)(v19 + 3992) > (unsigned int)v21 );
    }
  }
  return result;
}
