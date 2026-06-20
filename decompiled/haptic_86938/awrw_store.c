__int64 __fastcall awrw_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v6; // x22
  int v7; // w9
  __int64 v8; // x0
  __int64 v9; // x0
  int v10; // w8
  unsigned int v11; // w23
  int v12; // w24
  int v13; // w8
  void (__fastcall *v14)(_QWORD); // x8
  _DWORD *v15; // x8
  void (__fastcall *v16)(_QWORD); // x8
  __int64 v17; // x9
  __int64 v18; // x8
  __int16 v19; // w11
  __int64 v20; // x0
  int v21; // w0
  __int64 v23; // x2
  void *v24; // x0
  __int64 v25; // x2
  int v26; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v27; // [xsp+10h] [xbp-40h] BYREF
  _BYTE v28[4]; // [xsp+18h] [xbp-38h] BYREF
  char v29; // [xsp+1Ch] [xbp-34h] BYREF
  int v30; // [xsp+20h] [xbp-30h] BYREF
  char v31; // [xsp+24h] [xbp-2Ch]
  __int16 v32; // [xsp+28h] [xbp-28h] BYREF
  int v33; // [xsp+2Ah] [xbp-26h]
  __int16 v34; // [xsp+2Eh] [xbp-22h]
  char *v35; // [xsp+30h] [xbp-20h]
  __int16 v36; // [xsp+38h] [xbp-18h]
  __int16 v37; // [xsp+3Ah] [xbp-16h]
  __int16 v38; // [xsp+3Ch] [xbp-14h]
  __int16 v39; // [xsp+3Eh] [xbp-12h]
  __int64 v40; // [xsp+40h] [xbp-10h]
  __int64 v41; // [xsp+48h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v28[0] = 0;
  v31 = 0;
  v30 = 0;
  v27 = 0;
  v26 = 0;
  if ( sscanf(s, "%x %x %x", (char *)&v27 + 4, &v27, &v26) != 3 )
  {
    printk(&unk_15D56, "haptic_hv", 3220, "awrw_store");
    goto LABEL_22;
  }
  if ( !(_DWORD)v27 )
  {
    v23 = 3183;
    goto LABEL_30;
  }
  v7 = HIDWORD(v27);
  v8 = *(_QWORD *)(v6 + 1328);
  *(_DWORD *)(v6 + 1324) = v27;
  *(_DWORD *)(v6 + 1320) = v7;
  if ( v8 )
    kfree(v8);
  v9 = _kmalloc_noprof((unsigned int)v27, 3264);
  v10 = HIDWORD(v27);
  *(_QWORD *)(v6 + 1328) = v9;
  if ( v10 == 1 )
  {
    mutex_lock(v6 + 584);
    v14 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v6 + 1312) + 56LL);
    if ( *((_DWORD *)v14 - 1) != -2072377296 )
      __break(0x8228u);
    v14(v6 - 168);
    v15 = *(_DWORD **)(*(_QWORD *)(v6 + 1312) + 272LL);
    if ( *(v15 - 1) != 487251822 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v15)(v6 - 168, 0);
    v16 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v6 + 1312) + 240LL);
    if ( *((_DWORD *)v16 - 1) != -2072377296 )
      __break(0x8228u);
    v16(v6 - 168);
    v17 = *(_QWORD *)(v6 + 640);
    v29 = v26;
    v18 = *(_QWORD *)(v6 + 1328);
    v19 = *(_WORD *)(v17 + 2);
    v33 = 0x10000;
    v40 = v18;
    v32 = v19;
    v20 = *(_QWORD *)(v17 + 24);
    v36 = v19;
    v35 = &v29;
    v34 = 0;
    v37 = 1;
    v38 = v27;
    v39 = 0;
    v21 = i2c_transfer(v20, &v32, 2);
    if ( v21 < 0 )
    {
      v24 = &unk_147C9;
      v25 = 101;
    }
    else
    {
      if ( v21 == 2 )
      {
LABEL_21:
        mutex_unlock(v6 + 584);
        goto LABEL_22;
      }
      v24 = &unk_154F2;
      v25 = 104;
    }
    printk(v24, "haptic_hv", v25, "i2c_r_bytes");
    goto LABEL_21;
  }
  if ( !v10 )
  {
    if ( strlen(s) - 15 == 5 * (_DWORD)v27 )
    {
      if ( (_DWORD)v27 )
      {
        v11 = 0;
        v12 = 15;
        while ( 1 )
        {
          v13 = *(_DWORD *)&s[v12];
          v31 = 0;
          v30 = v13;
          if ( (kstrtou8(&v30, 0, v28) & 0x80000000) != 0 )
            break;
          v12 += 5;
          *(_BYTE *)(*(_QWORD *)(v6 + 1328) + (int)v11++) = v28[0];
          if ( v11 >= (unsigned int)v27 )
            goto LABEL_12;
        }
        v23 = 3201;
        goto LABEL_30;
      }
LABEL_12:
      mutex_lock(v6 + 584);
      i2c_w_bytes(v6 - 168, v26, *(const void **)(v6 + 1328), v27);
      goto LABEL_21;
    }
    v23 = 3193;
LABEL_30:
    printk(&unk_15D56, "haptic_hv", v23, "awrw_store");
    a4 = -34;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return a4;
}
