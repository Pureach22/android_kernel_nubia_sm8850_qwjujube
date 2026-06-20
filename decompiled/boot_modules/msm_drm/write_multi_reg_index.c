__int64 __fastcall write_multi_reg_index(unsigned int *a1)
{
  int *v2; // x8
  unsigned int v3; // w9
  __int64 v4; // x8

  v2 = (int *)(*(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL));
  *v2 = 805306368;
  v3 = a1[5];
  *v2 = v3 & 0x3FFFFF | 0x30000000;
  if ( a1[1] == 0x80000000 )
    *v2 = v3 & 0x3FFFFF | 0x38000000;
  v2[1] = a1[11] >> 2;
  v4 = *a1;
  if ( (unsigned int)v4 >= 7 )
  {
    __break(0x5512u);
    return write_multi_lut_reg();
  }
  else
  {
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL) += ops_mem_size[v4];
    memcpy(
      (void *)(*(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL)),
      *((const void **)a1 + 4),
      a1[11]);
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL) += a1[11];
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 40LL) = 127;
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 44LL) |= 0x7Eu;
    if ( a1[1] == 0x80000000 )
      *(_DWORD *)(*((_QWORD *)a1 + 3) + 48LL) += a1[11] >> 2;
    return 0;
  }
}
