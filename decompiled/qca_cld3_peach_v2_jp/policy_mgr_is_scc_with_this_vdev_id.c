__int64 __fastcall policy_mgr_is_scc_with_this_vdev_id(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v13 = context;
    v23 = 0;
    if ( (unsigned int)policy_mgr_get_chan_by_session_id(a1, a2, &v23) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Failed to get channel for vdev:%d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "policy_mgr_is_scc_with_this_vdev_id",
        (unsigned __int8)a2);
    }
    else
    {
      qdf_mutex_acquire(v13 + 56);
      if ( (_DWORD)qword_81C458 != (unsigned __int8)a2
        && BYTE4(qword_81C458) == 1
        && HIDWORD(pm_conc_connection_list) == v23
        || (_DWORD)qword_81C47C != (unsigned __int8)a2 && BYTE4(qword_81C47C) == 1 && HIDWORD(qword_81C464) == v23
        || (_DWORD)qword_81C4A0 != (unsigned __int8)a2 && BYTE4(qword_81C4A0) == 1 && HIDWORD(qword_81C488) == v23
        || (_DWORD)qword_81C4C4 != (unsigned __int8)a2 && BYTE4(qword_81C4C4) == 1 && HIDWORD(qword_81C4AC) == v23
        || (_DWORD)qword_81C4E8 != (unsigned __int8)a2 && BYTE4(qword_81C4E8) == 1 && HIDWORD(qword_81C4D0) == v23 )
      {
        qdf_mutex_release(v13 + 56);
        result = 1;
        goto LABEL_6;
      }
      qdf_mutex_release(v13 + 56);
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_is_scc_with_this_vdev_id");
  }
  result = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
