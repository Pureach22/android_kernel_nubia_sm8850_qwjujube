__int64 __fastcall wlan_hdd_deinit_multi_client_info_table(
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
  __int64 v10; // x20
  __int64 result; // x0

  v10 = a1 + 49152;
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: deinitializing the client info table",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_hdd_deinit_multi_client_info_table");
  if ( *(_BYTE *)(v10 + 2960) == 1 )
  {
    *(_WORD *)(v10 + 2962) = 0;
    *(_BYTE *)(v10 + 2964) = 0;
    *(_QWORD *)(a1 + 52104) = 0;
    *(_BYTE *)(a1 + 52112) = 0;
  }
  if ( *(_BYTE *)(v10 + 2976) == 1 )
  {
    *(_BYTE *)(v10 + 2976) = 0;
    *(_QWORD *)(v10 + 2968) = 1;
    *(_WORD *)(v10 + 2978) = 0;
    *(_BYTE *)(v10 + 2980) = 0;
  }
  if ( *(_BYTE *)(v10 + 2992) == 1 )
  {
    *(_BYTE *)(v10 + 2992) = 0;
    *(_QWORD *)(v10 + 2984) = 2;
    *(_WORD *)(v10 + 2994) = 0;
    *(_BYTE *)(v10 + 2996) = 0;
  }
  if ( *(_BYTE *)(v10 + 3008) == 1 )
  {
    *(_BYTE *)(v10 + 3008) = 0;
    *(_QWORD *)(v10 + 3000) = 3;
    *(_WORD *)(v10 + 3010) = 0;
    *(_BYTE *)(v10 + 3012) = 0;
  }
  if ( *(_BYTE *)(v10 + 3024) == 1 )
  {
    *(_BYTE *)(v10 + 3024) = 0;
    *(_QWORD *)(v10 + 3016) = 4;
    *(_WORD *)(v10 + 3026) = 0;
    *(_BYTE *)(v10 + 3028) = 0;
  }
  return result;
}
