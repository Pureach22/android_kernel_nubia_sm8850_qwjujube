__int64 __fastcall qcom_remove_smd_subdev(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a2 + 56) )
    return rproc_remove_subdev();
  return result;
}
