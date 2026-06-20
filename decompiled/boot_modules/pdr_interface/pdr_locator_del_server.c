__int64 __fastcall pdr_locator_del_server(__int64 a1)
{
  mutex_lock(a1 + 752);
  *(_BYTE *)(a1 + 800) = 0;
  *(_QWORD *)(a1 + 612) = 0;
  return mutex_unlock(a1 + 752);
}
