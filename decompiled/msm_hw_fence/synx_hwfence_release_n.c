__int64 __fastcall synx_hwfence_release_n(unsigned int **a1, int *a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x20
  __int64 v8; // x4
  unsigned __int64 v9; // x4
  unsigned int v10; // w5
  int v11; // w8
  unsigned int v12; // w23
  __int64 v13; // x25
  unsigned int v14; // w0

  v5 = v4;
  if ( !a1
    || (unsigned __int64)a1 > 0xFFFFFFFFFFFFF000LL
    || (unsigned int)(*(_DWORD *)a1 - 1024) > 0xBFF
    || !a2
    || (unsigned __int64)a2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_26E16, "synx_hwfence_release_n", 339, v4, a1);
    return (unsigned int)-22;
  }
  v8 = (unsigned int)*a2;
  if ( (_DWORD)v8 == 1 )
  {
    v12 = synx_hwfence_release(a1, a2[2], a3, a4, v8);
    a2[3] = v12;
    return v12;
  }
  if ( (_DWORD)v8 != 2 )
  {
    printk(&unk_25840, "synx_hwfence_release_n", 364, v4, v8);
    return (unsigned int)-22;
  }
  v9 = *((_QWORD *)a2 + 1);
  v10 = a2[4];
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL || !v10 || v10 >= *(_DWORD *)(hw_fence_drv_data + 80) )
  {
    printk(&unk_28F33, "synx_hwfence_release_n", 348, v4, v9);
    return (unsigned int)-22;
  }
  v11 = 0;
  v12 = 0;
  do
  {
    v13 = v11;
    v14 = synx_hwfence_release(a1, *(_DWORD *)(*((_QWORD *)a2 + 1) + 8LL * v11), a3, a4, v9);
    if ( v14 )
    {
      v12 = v14;
      printk(&unk_23D46, "synx_hwfence_release_n", 355, v5, (unsigned int)v13);
      v14 = v12;
    }
    *(_DWORD *)(*((_QWORD *)a2 + 1) + 8 * v13 + 4) = v14;
    v11 = v13 + 1;
  }
  while ( (int)v13 + 1 < (unsigned int)a2[4] );
  return v12;
}
