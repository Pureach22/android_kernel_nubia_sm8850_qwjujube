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
  unsigned __int64 v28; // x12
  __int64 v29; // x11

  if ( a2 > 5u || !(*(_QWORD *)(a1 + 17296) + 96LL * a2) )
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
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) &= ~0x4000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) &= ~0x8000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) &= ~0x10000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) &= ~0x20000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) &= ~0x40000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) &= ~0x80000000000000uLL;
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) &= ~0x100000000000000uLL;
  v23 = (__int64 *)(v12 + 1369);
  v24 = *(_QWORD *)(v12 + 1369);
  *(_QWORD *)(v12 + 1309) &= 0xFE03FFFFFFFFFFFFLL;
  *(_QWORD *)(v12 + 1369) = v24 & 0xFE03FFFFFFFFFFFFLL;
  if ( a3 > 1 )
  {
    if ( a3 == 2 )
    {
LABEL_8:
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) |= 0x8000000000000uLL;
      *v23 |= 0x8000000000000uLL;
LABEL_12:
      if ( *(_BYTE *)(v12 + 1305) == 1 )
      {
        v28 = *(_QWORD *)(v12 + 1601) & 0xFFFFFFFFFFFFFFF0LL | 1;
        *(_QWORD *)(v12 + 1593) = *(_QWORD *)(v12 + 1593) & 0xFFFFFFFFFFFFFFFLL | 0x1000000000000000LL;
        *(_QWORD *)(v12 + 1601) = v28;
      }
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) |= 0x4000000000000uLL;
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) |= 0x8000000000000uLL;
      v29 = *v23 | 0x8000000000000LL;
      *(_QWORD *)(v12 + 1309) |= 0x4000000000000uLL;
      *v23 = v29;
      return csr_update_session_he_cap(v22);
    }
    if ( a3 == 5 || a3 == 3 )
    {
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) |= 0x8000000000000uLL;
      *(_QWORD *)(*(_QWORD *)(a1 + 8) + 1309LL) |= 0x10000000000000uLL;
      *(_WORD *)(*(_QWORD *)(a1 + 8) + 1332LL) = *(_WORD *)(*(_QWORD *)(a1 + 8) + 1328LL);
      v25 = *(_QWORD *)(a1 + 8);
      *(_WORD *)(v12 + 1392) = *(_WORD *)(v12 + 1388);
      *(_WORD *)(v25 + 1334) = *(_WORD *)(v25 + 1330);
      v26 = *v23;
      *(_WORD *)(v12 + 1394) = *(_WORD *)(v12 + 1390);
      *v23 = v26 | 0x18000000000000LL;
      goto LABEL_8;
    }
    goto LABEL_16;
  }
  if ( a3 )
  {
    if ( a3 == 1 )
      goto LABEL_12;
LABEL_16:
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
  }
  return csr_update_session_he_cap(v22);
}
