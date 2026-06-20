__int64 __fastcall dp_ipa_register_op_cb(__int64 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (wlan_cfg_is_ipa_enabled(a1[5]) & 1) != 0 )
  {
    a1[2306] = a3;
    a1[2307] = a4;
  }
  return 0;
}
