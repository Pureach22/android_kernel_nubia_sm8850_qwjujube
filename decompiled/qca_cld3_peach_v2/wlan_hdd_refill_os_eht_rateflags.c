_WORD *__fastcall wlan_hdd_refill_os_eht_rateflags(_WORD *result, char a2)
{
  if ( a2 == 5 )
    *result |= 0x80u;
  return result;
}
