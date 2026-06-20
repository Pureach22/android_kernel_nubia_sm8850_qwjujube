__int64 __fastcall sub_68F8B0(__int64 a1, __int64 a2, double a3, double a4, double a5, double a6)
{
  __int64 v6; // d26

  *(_QWORD *)a2 = v6;
  *(double *)(a2 + 8) = a6;
  return wlan_osif_send_audio_transport_switch_req(a1, a2 - 16);
}
