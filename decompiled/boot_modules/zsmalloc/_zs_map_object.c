__int64 __fastcall zs_map_object(__int64 lock, __int64 *a2, int a3, _BYTE *a4)
{
  unsigned __int64 StatusReg; // x23
  __int64 v5; // x21
  __int64 v9; // x24
  __int64 v10; // x25
  _DWORD *v11; // x22
  unsigned __int64 v12; // x8
  __int64 v13; // x8
  int v14; // w11
  char *v15; // x24
  __int64 v16; // x9
  __int64 v17; // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x8
  int v20; // w10
  __int64 v21; // x26
  char *v22; // x20
  size_t v23; // x21
  int v24; // w27
  void *v25; // x0
  __int64 v26; // x8
  void *v27; // x0
  __int64 v28; // x8

  *a4 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    goto LABEL_19;
  v5 = lock;
  lock = raw_read_lock(lock + 2120);
  v9 = *a2;
  v10 = (((unsigned __int64)*a2 >> 18) & 0x3FFFFFFFFFC0LL) - ((__int64)memstart_addr >> 12 << 6) - 0x140000000LL;
  v11 = *(_DWORD **)((((unsigned __int64)*a2 >> 18) & 0x3FFFFFFFFFC0LL)
                   - ((__int64)memstart_addr >> 12 << 6)
                   - 0x13FFFFFD8LL);
  if ( (*v11 & 0x3FC000) != 0x160000 )
  {
LABEL_20:
    __break(0x800u);
LABEL_21:
    __break(0x800u);
    goto LABEL_22;
  }
  raw_read_lock(v11 + 12);
  lock = raw_read_unlock(v5 + 2120);
  v12 = ((unsigned __int64)(unsigned int)*v11 >> 5) & 0x1FF;
  if ( (unsigned int)v12 >= 0xFF )
  {
    __break(0x5512u);
LABEL_19:
    __break(0x800u);
    goto LABEL_20;
  }
  v13 = *(_QWORD *)(v5 + 8 * v12 + 8);
  v14 = *(_DWORD *)(v13 + 200) * v9;
  ++*(_DWORD *)(StatusReg + 16);
  v15 = (char *)&zs_map_area + _ReadStatusReg(TPIDR_EL1);
  *((_DWORD *)v15 + 4) = a3;
  v16 = *(int *)(v13 + 200);
  v17 = v14 & 0xFFF;
  if ( (unsigned __int64)(v16 + v17) <= 0x1000 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    ++*(_DWORD *)(StatusReg + 3220);
    v18 = ((v10 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL;
    *((_QWORD *)v15 + 1) = v18;
    v19 = v18 + v17;
    return v19 + (~(8 * *(_BYTE *)v11) & 8);
  }
  v20 = **(_DWORD **)(v10 + 40);
  if ( (v20 & 0x3FC000) == 0x160000 )
  {
    if ( (v20 & 1) == 0 )
    {
      v21 = *(_QWORD *)(v10 + 32);
      if ( v21 )
      {
        v22 = *(char **)v15;
        ++*(_DWORD *)(StatusReg + 3220);
        if ( *((_DWORD *)v15 + 4) != 2 )
        {
          ++*(_DWORD *)(StatusReg + 16);
          ++*(_DWORD *)(StatusReg + 3220);
          v23 = (unsigned int)(4096 - v17);
          v24 = v16 - v23;
          v25 = memcpy(
                  v22,
                  (const void *)((((v10 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + v17),
                  v23);
          --*(_DWORD *)(StatusReg + 3220);
          v26 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v26;
          if ( !v26 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule(v25);
          ++*(_DWORD *)(StatusReg + 16);
          ++*(_DWORD *)(StatusReg + 3220);
          v27 = memcpy(
                  &v22[v23],
                  (const void *)(((v21 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL),
                  v24);
          --*(_DWORD *)(StatusReg + 3220);
          v28 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v28;
          if ( !v28 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule(v27);
        }
        v19 = *(_QWORD *)v15;
        *a4 = 1;
        return v19 + (~(8 * *(_BYTE *)v11) & 8);
      }
    }
    goto LABEL_21;
  }
LABEL_22:
  __break(0x800u);
  return zs_map_object(lock);
}
