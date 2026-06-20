__int64 __fastcall sub_2C76FC(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #8, loc_29EB0C }
  return wlan_cm_init_occupied_ch_freq_list(a1, a2, a3);
}
