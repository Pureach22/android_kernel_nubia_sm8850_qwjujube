__int64 __fastcall qcom_remove_glink_subdev(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a2 + 64) )
  {
    rproc_remove_subdev();
    return kfree_const(*(_QWORD *)(a2 + 48));
  }
  return result;
}
