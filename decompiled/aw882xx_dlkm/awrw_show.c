__int64 __fastcall awrw_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v5; // x23
  __int64 v6; // x0
  __int64 result; // x0
  __int64 *v8; // x8
  __int64 v9; // x1
  __int64 v10; // x21
  __int64 v11; // x24
  __int16 v12; // w8
  __int64 v13; // x0
  int v14; // w0
  __int64 v15; // x1
  void *v16; // x0
  __int64 *v17; // x8
  __int64 v18; // x1
  unsigned __int64 v19; // x26
  int v20; // w25
  __int64 v21; // x0
  int v22; // w8
  __int64 v23; // x19
  int v24; // w0
  int v25; // w1
  char *v26; // x2
  char v27; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v28; // [xsp+8h] [xbp-28h] BYREF
  int v29; // [xsp+Ah] [xbp-26h]
  __int16 v30; // [xsp+Eh] [xbp-22h]
  char *v31; // [xsp+10h] [xbp-20h]
  __int16 v32; // [xsp+18h] [xbp-18h]
  __int16 v33; // [xsp+1Ah] [xbp-16h]
  __int16 v34; // [xsp+1Ch] [xbp-14h]
  __int16 v35; // [xsp+1Eh] [xbp-12h]
  __int64 v36; // [xsp+20h] [xbp-10h]
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v3 + 72) != 1 )
  {
    v8 = *(__int64 **)(v3 + 64);
    v9 = v8[14];
    if ( !v9 )
      v9 = *v8;
    printk(&unk_27E9F, v9, "awrw_show");
    result = -22;
    goto LABEL_4;
  }
  v5 = (unsigned int)(2 * *(_DWORD *)(v3 + 76));
  v6 = _kmalloc_noprof((int)v5, 3264);
  if ( !v6 )
  {
    result = -12;
LABEL_4:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = *(_QWORD *)(v3 + 56);
  v11 = v6;
  v27 = *(_DWORD *)(v3 + 80);
  v12 = *(_WORD *)(v10 + 2);
  v36 = v6;
  v13 = *(_QWORD *)(v10 + 24);
  v29 = 0x10000;
  v28 = v12;
  v32 = v12;
  v30 = 0;
  v31 = &v27;
  v33 = 1;
  v34 = v5;
  v35 = 0;
  v14 = i2c_transfer(v13, &v28, 2);
  if ( v14 < 0 )
  {
    v15 = *(_QWORD *)(v10 + 144);
    if ( !v15 )
      v15 = *(_QWORD *)(v10 + 32);
    v16 = &unk_253AA;
LABEL_23:
    printk(v16, v15, "aw882xx_i2c_reads");
    v23 = -14;
    goto LABEL_24;
  }
  if ( v14 != 2 )
  {
    v15 = *(_QWORD *)(v10 + 144);
    if ( !v15 )
      v15 = *(_QWORD *)(v10 + 32);
    v16 = &unk_23D54;
    goto LABEL_23;
  }
  v17 = *(__int64 **)(v3 + 64);
  v18 = v17[14];
  if ( !v18 )
    v18 = *v17;
  printk(&unk_27ECE, v18, "awrw_show");
  if ( (int)v5 < 1 )
  {
    v23 = 0;
LABEL_24:
    v21 = v11;
LABEL_25:
    kfree(v21);
    result = v23;
    *(_BYTE *)(v3 + 72) = 0;
    goto LABEL_4;
  }
  v19 = 0;
  v20 = 0;
  v21 = v11;
  while ( (int)v5 > v19 )
  {
    v22 = snprintf((char *)(a3 + v20), 4096LL - v20, "0x%02x,", *(unsigned __int8 *)(v21 + v19++));
    v21 = v11;
    v20 += v22;
    if ( v5 == v19 )
    {
      v23 = v20;
      goto LABEL_25;
    }
  }
  __break(1u);
  v24 = MEMORY[0x7115A4C](v21);
  return awrw_store(v24, v25, v26);
}
