__int64 __fastcall entry_panic(__int64 a1, __int64 a2)
{
  int v3; // w8
  const char *v4; // x19
  __int64 v5; // x1
  size_t v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  unsigned __int64 v9; // x27
  char v10; // w8
  int v11; // w21
  int v12; // w28
  unsigned int v13; // w22
  int v15; // w24
  void *v16; // x0
  __int64 v17; // x2
  const char *v18; // x0
  const char *v20; // x22
  char s[8]; // [xsp+30h] [xbp-110h] BYREF
  __int64 v22; // [xsp+38h] [xbp-108h]
  __int64 v23; // [xsp+40h] [xbp-100h]
  __int64 v24; // [xsp+48h] [xbp-F8h]
  __int64 v25; // [xsp+50h] [xbp-F0h]
  __int64 v26; // [xsp+58h] [xbp-E8h]
  __int64 v27; // [xsp+60h] [xbp-E0h]
  __int64 v28; // [xsp+68h] [xbp-D8h]
  __int64 v29; // [xsp+70h] [xbp-D0h]
  __int64 v30; // [xsp+78h] [xbp-C8h]
  __int64 v31; // [xsp+80h] [xbp-C0h]
  __int64 v32; // [xsp+88h] [xbp-B8h]
  __int64 v33; // [xsp+90h] [xbp-B0h]
  __int64 v34; // [xsp+98h] [xbp-A8h]
  __int64 v35; // [xsp+A0h] [xbp-A0h]
  __int64 v36; // [xsp+A8h] [xbp-98h]
  __int64 v37; // [xsp+B0h] [xbp-90h]
  __int64 v38; // [xsp+B8h] [xbp-88h]
  __int64 v39; // [xsp+C0h] [xbp-80h]
  __int64 v40; // [xsp+C8h] [xbp-78h]
  __int64 v41; // [xsp+D0h] [xbp-70h]
  __int64 v42; // [xsp+D8h] [xbp-68h]
  __int64 v43; // [xsp+E0h] [xbp-60h]
  __int64 v44; // [xsp+E8h] [xbp-58h]
  __int64 v45; // [xsp+F0h] [xbp-50h]
  __int64 v46; // [xsp+F8h] [xbp-48h]
  __int64 v47; // [xsp+100h] [xbp-40h]
  __int64 v48; // [xsp+108h] [xbp-38h]
  __int64 v49; // [xsp+110h] [xbp-30h]
  __int64 v50; // [xsp+118h] [xbp-28h]
  __int64 v51; // [xsp+120h] [xbp-20h]
  __int64 v52; // [xsp+128h] [xbp-18h]
  __int64 v53; // [xsp+130h] [xbp-10h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = once_entry_panic_count;
  v4 = *(const char **)a2;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v5 = (unsigned int)(once_entry_panic_count + 1);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  *(_QWORD *)s = 0;
  v22 = 0;
  ++once_entry_panic_count;
  if ( v3 )
  {
    v16 = &unk_71A6;
    v17 = (unsigned __int8)saved_nvmem_buf[0];
    goto LABEL_21;
  }
  if ( !v4 )
  {
LABEL_19:
    v18 = nullptr;
    goto LABEL_20;
  }
  v6 = strlen(v4);
  if ( v6 + 21 > 0x100 )
  {
    printk(&unk_74C7, v6 + 18, v4);
    goto LABEL_19;
  }
  snprintf(s, 0x100u, "%s%s", "ztedbg panic_hook:", v4);
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = -1;
  v13 = -1;
  while ( 1 )
  {
    v15 = (unsigned __int8)s[v9];
    if ( v15 == 37 )
    {
      v10 ^= 1u;
      goto LABEL_6;
    }
    if ( !s[v9] )
      goto LABEL_23;
    if ( (v10 & 1) == 0 )
    {
      v10 = 0;
      goto LABEL_6;
    }
    if ( !memchr("diouxXfFeEgGaAcsSpn", v15, 0x14u) )
      break;
    v10 = 0;
    if ( v15 == 115 && v12 == -1 )
    {
      v13 = v11 + 1;
      v12 = v11 + 1;
    }
    ++v11;
LABEL_6:
    if ( v9++ > 0xFE )
      __break(1u);
  }
  if ( v15 != 42 )
  {
    v10 = 1;
    goto LABEL_6;
  }
  v11 = -1;
LABEL_23:
  if ( v13 - 1 > 6 )
  {
LABEL_26:
    v20 = nullptr;
  }
  else
  {
    if ( !*(_QWORD *)(a2 + 8LL * v13) )
    {
      printk(&unk_7387, v13, v8);
      goto LABEL_26;
    }
    v20 = *(const char **)(a2 + 8LL * v13);
    printk(&unk_7247, v20, v8);
    if ( !strcmp(v20, "panicinpanic") )
      panic("panicinpanic %d", once_entry_panic_count);
  }
  if ( v11 > 1 )
  {
    if ( v11 != 2 && v11 != 3 )
      goto LABEL_35;
    printk(s, *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 16));
    v18 = v20;
  }
  else if ( v11 )
  {
    if ( v11 == 1 )
    {
      printk(s, *(_QWORD *)(a2 + 8), v8);
      v18 = v20;
      goto LABEL_20;
    }
LABEL_35:
    printk(&unk_72FC, (unsigned int)v11, v4);
    v18 = v20;
  }
  else
  {
    printk(s, v7, v8);
    v18 = v20;
  }
LABEL_20:
  saved_nvmem_buf[3] = 80;
  fill_nvmem_buf(v18, v4, (__int64)saved_nvmem_buf, 4, 1u);
  v16 = &unk_6FC2;
  v5 = (unsigned __int8)saved_nvmem_buf[0];
  v17 = (unsigned __int8)saved_nvmem_buf[1];
LABEL_21:
  printk(v16, v5, v17);
  _ReadStatusReg(SP_EL0);
  return 0;
}
