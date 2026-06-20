__int64 __fastcall clk_regera_pll_configure(unsigned int *a1, __int64 a2, unsigned int *a3)
{
  __int64 result; // x0
  __int64 v7; // x2
  __int64 v8; // x2
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x2
  __int64 v12; // x2
  __int64 v13; // x2
  __int64 v14; // x2
  __int64 v15; // x2
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  if ( a3 )
  {
    result = regmap_read(a2, *a1, &v16);
    if ( !(_DWORD)result )
    {
      if ( v16 < 0 )
      {
        printk(&unk_2941E);
      }
      else
      {
        v7 = a3[3];
        if ( (_DWORD)v7 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 3LL), v7);
        v8 = *a3;
        if ( (_DWORD)v8 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 1LL), v8);
        v9 = a3[5];
        if ( (_DWORD)v9 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 8LL), v9);
        v10 = a3[6];
        if ( (_DWORD)v10 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 9LL), v10);
        v11 = a3[7];
        if ( (_DWORD)v11 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 10LL), v11);
        v12 = a3[9];
        if ( (_DWORD)v12 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 5LL), v12);
        v13 = a3[12];
        if ( (_DWORD)v13 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 12LL), v13);
        v14 = a3[14];
        if ( (_DWORD)v14 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 13LL), v14);
        v15 = a3[16];
        if ( (_DWORD)v15 )
          regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 14LL), v15);
        regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), 0);
      }
      result = 0;
    }
  }
  else
  {
    printk(&unk_2908E);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
