__int64 __fastcall adreno_read_fuse(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x0
  const void *v3; // x19
  unsigned __int64 v4; // x20
  size_t v5; // x2
  unsigned __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  int dest; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = nvmem_cell_get(a1 + 16, a2);
  dest = 0;
  if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    LODWORD(v3) = 0;
  else
    LODWORD(v3) = v2;
  if ( (_DWORD)v3 == -2 )
  {
    LODWORD(v3) = 0;
  }
  else if ( !(_DWORD)v3 )
  {
    v7 = 0;
    v4 = v2;
    v3 = (const void *)nvmem_cell_read(v2, &v7);
    nvmem_cell_put(v4);
    if ( (unsigned __int64)v3 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( v7 >= 4 )
        v5 = 4;
      else
        v5 = v7;
      memcpy(&dest, v3, v5);
      kfree(v3);
      LODWORD(v3) = dest;
    }
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v3;
}
