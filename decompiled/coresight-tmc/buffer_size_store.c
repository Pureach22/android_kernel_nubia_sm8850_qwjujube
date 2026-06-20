__int64 __fastcall buffer_size_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( *(_DWORD *)(v4 + 140) == 1 )
  {
    v7[0] = 0;
    LODWORD(result) = kstrtoull(a3, 0, v7);
    if ( (_DWORD)result )
    {
      result = (int)result;
    }
    else if ( (v7[0] & 0xFFF) != 0 )
    {
      result = -22;
    }
    else
    {
      result = a4;
      *(_DWORD *)(v4 + 132) = v7[0];
    }
  }
  else
  {
    result = -1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
