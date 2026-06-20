__int64 __fastcall cam_csiphy_disable_hw(__int64 a1, unsigned int a2, long double a3, long double a4, int16x8_t a5)
{
  int v5; // w8
  __int64 v9; // x1

  if ( !a1 || (v5 = *(_DWORD *)(a1 + 120)) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_disable_hw",
      278,
      "csiphy dev NULL / ref_count ZERO");
    return 0;
  }
  if ( a2 < 4 )
  {
    *(_DWORD *)(a1 + 120) = v5 - 1;
    if ( v5 == 1 )
    {
      cam_csiphy_reset(a1);
      if ( *(_BYTE *)(a1 + 4112) == 1 && *(_BYTE *)(a1 + 104LL * a2 + 688) == 1 )
        v9 = *(unsigned int *)(a1 + 104LL * a2 + 684);
      else
        v9 = 0xFFFFFFFFLL;
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
        a1 + 912,
        v9,
        1,
        1);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_disable_hw",
        286,
        "csiphy refcount = %d",
        v5 - 1);
    }
    return 0;
  }
  __break(0x5512u);
  return cam_csiphy_parse_dt_info(a3, a4, COERCE_LONG_DOUBLE(vqaddq_s16(*(int16x8_t *)&a4, a5)));
}
