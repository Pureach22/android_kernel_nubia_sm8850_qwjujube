__int64 __fastcall sde_vbif_init_memtypes(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        char a7)
{
  __int64 v7; // x8
  __int64 v8; // x19
  unsigned int v9; // w8
  unsigned int v10; // w8
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 v13; // x8
  unsigned __int64 v14; // x21
  unsigned int v15; // w9
  _DWORD *v16; // x9
  __int64 v17; // x2
  __int64 v18; // x19
  __int64 v19; // x8
  __int64 v20; // x8
  unsigned __int64 v21; // x20
  unsigned int v22; // w9
  _DWORD *v23; // x9
  __int64 v24; // x2

  if ( !result )
    return printk(&unk_215A31, "sde_vbif_init_memtypes");
  v7 = *(_QWORD *)(result + 152);
  v8 = result;
  if ( (*(_QWORD *)(v7 + 22008) & 0x100000000LL) != 0 && v7 )
  {
    mutex_lock(result + 3696);
    if ( (*(_QWORD *)(*(_QWORD *)(v8 + 152) + 22008LL) & 0x400000000LL) != 0
      && *(_DWORD *)(v8 + 3664) == 1
      && (v9 = *(_DWORD *)(v8 + 3656), v9 <= 6)
      && ((1 << v9) & 0x64) != 0
      || (v10 = *(_DWORD *)(v8 + 3656), v10 <= 4) && ((1 << v10) & 0x1A) != 0 )
    {
      result = mutex_unlock(v8 + 3696);
      if ( (_drm_debug & 4) != 0 )
        return _drm_dev_dbg(0, 0, 0, "vbif operations not permitted\n");
      return result;
    }
    result = mutex_unlock(v8 + 3696);
  }
  v11 = *(_QWORD *)(v8 + 3512);
  if ( v11 && *(_QWORD *)(v11 + 40) )
  {
    v12 = *(unsigned int *)(v11 + 28);
    if ( (unsigned int)v12 > 2 )
      goto LABEL_39;
    if ( *(_QWORD *)(v11 + 216 + 8 * v12) )
    {
      mutex_lock(v11 + 288);
      v13 = *(_QWORD *)(v11 + 40);
      if ( *(_DWORD *)(v13 + 208) )
      {
        v14 = 0;
        do
        {
          v15 = *(_DWORD *)(v11 + 28);
          if ( v14 > 0xF || v15 > 2 )
            goto LABEL_39;
          v16 = *(_DWORD **)(v11 + 216 + 8LL * v15);
          v17 = *(unsigned int *)(v13 + 4 * v14 + 212);
          if ( *(v16 - 1) != -1288109875 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v16)(v11, (unsigned int)v14, v17);
          v13 = *(_QWORD *)(v11 + 40);
        }
        while ( ++v14 < *(unsigned int *)(v13 + 208) );
      }
      result = mutex_unlock(v11 + 288);
    }
  }
  v18 = *(_QWORD *)(v8 + 3520);
  if ( v18 && *(_QWORD *)(v18 + 40) )
  {
    v19 = *(unsigned int *)(v18 + 28);
    if ( (unsigned int)v19 <= 2 )
    {
      if ( !*(_QWORD *)(v18 + 216 + 8 * v19) )
        return result;
      mutex_lock(v18 + 288);
      v20 = *(_QWORD *)(v18 + 40);
      if ( !*(_DWORD *)(v20 + 208) )
        return mutex_unlock(v18 + 288);
      v21 = 0;
      while ( 1 )
      {
        v22 = *(_DWORD *)(v18 + 28);
        if ( v21 > 0xF || v22 > 2 )
          break;
        v23 = *(_DWORD **)(v18 + 216 + 8LL * v22);
        v24 = *(unsigned int *)(v20 + 4 * v21 + 212);
        if ( *(v23 - 1) != -1288109875 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v23)(v18, (unsigned int)v21, v24);
        v20 = *(_QWORD *)(v18 + 40);
        if ( ++v21 >= *(unsigned int *)(v20 + 208) )
          return mutex_unlock(v18 + 288);
      }
    }
LABEL_39:
    __break(0x5512u);
    if ( (a7 & 0x10) == 0 )
      JUMPOUT(0x13EC00);
    JUMPOUT(0x13B92C);
  }
  return result;
}
