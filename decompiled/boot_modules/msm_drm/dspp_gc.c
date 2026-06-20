__int64 __fastcall dspp_gc(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8
  size_t (__fastcall *v3)(__int64, int **); // x8

  v1 = result;
  v2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 104LL);
  if ( v2 == 0x20000 )
  {
    result = reg_dmav1_init_dspp_op_v4(3u, result);
    if ( !(_DWORD)result )
    {
      *(_QWORD *)(v1 + 448) = reg_dmav1_setup_dspp_gcv2;
      *(_QWORD *)(v1 + 456) = reg_dmav1_setup_dspp_gcv2;
    }
  }
  else if ( v2 == 65544 )
  {
    result = reg_dmav1_init_dspp_op_v4(3u, result);
    if ( (_DWORD)result )
      v3 = (size_t (__fastcall *)(__int64, int **))sde_setup_dspp_gc_v1_7;
    else
      v3 = reg_dmav1_setup_dspp_gcv18;
    *(_QWORD *)(v1 + 448) = v3;
  }
  return result;
}
