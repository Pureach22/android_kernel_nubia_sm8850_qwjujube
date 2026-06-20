__int64 __fastcall profile_index_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x20
  __int64 v7; // x21
  int v8; // w8
  unsigned int v9; // w3
  __int64 v10; // x9
  __int64 v11; // x9
  int v12; // w21
  __int64 v13; // x0
  void *v15; // x0
  unsigned int v16; // [xsp+Ch] [xbp-74h] BYREF
  _QWORD v17[12]; // [xsp+10h] [xbp-70h] BYREF
  int v18; // [xsp+70h] [xbp-10h]
  __int64 v19; // [xsp+78h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  v7 = ktime_get();
  v16 = 0;
  if ( (unsigned int)kstrtouint(a3, 0, &v16) )
  {
    a4 = -22;
    goto LABEL_17;
  }
  if ( v16 >= 0xB )
  {
    printk(&unk_6659);
    a4 = -22;
    goto LABEL_17;
  }
  mutex_lock(v6);
  v8 = *(_DWORD *)(v6 + 60);
  v9 = v16;
  if ( v8 && v16 )
  {
    v10 = *(_QWORD *)(v6 + 72);
  }
  else
  {
    if ( v8 || !v16 )
      goto LABEL_11;
    v10 = *(_QWORD *)(v6 + 80);
  }
  v11 = (unsigned __int128)((v7 - v10) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
  if ( (__int64)((v11 >> 7) + ((unsigned __int64)v11 >> 63)) < 1000LL * *(unsigned int *)(v6 + 64) )
  {
    v15 = &unk_6677;
    goto LABEL_22;
  }
LABEL_11:
  if ( v16 == v8 )
  {
    v15 = &unk_65E1;
LABEL_22:
    printk(v15);
    mutex_unlock(v6);
    a4 = -16;
    goto LABEL_17;
  }
  *(_DWORD *)(v6 + 56) = v16;
  scnprintf(v17, 100, "{class: fdcvs, profile_index: %d}", v9);
  if ( (unsigned int)qmp_send(*(_QWORD *)(v6 + 48), v17, 100) )
  {
    printk(&unk_6638);
  }
  else
  {
    v12 = *(_DWORD *)(v6 + 56);
    *(_DWORD *)(v6 + 60) = v12;
    v13 = ktime_get();
    if ( v12 )
      *(_QWORD *)(v6 + 72) = v13;
    else
      *(_QWORD *)(v6 + 80) = v13;
  }
  mutex_unlock(v6);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return a4;
}
