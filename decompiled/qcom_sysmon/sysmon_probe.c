__int64 __fastcall sysmon_probe(__int64 a1)
{
  __int64 v2; // x0
  void *v3; // x20
  _UNKNOWN **v4; // x21
  __int64 result; // x0
  const char *v6; // x1

  v2 = rproc_get_by_child();
  if ( v2 )
  {
    v3 = (void *)v2;
    mutex_lock(&sysmon_lock);
    v4 = &sysmon_list;
    while ( 1 )
    {
      v4 = (_UNKNOWN **)*v4;
      if ( v4 == &sysmon_list )
        break;
      if ( *(v4 - 8) == v3 )
      {
        mutex_unlock(&sysmon_lock);
        result = 0;
        *(_QWORD *)(*(_QWORD *)(a1 + 968) + 88LL) = v4 - 14;
        v4[16] = *(_UNKNOWN **)(a1 + 968);
        return result;
      }
    }
    mutex_unlock(&sysmon_lock);
    v6 = "no sysmon associated with parent rproc\n";
  }
  else
  {
    v6 = "sysmon device not child of rproc\n";
  }
  dev_err(a1, v6);
  return 4294967274LL;
}
