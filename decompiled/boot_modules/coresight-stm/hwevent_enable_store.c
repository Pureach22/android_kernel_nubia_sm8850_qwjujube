__int64 __fastcall hwevent_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w8
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v9[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 16, v9) )
  {
    a4 = -22;
  }
  else
  {
    v7 = v9[0];
    *(_DWORD *)(v6 + 164) = v9[0];
    *(_DWORD *)(v6 + 168) = v7;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
