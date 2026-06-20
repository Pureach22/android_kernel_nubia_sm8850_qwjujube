__int64 __fastcall write_single_reg(unsigned int *a1)
{
  int *v1; // x8
  unsigned int v2; // w9
  __int64 v3; // x8
  __int64 v4; // x8

  v1 = (int *)(*(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL));
  *v1 = 0x10000000;
  v2 = a1[5];
  *v1 = v2 & 0x3FFFFF | 0x10000000;
  if ( a1[1] == 0x80000000 )
  {
    *v1 = v2 & 0x3FFFFF | 0x18000000;
    ++*(_DWORD *)(*((_QWORD *)a1 + 3) + 48LL);
  }
  v1[1] = **((_DWORD **)a1 + 4);
  v3 = *a1;
  if ( (unsigned int)v3 >= 7 )
  {
    __break(0x5512u);
    return write_multi_reg_inc();
  }
  else
  {
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL) += ops_mem_size[v3];
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 44LL) |= 0x7Eu;
    v4 = *((_QWORD *)a1 + 3);
    *(_DWORD *)(v4 + 40) = 127;
    return 0;
  }
}
