__int64 __fastcall cam_csiphy_program_secure_mode(__int64 a1, char a2, unsigned int a3)
{
  __int64 v4; // x24
  unsigned int v7; // w20
  unsigned int v8; // w0

  if ( a3 >= 3 )
  {
    __break(0x5512u);
    return cam_csiphy_reset_phyconfig_param();
  }
  else
  {
    v4 = a1 + 104LL * a3;
    if ( (*(_BYTE *)(v4 + 680) & 1) != 0 || (cam_is_mink_api_available() & 1) == 0 )
    {
      if ( *(_BYTE *)(a1 + 4733) == 1 && (v8 = cam_cpas_enable_clks_for_domain_id(1)) != 0 )
      {
        v7 = v8;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_program_secure_mode",
          1994,
          "Failed to enable the Domain ID clocks");
      }
      else
      {
        v7 = cam_csiphy_notify_secure_mode(a1, a2 & 1, a3);
        if ( *(_BYTE *)(a1 + 4733) == 1 && (unsigned int)cam_cpas_enable_clks_for_domain_id(0) )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x8000,
            1,
            "cam_csiphy_program_secure_mode",
            2003,
            "Failed to disable the Domain ID clocks");
        if ( (a2 & 1) == 0 && (cam_is_mink_api_available() & 1) != 0 )
          *(_BYTE *)(v4 + 680) = 0;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_program_secure_mode",
        1986,
        "PHY[%u] domain id info not updated, aborting secure call",
        *(_DWORD *)(a1 + 932));
      return (unsigned int)-22;
    }
    return v7;
  }
}
