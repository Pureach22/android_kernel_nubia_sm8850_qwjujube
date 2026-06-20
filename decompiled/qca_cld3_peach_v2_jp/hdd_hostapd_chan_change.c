__int64 __fastcall hdd_hostapd_chan_change(
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
  int v11; // w10
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 result; // x0
  _DWORD v16[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int16 *)(a2 + 18);
  v12 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  v16[2] = *(unsigned __int16 *)(a2 + 16);
  v16[3] = v11;
  v13 = *(_QWORD *)(v12 + 8);
  v16[0] = *(unsigned __int16 *)(a2 + 20);
  v16[1] = 0;
  wlan_reg_set_channel_params_for_pwrmode(
    v13,
    *(_DWORD *)(a2 + 8),
    *(_DWORD *)(a2 + 12),
    (__int64)v16,
    0,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10);
  wlan_sap_get_phymode(*(_QWORD *)(a1 + 272));
  v14 = system_wq;
  *(_DWORD *)(a1 + 4444) = 1;
  result = queue_work_on(32, v14, a1 + 4448);
  _ReadStatusReg(SP_EL0);
  return result;
}
