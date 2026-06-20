__int64 **__fastcall wma_cdp_peer_setup(
        __int64 **result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  __int64 v14; // x8

  _ReadStatusReg(SP_EL0);
  if ( !*(_QWORD *)a12 || !(**(_DWORD **)a12 | *(unsigned __int16 *)(*(_QWORD *)a12 + 4LL)) )
  {
    if ( *result )
    {
      v14 = **result;
      if ( !v14 )
        goto LABEL_14;
      v13 = *(__int64 (**)(void))(v14 + 80);
      if ( !v13 )
        goto LABEL_14;
      goto LABEL_10;
    }
LABEL_13:
    result = (__int64 **)qdf_trace_msg(
                           0x89u,
                           8u,
                           "%s: Invalid Instance:",
                           a2,
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           "cdp_peer_setup");
    goto LABEL_14;
  }
  if ( !*result )
    goto LABEL_13;
  v12 = **result;
  if ( !v12 )
    goto LABEL_14;
  v13 = *(__int64 (**)(void))(v12 + 80);
  if ( !v13 )
    goto LABEL_14;
LABEL_10:
  if ( *((_DWORD *)v13 - 1) != 1226871712 )
    __break(0x8228u);
  result = (__int64 **)v13();
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
