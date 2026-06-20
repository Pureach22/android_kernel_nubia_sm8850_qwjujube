__int64 __fastcall write_block_lut_reg(unsigned int *a1)
{
  int *v1; // x9
  int v2; // w8
  __int64 v3; // x8
  __int64 v6; // x8

  v1 = (int *)(*(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL));
  *v1 = 1610612736;
  v2 = ((a1[12] & 1) << 16) | 0x60000000;
  *v1 = v2;
  *v1 = v2 | *((unsigned __int16 *)a1 + 26);
  LOBYTE(v2) = a1[14];
  v1[1] = (unsigned __int8)v2 << 16;
  v1[1] = a1[15] & 0x3FFF | ((unsigned __int8)v2 << 16);
  v3 = *a1;
  if ( (unsigned int)v3 >= 7 )
  {
    __break(0x5512u);
    JUMPOUT(0x19DC24);
  }
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
  v6 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL);
  *(_QWORD *)v6 = 0;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL) += 12;
  return 0;
}
