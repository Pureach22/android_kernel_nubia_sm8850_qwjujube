__int64 __fastcall dspp_igc(__int64 result, double a2, double a3, double a4, double a5)
{
  __int64 v5; // x19
  int v6; // w8
  void *v7; // x8

  v5 = result;
  v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 32LL);
  if ( v6 >= 327680 )
  {
    if ( v6 == 327680 )
    {
      result = reg_dmav2_init_dspp_op_v4(1, result, a2, a3, a4, a5);
      if ( (_DWORD)result )
        return result;
      v7 = reg_dmav2_setup_dspp_igcv5;
      goto LABEL_15;
    }
    if ( v6 == 327681 )
    {
      result = reg_dmav2_init_dspp_op_v4(1, result, a2, a3, a4, a5);
      if ( !(_DWORD)result )
      {
        *(_QWORD *)(v5 + 160) = reg_dmav2_setup_dspp_igcv51;
        *(_QWORD *)(v5 + 168) = reg_dmav2_setup_dspp_igcv51;
      }
    }
  }
  else
  {
    if ( v6 == 196609 )
    {
      result = reg_dmav1_init_dspp_op_v4(1u, result);
      if ( (_DWORD)result )
        v7 = sde_setup_dspp_igcv3;
      else
        v7 = reg_dmav1_setup_dspp_igcv31;
      goto LABEL_15;
    }
    if ( v6 == 0x40000 )
    {
      result = reg_dmav2_init_dspp_op_v4(1, result, a2, a3, a4, a5);
      if ( !(_DWORD)result )
      {
        v7 = reg_dmav2_setup_dspp_igcv4;
LABEL_15:
        *(_QWORD *)(v5 + 160) = v7;
      }
    }
  }
  return result;
}
