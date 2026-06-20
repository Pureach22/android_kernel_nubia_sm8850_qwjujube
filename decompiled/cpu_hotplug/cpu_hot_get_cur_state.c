__int64 __fastcall cpu_hot_get_cur_state(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x21

  v2 = *(_QWORD *)(a1 + 944);
  mutex_lock(&cpu_hot_lock);
  *a2 = *(unsigned __int8 *)(v2 + 20);
  mutex_unlock(&cpu_hot_lock);
  return 0;
}
