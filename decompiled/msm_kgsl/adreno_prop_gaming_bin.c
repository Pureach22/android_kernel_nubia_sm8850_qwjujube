__int64 __fastcall adreno_prop_gaming_bin(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x8
  unsigned __int64 v5; // x0
  __int64 result; // x0
  unsigned __int64 v7; // x22
  unsigned __int64 v8; // x21
  unsigned int v9; // w19
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[1396];
  v10[0] = 0;
  v5 = nvmem_cell_get(v4 + 16, "gaming_bin");
  if ( v5 <= 0xFFFFFFFFFFFFF000LL )
  {
    v7 = v5;
    v8 = nvmem_cell_read(v5, v10);
    nvmem_cell_put(v7);
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
    {
      v9 = copy_prop(a2, v8, v10[0]);
      kfree(v8);
      result = v9;
      goto LABEL_5;
    }
    dev_err(*a1, "failed to read gaming_bin nvmem cell\n");
  }
  result = 4294967274LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
