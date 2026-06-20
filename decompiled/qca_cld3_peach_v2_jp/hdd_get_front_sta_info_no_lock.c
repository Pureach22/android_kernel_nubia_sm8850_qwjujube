__int64 __fastcall hdd_get_front_sta_info_no_lock(_QWORD *a1, _QWORD *a2)
{
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a2 = 0;
  v4[0] = 0;
  result = qdf_list_peek_front(a1, v4);
  if ( !(_DWORD)result )
    *a2 = v4[0];
  _ReadStatusReg(SP_EL0);
  return result;
}
