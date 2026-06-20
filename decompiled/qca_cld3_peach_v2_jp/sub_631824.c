__int64 __fastcall sub_631824(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  if ( !a8 )
    JUMPOUT(0x6D0C24);
  return wlan_action_oui_search(a1, a2, a3);
}
