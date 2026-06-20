__int64 __fastcall block_size_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  __int64 v7; // x1
  __int64 v8; // x8
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v10[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( !(unsigned int)kstrtoull(a3, 0, v10) )
  {
    v8 = *(_QWORD *)(v6 + 304);
    if ( v8 )
    {
      if ( (unsigned __int64)(v10[0] - 1LL) > 0xFFE )
      {
        mutex_lock(v8 + 312);
        *(_DWORD *)(*(_QWORD *)(v6 + 304) + 152LL) = v10[0];
        mutex_unlock(*(_QWORD *)(v6 + 304) + 312LL);
        goto LABEL_6;
      }
      printk(&unk_1000D, v7);
    }
  }
  a4 = -22;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return a4;
}
