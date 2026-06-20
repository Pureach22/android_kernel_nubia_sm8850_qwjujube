void __fastcall wlan_hdd_send_mscs_action_frame(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 *v3; // x20
  int v4; // w8
  unsigned __int64 v5; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v2 = *(_QWORD *)(a2 + 55520);
  v3 = *(__int64 **)(*(_QWORD *)v2 + 24LL);
  if ( *(_DWORD *)(v3[13] + 48) )
  {
    v4 = *(_DWORD *)(v2 + 5960);
    v5 = *(unsigned int *)(v2 + 3016)
       + (unsigned __int64)*(unsigned int *)(v2 + 2968)
       + *(unsigned int *)(v2 + 3064)
       + (unsigned __int64)*(unsigned int *)(v2 + 3112)
       + *(unsigned int *)(v2 + 3160)
       + (unsigned __int64)*(unsigned int *)(v2 + 3208)
       + *(unsigned int *)(v2 + 3256)
       + *(unsigned int *)(v2 + 3304)
       + (unsigned __int64)*(unsigned int *)(v2 + 3352)
       + *(unsigned int *)(v2 + 3400)
       + *(unsigned int *)(v2 + 3448)
       + *(unsigned int *)(v2 + 3496)
       + (unsigned __int64)*(unsigned int *)(v2 + 3544)
       + *(unsigned int *)(v2 + 3592)
       + *(unsigned int *)(v2 + 3640)
       + *(unsigned int *)(v2 + 3688)
       + *(unsigned int *)(v2 + 3736)
       + (unsigned __int64)*(unsigned int *)(v2 + 3784)
       + *(unsigned int *)(v2 + 3832)
       + *(unsigned int *)(v2 + 3880)
       + *(unsigned int *)(v2 + 3928)
       + *(unsigned int *)(v2 + 3976)
       + *(unsigned int *)(v2 + 4024)
       + (unsigned __int64)*(unsigned int *)(v2 + 4072)
       + *(unsigned int *)(v2 + 4120)
       + *(unsigned int *)(v2 + 4168)
       + *(unsigned int *)(v2 + 4216)
       + *(unsigned int *)(v2 + 4264)
       + *(unsigned int *)(v2 + 4312)
       + *(unsigned int *)(v2 + 4360)
       + (unsigned __int64)*(unsigned int *)(v2 + 4408)
       + *(unsigned int *)(v2 + 4456);
    if ( !v4 )
      *(_QWORD *)(v2 + 5952) = v5;
    *(_DWORD *)(v2 + 5960) = v4 + 1;
    if ( *(_DWORD *)(v2 + 5960) * (unsigned int)ucfg_dp_get_bus_bw_compute_interval(*v3) >= 1000
                                                                                          * *(_DWORD *)(v3[13] + 52) )
    {
      *(_DWORD *)(v2 + 5960) = 0;
      if ( v5 - *(_QWORD *)(v2 + 5952) > *(unsigned int *)(v3[13] + 48)
        && (mlme_get_is_mscs_req_sent(*(_QWORD *)(v2 + 32), v6, v7, v8, v9, v10, v11, v12, v13) & 1) == 0 )
      {
        sme_send_mscs_action_frame(*(unsigned __int8 *)(v2 + 8));
      }
    }
  }
}
