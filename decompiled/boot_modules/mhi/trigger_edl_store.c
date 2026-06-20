__int64 __fastcall trigger_edl_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 result; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 - 24);
  v8[0] = 0;
  LODWORD(result) = kstrtoull(a3, 10, v8);
  if ( (result & 0x80000000) != 0 )
  {
    result = (int)result;
  }
  else if ( v8[0] )
  {
    v7 = *(__int64 (__fastcall **)(_QWORD))(v5 + 592);
    if ( *((_DWORD *)v7 - 1) != -700558418 )
      __break(0x8228u);
    LODWORD(result) = v7(v5);
    if ( (_DWORD)result )
      result = (int)result;
    else
      result = a4;
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
