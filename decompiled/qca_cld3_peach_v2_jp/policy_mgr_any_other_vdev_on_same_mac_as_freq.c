bool __fastcall policy_mgr_any_other_vdev_on_same_mac_as_freq(__int64 a1, unsigned int a2, unsigned __int8 a3)
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
  __int64 v15; // x19
  _BOOL4 v16; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v15 = context;
    qdf_mutex_acquire(context + 56);
    v16 = BYTE4(qword_81C458) == 1
       && (_DWORD)qword_81C458 != a3
       && (pm_conc_connection_list & 0xFFFFFFFE) != 4
       && (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(pm_conc_connection_list), a2) & 1) != 0
       || BYTE4(qword_81C47C) == 1
       && (_DWORD)qword_81C47C != a3
       && (qword_81C464 & 0xFFFFFFFE) != 4
       && (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(qword_81C464), a2) & 1) != 0
       || BYTE4(qword_81C4A0) == 1
       && (_DWORD)qword_81C4A0 != a3
       && (qword_81C488 & 0xFFFFFFFE) != 4
       && (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(qword_81C488), a2) & 1) != 0
       || BYTE4(qword_81C4C4) == 1
       && (_DWORD)qword_81C4C4 != a3
       && (qword_81C4AC & 0xFFFFFFFE) != 4
       && (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(qword_81C4AC), a2) & 1) != 0
       || BYTE4(qword_81C4E8) == 1
       && (_DWORD)qword_81C4E8 != a3
       && (qword_81C4D0 & 0xFFFFFFFE) != 4
       && (policy_mgr_are_2_freq_on_same_mac(a1, HIDWORD(qword_81C4D0), a2) & 1) != 0;
    qdf_mutex_release(v15 + 56);
  }
  else
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
      "policy_mgr_any_other_vdev_on_same_mac_as_freq");
    return 0;
  }
  return v16;
}
