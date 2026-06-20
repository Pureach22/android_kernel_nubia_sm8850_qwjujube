__int64 __fastcall policy_mgr_get_connection_max_channel_width(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x20
  unsigned int v11; // w9
  unsigned int v12; // w10
  unsigned int v13; // w11
  unsigned int v14; // w10
  unsigned int v15; // w10
  unsigned int v16; // w19

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v10 = context;
    qdf_mutex_acquire(context + 56);
    v11 = qword_8D4EF0;
    if ( (unsigned int)qword_8D4EF0 <= 3 )
      v11 = 3;
    v12 = qword_8D4F14;
    if ( !BYTE4(qword_8D4F00) )
      v11 = 3;
    if ( (unsigned int)qword_8D4F14 <= v11 )
      v12 = v11;
    v13 = qword_8D4F38;
    if ( BYTE4(qword_8D4F24) )
      v11 = v12;
    if ( (unsigned int)qword_8D4F38 <= v11 )
      v13 = v11;
    v14 = qword_8D4F5C;
    if ( BYTE4(qword_8D4F48) )
      v11 = v13;
    if ( (unsigned int)qword_8D4F5C <= v11 )
      v14 = v11;
    if ( BYTE4(qword_8D4F6C) )
      v11 = v14;
    if ( (unsigned int)qword_8D4F80 <= v11 )
      v15 = v11;
    else
      v15 = qword_8D4F80;
    if ( BYTE4(qword_8D4F90) )
      v16 = v15;
    else
      v16 = v11;
    qdf_mutex_release(v10 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: pm_ctx is NULL",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_get_connection_max_channel_width");
    return 3;
  }
  return v16;
}
