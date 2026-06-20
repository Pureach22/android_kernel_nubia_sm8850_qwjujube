__int64 __fastcall dspp_vlut(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 (__fastcall *v3)(); // x8

  v1 = result;
  v2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 500LL);
  if ( v2 == 65544 )
  {
    result = reg_dmav1_init_dspp_op_v4(0xAu, result);
    if ( (_DWORD)result )
      v3 = sde_setup_dspp_pa_vlut_v1_8;
    else
      v3 = (__int64 (__fastcall *)())reg_dmav1_setup_dspp_vlutv18;
  }
  else
  {
    if ( v2 != 65543 )
      return result;
    v3 = sde_setup_dspp_pa_vlut_v1_7;
  }
  *(_QWORD *)(v1 + 424) = v3;
  return result;
}
