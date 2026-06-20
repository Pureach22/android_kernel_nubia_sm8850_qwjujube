__int64 __fastcall frames_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  int v6; // w8
  __int64 result; // x0
  __int16 v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( *(_BYTE *)(v4 + 226) == 1 )
  {
    dev_err(*(_QWORD *)(v4 + 8), "Failed to configure frames, ECM is already running\n");
    result = -22;
  }
  else
  {
    v6 = kstrtou16(a3, 0, &v8);
    result = -22;
    if ( (v6 & 0x80000000) == 0 && v8 )
    {
      result = a4;
      *(_WORD *)(v4 + 32) = v8;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
