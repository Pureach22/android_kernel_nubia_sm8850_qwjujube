__int64 __fastcall disconnect_sta_and_restart_sap(__int64 *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  bool v10; // zf
  char v11; // w21
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  int v15; // w24
  __int64 v16; // x9
  unsigned int v17; // w8
  __int64 v18; // x9
  unsigned __int8 v19; // w10
  int next_adapter; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // [xsp+Ch] [xbp-1B4h] BYREF
  __int64 v30; // [xsp+10h] [xbp-1B0h] BYREF
  __int64 v31; // [xsp+18h] [xbp-1A8h] BYREF
  _BYTE s[408]; // [xsp+20h] [xbp-1A0h] BYREF
  __int64 v33; // [xsp+1B8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  memset(s, 0, sizeof(s));
  v29 = 0;
  hdd_check_and_disconnect_sta_on_invalid_channel((__int64)a1, 65527);
  if ( (unsigned int)policy_mgr_get_valid_chans(*a1, s, &v29) )
    v10 = 1;
  else
    v10 = v29 == 0;
  v11 = !v10;
  if ( v10 )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: No valid channels present, stop the SAPs",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "disconnect_sta_and_restart_sap");
  result = hdd_get_front_adapter(a1, &v31);
  if ( v31 && !(_DWORD)result )
  {
    result = v31;
    do
    {
      if ( !(unsigned int)_hdd_validate_adapter(result, "disconnect_sta_and_restart_sap") && *(_DWORD *)(v31 + 40) == 1 )
      {
        v13 = *(_QWORD *)(v31 + 52832);
        if ( (v11 & 1) != 0 )
        {
          v14 = a1[452];
          if ( v14 && *(_QWORD *)(v14 + 8) )
          {
            v15 = *(_DWORD *)(v13 + 2424);
            qdf_mutex_acquire((__int64)(a1 + 453));
            v16 = a1[452];
            v17 = *(_DWORD *)v16;
            if ( *(_DWORD *)v16 )
            {
              v18 = *(_QWORD *)(v16 + 8);
              v19 = 0;
              while ( *(_DWORD *)(v18 + 12LL * v19) != v15 )
              {
                if ( v17 <= ++v19 )
                  goto LABEL_22;
              }
              qdf_mutex_release((__int64)(a1 + 453));
              policy_mgr_check_sap_restart(
                *a1,
                *(unsigned __int8 *)(*(_QWORD *)(v31 + 52832) + 8LL),
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28);
            }
            else
            {
LABEL_22:
              qdf_mutex_release((__int64)(a1 + 453));
            }
          }
        }
        else
        {
          wlan_hdd_stop_sap(v13);
        }
      }
      next_adapter = hdd_get_next_adapter(a1, v31, &v30);
      result = v30;
      v31 = v30;
    }
    while ( v30 && !next_adapter );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
