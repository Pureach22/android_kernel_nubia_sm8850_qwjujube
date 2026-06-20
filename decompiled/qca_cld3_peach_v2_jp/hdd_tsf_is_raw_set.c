__int64 *__fastcall hdd_tsf_is_raw_set(__int64 *result)
{
  __int64 v1; // x0
  int tsf_ptp_options; // w8
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v1 = *result;
    v3 = 0;
    tsf_ptp_options = ucfg_fwol_get_tsf_ptp_options(v1, &v3);
    result = nullptr;
    if ( !tsf_ptp_options )
      result = (__int64 *)(((unsigned __int8)v3 >> 2) & 1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
