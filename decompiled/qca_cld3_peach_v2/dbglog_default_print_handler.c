__int64 __fastcall dbglog_default_print_handler(
        __int64 result,
        unsigned __int16 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int16 a5,
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int v14; // w22
  __int64 v18; // x4
  char *v19; // x23
  char *v20; // x22
  __int64 v21; // x23

  v14 = a2;
  v18 = a3;
  if ( a2 <= 0xEu )
  {
    if ( (dword_183E4 & 4) == 0 )
      goto LABEL_18;
    if ( (unsigned int)result > 0x9C || a3 > 0xFF )
    {
LABEL_8:
      v19 = dbglog_get_msg_unknown_str;
      snprintf(dbglog_get_msg_unknown_str, 0x40u, "UNKNOWN %u:%u", result, a3);
LABEL_9:
      result = qdf_trace_msg(
                 0x38u,
                 2u,
                 "%s: FWLOG: [%u] vap-%u %s ( ",
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 a14,
                 "dbglog_default_print_handler",
                 a4,
                 v14,
                 v19);
      goto LABEL_18;
    }
    if ( (((unsigned __int64)(unsigned int)result << 11) | (8LL * a3)) >> 11 <= 0x9C )
    {
      v19 = (&DBG_MSG_ARR[256 * (unsigned __int64)(unsigned int)result])[a3];
      if ( v19 && *v19 )
        goto LABEL_9;
      goto LABEL_8;
    }
LABEL_29:
    __break(1u);
    JUMPOUT(0x5B4C0C);
  }
  if ( (dword_183E4 & 4) != 0 )
  {
    if ( (unsigned int)result > 0x9C || a3 > 0xFF )
      goto LABEL_16;
    if ( (((unsigned __int64)(unsigned int)result << 11) | (8LL * a3)) >> 11 > 0x9C )
      goto LABEL_29;
    v20 = (&DBG_MSG_ARR[256 * (unsigned __int64)(unsigned int)result])[a3];
    if ( !v20 || !*v20 )
    {
LABEL_16:
      v20 = dbglog_get_msg_unknown_str;
      snprintf(dbglog_get_msg_unknown_str, 0x40u, "UNKNOWN %u:%u", result, a3);
    }
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s: FWLOG: [%u] %s ( ",
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               "dbglog_default_print_handler",
               a4,
               v20);
  }
LABEL_18:
  if ( a5 )
  {
    v21 = 0;
    do
    {
      if ( (dword_183E4 & 4) != 0 )
        result = qdf_trace_msg(
                   0x38u,
                   2u,
                   "%s: %#x",
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   a13,
                   a14,
                   "dbglog_default_print_handler",
                   *(unsigned int *)(a6 + 4 * v21));
      if ( ++v21 < (unsigned __int64)a5 && (dword_183E4 & 4) != 0 )
        result = qdf_trace_msg(
                   0x38u,
                   2u,
                   "%s: , ",
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   a13,
                   a14,
                   "dbglog_default_print_handler",
                   v18);
    }
    while ( a5 != v21 );
  }
  if ( (dword_183E4 & 4) != 0 )
    return qdf_trace_msg(
             0x38u,
             2u,
             "%s:  )\n",
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             "dbglog_default_print_handler",
             v18);
  return result;
}
