__int64 __fastcall hdcp1_start_smcinvoke(__int64 a1, unsigned int *a2, unsigned int *a3)
{
  __int64 result; // x0
  unsigned int *v7; // x19
  __int64 v8; // x0
  __int64 v9; // x0
  _DWORD *v10; // x8
  unsigned int v11; // w1
  unsigned int v12; // w19
  void *v13; // x0
  _QWORD v14[3]; // [xsp+8h] [xbp-18h] BYREF

  v14[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || !a3 )
  {
    v13 = &unk_BD48;
LABEL_18:
    printk(v13);
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( !a1 )
  {
    v13 = &unk_C81E;
    goto LABEL_18;
  }
  if ( (*(_BYTE *)(a1 + 64) & 1) == 0 )
  {
    v13 = &unk_C3AD;
    goto LABEL_18;
  }
  if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
  {
    result = 0;
    goto LABEL_22;
  }
  result = hdcp1_app_load_0(a1);
  if ( !(_DWORD)result )
  {
    v7 = (unsigned int *)_kmalloc_cache_noprof(msleep, 3520, 8);
    v8 = a1;
    if ( v7 )
    {
      if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
      {
        v10 = *(_DWORD **)a1;
        v9 = *(_QWORD *)(a1 + 8);
        v14[0] = v7;
        v14[1] = 8;
        if ( *(v10 - 1) != 816020464 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(__int64, __int64, _QWORD *, __int64))v10)(v9, 4, v14, 16) )
        {
          printk(&unk_C6FF);
          v12 = -126;
          goto LABEL_24;
        }
        v11 = bswap32(v7[1]);
        *a2 = bswap32(*v7);
        *a3 = v11;
        result = hdcp1_validate_aksv(*a2, v11);
        if ( (_DWORD)result )
        {
          v12 = result;
          printk(&unk_BDBF);
LABEL_24:
          v8 = a1;
          goto LABEL_21;
        }
        goto LABEL_22;
      }
      printk(&unk_C57F);
      v8 = a1;
    }
    v12 = -22;
LABEL_21:
    hdcp1_app_unload_0(v8);
    result = v12;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
