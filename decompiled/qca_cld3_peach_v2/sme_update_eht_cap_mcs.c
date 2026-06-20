void *__fastcall sme_update_eht_cap_mcs(
        _QWORD *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 v12; // x22
  __int64 *v13; // x23
  unsigned __int64 v14; // x8
  unsigned int v15; // w9
  unsigned __int64 v16; // x8
  __int64 v17; // x20
  unsigned int v18; // w21
  unsigned __int64 v20; // x9
  __int64 v21; // x10
  char v22; // w8
  unsigned __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x11

  if ( a2 > 5u )
    return (void *)qdf_trace_msg(
                     0x34u,
                     2u,
                     "%s: No session for id %d",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "sme_update_eht_cap_mcs");
  v11 = a1[2162] + 96LL * a2;
  if ( !v11 )
    return (void *)qdf_trace_msg(
                     0x34u,
                     2u,
                     "%s: No session for id %d",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "sme_update_eht_cap_mcs");
  v12 = a1[1];
  v13 = (__int64 *)(v12 + 1501);
  v14 = *(_QWORD *)(v12 + 1509);
  v15 = (unsigned int)v14 >> 28;
  v16 = v14 >> 60;
  if ( v15 )
    v17 = v15;
  else
    v17 = (unsigned int)v16;
  if ( !(_DWORD)v17 )
    return (void *)qdf_trace_msg(
                     0x34u,
                     2u,
                     "%s: No valid Nss",
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     "sme_update_eht_cap_mcs");
  v18 = a3;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: nss %d, mcs %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_update_eht_cap_mcs",
    (unsigned int)v17,
    a3);
  v20 = *(_QWORD *)(v12 + 1509) & 0xF0000FFFFFFFFFFFLL;
  v21 = *(_QWORD *)(v12 + 1517) & 0xFF0000FF0000FLL;
  v22 = *(_BYTE *)(v12 + 1525) & 0xF0;
  *(_QWORD *)(v12 + 1509) = v20;
  *(_QWORD *)(v12 + 1517) = v21;
  *(_BYTE *)(v12 + 1525) = v22;
  if ( v18 >= 2 )
  {
    v23 = v20 | ((unsigned __int64)((unsigned int)v17 | (16 * (_DWORD)v17)) << 44);
    v24 = v21 | (0x110000110000110LL * v17);
    v25 = *v13 | 0x6000000000000000LL;
    *(_QWORD *)(v12 + 1509) = v23;
    *(_QWORD *)(v12 + 1517) = v24;
    *v13 = v25;
    if ( v18 == 3 )
    {
      *(_BYTE *)(v12 + 1525) = v22 | v17;
      *(_QWORD *)(v12 + 1509) = v23 & 0xF00FFFFFFFFFFFFFLL | (v17 << 52) | (v17 << 56);
      *(_QWORD *)(v12 + 1517) = v24 & 0xFFFF00FFFF00FFFLL
                              | (v17 << 12)
                              | (v17 << 16)
                              | (v17 << 36)
                              | (v17 << 40)
                              | (v17 << 60);
    }
  }
  csr_update_session_eht_cap(a1, v11);
  qdf_mem_copy(a1 + 2758, (const void *)(v12 + 1500), 0x5Cu);
  return qdf_mem_copy((char *)a1 + 22156, (const void *)(v12 + 1500), 0x5Cu);
}
