__int64 __fastcall ieee80211_set_bitrate_mask(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 *v6; // x8
  unsigned int v7; // w8
  unsigned int *v8; // x8
  unsigned int v9; // w8
  __int64 *v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x13
  __int64 v16; // x14
  __int64 v17; // x2
  unsigned __int8 *v18; // x0
  __int64 v19; // x17
  _QWORD *v20; // x16
  __int64 v21; // x17
  _BYTE *v22; // x17
  int v23; // w2
  __int64 (__fastcall *v24)(__int64, __int64, __int64); // x8
  __int64 v25; // x20
  __int64 v26; // x21
  __int64 v27; // x1
  __int64 v28; // x22
  unsigned int v29; // w0
  __int64 v31; // x9
  __int64 v32; // x20
  const char *v33; // x8
  __int64 v34; // x21
  unsigned __int64 StatusReg; // x20
  __int64 v36; // x8
  __int64 v37; // [xsp+8h] [xbp-18h]
  __int64 v38; // [xsp+10h] [xbp-10h]
  __int64 v39; // [xsp+18h] [xbp-8h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v6 = *(__int64 **)(a2 + 992);
  if ( !v6 )
    goto LABEL_53;
  v5 = *v6;
  if ( !*v6 )
  {
LABEL_54:
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v38 = a2;
      v40 = a1;
      v37 = a5;
      _traceiter_drv_set_bitrate_mask(0, v5 + 1536, a2 + 2688, a5);
      a1 = v40;
      a5 = v37;
      a2 = v38;
      v36 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v36;
      if ( !v36 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v40);
        a5 = v37;
        a2 = v38;
        a1 = v40;
      }
    }
    goto LABEL_40;
  }
  if ( (*(_QWORD *)(a2 + 4320) & 1) == 0 )
    return (unsigned int)-100;
  if ( !*(_QWORD *)(a2 + 8328) )
    goto LABEL_9;
  v8 = *(unsigned int **)(a2 + 7632);
  if ( !v8 )
    goto LABEL_9;
  v9 = *v8;
  if ( v9 >= 6 )
  {
    __break(0x5512u);
LABEL_53:
    __break(0x800u);
    goto LABEL_54;
  }
  if ( (*(_DWORD *)(a5 + 60LL * v9) & *(_DWORD *)(a2 + 7568)) == 0 )
    return (unsigned int)-22;
LABEL_9:
  if ( (*(_QWORD *)(v5 + 1632) & 1) == 0 )
  {
LABEL_10:
    v10 = (__int64 *)(a1 + 328);
    v11 = -96;
    v12 = 4758;
    v13 = 4824;
    v14 = 4818;
    v15 = 4728;
    v16 = 4767;
    do
    {
      v17 = *v10;
      v18 = (unsigned __int8 *)(a2 + v12);
      *(_DWORD *)(a2 + v15) = *(_DWORD *)a5;
      v19 = *(_QWORD *)(a5 + 4);
      *((_WORD *)v18 + 4) = *(_WORD *)(a5 + 12);
      v20 = (_QWORD *)(a2 + v13);
      *(_QWORD *)v18 = v19;
      v21 = *(_QWORD *)(a5 + 22);
      *v20 = *(_QWORD *)(a5 + 14);
      v20[1] = v21;
      v22 = (_BYTE *)(a2 + v14);
      *(v22 - 66) = 0;
      *v22 = 0;
      if ( v17 )
      {
        if ( *v18 != 255
          || *(unsigned __int8 *)(a2 + v16 - 8) != 255
          || *(unsigned __int8 *)(a2 + v16 - 7) != 255
          || *(unsigned __int8 *)(a2 + v16 - 6) != 255
          || *(unsigned __int8 *)(a2 + v16 - 5) != 255
          || *(unsigned __int8 *)(a2 + v16 - 4) != 255
          || *(unsigned __int8 *)(a2 + v16 - 3) != 255
          || *(unsigned __int8 *)(a2 + v16 - 2) != 255
          || *(unsigned __int8 *)(a2 + v16 - 1) != 255
          || *(unsigned __int8 *)(a2 + v16) != 255 )
        {
          *(v22 - 66) = 1;
        }
        if ( *(__int16 *)v20 != -1
          || *(__int16 *)(a2 + v11 + 4922) != -1
          || *(__int16 *)(a2 + v11 + 4924) != -1
          || *(__int16 *)(a2 + v11 + 4926) != -1
          || *(__int16 *)(a2 + v11 + 4928) != -1
          || *(__int16 *)(a2 + v11 + 4930) != -1
          || *(__int16 *)(a2 + v11 + 4932) != -1
          || *(__int16 *)(a2 + v11 + 4934) != -1 )
        {
          *(_BYTE *)(a2 + v14) = 1;
        }
      }
      v12 += 10;
      v13 += 16;
      v11 += 16;
      ++v14;
      ++v10;
      a5 += 60;
      v15 += 4;
      v16 += 10;
    }
    while ( v11 );
    return 0;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 4304) + 1471LL) & 1) == 0 )
  {
    v23 = *(_DWORD *)(a2 + 4312);
    if ( (v23 & 0x20) == 0 && (drv_set_bitrate_mask___already_done & 1) == 0 )
    {
      v31 = *(_QWORD *)(a2 + 4296);
      drv_set_bitrate_mask___already_done = 1;
      v32 = a2;
      if ( v31 )
        v33 = (const char *)(v31 + 296);
      else
        v33 = (const char *)(a2 + 4328);
      v39 = a1;
      v34 = a5;
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v33, v23);
      a1 = v39;
      a2 = v32;
      a5 = v34;
      __break(0x800u);
    }
  }
  if ( (*(_BYTE *)(a2 + 4312) & 0x20) == 0 )
    return (unsigned int)-5;
LABEL_40:
  v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v5 + 2000) + 512LL);
  if ( v24 )
  {
    v25 = a1;
    v26 = a2;
    v27 = a2 + 7408;
    v28 = a5;
    if ( *((_DWORD *)v24 - 1) != 638112218 )
      __break(0x8228u);
    v29 = v24(v5 + 1536, v27, a5);
    a2 = v26;
    a5 = v28;
    v7 = v29;
    a1 = v25;
  }
  else
  {
    v7 = -95;
  }
  if ( !v7 )
    goto LABEL_10;
  return v7;
}
