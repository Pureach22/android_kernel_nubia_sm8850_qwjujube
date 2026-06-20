__int64 __fastcall sub_1E5A4C(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { STGP            X29, X8, [X28,#0xC]! }
  return dsi_display_mode_match(a1, a2, a3);
}
