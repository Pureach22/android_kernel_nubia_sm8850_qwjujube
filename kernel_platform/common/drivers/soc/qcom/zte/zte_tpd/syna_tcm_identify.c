__int64 __fastcall syna_tcm_identify(__int64 a1, void *a2, __int64 a3)
{
  __int64 result; // x0
  unsigned int v4; // w21
  _DWORD *v7; // x8
  unsigned int v8; // w21
  __int64 v9; // x2
  __int64 v10; // x2
  unsigned int v11; // w9
  const void *v12; // x1
  size_t v13; // x4
  __int64 v14; // x2
  __int64 v15; // x2
  char v16; // w8

  if ( !a1 )
  {
    printk(unk_3365A, "syna_tcm_identify", a3);
    return 4294967055LL;
  }
  v4 = a3;
  if ( !(_DWORD)a3 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 20LL) & 1) != 0 )
    {
      v4 = 0;
    }
    else
    {
      v4 = *(_DWORD *)(a1 + 524);
      printk(unk_3BA3F, "syna_tcm_identify", a3);
    }
  }
  v7 = *(_DWORD **)(a1 + 920);
  if ( *(v7 - 1) != 606091918 )
    __break(0x8228u);
  v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v7)(a1, 2, 0, 0, 0, v4);
  if ( (v8 & 0x80000000) != 0 )
  {
    printk(unk_39AB7, "syna_tcm_identify", 2);
    return v8;
  }
  v9 = *(unsigned __int8 *)(a1 + 129);
  *(_BYTE *)(a1 + 9) = v9;
  printk(unk_3C0EA, "syna_tcm_identify", v9);
  result = v8;
  if ( a2 )
  {
    if ( *(_BYTE *)(a1 + 392) )
      printk(unk_38244, "syna_tcm_buf_lock", *(unsigned __int8 *)(a1 + 392));
    mutex_lock(a1 + 344);
    v11 = *(_DWORD *)(a1 + 340);
    v12 = *(const void **)(a1 + 328);
    if ( v11 >= 0x30 )
      v13 = 48;
    else
      v13 = v11;
    ++*(_BYTE *)(a1 + 392);
    if ( v12 )
    {
      v14 = *(unsigned int *)(a1 + 336);
      if ( (unsigned int)v13 <= (unsigned int)v14 )
      {
        memcpy(a2, v12, v13);
        v15 = *(unsigned __int8 *)(a1 + 392);
        if ( (_DWORD)v15 == 1 )
        {
          v16 = 0;
        }
        else
        {
          printk(unk_38244, "syna_tcm_buf_unlock", v15);
          v16 = *(_BYTE *)(a1 + 392) - 1;
        }
        *(_BYTE *)(a1 + 392) = v16;
        mutex_unlock(a1 + 344);
        return 0;
      }
      printk(unk_3944E, "syna_pal_mem_cpy", v14);
    }
    printk(unk_3ACE0, "syna_tcm_identify", v10);
    syna_tcm_buf_unlock_0(a1 + 328);
    return 4294967274LL;
  }
  return result;
}
