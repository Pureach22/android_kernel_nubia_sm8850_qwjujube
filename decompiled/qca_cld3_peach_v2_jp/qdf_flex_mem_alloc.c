void *__fastcall qdf_flex_mem_alloc(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  int v4; // w9
  int v5; // w10
  size_t v6; // x1
  void *v7; // x20
  __int64 v8; // x8
  __int64 v9; // x0

  if ( a1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 24);
    }
    else
    {
      raw_spin_lock_bh(a1 + 24);
      *(_QWORD *)(a1 + 32) |= 1uLL;
    }
    v3 = a1;
    while ( 1 )
    {
      v3 = *(_QWORD *)v3;
      if ( v3 == a1 )
        break;
      v4 = *(_DWORD *)(v3 + 20);
      if ( v4 != -1 )
      {
        v5 = __clz(__rbit64((unsigned int)~v4));
        *(_DWORD *)(v3 + 20) = (1 << v5) ^ v4;
        v6 = *(unsigned __int16 *)(a1 + 42);
        v7 = (void *)(*(_QWORD *)(v3 + 24) + (unsigned int)(v6 * v5));
        qdf_mem_set(v7, v6, 0);
        v8 = *(_QWORD *)(a1 + 32);
        if ( (v8 & 1) != 0 )
        {
LABEL_17:
          *(_QWORD *)(a1 + 32) = v8 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 24);
          return v7;
        }
LABEL_14:
        raw_spin_unlock(a1 + 24);
        return v7;
      }
    }
    v9 = qdf_flex_mem_seg_alloc(a1);
    if ( v9 )
    {
      v7 = *(void **)(v9 + 24);
      *(_DWORD *)(v9 + 20) = 1;
      v8 = *(_QWORD *)(a1 + 32);
      if ( (v8 & 1) != 0 )
        goto LABEL_17;
    }
    else
    {
      v7 = nullptr;
      v8 = *(_QWORD *)(a1 + 32);
      if ( (v8 & 1) != 0 )
        goto LABEL_17;
    }
    goto LABEL_14;
  }
  return nullptr;
}
