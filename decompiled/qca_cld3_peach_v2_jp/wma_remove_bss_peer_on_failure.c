__int64 __fastcall wma_remove_bss_peer_on_failure(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  __int64 v13; // x9
  _QWORD *v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  _DWORD *v41; // x8
  int v42; // [xsp+0h] [xbp-10h] BYREF
  __int16 v43; // [xsp+4h] [xbp-Ch]
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wma_remove_bss_peer_on_failure", a3, a4, a5, a6, a7, a8, a9, a10);
  v43 = 0;
  v13 = a1[65];
  v42 = 0;
  v14 = context;
  result = wlan_vdev_get_bss_peer_mac(
             *(_QWORD *)(v13 + 488LL * (unsigned __int8)a2),
             &v42,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: connect failure for vdev %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wma_remove_bss_peer_on_failure",
      (unsigned __int8)a2);
    if ( v14 && *v14 && (v40 = *(_QWORD *)(*v14 + 72LL)) != 0 )
    {
      v41 = *(_DWORD **)(v40 + 16);
      if ( v41 )
      {
        if ( *(v41 - 1) != 454466150 )
          __break(0x8228u);
        if ( (((__int64 (__fastcall *)(_QWORD *, _QWORD, int *))v41)(v14, 0, &v42) & 1) != 0 )
        {
          result = wma_remove_peer(a1, &v42, a2, 0, v32, v33, v34, v35, v36, v37, v38, v39);
          goto LABEL_12;
        }
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v32, v33, v34, v35, v36, v37, v38, v39, "cdp_find_peer_exist");
    }
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to find peer %02x:%02x:%02x:**:**:%02x",
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               "wma_remove_bss_peer_on_failure",
               (unsigned __int8)v42,
               BYTE1(v42),
               BYTE2(v42),
               HIBYTE(v43));
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
