__int64 __fastcall store_boost_freq(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  unsigned int v7; // w8
  __int64 v8; // x21
  int v9; // w8
  _QWORD *v10; // x10
  unsigned int v11; // w8
  int v12; // w11
  unsigned int v13; // w12
  __int64 v14; // x11
  __int64 v15; // x9
  int v16; // w10
  int v17; // w12
  unsigned int v18; // w11
  unsigned int v19; // w11
  int v20; // w8
  __int64 (__fastcall *v21)(__int64, unsigned int *, __int64); // x8
  unsigned int v22; // w0
  unsigned int v24; // [xsp+8h] [xbp-18h] BYREF
  int v25; // [xsp+Ch] [xbp-14h]
  int v26; // [xsp+10h] [xbp-10h]
  unsigned int v27; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v6 = kstrtouint(a3, 10, &v27);
  if ( v6 < 0 )
  {
    a4 = v6;
    goto LABEL_31;
  }
  v7 = v27;
  if ( v27 > *(_DWORD *)(a1 + 124) )
  {
    a4 = -22;
    goto LABEL_31;
  }
  v8 = *(_QWORD *)(a1 + 136);
  if ( !v8 )
  {
    a4 = -1;
    goto LABEL_31;
  }
  if ( v27 <= *(_DWORD *)(a1 + 120) )
    v7 = *(_DWORD *)(a1 + 120);
  v27 = v7;
  *(_DWORD *)(a1 + 128) = v7;
  mutex_lock(v8 + 72);
  v9 = *(_DWORD *)(a1 + 96);
  v10 = *(_QWORD **)(v8 + 48);
  v25 = 0;
  v26 = v9;
  v11 = 0;
  if ( v10 != (_QWORD *)(v8 + 48) )
  {
    v12 = 0;
    do
    {
      v13 = *((_DWORD *)v10 - 4);
      v12 += *((_DWORD *)v10 - 3);
      v25 = v12;
      if ( v13 > v11 )
        v11 = v13;
      v10 = (_QWORD *)*v10;
    }
    while ( v10 != (_QWORD *)(v8 + 48) );
  }
  v14 = *(_QWORD *)(v8 + 16);
  v15 = *(_QWORD *)(v14 + 112);
  v16 = *(_DWORD *)(v14 + 120);
  if ( *(_DWORD *)(v8 + 8) )
  {
    v17 = 0;
    if ( v16 )
      goto LABEL_15;
    goto LABEL_22;
  }
  v19 = *(_DWORD *)(v14 + 136);
  if ( v19 > v11 )
    v11 = v19;
  v17 = 0;
  if ( !v16 )
  {
LABEL_22:
    v18 = 0;
    goto LABEL_23;
  }
LABEL_15:
  while ( 1 )
  {
    v18 = *(_DWORD *)(v15 + 4LL * v17);
    if ( v11 <= v18 )
      break;
    if ( v16 == ++v17 )
      goto LABEL_24;
  }
LABEL_23:
  if ( v17 == v16 )
LABEL_24:
    v18 = *(_DWORD *)(v15 + 4LL * (unsigned int)(v16 - 1));
  v20 = *(_DWORD *)(v8 + 24);
  v24 = v18;
  if ( v18 != v20 )
  {
    v21 = *(__int64 (__fastcall **)(__int64, unsigned int *, __int64))(v8 + 128);
    if ( *((_DWORD *)v21 - 1) != -556726186 )
      __break(0x8228u);
    v22 = v21(v8, &v24, 1);
    if ( (v22 & 0x80000000) != 0 )
      printk(&unk_C75B, v22);
  }
  mutex_unlock(v8 + 72);
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return a4;
}
