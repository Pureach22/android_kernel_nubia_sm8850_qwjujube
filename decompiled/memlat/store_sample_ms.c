__int64 __fastcall store_sample_ms(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (__fastcall **v5)(__int64, unsigned int *, __int64, __int64, __int64); // x20
  int v6; // w0
  unsigned int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 (__fastcall *v14)(__int64, unsigned int *, __int64, __int64, __int64); // x9
  __int64 v15; // x0
  int v16; // w0
  int v18; // w20
  unsigned int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v5 = *(__int64 (__fastcall ***)(__int64, unsigned int *, __int64, __int64, __int64))(memlat_data + 312);
  v6 = kstrtouint(a3, 10, &v19);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else
  {
    v7 = v19;
    if ( v19 <= 4 )
      v7 = 4;
    if ( v7 >= 0x3E8 )
      v7 = 1000;
    v19 = v7;
    mutex_lock(&memlat_lock);
    v8 = memlat_data;
    if ( *(_QWORD *)(memlat_data + 312) )
    {
      if ( (v9 = *(_QWORD *)(memlat_data + 248)) != 0 && (*(_BYTE *)(v9 + 28) & 1) != 0
        || (v10 = *(_QWORD *)(memlat_data + 256)) != 0 && (*(_BYTE *)(v10 + 28) & 1) != 0
        || (v11 = *(_QWORD *)(memlat_data + 264)) != 0 && (*(_BYTE *)(v11 + 28) & 1) != 0
        || (v12 = *(_QWORD *)(memlat_data + 272)) != 0 && (*(_BYTE *)(v12 + 28) & 1) != 0
        || (v13 = *(_QWORD *)(memlat_data + 280)) != 0 && *(_BYTE *)(v13 + 28) == 1 )
      {
        v14 = *v5;
        v15 = *(_QWORD *)(memlat_data + 320);
        if ( *((_DWORD *)*v5 - 1) != 1737159351 )
          __break(0x8229u);
        v16 = v14(v15, &v19, 0x4D454D4C4154LL, 31, 4);
        if ( v16 < 0 )
        {
          v18 = v16;
          printk(&unk_C925);
          mutex_unlock(&memlat_lock);
          a4 = v18;
          goto LABEL_23;
        }
        v8 = memlat_data;
      }
    }
    *(_DWORD *)(v8 + 160) = v19;
    mutex_unlock(&memlat_lock);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return a4;
}
