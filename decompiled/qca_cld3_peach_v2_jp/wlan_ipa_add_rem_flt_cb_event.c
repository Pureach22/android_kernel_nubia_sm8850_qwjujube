__int64 __fastcall wlan_ipa_add_rem_flt_cb_event(__int64 a1)
{
  return qdf_event_create((_DWORD *)(a1 + 8072));
}
