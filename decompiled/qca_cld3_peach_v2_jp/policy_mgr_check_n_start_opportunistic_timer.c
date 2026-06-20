__int64 __fastcall policy_mgr_check_n_start_opportunistic_timer(__int64 a1)
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
  unsigned int v12; // w19
  const char *v13; // x2
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v12 = 16;
    v13 = "%s: PM ctx not valid. Oppurtunistic timer cannot start";
    goto LABEL_6;
  }
  v11 = context;
  if ( !(unsigned int)policy_mgr_need_opportunistic_upgrade(a1, &v15) )
  {
    v12 = 16;
    goto LABEL_8;
  }
  qdf_mc_timer_stop(v11 + 120);
  v12 = qdf_mc_timer_start(v11 + 120, 0x1388u);
  if ( v12 )
  {
    v13 = "%s: Failed to start dbs opportunistic timer";
LABEL_6:
    qdf_trace_msg(0x4Fu, 2u, v13, v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_check_n_start_opportunistic_timer");
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v12;
}
