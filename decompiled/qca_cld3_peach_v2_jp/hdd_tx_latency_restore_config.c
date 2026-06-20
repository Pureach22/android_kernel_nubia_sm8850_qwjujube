__int64 __fastcall hdd_tx_latency_restore_config(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  __int64 v29; // x21
  __int64 v30; // x8
  _DWORD *v31; // x8
  __int64 v32; // x1
  __int64 v33; // x23
  __int64 v34; // x5
  unsigned int v35; // w19
  const char *v36; // x4

  context = _cds_get_context(71, (__int64)"hdd_tx_latency_restore_config", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v19 = context;
  if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                       *((_BYTE *)a1 + 8),
                       (__int64)"hdd_tx_latency_restore_config",
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18) )
    return 0;
  v29 = *a1;
  if ( !*v19 || (v30 = *(_QWORD *)(*v19 + 32LL)) == 0 || (v31 = *(_DWORD **)(v30 + 352)) == nullptr )
  {
    result = 16;
LABEL_13:
    v33 = jiffies;
    if ( hdd_tx_latency_restore_config___last_ticks - jiffies + 125 < 0 )
    {
      v34 = *((unsigned __int8 *)a1 + 8);
      v35 = result;
      if ( *(_BYTE *)(v29 + 57368) )
        v36 = "enable";
      else
        v36 = "disable";
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to %s for vdev id %d, status %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_tx_latency_restore_config",
        v36,
        v34,
        (unsigned int)result);
      hdd_tx_latency_restore_config___last_ticks = v33;
      return v35;
    }
    return result;
  }
  v32 = *((unsigned __int8 *)a1 + 8);
  if ( *(v31 - 1) != -716546988 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v31)(v19, v32, v29 + 57368);
  if ( (_DWORD)result )
    goto LABEL_13;
  return result;
}
