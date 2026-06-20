__int64 __fastcall of_register_swr_devices(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v6[5]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v7; // [xsp+30h] [xbp-20h]
  __int64 v8; // [xsp+38h] [xbp-18h]
  __int64 v9; // [xsp+40h] [xbp-10h]
  __int64 v10; // [xsp+48h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 744);
  if ( v2 )
  {
    result = of_get_next_available_child(v2, 0);
    if ( result )
    {
      v4 = result;
      do
      {
        v8 = 0;
        v9 = 0;
        v7 = 0;
        memset(v6, 0, sizeof(v6));
        v5 = 0;
        if ( (of_alias_from_compatible(v4, v6, 32) & 0x80000000) != 0 )
        {
          if ( (unsigned int)__ratelimit(&of_register_swr_devices__rs, "of_register_swr_devices") )
            dev_err(a1, "of_swr:modalias failure %s\n", *(_QWORD *)(v4 + 16));
        }
        else if ( (unsigned int)of_property_read_u64(v4, "reg", &v5) )
        {
          if ( (unsigned int)__ratelimit(&of_register_swr_devices__rs_8, "of_register_swr_devices") )
            dev_err(a1, "of_swr:invalid reg %s\n", *(_QWORD *)(v4 + 16));
        }
        else
        {
          v7 = v5;
          v8 = v4;
          if ( !swr_new_device(a1, (__int64)v6)
            && (unsigned int)__ratelimit(&of_register_swr_devices__rs_10, "of_register_swr_devices") )
          {
            dev_err(a1, "of_swr: Register failed %s\n", *(_QWORD *)(v4 + 16));
          }
        }
        result = of_get_next_available_child(*(_QWORD *)(a1 + 744), v4);
        v4 = result;
      }
      while ( result );
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
