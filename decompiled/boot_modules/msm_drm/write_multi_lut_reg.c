__int64 __fastcall write_multi_lut_reg(unsigned int *a1)
{
  int *v2; // x8
  unsigned int v3; // w9
  int v4; // w9
  unsigned int v5; // w9
  __int64 v6; // x8

  v2 = (int *)(*(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL));
  *v2 = 1342177280;
  v3 = a1[5];
  *v2 = v3 & 0x3FFFFF | 0x50000000;
  if ( a1[1] == 0x80000000 )
    *v2 = v3 & 0x3FFFFF | 0x58000000;
  v4 = (a1[4] == 0) << 31;
  v2[1] = v4;
  v5 = v4 & 0xFFF0FFFF | ((a1[3] & 0xF) << 16);
  v2[1] = v5;
  v2[1] = v5 & 0xFFFFC000 | ((unsigned __int16)a1[11] >> 2);
  *(_DWORD *)(*((_QWORD *)a1 + 3) + 40LL) = 126;
  v6 = *a1;
  if ( (unsigned int)v6 >= 7 )
  {
    __break(0x5512u);
    return write_single_modify();
  }
  else
  {
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL) += ops_mem_size[v6];
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
