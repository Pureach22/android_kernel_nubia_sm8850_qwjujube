__int64 __fastcall wcd938x_enable_micbias(__int64 a1, int a2, int a3)
{
  __int64 v5; // x22
  unsigned int v6; // w20
  __int64 v7; // x8
  int v8; // w9
  int v9; // w10
  __int64 v10; // x3
  __int64 result; // x0

  if ( a1 )
  {
    v5 = (unsigned int)(a2 - 1);
    v6 = dword_21DAC[a2 - 1];
    mutex_lock(a1 + 104);
    v7 = a1 + 72;
    v8 = *(_DWORD *)(a1 + 72 + 4LL * (unsigned int)v5);
    if ( a3 == 1 )
    {
      v9 = v8 - 1;
      if ( v8 >= 1 )
      {
        --v8;
        *(_DWORD *)(v7 + 4 * v5) = v9;
      }
      if ( v8 || *(_DWORD *)(a1 + 4 * v5 + 56) )
        return mutex_unlock(a1 + 104);
      v10 = 0;
    }
    else
    {
      *(_DWORD *)(v7 + 4 * v5) = v8 + 1;
      if ( v8 || *(_DWORD *)(a1 + 4 * v5 + 56) )
        return mutex_unlock(a1 + 104);
      v10 = 128;
    }
    regmap_update_bits_base(*(_QWORD *)(a1 + 32), v6, 192, v10, 0, 0, 0);
    return mutex_unlock(a1 + 104);
  }
  result = __ratelimit(&wcd938x_enable_micbias__rs, "wcd938x_enable_micbias");
  if ( (_DWORD)result )
    return printk(&unk_13868, "wcd938x_enable_micbias");
  return result;
}
