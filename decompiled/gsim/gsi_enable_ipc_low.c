__int64 __fastcall gsi_enable_ipc_low(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x0
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v4 = kstrtos8_from_user(a2, a3, 0, v11);
  if ( v4 )
  {
    v3 = v4;
  }
  else
  {
    mutex_lock(gsi_ctx + 28512, v5, v6, v7, v8);
    if ( v11[0] )
      printk(&unk_2AFB0, "gsi_enable_ipc_low", 587);
    v9 = gsi_ctx + 28512;
    *(_QWORD *)(gsi_ctx + 28656) = 0;
    mutex_unlock(v9);
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
