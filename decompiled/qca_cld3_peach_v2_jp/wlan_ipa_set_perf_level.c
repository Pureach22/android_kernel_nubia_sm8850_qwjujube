__int64 __fastcall wlan_ipa_set_perf_level(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x8
  __int64 v12; // x9
  unsigned int v13; // w19
  __int64 v14; // x4
  __int64 v17; // x4
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 *v26; // x9
  __int64 v27; // x10
  _DWORD *v28; // x10
  __int64 v29; // x2
  __int64 v30; // x8
  unsigned int v31; // w0
  __int64 v32; // x9
  __int64 v33; // x9
  _DWORD *v34; // x9
  unsigned int v35; // w0
  __int64 v36; // x9
  const char *v37; // x2

  v11 = *(_DWORD **)(a1 + 1464);
  if ( (~*v11 & 0x11) != 0 )
    return 0;
  if ( a3 + a2 <= (unsigned __int64)(unsigned int)v11[3] >> 1 )
  {
    v12 = 8;
    if ( a3 + a2 > (unsigned __int64)(unsigned int)v11[4] >> 1 )
      v12 = 7;
  }
  else
  {
    v12 = 6;
  }
  v13 = v11[v12];
  v14 = *(unsigned int *)(a1 + 3700);
  if ( (_DWORD)v14 == v13 )
    return 0;
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: Requesting IPA perf curr: %d, next: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_ipa_set_perf_level",
    v14,
    v13);
  v26 = *(__int64 **)(a1 + 1456);
  if ( v26 && *v26 && (v27 = *(_QWORD *)(*v26 + 152)) != 0 )
  {
    v28 = *(_DWORD **)(v27 + 168);
    v29 = *(unsigned int *)(a1 + 7460);
    v30 = a1;
    if ( !v28 )
      goto LABEL_17;
    if ( *(v28 - 1) != 1328438065 )
      __break(0x822Au);
    v31 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v28)(11, v13, v29);
    v17 = v31;
    if ( !v31 )
    {
      v26 = *(__int64 **)(a1 + 1456);
      if ( !v26 )
        goto LABEL_28;
      v29 = *(unsigned int *)(a1 + 7460);
      v30 = a1;
LABEL_17:
      v32 = *v26;
      if ( v32 )
      {
        v33 = *(_QWORD *)(v32 + 152);
        if ( v33 )
        {
          v34 = *(_DWORD **)(v33 + 168);
          if ( !v34 )
            goto LABEL_23;
          if ( *(v34 - 1) != 1328438065 )
            __break(0x8229u);
          v35 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v34)(10, v13, v29);
          v17 = v35;
          v30 = a1;
          if ( !v35 )
          {
LABEL_23:
            v36 = *(_QWORD *)(v30 + 3592);
            *(_DWORD *)(v30 + 3700) = v13;
            *(_QWORD *)(v30 + 3592) = v36 + 1;
            return 0;
          }
          goto LABEL_29;
        }
      }
LABEL_28:
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "cdp_ipa_set_perf_level",
        v17);
      v17 = 16;
LABEL_29:
      v37 = "%s: RM PROD set perf profile failed: %d";
      goto LABEL_26;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v18, v19, v20, v21, v22, v23, v24, v25, "cdp_ipa_set_perf_level");
    v17 = 16;
  }
  v37 = "%s: RM CONS set perf profile failed: %d";
LABEL_26:
  qdf_trace_msg(0x61u, 2u, v37, v18, v19, v20, v21, v22, v23, v24, v25, "wlan_ipa_set_perf_level", v17);
  return 16;
}
