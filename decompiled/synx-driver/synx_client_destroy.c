__int64 __fastcall synx_client_destroy(_QWORD *a1)
{
  _QWORD *v1; // x9
  __int64 v2; // x11

  v1 = (_QWORD *)a1[33106];
  if ( v1 )
  {
    v2 = a1[33105];
    *v1 = v2;
    if ( v2 )
      *(_QWORD *)(v2 + 8) = v1;
    a1[33105] = 0;
    a1[33106] = 0;
  }
  a1[33101] = 0xFFFFFFFE00000LL;
  a1[33102] = a1 + 33102;
  a1[33103] = a1 + 33102;
  a1[33104] = synx_client_cleanup;
  return queue_work_on(32, *(_QWORD *)(synx_dev + 168), a1 + 33101);
}
