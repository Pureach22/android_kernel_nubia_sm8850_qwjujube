__int64 __fastcall phase_sync_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  __int64 *v8; // x8
  __int64 v9; // x1
  _BOOL4 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v6 = kstrtouint(a3, 10, &v10);
  if ( v6 < 0 )
  {
    a4 = v6;
  }
  else
  {
    v8 = *(__int64 **)(v5 + 64);
    v9 = v8[14];
    v10 = v10;
    if ( !v9 )
      v9 = *v8;
    printk(&unk_225EC, v9, "phase_sync_store");
    *(_BYTE *)(v5 + 16) = v10;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
