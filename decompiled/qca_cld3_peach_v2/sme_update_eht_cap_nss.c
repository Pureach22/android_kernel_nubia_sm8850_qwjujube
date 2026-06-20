void *__fastcall sme_update_eht_cap_nss(
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
  __int64 v11; // x4
  __int64 v12; // x19
  __int64 v13; // x20
  const char *v14; // x2
  __int64 v16; // x21
  __int64 *v18; // x22
  unsigned __int64 v19; // x13
  __int64 v20; // x15
  __int64 v21; // x14
  unsigned __int64 v22; // x13
  unsigned __int64 v23; // x12
  unsigned __int64 v24; // x10
  unsigned __int64 v25; // x9
  char v26; // w10

  v11 = a2;
  if ( a2 > 5u || (v12 = a1[2162] + 96LL * a2) == 0 )
  {
    v14 = "%s: No session for id %d";
    return (void *)qdf_trace_msg(0x34u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_eht_cap_nss", v11);
  }
  v13 = a3;
  if ( (unsigned int)a3 - 3 <= 0xFFFFFFFD )
  {
    v11 = a3;
    v14 = "%s: invalid Nss value nss %d";
    return (void *)qdf_trace_msg(0x34u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_eht_cap_nss", v11);
  }
  v16 = a1[1];
  v18 = (__int64 *)(v16 + 1509);
  qdf_trace_msg(0x34u, 8u, "%s: Nss value %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_update_eht_cap_nss", a3);
  v19 = *(_QWORD *)(v16 + 1509) & 0xFFFFF0000FFFFFFFLL
      | ((unsigned __int64)(unsigned __int8)v13 << 28)
      | (v13 << 32)
      | (v13 << 36)
      | (v13 << 40);
  if ( (*(_QWORD *)(v16 + 1509) & 0xF00000000000LL) != 0 )
    v19 = *v18 & 0xFFF000000FFFFFFFLL
        | ((unsigned __int64)(unsigned __int8)v13 << 28) & 0xFFF00FFFFFFFFFFFLL
        | ((v13 << 32) | (v13 << 36) | (v13 << 40)) & 0xFFF00FFFFFFFFFFFLL
        | ((unsigned __int64)(unsigned __int8)v13 << 44)
        | (v13 << 48);
  if ( (v19 & 0xF0000000000000LL) != 0 )
    v19 = v19 & 0xF00FFFFFFFFFFFFFLL | ((unsigned __int64)(unsigned __int8)v13 << 52) | (v13 << 56);
  v20 = *(_QWORD *)(v16 + 1517);
  v21 = (v13 << 60) | v19 & 0xFFFFFFFFFFFFFFFLL;
  v22 = v20 & 0xFFFFFFFFFFFFFFF0LL | v13;
  *v18 = v21;
  if ( (v20 & 0xF0) != 0 )
    v22 = v20 & 0xFFFFFFFFFFFFF000LL | v13 & 0xFFFFFFFFFFFFF003LL | (16 * v13) | (v13 << 8);
  if ( (v22 & 0xF000) != 0 )
    v22 = v22 & 0xFFFFFFFFFFF00FFFLL | ((unsigned __int64)(unsigned __int8)v13 << 12) | (v13 << 16);
  v23 = ((unsigned __int64)(unsigned int)v13 << 28)
      | (v13 << 32)
      | v22 & 0xFFFFFFF0000FFFFFLL
      | (17825792 * v13) & 0xFFFFFFF0033FFFFFLL;
  if ( (v22 & 0xF0000000) == 0 )
    v23 = v22 & 0xFFFFFFFFF00FFFFFLL | (17825792 * v13);
  if ( (v23 & 0xF000000000LL) != 0 )
    v24 = (v13 << 36) | (v13 << 40) | v23 & 0xFFFFF00FF3FFFFFFLL;
  else
    v24 = v23;
  v25 = v24 & 0xFFF00FFFFFFFFFFFLL | (0x1100000000000LL * v13);
  if ( (v24 & 0xF0000000000000LL) != 0 )
    v25 = v24 & 0xF0000FFFFFFFFFFFLL | (0x1100000000000LL * v13) & 0xF0033FFFFFFFFFFFLL | (v13 << 52) | (v13 << 56);
  *(_QWORD *)(v16 + 1517) = v25;
  if ( v25 >> 60 )
  {
    v26 = *(_BYTE *)(v16 + 1525) & 0xF0;
    *(_QWORD *)(v16 + 1517) = v25 & 0xFFFFFFFFFFFFFFFLL | (v13 << 60);
    *(_BYTE *)(v16 + 1525) = v26 | v13;
  }
  csr_update_session_eht_cap(a1, v12);
  qdf_mem_copy(a1 + 2758, (const void *)(v16 + 1500), 0x5Cu);
  return qdf_mem_copy((char *)a1 + 22156, (const void *)(v16 + 1500), 0x5Cu);
}
