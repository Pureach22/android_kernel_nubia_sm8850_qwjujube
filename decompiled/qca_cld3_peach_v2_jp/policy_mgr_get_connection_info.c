__int64 __fastcall policy_mgr_get_connection_info(__int64 a1, __int64 a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  __int64 v22; // x23
  __int64 v23; // x23
  __int64 v24; // x23
  __int64 v25; // x20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_81C458) == 1 )
    {
      *(_BYTE *)(a2 + 1) = qword_81C458;
      *(_BYTE *)a2 = BYTE4(qword_81C448);
      *(_BYTE *)(a2 + 2) = wlan_reg_freq_to_chan(
                             *(_QWORD *)(v12 + 8),
                             HIDWORD(pm_conc_connection_list),
                             v13,
                             v14,
                             v15,
                             v16,
                             v17,
                             v18,
                             v19,
                             v20);
      v21 = 1;
      *(_DWORD *)(a2 + 4) = HIDWORD(pm_conc_connection_list);
    }
    else
    {
      v21 = 0;
    }
    if ( BYTE4(qword_81C47C) == 1 )
    {
      v22 = a2 + 8LL * v21;
      *(_BYTE *)(v22 + 1) = qword_81C47C;
      *(_BYTE *)v22 = BYTE4(qword_81C46C);
      *(_BYTE *)(v22 + 2) = wlan_reg_freq_to_chan(
                              *(_QWORD *)(v12 + 8),
                              HIDWORD(qword_81C464),
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20);
      ++v21;
      *(_DWORD *)(v22 + 4) = HIDWORD(qword_81C464);
    }
    if ( BYTE4(qword_81C4A0) == 1 )
    {
      v23 = a2 + 8LL * v21;
      *(_BYTE *)(v23 + 1) = qword_81C4A0;
      *(_BYTE *)v23 = BYTE4(qword_81C490);
      *(_BYTE *)(v23 + 2) = wlan_reg_freq_to_chan(
                              *(_QWORD *)(v12 + 8),
                              HIDWORD(qword_81C488),
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20);
      ++v21;
      *(_DWORD *)(v23 + 4) = HIDWORD(qword_81C488);
    }
    if ( BYTE4(qword_81C4C4) == 1 )
    {
      v24 = a2 + 8LL * v21;
      *(_BYTE *)(v24 + 1) = qword_81C4C4;
      *(_BYTE *)v24 = BYTE4(qword_81C4B4);
      *(_BYTE *)(v24 + 2) = wlan_reg_freq_to_chan(
                              *(_QWORD *)(v12 + 8),
                              HIDWORD(qword_81C4AC),
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20);
      ++v21;
      *(_DWORD *)(v24 + 4) = HIDWORD(qword_81C4AC);
    }
    if ( BYTE4(qword_81C4E8) == 1 )
    {
      v25 = a2 + 8LL * v21;
      *(_BYTE *)(v25 + 1) = qword_81C4E8;
      *(_BYTE *)v25 = BYTE4(qword_81C4D8);
      *(_BYTE *)(v25 + 2) = wlan_reg_freq_to_chan(
                              *(_QWORD *)(v12 + 8),
                              HIDWORD(qword_81C4D0),
                              v13,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20);
      ++v21;
      *(_DWORD *)(v25 + 4) = HIDWORD(qword_81C4D0);
    }
    qdf_mutex_release(v12 + 56);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_connection_info");
    return 0;
  }
  return v21;
}
