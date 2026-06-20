__int64 __fastcall temperature_counter_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w3
  int v14; // w21
  int v15; // w21
  int v16; // w21
  int v17; // w21
  int v18; // w21
  int v19; // w21
  int v20; // w21
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v21 = 0;
  LODWORD(result) = nvmem_device_read(*(_QWORD *)(v4 + 8), 124, 4, &v21);
  if ( (result & 0x80000000) == 0 )
  {
    v6 = *(_QWORD *)(v4 + 8);
    *(_DWORD *)(v4 + 48) = v21;
    LODWORD(result) = nvmem_device_read(v6, 120, 4, &v21);
    if ( (result & 0x80000000) == 0 )
    {
      v7 = *(_QWORD *)(v4 + 8);
      *(_DWORD *)(v4 + 52) = v21;
      LODWORD(result) = nvmem_device_read(v7, 116, 4, &v21);
      if ( (result & 0x80000000) == 0 )
      {
        v8 = *(_QWORD *)(v4 + 8);
        *(_DWORD *)(v4 + 56) = v21;
        LODWORD(result) = nvmem_device_read(v8, 112, 4, &v21);
        if ( (result & 0x80000000) == 0 )
        {
          v9 = *(_QWORD *)(v4 + 8);
          *(_DWORD *)(v4 + 60) = v21;
          LODWORD(result) = nvmem_device_read(v9, 108, 4, &v21);
          if ( (result & 0x80000000) == 0 )
          {
            v10 = *(_QWORD *)(v4 + 8);
            *(_DWORD *)(v4 + 64) = v21;
            LODWORD(result) = nvmem_device_read(v10, 104, 4, &v21);
            if ( (result & 0x80000000) == 0 )
            {
              v11 = *(_QWORD *)(v4 + 8);
              *(_DWORD *)(v4 + 68) = v21;
              LODWORD(result) = nvmem_device_read(v11, 100, 4, &v21);
              if ( (result & 0x80000000) == 0 )
              {
                v12 = *(_QWORD *)(v4 + 8);
                *(_DWORD *)(v4 + 72) = v21;
                LODWORD(result) = nvmem_device_read(v12, 96, 4, &v21);
                if ( (result & 0x80000000) == 0 )
                {
                  v13 = *(_DWORD *)(v4 + 48);
                  *(_DWORD *)(v4 + 76) = v21;
                  v14 = scnprintf(a3, 4096, "%u ", v13);
                  v15 = scnprintf(a3 + v14, 4096LL - v14, "%u ", *(_DWORD *)(v4 + 52)) + v14;
                  v16 = scnprintf(a3 + v15, 4096LL - v15, "%u ", *(_DWORD *)(v4 + 56)) + v15;
                  v17 = scnprintf(a3 + v16, 4096LL - v16, "%u ", *(_DWORD *)(v4 + 60)) + v16;
                  v18 = scnprintf(a3 + v17, 4096LL - v17, "%u ", *(_DWORD *)(v4 + 64)) + v17;
                  v19 = scnprintf(a3 + v18, 4096LL - v18, "%u ", *(_DWORD *)(v4 + 68)) + v18;
                  v20 = scnprintf(a3 + v19, 4096LL - v19, "%u ", *(_DWORD *)(v4 + 72)) + v19;
                  LODWORD(result) = scnprintf(a3 + v20, 4096LL - v20, "%u ", *(_DWORD *)(v4 + 76)) + v20;
                  *(_BYTE *)(a3 + (int)result - 1) = 10;
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
