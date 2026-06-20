__int64 __fastcall policy_mgr_fetch_existing_con_info(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        _DWORD *a4,
        _DWORD *a5,
        _DWORD *a6)
{
  __int64 context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  __int64 *v22; // x26
  char *v23; // x27
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v21 = context;
    qdf_mutex_acquire(context + 56);
    if ( ((unsigned int)pm_conc_connection_list < 4 || (_DWORD)pm_conc_connection_list == 6) && BYTE4(qword_81C458) == 1 )
    {
      v22 = &pm_conc_connection_list;
      v23 = (char *)&pm_conc_connection_list + 4;
      if ( (policy_mgr_are_2_freq_on_same_mac(a1, a3, HIDWORD(pm_conc_connection_list)) & 1) != 0
        && HIDWORD(pm_conc_connection_list) != a3
        && (_DWORD)qword_81C458 != a2 )
      {
        goto LABEL_32;
      }
    }
    if ( ((unsigned int)qword_81C464 < 4 || (_DWORD)qword_81C464 == 6) && BYTE4(qword_81C47C) == 1 )
    {
      v22 = &qword_81C464;
      v23 = (char *)&qword_81C464 + 4;
      if ( (policy_mgr_are_2_freq_on_same_mac(a1, a3, HIDWORD(qword_81C464)) & 1) != 0
        && HIDWORD(qword_81C464) != a3
        && (_DWORD)qword_81C47C != a2 )
      {
        goto LABEL_32;
      }
    }
    if ( ((unsigned int)qword_81C488 < 4 || (_DWORD)qword_81C488 == 6)
      && BYTE4(qword_81C4A0) == 1
      && (v22 = &qword_81C488,
          v23 = (char *)&qword_81C488 + 4,
          (policy_mgr_are_2_freq_on_same_mac(a1, a3, HIDWORD(qword_81C488)) & 1) != 0)
      && HIDWORD(qword_81C488) != a3
      && (_DWORD)qword_81C4A0 != a2
      || ((unsigned int)qword_81C4AC < 4 || (_DWORD)qword_81C4AC == 6)
      && BYTE4(qword_81C4C4) == 1
      && (v22 = &qword_81C4AC,
          v23 = (char *)&qword_81C4AC + 4,
          (policy_mgr_are_2_freq_on_same_mac(a1, a3, HIDWORD(qword_81C4AC)) & 1) != 0)
      && HIDWORD(qword_81C4AC) != a3
      && (_DWORD)qword_81C4C4 != a2
      || ((unsigned int)qword_81C4D0 < 4 || (_DWORD)qword_81C4D0 == 6)
      && BYTE4(qword_81C4E8) == 1
      && (v22 = &qword_81C4D0,
          v23 = (char *)&qword_81C4D0 + 4,
          (policy_mgr_are_2_freq_on_same_mac(a1, a3, HIDWORD(qword_81C4D0)) & 1) != 0)
      && HIDWORD(qword_81C4D0) != a3
      && (_DWORD)qword_81C4E8 != a2 )
    {
LABEL_32:
      qdf_mutex_release(v21 + 56);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Existing vdev_id for mode %d is %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "policy_mgr_fetch_existing_con_info",
        *(unsigned int *)v22,
        *((unsigned int *)v22 + 6));
      *a4 = *(_DWORD *)v22;
      *a5 = *(_DWORD *)v23;
      *a6 = policy_mgr_get_ch_width(*((_DWORD *)v22 + 2), v32, v33, v34, v35, v36, v37, v38, v39);
      return *((unsigned int *)v22 + 6);
    }
    qdf_mutex_release(v21 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "policy_mgr_fetch_existing_con_info");
  }
  return 255;
}
