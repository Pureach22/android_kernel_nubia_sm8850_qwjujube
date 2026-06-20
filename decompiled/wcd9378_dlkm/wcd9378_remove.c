__int64 __fastcall wcd9378_remove(__int64 a1)
{
  __int64 result; // x0

  result = component_master_del(a1 + 16, wcd9378_comp_ops);
  *(_QWORD *)(a1 + 168) = 0;
  return result;
}
