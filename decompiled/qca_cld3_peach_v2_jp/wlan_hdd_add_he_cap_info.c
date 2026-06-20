__int64 __fastcall wlan_hdd_add_he_cap_info(_BYTE *a1, __int64 a2, __int64 a3)
{
  int v4; // w0

  if ( (a1[467] & 0x40) == 0 )
    return 0;
  scnprintf(
    a2,
    a3,
    "mac_cap_info = 0x%02x%02x%02x%02x%02x%02x\n"
    "phy_cap_ch_width = 0x%02x\n"
    "phy_cap_8_to_23 = 0x%02x%02x\n"
    "phy_cap_24_to_39 = 0x%02x%02x\n"
    "phy_cap_40_to_55 = 0x%02x%02x\n"
    "phy_cap_56_to_71 = 0x%02x%02x\n"
    "phy_cap_72_to_87 = 0x%02x%02x\n",
    (unsigned __int8)a1[504],
    (unsigned __int8)a1[503],
    (unsigned __int8)a1[502],
    (unsigned __int8)a1[501],
    (unsigned __int8)a1[500],
    (unsigned __int8)a1[499],
    (unsigned __int8)a1[505],
    (unsigned __int8)a1[507],
    (unsigned __int8)a1[506],
    (unsigned __int8)a1[509],
    (unsigned __int8)a1[508],
    (unsigned __int8)a1[511],
    (unsigned __int8)a1[510],
    (unsigned __int8)a1[513],
    (unsigned __int8)a1[512],
    (unsigned __int8)a1[515],
    (unsigned __int8)a1[514]);
  return v4 & (unsigned int)~(v4 >> 31);
}
