__int64 __fastcall cti_plat_read_trig_group(int *a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x8
  unsigned __int64 v7; // x20
  __int64 v8; // x21
  unsigned int u32_array; // w0
  unsigned int v10; // w19
  unsigned __int64 v12; // x8
  __int64 v13; // x9
  unsigned __int64 v14; // x12
  unsigned __int64 v16; // x13
  unsigned __int64 v17; // x14
  __int64 v18; // x13
  unsigned __int64 v24; // x15
  unsigned __int64 StatusReg; // x24
  __int64 v26; // x25
  __int64 v27; // x8

  if ( !*a1 )
    return 0;
  v6 = (unsigned int)*a1;
  if ( (v6 & 0x80000000) == 0 )
  {
    v7 = 4 * v6;
    v8 = _kmalloc_noprof(4 * v6, 3520);
    while ( v8 )
    {
      u32_array = fwnode_property_read_u32_array(a2, a3, v8, *a1);
      if ( u32_array || *a1 < 1 )
      {
LABEL_6:
        v10 = u32_array;
        kfree(v8);
        return v10;
      }
      v12 = 0;
      v13 = 0;
      v14 = v7;
      while ( (v12 & 0x8000000000000000LL) == 0 )
      {
        if ( v7 < v12 )
          break;
        _CF = v14 >= 4;
        v14 -= 4LL;
        if ( !_CF )
          break;
        v16 = *(unsigned int *)(v8 + v12);
        v17 = v16 >> 6;
        v18 = 1LL << v16;
        _X14 = (unsigned __int64 *)&a1[2 * v17 + 2];
        __asm { PRFM            #0x11, [X14] }
        do
          v24 = __ldxr(_X14);
        while ( __stxr(v24 | v18, _X14) );
        ++v13;
        v12 += 4LL;
        if ( v13 >= *a1 )
          goto LABEL_6;
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v26 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v27 = (unsigned int)*a1;
      if ( (v27 & 0x80000000) != 0 )
      {
        v7 = 0;
        v8 = 0;
      }
      else
      {
        v7 = 4 * v27;
        v8 = _kmalloc_noprof(4 * v27, 3520);
      }
      *(_QWORD *)(StatusReg + 80) = v26;
    }
  }
  return 4294967284LL;
}
