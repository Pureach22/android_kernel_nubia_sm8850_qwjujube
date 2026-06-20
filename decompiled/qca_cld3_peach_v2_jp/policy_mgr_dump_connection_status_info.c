__int64 __fastcall policy_mgr_dump_connection_status_info(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _DWORD *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v29; // [xsp+0h] [xbp-30h]
  int v30; // [xsp+0h] [xbp-30h]
  __int64 v31; // [xsp+8h] [xbp-28h]
  int v32; // [xsp+8h] [xbp-28h]
  __int64 v33; // [xsp+10h] [xbp-20h]
  int v34; // [xsp+10h] [xbp-20h]
  __int64 v35; // [xsp+18h] [xbp-18h]
  int v36; // [xsp+18h] [xbp-18h]
  __int64 v37; // [xsp+20h] [xbp-10h]
  int v38; // [xsp+20h] [xbp-10h]
  __int64 v39; // [xsp+28h] [xbp-8h]
  int v40; // [xsp+28h] [xbp-8h]

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "policy_mgr_dump_connection_status_info");
  v11 = (_DWORD *)context;
  qdf_mutex_acquire(context + 56);
  if ( BYTE4(qword_81C458) == 1 )
  {
    v40 = HIWORD(qword_81C458);
    v38 = qword_81C448;
    v36 = dword_81C454;
    v34 = dword_81C450;
    v32 = HIDWORD(pm_conc_connection_list);
    v30 = BYTE4(qword_81C448);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: %d: use:%d vdev:%d mode:%d mac:%d freq:%d orig chainmask:%d orig nss:%d bw:%d, ch_flags %0X",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_dump_connection_status_info",
      0,
      1,
      (unsigned int)qword_81C458,
      (unsigned int)pm_conc_connection_list,
      v30,
      v32,
      v34,
      v36,
      v38,
      v40);
  }
  if ( BYTE4(qword_81C47C) == 1 )
  {
    LODWORD(v39) = HIWORD(qword_81C47C);
    LODWORD(v37) = qword_81C46C;
    LODWORD(v35) = dword_81C478;
    LODWORD(v33) = dword_81C474;
    LODWORD(v31) = HIDWORD(qword_81C464);
    LODWORD(v29) = BYTE4(qword_81C46C);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: %d: use:%d vdev:%d mode:%d mac:%d freq:%d orig chainmask:%d orig nss:%d bw:%d, ch_flags %0X",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_dump_connection_status_info",
      1,
      1,
      (unsigned int)qword_81C47C,
      (unsigned int)qword_81C464,
      v29,
      v31,
      v33,
      v35,
      v37,
      v39);
  }
  if ( BYTE4(qword_81C4A0) == 1 )
  {
    LODWORD(v39) = HIWORD(qword_81C4A0);
    LODWORD(v37) = qword_81C490;
    LODWORD(v35) = dword_81C49C;
    LODWORD(v33) = dword_81C498;
    LODWORD(v31) = HIDWORD(qword_81C488);
    LODWORD(v29) = BYTE4(qword_81C490);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: %d: use:%d vdev:%d mode:%d mac:%d freq:%d orig chainmask:%d orig nss:%d bw:%d, ch_flags %0X",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_dump_connection_status_info",
      2,
      1,
      (unsigned int)qword_81C4A0,
      (unsigned int)qword_81C488,
      v29,
      v31,
      v33,
      v35,
      v37,
      v39);
  }
  if ( BYTE4(qword_81C4C4) == 1 )
  {
    LODWORD(v39) = HIWORD(qword_81C4C4);
    LODWORD(v37) = qword_81C4B4;
    LODWORD(v35) = dword_81C4C0;
    LODWORD(v33) = dword_81C4BC;
    LODWORD(v31) = HIDWORD(qword_81C4AC);
    LODWORD(v29) = BYTE4(qword_81C4B4);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: %d: use:%d vdev:%d mode:%d mac:%d freq:%d orig chainmask:%d orig nss:%d bw:%d, ch_flags %0X",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_dump_connection_status_info",
      3,
      1,
      (unsigned int)qword_81C4C4,
      (unsigned int)qword_81C4AC,
      v29,
      v31,
      v33,
      v35,
      v37,
      v39);
  }
  if ( BYTE4(qword_81C4E8) == 1 )
  {
    LODWORD(v39) = HIWORD(qword_81C4E8);
    LODWORD(v37) = qword_81C4D8;
    LODWORD(v35) = dword_81C4E4;
    LODWORD(v33) = dword_81C4E0;
    LODWORD(v31) = HIDWORD(qword_81C4D0);
    LODWORD(v29) = BYTE4(qword_81C4D8);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: %d: use:%d vdev:%d mode:%d mac:%d freq:%d orig chainmask:%d orig nss:%d bw:%d, ch_flags %0X",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "policy_mgr_dump_connection_status_info",
      4,
      1,
      (unsigned int)qword_81C4E8,
      (unsigned int)qword_81C4D0,
      v29,
      v31,
      v33,
      v35,
      v37,
      v39);
  }
  qdf_mutex_release((__int64)(v11 + 14));
  if ( v11[365] | v11[367] )
    qdf_trace_msg(
      0x4Fu,
      8u,
      "PLCY_MGR_FREQ_RANGE_CUR: mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      0);
  if ( v11[369] | v11[371] )
    qdf_trace_msg(
      0x4Fu,
      8u,
      "PLCY_MGR_FREQ_RANGE_CUR: mac %d: 2Ghz: %d -> %d, 5Ghz: %d -> %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      1);
  return policy_mgr_validate_conn_info(a1);
}
