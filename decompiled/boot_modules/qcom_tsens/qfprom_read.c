unsigned __int64 __fastcall qfprom_read(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // [xsp+0h] [xbp-10h]
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  result = nvmem_cell_get(a1, a2);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = result;
    v4 = nvmem_cell_read();
    nvmem_cell_put(v3);
    result = v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
