__int64 __fastcall bwmon_update_cur_freq(__int64 a1)
{
  __int64 v2; // x19
  unsigned int v3; // w24
  __int64 v4; // x0
  __int64 v5; // x21
  unsigned int v6; // w8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x11
  __int64 v11; // x10
  unsigned __int64 v12; // x12
  unsigned __int64 v13; // x13
  unsigned __int64 v14; // x12
  unsigned __int64 v15; // x23
  unsigned __int64 v16; // x22
  __int64 v17; // x12
  unsigned __int64 v18; // x11
  unsigned __int64 v19; // x12
  unsigned __int64 v20; // x10
  unsigned __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x12
  unsigned __int64 v24; // x12
  unsigned __int64 v25; // x11
  __int64 v26; // x11
  __int64 v27; // x11
  __int64 v28; // x13
  __int64 v29; // x12
  __int64 v30; // x11
  __int64 v31; // x11
  __int64 v32; // x11
  bool v33; // cc
  __int64 v34; // x11
  unsigned __int64 v35; // x10
  void (__fastcall *v36)(__int64, __int64); // x9
  __int64 v37; // x1
  int v38; // w8
  _DWORD *v39; // x9
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x8
  unsigned int v42; // w10
  unsigned int v43; // w9
  unsigned int v44; // w10
  unsigned int v45; // w11
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x21
  unsigned __int64 v48; // x9
  unsigned int v49; // w8
  unsigned int v50; // w10
  int v51; // w8
  int v52; // w11
  __int64 v54; // x11
  __int64 v55; // x9
  unsigned int v56; // w11
  __int64 v57; // x10
  unsigned int v58; // w9
  unsigned int v59; // w11
  unsigned int v60; // w9
  unsigned int v61; // w8
  unsigned int v62; // w8

  v2 = *(_QWORD *)(a1 + 344);
  v3 = *(_DWORD *)(a1 + 52);
  v4 = raw_spin_lock_irqsave(&sample_irq_lock);
  v5 = v4;
  if ( *(_BYTE *)(a1 + 69) == 1 )
    v3 = *(_DWORD *)(a1 + 72);
  if ( *(_QWORD *)(v2 + 24) )
    v6 = 0;
  else
    v6 = (int)(ktime_get(v4) - *(_DWORD *)(a1 + 304)) / 1000000;
  if ( *(_BYTE *)(a1 + 320) != 1 || v6 >= *(_DWORD *)(a1 + 112) )
    _bw_hwmon_sample_end(*(_QWORD **)(a1 + 344));
  v7 = *(_QWORD *)(a1 + 224);
  v8 = *(_QWORD *)(a1 + 232);
  *(_BYTE *)(a1 + 320) = 0;
  *(_QWORD *)(a1 + 224) = 0;
  if ( v7 <= v8 && (v9 = *(_QWORD *)(a1 + 240)) != 0 )
  {
    if ( v7 >= 75 * v8 / 0x64 )
      v10 = *(unsigned int *)(a1 + 132);
    else
      v10 = v9 - 1;
    *(_QWORD *)(a1 + 240) = v10;
  }
  else
  {
    v11 = *(unsigned int *)(a1 + 132);
    *(_QWORD *)(a1 + 232) = v7;
    *(_QWORD *)(a1 + 240) = v11;
    v8 = v7;
  }
  v12 = *(unsigned int *)(a1 + 164);
  if ( !(_DWORD)v12 )
    goto LABEL_35;
  v13 = 100 * v7 / v3;
  if ( v13 > v12 )
  {
    v12 = *(unsigned int *)(a1 + 168);
    if ( !(_DWORD)v12 )
      goto LABEL_35;
    if ( v13 > v12 )
    {
      v12 = *(unsigned int *)(a1 + 172);
      if ( !(_DWORD)v12
        || v13 > v12
        && ((v12 = *(unsigned int *)(a1 + 176), !(_DWORD)v12)
         || v13 > v12
         && ((v12 = *(unsigned int *)(a1 + 180), !(_DWORD)v12)
          || v13 > v12
          && ((v12 = *(unsigned int *)(a1 + 184), !(_DWORD)v12)
           || v13 > v12
           && ((v12 = *(unsigned int *)(a1 + 188), !(_DWORD)v12)
            || v13 > v12
            && ((v12 = *(unsigned int *)(a1 + 192), !(_DWORD)v12)
             || v13 > v12
             && ((v12 = *(unsigned int *)(a1 + 196), !(_DWORD)v12)
              || v13 > v12 && (v12 = *(unsigned int *)(a1 + 200), v13 > v12))))))) )
      {
LABEL_35:
        v14 = 1000LL * *(unsigned int *)(*(_QWORD *)(a1 + 344) + 72LL);
        v12 = (((v14 & 0xFFFF8) * *(unsigned int *)(a1 + 12)) >> 20)
            + (unsigned int)(v14 >> 20) * (unsigned __int64)*(unsigned int *)(a1 + 12);
      }
    }
  }
  v15 = v7;
  if ( v7 <= v12 * v3 / 0x64 )
    v16 = v12 * v3 / 0x64;
  else
    v16 = v7;
  if ( *(_DWORD *)(a1 + 296) == 1 )
  {
    v17 = *(unsigned int *)(a1 + 116);
    v18 = v7 + (v7 - *(_QWORD *)(a1 + 288)) * v17 / 0x64;
    if ( v18 >= v8 )
      v19 = v8;
    else
      v19 = v7 + (v7 - *(_QWORD *)(a1 + 288)) * v17 / 0x64;
    if ( v7 >= v8 )
      v20 = v18;
    else
      v20 = v19;
    if ( v20 >= v16 )
      v15 = v16;
    else
      v15 = v20;
  }
  v21 = *(_QWORD *)(a1 + 256);
  if ( v7 > v21 && v7 > *(unsigned int *)(a1 + 152) )
  {
    v22 = *(unsigned int *)(a1 + 140);
    v23 = *(_QWORD *)(a1 + 272);
    v21 = v7;
    *(_QWORD *)(a1 + 248) = 0;
    *(_QWORD *)(a1 + 256) = v7;
    *(_QWORD *)(a1 + 264) = v22;
    if ( v23 )
    {
      v21 = v7;
      *(_QWORD *)(a1 + 272) = v22;
    }
  }
  if ( v7 >= 75 * v21 / 0x64 && v7 > *(unsigned int *)(a1 + 152) )
  {
    v24 = *(unsigned int *)(a1 + 136);
    v25 = *(_QWORD *)(a1 + 248) + 1LL;
    *(_QWORD *)(a1 + 248) = v25;
    if ( v25 >= v24 )
    {
      v26 = *(unsigned int *)(a1 + 140);
      *(_QWORD *)(a1 + 248) = 0;
      *(_QWORD *)(a1 + 272) = v26;
    }
  }
  v27 = *(_QWORD *)(a1 + 264);
  if ( v27 )
  {
    v28 = *(_QWORD *)(a1 + 272);
    v29 = v27 - 1;
    *(_QWORD *)(a1 + 264) = v27 - 1;
    if ( !v28 )
    {
      if ( v27 != 1 )
        goto LABEL_74;
      goto LABEL_68;
    }
    v30 = v28 - 1;
    *(_QWORD *)(a1 + 272) = v28 - 1;
    if ( v29 )
    {
      if ( v28 == 1 )
        goto LABEL_74;
      goto LABEL_65;
    }
  }
  else
  {
    v31 = *(_QWORD *)(a1 + 272);
    if ( !v31 )
    {
LABEL_68:
      *(_QWORD *)(a1 + 248) = 0;
      *(_QWORD *)(a1 + 256) = 0;
      goto LABEL_74;
    }
    v30 = v31 - 1;
    *(_QWORD *)(a1 + 272) = v30;
  }
  if ( !v30 )
    goto LABEL_68;
LABEL_65:
  if ( v7 <= *(unsigned int *)(a1 + 148) )
  {
    v34 = *(_QWORD *)(a1 + 280);
    if ( !v34 )
      goto LABEL_74;
    v33 = v15 > v21;
    v32 = v34 - 1;
  }
  else
  {
    v32 = *(unsigned int *)(a1 + 144);
    v33 = v15 > v21;
  }
  if ( !v33 )
    v15 = v21;
  *(_QWORD *)(a1 + 280) = v32;
LABEL_74:
  v35 = *(unsigned int *)(a1 + 152);
  if ( v7 >= v35 )
  {
    *(_QWORD *)(v2 + 232) = v15 * (unsigned int)(*(_DWORD *)(a1 + 120) + 100) / 0x64;
    *(_QWORD *)(v2 + 240) = v7 * *(unsigned int *)(a1 + 124) / 0x64;
    v36 = *(void (__fastcall **)(__int64, __int64))(v2 + 24);
    if ( v36 )
    {
LABEL_80:
      *(_DWORD *)(v2 + 248) = *(_DWORD *)(a1 + 128);
      v37 = *(unsigned int *)(a1 + 112);
      if ( *((_DWORD *)v36 - 1) != -1953942525 )
        __break(0x8229u);
      v36(v2, v37);
      goto LABEL_87;
    }
  }
  else
  {
    if ( v15 > v35 )
      v35 = v15;
    *(_QWORD *)(v2 + 232) = v35 * (unsigned int)(*(_DWORD *)(a1 + 120) + 100) / 0x64;
    *(_QWORD *)(v2 + 240) = 0;
    v7 = *(unsigned int *)(a1 + 152);
    if ( v15 >> 1 > v7 )
      v7 = v15 >> 1;
    v36 = *(void (__fastcall **)(__int64, __int64))(v2 + 24);
    if ( v36 )
      goto LABEL_80;
  }
  v38 = (((v7 * *(unsigned int *)(a1 + 112) + 999) >> 3) * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64;
  *(_DWORD *)(a1 + 300) = *(_DWORD *)(a1 + 128);
  v39 = *(_DWORD **)(v2 + 16);
  if ( *(v39 - 1) != -332346488 )
    __break(0x8229u);
  *(_QWORD *)(a1 + 216) = ((__int64 (__fastcall *)(__int64, _QWORD))v39)(v2, (v38 << 16) & 0xFFF00000);
LABEL_87:
  *(_DWORD *)(a1 + 296) = 0;
  *(_QWORD *)(a1 + 288) = v15;
  raw_spin_unlock_irqrestore(&sample_irq_lock, v5);
  v40 = *(_QWORD *)(a1 + 208);
  v41 = v15 + *(unsigned int *)(a1 + 44);
  if ( v41 <= v40 )
    LODWORD(v41) = ((int)v41 * *(_DWORD *)(a1 + 48) + (int)v40 * (100 - *(_DWORD *)(a1 + 48))) / 0x64u;
  v42 = *(_DWORD *)(a1 + 156);
  v43 = 100 * v41;
  *(_QWORD *)(a1 + 208) = (unsigned int)v41;
  if ( v42 <= 0x63 )
    LODWORD(v41) = v42 * ((unsigned int)v41 / 0x64) + (unsigned __int16)(v42 * ((unsigned int)v41 % 0x64)) / 0x64u;
  v44 = *(_DWORD *)(a1 + 108);
  v45 = ((unsigned int)v41 + v44 - 1) / v44;
  v46 = v43 / v3;
  v47 = v45 * v44;
  v48 = 1000LL * *(unsigned int *)(v2 + 72);
  v49 = ((v46 % v48) << 20) / v48 + ((unsigned int)(v46 / v48) << 20);
  v50 = *(_DWORD *)(a1 + 8);
  if ( v50 <= v49 )
    v50 = v49;
  v51 = *(unsigned __int8 *)(a1 + 60);
  if ( v50 >= *(_DWORD *)(a1 + 12) )
    v50 = *(_DWORD *)(a1 + 12);
  if ( v51 == 1 && v50 <= *(_DWORD *)(a1 + 64) )
    v50 = *(_DWORD *)(a1 + 64);
  v52 = ((v47 % v48) << 20) / v48 + ((unsigned int)(v47 / v48) << 20);
  if ( v50 == *(_DWORD *)(a1 + 16) && *(_DWORD *)(a1 + 20) == v52 )
    return 0;
  *(_DWORD *)(a1 + 16) = v50;
  *(_DWORD *)(a1 + 20) = v52;
  if ( *(_BYTE *)(v2 + 84) == 1 )
  {
    v54 = *(_QWORD *)(v2 + 160);
    if ( v54 )
    {
      v55 = v54 - 4;
      do
      {
        v56 = *(_DWORD *)(v55 + 4);
        v55 += 8;
      }
      while ( v56 && v56 < v50 );
      v57 = -8;
      if ( v56 )
        v57 = 0;
      v58 = *(_DWORD *)(v55 + v57);
      *(_DWORD *)(a1 + 28) = v58;
      if ( (v51 & 1) != 0 )
        goto LABEL_115;
      goto LABEL_112;
    }
    v59 = *(_DWORD *)(v2 + 80);
    if ( v59 )
    {
      v60 = (((v48 & 0xFFFF8) * v50) >> 20) + (v48 >> 20) * v50;
      v58 = ((v60 % (1000 * (unsigned __int64)v59)) << 20) / (1000 * (unsigned __int64)v59)
          + ((unsigned int)(v60 / (1000 * (unsigned __int64)v59)) << 20);
      *(_DWORD *)(a1 + 28) = v58;
      if ( (v51 & 1) == 0 )
      {
LABEL_112:
        v61 = *(_DWORD *)(v2 + 88);
        if ( v58 < v61 )
          v61 = v58;
        *(_DWORD *)(a1 + 28) = v61;
      }
    }
    else
    {
      v58 = 0;
      *(_DWORD *)(a1 + 28) = 0;
      if ( (v51 & 1) == 0 )
        goto LABEL_112;
    }
LABEL_115:
    v62 = *(_DWORD *)(v2 + 80);
    if ( v62 )
      v62 = ((v47 % (1000 * (unsigned __int64)v62)) << 20) / (1000 * (unsigned __int64)v62)
          + ((unsigned int)(v47 / (1000 * (unsigned __int64)v62)) << 20);
    *(_DWORD *)(a1 + 32) = v62 % 0x64 * *(_DWORD *)(a1 + 160) / 0x64 + v62 / 0x64 * *(_DWORD *)(a1 + 160);
  }
  return 1;
}
