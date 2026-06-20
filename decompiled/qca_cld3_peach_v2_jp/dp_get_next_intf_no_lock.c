__int64 __fastcall dp_get_next_intf_no_lock(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    *a3 = 0;
    v5[0] = 0;
    result = qdf_list_peek_next((_QWORD *)(a1 + 280), (_QWORD *)(a2 + 32), v5);
    if ( !(_DWORD)result )
      *a3 = v5[0] - 32LL;
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
