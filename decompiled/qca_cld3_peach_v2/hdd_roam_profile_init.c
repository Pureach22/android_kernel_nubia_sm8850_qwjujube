__int64 __fastcall hdd_roam_profile_init(
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
  __int64 v10; // x10
  __int64 v11; // x22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_roam_profile_init");
  qdf_mem_set(a1 + 11, 0xD8u, 0);
  v10 = *a1;
  a1[12] = (__int64)a1 + 316;
  a1[14] = (__int64)a1 + 308;
  a1[15] = 1024;
  *((_DWORD *)a1 + 22) = 0;
  *((_DWORD *)a1 + 26) = 0;
  *((_BYTE *)a1 + 128) = 0;
  a1[17] = 0;
  *(_DWORD *)(v10 + 41692) = 1;
  v11 = *a1 + 36864;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v12, v13, v14, v15, v16, v17, v18, v19, "hdd_clear_roam_profile_ie");
  *(_BYTE *)(v11 + 2070) = 0;
  *(_BYTE *)(v11 + 2068) = 0;
  qdf_trace_msg(0x33u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "hdd_clear_roam_profile_ie");
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v28, v29, v30, v31, v32, v33, v34, v35, "hdd_roam_profile_init");
}
