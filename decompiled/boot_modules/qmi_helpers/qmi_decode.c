__int64 __fastcall qmi_decode(_DWORD *a1, __int64 a2, unsigned __int8 *a3, unsigned int a4, int a5)
{
  int v5; // w23
  unsigned int v6; // w20
  unsigned __int8 *v7; // x24
  __int64 v8; // x28
  unsigned int v9; // w19
  _DWORD *v10; // x22
  unsigned int v11; // w8
  int v12; // t1
  unsigned int v13; // w25
  char v14; // w27
  int v15; // w8
  _BYTE *v16; // x26
  int v17; // t1
  size_t v18; // x21
  __int64 v19; // x8
  int v20; // w8
  unsigned int v21; // w28
  int v22; // w8
  size_t v23; // x21
  __int64 v24; // x20
  unsigned int v25; // w21
  int v26; // w9
  unsigned int v27; // w10
  unsigned int v28; // w20
  size_t v29; // x20
  unsigned int v30; // w27
  size_t v31; // x21
  unsigned __int8 *v32; // x23
  __int64 v33; // x25
  unsigned int v34; // w28
  int v35; // w20
  _BOOL4 v36; // w8
  unsigned int v37; // w23
  unsigned __int8 *v38; // x21
  unsigned int v39; // w0
  unsigned int v40; // w27
  void *v42; // x0
  const char *v43; // x1
  __int64 v44; // x2
  void *v45; // x0
  int v46; // [xsp+8h] [xbp-48h]
  int v47; // [xsp+14h] [xbp-3Ch]
  unsigned __int64 v49; // [xsp+20h] [xbp-30h]
  int v52; // [xsp+3Ch] [xbp-14h]
  unsigned int dest; // [xsp+40h] [xbp-10h] BYREF
  unsigned int v54; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+48h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest = 0;
  if ( !a4 )
  {
    v40 = 0;
    goto LABEL_76;
  }
  v5 = a5;
  v6 = a4;
  v7 = a3;
  v8 = a2;
  v9 = 0;
  v49 = a4;
  v10 = a1;
  v52 = a5 + 1;
  while ( 1 )
  {
    if ( v5 >= 2 )
    {
      if ( !*v10 )
      {
        v40 = v9;
        goto LABEL_76;
      }
LABEL_16:
      v14 = 0;
      v13 = v6 - v9;
      goto LABEL_17;
    }
    if ( v5 != 1 )
      goto LABEL_16;
    if ( (unsigned __int64)v9 + 3 > v49 )
      goto LABEL_74;
    v10 = a1;
    v11 = *v7;
    if ( *a1 )
    {
      while ( *((unsigned __int8 *)v10 + 16) != v11 )
      {
        v12 = v10[8];
        v10 += 8;
        if ( !v12 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      v10 = nullptr;
    }
    v13 = *(unsigned __int16 *)(v7 + 1);
    if ( v11 <= 0xF && !v10 )
    {
      v45 = &unk_84B7;
LABEL_81:
      printk(v45, "qmi_decode", a3);
      v40 = -22;
      goto LABEL_76;
    }
    v7 += 3;
    v9 += 3;
    if ( !v10 )
    {
      v7 += v13;
      v9 += v13;
      goto LABEL_56;
    }
    v14 = 1;
LABEL_17:
    v15 = *v10;
    v16 = (_BYTE *)(v8 + (unsigned int)v10[5]);
    if ( *v10 == 1 )
    {
      *v16 = 1;
      v17 = v10[8];
      v10 += 8;
      v15 = v17;
      v16 = (_BYTE *)(v8 + (unsigned int)v10[5]);
    }
    if ( v15 == 2 )
    {
      if ( v10[2] == 1 )
        v18 = 1;
      else
        v18 = 2;
      if ( (unsigned int)v18 > v6 - v9 )
      {
LABEL_74:
        v40 = -22;
        goto LABEL_76;
      }
      memcpy(&dest, v7, v18);
      v13 -= v18;
      v7 += v18;
      v9 += v18;
      *(_DWORD *)v16 = dest;
      v19 = (unsigned int)v10[13];
      v10 += 8;
      v16 = (_BYTE *)(v8 + v19);
    }
    v20 = v10[3];
    if ( v20 == 1 )
    {
      v21 = v10[1];
      goto LABEL_29;
    }
    if ( !v20 )
    {
      v21 = 1;
LABEL_29:
      dest = v21;
      goto LABEL_31;
    }
    v21 = dest;
    if ( dest > v10[1] )
    {
      v42 = &unk_8436;
      v43 = "qmi_decode";
      v44 = dest;
      goto LABEL_83;
    }
LABEL_31:
    v22 = *v10;
    if ( (unsigned int)(*v10 - 3) >= 6 )
      break;
    v23 = (unsigned int)v10[2];
    v40 = v23 * v21;
    if ( (unsigned int)v23 * v21 > v6 - v9 )
      goto LABEL_74;
    if ( v21 )
    {
      v24 = 0;
      do
      {
        memcpy(&v16[v24], &v7[v24], v23);
        --v21;
        v24 += v23;
      }
      while ( v21 );
LABEL_36:
      v6 = a4;
      v8 = a2;
      if ( (v40 & 0x80000000) != 0 )
        goto LABEL_76;
      goto LABEL_55;
    }
    v8 = a2;
LABEL_55:
    v7 += v40;
    v9 += v40;
    v10 += 8;
LABEL_56:
    v40 = v9;
    if ( v9 >= v6 )
      goto LABEL_76;
  }
  if ( v22 == 9 )
  {
    if ( v13 > v6 - v9 )
      goto LABEL_74;
    v35 = v5;
    v36 = v21 != 0;
    v40 = 0;
    if ( v21 && v13 )
    {
      v40 = 0;
      v37 = 0;
      v38 = v7;
      while ( 1 )
      {
        v39 = qmi_decode(*((_QWORD *)v10 + 3), v16, v38, v13 - v40, (unsigned int)v52);
        if ( (v39 & 0x80000000) != 0 )
          break;
        ++v37;
        v40 += v39;
        v36 = v37 < v21;
        if ( v37 < v21 )
        {
          v38 += v39;
          v16 += (unsigned int)v10[2];
          if ( v40 < v13 )
            continue;
        }
        goto LABEL_65;
      }
      v40 = v39;
      goto LABEL_76;
    }
LABEL_65:
    if ( v52 <= 2 && v40 != v13 )
      goto LABEL_79;
    if ( v40 > v13 )
      v36 = 1;
    if ( v52 >= 3 && v36 )
    {
LABEL_79:
      printk(&unk_82D1, "qmi_decode_struct_elem", (unsigned int)v52);
LABEL_85:
      v40 = -14;
      goto LABEL_76;
    }
    v5 = v35;
    goto LABEL_36;
  }
  if ( v22 != 10 )
  {
    v45 = &unk_8457;
    goto LABEL_81;
  }
  v25 = v10[1];
  v8 = a2;
  v26 = 0;
  v27 = v6 - v9;
  v28 = v13;
  v54 = 0;
  if ( (v14 & 1) == 0 )
  {
    if ( v25 < 0x100 )
      v29 = 1;
    else
      v29 = 2;
    if ( (unsigned int)v29 > v27 )
      goto LABEL_74;
    v30 = v27;
    memcpy(&v54, v7, v29);
    v26 = v29;
    v28 = v54;
    v27 = v30;
  }
  if ( v28 < v25 )
  {
    if ( v28 > v13 )
    {
      printk(&unk_848C, "qmi_decode_string_elem", v28);
      goto LABEL_85;
    }
    v31 = (unsigned int)v10[2];
    v40 = v31 * v28;
    if ( (unsigned int)v31 * v28 > v27 - v26 )
      goto LABEL_74;
    if ( v28 )
    {
      v47 = v5;
      v32 = &v7[v26];
      v33 = 0;
      v34 = v28;
      v46 = v26;
      do
      {
        memcpy(&v16[v33], &v32[v33], v31);
        --v34;
        v33 += v31;
      }
      while ( v34 );
      v5 = v47;
      v8 = a2;
      v26 = v46;
      if ( (v40 & 0x80000000) != 0 )
        goto LABEL_76;
    }
    v16[v28] = 0;
    v6 = a4;
    v40 += v26;
    if ( (v40 & 0x80000000) != 0 )
      goto LABEL_76;
    goto LABEL_55;
  }
  v42 = &unk_8235;
  v43 = "qmi_decode_string_elem";
  v44 = v28;
LABEL_83:
  printk(v42, v43, v44);
  v40 = -525;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return v40;
}
