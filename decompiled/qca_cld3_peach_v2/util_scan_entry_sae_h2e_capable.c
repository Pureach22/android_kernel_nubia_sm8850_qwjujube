unsigned __int8 *__fastcall util_scan_entry_sae_h2e_capable(
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
  int v9; // w8
  bool v10; // zf
  __int64 v11; // x8
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v9 = result[1286];
    if ( (unsigned int)(v9 - 1) <= 2
      && *(_QWORD *)&(**(&off_AD8528 + (unsigned __int8)(v9 - 1)))[(_QWORD)result]
      && (*((_DWORD *)result + 317) & 0x18000C00) != 0 )
    {
      v10 = v9 == 1;
      v11 = 1872;
      if ( v10 )
        v11 = 1792;
      result = *(unsigned __int8 **)&result[v11];
      if ( result )
      {
        v12[0] = 0;
        result = wlan_crypto_parse_rsnxe_ie(result, v12, a2, a3, a4, a5, a6, a7, a8, a9);
        if ( result )
          result = (unsigned __int8 *)((*result >> 5) & 1);
      }
    }
    else
    {
      result = nullptr;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
