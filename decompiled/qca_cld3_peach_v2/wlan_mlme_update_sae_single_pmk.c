__int64 __fastcall wlan_mlme_update_sae_single_pmk(
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
  __int64 ext_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  int param; // w0
  int v23; // w21
  __int64 result; // x0
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x10
  __int64 v28; // x11
  __int64 v29; // x8
  __int64 v30; // x10
  __int64 v31; // x11
  const char *v32; // x2

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ext_hdl )
  {
    v32 = "%s: vdev legacy private object is NULL";
    return qdf_trace_msg(0x1Fu, 2u, v32, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_mlme_update_sae_single_pmk");
  }
  v21 = ext_hdl;
  param = wlan_crypto_get_param(a1, 7u);
  if ( param < 0 )
  {
    v32 = "%s: Invalid mgmt cipher";
    return qdf_trace_msg(0x1Fu, 2u, v32, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_mlme_update_sae_single_pmk");
  }
  v23 = param & 0x8000400;
  result = qdf_trace_msg(
             0x1Fu,
             8u,
             "%s: SAE_SPMK: single_pmk_ap:%d, is_sae_connection:%d, pmk_len:%d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wlan_mlme_update_sae_single_pmk",
             *(unsigned __int8 *)(v21 + 176),
             (param & 0x8000400) != 0,
             *(unsigned __int8 *)(a2 + 64));
  if ( v23 )
  {
    if ( (*(_BYTE *)(v21 + 176) & 1) != 0 )
    {
      v25 = *(_QWORD *)(a2 + 8);
      *(_QWORD *)(v21 + 184) = *(_QWORD *)a2;
      *(_QWORD *)(v21 + 192) = v25;
      v26 = *(_QWORD *)(a2 + 40);
      v27 = *(_QWORD *)(a2 + 16);
      v28 = *(_QWORD *)(a2 + 24);
      *(_QWORD *)(v21 + 216) = *(_QWORD *)(a2 + 32);
      *(_QWORD *)(v21 + 224) = v26;
      *(_QWORD *)(v21 + 200) = v27;
      *(_QWORD *)(v21 + 208) = v28;
      v29 = *(_QWORD *)(a2 + 72);
      v30 = *(_QWORD *)(a2 + 48);
      v31 = *(_QWORD *)(a2 + 56);
      *(_QWORD *)(v21 + 248) = *(_QWORD *)(a2 + 64);
      *(_QWORD *)(v21 + 256) = v29;
      *(_QWORD *)(v21 + 232) = v30;
      *(_QWORD *)(v21 + 240) = v31;
    }
  }
  return result;
}
