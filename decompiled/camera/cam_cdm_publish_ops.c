__int64 cam_cdm_publish_ops()
{
  __int64 result; // x0
  _QWORD v1[3]; // [xsp+8h] [xbp-18h] BYREF

  v1[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[0] = 1;
  v1[1] = 0;
  result = cam_cdm_get_ops(0, v1, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
