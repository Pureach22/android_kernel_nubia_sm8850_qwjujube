__int64 __fastcall cdsprm_compute_core_set_priority(int a1)
{
  __int64 v1; // x8
  _DWORD v3[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v4; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dword_A3A0 = a1;
  if ( qword_A350 && gcdsprm )
  {
    v1 = *(_QWORD *)(qword_A350 + 968);
    v3[0] = 3;
    v3[1] = a1;
    v3[2] = 12;
    rpmsg_send(v1, v3, 12);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
