__int64 __fastcall sub_1E7F8C(__int64 a1, __int64 a2, __int64 a3, __int16 a4)
{
  if ( (a4 & 0x1000) != 0 )
    JUMPOUT(0x1E691C);
  return dsi_display_pre_kickoff();
}
