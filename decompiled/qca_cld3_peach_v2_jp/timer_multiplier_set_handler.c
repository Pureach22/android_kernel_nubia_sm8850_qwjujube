__int64 __fastcall timer_multiplier_set_handler(__int64 a1)
{
  unsigned int v1; // w0
  __int64 result; // x0
  unsigned int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  v1 = qdf_uint32_parse(a1, &v3);
  if ( v1 )
  {
    result = qdf_status_to_os_return(v1);
  }
  else if ( v3 )
  {
    qdf_timer_set_multiplier(v3);
    result = 0;
  }
  else
  {
    result = 4294967262LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
