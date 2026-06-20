__int64 __fastcall sme_update_eht_caps(
        _QWORD *a1,
        unsigned int a2,
        unsigned __int8 a3,
        int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v16; // x21
  __int64 v17; // x23
  unsigned __int64 *v18; // x8
  __int64 v19; // x4
  const char *v20; // x2
  unsigned int v21; // w1
  unsigned __int64 v23; // x9

  if ( (unsigned __int8)a2 > 5u || (v16 = a1[2162] + 96LL * (unsigned __int8)a2) == 0 )
  {
    v20 = "%s: No session for id %d";
    v21 = 2;
LABEL_8:
    qdf_trace_msg(0x34u, v21, v20, a6, a7, a8, a9, a10, a11, a12, a13, "sme_update_eht_caps");
    return 4294967274LL;
  }
  v17 = a1[1];
  v18 = (unsigned __int64 *)(v17 + 1501);
  if ( a4 <= 3 )
  {
    switch ( a4 )
    {
      case 1:
        v19 = 1;
        v23 = *v18 & 0xFFFFFFFFFFBFFFFFLL | ((unsigned __int64)(a3 & 1) << 22);
        break;
      case 2:
        v19 = 2;
        v23 = *v18 & 0xFFFFFFFFF8FFFFFFLL | ((unsigned __int64)(a3 & 7) << 24);
        break;
      case 3:
        v19 = 3;
        v23 = *v18 & 0xFFFFFFFFC7FFFFFFLL | ((unsigned __int64)(a3 & 7) << 27);
        break;
      default:
LABEL_17:
        v20 = "%s: default: Unhandled cap type %d";
        v21 = 8;
        goto LABEL_8;
    }
LABEL_21:
    *v18 = v23;
    goto LABEL_22;
  }
  if ( a4 > 5 )
  {
    if ( a4 == 6 )
    {
      v19 = 6;
      v23 = *v18 & 0xFFFFBFFFFFFFFFFFLL | ((unsigned __int64)(a3 & 1) << 46);
      goto LABEL_21;
    }
    if ( a4 == 7 )
    {
      v19 = 7;
      *(_QWORD *)(v17 + 1509) = *(_QWORD *)(v17 + 1509) & 0xFFFFFFFFFFFFFF83LL | (4 * (a3 & 0x1Fu));
      goto LABEL_22;
    }
    goto LABEL_17;
  }
  if ( a4 == 4 )
  {
    v19 = 4;
    v23 = *v18 & 0xFFFFFFFE3FFFFFFFLL | ((unsigned __int64)(a3 & 7) << 30);
    goto LABEL_21;
  }
  v19 = 5;
  *(_QWORD *)(v17 + 1509) = *(_QWORD *)(v17 + 1509) & 0xFFFFFFFFFFF7FFFFLL | ((unsigned __int64)(a3 & 1) << 19);
LABEL_22:
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: EHT cap: cap type %d, cfg val %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "sme_update_eht_caps",
    v19,
    a3);
  csr_update_session_eht_cap(a1, v16);
  qdf_mem_copy(a1 + 2758, (const void *)(v17 + 1500), 0x5Cu);
  qdf_mem_copy((char *)a1 + 22156, (const void *)(v17 + 1500), 0x5Cu);
  if ( !(unsigned int)qdf_mutex_acquire((__int64)(a1 + 1606)) )
  {
    csr_set_vdev_ies_per_band(a1, a2, a5);
    qdf_mutex_release((__int64)(a1 + 1606));
  }
  return 0;
}
