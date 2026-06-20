__int64 __fastcall cdsprm_cxlimit_camera_activity_notify(int a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  _DWORD v4[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( byte_A3D8 == 1 )
  {
    result = 0;
    dword_A3E0 = a1;
    if ( qword_A350 && gcdsprm[0] )
    {
      v3 = *(_QWORD *)(qword_A350 + 968);
      v4[0] = 11;
      v4[1] = a1;
      v4[2] = 12;
      rpmsg_send(v3, v4, 12);
      result = 0;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
