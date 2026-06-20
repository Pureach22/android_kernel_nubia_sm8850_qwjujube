__int64 __fastcall hw_fence_process_fence(__int64 a1, unsigned int *a2, _QWORD *a3, unsigned __int64 *a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v9; // x4
  __int64 result; // x0
  __int64 v11; // x30
  unsigned int v12; // w19

  v6 = v5;
  if ( a1 && a2 && a3 )
  {
    v9 = a3[6];
    if ( (v9 & 0x80000000) != 0 )
    {
      result = hw_fence_register_wait_client(a1, a3, a2, a3[4], a3[5], a4, a5);
      if ( (_DWORD)result )
      {
        v11 = v6;
        v12 = result;
        printk(&unk_2A2A6, "hw_fence_process_fence", 2264, v11, *a2);
        return v12;
      }
    }
    else
    {
      printk(&unk_217A2, "hw_fence_process_fence", 2257, v5, v9);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_2728B, "hw_fence_process_fence", 2252, v5, a5);
    return 4294967274LL;
  }
  return result;
}
