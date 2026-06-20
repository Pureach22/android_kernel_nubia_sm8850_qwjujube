__int64 __fastcall wlan_ipa_opt_dp_wait_for_completion(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x20
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x8
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x8
  __int64 (__fastcall *v19)(_QWORD); // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v9 = *(_QWORD *)(result + 1456);
  if ( !v9 )
    return qdf_trace_msg(0x45u, 2u, "%s: pointer null", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_ipa_is_completion_pending");
  if ( !*(_QWORD *)v9 )
    return qdf_trace_msg(0x45u, 2u, "%s: pointer null", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_ipa_is_completion_pending");
  v10 = *(_QWORD *)(*(_QWORD *)v9 + 152LL);
  if ( !v10 )
    return qdf_trace_msg(0x45u, 2u, "%s: pointer null", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_ipa_is_completion_pending");
  v11 = *(__int64 (__fastcall **)(_QWORD))(v10 + 272);
  if ( v11 )
  {
    v12 = result;
    v13 = *(_QWORD *)(result + 1456);
    if ( *((_DWORD *)v11 - 1) != 944657148 )
      __break(0x8228u);
    result = v11(v13);
    if ( (result & 1) != 0 )
    {
      result = qdf_sleep();
      if ( !*(_QWORD *)v9 )
        return qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: pointer null",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "cdp_ipa_is_completion_pending");
      v14 = *(_QWORD *)(*(_QWORD *)v9 + 152LL);
      if ( !v14 )
        return qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: pointer null",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "cdp_ipa_is_completion_pending");
      v15 = *(__int64 (__fastcall **)(_QWORD))(v14 + 272);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != 944657148 )
          __break(0x8228u);
        result = v15(v9);
        if ( (result & 1) != 0 )
        {
          result = qdf_sleep();
          if ( !*(_QWORD *)v9 )
            return qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: pointer null",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "cdp_ipa_is_completion_pending");
          v16 = *(_QWORD *)(*(_QWORD *)v9 + 152LL);
          if ( !v16 )
            return qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: pointer null",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "cdp_ipa_is_completion_pending");
          v17 = *(__int64 (__fastcall **)(_QWORD))(v16 + 272);
          if ( v17 )
          {
            if ( *((_DWORD *)v17 - 1) != 944657148 )
              __break(0x8228u);
            result = v17(v9);
            if ( (result & 1) != 0 )
            {
              result = qdf_sleep();
              if ( *(_QWORD *)v9 )
              {
                v18 = *(_QWORD *)(*(_QWORD *)v9 + 152LL);
                if ( v18 )
                {
                  v19 = *(__int64 (__fastcall **)(_QWORD))(v18 + 272);
                  if ( v19 )
                  {
                    if ( *((_DWORD *)v19 - 1) != 944657148 )
                      __break(0x8228u);
                    result = v19(v9);
                    if ( (result & 1) != 0 )
                    {
                      qdf_sleep();
                      result = qdf_trace_msg(
                                 0x45u,
                                 2u,
                                 "%s: Tx completion pending",
                                 v20,
                                 v21,
                                 v22,
                                 v23,
                                 v24,
                                 v25,
                                 v26,
                                 v27,
                                 "wlan_ipa_opt_dp_wait_for_completion");
                      *(_BYTE *)(v12 + 8440) = 1;
                    }
                  }
                  return result;
                }
              }
              return qdf_trace_msg(
                       0x45u,
                       2u,
                       "%s: pointer null",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       "cdp_ipa_is_completion_pending");
            }
          }
        }
      }
    }
  }
  return result;
}
