__int64 __fastcall obj_malloc(__int64 a1, unsigned int *a2, __int64 *a3)
{
  unsigned __int64 v3; // x8
  unsigned int v4; // w19
  __int64 v5; // x20
  int v6; // w8
  int v7; // w9
  int v8; // w10
  unsigned __int64 StatusReg; // x9
  char v10; // w11
  unsigned __int64 *v11; // x8
  __int64 v12; // x8
  __int64 result; // x0
  __int64 *v14; // x21
  unsigned int *v15; // x22

  v3 = ((unsigned __int64)*a2 >> 5) & 0x1FF;
  if ( (unsigned int)v3 >= 0xFF )
  {
    __break(0x5512u);
LABEL_15:
    __break(0x800u);
    return alloc_zspage(a1, a2, a3);
  }
  v4 = a2[2];
  v5 = *((_QWORD *)a2 + 2);
  v6 = *(_DWORD *)(*(_QWORD *)(a1 + 8 * v3 + 8) + 200LL) * v4;
  v7 = v6 >> 12;
  if ( v6 >> 12 >= 1 )
  {
    while ( 1 )
    {
      v8 = **(_DWORD **)(v5 + 40);
      if ( (v8 & 0x3FC000) != 0x160000 )
        goto LABEL_15;
      if ( (v8 & 1) != 0 )
      {
        v5 = 0;
        if ( !--v7 )
          break;
      }
      else
      {
        v5 = *(_QWORD *)(v5 + 32);
        if ( !--v7 )
          break;
      }
    }
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  ++*(_DWORD *)(StatusReg + 3220);
  v10 = *(_BYTE *)a2;
  v11 = (unsigned __int64 *)((((v5 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                           + 8LL * (((unsigned int)v6 >> 3) & 0x1FF));
  a2[2] = *v11 >> 1;
  if ( (v10 & 1) != 0 )
    v11 = (unsigned __int64 *)(*((_QWORD *)a2 + 2) + 32LL);
  *v11 = (unsigned __int64)a3 | 1;
  --*(_DWORD *)(StatusReg + 3220);
  v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v12;
  if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
  {
    v14 = a3;
    v15 = a2;
    preempt_schedule(a1);
    a2 = v15;
    a3 = v14;
  }
  ++a2[1];
  result = (((v5 - -64LL * (memstart_addr >> 12)) << 18) + 0x5000000000000LL) | *(_QWORD *)&v4 & 0xFFFFFFLL;
  *a3 = result;
  return result;
}
