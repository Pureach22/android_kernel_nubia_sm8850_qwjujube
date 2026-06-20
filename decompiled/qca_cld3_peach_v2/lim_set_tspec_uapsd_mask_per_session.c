__int64 __fastcall lim_set_tspec_uapsd_mask_per_session(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned int a12)
{
  unsigned int v12; // w8
  __int64 v14; // x21
  unsigned int v15; // w19
  int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  int v26; // w8
  char v27; // w10

  v12 = *(unsigned __int16 *)(a11 + 1);
  v14 = a10 + 4096;
  v15 = (v12 >> 5) & 3;
  v16 = (v12 >> 9) & 0x1C;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Set UAPSD mask for AC: %d dir: %d action: %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "lim_set_tspec_uapsd_mask_per_session",
    (0x33220110u >> ((v12 >> 9) & 0x1C)) & 3,
    v15,
    a12);
  v25 = (-857866513 >> v16) & 3;
  if ( a12 != 1 )
  {
    if ( a12 )
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: New pe_session->gUapsdPerAcTriggerEnableMask 0x%x pe_session->gUapsdPerAcDeliveryEnableMask 0x%x",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "lim_set_tspec_uapsd_mask_per_session",
               *(unsigned __int8 *)(v14 + 3178),
               *(unsigned __int8 *)(v14 + 3179));
    if ( v15 != 3 )
    {
      if ( v15 != 1 )
      {
        if ( !v15 )
          *(_BYTE *)(v14 + 3178) &= ~(1 << v25);
        return qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: New pe_session->gUapsdPerAcTriggerEnableMask 0x%x pe_session->gUapsdPerAcDeliveryEnableMask 0x%x",
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 "lim_set_tspec_uapsd_mask_per_session",
                 *(unsigned __int8 *)(v14 + 3178),
                 *(unsigned __int8 *)(v14 + 3179));
      }
      v26 = *(unsigned __int8 *)(v14 + 3179) & ~(1 << v25);
LABEL_16:
      *(_BYTE *)(v14 + 3179) = v26;
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: New pe_session->gUapsdPerAcTriggerEnableMask 0x%x pe_session->gUapsdPerAcDeliveryEnableMask 0x%x",
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               "lim_set_tspec_uapsd_mask_per_session",
               *(unsigned __int8 *)(v14 + 3178),
               *(unsigned __int8 *)(v14 + 3179));
    }
    v26 = 1 << v25;
    v27 = *(_BYTE *)(v14 + 3178) & ~(_BYTE)v26;
    LOBYTE(v26) = *(_BYTE *)(v14 + 3179) & ~(_BYTE)v26;
LABEL_15:
    *(_BYTE *)(v14 + 3178) = v27;
    goto LABEL_16;
  }
  switch ( v15 )
  {
    case 3u:
      v26 = 1 << v25;
      v27 = *(_BYTE *)(v14 + 3178) | v26;
      LOBYTE(v26) = *(_BYTE *)(v14 + 3179) | v26;
      goto LABEL_15;
    case 1u:
      v26 = *(unsigned __int8 *)(v14 + 3179) | (1 << v25);
      goto LABEL_16;
    case 0u:
      *(_BYTE *)(v14 + 3178) |= 1 << v25;
      break;
  }
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: New pe_session->gUapsdPerAcTriggerEnableMask 0x%x pe_session->gUapsdPerAcDeliveryEnableMask 0x%x",
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           "lim_set_tspec_uapsd_mask_per_session",
           *(unsigned __int8 *)(v14 + 3178),
           *(unsigned __int8 *)(v14 + 3179));
}
