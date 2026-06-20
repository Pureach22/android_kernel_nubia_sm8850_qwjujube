bool __fastcall policy_mgr_is_curr_hwmode_emlsr(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x8
  __int64 v12; // x9
  const char *v13; // x2
  const char *v14; // x3
  _BOOL8 result; // x0
  __int64 v16; // [xsp+0h] [xbp-20h] BYREF
  __int64 v17; // [xsp+8h] [xbp-18h]
  unsigned int v18; // [xsp+10h] [xbp-10h] BYREF
  int v19; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v13 = "%s: Invalid Context";
    v14 = "policy_mgr_is_hw_emlsr_capable";
LABEL_13:
    qdf_trace_msg(0x4Fu, 2u, v13, v3, v4, v5, v6, v7, v8, v9, v10, v14, v16, v17);
    goto LABEL_14;
  }
  v11 = *(unsigned int *)(context + 1184);
  if ( (_DWORD)v11 )
  {
    v12 = *(_QWORD *)(context + 1192);
    while ( (*(_BYTE *)(v12 + 4) & 1) == 0 )
    {
      --v11;
      v12 += 8;
      if ( !v11 )
        goto LABEL_14;
    }
    v19 = 0;
    v18 = 0;
    if ( !(unsigned int)policy_mgr_get_old_and_new_hw_index(a1, &v19, &v18) )
    {
      if ( v18 == 0xFFFF )
      {
        v13 = "%s: HW mode is not yet initialized";
        goto LABEL_12;
      }
      if ( !(unsigned int)policy_mgr_get_hw_mode_from_idx(a1, v18, (__int64)&v16) )
      {
        result = BYTE2(v17) != 0;
        goto LABEL_15;
      }
    }
    v13 = "%s: Failed to get HW mode index";
LABEL_12:
    v14 = "policy_mgr_get_current_hw_mode";
    goto LABEL_13;
  }
LABEL_14:
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
