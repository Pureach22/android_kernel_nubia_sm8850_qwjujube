__int64 __fastcall cdsprm_compute_prio_write(__int64 a1, int a2)
{
  __int64 v2; // x0
  _DWORD v4[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v5; // [xsp+18h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dword_A3A0 = a2;
  if ( qword_A350 && gcdsprm[0] )
  {
    v2 = *(_QWORD *)(qword_A350 + 968);
    v4[0] = 3;
    v4[1] = a2;
    v4[2] = 12;
    rpmsg_send(v2, v4, 12);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
