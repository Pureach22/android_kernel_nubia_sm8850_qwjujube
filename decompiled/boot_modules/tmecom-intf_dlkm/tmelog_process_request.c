__int64 __fastcall tmelog_process_request(int a1, int a2, _DWORD *a3, __int64 a4)
{
  _DWORD *v7; // x19
  unsigned int *v8; // x0
  __int64 v9; // x3
  unsigned int *v10; // x23
  unsigned int v11; // w0
  unsigned int v12; // w21
  __int64 v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  if ( a1 && a3 )
  {
    v7 = (_DWORD *)_kmalloc_cache_noprof(MEMORY[0x7D28], 3520, 12);
    v8 = (unsigned int *)_kmalloc_cache_noprof(MEMORY[0x7D28], 3520, 12);
    v10 = v8;
    if ( v7 && v8 )
    {
      *v7 = 1209532889;
      v7[1] = a2;
      v7[2] = a1;
      *v8 = -1;
      v11 = tmecom_process_request(v7, 0xCu, v8, v14);
      if ( v11 )
      {
        v12 = v11;
        printk(&unk_686A, "tmelog_process_request", 63, v11);
      }
      else if ( v14[0] == 12 )
      {
        v12 = *v10;
        *a3 = v10[1];
      }
      else
      {
        printk(&unk_6930, "tmelog_process_request", 69, v14[0]);
        v12 = -74;
      }
    }
    else
    {
      printk(&unk_68B5, "tmelog_process_request", 47, v9);
      v12 = -12;
    }
    kfree(v7);
    kfree(v10);
  }
  else
  {
    printk(&unk_698A, "tmelog_process_request", 40, a4);
    v12 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
