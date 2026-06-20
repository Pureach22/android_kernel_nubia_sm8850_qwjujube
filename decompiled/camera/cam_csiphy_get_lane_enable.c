__int64 __fastcall cam_csiphy_get_lane_enable(__int64 a1, __int64 a2, __int64 a3, int *a4, unsigned __int8 *a5)
{
  unsigned __int16 v6; // w20
  unsigned int v7; // w9
  int v8; // w6
  unsigned __int8 v9; // w8
  __int64 result; // x0
  const char *v11; // x5
  __int64 v12; // x4
  unsigned __int8 *v13; // [xsp+8h] [xbp-38h]

  if ( (unsigned int)a2 >= 3 )
  {
    __break(0x5512u);
    return cam_csiphy_program_lane_settings(a1, a2, a3, a4, a5);
  }
  v6 = a3;
  v7 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 15);
  if ( !*(_DWORD *)(a1 + 104LL * (unsigned int)a2 + 624) )
  {
    if ( v7 )
    {
      v13 = a5;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        (unsigned __int16)debug_mdl & 0x8000,
        4,
        "cam_csiphy_get_lane_enable",
        892,
        "LaneEnable for DPHY");
      a5 = v13;
    }
    v9 = v6;
    if ( v6 < 4u )
    {
      v8 = dword_45B660[v6];
      if ( a5 )
      {
        if ( v6 >= (unsigned int)*a5 )
          v9 = *a5;
        *a5 = v9;
      }
      goto LABEL_14;
    }
    v11 = "Wrong lane configuration for DPHY: %d";
    v12 = 909;
LABEL_19:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_get_lane_enable",
      v12,
      v11);
    *a4 = 0;
    return 4294967274LL;
  }
  if ( v7 )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      (unsigned __int16)debug_mdl & 0x8000,
      4,
      "cam_csiphy_get_lane_enable",
      873,
      "LaneEnable for CPHY");
  if ( v6 >= 3u )
  {
    v11 = "Wrong lane configuration for CPHY : %d";
    v12 = 887;
    goto LABEL_19;
  }
  v8 = dword_4558F0[v6];
LABEL_14:
  *a4 = v8;
  result = 0;
  if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int16)debug_mdl & 0x8000,
      4,
      "cam_csiphy_get_lane_enable",
      918,
      "Lane_select: 0x%x",
      v8);
    return 0;
  }
  return result;
}
