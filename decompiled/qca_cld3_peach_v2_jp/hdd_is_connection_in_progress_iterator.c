__int64 __fastcall hdd_is_connection_in_progress_iterator(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x23
  _QWORD *context; // x0
  __int64 v14; // x22
  _QWORD *v15; // x21
  __int64 v16; // x6
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char v25; // w8
  char v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w9
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  unsigned __int64 StatusReg; // x8
  __int64 v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  unsigned __int64 v59; // x26
  __int64 v60; // x8
  char v61; // w8
  __int64 result; // x0
  __int64 v63; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v64[2]; // [xsp+10h] [xbp-10h] BYREF

  v64[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)a1;
  v63 = 0;
  v64[0] = 0;
  context = _cds_get_context(51, (__int64)"hdd_is_connection_in_progress_iterator", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
LABEL_46:
    result = 10;
    goto LABEL_57;
  }
  v14 = context[2];
  v15 = context;
  LODWORD(v16) = *(_DWORD *)(v12 + 40);
  if ( (*(_QWORD *)(a1 + 4416) & 1) == 0 && (unsigned int)v16 < 8 && ((0x8Fu >> v16) & 1) != 0 )
    goto LABEL_56;
  if ( (unsigned int)v16 <= 7 && ((1 << v16) & 0x85) != 0 )
  {
    if ( hdd_cm_is_connecting(a1) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %pK(%d) mode %d Connection is in progress",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "hdd_is_connection_in_progress_iterator",
        a1 + 80,
        *(unsigned __int8 *)(a1 + 8),
        *(unsigned int *)(v12 + 40));
      v25 = *(_BYTE *)(a1 + 8);
      *(_DWORD *)(a2 + 4) = 1;
LABEL_53:
      *(_BYTE *)a2 = v25;
      result = 10;
      *(_BYTE *)(a2 + 8) = 1;
      goto LABEL_57;
    }
    LODWORD(v16) = *(_DWORD *)(v12 + 40);
  }
  if ( !(_DWORD)v16 )
  {
    v26 = sme_roaming_in_progress(v14, *(unsigned __int8 *)(a1 + 8));
    v16 = *(unsigned int *)(v12 + 40);
    if ( (v26 & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %pK(%d) mode %d Reassociation in progress",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_is_connection_in_progress_iterator",
        a1 + 80,
        *(unsigned __int8 *)(a1 + 8),
        v16);
      v25 = *(_BYTE *)(a1 + 8);
      v35 = 2;
LABEL_49:
      *(_DWORD *)(a2 + 4) = v35;
      goto LABEL_53;
    }
  }
  if ( (unsigned int)v16 > 7 )
    goto LABEL_54;
  if ( ((1 << v16) & 0x85) != 0 )
  {
    if ( hdd_cm_is_vdev_associated((_DWORD *)a1)
      && (sme_is_sta_key_exchange_in_progress(v14, *(unsigned __int8 *)(a1 + 8)) & 1) != 0 )
    {
      if ( v12 == -1617 )
      {
        v46 = 0;
        v44 = 0;
        v45 = 0;
        v47 = 0;
      }
      else
      {
        v44 = *(unsigned __int8 *)(v12 + 1617);
        v45 = *(unsigned __int8 *)(v12 + 1618);
        v46 = *(unsigned __int8 *)(v12 + 1619);
        v47 = *(unsigned __int8 *)(v12 + 1622);
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: client %02x:%02x:%02x:**:**:%02x is in middle of WPS/EAPOL exchange.",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "hdd_is_connection_in_progress_iterator",
        v44,
        v45,
        v46,
        v47);
      v25 = *(_BYTE *)(a1 + 8);
      v35 = 3;
      goto LABEL_49;
    }
    goto LABEL_54;
  }
  if ( ((1 << v16) & 0xA) == 0 )
  {
LABEL_54:
    if ( (ucfg_nan_is_enable_disable_in_progress(*v15) & 1) != 0 )
    {
      result = 10;
      *(_DWORD *)(a2 + 4) = 6;
      *(_BYTE *)a2 = 4;
      *(_BYTE *)(a2 + 8) = 1;
      goto LABEL_57;
    }
LABEL_56:
    result = 0;
    goto LABEL_57;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v12 + 38872);
  }
  else
  {
    raw_spin_lock_bh(v12 + 38872);
    *(_QWORD *)(v12 + 38880) |= 1uLL;
  }
  hdd_get_front_sta_info_no_lock(v12 + 38848, v64);
  if ( v64[0] )
    hdd_take_sta_info_ref(v12 + 38848, v64[0], 0, 24);
  hdd_get_next_sta_info_no_lock(v12 + 38848);
  if ( v63 )
    hdd_take_sta_info_ref(v12 + 38848, v63, 0, 24);
  v49 = *(_QWORD *)(v12 + 38880);
  if ( (v49 & 1) != 0 )
  {
    *(_QWORD *)(v12 + 38880) = v49 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 38872);
    v58 = v64[0];
    if ( v64[0] )
      goto LABEL_30;
    goto LABEL_51;
  }
  raw_spin_unlock(v12 + 38872);
  v58 = v64[0];
  if ( !v64[0] )
  {
LABEL_51:
    if ( *((_BYTE *)v15 + 1424) == 1 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: AP/GO: vdev %d connection is in progress",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "hdd_is_connection_in_progress_iterator",
        *(unsigned __int8 *)(a1 + 8));
      *(_DWORD *)(a2 + 4) = 5;
      v25 = *(_BYTE *)(a1 + 8);
      goto LABEL_53;
    }
    goto LABEL_54;
  }
LABEL_30:
  v59 = _ReadStatusReg(SP_EL0);
  while ( *(_DWORD *)(v58 + 44) != 2 )
  {
    hdd_put_sta_info_ref(v12 + 38848, v64, 1, 24);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v59 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v59 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v12 + 38872);
    }
    else
    {
      raw_spin_lock_bh(v12 + 38872);
      *(_QWORD *)(v12 + 38880) |= 1uLL;
    }
    v64[0] = v63;
    hdd_get_next_sta_info_no_lock(v12 + 38848);
    if ( v63 )
      hdd_take_sta_info_ref(v12 + 38848, v63, 0, 24);
    v60 = *(_QWORD *)(v12 + 38880);
    if ( (v60 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 38880) = v60 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 38872);
      v58 = v64[0];
      if ( !v64[0] )
        goto LABEL_51;
    }
    else
    {
      raw_spin_unlock(v12 + 38872);
      v58 = v64[0];
      if ( !v64[0] )
        goto LABEL_51;
    }
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: client %02x:%02x:%02x:**:**:%02x of SAP/GO is in middle of WPS/EAPOL exchange",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "hdd_is_connection_in_progress_iterator",
    *(unsigned __int8 *)(v58 + 32),
    *(unsigned __int8 *)(v58 + 33),
    *(unsigned __int8 *)(v58 + 34),
    *(unsigned __int8 *)(v58 + 37));
  v61 = *(_BYTE *)(a1 + 8);
  *(_DWORD *)(a2 + 4) = 4;
  *(_BYTE *)a2 = v61;
  *(_BYTE *)(a2 + 8) = 1;
  hdd_put_sta_info_ref(v12 + 38848, v64, 1, 24);
  if ( !v63 )
    goto LABEL_46;
  hdd_put_sta_info_ref(v12 + 38848, &v63, 1, 24);
  result = 10;
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
