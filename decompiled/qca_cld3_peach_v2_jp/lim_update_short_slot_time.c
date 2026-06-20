_WORD *__fastcall lim_update_short_slot_time(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
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
  _WORD *result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _DWORD *v25; // x8
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x25
  __int64 v39; // x26
  char *v40; // x23
  char *v41; // x24
  __int64 v42; // x27
  const void *v43; // x0
  __int64 v44; // x8
  _BYTE *v45; // x23
  _BYTE *v46; // x24
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w9
  __int16 v56; // w8
  __int64 v57; // x5
  int v58; // w8
  __int64 v59; // x6
  __int64 v60; // x7
  int v61; // w9
  __int16 v62; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+18h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  result = (_WORD *)dph_lookup_hash_entry(a5, a6, a7, a8, a9, a10, a11, a12, a1, a2, &v62, a4 + 360);
  v25 = (_DWORD *)(a4 + 7232);
  if ( !a4 )
    v25 = (_DWORD *)(a1 + 4840);
  if ( !result || *v25 != 2 || (*result & 0x20) != 0 )
    goto LABEL_42;
  if ( a2 )
  {
    v26 = *a2;
    v27 = a2[1];
    v28 = a2[2];
    v29 = a2[5];
  }
  else
  {
    v28 = 0;
    v26 = 0;
    v27 = 0;
    v29 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Short Slot Time is not enabled in Assoc Req from %02x:%02x:%02x:**:**:%02x",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "lim_update_short_slot_time",
    v26,
    v27,
    v28,
    v29);
  v38 = a4 + 840;
  v39 = a1 + 4456;
  v40 = (char *)(a4 + 841);
  v41 = (char *)(a1 + 4457);
  v42 = 32;
  do
  {
    if ( *(_DWORD *)(a4 + 88) == 1 )
    {
      if ( !*(v40 - 1) )
        goto LABEL_11;
      v43 = v40;
    }
    else
    {
      if ( !*(v41 - 1) )
        goto LABEL_11;
      v43 = v41;
    }
    result = (_WORD *)qdf_mem_cmp(v43, a2, 6u);
    if ( !(_DWORD)result )
      goto LABEL_42;
LABEL_11:
    --v42;
    v40 += 12;
    v41 += 12;
  }
  while ( v42 );
  v44 = 0;
  while ( 1 )
  {
    while ( *(_DWORD *)(a4 + 88) != 1 )
    {
      if ( !*(_BYTE *)(v39 + 12 * v44) )
      {
        v38 = a1 + 4456;
        v45 = (_BYTE *)(a1 + 4452);
        goto LABEL_28;
      }
      if ( ++v44 == 32 )
      {
        v57 = *(unsigned __int8 *)(a1 + 4452);
        if ( a2 )
        {
LABEL_40:
          v59 = *a2;
          v60 = a2[1];
          v58 = a2[2];
          v61 = a2[5];
          goto LABEL_41;
        }
LABEL_38:
        v58 = 0;
        v59 = 0;
        v60 = 0;
        v61 = 0;
LABEL_41:
        result = (_WORD *)qdf_trace_msg(
                            0x35u,
                            2u,
                            "%s: No space in ShortSlot cache active: %d sta: %d for sta %02x:%02x:%02x:**:**:%02x",
                            v30,
                            v31,
                            v32,
                            v33,
                            v34,
                            v35,
                            v36,
                            v37,
                            "lim_update_short_slot_time",
                            32,
                            v57,
                            v59,
                            v60,
                            v58,
                            v61);
        goto LABEL_42;
      }
    }
    if ( !*(_BYTE *)(v38 + 12 * v44) || !*(_BYTE *)(v39 + 12 * v44) )
      break;
    if ( ++v44 == 32 )
    {
      v57 = *(unsigned __int8 *)(a4 + 836);
      if ( a2 )
        goto LABEL_40;
      goto LABEL_38;
    }
  }
  v45 = (_BYTE *)(a4 + 836);
LABEL_28:
  v46 = (_BYTE *)(v38 + 12LL * (unsigned __int16)v44);
  result = qdf_mem_copy(v46 + 1, a2, 6u);
  *v46 = 1;
  ++*v45;
  v55 = *(_DWORD *)(a4 + 88);
  if ( v55 == 1 && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5388LL) )
  {
    if ( !*(_BYTE *)(a4 + 836) )
      goto LABEL_42;
LABEL_35:
    if ( *(_BYTE *)(a4 + 250) )
    {
      v56 = *(_WORD *)(a3 + 14) | 4;
      *(_BYTE *)(a3 + 2) = 0;
      *(_WORD *)(a3 + 14) = v56;
      result = (_WORD *)qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: Disable short slot time. Enable long slot time",
                          v47,
                          v48,
                          v49,
                          v50,
                          v51,
                          v52,
                          v53,
                          v54,
                          "lim_update_short_slot_time");
      *(_BYTE *)(a4 + 250) = 0;
    }
  }
  else if ( v55 != 1 && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5388LL) && *(_BYTE *)(a1 + 4452) )
  {
    goto LABEL_35;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
