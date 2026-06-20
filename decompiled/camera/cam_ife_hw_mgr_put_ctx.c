__int64 __fastcall cam_ife_hw_mgr_put_ctx(_QWORD *a1, _QWORD **a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x1

  mutex_lock(&unk_394A30);
  v4 = *a2;
  if ( *a2 )
  {
    v5 = (_QWORD *)a1[1];
    if ( v4 == a1 || v5 == v4 || (_QWORD *)*v5 != a1 )
    {
      _list_add_valid_or_report(v4);
    }
    else
    {
      a1[1] = v4;
      *v4 = a1;
      v4[1] = v5;
      *v5 = v4;
    }
  }
  *a2 = nullptr;
  return mutex_unlock(&unk_394A30);
}
