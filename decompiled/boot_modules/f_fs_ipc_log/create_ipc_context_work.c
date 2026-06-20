__int64 __fastcall create_ipc_context_work(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  size_t v4; // x20
  __int64 v5; // x8
  size_t v6; // x0
  size_t v7; // x8
  bool v8; // cf
  size_t v9; // x2
  char *v10; // x0
  unsigned __int64 v11; // x0
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  __int64 result; // x0
  _QWORD v15[6]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (unsigned int)num_devices;
  v16 = 0;
  v15[0] = *(_QWORD *)"usb_ffs_";
  memset(&v15[1], 0, 40);
  if ( num_devices >= 1 && byte_C318 )
  {
    if ( !strcmp(&byte_C318, (const char *)(a1 + 40)) )
    {
      v5 = 0;
      goto LABEL_61;
    }
    if ( (_DWORD)v4 != 1 && byte_C358 )
    {
      if ( !strcmp(&byte_C358, (const char *)(a1 + 40)) )
      {
        v5 = 1;
        goto LABEL_61;
      }
      if ( (_DWORD)v4 != 2 && byte_C398 )
      {
        if ( !strcmp(&byte_C398, (const char *)(a1 + 40)) )
        {
          v5 = 2;
          goto LABEL_61;
        }
        if ( (_DWORD)v4 != 3 && byte_C3D8 )
        {
          if ( !strcmp(&byte_C3D8, (const char *)(a1 + 40)) )
          {
            v5 = 3;
            goto LABEL_61;
          }
          if ( (_DWORD)v4 != 4 && byte_C418 )
          {
            if ( !strcmp(&byte_C418, (const char *)(a1 + 40)) )
            {
              v5 = 4;
              goto LABEL_61;
            }
            if ( (_DWORD)v4 != 5 && byte_C458 )
            {
              if ( !strcmp(&byte_C458, (const char *)(a1 + 40)) )
              {
                v5 = 5;
                goto LABEL_61;
              }
              if ( (_DWORD)v4 != 6 && byte_C498 )
              {
                if ( !strcmp(&byte_C498, (const char *)(a1 + 40)) )
                {
                  v5 = 6;
                  goto LABEL_61;
                }
                if ( (_DWORD)v4 != 7 && byte_C4D8 )
                {
                  if ( !strcmp(&byte_C4D8, (const char *)(a1 + 40)) )
                  {
                    v5 = 7;
                    goto LABEL_61;
                  }
                  if ( (_DWORD)v4 != 8 && byte_C518 )
                  {
                    if ( !strcmp(&byte_C518, (const char *)(a1 + 40)) )
                    {
                      v5 = 8;
LABEL_61:
                      ipc_log_s[8 * v5 + 1] = *(_QWORD *)(a1 + 32);
                      goto LABEL_62;
                    }
                    if ( (_DWORD)v4 == 9 )
                    {
LABEL_64:
                      printk(&unk_C1BA, a2, a3);
                      goto LABEL_62;
                    }
                    goto LABEL_67;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (int)v4 >= 9 )
    goto LABEL_64;
  v4 = strlen((const char *)v15);
  if ( v4 == -1 )
  {
    v4 = strnlen((const char *)v15, 0x32u);
    if ( v4 >= 0x33 )
    {
LABEL_70:
      _fortify_panic(2, 50, v4 + 1);
      JUMPOUT(0xB900);
    }
  }
  v6 = strnlen((const char *)(a1 + 40), 0x29u);
  if ( v6 >= 0x2A )
LABEL_65:
    _fortify_panic(2, 41, v6 + 1);
  if ( v6 == 41 )
  {
    _fortify_panic(4, 41, 42);
    goto LABEL_67;
  }
  if ( v4 <= 0x31 )
  {
    v7 = v6 + v4;
    v8 = v6 + v4 >= 0x32;
    if ( v6 + v4 >= 0x32 )
      v9 = 49 - v4;
    else
      v9 = v6;
    v10 = (char *)v15 + v4;
    if ( v8 )
      v4 = 49;
    else
      v4 = v7;
    memcpy(v10, (const void *)(a1 + 40), v9);
    *((_BYTE *)v15 + v4) = 0;
  }
  v11 = ipc_log_context_create(10, v15, 0);
  if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_C02B, "create_ipc_context_work", a1 + 40);
    goto LABEL_62;
  }
  v12 = (unsigned int)num_devices;
  if ( (unsigned int)num_devices > 8 )
  {
LABEL_67:
    __break(0x5512u);
    goto LABEL_68;
  }
  v13 = ((unsigned __int64)(unsigned int)num_devices << 6) | 8;
  ipc_log_s[8 * (unsigned __int64)(unsigned int)num_devices] = v11;
  if ( v13 > 0x240 )
  {
LABEL_68:
    __break(1u);
LABEL_69:
    _fortify_panic(7, 41, a3);
    goto LABEL_70;
  }
  v4 = (size_t)&ipc_log_s[8 * v12];
  *(_QWORD *)(v4 + 8) = *(_QWORD *)(a1 + 32);
  v6 = strnlen((const char *)(a1 + 40), 0x29u);
  if ( v6 >= 0x2A )
    goto LABEL_65;
  if ( v6 == 41 )
    a3 = 41;
  else
    a3 = v6 + 1;
  if ( a3 >= 0x2A )
    goto LABEL_69;
  sized_strscpy(v4 + 16, a1 + 40);
  ++num_devices;
LABEL_62:
  result = kfree(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
