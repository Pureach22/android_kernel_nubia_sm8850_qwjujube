__int64 __fastcall wlan_mlo_list_peek_head(_QWORD *a1)
{
  int v1; // w0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  v1 = qdf_list_peek_front(a1, v3);
  _ReadStatusReg(SP_EL0);
  if ( v1 )
    return 0;
  else
    return v3[0];
}
