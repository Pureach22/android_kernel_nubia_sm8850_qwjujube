__int64 __fastcall syna_tcm_testing_config_id(__int64 a1, __int64 a2, char a3)
{
  unsigned int v3; // w8
  int app_info; // w0
  __int64 v8; // x2
  int v9; // w19
  const char *v10; // x2
  __int64 v11; // x9
  int v12; // w22
  int v13; // w0
  int v14; // w8
  __int64 v15; // x8
  int v16; // w21
  char v17; // w8
  _QWORD v18[2]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v19[5]; // [xsp+18h] [xbp-28h] BYREF

  v19[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = -161;
  if ( a1 && a2 )
  {
    memset(v19, 0, 32);
    v18[0] = 0;
    v18[1] = 0;
    app_info = syna_tcm_get_app_info(a1, v18, 0);
    if ( app_info < 0 )
    {
      printk(unk_3298B, "syna_tcm_testing_config_id", v8);
      *(_BYTE *)(a2 + 16) = 0;
      v9 = -163;
      v10 = "fail";
    }
    else
    {
      v11 = a2;
      if ( *(_QWORD *)(a2 + 216) )
      {
        v12 = app_info;
        v13 = syna_tcm_buf_alloc_0(*(_QWORD *)(a2 + 216));
        v11 = a2;
        v14 = v13;
        app_info = v12;
        if ( (v14 & 0x80000000) == 0 )
        {
          syna_pal_mem_cpy_0(**(_QWORD **)(a2 + 216), *(unsigned int *)(*(_QWORD *)(a2 + 216) + 8LL), v19);
          v11 = a2;
          app_info = v12;
          *(_DWORD *)(*(_QWORD *)(a2 + 216) + 12LL) = 16;
        }
      }
      if ( (a3 & 1) != 0 )
      {
        v9 = app_info;
        v10 = "pass";
        *(_BYTE *)(v11 + 16) = 1;
      }
      else
      {
        v15 = *(_QWORD *)(v11 + 56);
        if ( v15 && *(_DWORD *)(v15 + 8) )
        {
          v16 = app_info;
          v17 = syna_tcm_testing_0002_check_config_id(v19, *(_QWORD *)v15);
          v11 = a2;
          app_info = v16;
          *(_BYTE *)(a2 + 16) = v17 & 1;
        }
        if ( *(_BYTE *)(v11 + 16) )
          v9 = app_info;
        else
          v9 = -162;
        if ( *(_BYTE *)(v11 + 16) )
          v10 = "pass";
        else
          v10 = "fail";
      }
    }
    printk(unk_3310F, "syna_tcm_testing_config_id", v10);
    v3 = v9;
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
