__int64 __fastcall coresight_loses_context_with_cpu(__int64 a1)
{
  __int64 v1; // x0

  v1 = _dev_fwnode(a1);
  return fwnode_property_present(v1, "arm,coresight-loses-context-with-cpu") & 1;
}
