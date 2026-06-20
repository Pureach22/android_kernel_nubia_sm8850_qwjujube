__int64 __fastcall wlan_ipa_uc_ssr_cleanup(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  int v19; // w8
  unsigned int v20; // w1
  __int64 v21; // x0
  int v22; // w8
  unsigned int v23; // w1
  __int64 result; // x0
  int v25; // w8
  unsigned int v26; // w1

  qdf_trace_msg(0x61u, 4u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ipa_uc_ssr_cleanup");
  v18 = *(_QWORD *)(a1 + 1088);
  if ( v18 )
  {
    v19 = *(_DWORD *)(a1 + 1096);
    if ( v19 == 1 )
    {
      v20 = 3;
    }
    else
    {
      if ( v19 )
      {
LABEL_7:
        wlan_ipa_cleanup_iface((__int64 *)(a1 + 1064), nullptr, v10, v11, v12, v13, v14, v15, v16, v17);
        goto LABEL_8;
      }
      v20 = 5;
    }
    wlan_ipa_uc_send_evt(v18, v20, *(const void **)(v18 + 1008), a1);
    goto LABEL_7;
  }
LABEL_8:
  v21 = *(_QWORD *)(a1 + 1216);
  if ( !v21 )
    goto LABEL_15;
  v22 = *(_DWORD *)(a1 + 1224);
  if ( !v22 )
  {
    v23 = 5;
    goto LABEL_13;
  }
  if ( v22 == 1 )
  {
    v23 = 3;
LABEL_13:
    wlan_ipa_uc_send_evt(v21, v23, *(const void **)(v21 + 1008), a1);
  }
  wlan_ipa_cleanup_iface((__int64 *)(a1 + 1192), nullptr, v10, v11, v12, v13, v14, v15, v16, v17);
LABEL_15:
  result = *(_QWORD *)(a1 + 1344);
  if ( result )
  {
    v25 = *(_DWORD *)(a1 + 1352);
    if ( v25 )
    {
      if ( v25 != 1 )
      {
LABEL_21:
        result = wlan_ipa_cleanup_iface((__int64 *)(a1 + 1320), nullptr, v10, v11, v12, v13, v14, v15, v16, v17);
        goto LABEL_22;
      }
      v26 = 3;
    }
    else
    {
      v26 = 5;
    }
    wlan_ipa_uc_send_evt(result, v26, *(const void **)(result + 1008), a1);
    goto LABEL_21;
  }
LABEL_22:
  *(_BYTE *)(a1 + 7465) = 1;
  return result;
}
