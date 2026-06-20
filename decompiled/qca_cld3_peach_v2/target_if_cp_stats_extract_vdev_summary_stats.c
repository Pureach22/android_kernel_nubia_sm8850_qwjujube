__int64 __fastcall target_if_cp_stats_extract_vdev_summary_stats(
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
        double a11,
        __int64 a12,
        unsigned int a13)
{
  unsigned int v13; // w5
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  _DWORD *v27; // x22
  char v28; // w0
  char v29; // w23
  __int64 v30; // x26
  unsigned __int64 v31; // x24
  const char *v32; // x25
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w28
  unsigned int v42; // w27
  const char *v43; // x2

  v13 = *(_DWORD *)(a2 + 12);
  if ( !v13 )
    return 0;
  if ( v13 >= 7 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: Unusually high num_vdev_stats: %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_cp_stats_extract_vdev_summary_stats",
      v13);
    return 4;
  }
  if ( 164 * v13 > a13 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: Data buffer too small: %u for %u vdev stats",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "target_if_cp_stats_extract_vdev_summary_stats");
    return 4;
  }
  *(_DWORD *)(a3 + 88) = v13;
  v17 = _qdf_mem_malloc(104LL * *(unsigned int *)(a2 + 12), "target_if_cp_stats_extract_vdev_summary_stats", 782);
  *(_QWORD *)(a3 + 96) = v17;
  if ( !v17 )
  {
    v43 = "%s: malloc failed for vdev_summary_stats";
LABEL_19:
    qdf_trace_msg(
      0x62u,
      2u,
      v43,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_cp_stats_extract_vdev_summary_stats");
    return 2;
  }
  v26 = _qdf_mem_malloc(0xA4u, "target_if_cp_stats_extract_vdev_summary_stats", 788);
  if ( !v26 )
  {
    v43 = "%s: malloc failed for vdev stats";
    goto LABEL_19;
  }
  v27 = (_DWORD *)v26;
  v28 = wmi_service_enabled(a1, 0xACu, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( *(_DWORD *)(a3 + 88) )
  {
    v29 = v28;
    v30 = 0;
    v31 = 0;
    if ( (v28 & 1) != 0 )
      v32 = "%s: vdev %d RSSI bcn: %d data: %d";
    else
      v32 = "%s: vdev %d SNR bcn: %d data: %d";
    do
    {
      if ( !(unsigned int)wmi_extract_vdev_stats(a1) )
      {
        v41 = v27[2];
        v42 = v27[1];
        *(_BYTE *)(*(_QWORD *)(a3 + 96) + v30) = *v27;
        qdf_trace_msg(
          0x62u,
          8u,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "target_if_cp_stats_extract_vdev_summary_stats",
          *(unsigned __int8 *)(*(_QWORD *)(a3 + 96) + v30),
          v42,
          v41);
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 44) = v27[3];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 68) = v27[12];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 28) = v27[8];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 48) = v27[4];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 72) = v27[13];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 32) = v27[9];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 52) = v27[5];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 76) = v27[14];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 36) = v27[10];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 56) = v27[6];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 80) = v27[15];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 40) = v27[11];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 60) = v27[7];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 100) = v27[18];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 96) = v27[19];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 88) = v27[20];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 92) = v27[17];
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 84) = v27[16];
        wlan_util_stats_get_rssi(v29 & 1, v42, v41, (char *)(*(_QWORD *)(a3 + 96) + v30 + 8));
        *(_DWORD *)(*(_QWORD *)(a3 + 96) + v30 + 4) = *(char *)(*(_QWORD *)(a3 + 96) + v30 + 8) + 96;
      }
      ++v31;
      v30 += 104;
    }
    while ( v31 < *(unsigned int *)(a3 + 88) );
  }
  _qdf_mem_free((__int64)v27);
  return 0;
}
