__int64 __fastcall hw_fence_ssr_cleanup_table(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x30
  __int64 v4; // x20
  int v8; // w8
  unsigned __int64 v9; // x25
  _DWORD *v10; // x26
  __int64 v11; // x2
  __int64 result; // x0
  unsigned int v13; // w19

  v4 = v3;
  if ( a1 && a2 )
  {
    if ( a3 )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = v8;
        if ( a3 <= (unsigned __int64)v8 )
          break;
        v10 = (_DWORD *)(a2 + ((__int64)v8 << 7));
        if ( *v10 )
          goto LABEL_8;
LABEL_5:
        v8 = v9 + 1;
        if ( a3 == (_DWORD)v9 + 1 )
          goto LABEL_13;
      }
      printk(&unk_23ADB, "_get_hw_fence", 1135, v4, v8);
      v10 = nullptr;
LABEL_8:
      if ( v10[8] != -2 && signal_fence_if_unsignaled(a1, (__int64)v10, v9, 1u, 0) )
      {
        v11 = (unsigned int)v10[29];
        if ( (_DWORD)v11 )
          hw_fence_interop_signal_synx_fence(a1, 1, v11, 1);
      }
      goto LABEL_5;
    }
LABEL_13:
    result = hw_fence_interop_notify_recover(a1);
    if ( (_DWORD)result )
    {
      v13 = result;
      printk(&unk_231A8, "hw_fence_ssr_cleanup_table", 2860, v4, (unsigned int)result);
      return v13;
    }
  }
  else
  {
    printk(&unk_287A7, "hw_fence_ssr_cleanup_table", 2840, v3, a1);
    return 4294967274LL;
  }
  return result;
}
