__int64 __fastcall syna_tcm_testing_build_id(__int64 a1, __int64 a2, char a3)
{
  unsigned int v3; // w8
  int v7; // w0
  __int64 v8; // x2
  int v9; // w19
  const char *v10; // x2
  __int64 v11; // x8
  __int64 v12; // x9
  int v13; // w0
  int v14; // w8
  int v15; // w0
  int v16; // w8
  __int64 v17; // x8
  int v18; // w22
  __int64 v19; // x8
  size_t v20; // x2
  int v21; // w8
  int v22; // w0
  int v23; // w8
  unsigned int src; // [xsp+4h] [xbp-3Ch] BYREF
  _QWORD v25[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v26; // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = -161;
  if ( a1 && a2 )
  {
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v25[0] = 0;
    v25[1] = 0;
    src = 0;
    v7 = syna_tcm_identify();
    if ( v7 < 0 )
    {
      printk(unk_32661, "syna_tcm_testing_build_id", v8);
      *(_BYTE *)(a2 + 16) = 0;
      v9 = -163;
      v10 = "fail";
LABEL_27:
      printk(unk_3310F, "syna_tcm_testing_build_id", v10);
      v3 = v9;
      goto LABEL_3;
    }
    v11 = *(_QWORD *)(a2 + 216);
    v12 = a2;
    v9 = v7;
    src = *(_DWORD *)((char *)&v26 + 2);
    if ( v11 )
    {
      v13 = syna_tcm_buf_alloc(v11, 4);
      v12 = a2;
      v14 = v13;
      v7 = v9;
      if ( (v14 & 0x80000000) == 0 )
      {
        syna_pal_mem_cpy(**(_QWORD **)(a2 + 216), *(_DWORD *)(*(_QWORD *)(a2 + 216) + 8LL), &src, 4, 4u);
        v12 = a2;
        v7 = v9;
        *(_DWORD *)(*(_QWORD *)(a2 + 216) + 12LL) = 4;
      }
    }
    if ( *(_QWORD *)(v12 + 224) )
    {
      v15 = syna_tcm_buf_alloc(*(_QWORD *)(v12 + 224), 16);
      v12 = a2;
      v16 = v15;
      v7 = v9;
      if ( (v16 & 0x80000000) == 0 )
      {
        syna_pal_mem_cpy(**(_QWORD **)(a2 + 224), *(_DWORD *)(*(_QWORD *)(a2 + 224) + 8LL), (char *)v25 + 2, 16, 0x10u);
        v12 = a2;
        v7 = v9;
        *(_DWORD *)(*(_QWORD *)(a2 + 224) + 12LL) = 16;
      }
    }
    if ( (a3 & 1) != 0 )
    {
      v10 = "pass";
      *(_BYTE *)(v12 + 16) = 1;
      goto LABEL_27;
    }
    v17 = *(_QWORD *)(v12 + 56);
    if ( v17 && *(_DWORD *)(v17 + 8) >= 4u && **(_DWORD **)v17 != src )
    {
      printk(unk_3498E, "syna_tcm_testing_0001_check_build_id", src);
      v12 = a2;
      v7 = v9;
      v18 = 0;
      v19 = *(_QWORD *)(a2 + 64);
      if ( !v19 )
        goto LABEL_19;
    }
    else
    {
      v18 = 1;
      v19 = *(_QWORD *)(v12 + 64);
      if ( !v19 )
        goto LABEL_19;
    }
    v20 = *(unsigned int *)(v19 + 8);
    if ( (_DWORD)v20 )
    {
      v22 = syna_tcm_testing_0001_check_device_id((int)v25 + 2, *(char **)v19, v20);
      v12 = a2;
      v21 = v22;
      v7 = v9;
      goto LABEL_21;
    }
LABEL_19:
    v21 = 1;
LABEL_21:
    v23 = v18 & v21;
    *(_BYTE *)(v12 + 16) = v23;
    if ( v23 )
      v9 = v7;
    else
      v9 = -162;
    if ( v23 )
      v10 = "pass";
    else
      v10 = "fail";
    goto LABEL_27;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v3;
}
