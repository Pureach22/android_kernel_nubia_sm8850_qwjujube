bool __fastcall wlan_is_emulation_platform(unsigned int a1)
{
  return a1 == 0xFFFF || a1 >> 2 == 10992 || a1 == 43981;
}
