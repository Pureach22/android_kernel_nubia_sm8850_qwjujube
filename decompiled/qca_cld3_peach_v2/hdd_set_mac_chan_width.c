__int64 __fastcall hdd_set_mac_chan_width(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  return hdd_update_channel_width(a1, a2, (_DWORD)a2 != 0, a3, a4);
}
