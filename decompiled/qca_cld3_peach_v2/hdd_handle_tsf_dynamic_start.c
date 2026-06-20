__int64 __fastcall hdd_handle_tsf_dynamic_start(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // x0
  int tsf_ptp_options; // w8
  int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_6;
  v10 = *(_QWORD *)(a1 + 24);
  if ( v10 && *(int *)(v10 + 3236) > 0 )
  {
LABEL_4:
    result = 4294967182LL;
    goto LABEL_7;
  }
  if ( (unsigned int)_wlan_hdd_validate_context(
                       *(_QWORD *)(a1 + 24),
                       (__int64)"hdd_handle_tsf_dynamic_start",
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10) )
  {
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  v22 = a1;
  if ( a2 )
    LODWORD(a2) = *(_DWORD *)(a2 + 4);
  if ( *(_BYTE *)(a1 + 39344) == 1 )
  {
    if ( (_DWORD)a2 != *(_DWORD *)(a1 + 39348) )
    {
      result = 0;
      *(_DWORD *)(a1 + 39348) = a2;
      goto LABEL_7;
    }
    goto LABEL_4;
  }
  *(_DWORD *)(a1 + 39348) = a2;
  *(_BYTE *)(a1 + 39344) = 1;
  if ( v10 )
  {
    v23 = *(_QWORD *)v10;
    v25 = 0;
    tsf_ptp_options = ucfg_fwol_get_tsf_ptp_options(v23, &v25);
    v22 = a1;
    if ( !tsf_ptp_options && (v25 & 0x20) != 0 )
    {
      pld_set_tsf_sync_period(*(_QWORD *)(v10 + 96), a2);
      v22 = a1;
    }
  }
  result = hdd_start_tsf_sync(v22, v14, v15, v16, v17, v18, v19, v20, v21);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
