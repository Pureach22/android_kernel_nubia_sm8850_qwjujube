__int64 __fastcall syna_tcm_testing_noise(__int64 a1, __int64 a2, char a3)
{
  unsigned int v3; // w8
  unsigned int v8; // w19
  unsigned int v9; // w20
  int v10; // w0
  int v11; // w20
  const char *v12; // x2
  __int64 v13; // x9
  int v14; // w21
  __int64 v15; // x8
  int v16; // w23
  unsigned __int8 v17; // w21
  unsigned __int8 v18; // w0
  __int64 v19; // x8
  unsigned __int8 v20; // w0
  __int64 v21; // x19
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // [xsp+0h] [xbp-50h] BYREF
  __int64 v25; // [xsp+8h] [xbp-48h]
  _QWORD v26[6]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v27; // [xsp+40h] [xbp-10h]
  __int64 v28; // [xsp+48h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = -161;
  if ( a1 && a2 )
  {
    v27 = 0;
    v25 = 0;
    memset(v26, 0, sizeof(v26));
    v24 = 0;
    _mutex_init(v26, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_4);
    v9 = *(_DWORD *)(a1 + 28);
    v8 = *(_DWORD *)(a1 + 32);
    v10 = syna_tcm_run_production_test(a1, 10, &v24, 0);
    if ( v10 < 0 )
    {
      printk(unk_3B2B9, "syna_tcm_testing_noise", 10);
      *(_BYTE *)(a2 + 16) = 0;
      v11 = -163;
      v12 = "fail";
    }
    else
    {
      v13 = a2;
      if ( *(_QWORD *)(a2 + 216) )
      {
        v14 = v10;
        syna_tcm_buf_copy(*(_QWORD *)(a2 + 216), &v24);
        v13 = a2;
        v10 = v14;
      }
      if ( (a3 & 1) != 0 )
      {
        v11 = v10;
        v12 = "pass";
        *(_BYTE *)(v13 + 16) = 1;
      }
      else
      {
        v15 = *(_QWORD *)(v13 + 56);
        v16 = v10;
        if ( v15 )
        {
          v18 = syna_tcm_testing_check_frame_data(
                  v24,
                  HIDWORD(v25),
                  v9,
                  v8,
                  syna_tcm_testing_0A00_check_upper_bound,
                  *(_QWORD *)v15,
                  *(unsigned int *)(v15 + 8));
          v13 = a2;
          v17 = v18;
        }
        else
        {
          v17 = 0;
        }
        v19 = *(_QWORD *)(v13 + 64);
        if ( v19 )
        {
          v20 = syna_tcm_testing_check_frame_data(
                  v24,
                  HIDWORD(v25),
                  v9,
                  v8,
                  syna_tcm_testing_0A00_check_lower_bound,
                  *(_QWORD *)v19,
                  *(unsigned int *)(v19 + 8));
          v13 = a2;
        }
        else
        {
          v20 = 0;
        }
        *(_BYTE *)(v13 + 16) = v17 & v20 & 1;
        if ( (v17 & v20 & 1) != 0 )
          v11 = v16;
        else
          v11 = -162;
        if ( (v17 & v20 & 1) != 0 )
          v12 = "pass";
        else
          v12 = "fail";
      }
    }
    printk(unk_3310F, "syna_tcm_testing_noise", v12);
    if ( (_BYTE)v27 )
      printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v27);
    v21 = v24;
    v22 = syna_request_managed_device();
    if ( v22 )
    {
      if ( v21 )
        devm_kfree(v22, v21);
    }
    else
    {
      printk(unk_3BE43, "syna_pal_mem_free", v23);
    }
    v3 = v11;
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
