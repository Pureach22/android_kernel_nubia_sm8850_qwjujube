__int64 __fastcall wlan_connectivity_t2lm_req_resp_event(
        __int64 a1,
        char a2,
        char a3,
        int a4,
        char a5,
        char a6,
        char a7)
{
  __int16 v13; // w8
  __int64 result; // x0
  _QWORD v15[4]; // [xsp+0h] [xbp-30h] BYREF
  char v16; // [xsp+20h] [xbp-10h]
  char v17; // [xsp+21h] [xbp-Fh]
  char v18; // [xsp+22h] [xbp-Eh]
  char v19; // [xsp+23h] [xbp-Dh]
  char v20; // [xsp+24h] [xbp-Ch]
  char v21; // [xsp+25h] [xbp-Bh]
  __int16 v22; // [xsp+26h] [xbp-Ah]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(unsigned __int8 *)(a1 + 168);
  v22 = 0;
  v15[2] = 0;
  v15[0] = 0;
  HIWORD(v15[0]) = v13;
  v15[3] = ktime_get(a1) / 1000;
  v15[1] = qdf_get_time_of_the_day_us();
  v16 = 1;
  v19 = a2;
  v21 = a7;
  v18 = a3;
  v17 = a5;
  v20 = a6 | (2 * wlan_get_diag_tx_status(a4));
  result = host_diag_event_report_payload(3418, 40, v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
