void *__fastcall kgsl_get_device(int a1)
{
  void *v2; // x19

  mutex_lock(&unk_3A878);
  v2 = off_3A7F8;
  if ( !off_3A7F8 || *(int *)((char *)&dword_10 + (_QWORD)off_3A7F8) != a1 )
    v2 = nullptr;
  mutex_unlock(&unk_3A878);
  return v2;
}
