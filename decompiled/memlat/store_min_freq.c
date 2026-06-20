__int64 __fastcall store_min_freq(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x23
  __int64 (__fastcall **v7)(__int64, __int64 *, __int64, __int64, __int64); // x22
  int v8; // w0
  unsigned int v9; // w8
  int v10; // w9
  __int64 (__fastcall *v11)(__int64, __int64 *, __int64, __int64, __int64); // x9
  __int64 v12; // x0
  int v13; // w0
  int v15; // w21
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v17; // [xsp+10h] [xbp-10h]
  unsigned int v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 - 80);
  v18 = 0;
  v7 = *(__int64 (__fastcall ***)(__int64, __int64 *, __int64, __int64, __int64))(memlat_data + 312);
  v17 = 0;
  v16 = 0;
  v8 = kstrtouint(a3, 10, &v18);
  if ( v8 < 0 )
  {
    a4 = v8;
  }
  else
  {
    v9 = v18;
    if ( v18 <= *(_DWORD *)(v6 + 84) )
      v9 = *(_DWORD *)(v6 + 84);
    if ( v9 >= *(_DWORD *)(a1 - 8) )
      v9 = *(_DWORD *)(a1 - 8);
    v18 = v9;
    mutex_lock(a1 + 104);
    if ( (*(_BYTE *)(a1 - 72) & 4) == 0 || !v7 )
      goto LABEL_11;
    v10 = *(_DWORD *)(a1 + 100);
    LODWORD(v16) = *(_DWORD *)(v6 + 16);
    HIDWORD(v16) = v10;
    v17 = v18;
    v11 = *v7;
    v12 = *(_QWORD *)(memlat_data + 320);
    if ( *((_DWORD *)*v7 - 1) != 1737159351 )
      __break(0x8229u);
    v13 = v11(v12, &v16, 0x4D454D4C4154LL, 33, 12);
    if ( v13 < 0 )
    {
      v15 = v13;
      printk(&unk_CAC0);
      mutex_unlock(a1 + 104);
      a4 = v15;
    }
    else
    {
LABEL_11:
      *(_DWORD *)(a1 - 12) = v18;
      mutex_unlock(a1 + 104);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
