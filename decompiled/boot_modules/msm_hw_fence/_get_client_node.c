_QWORD *__fastcall get_client_node(__int64 a1, int a2)
{
  _QWORD *v4; // x9
  _QWORD *v5; // x20

  mutex_lock(a1 + 544);
  v4 = (_QWORD *)(a1 + 528);
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(a1 + 528) )
      break;
    if ( *((_DWORD *)v4 - 16) == a2 )
    {
      v5 = v4 - 8;
      goto LABEL_6;
    }
  }
  v5 = nullptr;
LABEL_6:
  mutex_unlock(a1 + 544);
  return v5;
}
