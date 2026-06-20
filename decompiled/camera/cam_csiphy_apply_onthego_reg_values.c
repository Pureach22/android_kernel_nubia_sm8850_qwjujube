__int64 __fastcall cam_csiphy_apply_onthego_reg_values(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x19
  unsigned __int64 v3; // x24
  unsigned __int64 v4; // x25
  unsigned __int64 v5; // x26
  __int64 v6; // x22
  int v7; // w0
  __int64 v8; // x0

  v2 = result;
  if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
  {
    if ( a2 < 8u )
    {
      v3 = a2;
      result = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 (unsigned __int16)debug_mdl & 0x8000,
                 4,
                 "cam_csiphy_apply_onthego_reg_values",
                 493,
                 "csiphy: %d, onthego_reg_count: %d",
                 a2,
                 csiphy_onthego_reg_count[a2]);
      if ( v3 <= 7 )
        goto LABEL_5;
      goto LABEL_17;
    }
LABEL_18:
    __break(0x5512u);
    JUMPOUT(0x280598);
  }
  if ( a2 > 7u )
    goto LABEL_18;
  v3 = a2;
  if ( a2 > 7uLL )
  {
LABEL_17:
    __break(1u);
    goto LABEL_18;
  }
LABEL_5:
  v4 = 0;
  v5 = 360LL * (unsigned int)v3;
  while ( (__int64)v4 < csiphy_onthego_reg_count[v3] )
  {
    if ( v4 > 0x58 )
      goto LABEL_18;
    if ( v5 + 4 <= 0xB3F && v5 <= 0xB3F )
    {
      cam_io_w_mb(
        *(unsigned int *)((char *)&csiphy_onthego_regvals + v5 + 4),
        v2 + *(unsigned int *)((char *)&csiphy_onthego_regvals + v5));
      if ( v5 + 8 <= 0xB3F )
      {
        v8 = *(unsigned int *)((char *)&csiphy_onthego_regvals + v5 + 8);
        if ( (_DWORD)v8 )
          usleep_range_state(v8, (unsigned int)(v8 + 5), 2);
        v6 = *(unsigned int *)((char *)&csiphy_onthego_regvals + v5);
        v7 = cam_io_r_mb(v2 + v6);
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x8000,
                   3,
                   "cam_csiphy_apply_onthego_reg_values",
                   506,
                   "Offset: 0x%x, Val: 0x%x Delay(us): %u",
                   v6,
                   v7,
                   *(_DWORD *)((char *)&csiphy_onthego_regvals + v5 + 8));
        v4 += 3LL;
        v5 += 12LL;
        if ( v3 <= 7 )
          continue;
      }
    }
    goto LABEL_17;
  }
  return result;
}
