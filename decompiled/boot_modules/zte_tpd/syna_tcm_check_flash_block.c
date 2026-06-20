__int64 __fastcall syna_tcm_check_flash_block(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v5; // w9
  unsigned __int64 v6; // t2
  int v7; // w3
  int v8; // w9
  __int64 v9; // x2
  unsigned int v10; // w19
  unsigned __int8 *v11; // x10
  int v12; // w8
  int v13; // w3
  __int64 v14; // x8
  __int64 v15; // x11
  unsigned int v16; // w8
  void *v17; // x0
  int v18; // w8
  const char *v19; // x1
  void *v20; // x0

  if ( !a2 )
  {
    v17 = &unk_33F04;
LABEL_24:
    printk(v17, "syna_tcm_check_flash_block", a3);
    return 4294967055LL;
  }
  if ( !a3 )
  {
    v17 = &unk_31BDD;
    goto LABEL_24;
  }
  result = 0;
  HIDWORD(v6) = *(unsigned __int8 *)(a3 + 24) - 1;
  LODWORD(v6) = HIDWORD(v6);
  v5 = v6 >> 1;
  if ( v5 > 2 )
  {
    if ( v5 == 3 )
      return *(unsigned int *)(a3 + 16);
    if ( v5 != 9 )
      return result;
    result = *(unsigned int *)(a3 + 16);
    if ( (unsigned int)result <= 7 )
    {
      v19 = "syna_tcm_check_flash_tool_boot_config";
      v9 = (unsigned int)result;
      v20 = &unk_39BAB;
      goto LABEL_33;
    }
    v11 = *(unsigned __int8 **)(a2 + 32);
    v12 = *v11;
    if ( (v12 | 2) != 3 )
    {
      v20 = &unk_3C1D7;
      v19 = "syna_tcm_check_flash_tool_boot_config";
      v9 = *v11;
      goto LABEL_33;
    }
    v13 = *(_DWORD *)(a3 + 20);
    if ( v12 == 1 )
    {
      v14 = 13;
      v15 = 12;
    }
    else
    {
      if ( v12 != 3 )
      {
        v18 = 0;
        goto LABEL_28;
      }
      v14 = 17;
      v15 = 16;
    }
    v18 = v11[v15] | (v11[v14] << 8);
LABEL_28:
    v9 = (unsigned int)(v18 * *(_DWORD *)(a2 + 44));
    if ( v13 == (_DWORD)v9 )
      return result;
    v20 = &unk_3278B;
    v19 = "syna_tcm_check_flash_tool_boot_config";
    goto LABEL_33;
  }
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      result = *(unsigned int *)(a3 + 16);
      if ( (_DWORD)result )
      {
        v7 = *(unsigned __int16 *)(a1 + 186);
        v8 = *(unsigned __int16 *)(a1 + 184) * *(_DWORD *)(a2 + 44);
        if ( v8 | v7 )
        {
          v9 = *(unsigned int *)(a3 + 20);
          if ( (_DWORD)v9 == v8 )
          {
            if ( (_DWORD)result != v7 )
            {
              v10 = result;
              printk(&unk_31C8B, "syna_tcm_check_flash_app_config", (unsigned int)result);
              return v10;
            }
            return result;
          }
          v20 = &unk_368AF;
          v19 = "syna_tcm_check_flash_app_config";
LABEL_33:
          printk(v20, v19, v9);
          return 4294967055LL;
        }
      }
    }
  }
  else
  {
    v16 = *(_DWORD *)(a3 + 16);
    if ( v16 )
      return v16;
    else
      return 4294967055LL;
  }
  return result;
}
