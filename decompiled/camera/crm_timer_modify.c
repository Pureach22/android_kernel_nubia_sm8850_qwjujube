_DWORD *__fastcall crm_timer_modify(_DWORD *result, __int64 a2)
{
  unsigned int v2; // w19
  _DWORD *v3; // x20

  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    v2 = a2;
    v3 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "crm_timer_modify",
      36,
      "new time %d",
      a2);
    result = v3;
    a2 = v2;
    if ( !v3 )
      return result;
  }
  else if ( !result )
  {
    return result;
  }
  *result = a2;
  return (_DWORD *)cam_common_modify_timer(result + 2, a2);
}
