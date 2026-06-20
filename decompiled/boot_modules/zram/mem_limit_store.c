__int64 __fastcall mem_limit_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v9; // x20
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 - 224);
  v11[0] = 0;
  v7 = *(_QWORD *)(v6 + 88);
  v8 = memparse(a3, v11);
  if ( v11[0] == a3 )
  {
    a4 = -22;
  }
  else
  {
    v9 = v8;
    down_write(v7 + 32);
    *(_QWORD *)(v7 + 96) = (unsigned __int64)(v9 + 4095) >> 12;
    up_write(v7 + 32);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
