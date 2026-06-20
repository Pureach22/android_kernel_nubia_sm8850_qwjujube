unsigned __int64 __fastcall awrw_store(__int64 *a1, int a2, char *s, unsigned __int64 a4)
{
  const char *v4; // x19
  __int64 v6; // x1
  __int64 v7; // x1
  __int64 v8; // x23
  int v9; // w3
  int v10; // w8
  bool v11; // zf
  __int64 *v12; // x8
  __int64 v13; // x1
  int v14; // w8
  __int64 v15; // x24
  unsigned __int64 v16; // x21
  __int64 v17; // x26
  unsigned __int64 v18; // x28
  const char *v19; // x20
  unsigned __int64 v20; // x22
  __int64 *v21; // x8
  __int64 v22; // x1
  __int64 *v23; // x8
  __int64 v24; // x1
  __int64 *v25; // x8
  __int64 v26; // x1
  void *v27; // x0
  __int64 *v28; // x8
  const char *v29; // x2
  unsigned __int64 result; // x0
  __int64 *v31; // x8
  __int64 v32; // x1
  __int64 *v33; // x9
  __int64 v34; // x1
  __int64 *v35; // x8
  __int64 *v36; // x8
  __int64 v37; // x1
  unsigned __int64 StatusReg; // x20
  __int64 v39; // x22
  __int64 v40; // x0
  _BYTE *v41; // [xsp+8h] [xbp-38h]
  int v43; // [xsp+1Ch] [xbp-24h] BYREF
  __int128 v44; // [xsp+20h] [xbp-20h] BYREF
  int v45; // [xsp+30h] [xbp-10h] BYREF
  __int64 v46; // [xsp+38h] [xbp-8h]

  v4 = s;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 <= 0x17 )
  {
    v6 = a1[14];
    if ( !v6 )
      v6 = *a1;
    printk(&unk_26F80, v6, "awrw_store");
    v7 = a1[14];
    if ( !v7 )
      v7 = *a1;
    printk(&unk_28BC5, v7, "awrw_store");
    goto LABEL_42;
  }
  v8 = a1[19];
  v45 = 0;
  v44 = 0u;
  if ( sscanf(
         s,
         "0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",
         &v44,
         (char *)&v44 + 4,
         (char *)&v44 + 8,
         (char *)&v44 + 12,
         &v45) != 5 )
  {
    v23 = *(__int64 **)(v8 + 64);
    v24 = v23[14];
    if ( !v24 )
      v24 = *v23;
    printk(&unk_225BD, v24, "aw882xx_awrw_parse_buf");
    goto LABEL_42;
  }
  if ( *(_QWORD *)((char *)&v44 + 4) != 0x200000001LL )
  {
    v25 = *(__int64 **)(v8 + 64);
    v26 = v25[14];
    if ( !v26 )
      v26 = *v25;
    v27 = &unk_264EE;
    goto LABEL_40;
  }
  v9 = v45;
  if ( v45 >= *(_DWORD *)(*(_QWORD *)(v8 + 96) + 28LL) )
  {
    v28 = *(__int64 **)(v8 + 64);
    v26 = v28[14];
    if ( !v26 )
      v26 = *v28;
    v27 = &unk_2652E;
LABEL_40:
    v29 = "aw882xx_awrw_data_check";
LABEL_41:
    printk(v27, v26, v29);
    goto LABEL_42;
  }
  v10 = v44;
  v11 = (_DWORD)v44 == 1;
  *(_DWORD *)(v8 + 76) = HIDWORD(v44);
  *(_DWORD *)(v8 + 80) = v9;
  if ( v11 )
  {
    v31 = *(__int64 **)(v8 + 64);
    *(_BYTE *)(v8 + 72) = 1;
    v32 = v31[14];
    if ( !v32 )
      v32 = *v31;
    printk(&unk_236BE, v32, "aw882xx_awrw_parse_buf");
    result = a4;
    goto LABEL_43;
  }
  if ( v10 )
  {
    v33 = *(__int64 **)(v8 + 64);
    v34 = v33[14];
    if ( !v34 )
      v34 = *v33;
    printk(&unk_24A55, v34, "aw882xx_awrw_parse_buf");
    goto LABEL_42;
  }
  v12 = *(__int64 **)(v8 + 64);
  v13 = v12[14];
  if ( !v13 )
    v13 = *v12;
  v43 = 0;
  printk(&unk_2655C, v13, "aw882xx_awrw_write");
  v14 = *(_DWORD *)(v8 + 76);
  if ( 10 * v14 - 1 > (int)a4 - 25 )
  {
    v35 = *(__int64 **)(v8 + 64);
    v26 = v35[14];
    if ( !v26 )
      v26 = *v35;
    v27 = &unk_2346F;
    v29 = "aw882xx_awrw_write";
    goto LABEL_41;
  }
  v15 = (unsigned int)(2 * v14);
  v16 = (int)(v15 | 1);
  v41 = (_BYTE *)_kmalloc_noprof(v16, 3264);
  if ( !v41 )
  {
LABEL_42:
    result = -22;
    goto LABEL_43;
  }
LABEL_16:
  *v41 = *(_DWORD *)(v8 + 80);
  if ( (int)v15 >= 1 )
  {
    v17 = 0;
    v18 = 0;
    v19 = v4 + 25;
    v4 = "0x%02x";
    if ( v16 >= v16 - 1 )
      v20 = v16 - 1;
    else
      v20 = v16;
    while ( sscanf(&v19[v17 >> 32], "0x%02x", &v43) == 1 )
    {
      if ( v20 == v18 || (__int64)(v18 + 1) < 0 || v16 <= v18 || v16 - 1 == v18 )
      {
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v39 = *(_QWORD *)(StatusReg + 80);
        v16 = (int)(v15 | 1);
        *(_QWORD *)(StatusReg + 80) = &aw882xx_awrw_write__alloc_tag;
        v40 = _kmalloc_noprof(v16, 3264);
        *(_QWORD *)(StatusReg + 80) = v39;
        v41 = (_BYTE *)v40;
        if ( v40 )
          goto LABEL_16;
        goto LABEL_42;
      }
      v41[v18 + 1] = v43;
      v11 = v15 == v18 + 1;
      v17 += 0x500000000LL;
      ++v18;
      if ( v11 )
        goto LABEL_27;
    }
    goto LABEL_42;
  }
LABEL_27:
  if ( (i2c_transfer_buffer_flags(*(_QWORD *)(v8 + 56), v41, (unsigned int)v15 | 1, 0) & 0x80000000) != 0 )
  {
    v21 = *(__int64 **)(v8 + 64);
    v22 = v21[14];
    if ( !v22 )
      v22 = *v21;
    printk(&unk_222B3, v22, "aw882xx_awrw_write");
    kfree(v41);
    goto LABEL_42;
  }
  kfree(v41);
  v36 = *(__int64 **)(v8 + 64);
  v37 = v36[14];
  if ( !v37 )
    v37 = *v36;
  printk(&unk_24A93, v37, "aw882xx_awrw_write");
  result = a4;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
