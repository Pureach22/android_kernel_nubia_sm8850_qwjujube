__int64 __fastcall policy_mgr_check_and_stop_opportunistic_timer(__int64 a1, unsigned __int8 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  unsigned int v14; // w22
  const char *v15; // x2
  unsigned int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 16;
  result = policy_mgr_get_context(a1);
  if ( !result )
  {
    v15 = "%s: Invalid Context";
LABEL_7:
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               v15,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "policy_mgr_check_and_stop_opportunistic_timer");
    goto LABEL_8;
  }
  v13 = result;
  if ( *(_DWORD *)(result + 268) == 21 )
  {
    qdf_mc_timer_stop(result + 120);
    result = policy_mgr_need_opportunistic_upgrade(a1, &v16);
    if ( (_DWORD)result )
    {
      v14 = result;
      qdf_event_reset(v13 + 2112);
      if ( (unsigned int)policy_mgr_next_actions(a1, a2, v14, v16, 0) )
      {
        v15 = "%s: Failed in policy_mgr_next_actions";
      }
      else
      {
        result = qdf_wait_single_event(v13 + 2112, 0x1770u);
        if ( !(_DWORD)result )
          goto LABEL_8;
        v15 = "%s: wait for event failed";
      }
      goto LABEL_7;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
