__int64 __fastcall syna_testing_pt01_zte(__int64 *a1)
{
  __int64 v2; // x2
  const char *v3; // x19
  __int64 testing_0100; // x0
  __int64 v5; // x21
  _DWORD *v6; // x9
  __int64 v7; // x0
  const char *v8; // x5
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x20
  unsigned int v12; // w22
  int v13; // w0
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x2
  void *v18; // [xsp+0h] [xbp-60h] BYREF
  __int64 v19; // [xsp+8h] [xbp-58h]
  __int64 v20; // [xsp+10h] [xbp-50h] BYREF
  __int64 v21; // [xsp+18h] [xbp-48h]
  _QWORD v22[6]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v23; // [xsp+50h] [xbp-10h]
  __int64 v24; // [xsp+58h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v23 = 0;
  memset(v22, 0, sizeof(v22));
  v3 = (const char *)_kmalloc_cache_noprof(init_timer_key, 3520, 4096);
  if ( v3 )
  {
    testing_0100 = syna_tcm_get_testing_0100();
    if ( testing_0100 )
    {
      v5 = testing_0100;
      LOBYTE(v23) = 0;
      v20 = 0;
      v21 = 0;
      _mutex_init(v22, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_3);
      *(_QWORD *)(v5 + 216) = &v20;
      *(_QWORD *)(v5 + 56) = &v18;
      v6 = *(_DWORD **)(v5 + 24);
      v7 = *a1;
      v18 = &pt01_limits;
      LODWORD(v19) = 16;
      if ( *(v6 - 1) != -2118104430 )
        __break(0x8229u);
      if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(v7, v5, 0) & 0x80000000) != 0 )
      {
        printk(unk_3D2FD, "syna_testing_pt01_zte", *(_QWORD *)(v5 + 8));
        v8 = "Fail";
      }
      else if ( *(_BYTE *)(v5 + 16) )
      {
        v8 = "Pass";
      }
      else
      {
        v8 = "Fail";
      }
      LODWORD(v11) = scnprintf(v3, 4096, "\n%s (version.%d): %s\n\n", *(const char **)(v5 + 8), *(_DWORD *)v5, v8);
      if ( HIDWORD(v21) )
      {
        v12 = 0;
        do
        {
          v13 = scnprintf(
                  &v3[(unsigned int)v11],
                  4096LL - (unsigned int)v11,
                  "x%02X ",
                  *(unsigned __int8 *)(v20 + (int)v12++));
          v11 = (unsigned int)(v13 + v11);
        }
        while ( v12 < HIDWORD(v21) );
        LODWORD(v11) = scnprintf(&v3[v11], 4096 - v11, "\n") + v11;
      }
      tpd_copy_to_tp_firmware_data(v3, v9, v10);
      if ( (_BYTE)v23 )
        printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v23);
      v14 = v20;
      v15 = syna_request_managed_device();
      if ( v15 )
      {
        if ( v14 )
          devm_kfree(v15, v14);
      }
      else
      {
        printk(unk_3BE43, "syna_pal_mem_free", v16);
      }
      v21 = 0;
      LOBYTE(v23) = 0;
      kfree(v3);
    }
    else
    {
      LODWORD(v11) = scnprintf(v3, 4096, "Invalid testing item id:%d\n", 256);
    }
  }
  else
  {
    printk(unk_3C045, "syna_testing_pt01_zte", v2);
    LODWORD(v11) = -12;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v11;
}
