__int64 __fastcall policy_mgr_current_concurrency_is_mcc(__int64 a1)
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
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x22
  unsigned int v14; // w21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  char v23; // w20
  const char *v24; // x3
  unsigned int v25; // w1

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v24 = "policy_mgr_current_concurrency_is_mcc";
LABEL_11:
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, v24);
    goto LABEL_12;
  }
  v11 = context;
  v12 = policy_mgr_get_context(a1);
  if ( !v12 )
  {
    v24 = "policy_mgr_get_connection_count";
    goto LABEL_11;
  }
  v13 = v12;
  qdf_mutex_acquire(v12 + 56);
  v14 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
  qdf_mutex_release(v13 + 56);
  if ( v14 )
  {
    qdf_mutex_acquire(v11 + 56);
    if ( v14 == 1 )
      goto LABEL_23;
    if ( v14 != 3 )
    {
      if ( v14 == 2 )
      {
        if ( HIDWORD(pm_conc_connection_list) != HIDWORD(qword_8D4F0C) )
        {
          v23 = policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C));
LABEL_24:
          qdf_mutex_release(v11 + 56);
          return v23 & 1;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: unexpected num_connections value %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "policy_mgr_current_concurrency_is_mcc",
          v14);
      }
LABEL_23:
      v23 = 0;
      goto LABEL_24;
    }
    v25 = HIDWORD(pm_conc_connection_list);
    if ( HIDWORD(pm_conc_connection_list) != HIDWORD(qword_8D4F0C) )
    {
      if ( (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_8D4F0C)) & 1) != 0 )
        goto LABEL_21;
      v25 = HIDWORD(pm_conc_connection_list);
    }
    if ( v25 != HIDWORD(qword_8D4F30) )
    {
      if ( (policy_mgr_are_2_freq_on_same_mac(a1, v25, HIDWORD(qword_8D4F30)) & 1) != 0 )
        goto LABEL_21;
      v25 = HIDWORD(qword_8D4F30);
    }
    if ( HIDWORD(qword_8D4F0C) == v25 || (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(qword_8D4F0C), v25) & 1) == 0 )
      goto LABEL_23;
LABEL_21:
    v23 = 1;
    goto LABEL_24;
  }
LABEL_12:
  v23 = 0;
  return v23 & 1;
}
