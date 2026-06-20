__int64 __fastcall cpu_hot_hp_online(int a1)
{
  _UNKNOWN **v2; // x8
  unsigned int v3; // w19

  mutex_lock(&cpu_hot_lock);
  v2 = &cpu_hot_cdev_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &cpu_hot_cdev_list )
      goto LABEL_9;
  }
  while ( *((_DWORD *)v2 + 4) != a1 );
  if ( !v2[3] )
  {
    queue_work_on(32, system_highpri_wq, v2 + 8);
LABEL_9:
    v3 = 0;
    goto LABEL_10;
  }
  if ( *((_BYTE *)v2 + 20) )
    v3 = 32770;
  else
    v3 = 0;
LABEL_10:
  mutex_unlock(&cpu_hot_lock);
  return v3;
}
