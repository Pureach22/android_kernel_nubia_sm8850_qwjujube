unsigned __int8 *__fastcall util_is_rsnxe_h2e_capable(
        unsigned __int8 *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v9[0] = 0;
    result = wlan_crypto_parse_rsnxe_ie(result, v9, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( result )
      result = (unsigned __int8 *)((*result >> 5) & 1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
