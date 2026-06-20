__int64 __fastcall set_preferred_cluster(__int64 result, __int64 a2)
{
  int v2; // w12
  _QWORD *v3; // x23
  _QWORD *v4; // x24
  __int64 v5; // x8
  unsigned __int64 v6; // x20
  char *v7; // x21
  unsigned int v8; // w4
  char v9; // w0
  char v10; // w8
  unsigned __int16 *v11; // x8
  char v12; // w11
  int v13; // w8
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  int v16; // [xsp+Ch] [xbp-14h]
  __int64 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v2 = *(unsigned __int8 *)(result + 40);
  if ( !sched_group_upmigrate )
    goto LABEL_4;
  v3 = (_QWORD *)(result + 8);
  v4 = *(_QWORD **)(result + 8);
  if ( v4 == (_QWORD *)(result + 8) || max_possible_cluster_id == min_possible_cluster_id )
    goto LABEL_4;
  if ( a2 - *(_QWORD *)(result + 64) < (unsigned int)sched_ravg_window / 0xAuLL )
    return result;
  v6 = 0;
  while ( 1 )
  {
    if ( v4 - 31 == (_QWORD *)&vendor_data_pad )
      v7 = (char *)&init_task;
    else
      v7 = (char *)(v4 - 679);
    if ( boost_policy )
    {
      v18 = result;
      v17 = a2;
      v16 = v2;
      v9 = task_sched_boost(v7);
      v2 = v16;
      a2 = v17;
      v10 = v9;
      result = v18;
      if ( (v10 & 1) != 0 && boost_policy == 1 )
      {
        if ( sched_boost_type != 5 && sched_boost_type != 2 )
          goto LABEL_29;
        v11 = (unsigned __int16 *)(v7 + 5184);
        if ( v7 == (char *)&init_task )
          v11 = (unsigned __int16 *)&vendor_data_pad;
        if ( sysctl_sched_min_task_util_for_boost < (unsigned int)v11[79] )
        {
LABEL_29:
          *(_QWORD *)(v18 + 64) = v17;
          goto LABEL_4;
        }
      }
    }
    if ( *(v4 - 30) >= a2 - (unsigned __int64)(unsigned int)(5 * sched_ravg_window) )
    {
      v6 += *((unsigned int *)v4 - 54);
      v8 = sched_group_upmigrate;
      if ( v6 > (unsigned int)sched_group_upmigrate )
        break;
    }
    v4 = (_QWORD *)*v4;
    if ( v4 == v3 )
    {
      v8 = sched_group_upmigrate;
      break;
    }
  }
  v12 = *(_BYTE *)(result + 40);
  v13 = sysctl_sched_user_hint;
  *(_QWORD *)(result + 64) = a2;
  if ( v13 == 1000 )
    v14 = v8;
  else
    v14 = v6;
  if ( (v12 & 1) == 0 )
  {
    if ( v14 >= v8 )
      *(_BYTE *)(result + 40) = 1;
    goto LABEL_5;
  }
  if ( v14 >= (unsigned int)sched_group_downmigrate )
  {
    if ( *(_QWORD *)(result + 72) )
      *(_QWORD *)(result + 72) = 0;
    goto LABEL_5;
  }
  if ( !sysctl_sched_coloc_downmigrate_ns
    || a2 - *(_QWORD *)(result + 80) < (unsigned __int64)(unsigned int)sysctl_sched_hyst_min_coloc_ns )
  {
    goto LABEL_40;
  }
  v15 = *(_QWORD *)(result + 72);
  if ( !v15 )
  {
    *(_QWORD *)(result + 72) = a2;
    goto LABEL_5;
  }
  if ( a2 - v15 > (unsigned __int64)(unsigned int)sysctl_sched_coloc_downmigrate_ns )
  {
LABEL_40:
    *(_QWORD *)(result + 72) = 0;
LABEL_4:
    *(_BYTE *)(result + 40) = 0;
  }
LABEL_5:
  if ( *(_DWORD *)result == 1 && *(unsigned __int8 *)(result + 40) != v2 )
  {
    if ( *(_BYTE *)(result + 40) )
      v5 = a2;
    else
      v5 = 0;
    *(_QWORD *)(result + 80) = v5;
    return ((__int64 (*)(void))sched_update_hyst_times)();
  }
  return result;
}
