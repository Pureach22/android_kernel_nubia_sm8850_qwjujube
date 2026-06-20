__int64 __fastcall dsi_conn_enable_event(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  _QWORD v5[4]; // [xsp+0h] [xbp-20h] BYREF

  v5[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[1] = a1;
  v5[2] = sde_connector_trigger_event;
  v5[0] = 0;
  result = dsi_display_enable_event(a1, a4, a2, v5, a3);
  _ReadStatusReg(SP_EL0);
  return result;
}
