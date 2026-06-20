__int64 __fastcall target_if_sops_is_spectral_active(__int64 a1, __int64 a2)
{
  int v2; // w0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v2 = target_if_spectral_info_read(a1, a2, 0, v4, 1);
  _ReadStatusReg(SP_EL0);
  if ( v2 )
    return 0;
  else
    return v4[0];
}
