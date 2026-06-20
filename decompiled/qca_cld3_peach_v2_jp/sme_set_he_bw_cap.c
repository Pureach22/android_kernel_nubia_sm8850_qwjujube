__int64 __fastcall sme_set_he_bw_cap(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 *v23; // x9
  __int64 v24; // x11
  __int64 v25; // x11
  __int64 v26; // x11
  __int64 v28; // x11

  if ( a2 > 5u || !(*(_QWORD *)(a1 + 17224) + 96LL * a2) )
    return qdf_trace_msg(0x34u, 8u, "%s: No session for id %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_he_bw_cap");
  v12 = a1 + 20480;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Config HE caps for BW %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_set_he_bw_cap",
    (unsigned int)a3);
  v22 = a1;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) &= ~0x4000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) &= ~0x8000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) &= ~0x10000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) &= ~0x20000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) &= ~0x40000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) &= ~0x80000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) &= ~0x100000000000000uLL;
  v23 = (__int64 *)(v12 + 1297);
  v24 = *(_QWORD *)(v12 + 1297);
  *(_QWORD *)(v12 + 1237) &= 0xFE03FFFFFFFFFFFFLL;
  *(_QWORD *)(v12 + 1297) = v24 & 0xFE03FFFFFFFFFFFFLL;
  if ( a3 > 1 )
  {
    if ( a3 == 2 )
    {
LABEL_8:
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) |= 0x8000000000000uLL;
      *v23 |= 0x8000000000000uLL;
LABEL_12:
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) |= 0x4000000000000uLL;
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) |= 0x8000000000000uLL;
      v28 = *v23 | 0x8000000000000LL;
      *(_QWORD *)(v12 + 1237) |= 0x4000000000000uLL;
      *v23 = v28;
      return csr_update_session_he_cap(v22);
    }
    if ( a3 == 5 || a3 == 3 )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) |= 0x8000000000000uLL;
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1289LL) |= 0x10000000000000uLL;
      *(_WORD *)(*(_QWORD *)(a1 + 8) + 1312LL) = *(_WORD *)(*(_QWORD *)(a1 + 8) + 1308LL);
      v25 = *(_QWORD *)(a1 + 8);
      *(_WORD *)(v12 + 1320) = *(_WORD *)(v12 + 1316);
      *(_WORD *)(v25 + 1314) = *(_WORD *)(v25 + 1310);
      v26 = *v23;
      *(_WORD *)(v12 + 1322) = *(_WORD *)(v12 + 1318);
      *v23 = v26 | 0x18000000000000LL;
      goto LABEL_8;
    }
LABEL_14:
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Config BW %d not handled",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "sme_set_he_bw_cap",
      (unsigned int)a3);
    v22 = a1;
    return csr_update_session_he_cap(v22);
  }
  if ( a3 )
  {
    if ( a3 == 1 )
      goto LABEL_12;
    goto LABEL_14;
  }
  return csr_update_session_he_cap(v22);
}
