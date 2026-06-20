__int64 __fastcall qbt_touch_work_func(unsigned int *a1)
{
  __int64 v2; // x27
  __int64 v3; // x28
  int v4; // w21
  __int64 v5; // x26
  unsigned int *v6; // x8
  signed int v7; // w23
  signed int v8; // w24
  char v9; // w9
  unsigned int v10; // w20
  signed int v11; // w10
  signed int v12; // w25
  unsigned int v13; // w22
  char v14; // w9
  int v15; // w9
  int v16; // w21
  signed int v17; // w8
  signed int v18; // w20
  void *v19; // x0
  __int64 v20; // x0
  void *v21; // x0
  _BOOL4 v22; // w22
  void *v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w8
  __int64 v27; // x1
  unsigned int *v28; // x8
  int v29; // w9
  int v30; // w10
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x1
  signed int v34; // w8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 result; // x0
  int v38; // [xsp+8h] [xbp-48h]
  signed int v39; // [xsp+Ch] [xbp-44h]
  unsigned int *v40; // [xsp+10h] [xbp-40h]
  signed int v41; // [xsp+18h] [xbp-38h]
  int v42; // [xsp+1Ch] [xbp-34h]
  __int64 v43; // [xsp+20h] [xbp-30h] BYREF
  __int64 v44; // [xsp+28h] [xbp-28h]
  unsigned __int64 v45; // [xsp+30h] [xbp-20h]
  __int64 v46; // [xsp+38h] [xbp-18h]
  __int64 v47; // [xsp+40h] [xbp-10h]
  __int64 v48; // [xsp+48h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = printk(&unk_9A11, "qbt_touch_work_func");
    goto LABEL_69;
  }
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v40 = a1 - 152;
  v5 = 111;
  v46 = 0;
  v44 = 0;
  v45 = 0;
  v43 = 0;
  v47 = 1;
  do
  {
    v6 = &a1[v2];
    v7 = a1[v2 + 8];
    v8 = a1[v2 + 9];
    v9 = a1[v2 + 11];
    v10 = a1[v2 + 10];
    LOBYTE(a1[v2 + 11]) = 0;
    if ( (v9 & 1) == 0 )
      goto LABEL_5;
    v12 = v6[48];
    v11 = v6[49];
    v13 = v6[50];
    *((_BYTE *)v6 + 204) = v9;
    v14 = *((_BYTE *)v6 + 47);
    v6[48] = v7;
    v6[49] = v8;
    v41 = v11;
    v42 = v4;
    LOWORD(v11) = *(_WORD *)((char *)v6 + 45);
    v6[50] = v10;
    *(_WORD *)((char *)v6 + 205) = v11;
    *((_BYTE *)v6 + 207) = v14;
    if ( (v10 & 0x80000000) != 0 )
    {
      v15 = 0;
      v16 = 0;
    }
    else
    {
      if ( (v13 & 0x80000000) != 0 )
        goto LABEL_13;
      if ( v13 != v10 )
      {
        printk(&unk_9828, "qbt_touch_work_func");
LABEL_13:
        v15 = 0;
        v16 = 1;
        goto LABEL_14;
      }
      v16 = 2;
      v15 = 1;
    }
LABEL_14:
    v17 = *(a1 - 8);
    HIDWORD(v46) = v16;
    if ( v7 < v17 || v7 > (int)*(a1 - 6) || v8 < (int)*(a1 - 7) )
    {
      printk(&unk_9462, "qbt_touch_filter_aoi_region");
LABEL_18:
      if ( v12 < (int)*(a1 - 8) || v12 > (int)*(a1 - 6) || v41 < (int)*(a1 - 7) )
      {
        printk(&unk_9462, "qbt_touch_filter_aoi_region");
LABEL_4:
        v4 = v42;
        goto LABEL_5;
      }
      v18 = *(a1 - 5);
      if ( v41 > v18 )
        v19 = &unk_9462;
      else
        v19 = &unk_9AA5;
      v20 = printk(v19, "qbt_touch_filter_aoi_region");
      if ( v41 > v18 || (v13 & 0x80000000) != 0 )
        goto LABEL_4;
      v16 = 0;
LABEL_38:
      HIDWORD(v46) = v16;
      goto LABEL_39;
    }
    v38 = v15;
    v39 = *(a1 - 5);
    if ( v8 <= v39 )
      v21 = &unk_9AA5;
    else
      v21 = &unk_9462;
    printk(v21, "qbt_touch_filter_aoi_region");
    if ( v8 > v39 )
      goto LABEL_18;
    if ( v12 >= (int)*(a1 - 8) && v12 <= (int)*(a1 - 6) && v41 >= (int)*(a1 - 7) )
    {
      v34 = *(a1 - 5);
      v22 = v41 <= v34;
      if ( v41 > v34 )
        v23 = &unk_9462;
      else
        v23 = &unk_9AA5;
    }
    else
    {
      v22 = 0;
      v23 = &unk_9462;
    }
    v20 = printk(v23, "qbt_touch_filter_aoi_region");
    if ( (v10 & 0x80000000) == 0 && !v22 )
    {
      v16 = 1;
      goto LABEL_38;
    }
    if ( v38 )
    {
      v28 = &a1[v5];
      v29 = a1[v5 - 23] + v7 - v12;
      v30 = a1[v5 - 13] + v8 - v41;
      *(v28 - 23) = v29;
      *(v28 - 13) = v30;
      if ( v30 < 0 )
        v30 = -v30;
      if ( *((_BYTE *)a1 - 35) == 1 )
      {
        if ( v29 < 0 )
          v29 = -v29;
        if ( v29 <= *(a1 - 4) && v30 <= *(a1 - 3) )
          goto LABEL_4;
      }
      *(v28 - 23) = 0;
      *(v28 - 13) = 0;
      v31 = ktime_get(v20);
      v32 = ns_to_timespec64(v31);
      v4 = v42;
      LODWORD(v46) = v3;
      v43 = v32;
      v44 = v33;
      v45 = __PAIR64__(v8, v7);
      goto LABEL_50;
    }
LABEL_39:
    v24 = ktime_get(v20);
    v25 = ns_to_timespec64(v24);
    a1[v5] = v16;
    v26 = a1[111];
    v43 = v25;
    v44 = v27;
    LODWORD(v46) = v3;
    v45 = __PAIR64__(v8, v7);
    if ( v26 == 1
      || a1[112] == 1
      || a1[113] == 1
      || a1[114] == 1
      || a1[115] == 1
      || a1[116] == 1
      || a1[117] == 1
      || a1[118] == 1
      || a1[119] == 1 )
    {
      v4 = 1;
    }
    else
    {
      v4 = (a1[120] == 1) | v42;
    }
    if ( *((_BYTE *)a1 - 8) == 1 )
    {
      printk(&unk_9D80, "qbt_touch_work_func");
      v35 = a1[110];
      if ( (v35 & 0x80000000) != 0 )
      {
        printk(&unk_9932, "qbt_touch_work_func");
      }
      else
      {
        v36 = gpio_to_desc(v35);
        gpiod_set_raw_value(v36, v4 & 1);
      }
    }
LABEL_50:
    if ( *((_BYTE *)a1 - 36) == 1 )
      qbt_fd_report_event(v40, &v43);
LABEL_5:
    ++v3;
    v2 += 4;
    ++v5;
  }
  while ( v3 != 10 );
  result = pm_relax(*((_QWORD *)a1 - 40));
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
