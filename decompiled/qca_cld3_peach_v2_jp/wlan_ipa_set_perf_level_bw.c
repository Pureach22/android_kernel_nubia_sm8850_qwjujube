__int64 __fastcall wlan_ipa_set_perf_level_bw(
        __int64 result,
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
  __int64 v10; // x8
  char v11; // w9
  __int64 v13; // x20
  __int64 v14; // x4
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x10
  __int64 *v24; // x8
  __int64 v25; // x11
  _DWORD *v26; // x11
  __int64 v27; // x2
  unsigned int v28; // w19
  __int64 v29; // x8
  __int64 v30; // x8
  _DWORD *v31; // x8
  __int64 v32; // x20
  const char *v33; // x2

  v10 = *(_QWORD *)(result + 1464);
  if ( !v10 || (*(_DWORD *)v10 & 0x11) != 1 || *(_BYTE *)(v10 + 36) != 1 )
    return result;
  v11 = *(_BYTE *)(result + 6984);
  *(_BYTE *)(result + 7448) = a2;
  if ( (v11 & 1) != 0 )
  {
    v13 = result;
    result = qdf_trace_msg(
               0x61u,
               8u,
               "%s: Set perf level to %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_ipa_set_perf_level_bw",
               a2);
    v23 = 32;
    v24 = *(__int64 **)(v13 + 1456);
    if ( a2 == 1 )
      v23 = 28;
    if ( a2 == 2 )
      v23 = 24;
    if ( v24 && *v24 && (v25 = *(_QWORD *)(*v24 + 152)) != 0 )
    {
      v26 = *(_DWORD **)(v25 + 168);
      v27 = *(unsigned int *)(v13 + 7460);
      v28 = *(_DWORD *)(*(_QWORD *)(v13 + 1464) + v23);
      if ( !v26 )
        goto LABEL_18;
      if ( *(v26 - 1) != 1328438065 )
        __break(0x822Bu);
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v26)(11, v28, v27);
      v14 = (unsigned int)result;
      if ( !(_DWORD)result )
      {
        v24 = *(__int64 **)(v13 + 1456);
        if ( !v24 )
          goto LABEL_31;
        v27 = *(unsigned int *)(v13 + 7460);
LABEL_18:
        v29 = *v24;
        if ( v29 )
        {
          v30 = *(_QWORD *)(v29 + 152);
          if ( v30 )
          {
            v31 = *(_DWORD **)(v30 + 168);
            if ( !v31 )
              return result;
            if ( *(v31 - 1) != 1328438065 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v31)(10, v28, v27);
            v14 = (unsigned int)result;
            if ( !(_DWORD)result )
              return result;
            goto LABEL_32;
          }
        }
LABEL_31:
        qdf_trace_msg(
          0x45u,
          1u,
          "%s invalid instance",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "cdp_ipa_set_perf_level",
          v14);
        v14 = 16;
LABEL_32:
        v33 = "%s: PROD set perf profile failed: %d";
        return qdf_trace_msg(0x61u, 2u, v33, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_ipa_set_perf_level_bw", v14);
      }
    }
    else
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v15, v16, v17, v18, v19, v20, v21, v22, "cdp_ipa_set_perf_level");
      v14 = 16;
    }
    v33 = "%s: CONS set perf profile failed: %d";
    return qdf_trace_msg(0x61u, 2u, v33, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_ipa_set_perf_level_bw", v14);
  }
  v32 = jiffies;
  if ( wlan_ipa_set_perf_level_bw___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x61u,
               4u,
               "%s: current bw level %u",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_ipa_set_perf_level_bw",
               (unsigned __int8)a2);
    wlan_ipa_set_perf_level_bw___last_ticks = v32;
  }
  return result;
}
