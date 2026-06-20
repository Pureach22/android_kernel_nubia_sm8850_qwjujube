__int64 __fastcall syna_tcm_get_features(__int64 a1, void *a2, __int64 a3)
{
  unsigned int v3; // w21
  __int64 v4; // x2
  _DWORD *v7; // x8
  __int64 result; // x0
  __int64 v9; // x2
  unsigned int v10; // w9
  const void *v11; // x1
  size_t v12; // x4
  __int64 v13; // x2
  __int64 v14; // x2
  char v15; // w8
  unsigned int v16; // w19
  __int64 v17; // x2
  char v18; // w8

  if ( !a1 )
  {
    printk(unk_3365A, "syna_tcm_get_features", a3);
    return 4294967055LL;
  }
  v3 = a3;
  v4 = *(unsigned __int8 *)(a1 + 9);
  if ( (_DWORD)v4 != 1 )
  {
    printk(unk_33E1E, "syna_tcm_get_features", v4);
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
      printk(unk_3BA3F, "syna_tcm_get_features", v4);
    }
  }
  v7 = *(_DWORD **)(a1 + 920);
  if ( *(v7 - 1) != 606091918 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v7)(a1, 50, 0, 0, 0, v3);
  if ( (result & 0x80000000) != 0 )
  {
    v16 = result;
    printk(unk_39AB7, "syna_tcm_get_features", 50);
    return v16;
  }
  if ( a2 )
  {
    if ( *(_BYTE *)(a1 + 392) )
      printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 392));
    mutex_lock(a1 + 344);
    v10 = *(_DWORD *)(a1 + 340);
    v11 = *(const void **)(a1 + 328);
    if ( v10 >= 0x10 )
      v12 = 16;
    else
      v12 = v10;
    ++*(_BYTE *)(a1 + 392);
    if ( v11 )
    {
      v13 = *(unsigned int *)(a1 + 336);
      if ( (unsigned int)v12 <= (unsigned int)v13 )
      {
        memcpy(a2, v11, v12);
        v14 = *(unsigned __int8 *)(a1 + 392);
        if ( (_DWORD)v14 == 1 )
        {
          v15 = 0;
        }
        else
        {
          printk(unk_38244, "syna_tcm_buf_unlock", v14);
          v15 = *(_BYTE *)(a1 + 392) - 1;
        }
        *(_BYTE *)(a1 + 392) = v15;
        mutex_unlock(a1 + 344);
        return 0;
      }
      printk(unk_3944E, "syna_pal_mem_cpy", v13);
    }
    printk(unk_3CDC0, "syna_tcm_get_features", v9);
    v17 = *(unsigned __int8 *)(a1 + 392);
    if ( (_DWORD)v17 == 1 )
    {
      v18 = 0;
    }
    else
    {
      printk(unk_38244, "syna_tcm_buf_unlock", v17);
      v18 = *(_BYTE *)(a1 + 392) - 1;
    }
    *(_BYTE *)(a1 + 392) = v18;
    mutex_unlock(a1 + 344);
    return 4294967274LL;
  }
  return result;
}
