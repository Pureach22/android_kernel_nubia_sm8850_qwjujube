__int64 __fastcall hfi_util_u32_prop_helper_alloc(int a1)
{
  unsigned __int64 v1; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x21

  if ( (unsigned int)(a1 + 16) >= 0x1000 )
    v1 = 4096;
  else
    v1 = (unsigned int)(a1 + 16);
  result = _kvmalloc_node_noprof(v1, 0, 3520, 0xFFFFFFFFLL);
  if ( result )
  {
    while ( 1 )
    {
      if ( v1 >= 4 )
      {
        *(_DWORD *)result = v1 - 16;
        if ( v1 >= 8 && (v1 & 0x7FFFFFF8) != 8 )
        {
          *(_QWORD *)(result + 8) = result + 20;
          if ( (v1 & 0x7FFFFFFC) != 4 )
            break;
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v4 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &hfi_util_u32_prop_helper_alloc__alloc_tag;
      result = _kvmalloc_node_noprof(v1, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v4;
      if ( !result )
        goto LABEL_12;
    }
    *(_DWORD *)(result + 4) = 0;
  }
  else
  {
LABEL_12:
    printk(&unk_220556, "hfi_util_u32_prop_helper_alloc");
    return -12;
  }
  return result;
}
