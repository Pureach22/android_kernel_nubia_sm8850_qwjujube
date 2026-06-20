__int64 __fastcall sub_2C02B0(long double a1, long double a2)
{
  uint16x8_t v2; // q8
  uint16x8_t v3; // q23

  return mlme_get_peer_disconnect_ies(a1, a2, COERCE_LONG_DOUBLE(vcgeq_u16(v2, v3)));
}
