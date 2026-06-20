__int64 __fastcall update_reg_dump_table(__int64 a1, int a2)
{
  int v2; // w21
  __int64 v3; // x19
  unsigned int v5; // w23
  unsigned int v6; // w22
  __int64 v7; // x8
  bool v8; // cf
  __int64 v9; // x8
  unsigned int v10; // w20

  v2 = 2 * a2;
  v3 = *(_QWORD *)(a1 + 152);
  v5 = 2 * a2 + 6;
  v6 = 4 * v5;
  mutex_lock(v3);
  v7 = *(_QWORD *)(v3 + 56);
  if ( v5 >> 30 )
    v8 = 1;
  else
    v8 = v6 >= *(_DWORD *)(v7 + 8);
  if ( v8 )
  {
    v10 = -12;
  }
  else
  {
    *(_DWORD *)(v7 + 12) = a2;
    *(_DWORD *)(*(_QWORD *)(v3 + 56) + 16LL) = 0;
    *(_DWORD *)(*(_QWORD *)(v3 + 56) + 20LL) = 4;
    *(_DWORD *)(*(_QWORD *)(v3 + 56) + 24LL) = 0;
    *(_DWORD *)(*(_QWORD *)(v3 + 56) + 28LL) = v6;
    memset(**(void ***)(v3 + 56), 222, *(unsigned int *)(*(_QWORD *)(v3 + 56) + 8LL));
    v9 = **(_QWORD **)(v3 + 56);
    *(_QWORD *)v9 = 0x200C0FFEELL;
    *(_DWORD *)(v9 + 8) = v2 + 5;
    *(_DWORD *)(v9 + 12) = v6;
    memset((void *)(**(_QWORD **)(v3 + 56) + 16LL), 0, 4LL * (unsigned int)(v2 + 2));
    v10 = 0;
  }
  mutex_unlock(v3);
  return v10;
}
