__int64 __fastcall wlan_serialization_find_and_start_timer(
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
  const char *v22; // x2
  __int64 psoc_obj; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  _QWORD *v33; // x21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  __int64 v43; // x22
  unsigned int multiplier; // w20
  __int64 v45; // x0

  if ( !a1 || !a2 )
  {
    v22 = "%s: invalid param";
LABEL_7:
    qdf_trace_msg(0x4Cu, 2u, v22, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_serialization_find_and_start_timer");
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
        "%s: [SCAN-EMULATION]: Not performing timer functions\n",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_serialization_find_and_start_timer");
      return 0;
    }
  }
  psoc_obj = wlan_serialization_get_psoc_obj(a1);
  wlan_serialization_acquire_lock(psoc_obj + 14976);
  v32 = *(unsigned __int8 *)(psoc_obj + 14968);
  if ( !*(_BYTE *)(psoc_obj + 14968) )
  {
LABEL_12:
    wlan_serialization_release_lock(psoc_obj + 14976);
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Failed to start timer for cmd: type[%d] id[%d] high_priority[%d] blocking[%d]",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wlan_serialization_find_and_start_timer",
      *a2,
      a2[1],
      a2[5] & 1,
      (*((unsigned __int8 *)a2 + 20) >> 1) & 1);
    return 16;
  }
  v33 = *(_QWORD **)(psoc_obj + 14960);
  while ( *v33 )
  {
    --v32;
    v33 += 8;
    if ( !v32 )
      goto LABEL_12;
  }
  *v33 = a2;
  if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(*((_QWORD *)a2 + 4), 9u, v24, v25, v26, v27, v28, v29, v30, v31) )
  {
    *v33 = 0;
    wlan_serialization_release_lock(psoc_obj + 14976);
    v22 = "%s: Unbale to get vdev reference";
    goto LABEL_7;
  }
  wlan_serialization_release_lock(psoc_obj + 14976);
  v33[6] = wlan_serialization_timer_handler;
  v33[7] = v33;
  init_timer_key(v33 + 1, _os_timer_shim_3, 0x80000, 0, 0);
  v42 = a2[6];
  v43 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  v45 = _msecs_to_jiffies(v42);
  mod_timer(v33 + 1, v43 + v45 * multiplier);
  return 0;
}
