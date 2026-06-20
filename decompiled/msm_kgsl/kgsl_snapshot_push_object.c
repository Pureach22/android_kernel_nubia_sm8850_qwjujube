_QWORD *__fastcall kgsl_snapshot_push_object(_QWORD *result, __int64 a2, unsigned __int64 a3, unsigned __int64 a4)
{
  _QWORD *v4; // x19
  __int64 v5; // x8
  _QWORD *v6; // x11
  unsigned __int64 v7; // x9
  __int64 v8; // x10
  unsigned __int64 v9; // x12
  char *v10; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x8
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  __int64 v18; // x11
  unsigned __int64 *v19; // x10
  __int64 v20; // x8
  _QWORD *v21; // x19

  if ( a2 && a3 )
  {
    v4 = result;
    if ( objbufptr )
    {
      v5 = 0;
      while ( v5 != 3584 )
      {
        if ( *(_QWORD *)((char *)&objbuf + v5) == a3 )
        {
          if ( (unsigned __int64)(v5 - 3552) < 0xFFFFFFFFFFFFF200LL )
            goto LABEL_39;
          v6 = *(_QWORD **)((char *)&objbuf + v5 + 32);
          if ( v6[32] == a2 )
          {
            if ( (unsigned __int64)(v6 + 1) > 0xFFFFFFFFFFFFF000LL )
              return (_QWORD *)dev_err(*result, "snapshot: gpuaddr 0x%016llX size is less than requested\n", a3);
            v7 = 4 * a4;
            v8 = 4 * a4 <= 1 ? 1LL : 4 * a4;
            if ( __CFADD__(a3, v8) )
              return (_QWORD *)dev_err(*result, "snapshot: gpuaddr 0x%016llX size is less than requested\n", a3);
            v9 = v6[4];
            if ( v9 > a3 || v8 + a3 > v6[6] + v9 )
              return (_QWORD *)dev_err(*result, "snapshot: gpuaddr 0x%016llX size is less than requested\n", a3);
            if ( (unsigned __int64)(v5 - 3576) < 0xFFFFFFFFFFFFF200LL )
            {
LABEL_39:
              __break(1u);
              break;
            }
            v10 = (char *)&objbuf + v5;
            if ( *((_QWORD *)v10 + 1) > v7 )
              v7 = *((_QWORD *)v10 + 1);
            *((_QWORD *)v10 + 1) = v7;
            return result;
          }
        }
        v5 += 56;
        if ( 56LL * (unsigned int)objbufptr == v5 )
        {
          if ( objbufptr != 64 )
            goto LABEL_22;
          return (_QWORD *)dev_err(*result, "snapshot: too many snapshot objects\n");
        }
      }
LABEL_40:
      __break(0x5512u);
      return (_QWORD *)kgsl_mem_entry_put(result);
    }
LABEL_22:
    result = (_QWORD *)kgsl_sharedmem_find(a2, a3);
    if ( !result )
      return (_QWORD *)dev_err(*v4, "snapshot: Can't find entry for 0x%016llX\n", a3);
    v13 = result[4];
    v14 = result[6];
    v15 = v14 + v13;
    v16 = (v13 - a3 + v14) >> 2;
    if ( a3 + 4 * a4 <= v15 )
      v16 = a4;
    if ( (unsigned __int64)(result + 1) > 0xFFFFFFFFFFFFF000LL
      || ((v17 = 4 * v16, v17 <= 1) ? (v18 = 1) : (v18 = v17), __CFADD__(a3, v18) || v13 > a3 || v18 + a3 > v15) )
    {
      v20 = *v4;
      v21 = result;
      dev_err(v20, "snapshot: Mem entry 0x%016llX is too small\n", a3);
      return (_QWORD *)kgsl_mem_entry_put(v21);
    }
    if ( (unsigned int)objbufptr > 0x3F )
      goto LABEL_40;
    v19 = (unsigned __int64 *)((char *)&objbuf + 56 * (unsigned int)objbufptr++);
    *v19 = a3;
    v19[1] = v17;
    v19[4] = (unsigned __int64)result;
  }
  return result;
}
