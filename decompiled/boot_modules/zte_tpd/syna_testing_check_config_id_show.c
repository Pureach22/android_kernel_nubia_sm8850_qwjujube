__int64 __fastcall syna_testing_check_config_id_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 *v6; // x21
  __int64 testing_0002; // x0
  __int64 v8; // x20
  _DWORD *v9; // x8
  __int64 v10; // x0
  const char *v11; // x5
  unsigned int v12; // w20
  const char *v13; // x19
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 result; // x0
  const char *v17; // [xsp+0h] [xbp-60h] BYREF
  __int64 v18; // [xsp+8h] [xbp-58h]
  const char *v19; // [xsp+10h] [xbp-50h] BYREF
  __int64 v20; // [xsp+18h] [xbp-48h]
  _QWORD v21[6]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v22; // [xsp+50h] [xbp-10h]
  __int64 v23; // [xsp+58h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v22 = 0;
  v5 = *(_QWORD *)(v4 + 24);
  v18 = 0;
  memset(v21, 0, sizeof(v21));
  v6 = *(__int64 **)(v5 + 152);
  if ( (*((_BYTE *)v6 + 1410) & 1) == 0 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Device is NOT connected\n");
LABEL_19:
    result = (int)result;
    goto LABEL_20;
  }
  testing_0002 = syna_tcm_get_testing_0002();
  if ( !testing_0002 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Invalid testing item id:%d\n", 2);
    goto LABEL_19;
  }
  v8 = testing_0002;
  LOBYTE(v22) = 0;
  v19 = nullptr;
  v20 = 0;
  _mutex_init(v21, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_3);
  v17 = "Default";
  *(_QWORD *)(v8 + 216) = &v19;
  LODWORD(v18) = 16;
  *(_QWORD *)(v8 + 56) = &v17;
  v9 = *(_DWORD **)(v8 + 24);
  v10 = *v6;
  if ( *(v9 - 1) != -2118104430 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))v9)(v10, v8, 0) & 0x80000000) != 0 )
  {
    printk(&unk_3D2FD, "syna_testing_check_config_id_show", *(_QWORD *)(v8 + 8));
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
  if ( HIDWORD(v20) )
    v12 += scnprintf(a3 + v12, 4096LL - v12, "\nConfig ID: %s\n", v19);
  if ( (_BYTE)v22 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v22);
  v13 = v19;
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
  result = v12;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
