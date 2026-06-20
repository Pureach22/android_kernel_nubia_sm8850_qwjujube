__int64 __fastcall msm_camera_pinctrl_init(unsigned __int64 *a1, __int64 a2)
{
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  __int64 result; // x0
  const char *v7; // x5
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x4

  v3 = devm_pinctrl_get(a2);
  *a1 = v3;
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
  {
    v4 = pinctrl_lookup_state(v3, "cam_default");
    a1[1] = v4;
    if ( v4 && v4 < 0xFFFFFFFFFFFFF001LL )
    {
      v5 = pinctrl_lookup_state(*a1, "cam_suspend");
      a1[2] = v5;
      if ( v5 && v5 < 0xFFFFFFFFFFFFF001LL )
        return 0;
      v7 = "Failed to get the suspend state pinctrl handle";
      v8 = 0x800000000LL;
      v9 = 1;
      v10 = 2094;
    }
    else
    {
      v7 = "Failed to get the active state pinctrl handle";
      v8 = 0x800000000LL;
      v9 = 1;
      v10 = 2086;
    }
    goto LABEL_13;
  }
  result = 4294967274LL;
  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
  {
    v7 = "Getting pinctrl handle failed";
    v8 = debug_mdl & 0x800000000LL;
    v9 = 4;
    v10 = 2078;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v8,
      v9,
      "msm_camera_pinctrl_init",
      v10,
      v7);
    return 4294967274LL;
  }
  return result;
}
