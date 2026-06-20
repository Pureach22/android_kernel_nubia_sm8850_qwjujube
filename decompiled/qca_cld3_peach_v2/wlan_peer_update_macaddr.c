__int64 __fastcall wlan_peer_update_macaddr(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x20
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x4
  __int64 v25; // x5
  const char *v26; // x2
  __int64 v27; // x6
  __int64 v28; // x7
  unsigned int v29; // w19
  __int64 result; // x0
  __int64 v31; // x4
  __int64 v32; // x5
  const char *v33; // x2
  unsigned __int8 *v34; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: PEER is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_peer_update_macaddr");
    return 16;
  }
  v10 = *(_QWORD *)(a1 + 96);
  if ( !v10 )
  {
    v31 = *(unsigned __int8 *)(a1 + 48);
    v32 = *(unsigned __int8 *)(a1 + 49);
    v33 = "%s: VDEV is NULL for peer(%02x:%02x:%02x:**:**:%02x)";
    goto LABEL_10;
  }
  v11 = *(_QWORD *)(v10 + 216);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v31 = *(unsigned __int8 *)(a1 + 48);
    v32 = *(unsigned __int8 *)(a1 + 49);
    v33 = "%s: PSOC is NULL for peer(%02x:%02x:%02x:**:**:%02x)";
LABEL_10:
    qdf_trace_msg(
      0x57u,
      2u,
      v33,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_peer_update_macaddr",
      v31,
      v32,
      *(unsigned __int8 *)(a1 + 50),
      *(unsigned __int8 *)(a1 + 53));
    return 16;
  }
  v15 = wlan_objmgr_psoc_peer_detach(*(_QWORD *)(v11 + 80), a1);
  if ( v15 )
  {
    v24 = *(unsigned __int8 *)(a1 + 48);
    v25 = *(unsigned __int8 *)(a1 + 49);
    v26 = "%s: Failed to detach peer(%02x:%02x:%02x:**:**:%02x)";
    v27 = *(unsigned __int8 *)(a1 + 50);
    v28 = *(unsigned __int8 *)(a1 + 53);
    v29 = v15;
  }
  else
  {
    qdf_mem_copy((void *)(a1 + 48), a2, 6u);
    result = wlan_objmgr_psoc_peer_attach(v12, a1);
    if ( !(_DWORD)result )
      return result;
    if ( a2 )
    {
      v34 = (unsigned __int8 *)a2;
      v29 = result;
      v24 = *v34;
      v25 = v34[1];
      v27 = v34[2];
      v28 = v34[5];
    }
    else
    {
      v29 = result;
      v27 = 0;
      v24 = 0;
      v25 = 0;
      v28 = 0;
    }
    v26 = "%s: Failed to attach peer(%02x:%02x:%02x:**:**:%02x)";
  }
  qdf_trace_msg(0x57u, 2u, v26, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_peer_update_macaddr", v24, v25, v27, v28);
  return v29;
}
