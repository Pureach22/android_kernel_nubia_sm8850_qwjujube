__int64 __fastcall syna_tcm_testing_trx_trx_short(__int64 a1, __int64 a2, char a3)
{
  unsigned int v3; // w8
  int v8; // w0
  int v9; // w20
  const char *v10; // x2
  __int64 v11; // x9
  int v12; // w19
  __int64 v13; // x10
  __int64 v14; // x19
  char v15; // w0
  __int64 v16; // x19
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // [xsp+0h] [xbp-50h] BYREF
  __int64 v20; // [xsp+8h] [xbp-48h]
  _QWORD v21[6]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v22; // [xsp+40h] [xbp-10h]
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = -161;
  if ( !a1 || !a2 )
    goto LABEL_3;
  v22 = 0;
  v20 = 0;
  memset(v21, 0, sizeof(v21));
  v19 = 0;
  _mutex_init(v21, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_5);
  v8 = syna_tcm_run_production_test(a1, 1, &v19, 0);
  if ( v8 < 0 )
  {
    printk(unk_3B2B9, "syna_tcm_testing_trx_trx_short", 1);
    *(_BYTE *)(a2 + 16) = 0;
    v9 = -163;
  }
  else
  {
    v11 = a2;
    if ( *(_QWORD *)(a2 + 216) )
    {
      v12 = v8;
      syna_tcm_buf_copy_0(*(_QWORD *)(a2 + 216), &v19);
      v11 = a2;
      v8 = v12;
    }
    if ( (a3 & 1) != 0 )
    {
      v9 = v8;
      v10 = "pass";
      *(_BYTE *)(v11 + 16) = 1;
      goto LABEL_18;
    }
    v13 = *(_QWORD *)(v11 + 56);
    if ( v13 )
    {
      v9 = v8;
      v14 = v11;
      v15 = syna_tcm_testing_check_array_data(v19, HIDWORD(v20), *(_QWORD *)v13, *(unsigned int *)(v13 + 8));
      if ( (v15 & 1) == 0 )
        v9 = -162;
      *(_BYTE *)(v14 + 16) = v15 & 1;
      if ( (v15 & 1) != 0 )
        v10 = "pass";
      else
        v10 = "fail";
      goto LABEL_18;
    }
    *(_BYTE *)(v11 + 16) = 0;
    v9 = -162;
  }
  v10 = "fail";
LABEL_18:
  printk(unk_3310F, "syna_tcm_testing_trx_trx_short", v10);
  if ( (_BYTE)v22 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v22);
  v16 = v19;
  v17 = syna_request_managed_device();
  if ( v17 )
  {
    if ( v16 )
      devm_kfree(v17, v16);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v18);
  }
  v3 = v9;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v3;
}
