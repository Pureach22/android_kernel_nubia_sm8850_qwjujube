__int64 __fastcall walt_cfs_tick(__int64 result)
{
  __int64 v1; // x8
  char *v2; // x10
  __int64 v3; // x20
  __int64 v4; // x19
  _QWORD *v5; // x21
  char *v6; // x8
  char *v7; // x21
  char **v8; // x20
  int v9; // w22

  v1 = *(unsigned int *)(result + 3632);
  if ( (unsigned int)v1 >= 0x20 )
  {
    __break(0x5512u);
    JUMPOUT(0x5119C);
  }
  if ( (walt_disabled & 1) == 0 )
  {
    v2 = *(char **)(result + 3344);
    v3 = *((_QWORD *)&_per_cpu_offset + v1);
    v4 = result;
    if ( v2 == (char *)&init_task )
      v5 = &vendor_data_pad;
    else
      v5 = v2 + 5184;
    raw_spin_lock(result);
    v6 = (char *)v5[36];
    if ( v6 )
    {
      v7 = (char *)(v5 + 36);
      if ( v6 != v7 )
      {
        v8 = (char **)&walt_rq[v3];
        v9 = *((unsigned __int8 *)v8 + 608);
        ((void (__fastcall *)(__int64, _QWORD))walt_cfs_account_mvp_runtime)(v4, *(_QWORD *)(v4 + 3344));
        if ( (v9 != *((unsigned __int8 *)v8 + 608) || v8[71] != v7) && *(_DWORD *)(v4 + 532) >= 2u )
          resched_curr(v4);
      }
    }
    return raw_spin_unlock(v4);
  }
  return result;
}
