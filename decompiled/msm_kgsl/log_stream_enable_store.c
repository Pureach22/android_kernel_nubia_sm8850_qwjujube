__int64 __fastcall log_stream_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v6 = kstrtobool(a3, v8);
  if ( v6 )
    a4 = v6;
  else
    *(_BYTE *)(a1 - 8) = v8[0];
  _ReadStatusReg(SP_EL0);
  return a4;
}
