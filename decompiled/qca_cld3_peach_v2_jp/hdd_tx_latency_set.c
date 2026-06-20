__int64 __fastcall hdd_tx_latency_set(__int64 a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  int v14; // w8
  unsigned int v15; // w19
  const char *v16; // x4
  __int64 v17; // x9
  bool v18; // zf
  char v19; // w24
  unsigned __int8 *v20; // x23
  _QWORD *context; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  _QWORD *v30; // x21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  _DWORD *v40; // x8
  __int64 v41; // x1
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w21
  __int64 v52; // x24
  const char *v53; // x4

  result = hdd_set_tsf_auto_report(a1, *a2, 1);
  if ( !(_DWORD)result )
  {
    if ( a1 )
      v17 = a1 + 52832;
    else
      v17 = 0;
    if ( v17 )
      v18 = v17 == a1 + 52832;
    else
      v18 = 0;
    v19 = v18;
    if ( !v18 )
    {
      v51 = 17;
      goto LABEL_37;
    }
    v20 = (unsigned __int8 *)(a1 + 52840);
    context = _cds_get_context(71, (__int64)"hdd_tx_latency_set_for_link", v5, v6, v7, v8, v9, v10, v11, v12);
    if ( !context )
    {
      v51 = 4;
      goto LABEL_37;
    }
    v30 = context;
    if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                          *v20,
                          (__int64)"hdd_tx_latency_set_for_link",
                          v22,
                          v23,
                          v24,
                          v25,
                          v26,
                          v27,
                          v28,
                          v29) )
    {
      if ( *v30 && (v39 = *(_QWORD *)(*v30 + 32LL)) != 0 && (v40 = *(_DWORD **)(v39 + 352)) != nullptr )
      {
        v41 = *v20;
        if ( *(v40 - 1) != -716546988 )
          __break(0x8228u);
        v42 = ((__int64 (__fastcall *)(_QWORD *, __int64, unsigned __int8 *))v40)(v30, v41, a2);
        if ( !v42 )
          goto LABEL_26;
        v51 = v42;
      }
      else
      {
        v51 = 16;
      }
      v52 = jiffies;
      if ( hdd_tx_latency_set_for_link___last_ticks - jiffies + 125 < 0 )
      {
        if ( *a2 )
          v53 = "enable";
        else
          v53 = "disable";
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: failed to %s for vdev id %d, status %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "hdd_tx_latency_set_for_link",
          v53,
          *v20,
          v51);
        hdd_tx_latency_set_for_link___last_ticks = v52;
      }
      goto LABEL_37;
    }
LABEL_26:
    if ( (v19 & 1) != 0 )
    {
      qdf_mem_copy((void *)(a1 + 57368), a2, 0x18u);
      v51 = 0;
LABEL_38:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: enable %d status %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "hdd_tx_latency_set",
        *a2,
        v51);
      return qdf_status_to_os_return(v51);
    }
    v51 = 0;
LABEL_37:
    hdd_set_tsf_auto_report(a1, (*a2 & 1) == 0, 1);
    goto LABEL_38;
  }
  v13 = jiffies;
  if ( hdd_tx_latency_set___last_ticks - jiffies + 125 < 0 )
  {
    v14 = *a2;
    v15 = result;
    if ( v14 )
      v16 = "enable";
    else
      v16 = "disable";
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to %s tsf auto report, ret %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_tx_latency_set",
      v16,
      (unsigned int)result);
    hdd_tx_latency_set___last_ticks = v13;
    return v15;
  }
  return result;
}
