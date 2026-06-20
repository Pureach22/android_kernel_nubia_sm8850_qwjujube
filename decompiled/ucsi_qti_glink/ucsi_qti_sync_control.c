__int64 __fastcall ucsi_qti_sync_control(__int64 a1, __int64 a2)
{
  __int64 drvdata; // x0
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = a2;
  drvdata = ucsi_get_drvdata(a1, a2);
  result = ucsi_qti_glink_write(drvdata, v4, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
