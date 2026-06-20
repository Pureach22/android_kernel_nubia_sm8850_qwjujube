__int64 __fastcall sme_update_he_capabilities(
        _QWORD *a1,
        unsigned __int8 a2,
        char a3,
        char a4,
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
  _QWORD *v13; // x21
  unsigned __int64 *v14; // x22
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x10
  _QWORD *v17; // x20
  unsigned __int64 v18; // x13
  const char *v19; // x2
  unsigned int v20; // w1
  unsigned __int8 v22; // w8
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x11
  __int64 v25; // x12
  unsigned __int64 v26; // x11

  if ( a2 > 5u || !(a1[2162] + 96LL * a2) )
  {
    v19 = "%s: No session for id %d";
    v20 = 2;
LABEL_9:
    qdf_trace_msg(0x34u, v20, v19, a5, a6, a7, a8, a9, a10, a11, a12, "sme_update_he_capabilities");
    return 4294967274LL;
  }
  v12 = a1[1];
  v13 = a1 + 2560;
  v14 = (unsigned __int64 *)(v12 + 1309);
  if ( a4 == 49 )
  {
    v17 = a1;
    if ( a3 )
    {
      v22 = *(_DWORD *)(cfg_psoc_get_values(a1[2703]) + 7644) & 0xF;
      v23 = *v14 & 0xE1FFFFFFFFFFFFFFLL | ((unsigned __int64)v22 << 57);
      *(unsigned __int64 *)((char *)v14 + 60) = *(unsigned __int64 *)((char *)v14 + 60) & 0xE1FFFFFFFFFFFFFFLL
                                              | ((unsigned __int64)v22 << 57);
      *v14 = v23;
      *(_QWORD *)((char *)v13 + 1309) = *(_QWORD *)((char *)v13 + 1309) & 0xE1FFFFFFFFFFFFFFLL
                                      | ((unsigned __int64)(v22 & 0xF) << 57);
      *(_QWORD *)((char *)v13 + 1369) = *(_QWORD *)((char *)v13 + 1369) & 0xE1FFFFFFFFFFFFFFLL
                                      | (((*(unsigned __int64 *)((char *)v14 + 60) >> 57) & 0xF) << 57);
    }
    else
    {
      *v14 &= 0xE1FFFFFFFFFFFFFFLL;
      v24 = *(_QWORD *)((char *)a1 + 21849) & 0xE1FFFFFFFFFFFFFFLL;
      *(_QWORD *)((char *)a1 + 21789) &= 0xE1FFFFFFFFFFFFFFLL;
      *(_QWORD *)((char *)a1 + 21849) = v24;
    }
    goto LABEL_18;
  }
  if ( a4 == 56 )
  {
    v17 = a1;
    if ( a3 )
      *v14 = *v14 & 0xFFFFFFFF7FFFFFFFLL | (((*(_QWORD *)(v12 + 1369) >> 31) & 1LL) << 31);
    else
      *v14 &= ~0x80000000uLL;
    goto LABEL_18;
  }
  if ( a4 != 57 )
  {
    v19 = "%s: default: Unhandled cfg %d";
    v20 = 8;
    goto LABEL_9;
  }
  if ( a3 )
  {
    v15 = *(_QWORD *)(v12 + 1369);
    v16 = *v14;
    *(_BYTE *)(v12 + 3756) = 0;
    v17 = a1;
    *v14 = v16 & 0xFFFFFFFFFFEFFFFFLL | (((v15 >> 20) & 1) << 20);
    v18 = *(_QWORD *)((char *)a1 + 21849) & 0xFFFFFFFFFFEFFFFFLL
        | (((*(_QWORD *)((char *)a1 + 21969) >> 20) & 1LL) << 20);
    *(_QWORD *)((char *)a1 + 21789) = *(_QWORD *)((char *)a1 + 21789) & 0xFFFFFFFFFFEFFFFFLL
                                    | (((*(_QWORD *)((char *)a1 + 21909) >> 20) & 1LL) << 20);
    *(_QWORD *)((char *)a1 + 21849) = v18;
  }
  else
  {
    v17 = a1;
    *v14 &= ~0x100000uLL;
    v25 = a1[1];
    v26 = *(_QWORD *)((char *)a1 + 21849) & 0xFFFFFFFFFFEFFFFFLL;
    *(_QWORD *)((char *)a1 + 21789) &= ~0x100000uLL;
    *(_QWORD *)((char *)a1 + 21849) = v26;
    *(_BYTE *)(v25 + 3756) = 1;
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
    "sme_update_he_capabilities");
  csr_update_session_he_cap(v17);
  return 0;
}
