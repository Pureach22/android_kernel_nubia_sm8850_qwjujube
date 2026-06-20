__int64 __fastcall ipclite_device_release(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  __int64 v10; // x20
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (ipclite_debug_level & 4) != 0 )
  {
    if ( (ipclite_debug_control & 1) != 0 )
    {
      v10 = a1;
      printk(&unk_1013B, "ipclite", "ipclite_device_release");
      a1 = v10;
      if ( (ipclite_debug_control & 4) == 0 )
        return kfree(a1);
      goto LABEL_4;
    }
    if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_4:
      v8 = a1;
      ipclite_inmem_log("APPS:%s:Releasing IPCLite device\n", (__int64)"INFO", a3, a4, a5, a6, a7, a8, vars0);
      a1 = v8;
    }
  }
  return kfree(a1);
}
