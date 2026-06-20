__int64 __fastcall dsi_display_continuous_clk_ctrl(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x8
  char v5; // w19
  __int64 v6; // x8

  if ( result )
  {
    v2 = result;
    if ( *(_BYTE *)(*(_QWORD *)(result + 264) + 1275LL) == 1 )
    {
      if ( *(_DWORD *)(result + 160) )
      {
        v3 = *(_QWORD *)(result + 168);
        v4 = *(unsigned int *)(v3 + 1608);
        if ( (unsigned int)v4 >= 3 )
          goto LABEL_14;
        v5 = a2;
        if ( *(_QWORD *)(*(_QWORD *)(v2 + 192) + 8 * v4 + 432) )
        {
          dsi_ctrl_hs_req_sel(v3, 1);
          dsi_ctrl_set_continuous_clk(*(_QWORD *)(v2 + 168), v5 & 1);
          result = ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_set_continuous_clk)(*(_QWORD *)(v2 + 192), v5 & 1);
        }
        else
        {
          result = dsi_ctrl_set_continuous_clk(v3, a2 & 1);
        }
        if ( *(_DWORD *)(v2 + 160) >= 2u )
        {
          v3 = *(_QWORD *)(v2 + 216);
          v6 = *(unsigned int *)(v3 + 1608);
          if ( (unsigned int)v6 <= 2 )
          {
            if ( !*(_QWORD *)(*(_QWORD *)(v2 + 240) + 8 * v6 + 432) )
              return dsi_ctrl_set_continuous_clk(v3, v5 & 1);
            dsi_ctrl_hs_req_sel(v3, 1);
            dsi_ctrl_set_continuous_clk(*(_QWORD *)(v2 + 216), v5 & 1);
            return ((__int64 (__fastcall *)(_QWORD, _QWORD))dsi_phy_set_continuous_clk)(*(_QWORD *)(v2 + 240), v5 & 1);
          }
LABEL_14:
          __break(0x5512u);
          return dsi_display_set_ulps(v3, a2);
        }
      }
    }
  }
  return result;
}
