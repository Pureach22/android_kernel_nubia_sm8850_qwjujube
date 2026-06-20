// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_63387C(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 v8; // x19
  __int64 v9; // x20
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x23
  _QWORD *v13; // x25
  __int64 v14; // x26
  __int64 v15; // x27
  __int64 v16; // x28
  __int64 v18; // x8
  unsigned int v19; // w4
  _WORD *v20; // x1
  unsigned int v21; // w3
  _WORD *v22; // x2
  __int64 v23; // x0
  __int16 v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x4
  long double v34; // q0
  char v35; // [xsp-118h] [xbp-118h]
  int v36; // [xsp-114h] [xbp-114h]
  _QWORD *v37; // [xsp-110h] [xbp-110h]
  unsigned __int16 v38; // [xsp-104h] [xbp-104h]
  _QWORD *v39[31]; // [xsp-F8h] [xbp-F8h] BYREF

  if ( (v16 & 0x4000000000LL) == 0 )
    return ucfg_tdls_get_current_mode();
LABEL_3:
  v37 = v13;
LABEL_4:
  while ( ++v14 != 16 )
  {
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v15 + v14 * v12), v39) )
    {
      while ( 1 )
      {
        v13 = v39[0];
        if ( !(unsigned int)qdf_mem_cmp(v39[0] + 3, (const void *)(v11 + 350), 6u) )
          goto LABEL_3;
        if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v15 + v14 * v12), v39[0], v39) )
          goto LABEL_4;
      }
    }
  }
  if ( v37 )
  {
    if ( *(_DWORD *)(v11 + 360) == 3 )
    {
      v18 = *(_QWORD *)(v8 + 8);
      v19 = *(unsigned __int16 *)(v11 + 890);
      v20 = (_WORD *)(v11 + 318);
      v21 = *(unsigned __int16 *)(v11 + 888);
      v22 = (_WORD *)(v11 + 320);
      v23 = v8;
    }
    else
    {
      if ( (*((_BYTE *)&qword_1F0 + (_QWORD)v37) & 8) == 0 )
      {
        *(_DWORD *)(v11 + 318) = -1;
        goto LABEL_29;
      }
      v18 = *(_QWORD *)(v8 + 8);
      v20 = (_WORD *)(v11 + 318);
      v22 = (_WORD *)(v11 + 320);
      v23 = v8;
      v21 = 65530;
      v19 = 65530;
    }
    lim_populate_he_mcs_per_bw(
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      v23,
      v20,
      v22,
      v21,
      v19,
      v35,
      *(unsigned __int16 *)(v18 + 1332),
      *(unsigned __int16 *)(v18 + 1334));
LABEL_29:
    if ( *(_DWORD *)(v11 + 360) == 4 )
      lim_populate_he_mcs_per_bw(
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        v8,
        (_WORD *)(v11 + 322),
        (_WORD *)(v11 + 324),
        *(unsigned __int16 *)(v11 + 892),
        *(unsigned __int16 *)(v11 + 894),
        v35,
        *(unsigned __int16 *)(*(_QWORD *)(v8 + 8) + 1336LL),
        *(unsigned __int16 *)(*(_QWORD *)(v8 + 8) + 1338LL));
    else
      *(_DWORD *)(v11 + 322) = -1;
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: failed to ger tdls peer object",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "lim_tdls_fill_he_wideband_offchannel_mcs");
LABEL_12:
  if ( v36 == 2 && (_DWORD)v16 )
    *(_WORD *)v11 |= 4u;
  if ( *(_BYTE *)(v11 + 864) )
    lim_check_and_force_he_ldpc_cap(v10, v11 + 864);
  v24 = *(_WORD *)(v9 + 26);
  *(_BYTE *)(v11 + 356) = 4;
  *(_WORD *)(v11 + 22) = v24;
  if ( (unsigned int)lim_add_sta(v8, (unsigned __int16 *)v11, *(_DWORD *)(v9 + 16) == 2, v10) )
  {
    if ( v38 > 0x1Fu )
    {
      if ( v38 <= 0x3Fu )
        *(_DWORD *)(v10 + 7256) &= ~(1 << v38);
    }
    else
    {
      *(_DWORD *)(v10 + 7252) &= ~(1 << v38);
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev:%d Add TDLS Station request failed",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_process_sme_tdls_add_sta_req",
      *(unsigned __int8 *)(v10 + 10));
    lim_send_sme_tdls_add_sta_rsp(v8, *(unsigned __int8 *)(v9 + 4), v9 + 20, *(_DWORD *)(v9 + 16) == 2, v33, 16, v34);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
