__int64 __fastcall lim_validate_delts_req(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x22
  __int64 hash_entry; // x0
  const char *v17; // x2
  __int64 v18; // x8
  char v19; // w9
  __int16 v20; // w10
  unsigned int v21; // w1
  __int64 result; // x0
  __int64 v23; // x23
  unsigned int v24; // w10
  _QWORD *v25; // x22
  __int64 v26; // x21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x9
  __int64 v44; // x10
  unsigned int v45; // w3
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _QWORD v57[6]; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v58[2]; // [xsp+40h] [xbp-20h]
  unsigned __int8 v59[4]; // [xsp+50h] [xbp-10h] BYREF
  _BYTE v60[4]; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v61; // [xsp+58h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60[0] = 0;
  v59[0] = 0;
  if ( !a2 )
  {
    v17 = "%s: Delete TS request pointer is NULL";
    goto LABEL_19;
  }
  if ( *(_DWORD *)(a4 + 88) == 2 )
  {
    v15 = a2;
    hash_entry = dph_get_hash_entry(a1, 1u, a4 + 360);
    *a3 = *(_BYTE *)(a4 + 24);
    a3[1] = *(_BYTE *)(a4 + 25);
    a3[2] = *(_BYTE *)(a4 + 26);
    a3[3] = *(_BYTE *)(a4 + 27);
    a3[4] = *(_BYTE *)(a4 + 28);
    a3[5] = *(_BYTE *)(a4 + 29);
    if ( !hash_entry )
    {
LABEL_4:
      v17 = "%s: Cannot find station context for delts req";
LABEL_19:
      v21 = 2;
      goto LABEL_20;
    }
  }
  else
  {
    LOWORD(v57[0]) = *(_WORD *)(a2 + 12);
    if ( LOWORD(v57[0]) )
    {
      v15 = a2;
      hash_entry = dph_get_hash_entry(a1, v57[0], a4 + 360);
      if ( !hash_entry )
        goto LABEL_4;
    }
    else
    {
      v15 = a2;
      hash_entry = dph_lookup_hash_entry(
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     a10,
                     a11,
                     a12,
                     a1,
                     (unsigned __int8 *)(a2 + 14),
                     v57,
                     a4 + 360);
      if ( !hash_entry )
        goto LABEL_4;
    }
    *a3 = *(_BYTE *)(hash_entry + 350);
    a3[1] = *(_BYTE *)(hash_entry + 351);
    a3[2] = *(_BYTE *)(hash_entry + 352);
    a3[3] = *(_BYTE *)(hash_entry + 353);
    a3[4] = *(_BYTE *)(hash_entry + 354);
    a3[5] = *(_BYTE *)(hash_entry + 355);
  }
  if ( (*(_WORD *)hash_entry & 1) == 0 || *(_DWORD *)(hash_entry + 8) != 14 )
  {
    v17 = "%s: Invalid Sta (or state) for DelTsReq";
    goto LABEL_19;
  }
  v18 = v15;
  v19 = *(_BYTE *)(v15 + 83) & 0xF8;
  *(_BYTE *)(v15 + 83) = v19;
  v20 = *(_WORD *)hash_entry;
  if ( (*(_WORD *)hash_entry & 0x100) != 0 && (*(_WORD *)(v15 + 28) & 0x180) != 0x80 )
  {
    v23 = hash_entry;
    v24 = 2;
  }
  else if ( (v20 & 0x40) != 0 )
  {
    v23 = hash_entry;
    v24 = 1;
  }
  else
  {
    if ( (v20 & 0x80) == 0 )
    {
      v17 = "%s: DELTS_REQ ignore - qos is disabled";
      v21 = 3;
LABEL_20:
      qdf_trace_msg(0x35u, v21, v17, a5, a6, a7, a8, a9, a10, a11, a12, "lim_validate_delts_req");
LABEL_21:
      result = 16;
      goto LABEL_22;
    }
    v23 = hash_entry;
    v24 = 4;
  }
  v25 = (_QWORD *)(v15 + 21);
  *(_BYTE *)(v18 + 83) = v19 | v24;
  if ( (v24 & 1) != 0 )
    v26 = v18 + 27;
  else
    v26 = v18 + 21;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: received DELTS_REQ message wmeTspecPresent: %d lleTspecPresent: %d wsmTspecPresent: %d tsid: %d  up: %d direction: %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "lim_validate_delts_req",
    v24 & 1,
    v24 >> 2,
    (v24 >> 1) & 1,
    (*(unsigned __int16 *)(v26 + 1) >> 1) & 0xF,
    (*(unsigned __int16 *)(v26 + 1) >> 11) & 7,
    (*(unsigned __int16 *)(v26 + 1) >> 5) & 3);
  if ( (unsigned int)lim_admit_control_delete_ts(
                       a1,
                       *(_WORD *)(v23 + 348),
                       v26,
                       v60,
                       v59,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32,
                       v33,
                       v34) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: DELTS request for sta assocId: %d tsid: %d up: %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "lim_validate_delts_req",
      *(unsigned __int16 *)(v23 + 348),
      (*(unsigned __int16 *)(v26 + 1) >> 1) & 0xF,
      (*(unsigned __int16 *)(v26 + 1) >> 11) & 7);
    goto LABEL_21;
  }
  if ( (*(_WORD *)(v26 + 1) & 0x180) != 0x80 )
  {
    result = 0;
    goto LABEL_22;
  }
  v43 = v25[5];
  v44 = v25[6];
  v45 = *(unsigned __int8 *)(a4 + 8);
  v57[4] = v25[4];
  v57[5] = v43;
  v46 = *(_QWORD *)((char *)v25 + 55);
  v58[0] = v44;
  *(_QWORD *)((char *)v58 + 7) = v46;
  v47 = v25[1];
  v57[0] = *v25;
  v57[1] = v47;
  v48 = v25[3];
  v57[2] = v25[2];
  v57[3] = v48;
  result = lim_send_hal_msg_del_ts(a1, v59[0], v57, v45, (const void *)(a4 + 24));
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: DelTs with UP: %d failed in lim_send_hal_msg_del_ts - ignoring request",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "lim_validate_delts_req",
      (*(unsigned __int16 *)(v26 + 1) >> 11) & 7);
    goto LABEL_21;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
