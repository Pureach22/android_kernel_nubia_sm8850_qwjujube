__int64 __fastcall walt_cfs_dequeue_task(__int64 result, __int64 a2)
{
  __int64 v2; // x14
  _QWORD *v3; // x10
  char *v4; // x8
  char *v5; // x9
  __int64 v7; // x11
  char **v8; // x12
  __int64 v9; // x11
  __int64 v10; // x12

  if ( (_UNKNOWN *)a2 == &init_task )
    v3 = &vendor_data_pad;
  else
    v3 = (_QWORD *)(a2 + 5184);
  v4 = (char *)v3[36];
  v5 = (char *)(v3 + 36);
  if ( v4 == (char *)(v3 + 36) || v4 == nullptr )
  {
LABEL_13:
    if ( *(_DWORD *)(a2 + 48) )
      v3[40] = 0;
    return result;
  }
  v7 = *(unsigned int *)(result + 3632);
  if ( (unsigned int)v7 < 0x20 )
  {
    v8 = (char **)v3[37];
    v9 = *((_QWORD *)&_per_cpu_offset + v7);
    if ( *v8 == v5 && *((char **)v4 + 1) == v5 )
    {
      *((_QWORD *)v4 + 1) = v8;
      *v8 = v4;
    }
    else
    {
      result = _list_del_entry_valid_or_report(v3 + 36);
      a2 = v10;
    }
    v3[36] = v3 + 36;
    v3[37] = v5;
    *((_DWORD *)v3 + 82) = -1;
    --*(_DWORD *)&walt_rq[v9 + 584];
    goto LABEL_13;
  }
  __break(0x5512u);
  if ( (v2 & 0x1000000000LL) != 0 )
    JUMPOUT(0x51EC0);
  return walt_cfs_tick(result);
}
