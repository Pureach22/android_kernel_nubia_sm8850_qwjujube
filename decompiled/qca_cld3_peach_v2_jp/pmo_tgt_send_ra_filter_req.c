__int64 __fastcall pmo_tgt_send_ra_filter_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x21
  __int64 comp_private_obj; // x0
  unsigned int v12; // w23
  __int64 v13; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v15; // x8
  unsigned int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD *context; // x0
  __int64 v34; // x24
  _QWORD *v35; // x23
  bool v36; // zf
  char v37; // w8
  unsigned __int64 v38; // x8
  __int64 v39; // x8
  unsigned int v40; // w24
  __int64 v41; // x0
  unsigned __int64 v42; // x8
  __int64 v43; // x8
  __int64 v44; // x9
  _DWORD *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w20
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x21
  char v64; // w8
  unsigned __int64 v65; // x8
  __int64 v66; // x8
  __int64 v67; // x0
  unsigned __int64 v68; // x8
  __int64 v69; // x8
  __int64 v70; // x9

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_tgt_send_ra_filter_req");
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL);
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v12 = *(unsigned __int8 *)(a1 + 104);
  v13 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1056);
    v15 = *(_QWORD *)(v13 + 1064);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 1056);
    v15 = *(_QWORD *)(v13 + 1064) | 1LL;
    *(_QWORD *)(v13 + 1064) = v15;
  }
  v16 = *(unsigned __int16 *)(*(_QWORD *)v13 + 18LL);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 1064) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 1056);
  }
  else
  {
    raw_spin_unlock(v13 + 1056);
  }
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: send RA rate limit [%d] to fw vdev = %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "pmo_tgt_send_ra_filter_req",
    v16,
    v12);
  context = _cds_get_context(
              51,
              (__int64)"pmo_get_and_increment_wow_default_ptrn",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32);
  v34 = *(_QWORD *)v13;
  v35 = context;
  v36 = *(_BYTE *)(*(_QWORD *)v13 + 955LL) == 1;
  v37 = _ReadStatusReg(DAIF);
  if ( v36 )
  {
    if ( v37 < 0
      || (v38 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v38 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v38 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v13 + 1056);
      v39 = *(_QWORD *)(v13 + 1064);
    }
    else
    {
      raw_spin_lock_bh(v13 + 1056);
      v39 = *(_QWORD *)(v13 + 1064) | 1LL;
      *(_QWORD *)(v13 + 1064) = v39;
    }
    v40 = *(unsigned __int8 *)(v13 + 1030);
    *(_BYTE *)(v13 + 1030) = v40 + 1;
    if ( (v39 & 1) == 0 )
    {
      v41 = v13 + 1056;
LABEL_21:
      raw_spin_unlock(v41);
      goto LABEL_22;
    }
    *(_QWORD *)(v13 + 1064) = v39 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 1056);
  }
  else
  {
    if ( v37 < 0
      || (v42 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v42 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v42 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v34 + 1040);
    }
    else
    {
      raw_spin_lock_bh(v34 + 1040);
      *(_QWORD *)(v34 + 1048) |= 1uLL;
    }
    v40 = *(unsigned __int8 *)(*(_QWORD *)v13 + 944LL);
    *(_BYTE *)(*(_QWORD *)v13 + 944LL) = v40 + 1;
    v43 = *(_QWORD *)v13;
    v44 = *(_QWORD *)(*(_QWORD *)v13 + 1048LL);
    if ( (v44 & 1) == 0 )
    {
      v41 = v43 + 1040;
      goto LABEL_21;
    }
    *(_QWORD *)(v43 + 1048) = v44 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v43 + 1040);
  }
LABEL_22:
  ucfg_pmo_get_num_wow_filters(*v35);
  v45 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(v10, 4u) + 248);
  if ( v45 )
  {
    if ( *(v45 - 1) != -1687241691 )
      __break(0x8228u);
    v54 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v45)(a1, v40, v16);
    if ( v54 )
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Failed to send RA rate limit to fw",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "pmo_tgt_send_ra_filter_req");
      v63 = *(_QWORD *)v13;
      v36 = *(_BYTE *)(*(_QWORD *)v13 + 955LL) == 1;
      v64 = _ReadStatusReg(DAIF);
      if ( v36 )
      {
        if ( v64 < 0
          || (v65 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v65 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v65 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v13 + 1056);
          v66 = *(_QWORD *)(v13 + 1064);
        }
        else
        {
          raw_spin_lock_bh(v13 + 1056);
          v66 = *(_QWORD *)(v13 + 1064) | 1LL;
          *(_QWORD *)(v13 + 1064) = v66;
        }
        --*(_BYTE *)(v13 + 1030);
        if ( (v66 & 1) != 0 )
        {
          *(_QWORD *)(v13 + 1064) = v66 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v13 + 1056);
          goto LABEL_42;
        }
        v67 = v13 + 1056;
      }
      else
      {
        if ( v64 < 0
          || (v68 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v68 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v68 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v63 + 1040);
        }
        else
        {
          raw_spin_lock_bh(v63 + 1040);
          *(_QWORD *)(v63 + 1048) |= 1uLL;
        }
        --*(_BYTE *)(*(_QWORD *)v13 + 944LL);
        v69 = *(_QWORD *)v13;
        v70 = *(_QWORD *)(*(_QWORD *)v13 + 1048LL);
        if ( (v70 & 1) != 0 )
        {
          *(_QWORD *)(v69 + 1048) = v70 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v69 + 1040);
          goto LABEL_42;
        }
        v67 = v69 + 1040;
      }
      raw_spin_unlock(v67);
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_ra_filter_cmd is null",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "pmo_tgt_send_ra_filter_req");
    v54 = 4;
  }
LABEL_42:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v55, v56, v57, v58, v59, v60, v61, v62, "pmo_tgt_send_ra_filter_req");
  return v54;
}
