__int64 __fastcall sub_DFAC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __asm { STZG            X13, [X7,#-0xC30]! }
  return drm_panel_dp_aux_backlight(a1, a2, a3, a4, a5, a6, a7, a8);
}
