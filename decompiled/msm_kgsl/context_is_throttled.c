__int64 __fastcall context_is_throttled(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned int v6; // w8
  const char *v7; // x2
  __int64 v8; // x8
  __int64 v9; // x8
  int v10; // w3

  v4 = ktime_get(a1);
  if ( v4 - *(_QWORD *)(a2 + 264) < 2001000000 )
  {
    v6 = *(_DWORD *)(a2 + 256) + 1;
    *(_DWORD *)(a2 + 256) = v6;
    if ( v6 >= 4 )
    {
      if ( a2 )
      {
        v8 = *(_QWORD *)(a2 + 24);
        if ( v8 )
          v7 = (const char *)(v8 + 16);
        else
          v7 = "unknown";
      }
      else
      {
        v7 = "unknown";
        v8 = 0x183560000F4F68LL;
      }
      v9 = *(_QWORD *)(v8 + 8);
      if ( v9 )
        v10 = *(_DWORD *)(v9 + 112);
      else
        v10 = 0;
      dev_err(*a1, "%s[%d]: gpu fault threshold exceeded %d faults in %d msecs\n", v7, v10, 3, 2000);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_QWORD *)(a2 + 264) = ktime_get(v4);
    *(_DWORD *)(a2 + 256) = 1;
    return 0;
  }
}
