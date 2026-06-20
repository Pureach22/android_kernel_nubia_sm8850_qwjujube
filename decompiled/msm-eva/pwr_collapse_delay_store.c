__int64 __fastcall pwr_collapse_delay_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  __int64 v6; // x9
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v5 = kstrtoull(a3, 0, v8);
  if ( v5 )
  {
    a4 = v5;
  }
  else if ( v8[0] && (v6 = *(_QWORD *)(cvp_driver + 48)) != 0 )
  {
    *(_DWORD *)(v6 + 1040) = v8[0];
  }
  else
  {
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
