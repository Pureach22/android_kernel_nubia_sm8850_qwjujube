__int64 __fastcall dspp_pcc(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 (__fastcall *v3)(); // x8

  v1 = result;
  v2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 68LL);
  if ( v2 >= 327680 )
  {
    if ( v2 == 327680 || v2 == 393216 )
    {
      result = reg_dmav1_init_dspp_op_v4(2u, result);
      if ( !(_DWORD)result )
      {
        *(_QWORD *)(v1 + 208) = reg_dmav1_setup_dspp_pccv5;
        *(_QWORD *)(v1 + 216) = reg_dmav1_setup_dspp_pccv6;
      }
    }
  }
  else
  {
    if ( v2 == 65543 )
    {
      v3 = sde_setup_dspp_pcc_v1_7;
    }
    else
    {
      if ( v2 != 0x40000 )
        return result;
      result = reg_dmav1_init_dspp_op_v4(2u, result);
      if ( (_DWORD)result )
        v3 = (__int64 (__fastcall *)())sde_setup_dspp_pccv4;
      else
        v3 = (__int64 (__fastcall *)())reg_dmav1_setup_dspp_pccv4;
    }
    *(_QWORD *)(v1 + 208) = v3;
  }
  return result;
}
