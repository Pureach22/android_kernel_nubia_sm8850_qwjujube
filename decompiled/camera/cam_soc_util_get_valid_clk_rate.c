__int64 __fastcall cam_soc_util_get_valid_clk_rate(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 clk_level_to_apply; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  unsigned int v8; // w19
  __int64 v9; // x9
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  clk_level_to_apply = cam_soc_util_get_clk_level_to_apply(a1, a2, &v11);
  v8 = clk_level_to_apply;
  if ( (_DWORD)clk_level_to_apply )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_get_valid_clk_rate",
      1955,
      "Failed to get clk level to apply rc: %d",
      clk_level_to_apply);
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return v8;
  }
  if ( v11 < 0xA )
  {
    v9 = *(unsigned int *)(a1 + 2796);
    if ( (unsigned int)v9 <= 0x1F )
    {
      *a3 = *(int *)(a1 + ((unsigned __int64)v11 << 7) + 4 * v9 + 1384);
      goto LABEL_6;
    }
  }
  __break(0x5512u);
  return cam_soc_util_get_clk_level_to_apply(clk_level_to_apply, v6, v7);
}
