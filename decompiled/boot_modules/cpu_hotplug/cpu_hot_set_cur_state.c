__int64 __fastcall cpu_hot_set_cur_state(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x20
  char v4; // w21

  v2 = *(_QWORD *)(a1 + 944);
  if ( *(_DWORD *)(v2 + 16) == -1 )
    return 4294967277LL;
  if ( a2 > 1 )
    return 4294967274LL;
  if ( *(unsigned __int8 *)(v2 + 20) != a2 )
  {
    v4 = a2;
    mutex_lock(&cpu_hot_lock);
    *(_BYTE *)(v2 + 20) = v4;
    mutex_unlock(&cpu_hot_lock);
    queue_work_on(32, system_highpri_wq, v2 + 96);
  }
  return 0;
}
