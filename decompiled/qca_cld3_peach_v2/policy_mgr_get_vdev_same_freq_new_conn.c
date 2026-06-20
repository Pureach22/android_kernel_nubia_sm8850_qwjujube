__int64 __fastcall policy_mgr_get_vdev_same_freq_new_conn(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned __int8 *a4)
{
  __int64 context; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  unsigned __int8 v26; // w9
  unsigned int v27; // w22

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v16 = context;
    qdf_mutex_acquire(context + 56);
    v25 = a2;
    if ( BYTE4(qword_8D4F00) == 1
      && HIDWORD(pm_conc_connection_list) == a3
      && (v26 = qword_8D4F00, (_DWORD)qword_8D4F00 != a2)
      || BYTE4(qword_8D4F24) == 1 && HIDWORD(qword_8D4F0C) == a3 && (v26 = qword_8D4F24, (_DWORD)qword_8D4F24 != a2)
      || BYTE4(qword_8D4F48) == 1 && HIDWORD(qword_8D4F30) == a3 && (v26 = qword_8D4F48, (_DWORD)qword_8D4F48 != a2)
      || BYTE4(qword_8D4F6C) == 1 && HIDWORD(qword_8D4F54) == a3 && (v26 = qword_8D4F6C, (_DWORD)qword_8D4F6C != a2)
      || (v27 = 0, BYTE4(qword_8D4F90) == 1)
      && HIDWORD(qword_8D4F78) == a3
      && (v26 = qword_8D4F90, (_DWORD)qword_8D4F90 != v25) )
    {
      *a4 = v26;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: new_freq %d matched with vdev_id %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "policy_mgr_get_vdev_same_freq_new_conn",
        a3,
        v26);
      v27 = 1;
    }
    qdf_mutex_release(v16 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm_ctx",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "policy_mgr_get_vdev_same_freq_new_conn");
    return 0;
  }
  return v27;
}
