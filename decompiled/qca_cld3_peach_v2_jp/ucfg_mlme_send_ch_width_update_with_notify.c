__int64 __fastcall ucfg_mlme_send_ch_width_update_with_notify(
        __int64 a1,
        _QWORD *a2,
        unsigned int a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  return wlan_mlme_send_ch_width_update_with_notify(a5, a6, a7, a8, a9, a10, a11, a12, a1, a2, a4, a3);
}
