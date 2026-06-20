__int64 __fastcall dspp_sixzone(__int64 result, double a2, double a3, double a4, double a5)
{
  __int64 v5; // x19
  int v6; // w8
  size_t (__fastcall *v7)(__int64, __int64 **); // x8

  v5 = result;
  v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 212LL);
  if ( v6 == 0x20000 )
  {
    result = reg_dmav2_init_dspp_op_v4(6, result, a2, a3, a4, a5);
    if ( !(_DWORD)result )
    {
      *(_QWORD *)(v5 + 352) = reg_dmav2_setup_dspp_sixzonev2;
      *(_QWORD *)(v5 + 360) = reg_dmav2_setup_dspp_sixzonev2;
    }
  }
  else if ( v6 == 65543 )
  {
    result = reg_dmav1_init_dspp_op_v4(6u, result);
    if ( (_DWORD)result )
      v7 = (size_t (__fastcall *)(__int64, __int64 **))sde_setup_dspp_sixzone_v17;
    else
      v7 = reg_dmav1_setup_dspp_sixzonev17;
    *(_QWORD *)(v5 + 352) = v7;
  }
  return result;
}
