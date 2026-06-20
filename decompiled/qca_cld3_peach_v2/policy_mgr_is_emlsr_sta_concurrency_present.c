__int64 __fastcall policy_mgr_is_emlsr_sta_concurrency_present(__int64 a1)
{
  unsigned int v2; // w20
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
  unsigned int v13; // w21
  __int64 result; // x0
  unsigned __int8 v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, v15) & 1) == 0 )
    goto LABEL_6;
  v2 = v15[0];
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_connection_count");
    goto LABEL_6;
  }
  v12 = context;
  qdf_mutex_acquire(context + 56);
  v13 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
  qdf_mutex_release(v12 + 56);
  if ( v13 <= v2 )
  {
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  result = 1;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
