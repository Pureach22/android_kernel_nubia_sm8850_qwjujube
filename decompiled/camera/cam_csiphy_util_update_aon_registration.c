__int64 __fastcall cam_csiphy_util_update_aon_registration(unsigned int a1, int a2)
{
  const char *v2; // x5
  __int64 v3; // x4
  char *v4; // x8

  if ( a1 < 8 )
  {
    v4 = (char *)&g_phy_data + 56 * a1;
    if ( *(_QWORD *)v4 )
    {
      *((_DWORD *)v4 + 9) = a2;
      return 0;
    }
    v2 = "Invalid PHY idx: %d from Sensor user";
    v3 = 2340;
  }
  else
  {
    v2 = "Invalid PHY index: %u";
    v3 = 2335;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_util_update_aon_registration",
    v3,
    v2,
    a1);
  return 4294967274LL;
}
