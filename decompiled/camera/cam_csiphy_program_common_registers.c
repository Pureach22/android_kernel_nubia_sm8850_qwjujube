__int64 __fastcall cam_csiphy_program_common_registers(__int64 result, char a2, int a3)
{
  __int64 v3; // x9
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x1
  unsigned int v7; // w9

  v3 = *(_QWORD *)(result + 112);
  v4 = *(_QWORD *)(v3 + 8);
  if ( a3 )
  {
    v5 = *(unsigned int *)(result + 932);
    v6 = *(_QWORD *)(v3 + 8);
    return _csiphy_prgm_common_data(v5, v6);
  }
  if ( (unsigned int)active_csiphy_hw_cnt >= 8 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x8000,
             2,
             "cam_csiphy_program_common_registers",
             777,
             "MisMatched in active phy hw: %d and Max supported: %d",
             active_csiphy_hw_cnt,
             8);
  v7 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 15);
  if ( !active_csiphy_hw_cnt )
  {
    if ( v7 )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_program_common_registers",
        788,
        "Is reset required: %d",
        a2 & 1);
    _csiphy_prgm_common_data(0, v4);
    _csiphy_prgm_common_data(1, v4);
    _csiphy_prgm_common_data(2, v4);
    _csiphy_prgm_common_data(3, v4);
    _csiphy_prgm_common_data(4, v4);
    _csiphy_prgm_common_data(5, v4);
    _csiphy_prgm_common_data(6, v4);
    v5 = 7;
    v6 = v4;
    return _csiphy_prgm_common_data(v5, v6);
  }
  if ( v7 )
    return ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             (unsigned __int16)debug_mdl & 0x8000,
             4,
             "cam_csiphy_program_common_registers",
             784,
             "Common Settings already applied for all PHYs. active_phy_cnt: %d",
             active_csiphy_hw_cnt);
  return result;
}
