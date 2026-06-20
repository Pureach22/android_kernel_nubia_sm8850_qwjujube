__int64 __fastcall adc5_gen3_do_conversion(_QWORD *a1, int *a2, _WORD *a3)
{
  unsigned int v6; // w24
  int v7; // w25
  unsigned int v8; // w0
  int v9; // w8
  unsigned int v10; // w9
  __int64 v11; // x0
  unsigned int v12; // w23
  unsigned int v13; // w0
  char v14; // w13
  __int64 v15; // x0
  char v16; // w9
  char v17; // w12
  char v18; // w10
  int v19; // w11
  __int64 v20; // x9
  __int64 v21; // x10
  unsigned int v22; // w0
  int v23; // w26
  __int64 v24; // x23
  unsigned int v25; // w0
  __int64 v26; // x2
  unsigned int v27; // w20
  __int64 v28; // x9
  unsigned int v29; // w22
  int v30; // w21
  unsigned int v31; // w0
  __int64 v32; // x2
  int v33; // w8
  __int64 v34; // x10
  unsigned int v35; // w0
  __int64 v36; // x9
  unsigned int v37; // w0
  __int64 v38; // x9
  void *v39; // x0
  __int64 v40; // x1
  __int64 v41; // x2
  void *v42; // x8
  unsigned int v43; // w3
  void *v44; // x0
  __int64 v45; // x1
  __int64 v46; // x2
  __int64 v47; // x2
  unsigned int v48; // w3
  unsigned int v50; // w21
  __int64 v51; // x2
  char v52[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v53[4]; // [xsp+8h] [xbp-18h] BYREF
  char v54[4]; // [xsp+Ch] [xbp-14h] BYREF
  _DWORD v55[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v56; // [xsp+18h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((unsigned __int8 *)a2 + 28);
  v7 = a2[18];
  v53[0] = 0;
  v52[0] = 0;
  mutex_lock(a1 + 12);
  v8 = adc5_gen3_poll_wait_hs(a1, 0);
  if ( (v8 & 0x80000000) == 0 )
  {
    v9 = a2[18];
    v10 = *((unsigned __int8 *)a2 + 28);
    v11 = *a1;
    memset(v55, 0, 7);
    if ( v9 )
      v12 = 0;
    else
      v12 = v10;
    v13 = regmap_bulk_read(v11, (unsigned int)*(unsigned __int16 *)(a1[3] + 24LL * v12) + 79, v55, 7);
    if ( (v13 & 0x80000000) != 0 )
    {
      v42 = &unk_9458;
    }
    else
    {
      v14 = *((_BYTE *)a2 + 24);
      v15 = *a1;
      v16 = HIBYTE(v55[0]) & 0xC3 | (16 * *((_BYTE *)a2 + 4));
      v17 = *((_BYTE *)a2 + 8);
      LOBYTE(v55[0]) = a2[3] & 0x1F | (32 * (a2[8] & 3));
      LOBYTE(v55[1]) = v55[1] & 0x78 | v14 | 0x80;
      v18 = *((_BYTE *)a2 + 20);
      HIBYTE(v55[0]) = v16 | (4 * v17);
      *(_WORD *)((char *)v55 + 1) = 384;
      v19 = *a2;
      BYTE2(v55[1]) = BYTE2(v55[1]) & 0xF0 | v18;
      v20 = a1[3];
      BYTE1(v55[1]) = v19;
      *((_DWORD *)a1 + 16) = 0;
      v13 = regmap_bulk_write(v15, (unsigned int)*(unsigned __int16 *)(v20 + 24LL * v12) + 79, v55, 7);
      if ( (v13 & 0x80000000) == 0 )
      {
        v21 = a1[3];
        v54[0] = 1;
        v22 = regmap_bulk_write(*a1, (unsigned int)*(unsigned __int16 *)(v21 + 24LL * v12) + 229, v54, 1);
        if ( (v22 & 0x80000000) == 0 )
        {
          v23 = 10;
          while ( 1 )
          {
            v24 = wait_for_completion_timeout(a1 + 8, 13);
            if ( v24 )
              break;
            v25 = regmap_bulk_read(*a1, (unsigned int)*(unsigned __int16 *)a1[3] + 74, v52, 1);
            if ( (v25 & 0x80000000) != 0 )
            {
              v50 = v25;
              printk(&unk_9458, 74, 1);
              v27 = v50;
              printk(&unk_9855, v50, v51);
              goto LABEL_37;
            }
            if ( (v52[0] & 1) != 0 )
              break;
            if ( !--v23 )
            {
              printk(&unk_99A2, *((_QWORD *)a2 + 6), v26);
              ipc_log_string(a1[2], "Reading ADC channel %s timed out\n", *((const char **)a2 + 6));
              adc5_gen3_dump_regs_debug(a1);
              v27 = -110;
              goto LABEL_37;
            }
          }
          jiffies_to_msecs(v24);
          v28 = a1[3];
          if ( v7 )
            v29 = 0;
          else
            v29 = v6;
          LOWORD(v55[0]) = 0;
          v30 = a2[9];
          v31 = regmap_bulk_read(*a1, (unsigned int)*(unsigned __int16 *)(v28 + 24LL * v29) + 92, v55, 2);
          if ( (v31 & 0x80000000) != 0 )
          {
            v48 = v31;
            v39 = &unk_9458;
            v40 = 92;
            v41 = 2;
          }
          else
          {
            v33 = LOWORD(v55[0]);
            *a3 = v55[0];
            if ( !v30 && v33 == 0x8000 )
            {
              printk(&unk_96B2, 0x8000, v32);
              v27 = -22;
              goto LABEL_37;
            }
            v34 = a1[3];
            v53[0] = 1;
            v35 = regmap_bulk_write(*a1, (unsigned int)*(unsigned __int16 *)(v34 + 24LL * v29) + 75, v53, 1);
            if ( (v35 & 0x80000000) != 0 )
            {
              v48 = v35;
              v39 = &unk_95F2;
              v40 = 75;
            }
            else
            {
              v36 = a1[3];
              v53[0] = 0;
              v37 = regmap_bulk_write(*a1, (unsigned int)*(unsigned __int16 *)(v36 + 24LL * v29) + 80, v53, 1);
              if ( (v37 & 0x80000000) == 0 )
              {
                v38 = a1[3];
                v53[0] = 1;
                v27 = regmap_bulk_write(*a1, (unsigned int)*(unsigned __int16 *)(v38 + 24LL * v29) + 229, v53, 1);
                if ( (v27 & 0x80000000) == 0 )
                  goto LABEL_37;
                v39 = &unk_95F2;
                v40 = 229;
                v41 = 1;
                goto LABEL_36;
              }
              v48 = v37;
              v39 = &unk_95F2;
              v40 = 80;
            }
            v41 = 1;
          }
          v27 = v48;
LABEL_36:
          printk(v39, v40, v41);
          goto LABEL_37;
        }
        v43 = v22;
        v44 = &unk_95F2;
        v45 = 229;
        v46 = 1;
        goto LABEL_29;
      }
      v42 = &unk_95F2;
    }
    v43 = v13;
    v44 = v42;
    v45 = 79;
    v46 = 7;
LABEL_29:
    v27 = v43;
    printk(v44, v45, v46);
    printk(&unk_9254, v27, v47);
    goto LABEL_37;
  }
  v27 = v8;
LABEL_37:
  mutex_unlock(a1 + 12);
  _ReadStatusReg(SP_EL0);
  return v27;
}
