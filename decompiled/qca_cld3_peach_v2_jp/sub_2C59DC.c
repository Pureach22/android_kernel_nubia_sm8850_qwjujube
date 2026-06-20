__int64 sub_2C59DC()
{
  unsigned __int16 v0; // w15
  __int64 v1; // x28

  atomic_store(v0, (unsigned __int16 *)(v1 + 92));
  return wlan_cm_set_psk_pmk();
}
