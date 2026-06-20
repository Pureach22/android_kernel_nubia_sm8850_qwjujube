__int64 store_kaslr_offset()
{
  __int64 compatible_node; // x0
  _DWORD *v1; // x0
  _DWORD *v2; // x20
  void *v4; // x0

  compatible_node = of_find_compatible_node(0, 0, "qcom,msm-imem-kaslr_offset");
  if ( !compatible_node )
  {
    v4 = &unk_6723;
    return printk(v4, "qcom,msm-imem-kaslr_offset");
  }
  v1 = (_DWORD *)of_iomap(compatible_node, 0);
  if ( !v1 )
  {
    v4 = &unk_668B;
    return printk(v4, "qcom,msm-imem-kaslr_offset");
  }
  *v1 = -559067475;
  v2 = v1;
  v1[1] = debug_symbol_lookup_name("_text") ^ 0x80000000;
  v2[2] = (unsigned __int64)(debug_symbol_lookup_name("_text") + 0x3F80000000LL) >> 32;
  return iounmap(v2);
}
