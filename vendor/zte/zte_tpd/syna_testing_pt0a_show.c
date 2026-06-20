__int64 __fastcall syna_testing_pt0a_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x8
  _BYTE *v6; // x24
  __int64 testing_0A00; // x0
  __int64 v8; // x20
  __int64 v9; // x8
  _DWORD *v10; // x8
  __int64 v11; // x0
  const char *v12; // x5
  unsigned int v13; // w21
  __int64 v14; // x26
  unsigned int v15; // w25
  unsigned int v16; // w28
  int v17; // w0
  __int64 result; // x0
  __int64 v19; // x19
  __int64 v20; // x0
  __int64 v21; // x2
  void *v22; // [xsp+0h] [xbp-70h] BYREF
  __int64 v23; // [xsp+8h] [xbp-68h]
  const __int16 *v24; // [xsp+10h] [xbp-60h] BYREF
  __int64 v25; // [xsp+18h] [xbp-58h]
  __int64 v26; // [xsp+20h] [xbp-50h] BYREF
  __int64 v27; // [xsp+28h] [xbp-48h]
  _QWORD v28[6]; // [xsp+30h] [xbp-40h] BYREF
  __int64 v29; // [xsp+60h] [xbp-10h]
  __int64 v30; // [xsp+68h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v29 = 0;
  v5 = *(_QWORD *)(v4 + 24);
  v25 = 0;
  v23 = 0;
  v6 = *(_BYTE **)(v5 + 152);
  memset(v28, 0, sizeof(v28));
  if ( (v6[1410] & 1) == 0 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Device is NOT connected\n");
LABEL_25:
    result = (int)result;
    goto LABEL_26;
  }
  testing_0A00 = syna_tcm_get_testing_0A00();
  if ( !testing_0A00 )
  {
    LODWORD(result) = scnprintf(a3, 4096, "Invalid testing item id:%d\n", 2560);
    goto LABEL_25;
  }
  v8 = testing_0A00;
  *(_DWORD *)(testing_0A00 + 36) = *(_DWORD *)(*(_QWORD *)v6 + 32LL);
  v9 = *(_QWORD *)v6;
  v26 = 0;
  v27 = 0;
  *(_DWORD *)(testing_0A00 + 32) = *(_DWORD *)(v9 + 28);
  LOBYTE(v29) = 0;
  _mutex_init(v28, "(struct mutex *)ptr", &syna_pal_mutex_alloc___key_3);
  v24 = pt0a_hi_limits;
  LODWORD(v25) = 3200;
  v22 = &pt0a_lo_limits;
  LODWORD(v23) = 3200;
  *(_QWORD *)(v8 + 216) = &v26;
  *(_QWORD *)(v8 + 56) = &v24;
  *(_QWORD *)(v8 + 64) = &v22;
  v10 = *(_DWORD **)(v8 + 24);
  v11 = *(_QWORD *)v6;
  if ( *(v10 - 1) != -2118104430 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(v11, v8, 0) & 0x80000000) != 0 )
  {
    printk(unk_3D2FD, "syna_testing_pt0a_show", *(_QWORD *)(v8 + 8));
    v12 = "Fail";
  }
  else if ( *(_BYTE *)(v8 + 16) )
  {
    v12 = "Pass";
  }
  else
  {
    v12 = "Fail";
  }
  v13 = scnprintf(a3, 4096, "\n%s (version.%d): %s\n\n", *(const char **)(v8 + 8), *(_DWORD *)v8, v12);
  if ( HIDWORD(v27) && *(_DWORD *)(v8 + 32) )
  {
    v14 = v26;
    v15 = 0;
    do
    {
      if ( *(_DWORD *)(v8 + 36) )
      {
        v16 = 0;
        do
        {
          v17 = scnprintf(
                  a3 + v13,
                  4096LL - v13,
                  "%d ",
                  *(__int16 *)(v14 + 2LL * (v16 + v15 * *(_DWORD *)(*(_QWORD *)v6 + 32LL))));
          ++v16;
          v13 += v17;
        }
        while ( v16 < *(_DWORD *)(v8 + 36) );
      }
      ++v15;
      v13 += scnprintf(a3 + v13, 4096LL - v13, "\n");
    }
    while ( v15 < *(_DWORD *)(v8 + 32) );
  }
  if ( (_BYTE)v29 )
    printk(unk_34845, "syna_tcm_buf_release", (unsigned __int8)v29);
  v19 = v26;
  v20 = syna_request_managed_device();
  if ( v20 )
  {
    if ( v19 )
      devm_kfree(v20, v19);
  }
  else
  {
    printk(unk_3BE43, "syna_pal_mem_free", v21);
  }
  result = v13;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
