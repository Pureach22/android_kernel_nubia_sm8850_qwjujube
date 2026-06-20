__int64 __fastcall policy_mgr_get_vdev_diff_freq_new_conn(__int64 a1, unsigned int a2, _BYTE *a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 *v23; // x8
  unsigned int v24; // w22
  int v25; // w8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = context;
    qdf_mutex_acquire(context + 56);
    v23 = &pm_conc_connection_list;
    if ( BYTE4(qword_8D4F00) == 1 && HIDWORD(pm_conc_connection_list) != a2
      || (v23 = &qword_8D4F0C, BYTE4(qword_8D4F24) == 1) && HIDWORD(qword_8D4F0C) != a2
      || (v23 = &qword_8D4F30, BYTE4(qword_8D4F48) == 1) && HIDWORD(qword_8D4F30) != a2
      || (v23 = &qword_8D4F54, BYTE4(qword_8D4F6C) == 1) && HIDWORD(qword_8D4F54) != a2
      || (v23 = &qword_8D4F78, v24 = 0, BYTE4(qword_8D4F90) == 1) && HIDWORD(qword_8D4F78) != a2 )
    {
      v25 = *((_DWORD *)v23 + 6);
      *a3 = v25;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: new_freq %d matched with vdev_id %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "policy_mgr_get_vdev_diff_freq_new_conn",
        a2,
        (unsigned __int8)v25);
      v24 = 1;
    }
    qdf_mutex_release(v14 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm_ctx",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_get_vdev_diff_freq_new_conn");
    return 0;
  }
  return v24;
}
