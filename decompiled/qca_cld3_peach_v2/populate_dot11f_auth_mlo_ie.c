__int64 __fastcall populate_dot11f_auth_mlo_ie(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int16 *a11)
{
  __int16 v13; // w8
  unsigned __int8 *v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int16 v27; // w9
  __int16 v28; // w11
  __int16 v29; // w10
  __int16 v30; // w11

  qdf_trace_msg(0x35u, 8u, "%s: Populate Auth MLO IEs", a1, a2, a3, a4, a5, a6, a7, a8, "populate_dot11f_auth_mlo_ie");
  v13 = *a11;
  *((_BYTE *)a11 + 2) = 1;
  *a11 = v13 & 0xFFF8;
  v14 = *(unsigned __int8 **)(a10 + 16);
  qdf_mem_copy((char *)a11 + 3, v14 + 80, 6u);
  *((_BYTE *)a11 + 2) += 6;
  if ( v14 == (unsigned __int8 *)-80LL )
  {
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v26 = 0;
  }
  else
  {
    v23 = v14[80];
    v24 = v14[81];
    v25 = v14[82];
    v26 = v14[85];
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: MLD mac addr: %02x:%02x:%02x:**:**:%02x",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "populate_dot11f_auth_mlo_ie",
    v23,
    v24,
    v25,
    v26);
  v27 = *a11;
  v28 = *(__int16 *)((char *)a11 + 2093);
  a11[1045] = 255;
  v29 = v27 & 0xF80F;
  v30 = v28 & 0xFFF8 | v27 & 7;
  LOBYTE(v27) = *((_BYTE *)a11 + 2);
  *((_BYTE *)a11 + 2092) = 107;
  *a11 = v29;
  *(__int16 *)((char *)a11 + 2093) = v30;
  *((_BYTE *)a11 + 2095) = v27;
  qdf_mem_copy(a11 + 1048, (char *)a11 + 3, 6u);
  a11[1044] = 12;
  return 0;
}
