__int64 __fastcall policy_mgr_get_mcc_operating_channel(__int64 a1, unsigned __int8 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  const char *v13; // x2
  unsigned int v14; // w1
  __int64 result; // x0
  unsigned int v16; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int8 v17[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[0] = 0;
  if ( (policy_mgr_is_mcc_with_this_vdev_id(a1, a2, v17) & 1) != 0 )
  {
    v16 = 0;
    if ( !(unsigned int)policy_mgr_get_chan_by_session_id(a1, v17[0], &v16) )
    {
      result = v16;
      goto LABEL_6;
    }
    v12 = v17[0];
    v13 = "%s: Failed to get channel for MCC vdev:%d";
    v14 = 2;
  }
  else
  {
    v13 = "%s: No concurrent MCC vdev for id:%d";
    v12 = a2;
    v14 = 8;
  }
  qdf_trace_msg(0x4Fu, v14, v13, v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_mcc_operating_channel", v12);
  result = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
