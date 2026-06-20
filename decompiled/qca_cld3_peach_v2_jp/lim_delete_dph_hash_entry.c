__int64 __fastcall lim_delete_dph_hash_entry(__int64 a1, unsigned __int8 *a2, unsigned int a3, __int64 a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x0
  unsigned __int8 *v17; // x23
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  const char *v22; // x2
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  __int64 v33; // x4
  __int64 i; // x24
  char v35; // w8
  _BYTE *v36; // x24
  int v37; // w27
  int v38; // w26
  __int64 v39; // x25
  __int64 v40; // x28
  char *v41; // x25
  __int16 v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // [xsp+0h] [xbp-30h]
  __int64 v52; // [xsp+8h] [xbp-28h] BYREF
  __int64 v53; // [xsp+10h] [xbp-20h]
  __int64 v54; // [xsp+18h] [xbp-18h]
  int v55; // [xsp+20h] [xbp-10h]
  __int16 v56; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+28h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v55 = 0;
  v53 = 0;
  v54 = 0;
  v52 = 0;
  qdf_mem_set(&v52, 0x1Cu, 0);
  HIWORD(v53) = 0;
  lim_deactivate_and_change_per_sta_id_timer(a1, 8, a3);
  if ( !a4 )
  {
    v22 = "%s: NULL session_entry";
LABEL_7:
    result = qdf_trace_msg(0x35u, 2u, v22, v8, v9, v10, v11, v12, v13, v14, v15, "lim_delete_dph_hash_entry");
    goto LABEL_55;
  }
  LOBYTE(v52) = *(_BYTE *)(a4 + 10);
  v16 = dph_lookup_hash_entry(v8, v9, v10, v11, v12, v13, v14, v15, a1, a2, &v56, a4 + 360);
  if ( !v16 )
  {
    v22 = "%s: sta_ds is NULL";
    goto LABEL_7;
  }
  v17 = (unsigned __int8 *)v16;
  if ( a2 )
  {
    v18 = *a2;
    v19 = a2[1];
    v20 = a2[2];
    v21 = a2[5];
  }
  else
  {
    v20 = 0;
    v18 = 0;
    v19 = 0;
    v21 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Deleting DPH Hash entry sta mac %02x:%02x:%02x:**:**:%02x",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "lim_delete_dph_hash_entry",
    v18,
    v19,
    v20,
    v21);
  lim_util_count_sta_del(a1, v17, a4);
  if ( *(_DWORD *)(a4 + 88) == 1 )
  {
    if ( *(_BYTE *)(a4 + 428) )
      lim_decide_ap_protection_on_delete(a1, v17, &v52, a4);
    if ( v17[646] )
    {
      if ( *(_BYTE *)(a4 + 8675) )
      {
        v32 = "%s: reducing the non ECSA num to %d";
        v33 = (unsigned __int8)--*(_BYTE *)(a4 + 8675);
      }
      else
      {
        v32 = "%s: NonECSA sta 0, id %d is ecsa";
        v33 = (unsigned __int16)a3;
      }
      qdf_trace_msg(0x35u, 8u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "lim_delete_dph_hash_entry", v33);
    }
    if ( (*(_WORD *)v17 & 0x10) == 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: (%d) A non-short preamble STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_decide_short_preamble",
        *(unsigned __int8 *)(a4 + 448),
        v17[338],
        v17[339],
        v17[340],
        v17[343]);
      for ( i = 0; i != 384; i += 12 )
      {
        if ( *(_BYTE *)(a4 + i + 452) && !(unsigned int)qdf_mem_cmp((const void *)(a4 + i + 453), v17 + 338, 6u) )
        {
          v35 = *(_BYTE *)(a4 + 448);
          *(_BYTE *)(a4 + i + 452) = 0;
          *(_BYTE *)(a4 + 448) = --v35;
          if ( v35 )
            goto LABEL_27;
          goto LABEL_25;
        }
      }
      if ( *(_BYTE *)(a4 + 448) )
        goto LABEL_27;
LABEL_25:
      qdf_mem_set((void *)(a4 + 448), 0x184u, 0);
      if ( (unsigned int)lim_enable_short_preamble(a1, 1, &v52, a4) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Cannot enable short preamble",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "lim_decide_short_preamble");
    }
LABEL_27:
    if ( (*(_WORD *)v17 & 0x20) != 0 )
      goto LABEL_47;
    v36 = (_BYTE *)(a1 + 4452);
    LODWORD(v51) = v17[343];
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: (%d) A non-short slottime STA is disassociated. Addr is %02x:%02x:%02x:**:**:%02x",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "lim_decide_short_slot",
      *(unsigned __int8 *)(a1 + 4452),
      v17[338],
      v17[339],
      v17[340],
      v51);
    v37 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5388LL);
    if ( *(_DWORD *)(a4 + 88) == 1 )
    {
      v38 = *(unsigned __int8 *)(a4 + 836);
      v39 = 0;
      v36 = (_BYTE *)(a4 + 836);
      while ( !*(_BYTE *)(a4 + v39 + 840) || (unsigned int)qdf_mem_cmp((const void *)(a4 + v39 + 841), v17 + 338, 6u) )
      {
        v39 += 12;
        if ( v39 == 384 )
          goto LABEL_34;
      }
      --v38;
      *(_BYTE *)(a4 + v39 + 840) = 0;
LABEL_34:
      if ( v38 || !v37 )
        goto LABEL_46;
      qdf_mem_set((void *)(a4 + 836), 0x184u, 0);
    }
    else
    {
      v38 = (unsigned __int8)*v36;
      v40 = 32;
      v41 = (char *)(a1 + 4457);
      while ( !*(v41 - 1) || (unsigned int)qdf_mem_cmp(v41, v17 + 338, 6u) )
      {
        --v40;
        v41 += 12;
        if ( !v40 )
          goto LABEL_42;
      }
      --v38;
      *(v41 - 1) = 0;
LABEL_42:
      if ( !v37 )
        goto LABEL_46;
      if ( v38 )
        goto LABEL_46;
      qdf_mem_set((void *)(a1 + 4452), 0x184u, 0);
      if ( *(_DWORD *)(a4 + 88) != 1 )
        goto LABEL_46;
    }
    LOBYTE(v38) = 0;
    BYTE2(v52) = 1;
    v42 = HIWORD(v53) | 4;
    *(_BYTE *)(a4 + 250) = 1;
    HIWORD(v53) = v42;
LABEL_46:
    *v36 = v38;
LABEL_47:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: param bitmap: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "lim_delete_dph_hash_entry",
      HIWORD(v53));
    if ( HIWORD(v53) && !*(_BYTE *)(a1 + 14809) )
    {
      ((void (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(a1, a4);
      lim_send_beacon_params(a1, &v52, a4);
    }
    lim_obss_send_detection_cfg(a1, a4, 0);
    if ( (*(_WORD *)v17 & 0x400) != 0 )
    {
      LODWORD(v51) = v17[343];
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: delete pmf timer assoc-id:%d sta mac %02x:%02x:%02x:**:**:%02x",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_delete_dph_hash_entry",
        *((unsigned __int16 *)v17 + 168),
        v17[338],
        v17[339],
        v17[340],
        v51);
      v24 = tx_timer_delete(v17 + 360);
    }
  }
  if ( (unsigned int)dph_delete_hash_entry(v24, v25, v26, v27, v28, v29, v30, v31, a1, a2, a3, a4 + 360) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: error deleting hash entry",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "lim_delete_dph_hash_entry");
  result = lim_ap_check_6g_compatible_peer(a1, a4);
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
