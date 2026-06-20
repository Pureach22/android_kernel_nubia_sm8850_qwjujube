__int64 __fastcall hfi_util_kv_helper_alloc(int a1, __int64 a2)
{
  unsigned int v2; // w20
  unsigned __int64 v3; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x22

  v2 = 16 * a1 + 16;
  if ( v2 > 0x1000 )
  {
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_237DC2, a2);
    else
      printk(&unk_22A715, "hfi_util_kv_helper_alloc");
    v2 = 4096;
  }
  v3 = v2;
  result = _kvmalloc_node_noprof(v2, 0, 3520, 0xFFFFFFFFLL);
  if ( result )
  {
    while ( v3 < 4 || (v3 & 0x7FFFFFFC) == 4 )
    {
      __break(1u);
      v3 = v2;
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &hfi_util_kv_helper_alloc__alloc_tag;
      result = _kvmalloc_node_noprof(v2, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v6;
      if ( !result )
        goto LABEL_12;
    }
    *(_QWORD *)result = v2 - 16;
  }
  else
  {
LABEL_12:
    printk(&unk_220556, "hfi_util_kv_helper_alloc");
    return -12;
  }
  return result;
}
