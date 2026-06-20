__int64 __fastcall wlan_serialization_find_and_update_timer(
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
  __int64 psoc_obj; // x19
  __int64 v12; // x8
  __int64 v13; // x21
  __int64 v14; // x9
  unsigned int v15; // w20
  __int64 v16; // x24
  unsigned int multiplier; // w22
  __int64 v18; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

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
      "wlan_serialization_find_and_update_timer");
    return 16;
  }
  psoc_obj = wlan_serialization_get_psoc_obj(a1);
  wlan_serialization_acquire_lock(psoc_obj + 14976);
  v12 = *(unsigned __int8 *)(psoc_obj + 14968);
  if ( !*(_BYTE *)(psoc_obj + 14968) )
  {
LABEL_12:
    wlan_serialization_release_lock(psoc_obj + 14976);
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: Can't find timer for cmd_type %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_serialization_find_and_update_timer",
      *a2);
    return 16;
  }
  v13 = *(_QWORD *)(psoc_obj + 14960) + 8LL;
  while ( 1 )
  {
    v14 = *(_QWORD *)(v13 - 8);
    if ( v14 )
    {
      if ( *(_DWORD *)(v14 + 4) == a2[1] && *(_DWORD *)v14 == *a2 && *(_QWORD *)(v14 + 32) == *((_QWORD *)a2 + 4) )
        break;
    }
    --v12;
    v13 += 64;
    if ( !v12 )
      goto LABEL_12;
  }
  v15 = a2[6];
  v16 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  v18 = _msecs_to_jiffies(v15);
  mod_timer(v13, v16 + v18 * multiplier);
  wlan_serialization_release_lock(psoc_obj + 14976);
  return 0;
}
