__int64 __fastcall sde_hw_parse_fuse_configuration(__int64 a1, __int64 a2)
{
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x19
  unsigned __int64 v5; // x21

  _ReadStatusReg(SP_EL0);
  v3 = nvmem_cell_get(a1 + 16);
  if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    LODWORD(v4) = 0;
  else
    LODWORD(v4) = v3;
  if ( (_DWORD)v4 )
  {
    if ( (_DWORD)v4 == -2 )
    {
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_23902F, a2);
      else
        printk(&unk_23FDFA, "sde_hw_parse_fuse_configuration");
      LODWORD(v4) = -2;
    }
  }
  else
  {
    v5 = v3;
    v4 = nvmem_cell_read();
    nvmem_cell_put(v5);
    if ( v4 < 0xFFFFFFFFFFFFF001LL )
    {
      kvfree(v4);
      LODWORD(v4) = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v4;
}
