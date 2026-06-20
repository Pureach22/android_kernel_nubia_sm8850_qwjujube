_QWORD *__fastcall cam_cdm_find_request_by_bl_tag(int a1, _QWORD *a2)
{
  _QWORD *v2; // x8

  v2 = a2;
  while ( 1 )
  {
    v2 = (_QWORD *)*v2;
    if ( v2 == a2 )
      break;
    if ( *((unsigned __int8 *)v2 - 32) == a1 )
      return v2 - 4;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    1,
    "cam_cdm_find_request_by_bl_tag",
    163,
    "Could not find the bl request for tag=%x",
    a1);
  return nullptr;
}
