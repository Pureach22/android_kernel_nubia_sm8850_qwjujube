__int64 __fastcall dspp_hsic(__int64 result)
{
  __int64 v1; // x19

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 140LL) == 65543 )
  {
    v1 = result;
    result = reg_dmav1_init_dspp_op_v4(4u, result);
    if ( (_DWORD)result )
    {
      *(_QWORD *)(v1 + 184) = sde_setup_dspp_pa_hsic_v17;
    }
    else
    {
      *(_QWORD *)(v1 + 184) = reg_dmav1_setup_dspp_pa_hsicv17;
      *(_QWORD *)(v1 + 192) = reg_dmav1_setup_dspp_pa_hsicv17;
    }
  }
  return result;
}
