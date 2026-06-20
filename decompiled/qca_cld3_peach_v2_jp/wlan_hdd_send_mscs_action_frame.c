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

  v2 = *(_QWORD *)(a2 + 55512);
  v3 = *(__int64 **)(*(_QWORD *)v2 + 24LL);
  if ( *(_DWORD *)(v3[13] + 48) )
  {
    v4 = *(_DWORD *)(v2 + 4408);
    v5 = *(unsigned int *)(v2 + 2744)
       + (unsigned __int64)*(unsigned int *)(v2 + 2696)
       + *(unsigned int *)(v2 + 2792)
       + (unsigned __int64)*(unsigned int *)(v2 + 2840)
       + *(unsigned int *)(v2 + 2888)
       + (unsigned __int64)*(unsigned int *)(v2 + 2936)
       + *(unsigned int *)(v2 + 2984)
       + *(unsigned int *)(v2 + 3032)
       + (unsigned __int64)*(unsigned int *)(v2 + 3080)
       + *(unsigned int *)(v2 + 3128)
       + *(unsigned int *)(v2 + 3176)
       + *(unsigned int *)(v2 + 3224)
       + (unsigned __int64)*(unsigned int *)(v2 + 3272)
       + *(unsigned int *)(v2 + 3320)
       + *(unsigned int *)(v2 + 3368)
       + *(unsigned int *)(v2 + 3416)
       + *(unsigned int *)(v2 + 3464)
       + (unsigned __int64)*(unsigned int *)(v2 + 3512)
       + *(unsigned int *)(v2 + 3560)
       + *(unsigned int *)(v2 + 3608)
       + *(unsigned int *)(v2 + 3656)
       + *(unsigned int *)(v2 + 3704)
       + *(unsigned int *)(v2 + 3752)
       + (unsigned __int64)*(unsigned int *)(v2 + 3800)
       + *(unsigned int *)(v2 + 3848)
       + *(unsigned int *)(v2 + 3896)
       + *(unsigned int *)(v2 + 3944)
       + *(unsigned int *)(v2 + 3992)
       + *(unsigned int *)(v2 + 4040)
       + *(unsigned int *)(v2 + 4088)
       + (unsigned __int64)*(unsigned int *)(v2 + 4136)
       + *(unsigned int *)(v2 + 4184);
    if ( !v4 )
      *(_QWORD *)(v2 + 4400) = v5;
    *(_DWORD *)(v2 + 4408) = v4 + 1;
    if ( *(_DWORD *)(v2 + 4408) * (unsigned int)ucfg_dp_get_bus_bw_compute_interval(*v3) >= 1000
                                                                                          * *(_DWORD *)(v3[13] + 52) )
    {
      *(_DWORD *)(v2 + 4408) = 0;
      if ( v5 - *(_QWORD *)(v2 + 4400) > *(unsigned int *)(v3[13] + 48)
        && (mlme_get_is_mscs_req_sent(*(_QWORD *)(v2 + 32), v6, v7, v8, v9, v10, v11, v12, v13) & 1) == 0 )
      {
        sme_send_mscs_action_frame(*(unsigned __int8 *)(v2 + 8));
      }
    }
  }
}
