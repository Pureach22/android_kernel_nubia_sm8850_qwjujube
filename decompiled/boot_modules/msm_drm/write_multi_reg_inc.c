__int64 __fastcall write_multi_reg_inc(unsigned int *a1)
{
  _DWORD *v1; // x9
  int v2; // w8
  __int64 v3; // x8

  v1 = (_DWORD *)(*(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL));
  *v1 = 0x40000000;
  if ( a1[1] == 0x80000000 )
    v2 = 1207959552;
  else
    v2 = 0x40000000;
  *v1 = v2;
  *v1 = v2 & 0xFFC00000 | a1[5] & 0x3FFFFF;
  v1[1] = a1[11] >> 2;
  v3 = *a1;
  if ( (unsigned int)v3 >= 7 )
  {
    __break(0x5512u);
    return write_multi_reg_index();
  }
  else
  {
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL) += ops_mem_size[v3];
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
