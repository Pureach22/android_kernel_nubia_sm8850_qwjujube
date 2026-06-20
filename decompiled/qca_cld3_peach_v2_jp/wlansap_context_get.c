__int64 __fastcall wlansap_context_get(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v11; // x8
  unsigned int v18; // w9

  qdf_mutex_acquire((__int64)&sap_context_lock);
  if ( !a1 )
    goto LABEL_8;
  if ( gp_sap_ctx == a1 )
  {
    v11 = 0;
  }
  else if ( qword_855E88 == a1 )
  {
    v11 = 1;
  }
  else if ( qword_855E90 == a1 )
  {
    v11 = 2;
  }
  else if ( qword_855E98 == a1 )
  {
    v11 = 3;
  }
  else if ( qword_855EA0 == a1 )
  {
    v11 = 4;
  }
  else
  {
    if ( qword_855EA8 != a1 )
    {
LABEL_8:
      qdf_mutex_release((__int64)&sap_context_lock);
      qdf_trace_msg(0x39u, 8u, "%s: sap session is not valid", v2, v3, v4, v5, v6, v7, v8, v9, "wlansap_context_get");
      return 16;
    }
    v11 = 5;
  }
  _X8 = (unsigned int *)&sap_ctx_ref_count[v11];
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 + 1, _X8) );
  qdf_mutex_release((__int64)&sap_context_lock);
  return 0;
}
