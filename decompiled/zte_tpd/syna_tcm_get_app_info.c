__int64 __fastcall syna_tcm_get_app_info(__int64 a1, void *a2, __int64 a3)
{
  unsigned int v3; // w21
  __int64 v4; // x2
  _DWORD *v7; // x8
  unsigned int v8; // w0
  unsigned int v9; // w8
  size_t v10; // x21
  __int64 v11; // x2
  const void *v12; // x1
  __int64 v13; // x2
  __int64 v14; // x2
  char v15; // w8
  __int64 v16; // x2
  int v17; // w9
  int v19; // w11
  int v20; // w9
  __int64 v21; // x8
  __int64 v22; // x10
  void *v23; // x0
  unsigned int v24; // w19
  __int64 v25; // x2
  char v26; // w8

  if ( !a1 )
  {
    printk(&unk_3365A, "syna_tcm_get_app_info", a3);
    return 4294967055LL;
  }
  v3 = a3;
  v4 = *(unsigned __int8 *)(a1 + 9);
  if ( (_DWORD)v4 != 1 )
  {
    printk(&unk_33E1E, "syna_tcm_get_app_info", v4);
    return 4294967055LL;
  }
  if ( !v3 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
    {
      v3 = 0;
    }
    else
    {
      v3 = *(_DWORD *)(a1 + 524);
      printk(&unk_3BA3F, "syna_tcm_get_app_info", v4);
    }
  }
  v7 = *(_DWORD **)(a1 + 920);
  if ( *(v7 - 1) != 606091918 )
    __break(0x8228u);
  v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v7)(a1, 32, 0, 0, 0, v3);
  if ( (v8 & 0x80000000) != 0 )
  {
    v24 = v8;
    printk(&unk_39AB7, "syna_tcm_get_app_info", 32);
    return v24;
  }
  v9 = *(_DWORD *)(a1 + 340);
  if ( v9 >= 0x30 )
    v10 = 48;
  else
    v10 = v9;
  if ( *(_BYTE *)(a1 + 392) )
    printk(&unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 392));
  mutex_lock(a1 + 344);
  v12 = *(const void **)(a1 + 328);
  ++*(_BYTE *)(a1 + 392);
  if ( !v12 )
    goto LABEL_28;
  v13 = *(unsigned int *)(a1 + 336);
  if ( (unsigned int)v10 > (unsigned int)v13 )
  {
    printk(&unk_3944E, "syna_pal_mem_cpy", v13);
LABEL_28:
    printk(&unk_379D4, "syna_tcm_get_app_info", v11);
    v25 = *(unsigned __int8 *)(a1 + 392);
    if ( (_DWORD)v25 == 1 )
    {
      v26 = 0;
    }
    else
    {
      printk(&unk_38244, "syna_tcm_buf_unlock", v25);
      v26 = *(_BYTE *)(a1 + 392) - 1;
    }
    *(_BYTE *)(a1 + 392) = v26;
    mutex_unlock(a1 + 344);
    return 4294967274LL;
  }
  memcpy((void *)(a1 + 176), v12, v10);
  v14 = *(unsigned __int8 *)(a1 + 392);
  if ( (_DWORD)v14 == 1 )
  {
    v15 = 0;
  }
  else
  {
    printk(&unk_38244, "syna_tcm_buf_unlock", v14);
    v15 = *(_BYTE *)(a1 + 392) - 1;
  }
  *(_BYTE *)(a1 + 392) = v15;
  mutex_unlock(a1 + 344);
  if ( a2 )
    memcpy(a2, (const void *)(a1 + 176), v10);
  v16 = *(unsigned __int16 *)(a1 + 178);
  if ( *(_WORD *)(a1 + 178) )
  {
    if ( (_DWORD)v16 == 255 )
      v23 = &unk_3A507;
    else
      v23 = &unk_35677;
    printk(v23, "syna_tcm_get_app_info", v16);
    return 4294967054LL;
  }
  else
  {
    v17 = *(unsigned __int16 *)(a1 + 210);
    v19 = *(unsigned __int16 *)(a1 + 218);
    *(_DWORD *)(a1 + 16) = *(unsigned __int16 *)(a1 + 208);
    *(_DWORD *)(a1 + 20) = v17;
    v20 = *(unsigned __int16 *)(a1 + 216);
    *(_DWORD *)(a1 + 24) = *(unsigned __int16 *)(a1 + 212);
    v21 = *(_QWORD *)(a1 + 192);
    v22 = *(_QWORD *)(a1 + 200);
    *(_DWORD *)(a1 + 28) = v20;
    *(_DWORD *)(a1 + 32) = v19;
    *(_QWORD *)(a1 + 44) = v22;
    *(_QWORD *)(a1 + 36) = v21;
    return 0;
  }
}
