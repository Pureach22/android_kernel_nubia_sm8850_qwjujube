__int64 __fastcall walt_should_kick_upmigrate_0(char *a1, __int64 a2)
{
  char *v2; // x9
  bool v3; // zf
  __int64 result; // x0
  _QWORD *v5; // x8
  __int64 v6; // x9

  v2 = a1 + 5184;
  v3 = a1 == (char *)&init_task;
  result = 0;
  if ( v3 )
    v5 = &vendor_data_pad;
  else
    v5 = v2;
  if ( sysctl_sched_user_hint == 1000 )
  {
    v6 = v5[30];
    if ( v6 )
    {
      if ( *(_DWORD *)v6 == 1 && *(_BYTE *)(v6 + 40) == 1 && *((_DWORD *)v5 + 55) )
      {
        if ( (unsigned int)a2 >= 0x20 )
        {
          __break(0x5512u);
          return task_fits_capacity(0, a2);
        }
        else
        {
          return *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a2) + 8] + 32LL) == min_possible_cluster_id;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
