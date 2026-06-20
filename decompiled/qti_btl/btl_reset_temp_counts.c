__int64 __fastcall btl_reset_temp_counts(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v6 = 0;
  result = nvmem_device_write(v2, 92, 2, &v6);
  if ( (result & 0x80000000) == 0 )
  {
    v4 = *(_QWORD *)(a1 + 8);
    v6 = 0xFFFF;
    result = nvmem_device_write(v4, 94, 2, &v6);
    if ( (result & 0x80000000) == 0 )
    {
      v5 = *(_QWORD *)(a1 + 8);
      v6 = 0;
      result = nvmem_device_write(v5, 124, 4, &v6);
      if ( (result & 0x80000000) == 0 )
      {
        result = nvmem_device_write(*(_QWORD *)(a1 + 8), 120, 4, &v6);
        if ( (result & 0x80000000) == 0 )
        {
          result = nvmem_device_write(*(_QWORD *)(a1 + 8), 116, 4, &v6);
          if ( (result & 0x80000000) == 0 )
          {
            result = nvmem_device_write(*(_QWORD *)(a1 + 8), 112, 4, &v6);
            if ( (result & 0x80000000) == 0 )
            {
              result = nvmem_device_write(*(_QWORD *)(a1 + 8), 108, 4, &v6);
              if ( (result & 0x80000000) == 0 )
              {
                result = nvmem_device_write(*(_QWORD *)(a1 + 8), 104, 4, &v6);
                if ( (result & 0x80000000) == 0 )
                {
                  result = nvmem_device_write(*(_QWORD *)(a1 + 8), 100, 4, &v6);
                  if ( (result & 0x80000000) == 0 )
                    result = nvmem_device_write(*(_QWORD *)(a1 + 8), 96, 4, &v6);
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
