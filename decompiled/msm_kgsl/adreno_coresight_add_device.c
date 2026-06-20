unsigned __int64 __fastcall adreno_coresight_add_device(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 result; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x23
  unsigned __int64 v10; // x22
  __int64 v11; // x9
  __int64 v12; // x8
  _QWORD v13[2]; // [xsp+8h] [xbp-58h] BYREF
  void *v14; // [xsp+18h] [xbp-48h]
  unsigned __int64 platform_data; // [xsp+20h] [xbp-40h]
  __int64 v16; // [xsp+28h] [xbp-38h]
  __int64 v17; // [xsp+30h] [xbp-30h]
  _QWORD v18[5]; // [xsp+38h] [xbp-28h] BYREF

  v18[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = of_find_compatible_node(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL), 0, a2);
  if ( result )
  {
    v8 = *(_QWORD *)(a1 + 20736);
    if ( v8 && !*(_QWORD *)(v8 + 24) )
      *(_QWORD *)(v8 + 24) = &funnel_gfx_ops;
    v9 = result;
    result = of_find_device_by_node();
    if ( result )
    {
      v10 = result;
      memset(v18, 0, 32);
      v16 = 0;
      v17 = 0;
      v14 = nullptr;
      platform_data = 0;
      v13[0] = 0;
      v13[1] = 0;
      result = of_property_read_string(v9, "coresight-name", v18);
      if ( !(_DWORD)result )
      {
        platform_data = coresight_get_platform_data(v10 + 16);
        result = platform_device_put(v10);
        if ( platform_data <= 0xFFFFFFFFFFFFF000LL )
        {
          v11 = *(_QWORD *)(a1 + 11168);
          v13[0] = 0x200000003LL;
          v12 = *(_QWORD *)(a3 + 16);
          v14 = &adreno_coresight_ops;
          v16 = v11 + 16;
          v17 = v12;
          *(_DWORD *)(a4 + 28) = 0;
          *(_QWORD *)(a4 + 16) = a1;
          result = coresight_register(v13);
          *(_QWORD *)a4 = result;
          *(_QWORD *)(a4 + 8) = a3;
          if ( result )
          {
            if ( result <= 0xFFFFFFFFFFFFF000LL )
              *(_QWORD *)(result + 208) = a4;
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
