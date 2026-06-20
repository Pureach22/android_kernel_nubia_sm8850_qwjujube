__int64 __fastcall store_adaptive_high_freq(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (__fastcall **v6)(__int64, __int64 *, __int64, __int64, __int64); // x23
  int v7; // w0
  int v8; // w8
  __int64 (__fastcall *v9)(__int64, __int64 *, __int64, __int64, __int64); // x9
  __int64 v10; // x0
  int v11; // w0
  int v13; // w22
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v15; // [xsp+10h] [xbp-10h]
  unsigned int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v15 = 0;
  v6 = *(__int64 (__fastcall ***)(__int64, __int64 *, __int64, __int64, __int64))(memlat_data + 312);
  v14 = 0;
  v7 = kstrtouint(a3, 10, &v16);
  if ( v7 < 0 )
  {
    a4 = v7;
  }
  else
  {
    v8 = v16;
    if ( v16 >= 0x7A1200 )
      v8 = 8000000;
    v16 = v8;
    mutex_lock(a1 - 48);
    if ( *(_BYTE *)(a1 - 180) != 1 || !v6 )
      goto LABEL_9;
    v14 = *(unsigned int *)(a1 - 192);
    v15 = v16;
    v9 = *v6;
    v10 = *(_QWORD *)(memlat_data + 320);
    if ( *((_DWORD *)*v6 - 1) != 1737159351 )
      __break(0x8229u);
    v11 = v9(v10, &v14, 0x4D454D4C4154LL, 21, 12);
    if ( v11 < 0 )
    {
      v13 = v11;
      printk(&unk_C295);
      mutex_unlock(a1 - 48);
      a4 = v13;
    }
    else
    {
LABEL_9:
      *(_DWORD *)(a1 - 168) = v16;
      mutex_unlock(a1 - 48);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
