__int64 __fastcall simple_amp_read_print_registers(__int64 result, unsigned int *a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v5; // x21
  __int64 v6; // x2
  __int64 v7; // x3
  void *v8; // x0
  unsigned int v9; // w0
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v3 = a3;
    v5 = result;
    v10 = 0;
    do
    {
      v9 = regmap_read(v5, *a2, &v10);
      if ( v9 )
      {
        v6 = *a2;
        v7 = v9;
        v8 = &unk_CF69;
      }
      else
      {
        result = __ratelimit(&simple_amp_read_print_registers__rs, "simple_amp_read_print_registers");
        if ( !(_DWORD)result )
          goto LABEL_5;
        v6 = *a2;
        v7 = v10;
        v8 = &unk_CE09;
      }
      result = printk(v8, "simple_amp_read_print_registers", v6, v7);
LABEL_5:
      --v3;
      ++a2;
    }
    while ( v3 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
