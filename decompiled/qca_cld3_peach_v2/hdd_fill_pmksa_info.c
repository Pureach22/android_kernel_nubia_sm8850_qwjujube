__int64 __fastcall hdd_fill_pmksa_info(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *v11; // x8
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  int v18; // w8
  const char *v19; // x4
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x7
  int v29; // w10
  const char *v30; // x4
  __int64 v31; // x5
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w4
  char v41; // w5
  __int64 result; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4

  v11 = *(unsigned __int8 **)a2;
  if ( *(_QWORD *)a2 )
  {
    v15 = *v11;
    v16 = v11[1];
    v17 = v11[2];
    v18 = v11[5];
    if ( (a3 & 1) != 0 )
      v19 = "Delete";
    else
      v19 = "Set";
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: %s PMKSA for %02x:%02x:%02x:**:**:%02x",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hdd_fill_pmksa_info",
      v19,
      v15,
      v16,
      v17,
      v18);
    qdf_mem_copy((void *)a1, *(const void **)a2, 6u);
  }
  else
  {
    qdf_mem_copy((void *)(a1 + 88), *(const void **)(a2 + 32), *(unsigned int *)(a2 + 40));
    qdf_mem_copy((void *)(a1 + 120), *(const void **)(a2 + 48), 2u);
    v28 = *(unsigned __int8 *)(a1 + 120);
    v29 = *(unsigned __int8 *)(a1 + 121);
    if ( (a3 & 1) != 0 )
      v30 = "Delete";
    else
      v30 = "Set";
    v31 = (unsigned __int8)*(_QWORD *)(a2 + 40);
    *(_BYTE *)(a1 + 87) = *(_QWORD *)(a2 + 40);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: %s PMKSA for ssid %.*s cache_id %x %x",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_fill_pmksa_info",
      v30,
      v31,
      a1 + 88,
      v28,
      v29);
  }
  qdf_mem_copy((void *)(a1 + 6), *(const void **)(a2 + 8), 0x10u);
  if ( *(_DWORD *)(a2 + 56) >= 0xA8C0u )
    v40 = 43200;
  else
    v40 = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(a1 + 124) = v40;
  if ( *(unsigned __int8 *)(a2 + 60) >= 0x63u )
    v41 = 99;
  else
    v41 = *(_BYTE *)(a2 + 60);
  *(_BYTE *)(a1 + 128) = v41;
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: PMKSA: lifetime:%d threshold:%d",
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             "hdd_fill_pmksa_lifetime");
  if ( (a3 & 1) == 0 )
  {
    v51 = *(_QWORD *)(a2 + 24);
    if ( (unsigned __int64)(v51 - 1) > 0x3F )
    {
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: Invalid pmk len is %zu",
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               "hdd_fill_pmksa_info");
    }
    else
    {
      result = (__int64)qdf_mem_copy((void *)(a1 + 22), *(const void **)(a2 + 16), (unsigned int)v51);
      *(_BYTE *)(a1 + 86) = *(_QWORD *)(a2 + 24);
    }
  }
  return result;
}
