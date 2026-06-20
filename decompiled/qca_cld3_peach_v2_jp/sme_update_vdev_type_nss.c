__int64 __fastcall sme_update_vdev_type_nss(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _WORD *v11; // x20
  __int64 v12; // x29
  __int64 v13; // x30
  __int64 v14; // d8
  __int64 v15; // x11
  __int64 v16; // x9
  _BYTE *v17; // x11
  unsigned int v18; // w8
  char v19; // w5
  char v20; // w6
  unsigned int v21; // w8
  unsigned int v22; // w12
  unsigned int v23; // w13
  unsigned int v24; // w14
  unsigned int v25; // w15
  unsigned int v26; // w16
  unsigned int v27; // w17
  unsigned int v28; // w9

  if ( a3 >= 2 )
  {
    __break(0x5512u);
    *v11 = HIWORD(a9);
    v11[1] = HIWORD(a10);
    v11[2] = HIWORD(a11);
    v11[3] = HIWORD(v14);
    return sme_set_he_bss_color();
  }
  else
  {
    v15 = 21512;
    v16 = *(_QWORD *)(a1 + 8) + 4LL * a3;
    if ( a3 == 1 )
      v15 = 21522;
    v17 = (_BYTE *)(a1 + v15);
    v18 = *(_DWORD *)(v16 + 3268) & 7;
    if ( v18 >= a2 )
      v19 = a2;
    else
      v19 = v18;
    *v17 = v19;
    if ( ((*(_DWORD *)(v16 + 3268) >> 3) & 7u) >= a2 )
      v20 = a2;
    else
      v20 = (*(_DWORD *)(v16 + 3268) >> 3) & 7;
    v17[1] = v20;
    v21 = (*(_DWORD *)(v16 + 3268) >> 6) & 7;
    if ( v21 >= a2 )
      v21 = a2;
    v17[2] = v21;
    v22 = (*(_DWORD *)(v16 + 3268) >> 9) & 7;
    if ( v22 > a2 )
      LOBYTE(v22) = a2;
    v17[3] = v22;
    v23 = (*(_DWORD *)(v16 + 3268) >> 18) & 7;
    if ( v23 > a2 )
      LOBYTE(v23) = a2;
    v17[4] = v23;
    v24 = (*(_DWORD *)(v16 + 3268) >> 15) & 7;
    if ( v24 > a2 )
      LOBYTE(v24) = a2;
    v17[5] = v24;
    v25 = (*(_DWORD *)(v16 + 3268) >> 12) & 7;
    if ( v25 > a2 )
      LOBYTE(v25) = a2;
    v17[6] = v25;
    v26 = (*(_DWORD *)(v16 + 3268) >> 21) & 7;
    if ( v26 > a2 )
      LOBYTE(v26) = a2;
    v17[7] = v26;
    v27 = *(_BYTE *)(v16 + 3271) & 7;
    if ( v27 > a2 )
      LOBYTE(v27) = a2;
    v17[8] = v27;
    v28 = *(_BYTE *)(v16 + 3271) & 7;
    if ( v28 > a2 )
      LOBYTE(v28) = a2;
    v17[9] = v28;
    return qdf_trace_msg(
             0x34u,
             8u,
             "%s: band %d NSS:sta %d sap %d cli %d go %d dev %d ibss %d tdls %d ocb %d nan %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "sme_update_vdev_type_nss",
             a3,
             v21,
             (unsigned __int8)v23,
             (unsigned __int8)v24,
             (unsigned __int8)v25,
             (unsigned __int8)v26,
             (unsigned __int8)v27,
             v12,
             v13);
  }
}
