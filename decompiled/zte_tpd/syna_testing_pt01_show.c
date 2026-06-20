__int64 __fastcall syna_testing_pt01_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 *v6; // x21
  __int64 testing_0100; // x0
  __int64 v8; // x20
  _DWORD *v9; // x8
  __int64 v10; // x0
  const char *v11; // x5
  unsigned int v12; // w22
  int v13; // w0
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 result; // x0
  void *v18; // [xsp+0h] [xbp-60h] BYREF
  __int64 v19; // [xsp+8h] [xbp-58h]
  __int64 v20; // [xsp+10h] [xbp-50h] BYREF
  __int64 v21; // [xsp+18h] [xbp-48h]
  _QWORD v22[6]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v23; // [xsp+50h] [xbp-10h]
  __int64 v24; // [xsp+58h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v23 = 0;
  v5 = *(_QWORD *)(v4 + 24);
  v19 = 0;
  memset(v22, 0, sizeof(v22));
  v6 = *(__int64 **)(v5 + 152);
  if ( (*((_BYTE *)v6 + 1410) & 1) == 0 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Device is NOT connected\n");
LABEL_21:
    result = (int)result;
    goto LABEL_22;
  }
  testing_0100 = syna_tcm_get_testing_0100();
  if ( !testing_0100 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Invalid testing item id:%d\n", 256);
    goto LABEL_21;
  }
  v8 = testing_0100;
  LOBYTE(v23) = 0;
  v20 = 0;
  v21 = 0;
  _mutex_init(v22, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_3);
  v18 = &pt01_limits;
  *(_QWORD *)(v8 + 216) = &v20;
  LODWORD(v19) = 16;
  *(_QWORD *)(v8 + 56) = &v18;
  v9 = *(_DWORD **)(v8 + 24);
  v10 = *v6;
  if ( *(v9 - 1) != -2118104430 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))v9)(v10, v8, 0) & 0x80000000) != 0 )
  {
    printk(&unk_3D2FD, "syna_testing_pt01_show", *(_QWORD *)(v8 + 8));
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
  LODWORD(v8) = scnprintf(a3, 4096, "\n%s (version.%d): %s\n\n", *(const char **)(v8 + 8), *(_DWORD *)v8, v11);
  if ( HIDWORD(v21) )
  {
    v12 = 0;
    do
    {
      v13 = scnprintf(
              a3 + (unsigned int)v8,
              4096LL - (unsigned int)v8,
              "x%02X ",
              *(unsigned __int8 *)(v20 + (int)v12++));
      v8 = (unsigned int)(v13 + v8);
    }
    while ( v12 < HIDWORD(v21) );
    LODWORD(v8) = scnprintf(a3 + v8, 4096 - v8, "\n") + v8;
  }
  if ( (_BYTE)v23 )
    printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)v23);
  v14 = v20;
  v15 = syna_request_managed_device();
  if ( v15 )
  {
    if ( v14 )
      devm_kfree(v15, v14);
  }
  else
  {
    printk(&unk_3BE43, "syna_pal_mem_free", v16);
  }
  result = (unsigned int)v8;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
