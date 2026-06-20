__int64 __fastcall tp_edge_report_limit_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x21
  size_t v5; // x19
  __int64 v6; // x1
  __int64 v7; // x2
  int tp_algo_item_id; // w0
  int v9; // w8
  __int64 result; // x0
  __int64 v11; // x1
  unsigned int v12; // w8
  unsigned int v13; // w8
  int v14; // w22
  char *v15; // x20
  __int64 v16; // x2
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x2
  _BOOL8 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x1
  unsigned __int64 v23; // x22
  char *v24; // x0
  unsigned __int8 v25; // w8
  __int64 v26; // x2
  __int64 v27; // x1
  char v28; // w8
  __int64 v29; // x2
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x1
  __int64 v33; // x2
  _BOOL8 v34; // x1
  __int64 v35; // [xsp+0h] [xbp-80h] BYREF
  char *stringp; // [xsp+8h] [xbp-78h] BYREF
  char s[8]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v38; // [xsp+18h] [xbp-68h]
  __int64 v39; // [xsp+20h] [xbp-60h]
  __int64 v40; // [xsp+28h] [xbp-58h]
  __int64 v41; // [xsp+30h] [xbp-50h]
  __int64 v42; // [xsp+38h] [xbp-48h]
  __int64 v43; // [xsp+40h] [xbp-40h]
  __int64 v44; // [xsp+48h] [xbp-38h]
  __int64 v45; // [xsp+50h] [xbp-30h]
  __int64 v46; // [xsp+58h] [xbp-28h]
  __int64 v47; // [xsp+60h] [xbp-20h]
  __int64 v48; // [xsp+68h] [xbp-18h]
  int v49; // [xsp+70h] [xbp-10h]
  __int64 v50; // [xsp+78h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = tpd_cdev;
  v49 = 0;
  if ( a3 >= 0x64 )
    v5 = 100;
  else
    v5 = a3;
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
  *(_QWORD *)s = 0;
  v38 = 0;
  v35 = 0;
  if ( a2 && (_check_object_size(s, v5, 0), inline_copy_from_user((__int64)s, a2, v5)) )
  {
    printk(&unk_33B59, v6, v7);
    result = -22;
  }
  else
  {
    tp_algo_item_id = get_tp_algo_item_id(s);
    if ( (tp_algo_item_id & 0x80000000) == 0 )
    {
      v14 = tp_algo_item_id;
      v15 = strchr(s, 58) + 1;
      stringp = v15;
      printk(&unk_31887, v15, v16);
      if ( v14 <= 2 )
      {
        switch ( v14 )
        {
          case 0:
            if ( !(unsigned int)kstrtouint(v15, 10, (char *)&v35 + 4) )
            {
              v34 = HIDWORD(v35) != 0;
              HIDWORD(v35) = HIDWORD(v35) != 0;
              *(_BYTE *)(v4 + 27) = v34;
              printk(&unk_37521, v34, v33);
            }
            goto LABEL_19;
          case 1:
            if ( !(unsigned int)kstrtouint(v15, 10, (char *)&v35 + 4) )
            {
              v32 = BYTE4(v35);
              *(_BYTE *)(v4 + 36) = BYTE4(v35);
              printk(&unk_39CF4, v32, v31);
            }
            goto LABEL_19;
          case 2:
            if ( !(unsigned int)kstrtouint(v15, 10, (char *)&v35 + 4) )
            {
              v22 = WORD2(v35);
              *(_WORD *)(v4 + 62) = WORD2(v35);
              printk(&unk_33421, v22, v21);
            }
            goto LABEL_19;
        }
      }
      else
      {
        if ( v14 <= 4 )
        {
          if ( v14 == 3 )
          {
            if ( !(unsigned int)kstrtouint(v15, 10, (char *)&v35 + 4) )
            {
              v27 = BYTE4(v35);
              *(_BYTE *)(v4 + 38) = BYTE4(v35);
              printk(&unk_38CA5, v27, v26);
              v28 = *(_BYTE *)(v4 + 38);
              result = v5;
              *(_BYTE *)(v4 + 39) = v28;
              *(_BYTE *)(v4 + 40) = v28;
              *(_BYTE *)(v4 + 41) = v28;
              *(_BYTE *)(v4 + 42) = v28;
              goto LABEL_20;
            }
          }
          else if ( !(unsigned int)kstrtouint(v15, 10, (char *)&v35 + 4) )
          {
            v20 = HIDWORD(v35) != 0;
            HIDWORD(v35) = HIDWORD(v35) != 0;
            *(_BYTE *)(v4 + 37) = v20;
            printk(&unk_380F6, v20, v19);
          }
          goto LABEL_19;
        }
        if ( v14 == 5 )
        {
          if ( !(unsigned int)kstrtouint(v15, 10, (char *)&v35 + 4) )
          {
            v30 = WORD2(v35);
            *(_WORD *)(v4 + 60) = WORD2(v35);
            printk(&unk_37521, v30, v29);
          }
          goto LABEL_19;
        }
        if ( v14 == 6 )
        {
          v23 = 0;
          do
          {
            v24 = strsep(&stringp, ",");
            if ( !v24 )
              break;
            if ( !(unsigned int)kstrtouint(v24, 10, (char *)&v35 + 4) )
            {
              v25 = BYTE4(v35);
              *(_BYTE *)(v4 + 52 + v23) = BYTE4(v35);
              printk(&unk_3CA2F, (unsigned __int16)v23++, v25);
            }
          }
          while ( v23 <= 3 );
          goto LABEL_19;
        }
      }
      printk(&unk_3B681, v17, v18);
LABEL_19:
      result = v5;
      goto LABEL_20;
    }
    v9 = kstrtouint_from_user(a2, v5, 10, &v35);
    result = -22;
    if ( !v9 )
    {
      v11 = (unsigned int)v35;
      if ( (unsigned int)v35 <= 0xA )
      {
        v12 = *(unsigned __int16 *)(v4 + 1090);
        *(_BYTE *)(v4 + 56) = v35;
        if ( (unsigned int)v11 > 5 )
          v13 = ((4294968 * (unsigned __int64)(35 * v12)) >> 32) + (v11 + 65531) * ((33555 * (v12 >> 1)) >> 22);
        else
          v13 = 7 * (unsigned int)v11 * v12 / 0x3E8;
        *(_WORD *)(v4 + 44) = v13;
        *(_WORD *)(v4 + 46) = 0;
        printk(&unk_328F9, v11, (unsigned __int16)v13);
        goto LABEL_19;
      }
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
