__int64 __fastcall qmi_encode(unsigned __int8 *a1, unsigned __int8 *a2, __int64 a3, unsigned int a4, int a5)
{
  unsigned __int8 *v5; // x23
  __int64 v6; // x9
  int v7; // w19
  unsigned int v8; // w20
  unsigned int v9; // w21
  __int64 v10; // x22
  int v11; // w8
  char *v12; // x24
  unsigned int v13; // w26
  unsigned int v15; // w10
  __int64 v16; // x9
  int v17; // w28
  __int64 v18; // x25
  size_t v19; // x26
  int v20; // w27
  __int64 v21; // x20
  size_t v22; // x2
  __int64 v23; // x2
  size_t v24; // x25
  unsigned int v25; // w0
  unsigned int v26; // w3
  unsigned int v27; // w26
  size_t v28; // x27
  unsigned int v29; // w3
  size_t v30; // x28
  __int64 v31; // x19
  char *v32; // x27
  unsigned int v33; // w0
  unsigned __int8 *v34; // x10
  unsigned int v35; // w9
  int v36; // w9
  int v37; // w10
  unsigned __int8 *v38; // x8
  int v39; // w9
  int v40; // t1
  void *v41; // x0
  __int64 v42; // x0
  int v44; // [xsp+8h] [xbp-38h]
  unsigned __int64 v46; // [xsp+10h] [xbp-30h]
  unsigned __int8 *v47; // [xsp+18h] [xbp-28h]
  __int64 v48; // [xsp+20h] [xbp-20h]
  unsigned __int8 v49; // [xsp+2Ch] [xbp-14h]
  unsigned int dest; // [xsp+30h] [xbp-10h] BYREF
  unsigned int src; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v52; // [xsp+38h] [xbp-8h]

  v48 = a3;
  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dest = 0;
  if ( !a1 || (v5 = a1, !*(_DWORD *)a1) )
  {
    v13 = 0;
    goto LABEL_7;
  }
  v6 = 3;
  v7 = a5;
  if ( a5 != 1 )
    v6 = 0;
  v8 = a4;
  v9 = 0;
  LODWORD(v10) = 0;
  v11 = 0;
  v12 = (char *)&a2[v6];
  v46 = a4;
  v47 = a2;
  while ( 1 )
  {
    v15 = *((_DWORD *)v5 + 3);
    v16 = *((unsigned int *)v5 + 5);
    v49 = v5[16];
    if ( v15 == 1 )
    {
      v17 = *((_DWORD *)v5 + 1);
      goto LABEL_15;
    }
    if ( !v15 )
    {
      v17 = 1;
LABEL_15:
      dest = v17;
      goto LABEL_18;
    }
    v17 = dest;
    if ( !dest || *((_DWORD *)v5 + 1) < dest )
    {
      v41 = &unk_8574;
      goto LABEL_72;
    }
LABEL_18:
    a3 = *(unsigned int *)v5;
    v18 = v48 + v16;
    if ( (int)a3 > 2 )
    {
      if ( (unsigned int)(a3 - 3) < 6 )
      {
        v19 = *((unsigned int *)v5 + 2);
        v20 = v19 * v17;
        v10 = (unsigned int)(v19 * v17 + v10);
        if ( v10 + 3 <= v46 )
        {
          if ( v17 )
          {
            v21 = 0;
            do
            {
              memcpy(&v12[v21], (const void *)(v18 + v21), v19);
              --v17;
              v21 += v19;
            }
            while ( v17 );
          }
          v12 += v20;
          v8 = a4;
          v9 += v20;
          v5 += 32;
          v11 = 1;
          goto LABEL_61;
        }
        printk(&unk_8613, "qmi_encode", a3);
        v13 = -525;
LABEL_7:
        _ReadStatusReg(SP_EL0);
        return v13;
      }
      if ( (_DWORD)a3 == 9 )
      {
        v13 = 0;
        if ( v17 )
        {
          v32 = v12;
          do
          {
            v33 = qmi_encode(*((_QWORD *)v5 + 3), v32, v18, v8 - ((_DWORD)v10 + v13), (unsigned int)(v7 + 1));
            if ( (v33 & 0x80000000) != 0 )
            {
              v13 = v33;
              printk(&unk_83EF, "qmi_encode_struct_elem", a3);
              goto LABEL_7;
            }
            v32 += v33;
            --v17;
            v13 += v33;
            v18 += *((unsigned int *)v5 + 2);
          }
          while ( v17 );
          if ( (v13 & 0x80000000) == 0 )
            goto LABEL_59;
          goto LABEL_7;
        }
        goto LABEL_59;
      }
      if ( (_DWORD)a3 == 10 )
      {
        v25 = strlen((const char *)(v48 + v16));
        v26 = *((_DWORD *)v5 + 1);
        v27 = v25;
        src = v25;
        if ( v26 < 0x100 )
          v28 = 1;
        else
          v28 = 2;
        if ( v26 < v25 )
        {
          printk(&unk_832E, "qmi_encode_string_elem", v25);
          v13 = -22;
          goto LABEL_7;
        }
        v29 = v8 - v10;
        if ( v7 == 1 )
        {
          if ( (unsigned __int64)v25 + 3 > v29 )
            goto LABEL_77;
          LODWORD(v28) = 0;
          if ( v25 )
          {
LABEL_44:
            v30 = *((unsigned int *)v5 + 2);
            v31 = 0;
            v44 = v30 * v27;
            do
            {
              memcpy(&v12[(unsigned int)v28 + v31], (const void *)(v18 + v31), v30);
              --v27;
              v31 += v30;
            }
            while ( v27 );
            v7 = a5;
            v8 = a4;
            v13 = v44 + v28;
            if ( v44 + (int)v28 < 0 )
              goto LABEL_7;
            goto LABEL_59;
          }
        }
        else
        {
          if ( (unsigned int)v28 + v25 > v29 )
          {
LABEL_77:
            printk(&unk_84E1, "qmi_encode_string_elem", v25);
            v13 = -525;
            goto LABEL_7;
          }
          memcpy(v12, &src, v28);
          if ( v27 )
            goto LABEL_44;
        }
        v13 = v28;
LABEL_59:
        v12 += v13;
        LODWORD(v10) = v13 + v10;
        v9 += v13;
        v5 += 32;
LABEL_60:
        v11 = 1;
        goto LABEL_61;
      }
LABEL_74:
      v41 = &unk_8457;
LABEL_72:
      printk(v41, "qmi_encode", a3);
      v13 = -22;
      goto LABEL_7;
    }
    if ( (_DWORD)a3 == 1 )
    {
      if ( *(_BYTE *)v18 )
      {
        v5 += 32;
        goto LABEL_61;
      }
      if ( v7 <= 1 )
      {
        do
        {
          v36 = v5[16];
          v37 = v5[48];
          v5 += 32;
        }
        while ( v36 == v37 );
LABEL_61:
        if ( v7 == 1 )
        {
          if ( v11 )
          {
            v34 = v47;
            v11 = 0;
            v47 = (unsigned __int8 *)v12;
            v12 += 3;
            LODWORD(v10) = v10 + 3;
            *v34 = v49;
            v35 = v9 >> 8;
            v34[1] = v9;
            v9 = 0;
            v34[2] = v35;
          }
        }
        goto LABEL_10;
      }
      goto LABEL_9;
    }
    if ( (_DWORD)a3 != 2 )
      goto LABEL_74;
    v22 = *((unsigned int *)v5 + 2);
    if ( (unsigned int)v22 >= 5 )
      break;
    memcpy(&dest, (const void *)(v48 + v16), v22);
    if ( *((_DWORD *)v5 + 2) == 1 )
      v24 = 1;
    else
      v24 = 2;
    v10 = (unsigned int)(v24 + v10);
    if ( v10 + 3 > v46 )
    {
      printk(&unk_8639, "qmi_encode", v23);
      v13 = -525;
      goto LABEL_7;
    }
    memcpy(v12, &dest, v24);
    v12 += v24;
    v9 += v24;
    if ( dest )
    {
      v11 = 0;
LABEL_9:
      v5 += 32;
      goto LABEL_10;
    }
    if ( v7 <= 1 )
    {
      v38 = v5 + 80;
      do
      {
        v39 = *(v38 - 32);
        v40 = *v38;
        v38 += 32;
      }
      while ( v39 == v40 );
      v5 = v38 - 48;
      goto LABEL_60;
    }
    v5 += 64;
    v11 = 1;
LABEL_10:
    v13 = v10;
    if ( !*(_DWORD *)v5 )
      goto LABEL_7;
  }
  v42 = _fortify_panic(17, 4);
  return qmi_decode_message(v42, *(unsigned int *)(v18 + 14304));
}
