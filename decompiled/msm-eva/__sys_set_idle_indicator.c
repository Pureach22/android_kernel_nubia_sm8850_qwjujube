__int64 __fastcall _sys_set_idle_indicator(__int64 a1)
{
  __int64 v2; // x0
  unsigned int *v3; // x20
  __int64 v4; // x8
  void (__fastcall *v5)(__int64, __int64); // x8

  v2 = _kmalloc_cache_noprof(printk, 3520, 20);
  v3 = (unsigned int *)v2;
  v4 = *(_QWORD *)(a1 + 2416);
  if ( v4 )
  {
    v5 = *(void (__fastcall **)(__int64, __int64))(v4 + 48);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != 1706540593 )
        __break(0x8228u);
      v5(v2, 1);
    }
  }
  _iface_cmdq_write(a1, v3);
  return kfree(v3);
}
