__int64 __fastcall hdd_handle_tsf_dynamic_stop(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v20; // x0
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1
    && (v9 = *(__int64 **)(a1 + 24),
        !(unsigned int)_wlan_hdd_validate_context(
                         (__int64)v9,
                         (__int64)"hdd_handle_tsf_dynamic_stop",
                         a2,
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9)) )
  {
    if ( *(_BYTE *)(a1 + 39344) == 1 )
    {
      *(_BYTE *)(a1 + 39344) = 0;
      *(_DWORD *)(a1 + 39348) = 0;
      if ( v9 )
      {
        v20 = *v9;
        v21 = 0;
        if ( !(unsigned int)ucfg_fwol_get_tsf_ptp_options(v20, &v21) && (v21 & 0x20) != 0 )
          pld_reset_tsf_sync_period(v9[12]);
      }
      result = hdd_stop_tsf_sync(a1, v11, v12, v13, v14, v15, v16, v17, v18);
    }
    else
    {
      result = 4294967182LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
