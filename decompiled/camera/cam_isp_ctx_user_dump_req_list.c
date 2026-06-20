_QWORD *__fastcall cam_isp_ctx_user_dump_req_list(_QWORD **a1, _QWORD *a2)
{
  _QWORD *v2; // x9
  bool v4; // zf
  _QWORD *result; // x0
  _QWORD *v6; // x10

  v2 = *a1;
  v4 = *a1 == a1;
  result = a2;
  if ( !v4 )
  {
    do
    {
      v6 = (_QWORD *)*v2;
      *result++ = v2[3];
      v2 = v6;
    }
    while ( v6 != a1 );
  }
  return result;
}
