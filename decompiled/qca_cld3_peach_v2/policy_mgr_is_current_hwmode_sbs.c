_DWORD *__fastcall policy_mgr_is_current_hwmode_sbs(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  _DWORD *result; // x0
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  __int64 v13; // [xsp+8h] [xbp-18h]
  unsigned int v14; // [xsp+10h] [xbp-10h] BYREF
  int v15; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0 )
    goto LABEL_7;
  v15 = 0;
  v14 = 0;
  if ( (unsigned int)policy_mgr_get_old_and_new_hw_index(a1, &v15, &v14) )
    goto LABEL_3;
  if ( v14 == 0xFFFF )
  {
    v10 = "%s: HW mode is not yet initialized";
    goto LABEL_6;
  }
  if ( (unsigned int)policy_mgr_get_hw_mode_from_idx(a1, v14, (__int64)&v12) )
  {
LABEL_3:
    v10 = "%s: Failed to get HW mode index";
LABEL_6:
    qdf_trace_msg(0x4Fu, 2u, v10, v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_get_current_hw_mode", v12, v13);
    goto LABEL_7;
  }
  if ( BYTE1(v13) )
  {
    result = (_DWORD *)policy_mgr_get_context(a1);
    if ( !result )
      goto LABEL_8;
    if ( result[365] && result[367] || result[369] && result[371] )
    {
      result = (_DWORD *)(&off_0 + 1);
      goto LABEL_8;
    }
  }
LABEL_7:
  result = nullptr;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
