__int64 __fastcall store_cpucp_log_level(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (__fastcall **v4)(__int64, int *, __int64, __int64, __int64); // x20
  __int64 v5; // x9
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x8
  int v11; // w0
  __int64 (__fastcall *v12)(__int64, int *, __int64, __int64, __int64); // x9
  __int64 v13; // x0
  int v14; // w0
  int v16; // w20
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 (__fastcall ***)(__int64, int *, __int64, __int64, __int64))(memlat_data + 312);
  if ( v4
    && ((v5 = *(_QWORD *)(memlat_data + 248)) != 0 && (*(_BYTE *)(v5 + 28) & 1) != 0
     || (v7 = *(_QWORD *)(memlat_data + 256)) != 0 && (*(_BYTE *)(v7 + 28) & 1) != 0
     || (v8 = *(_QWORD *)(memlat_data + 264)) != 0 && (*(_BYTE *)(v8 + 28) & 1) != 0
     || (v9 = *(_QWORD *)(memlat_data + 272)) != 0 && (*(_BYTE *)(v9 + 28) & 1) != 0
     || (v10 = *(_QWORD *)(memlat_data + 280)) != 0 && *(_BYTE *)(v10 + 28) == 1) )
  {
    v17 = 0;
    v11 = kstrtouint(a3, 10, &v17);
    if ( v11 < 0 )
    {
      a4 = v11;
    }
    else
    {
      mutex_lock(&memlat_lock);
      v12 = *v4;
      v13 = *(_QWORD *)(memlat_data + 320);
      if ( *((_DWORD *)*v4 - 1) != 1737159351 )
        __break(0x8229u);
      v14 = v12(v13, &v17, 0x4D454D4C4154LL, 3, 4);
      if ( v14 < 0 )
      {
        v16 = v14;
        printk(&unk_C86E);
        mutex_unlock(&memlat_lock);
        a4 = v16;
      }
      else
      {
        *(_DWORD *)(memlat_data + 332) = v17;
        mutex_unlock(&memlat_lock);
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
