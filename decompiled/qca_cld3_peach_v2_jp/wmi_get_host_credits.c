__int64 __fastcall wmi_get_host_credits(__int64 a1)
{
  __int64 v1; // x0
  unsigned int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 64);
  v3 = 0;
  htc_get_control_endpoint_tx_host_credits(v1, &v3);
  _ReadStatusReg(SP_EL0);
  return v3;
}
