__int64 __fastcall wlan_ipa_set_mcc_mode(__int64 result, char a2)
{
  if ( (**(_BYTE **)(result + 1464) & 0x40) != 0 && *(_BYTE *)(result + 7298) != (a2 & 1) )
  {
    *(_BYTE *)(result + 7298) = a2 & 1;
    return queue_work_on(32, system_wq, result + 7304);
  }
  return result;
}
