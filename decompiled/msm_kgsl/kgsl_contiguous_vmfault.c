__int64 __fastcall kgsl_contiguous_vmfault(__int64 a1, __int64 a2)
{
  return vmf_insert_pfn(a2);
}
