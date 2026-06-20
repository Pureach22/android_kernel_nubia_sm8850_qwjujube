__int64 __fastcall dspp_gamut(__int64 result, double a2, double a3, double a4, double a5)
{
  __int64 v5; // x19
  int v6; // w8
  void *v7; // x8

  v5 = result;
  v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 248LL);
  if ( v6 <= 262145 )
  {
    if ( v6 == 0x40000 )
    {
      result = reg_dmav1_init_dspp_op_v4(7u, result);
      if ( (_DWORD)result )
        v7 = sde_setup_dspp_3d_gamutv4;
      else
        v7 = reg_dmav1_setup_dspp_3d_gamutv4;
    }
    else
    {
      if ( v6 != 262145 )
        return result;
      result = reg_dmav1_init_dspp_op_v4(7u, result);
      if ( (_DWORD)result )
        v7 = sde_setup_dspp_3d_gamutv41;
      else
        v7 = reg_dmav1_setup_dspp_3d_gamutv41;
    }
LABEL_16:
    *(_QWORD *)(v5 + 472) = v7;
    return result;
  }
  if ( v6 == 262146 )
  {
    result = reg_dmav1_init_dspp_op_v4(7u, result);
    if ( (_DWORD)result )
      return result;
    v7 = reg_dmav1_setup_dspp_3d_gamutv42;
    goto LABEL_16;
  }
  if ( v6 == 262147 )
  {
    result = reg_dmav2_init_dspp_op_v4(7, result, a2, a3, a4, a5);
    if ( !(_DWORD)result )
    {
      *(_QWORD *)(v5 + 472) = reg_dmav2_setup_dspp_3d_gamutv43;
      *(_QWORD *)(v5 + 480) = reg_dmav2_setup_dspp_3d_gamutv43;
    }
  }
  return result;
}
