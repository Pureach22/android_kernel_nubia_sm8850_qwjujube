__int64 __fastcall hdd_hostapd_chan_change(__int64 *a1, __int64 a2)
{
  int v4; // w8
  __int64 v5; // x10
  int v6; // w9
  __int64 v7; // x0
  unsigned int v8; // w8
  __int64 v9; // x21
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  char v18; // w0
  __int16 v19; // w8
  __int64 v20; // x1
  __int64 result; // x0
  int v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+4h] [xbp-1Ch]
  __int64 v24; // [xsp+Ch] [xbp-14h]
  int v25; // [xsp+14h] [xbp-Ch]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int16 *)(a2 + 20);
  v5 = *a1;
  v6 = *(unsigned __int16 *)(a2 + 16);
  v7 = *((unsigned int *)a1 + 80);
  v23 = 0;
  v22 = v4;
  v8 = *(unsigned __int16 *)(a2 + 18);
  v9 = *(_QWORD *)(v5 + 24);
  HIDWORD(v23) = v6;
  v24 = v8;
  v25 = 0;
  v10 = sap_phymode_is_eht(v7);
  if ( (v18 & 1) != 0 )
    wlan_reg_set_create_punc_bitmap((__int64)&v22, 1);
  wlan_reg_set_channel_params_for_pwrmode(
    *(_QWORD *)(v9 + 8),
    *(_DWORD *)(a2 + 8),
    *(_DWORD *)(a2 + 12),
    (__int64)&v22,
    0,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17);
  wlan_sap_get_phymode(a1[34]);
  v19 = HIWORD(v24);
  v20 = system_wq;
  *((_DWORD *)a1 + 1501) = 1;
  *((_WORD *)a1 + 1320) = v19;
  result = queue_work_on(32, v20, a1 + 751);
  _ReadStatusReg(SP_EL0);
  return result;
}
