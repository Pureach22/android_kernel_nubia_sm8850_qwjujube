__int64 __fastcall _set_ubwc_config(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int *v3; // x20
  __int64 v4; // x8
  unsigned int (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x1
  unsigned __int64 StatusReg; // x8

  if ( *(_QWORD *)(*(_QWORD *)(result + 2208) + 456LL) )
  {
    v1 = result;
    v2 = _kmalloc_cache_noprof(_kmem_cache_create_args, 3520, 56);
    v3 = (unsigned int *)v2;
    v4 = *(_QWORD *)(v1 + 2416);
    if ( !v4 )
      goto LABEL_10;
    v5 = *(unsigned int (__fastcall **)(__int64, __int64))(v4 + 72);
    if ( !v5 )
      goto LABEL_10;
    v6 = *(_QWORD *)(*(_QWORD *)(v1 + 2208) + 456LL);
    if ( *((_DWORD *)v5 - 1) != 1880985272 )
      __break(0x8228u);
    if ( v5(v2, v6) )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_89377, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      }
    }
    else
    {
LABEL_10:
      _iface_cmdq_write(v1, v3);
    }
    return kfree(v3);
  }
  return result;
}
