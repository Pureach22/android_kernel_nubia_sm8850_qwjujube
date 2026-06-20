unsigned __int64 __fastcall etm_perf_add_symlink_cscfg(__int64 a1, __int64 *a2)
{
  unsigned __int64 result; // x0
  __int64 v4; // x21
  __int64 v5; // x19
  __int64 v7; // x0
  unsigned __int64 v8; // x20
  unsigned int v9; // w23
  __int64 v10; // x0

  if ( a2[8] )
    return 0;
  if ( etm_perf_up == 1 )
  {
    v4 = *a2;
    v5 = qword_11970;
    v7 = devm_kmalloc(a1, 40, 3520);
    if ( v7 && (v8 = v7, v9 = hashlen_string(0, v4), v10 = devm_kstrdup(a1, v4, 3264), (*(_QWORD *)v8 = v10) != 0) )
    {
      *(_WORD *)(v8 + 8) = 292;
      *(_QWORD *)(v8 + 32) = v9;
      LODWORD(result) = sysfs_add_file_to_group(v5, v8, "events");
      if ( (_DWORD)result )
        result = (int)result;
      else
        result = v8;
      a2[8] = result;
      if ( result <= 0xFFFFFFFFFFFFF000LL )
      {
        *(_QWORD *)(result + 16) = etm_perf_cscfg_event_show;
        return 0;
      }
    }
    else
    {
      result = -12;
    }
    a2[8] = 0;
  }
  else
  {
    a2[8] = 0;
    return -517;
  }
  return result;
}
