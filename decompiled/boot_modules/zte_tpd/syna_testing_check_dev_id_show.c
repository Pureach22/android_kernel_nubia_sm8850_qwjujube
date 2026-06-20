__int64 __fastcall syna_testing_check_dev_id_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 *v6; // x23
  __int64 testing_0001; // x0
  __int64 v8; // x20
  _DWORD *v9; // x8
  __int64 v10; // x0
  const char *v11; // x5
  unsigned int v12; // w20
  _DWORD *v13; // x19
  __int64 v14; // x0
  __int64 v15; // x2
  const char *v16; // x19
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 result; // x0
  const char *v20; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v21; // [xsp+10h] [xbp-A0h]
  _DWORD *v22; // [xsp+18h] [xbp-98h] BYREF
  __int64 v23; // [xsp+20h] [xbp-90h]
  _QWORD v24[6]; // [xsp+28h] [xbp-88h] BYREF
  __int64 v25; // [xsp+58h] [xbp-58h]
  const char *v26; // [xsp+60h] [xbp-50h] BYREF
  __int64 v27; // [xsp+68h] [xbp-48h]
  _QWORD v28[6]; // [xsp+70h] [xbp-40h] BYREF
  __int64 v29; // [xsp+A0h] [xbp-10h]
  __int64 v30; // [xsp+A8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v29 = 0;
  v27 = 0;
  memset(v28, 0, sizeof(v28));
  v25 = 0;
  v26 = nullptr;
  memset(v24, 0, sizeof(v24));
  v5 = *(_QWORD *)(v4 + 24);
  v21 = 0;
  v6 = *(__int64 **)(v5 + 152);
  if ( (*((_BYTE *)v6 + 1410) & 1) == 0 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Device is NOT connected\n");
LABEL_26:
    result = (int)result;
    goto LABEL_27;
  }
  testing_0001 = syna_tcm_get_testing_0001();
  if ( !testing_0001 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Invalid testing item id:%d\n", 1);
    goto LABEL_26;
  }
  v8 = testing_0001;
  LOBYTE(v25) = 0;
  v22 = nullptr;
  v23 = 0;
  _mutex_init(v24, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_3);
  *(_QWORD *)(v8 + 216) = &v22;
  LOBYTE(v29) = 0;
  v26 = nullptr;
  v27 = 0;
  _mutex_init(v28, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_3);
  *(_QWORD *)(v8 + 224) = &v26;
  v20 = "3908";
  LODWORD(v21) = 4;
  *(_QWORD *)(v8 + 56) = 0;
  *(_QWORD *)(v8 + 64) = &v20;
  v9 = *(_DWORD **)(v8 + 24);
  v10 = *v6;
  if ( *(v9 - 1) != -2118104430 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))v9)(v10, v8, 0) & 0x80000000) != 0 )
  {
    printk(&unk_3D2FD, "syna_testing_check_dev_id_show", *(_QWORD *)(v8 + 8));
    v11 = "Fail";
  }
  else if ( *(_BYTE *)(v8 + 16) )
  {
    v11 = "Pass";
  }
  else
  {
    v11 = "Fail";
  }
  v12 = scnprintf(a3, 4096, "\n%s (version.%d): %s\n\n", *(const char **)(v8 + 8), *(_DWORD *)v8, v11);
  if ( HIDWORD(v23) )
    v12 += scnprintf(a3 + v12, 4096LL - v12, "Build ID: %d\n", *v22);
  if ( HIDWORD(v27) )
    v12 += scnprintf(a3 + v12, 4096LL - v12, "Device ID: %s\n", v26);
  if ( (_BYTE)v25 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v25);
  v13 = v22;
  v14 = syna_request_managed_device();
  if ( v14 )
  {
    if ( v13 )
      devm_kfree(v14, v13);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v15);
  }
  v23 = 0;
  LOBYTE(v25) = 0;
  if ( (_BYTE)v29 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v29);
  v16 = v26;
  v17 = syna_request_managed_device();
  if ( v17 )
  {
    if ( v16 )
      devm_kfree(v17, v16);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v18);
  }
  result = v12;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
