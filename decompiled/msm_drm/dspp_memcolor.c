__int64 __fastcall dspp_memcolor(__int64 result)
{
  _QWORD *v1; // x19

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 176LL) == 65543 )
  {
    v1 = (_QWORD *)result;
    result = reg_dmav1_init_dspp_op_v4(5u, result);
    if ( (_DWORD)result )
    {
      v1[32] = sde_setup_dspp_memcol_skin_v17;
      v1[35] = sde_setup_dspp_memcol_sky_v17;
      v1[38] = sde_setup_dspp_memcol_foliage_v17;
      v1[41] = sde_setup_dspp_memcol_prot_v17;
    }
    else
    {
      v1[32] = reg_dmav1_setup_dspp_memcol_skinv17;
      v1[33] = reg_dmav1_setup_dspp_memcol_skinv17;
      v1[35] = reg_dmav1_setup_dspp_memcol_skyv17;
      v1[36] = reg_dmav1_setup_dspp_memcol_skyv17;
      v1[38] = reg_dmav1_setup_dspp_memcol_folv17;
      v1[39] = reg_dmav1_setup_dspp_memcol_folv17;
      v1[41] = reg_dmav1_setup_dspp_memcol_protv17;
      v1[42] = reg_dmav1_setup_dspp_memcol_protv17;
    }
  }
  return result;
}
