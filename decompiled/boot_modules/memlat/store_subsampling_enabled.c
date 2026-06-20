__int64 __fastcall store_subsampling_enabled(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (__fastcall **v4)(__int64, int *, __int64, __int64, __int64); // x20
  __int64 v5; // x9
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x8
  int v11; // w0
  int v12; // w22
  __int64 (__fastcall *v13)(__int64, int *, __int64, __int64, __int64); // x9
  __int64 v14; // x0
  int v15; // w0
  int v17; // w20
  int v18; // [xsp+0h] [xbp-10h] BYREF
  char v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 (__fastcall ***)(__int64, int *, __int64, __int64, __int64))(memlat_data + 312);
  if ( v4
    && ((v5 = *(_QWORD *)(memlat_data + 248)) != 0 && (*(_BYTE *)(v5 + 28) & 1) != 0
     || (v7 = *(_QWORD *)(memlat_data + 256)) != 0 && (*(_BYTE *)(v7 + 28) & 1) != 0
     || (v8 = *(_QWORD *)(memlat_data + 264)) != 0 && (*(_BYTE *)(v8 + 28) & 1) != 0
     || (v9 = *(_QWORD *)(memlat_data + 272)) != 0 && (*(_BYTE *)(v9 + 28) & 1) != 0
     || (v10 = *(_QWORD *)(memlat_data + 280)) != 0 && *(_BYTE *)(v10 + 28) == 1) )
  {
    v19[0] = 0;
    v11 = kstrtobool(a3, v19);
    if ( v11 < 0 )
    {
      a4 = v11;
    }
    else
    {
      v12 = (unsigned __int8)v19[0];
      v18 = (unsigned __int8)v19[0];
      mutex_lock(&memlat_lock);
      if ( v12 != *(unsigned __int8 *)(memlat_data + 328) )
      {
        v13 = *v4;
        v14 = *(_QWORD *)(memlat_data + 320);
        if ( *((_DWORD *)*v4 - 1) != 1737159351 )
          __break(0x8229u);
        v15 = v13(v14, &v18, 0x4D454D4C4154LL, 41, 4);
        if ( v15 < 0 )
        {
          v17 = v15;
          printk(&unk_C52D);
          mutex_unlock(&memlat_lock);
          a4 = v17;
        }
        else
        {
          *(_BYTE *)(memlat_data + 328) = v18 != 0;
          mutex_unlock(&memlat_lock);
        }
      }
    }
  }
  else
  {
    a4 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
