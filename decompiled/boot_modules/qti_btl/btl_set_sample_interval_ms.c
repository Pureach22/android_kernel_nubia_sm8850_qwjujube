__int64 __fastcall btl_set_sample_interval_ms(__int64 a1, int a2)
{
  __int64 v3; // x0
  unsigned __int16 v4; // w20
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  char v8; // w9
  char v9; // w8
  char v10[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v11[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v12[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 1;
  if ( (unsigned int)(a2 - 25501) <= 0xFFFF9CC6 )
  {
    dev_err(*(_QWORD *)a1, "Error, sample interval should be within [%u %u]\n", 100, 25500);
    result = 4294967274LL;
    goto LABEL_14;
  }
  v3 = *(_QWORD *)(a1 + 8);
  v4 = a2;
  v12[0] = 0;
  result = nvmem_device_write(v3, 74, 1, v12);
  if ( (result & 0x80000000) == 0 )
  {
    v6 = *(_QWORD *)(a1 + 8);
    v12[0] = 1;
    result = nvmem_device_write(v6, 229, 1, v12);
    if ( (result & 0x80000000) == 0 )
    {
      result = btl_reset_temp_counts(a1);
      if ( (result & 0x80000000) == 0 )
      {
        v7 = *(_QWORD *)(a1 + 8);
        v11[0] = v4 / 0x64u;
        result = nvmem_device_write(v7, 75, 1, v11);
        if ( (result & 0x80000000) == 0 )
        {
          v8 = *(_BYTE *)(a1 + 100);
          *(_BYTE *)(a1 + 16) = v11[0];
          if ( (v8 & 1) == 0 )
          {
            result = nvmem_device_write(*(_QWORD *)(a1 + 8), 72, 1, v10);
            if ( (result & 0x80000000) != 0 )
              goto LABEL_14;
            *(_BYTE *)(a1 + 100) = 1;
          }
          v9 = *(_BYTE *)(a1 + 80);
          v13[0] = 1;
          if ( (v9 & 2) != 0 )
          {
            result = nvmem_device_write(*(_QWORD *)(a1 + 8), 74, 1, v13);
            if ( (result & 0x80000000) == 0 )
              result = nvmem_device_write(*(_QWORD *)(a1 + 8), 229, 1, v13);
          }
          else
          {
            result = 0;
          }
        }
      }
    }
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
