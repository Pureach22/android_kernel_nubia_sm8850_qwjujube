__int64 __fastcall qbg_blob_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v7; // x22
  int v8; // w9
  int v9; // w0
  int v10; // w21
  __int64 v11; // x2
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  int v14; // [xsp+10h] [xbp-10h]
  int v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 152);
  v13 = 0x10000800DLL;
  v8 = *(_DWORD *)(v7 + 4780);
  v14 = 54;
  v15 = v8;
  mutex_lock(v7 + 16);
  *(_DWORD *)(v7 + 64) = 0;
  v9 = pmic_glink_write(*(_QWORD *)(v7 + 8), &v13, 16);
  if ( v9 )
  {
    v10 = v9;
    mutex_unlock(v7 + 16);
    if ( v10 < 0 )
      a6 = v10;
  }
  else if ( (unsigned int)wait_for_completion_timeout(v7 + 64, 250) )
  {
    mutex_unlock(v7 + 16);
  }
  else
  {
    printk(&unk_750C, "battery_dbg_write", v11);
    mutex_unlock(v7 + 16);
    a6 = -110;
  }
  _ReadStatusReg(SP_EL0);
  return a6;
}
