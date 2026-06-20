__int64 __fastcall sub_4C17C4(long double a1, long double a2, long double a3, uint16x8_t a4, uint8x8_t a5)
{
  return ol_rx_err(a1, a2, a3, COERCE_LONG_DOUBLE(vmlsl_u8(a4, *(uint8x8_t *)&a3, a5)));
}
