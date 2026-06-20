__int64 __fastcall cam_flash_pmic_flush_request(__int64 a1, int a2, __int64 a3)
{
  _BYTE *v3; // x21
  __int64 v4; // x8
  __int64 v5; // x19
  const char *v6; // x5
  __int64 v7; // x4
  __int64 v8; // x22
  char v9; // w9
  __int64 v10; // x25
  __int64 v11; // x6
  __int64 v12; // x26
  unsigned int v13; // w8
  unsigned int v14; // w9
  unsigned int v15; // w8

  if ( !a1 )
  {
    v6 = "Device data is NULL";
    v7 = 236;
    goto LABEL_34;
  }
  v3 = (_BYTE *)(a1 + 4096);
  if ( a2 )
  {
    if ( a2 == 1 && a3 )
    {
      v4 = a1 + 56 * (a3 & 0x1F);
      v5 = v4 + 3696;
      if ( *(_BYTE *)(v4 + 3726) == 1 )
      {
        if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x1000,
            4,
            "cam_flash_pmic_flush_request",
            274,
            "FLASH_REQ: Turn off the flash for req %llu",
            *(_QWORD *)(v4 + 3704));
        *(_QWORD *)(v5 + 8) = 0;
        *(_BYTE *)v5 = 0;
        *(_DWORD *)(v5 + 16) = 0;
        *(_QWORD *)(v5 + 32) = 0;
        goto LABEL_42;
      }
      v15 = 0;
      *(_QWORD *)(v5 + 8) = 0;
      *(_BYTE *)v5 = 0;
      *(_DWORD *)(v5 + 16) = 0;
      *(_QWORD *)(v5 + 32) = 0;
      return v15;
    }
    if ( a2 == 1 && !a3 )
    {
      v14 = *(unsigned __int8 *)(a1 + 5508);
      v15 = 0;
      if ( v14 > 0xD )
      {
        if ( v14 != 14 && v14 != 16 )
          return v15;
      }
      else
      {
        if ( v14 == 10 )
        {
          v15 = 0;
          *(_BYTE *)(a1 + 6104) = 0;
          return v15;
        }
        if ( v14 != 12 )
          return v15;
      }
      v15 = 0;
      *(_BYTE *)(a1 + 5488) = 0;
      *(_DWORD *)(a1 + 5504) = 0;
      *(_DWORD *)(a1 + 5512) = 0;
      *(_WORD *)(a1 + 5516) = 0;
      *(_QWORD *)(a1 + 5520) = 0;
      return v15;
    }
    v6 = "Invalid arguments";
    v7 = 287;
LABEL_34:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_pmic_flush_request",
      v7,
      v6);
    return (unsigned int)-22;
  }
  v8 = 0;
  v9 = 0;
  do
  {
    v10 = a1 + v8;
    if ( *(_BYTE *)(a1 + v8 + 3726) == 1 )
    {
      v11 = *(_QWORD *)(v10 + 3704);
      if ( v11 )
      {
        if ( *(_BYTE *)(v10 + 3696) == 1 )
        {
          v9 = 1;
          if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
          {
            v12 = a1;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x1000,
              4,
              "cam_flash_pmic_flush_request",
              252,
              "FLASH_ALL: Turn off the flash for req %llu",
              v11);
            a1 = v12;
            v9 = 1;
          }
        }
      }
    }
    v8 += 56;
    *(_QWORD *)(v10 + 3704) = 0;
    *(_BYTE *)(v10 + 3696) = 0;
    *(_DWORD *)(v10 + 3712) = 0;
    *(_QWORD *)(v10 + 3728) = 0;
  }
  while ( v8 != 1792 );
  v13 = (unsigned __int8)v3[1412];
  if ( v13 > 0xD )
  {
    if ( v13 != 14 && v13 != 16 )
    {
LABEL_39:
      if ( (v9 & 1) == 0 )
        return 0;
      goto LABEL_42;
    }
LABEL_31:
    v15 = 0;
    v3[1392] = 0;
    *(_DWORD *)(a1 + 5504) = 0;
    *(_DWORD *)(a1 + 5512) = 0;
    *(_WORD *)(a1 + 5516) = 0;
    *(_QWORD *)(a1 + 5520) = 0;
    if ( (v9 & 1) == 0 )
      return v15;
    goto LABEL_42;
  }
  if ( v13 != 10 )
  {
    if ( v13 != 12 )
      goto LABEL_39;
    goto LABEL_31;
  }
  v15 = 0;
  v3[2008] = 0;
  if ( (v9 & 1) != 0 )
  {
LABEL_42:
    ((void (*)(void))cam_flash_off)();
    return 0;
  }
  return v15;
}
