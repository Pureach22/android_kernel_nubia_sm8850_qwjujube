__int64 __fastcall wlansap_roam_process_infra_assoc_ind(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  size_t v14; // x2
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x5
  __int64 v24; // x6
  const char *v25; // x2
  __int64 v26; // x7
  int v27; // w8
  unsigned int v28; // w1
  __int64 result; // x0
  int v30; // [xsp+0h] [xbp-10h]

  qdf_trace_msg(
    0x39u,
    8u,
    "%s: CSR roam_result = eCSR_ROAM_RESULT_INFRA_ASSOCIATION_IND (%d)",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlansap_roam_process_infra_assoc_ind",
    10);
  v14 = *(unsigned __int8 *)(a2 + 43);
  *(_DWORD *)(a1 + 1224) = v14;
  if ( (_DWORD)v14 )
    qdf_mem_copy((void *)(a1 + 1228), *(const void **)(a2 + 48), v14);
  if ( (unsigned int)sap_is_peer_mac_allowed(a1, a2 + 23) )
  {
    v23 = *(unsigned __int8 *)(a2 + 23);
    v24 = *(unsigned __int8 *)(a2 + 24);
    v25 = "%s: CSR roam_result = (%d) MAC (%02x:%02x:%02x:**:**:%02x) not allowed";
    v26 = *(unsigned __int8 *)(a2 + 25);
    v27 = *(unsigned __int8 *)(a2 + 28);
    v28 = 3;
  }
  else
  {
    result = sap_signal_hdd_event(a1, a2, 2, 0);
    if ( !(_DWORD)result )
      return result;
    v23 = *(unsigned __int8 *)(a2 + 23);
    v24 = *(unsigned __int8 *)(a2 + 24);
    v25 = "%s: CSR roam_result = (%d) MAC (%02x:%02x:%02x:**:**:%02x) fail";
    v26 = *(unsigned __int8 *)(a2 + 25);
    v27 = *(unsigned __int8 *)(a2 + 28);
    v28 = 2;
  }
  v30 = v27;
  result = qdf_trace_msg(
             0x39u,
             v28,
             v25,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "wlansap_roam_process_infra_assoc_ind",
             10,
             v23,
             v24,
             v26,
             v30);
  *a3 = 16;
  return result;
}
