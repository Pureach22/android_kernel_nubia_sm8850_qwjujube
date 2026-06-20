__int64 __fastcall policy_mgr_set_pcl_for_existing_combo(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _BYTE s[516]; // [xsp+4h] [xbp-20Ch] BYREF
  __int64 v16; // [xsp+208h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  result = ((__int64 (__fastcall *)(__int64, _QWORD, _BYTE *, _BYTE *, _BYTE *, __int64, _QWORD))policy_mgr_get_pcl_for_vdev_id)(
             a1,
             a2,
             s,
             &s[512],
             &s[408],
             102,
             a3);
  if ( !(_DWORD)result )
  {
    result = policy_mgr_set_pcl(a1, s, a3, 0);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: Send set PCL to policy mgr failed",
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 "policy_mgr_set_pcl_for_existing_combo");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
