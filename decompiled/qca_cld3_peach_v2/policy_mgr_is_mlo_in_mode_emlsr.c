__int64 __fastcall policy_mgr_is_mlo_in_mode_emlsr(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  unsigned int mode_specific_conn_info; // w0
  __int64 v17; // x27
  unsigned __int8 v18; // w25
  int v19; // w24
  __int64 v20; // x28
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v58; // [xsp+0h] [xbp-10h] BYREF
  __int64 v59; // [xsp+8h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v58) = 0;
  LODWORD(v58) = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "policy_mgr_is_mlo_in_mode_emlsr",
      v58,
      v59);
    LOBYTE(v19) = 0;
    goto LABEL_27;
  }
  v15 = context;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, 0, &v58, 0);
  if ( mode_specific_conn_info )
  {
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v20 = mode_specific_conn_info;
    while ( 1 )
    {
      if ( v17 == 5 )
        __break(0x5512u);
      v21 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              *((unsigned __int8 *)&v58 + v17),
              24);
      if ( !v21 )
        break;
      v30 = v21;
      if ( (wlan_vdev_mlme_is_mlo_vdev(v21, v22, v23, v24, v25, v26, v27, v28, v29) & 1) != 0 )
      {
        if ( a2 )
          *(_BYTE *)(a2 + v18) = *((_BYTE *)&v58 + v17);
        ++v18;
      }
      v19 |= (*(_DWORD *)(v30 + 48) & 0x400u) >> 10;
      wlan_objmgr_vdev_release_ref(
        v30,
        0x18u,
        (unsigned int *)(*(_DWORD *)(v30 + 48) & 0x400),
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38);
      if ( v20 == ++v17 )
        goto LABEL_13;
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: invalid vdev for id %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "policy_mgr_is_mlo_in_mode_emlsr",
      *((unsigned __int8 *)&v58 + v17),
      v58,
      v59);
    if ( !a3 )
      goto LABEL_27;
LABEL_26:
    *a3 = v18;
    goto LABEL_27;
  }
  v19 = 0;
  v18 = 0;
LABEL_13:
  qdf_mutex_acquire(v15 + 56);
  if ( pm_disabled_ml_links == 1 && !dword_8D4FC4 )
  {
    v39 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            (unsigned __int8)byte_8D4FCC,
            24);
    if ( v39 )
    {
      v19 |= (*(_DWORD *)(v39 + 48) & 0x400u) >> 10;
      wlan_objmgr_vdev_release_ref(
        v39,
        0x18u,
        (unsigned int *)(*(_DWORD *)(v39 + 48) & 0x400),
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: invalid inactive vdev for id %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "policy_mgr_is_mlo_in_mode_emlsr",
        (unsigned __int8)byte_8D4FCC,
        v58,
        v59);
    }
  }
  if ( byte_8D4FD0 == 1 && !dword_8D4FD4 )
  {
    v48 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            (unsigned __int8)byte_8D4FDC,
            24);
    if ( v48 )
    {
      v19 |= (*(_DWORD *)(v48 + 48) & 0x400u) >> 10;
      wlan_objmgr_vdev_release_ref(
        v48,
        0x18u,
        (unsigned int *)(*(_DWORD *)(v48 + 48) & 0x400),
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: invalid inactive vdev for id %d",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "policy_mgr_is_mlo_in_mode_emlsr",
        (unsigned __int8)byte_8D4FDC);
    }
  }
  qdf_mutex_release(v15 + 56);
  if ( a3 )
    goto LABEL_26;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v19 & 1;
}
