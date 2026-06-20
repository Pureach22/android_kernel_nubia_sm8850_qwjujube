__int64 __fastcall sme_update_he_capabilities(
        _QWORD *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x4
  _QWORD *v14; // x21
  unsigned __int64 *v15; // x22
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x10
  _QWORD *v18; // x20
  unsigned __int64 v19; // x13
  const char *v20; // x2
  unsigned int v21; // w1
  unsigned __int8 v23; // w23
  __int64 values; // x0
  unsigned __int8 v25; // w8
  unsigned __int64 v26; // x10
  unsigned __int64 v27; // x11
  __int64 v28; // x12
  unsigned __int64 v29; // x11

  if ( a2 > 5u || !(a1[2153] + 96LL * a2) )
  {
    v20 = "%s: No session for id %d";
    v21 = 2;
LABEL_9:
    qdf_trace_msg(0x34u, v21, v20, a5, a6, a7, a8, a9, a10, a11, a12, "sme_update_he_capabilities");
    return 4294967274LL;
  }
  v12 = a1[1];
  v13 = a4;
  v14 = a1 + 2560;
  v15 = (unsigned __int64 *)(v12 + 1289);
  if ( a4 == 49 )
  {
    v18 = a1;
    if ( a3 )
    {
      v23 = a3;
      values = cfg_psoc_get_values(a1[2694]);
      v13 = 49;
      a3 = v23;
      v25 = *(_DWORD *)(values + 7552) & 0xF;
      v26 = *v15 & 0xE1FFFFFFFFFFFFFFLL | ((unsigned __int64)v25 << 57);
      *(unsigned __int64 *)((char *)v15 + 60) = *(unsigned __int64 *)((char *)v15 + 60) & 0xE1FFFFFFFFFFFFFFLL
                                              | ((unsigned __int64)v25 << 57);
      *v15 = v26;
      *(_QWORD *)((char *)v14 + 1237) = *(_QWORD *)((char *)v14 + 1237) & 0xE1FFFFFFFFFFFFFFLL
                                      | ((unsigned __int64)(v25 & 0xF) << 57);
      *(_QWORD *)((char *)v14 + 1297) = *(_QWORD *)((char *)v14 + 1297) & 0xE1FFFFFFFFFFFFFFLL
                                      | (((*(unsigned __int64 *)((char *)v15 + 60) >> 57) & 0xF) << 57);
    }
    else
    {
      *v15 &= 0xE1FFFFFFFFFFFFFFLL;
      v27 = *(_QWORD *)((char *)a1 + 21777) & 0xE1FFFFFFFFFFFFFFLL;
      *(_QWORD *)((char *)a1 + 21717) &= 0xE1FFFFFFFFFFFFFFLL;
      *(_QWORD *)((char *)a1 + 21777) = v27;
    }
    goto LABEL_18;
  }
  if ( a4 == 56 )
  {
    v18 = a1;
    if ( a3 )
      *v15 = *v15 & 0xFFFFFFFF7FFFFFFFLL | (((*(_QWORD *)(v12 + 1349) >> 31) & 1LL) << 31);
    else
      *v15 &= ~0x80000000uLL;
    goto LABEL_18;
  }
  if ( a4 != 57 )
  {
    v20 = "%s: default: Unhandled cfg %d";
    v21 = 8;
    goto LABEL_9;
  }
  if ( a3 )
  {
    v16 = *(_QWORD *)(v12 + 1349);
    v17 = *v15;
    *(_BYTE *)(v12 + 3544) = 0;
    v18 = a1;
    *v15 = v17 & 0xFFFFFFFFFFEFFFFFLL | (((v16 >> 20) & 1) << 20);
    v19 = *(_QWORD *)((char *)a1 + 21777) & 0xFFFFFFFFFFEFFFFFLL
        | (((*(_QWORD *)((char *)a1 + 21897) >> 20) & 1LL) << 20);
    *(_QWORD *)((char *)a1 + 21717) = *(_QWORD *)((char *)a1 + 21717) & 0xFFFFFFFFFFEFFFFFLL
                                    | (((*(_QWORD *)((char *)a1 + 21837) >> 20) & 1LL) << 20);
    *(_QWORD *)((char *)a1 + 21777) = v19;
  }
  else
  {
    v18 = a1;
    *v15 &= ~0x100000uLL;
    v28 = a1[1];
    v29 = *(_QWORD *)((char *)a1 + 21777) & 0xFFFFFFFFFFEFFFFFLL;
    *(_QWORD *)((char *)a1 + 21717) &= ~0x100000uLL;
    *(_QWORD *)((char *)a1 + 21777) = v29;
    *(_BYTE *)(v28 + 3544) = 1;
  }
LABEL_18:
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: HE cap: cfg id %d, cfg val %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "sme_update_he_capabilities",
    v13,
    a3);
  csr_update_session_he_cap(v18);
  return 0;
}
