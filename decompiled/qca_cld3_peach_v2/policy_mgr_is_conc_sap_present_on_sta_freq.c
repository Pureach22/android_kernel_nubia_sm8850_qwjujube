bool __fastcall policy_mgr_is_conc_sap_present_on_sta_freq(__int64 a1, int a2, int a3)
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
  __int64 v15; // x20
  _BOOL4 v16; // w19
  __int64 v17; // x8

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( (a2 & 0xFFFFFFFD) != 0 )
    {
      return 0;
    }
    else
    {
      v15 = context;
      qdf_mutex_acquire(context + 56);
      if ( BYTE4(qword_8D4F00) == 1
        && HIDWORD(pm_conc_connection_list) == a3
        && (pm_conc_connection_list & 0xFFFFFFFD) == 1 )
      {
        v16 = 1;
        v17 = v15;
      }
      else
      {
        v17 = v15;
        v16 = BYTE4(qword_8D4F24) == 1 && HIDWORD(qword_8D4F0C) == a3 && (qword_8D4F0C & 0xFFFFFFFD) == 1
           || BYTE4(qword_8D4F48) == 1 && HIDWORD(qword_8D4F30) == a3 && (qword_8D4F30 & 0xFFFFFFFD) == 1
           || BYTE4(qword_8D4F6C) == 1 && HIDWORD(qword_8D4F54) == a3 && (qword_8D4F54 & 0xFFFFFFFD) == 1
           || BYTE4(qword_8D4F90) == 1 && HIDWORD(qword_8D4F78) == a3 && (qword_8D4F78 & 0xFFFFFFFD) == 1;
      }
      qdf_mutex_release(v17 + 56);
      return v16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid pm context",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_is_conc_sap_present_on_sta_freq");
    return 0;
  }
}
