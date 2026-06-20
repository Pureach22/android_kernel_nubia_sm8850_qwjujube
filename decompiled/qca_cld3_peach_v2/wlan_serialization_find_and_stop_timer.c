__int64 __fastcall wlan_serialization_find_and_stop_timer(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  char is_emulation_platform; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  __int64 psoc_obj; // x20
  __int64 v23; // x8
  __int64 *v24; // x0
  __int64 v25; // x9
  __int64 v26; // x22
  double v27; // d0
  unsigned int v28; // w0
  unsigned int *v29; // x8
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid param",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_serialization_find_and_stop_timer");
    return 16;
  }
  if ( !a2[6] )
  {
    v11 = a1;
    is_emulation_platform = wlan_is_emulation_platform(*(unsigned int *)(a1 + 8));
    a1 = v11;
    if ( (is_emulation_platform & 1) != 0 )
    {
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: [SCAN-EMULATION]: Not performing timer funcs",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_serialization_find_and_stop_timer");
      return 0;
    }
  }
  psoc_obj = wlan_serialization_get_psoc_obj(a1);
  wlan_serialization_acquire_lock(psoc_obj + 14976);
  v23 = *(unsigned __int8 *)(psoc_obj + 14968);
  if ( !*(_BYTE *)(psoc_obj + 14968) )
  {
LABEL_16:
    wlan_serialization_release_lock(psoc_obj + 14976);
    v21 = 16;
LABEL_17:
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Can't find timer for cmd_type %d cmd id %d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "wlan_serialization_find_and_stop_timer",
      *a2,
      a2[1]);
    return v21;
  }
  v24 = *(__int64 **)(psoc_obj + 14960);
  while ( 1 )
  {
    v25 = *v24;
    if ( *v24 )
    {
      if ( *(_DWORD *)(v25 + 4) == a2[1] && *(_DWORD *)v25 == *a2 )
      {
        v26 = *(_QWORD *)(v25 + 32);
        if ( v26 == *((_QWORD *)a2 + 4) )
          break;
      }
    }
    --v23;
    v24 += 8;
    if ( !v23 )
      goto LABEL_16;
  }
  v27 = wlan_serialization_stop_timer();
  v21 = v28;
  wlan_objmgr_vdev_release_ref(v26, 9u, v29, v27, v30, v31, v32, v33, v34, v35, v36);
  wlan_serialization_release_lock(psoc_obj + 14976);
  if ( v21 )
    goto LABEL_17;
  return v21;
}
