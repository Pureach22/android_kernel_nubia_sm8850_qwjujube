__int64 __fastcall coresight_init_driver(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w0
  __int64 result; // x0
  unsigned int v8; // w20
  unsigned int v9; // w21

  v6 = _amba_driver_register(a2, &_this_module);
  if ( v6 )
  {
    v8 = v6;
    printk(&unk_12922, a1);
    return v8;
  }
  else
  {
    result = _platform_driver_register(a3, &_this_module);
    if ( (_DWORD)result )
    {
      v9 = result;
      printk(&unk_1241A, a1);
      amba_driver_unregister(a2);
      return v9;
    }
  }
  return result;
}
