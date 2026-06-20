__int64 __fastcall cam_csiphy_get_settle_count(
        __int64 result,
        __int64 a2,
        unsigned __int16 *a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 (*v8)(void); // x8
  int v9; // w22
  unsigned int v10; // w23
  unsigned __int64 v11; // x9
  __int64 v12; // x8
  unsigned __int64 v13; // x11
  __int64 v14; // x21
  int v15; // w7
  unsigned int v16; // w10
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x8
  unsigned __int16 v20; // w8
  __int64 v21; // x22

  if ( (unsigned int)a2 >= 3 )
    goto LABEL_19;
  v6 = result;
  v7 = result + 104LL * (unsigned int)a2;
  v8 = *(__int64 (**)(void))(*(_QWORD *)(result + 112) + 112LL);
  v9 = *(_DWORD *)(v7 + 696);
  v10 = *(_DWORD *)(v7 + 700);
  if ( *((_DWORD *)v8 - 1) != -1852174336 )
    __break(0x8228u);
  result = v8();
  if ( (unsigned int)result > 9 || (v11 = *(unsigned __int8 *)(v6 + 100), v11 > 0x1F) )
  {
LABEL_19:
    __break(0x5512u);
    return cam_csiphy_get_lane_enable(result, a2, a3, a4, a5);
  }
  else
  {
    v12 = v7 + 600;
    v13 = *(_QWORD *)(v7 + 608) / 0xBEBC200uLL;
    v14 = *(int *)(v6 + ((unsigned __int64)(unsigned int)result << 7) + 4 * v11 + 2296);
    *a3 = v13;
    if ( !(_WORD)v13 )
    {
      v15 = *(_DWORD *)(v12 + 24);
      v16 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 15);
      if ( v15 )
      {
        if ( v16 )
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int16)debug_mdl & 0x8000,
            4,
            "cam_csiphy_get_settle_count",
            388,
            "PHY:%d cphy:%d, timer_clk_rate:%lld, t3_prepare:%u, t3_preamble:%u",
            *(_DWORD *)(v6 + 932),
            v15,
            v14,
            v9,
            v10);
        v17 = v10 / 3 + v9;
      }
      else
      {
        if ( v16 )
        {
          v21 = v12;
          ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            (unsigned __int16)debug_mdl & 0x8000,
            4,
            "cam_csiphy_get_settle_count",
            399,
            "PHY:%d cphy:%d, timer_clk_rate:%lld, data_rate:%llu",
            *(_DWORD *)(v6 + 932),
            0,
            v14,
            *(_QWORD *)(v12 + 16));
          v12 = v21;
        }
        v17 = 0x165A0BC00uLL / *(_QWORD *)(v12 + 16) + 85;
      }
      v18 = v17 * v14;
      v19 = v17 * v14 / 0x3B9ACA00;
      if ( v18 < 0x28FA6AE00LL )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          2,
          "cam_csiphy_get_settle_count",
          414,
          "PHY:%d Invalid calculated settle count:%d, setting to 0",
          *(_DWORD *)(v6 + 932),
          v19 - 10);
        v20 = 0;
      }
      else
      {
        v20 = v19 - 10;
      }
      *a3 = v20;
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x8000,
               3,
               "cam_csiphy_get_settle_count",
               419,
               "PHY:%d Calculated settle count:%u",
               *(_DWORD *)(v6 + 932),
               v20);
    }
  }
  return result;
}
