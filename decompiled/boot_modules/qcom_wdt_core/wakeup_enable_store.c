__int64 __fastcall wakeup_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  int v7; // w8
  int v8; // w9
  __int64 v9; // x0
  void (__fastcall *v10)(__int64, __int64); // x9
  int v12; // w19
  int v13; // w8
  char v14[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v14[0] = 0;
  v6 = kstrtou8(a3, 10, v14);
  if ( v6 || (unsigned __int8)v14[0] >= 2u )
  {
    v12 = v6;
    dev_err(*(_QWORD *)(v5 + 8), "invalid user input\n");
    if ( v12 )
      v13 = v12;
    else
      v13 = -22;
    a4 = v13;
  }
  else
  {
    mutex_lock(v5 + 56);
    v7 = (unsigned __int8)v14[0];
    v8 = *(unsigned __int8 *)(v5 + 208);
    *(_BYTE *)(v5 + 38) = v14[0] != 0;
    if ( v8 == 1 )
    {
      if ( v7 )
        v9 = 3;
      else
        v9 = 1;
      v10 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v5 + 16) + 24LL);
      if ( *((_DWORD *)v10 - 1) != -872624411 )
        __break(0x8229u);
      v10(v9, v5);
    }
    mutex_unlock(v5 + 56);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
