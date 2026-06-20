__int64 __fastcall csr_release_command(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  __int64 v13; // x20
  int v14; // w9
  int v15; // w8
  const char *v16; // x2
  __int64 result; // x0
  int v18; // w8
  int v19; // w9
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  _QWORD v54[4]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v55; // [xsp+28h] [xbp-38h]
  __int64 v56; // [xsp+30h] [xbp-30h]
  __int128 v57; // [xsp+38h] [xbp-28h] BYREF
  __int64 v58; // [xsp+48h] [xbp-18h]
  __int64 v59; // [xsp+50h] [xbp-10h]
  __int64 v60; // [xsp+58h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v59 = 0;
  v57 = 0u;
  v55 = 0;
  v56 = 0;
  memset(v54, 0, sizeof(v54));
  if ( !a2 )
  {
    v16 = "%s: sme_cmd is NULL";
LABEL_11:
    result = qdf_trace_msg(0x34u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "csr_release_command");
    goto LABEL_38;
  }
  v12 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21624),
          (unsigned int)a2[6],
          11);
  if ( !v12 )
  {
    v16 = "%s: Invalid vdev";
    goto LABEL_11;
  }
  v13 = v12;
  qdf_mem_set(&v57, 0x20u, 0);
  v14 = a2[4];
  DWORD2(v57) = a2[5];
  HIDWORD(v57) = 8;
  v15 = 34;
  if ( v14 <= 262146 )
  {
    if ( v14 > 0x40000 )
    {
      if ( v14 == 262145 )
        v15 = 11;
      else
        v15 = 12;
    }
    else if ( v14 == 65537 )
    {
      v18 = a2[8];
      if ( v18 == 2 )
        v19 = 3;
      else
        v19 = 34;
      if ( v18 == 1 )
        v15 = 2;
      else
        v15 = v19;
    }
    else if ( v14 == 65538 )
    {
      v15 = 5;
    }
  }
  else if ( v14 <= 262148 )
  {
    if ( v14 == 262147 )
      v15 = 16;
    else
      v15 = 17;
  }
  else
  {
    switch ( v14 )
    {
      case 262149:
        v15 = 18;
        break;
      case 262150:
        v15 = 19;
        break;
      case 262151:
        v15 = 31;
        break;
    }
  }
  DWORD1(v57) = v15;
  v58 = v13;
  qdf_mem_set(v54, 0x30u, 0);
  v20 = *(_QWORD *)(a1 + 21624);
  v54[0] = *(_QWORD *)((char *)&v57 + 4);
  v55 = v58;
  if ( (wlan_serialization_is_cmd_present_in_active_queue(
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v20,
          (unsigned int *)v54)
      & 1) != 0 )
  {
    LOBYTE(v59) = 1;
    wlan_serialization_remove_cmd((unsigned int *)&v57, v29, v30, v31, v32, v33, v34, v35, v36);
    result = v58;
    if ( !v58 )
      goto LABEL_38;
    goto LABEL_37;
  }
  if ( (wlan_serialization_is_cmd_present_in_pending_queue(
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          *(_QWORD *)(a1 + 21624),
          (unsigned int *)v54)
      & 1) != 0 )
  {
    LOBYTE(v59) = 2;
    wlan_serialization_cancel_request((unsigned int *)&v57, v46, v47, v48, v49, v50, v51, v52, v53);
    result = v58;
    if ( !v58 )
      goto LABEL_38;
    goto LABEL_37;
  }
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: can't find cmd_id %d cmd_type %d",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "csr_release_command",
    DWORD2(v57),
    DWORD1(v57));
  result = v58;
  if ( v58 )
LABEL_37:
    result = wlan_objmgr_vdev_release_ref(result, 0xBu, v37, v38, v39, v40, v41, v42, v43, v44, v45);
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
