__int64 __fastcall sme_set_tspec_uapsd_mask_per_session(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  unsigned int v13; // w8
  unsigned int v15; // w19
  int v16; // w22
  _BYTE *v17; // x21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  char v27; // w9
  char v28; // w10
  char v29; // w9
  char v30; // w9
  char v31; // w9
  char v32; // w8
  char v33; // w10
  char v34; // w9
  char v35; // w10
  char v36; // w9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  if ( a3 >= 7u )
  {
    __break(0x5512u);
    JUMPOUT(0x75CA51C);
  }
  v13 = *(unsigned __int16 *)(a2 + 1);
  v15 = (v13 >> 5) & 3;
  v16 = (v13 >> 9) & 0x1C;
  v17 = (_BYTE *)(a1 + 192LL * a3 + 13120);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Set UAPSD mask for AC: %d dir: %d action: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_set_tspec_uapsd_mask_per_session",
    (0x33220110u >> ((v13 >> 9) & 0x1C)) & 3,
    v15,
    (v13 >> 10) & 1,
    v11,
    v12);
  v26 = 1 << ((-857866513 >> v16) & 3);
  v27 = v17[20];
  if ( (*(_WORD *)(a2 + 1) & 0x400) == 0 )
  {
    v28 = v27 & ~(_BYTE)v26;
    v29 = ~(_BYTE)v26;
    v17[20] = v28;
    if ( v15 != 3 )
    {
      if ( v15 != 1 )
      {
        if ( !v15 )
        {
          v30 = v17[16] & v29;
LABEL_11:
          v17[16] = v30;
          v17[18] |= v26;
          goto LABEL_19;
        }
        goto LABEL_19;
      }
      v31 = v17[17] & v29;
      goto LABEL_14;
    }
    v33 = v17[16] & v29;
    v34 = v17[17] & v29;
    v17[16] = v33;
    v17[17] = v34;
LABEL_17:
    v36 = v17[18] | v26;
    v32 = v17[19] | v26;
    v17[18] = v36;
    goto LABEL_18;
  }
  v17[20] = v27 | v26;
  switch ( v15 )
  {
    case 3u:
      v35 = v17[17] | v26;
      v17[16] |= v26;
      v17[17] = v35;
      goto LABEL_17;
    case 1u:
      v31 = v17[17] | v26;
LABEL_14:
      v17[17] = v31;
      v32 = v17[19] | v26;
LABEL_18:
      v17[19] = v32;
      break;
    case 0u:
      v30 = v17[16] | v26;
      goto LABEL_11;
  }
LABEL_19:
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: New ps_param->uapsd_per_ac_trigger_enable_mask: 0x%x",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "sme_set_tspec_uapsd_mask_per_session",
    (unsigned __int8)v17[16]);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: New  ps_param->uapsd_per_ac_delivery_enable_mask: 0x%x",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "sme_set_tspec_uapsd_mask_per_session",
    (unsigned __int8)v17[17]);
  return qdf_trace_msg(
           0x34u,
           8u,
           "%s: New ps_param->ac_admit_mask[SIR_MAC_DIRECTION_UPLINK]: 0x%x",
           v45,
           v46,
           v47,
           v48,
           v49,
           v50,
           v51,
           v52,
           "sme_set_tspec_uapsd_mask_per_session",
           (unsigned __int8)v17[18]);
}
