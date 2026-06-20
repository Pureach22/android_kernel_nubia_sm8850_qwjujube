__int64 __fastcall cfg_bool_item_handler(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x21
  __int64 result; // x0
  const char *v7; // x7

  v5 = a1 + *(unsigned int *)(a2 + 8);
  result = qdf_bool_parse(a3, v5 + 28);
  if ( (_DWORD)result )
  {
    if ( *(_BYTE *)(v5 + 28) )
      v7 = "true";
    else
      v7 = "false";
    return qdf_trace_msg(
             80,
             2,
             "%s: %s=%s - Invalid format (status %d); Using default '%s'",
             "cfg_bool_item_handler",
             *(_QWORD *)a2,
             a3,
             (unsigned int)result,
             v7);
  }
  return result;
}
