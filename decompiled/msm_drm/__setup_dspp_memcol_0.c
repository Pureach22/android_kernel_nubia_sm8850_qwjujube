__int64 __fastcall _setup_dspp_memcol_0(__int64 a1, int a2, unsigned int *a3)
{
  char v5; // w24
  unsigned int v7; // w23
  int v8; // w23
  int v9; // w23
  int v10; // w0

  v5 = 4 * a2;
  v7 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 164LL) + 20 * a2;
  sde_reg_write(a1, v7, a3[2], "addr");
  sde_reg_write(a1, v7 + 4, a3[3], "addr");
  sde_reg_write(a1, v7 + 8, a3[8], "addr");
  sde_reg_write(a1, v7 + 12, a3[9], "addr");
  sde_reg_write(a1, v7 + 16, a3[10], "addr");
  v8 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 164LL) + 8 * a2;
  sde_reg_write(a1, v8 + 60, a3[4], "addr");
  sde_reg_write(a1, v8 + 64, a3[5], "addr");
  v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 128LL);
  v10 = sde_reg_read(a1, v9 + 64);
  return sde_reg_write(
           a1,
           v9 + 64,
           v10 & ~(unsigned int)(15LL << v5)
         | ((unsigned __int64)(a3[7] & 3) << ((4 * a2) | 2u))
         | ((unsigned __int64)(a3[6] & 3) << v5),
           "addr");
}
