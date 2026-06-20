__int64 __fastcall snapshot_freeze_obj_list(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v5; // x21
  __int64 v6; // x22
  int v7; // w23
  unsigned __int64 *v8; // x8
  unsigned __int64 v9; // x2
  __int64 v10; // x10
  unsigned __int64 v11; // x11
  __int64 v12; // x11
  unsigned int v19; // w9
  __int64 v20; // x0

  if ( *(int *)(a3 + 8) >= 1 )
  {
    v5 = result;
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = (unsigned __int64 *)(*(_QWORD *)a3 + 32 * v6);
      v9 = *v8;
      if ( objbufptr )
      {
        v10 = 0;
        while ( 1 )
        {
          if ( v10 == 448 )
            goto LABEL_22;
          v11 = objbuf[v10];
          if ( v11 <= v9 )
          {
            if ( (unsigned __int64)(v10 * 8 - 3576) < 0xFFFFFFFFFFFFF200LL )
              goto LABEL_21;
            if ( objbuf[v10 + 1] + v11 >= v8[1] + v9 )
            {
              if ( (unsigned __int64)(v10 * 8 - 3552) < 0xFFFFFFFFFFFFF200LL )
              {
LABEL_21:
                __break(1u);
LABEL_22:
                __break(0x5512u);
                v20 = MEMORY[0x71F1F64](result, a2, v9);
                return adreno_sysfs_store_u32(v20);
              }
              v12 = objbuf[v10 + 4];
              if ( *(_QWORD *)(v12 + 256) == a2 )
                break;
            }
          }
          v10 += 7;
          if ( 7LL * (unsigned int)objbufptr == v10 )
            goto LABEL_3;
        }
        _X8 = (unsigned int *)(v12 + 56);
        __asm { PRFM            #0x11, [X8] }
        do
          v19 = __ldxr(_X8);
        while ( __stxr(v19 & 0xFFFFEFFF, _X8) );
      }
      else
      {
LABEL_3:
        result = kgsl_snapshot_get_object(v5, a2);
        if ( (result & 0x80000000) != 0 )
        {
          if ( v7 >= 0 )
            v7 = result;
        }
        else
        {
          snapshot_frozen_objsize += (unsigned int)result;
        }
      }
      ++v6;
    }
    while ( v6 < *(int *)(a3 + 8) );
  }
  return result;
}
