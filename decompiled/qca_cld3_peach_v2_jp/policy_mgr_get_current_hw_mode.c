__int64 __fastcall policy_mgr_get_current_hw_mode(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  if ( !(unsigned int)policy_mgr_get_old_and_new_hw_index(a1, (_DWORD *)v14 + 1, v14) )
  {
    if ( LODWORD(v14[0]) == 0xFFFF )
    {
      v12 = "%s: HW mode is not yet initialized";
      goto LABEL_5;
    }
    result = policy_mgr_get_hw_mode_from_idx(a1, v14[0], a2);
    if ( !(_DWORD)result )
      goto LABEL_6;
  }
  v12 = "%s: Failed to get HW mode index";
LABEL_5:
  qdf_trace_msg(0x4Fu, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_current_hw_mode");
  result = 16;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
