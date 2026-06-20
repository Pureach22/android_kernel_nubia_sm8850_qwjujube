__int64 __fastcall sme_modify_nss_in_mlme_cfg(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        unsigned int a4,
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
  unsigned int v13; // w8
  unsigned int v15; // w20
  int v16; // w8
  __int64 v18; // x21
  unsigned __int8 v19; // w22
  unsigned __int8 v20; // w23
  __int64 v21; // x10
  int v22; // w13
  __int64 v23; // x9
  int v24; // w10

  v13 = *(_DWORD *)(a1 + 4);
  v15 = a2;
  if ( a5 == 1 )
  {
    if ( a2 > HIBYTE(v13) || BYTE2(v13) < (unsigned int)a3 )
      return qdf_trace_msg(
               0x34u,
               8u,
               "%s: Nss modification failed, fw doesn't support this nss %d",
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               "sme_modify_nss_in_mlme_cfg",
               v15);
  }
  else
  {
    if ( a5 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Unknown Band nss change not allowed",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "sme_is_nss_update_allowed");
      return qdf_trace_msg(
               0x34u,
               8u,
               "%s: Nss modification failed, fw doesn't support this nss %d",
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               "sme_modify_nss_in_mlme_cfg",
               v15);
    }
    if ( a2 > (unsigned int)BYTE1(v13) || (unsigned __int8)*(_DWORD *)(a1 + 4) < (unsigned int)a3 )
      return qdf_trace_msg(
               0x34u,
               8u,
               "%s: Nss modification failed, fw doesn't support this nss %d",
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               "sme_modify_nss_in_mlme_cfg",
               v15);
  }
  if ( a4 < 0x11 && ((0x189AFu >> a4) & 1) != 0 )
  {
    v16 = dword_B09170[a4];
  }
  else
  {
    v18 = a1;
    v19 = a2;
    v20 = a3;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Device mode %d invalid",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "sme_get_nss_chain_shift");
    a2 = v19;
    a1 = v18;
    a3 = v20;
    LOBYTE(v16) = 0;
  }
  v21 = 4LL * a5;
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + v21 + 3468) &= ~(7 << v16);
  if ( (a2 & 0xFE) != 0 )
    v22 = 2;
  else
    v22 = a2;
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + v21 + 3468) |= v22 << v16;
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + v21 + 3460) &= ~(7 << v16);
  v23 = *(_QWORD *)(a1 + 8) + v21;
  if ( (a3 & 0xFE) != 0 )
    v24 = 2;
  else
    v24 = a3;
  *(_DWORD *)(v23 + 3460) |= v24 << v16;
  return qdf_trace_msg(
           0x34u,
           8u,
           "%s: rx nss %d tx nss %d changed for vdev mode %d for band %d",
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a13,
           "sme_modify_nss_in_mlme_cfg");
}
