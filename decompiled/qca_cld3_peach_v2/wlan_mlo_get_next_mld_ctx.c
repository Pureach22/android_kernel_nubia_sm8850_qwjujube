__int64 __fastcall wlan_mlo_get_next_mld_ctx(_QWORD *a1, _QWORD *a2)
{
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  if ( a2 )
  {
    if ( (unsigned int)qdf_list_peek_next(a1, a2, v3) )
      result = 0;
    else
      result = v3[0];
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
