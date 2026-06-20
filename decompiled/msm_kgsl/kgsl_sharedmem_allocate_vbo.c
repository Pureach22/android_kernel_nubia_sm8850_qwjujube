__int64 __fastcall kgsl_sharedmem_allocate_vbo(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 v5; // x20

  if ( (*(_QWORD *)(a1 + 104) & 0x80) != 0 )
  {
    v5 = (a3 + 4095) & 0xFFFFFFFFFFFFF000LL;
    kgsl_memdesc_init(a1, a2, a4);
    *(_DWORD *)(a2 + 48) = 0;
    *(_QWORD *)(a2 + 64) = &kgsl_vbo_ops;
    *(_QWORD *)(a2 + 40) = v5;
    *(_QWORD *)(a2 + 120) = 0;
    *(_QWORD *)(a2 + 128) = 0;
    _mutex_init(a2 + 136, "&memdesc->ranges_lock", &kgsl_sharedmem_allocate_vbo___key);
    return 0;
  }
  else
  {
    __break(0x800u);
    return 4294967201LL;
  }
}
