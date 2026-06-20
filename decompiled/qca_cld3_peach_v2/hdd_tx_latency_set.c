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
  bool v17; // zf
  char v18; // w23
  _QWORD *context; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v28; // x21
  unsigned __int8 *v29; // x22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  __int64 v39; // x27
  _QWORD *v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  _QWORD *v49; // x21
  __int64 v50; // x8
  _DWORD *v51; // x8
  __int64 v52; // x1
  unsigned int v53; // w0
  unsigned int v54; // w21
  __int64 v55; // x8
  _DWORD *v56; // x8
  __int64 v57; // x1
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x24
  const char *v67; // x4

  result = hdd_set_tsf_auto_report(a1, *a2, 1);
  if ( !(_DWORD)result )
  {
    if ( a1 )
      v17 = a1 == -52840;
    else
      v17 = 1;
    v18 = !v17;
    if ( v17 )
    {
      v54 = 17;
      goto LABEL_49;
    }
    context = _cds_get_context(71, (__int64)"hdd_tx_latency_set_for_link", v5, v6, v7, v8, v9, v10, v11, v12);
    if ( !context )
    {
LABEL_30:
      v54 = 4;
      goto LABEL_49;
    }
    v28 = context;
    v29 = (unsigned __int8 *)(a1 + 52848);
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(_BYTE *)(a1 + 52848),
                         (__int64)"hdd_tx_latency_set_for_link",
                         v20,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27) )
    {
LABEL_16:
      if ( a1 == -58928 )
      {
LABEL_40:
        qdf_mem_copy((void *)(a1 + 71112), a2, 0x18u);
        v54 = 0;
LABEL_50:
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enable %d status %d",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "hdd_tx_latency_set",
          *a2,
          v54);
        return qdf_status_to_os_return(v54);
      }
      v38 = 58936;
      v39 = 6088;
      while ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v39 >> 3)) <= 2 )
      {
        v40 = _cds_get_context(71, (__int64)"hdd_tx_latency_set_for_link", v30, v31, v32, v33, v34, v35, v36, v37);
        if ( !v40 )
          goto LABEL_30;
        v49 = v40;
        if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                              *(_BYTE *)(a1 + v38),
                              (__int64)"hdd_tx_latency_set_for_link",
                              v41,
                              v42,
                              v43,
                              v44,
                              v45,
                              v46,
                              v47,
                              v48) )
        {
          if ( !*v49 || (v50 = *(_QWORD *)(*v49 + 32LL)) == 0 || (v51 = *(_DWORD **)(v50 + 352)) == nullptr )
          {
            v54 = 16;
            goto LABEL_42;
          }
          v52 = *(unsigned __int8 *)(a1 + v38);
          if ( *(v51 - 1) != -716546988 )
            __break(0x8228u);
          v53 = ((__int64 (__fastcall *)(_QWORD *, __int64, unsigned __int8 *))v51)(v49, v52, a2);
          if ( v53 )
          {
            v54 = v53;
LABEL_42:
            v29 = (unsigned __int8 *)(a1 + v38);
            goto LABEL_43;
          }
        }
        v38 += 6088;
        v39 += 6088;
        if ( a1 + v38 == 8 )
          break;
      }
      if ( (v18 & 1) != 0 )
        goto LABEL_40;
      v54 = 0;
LABEL_49:
      hdd_set_tsf_auto_report(a1, (*a2 & 1) == 0, 1);
      goto LABEL_50;
    }
    if ( *v28 && (v55 = *(_QWORD *)(*v28 + 32LL)) != 0 && (v56 = *(_DWORD **)(v55 + 352)) != nullptr )
    {
      v57 = *v29;
      if ( *(v56 - 1) != -716546988 )
        __break(0x8228u);
      v54 = ((__int64 (__fastcall *)(_QWORD *, __int64, unsigned __int8 *))v56)(v28, v57, a2);
      if ( !v54 )
        goto LABEL_16;
    }
    else
    {
      v54 = 16;
    }
LABEL_43:
    v66 = jiffies;
    if ( hdd_tx_latency_set_for_link___last_ticks - jiffies + 125 < 0 )
    {
      if ( *a2 )
        v67 = "enable";
      else
        v67 = "disable";
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to %s for vdev id %d, status %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_tx_latency_set_for_link",
        v67,
        *v29,
        v54);
      hdd_tx_latency_set_for_link___last_ticks = v66;
    }
    goto LABEL_49;
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
