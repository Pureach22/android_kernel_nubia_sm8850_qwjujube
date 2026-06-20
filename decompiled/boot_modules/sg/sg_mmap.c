__int64 __fastcall sg_mmap(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x19
  unsigned __int64 v6; // x21
  unsigned int v7; // w20
  _QWORD *v8; // x0
  __int64 v9; // x8
  __int64 v10; // x8

  result = 4294967290LL;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 32);
    if ( v4 )
    {
      if ( *(_QWORD *)(a2 + 80) )
      {
        return 4294967274LL;
      }
      else
      {
        v6 = *(_QWORD *)(a2 + 8) - *(_QWORD *)a2;
        mutex_lock(v4 + 56);
        if ( v6 <= *(unsigned int *)(v4 + 120) )
        {
          v8 = (_QWORD *)a2;
          *(_BYTE *)(v4 + 4908) = 1;
          v9 = *(_QWORD *)(a2 + 16);
          if ( (*(_QWORD *)(v9 + 136) & 1) == 0 )
          {
            __break(0x800u);
            v9 = *(_QWORD *)(a2 + 16);
          }
          if ( *(_DWORD *)(a2 + 40) != *(_DWORD *)(v9 + 224) )
          {
            _vma_start_write(a2);
            v8 = (_QWORD *)a2;
          }
          v10 = v8[4];
          v7 = 0;
          v8[12] = v4;
          v8[4] = v10 | 0x4044000;
          v8[9] = &sg_mmap_vm_ops;
        }
        else
        {
          v7 = -12;
        }
        mutex_unlock(v4 + 56);
        return v7;
      }
    }
    else
    {
      return 4294967290LL;
    }
  }
  return result;
}
