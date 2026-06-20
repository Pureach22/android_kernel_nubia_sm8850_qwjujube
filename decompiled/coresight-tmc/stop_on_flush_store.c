__int64 __fastcall stop_on_flush_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v8[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 0, v8) || v8[0] > 1u )
    a4 = -22;
  else
    *(_BYTE *)(v6 + 344) = v8[0];
  _ReadStatusReg(SP_EL0);
  return a4;
}
