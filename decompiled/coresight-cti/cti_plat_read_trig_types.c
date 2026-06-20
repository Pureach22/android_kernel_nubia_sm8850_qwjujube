__int64 __fastcall cti_plat_read_trig_types(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x25
  int u32_array; // w0
  unsigned __int64 v8; // x19
  unsigned __int64 v10; // x20
  __int64 v11; // x21
  unsigned int v12; // w0
  unsigned __int64 v13; // x8
  __int64 v14; // x11
  unsigned __int64 v15; // x12
  unsigned int v16; // w13
  unsigned int v17; // w19
  unsigned __int64 StatusReg; // x26
  __int64 v19; // x27

  v3 = *a1;
  if ( !(_DWORD)v3 )
    return 0;
  u32_array = fwnode_property_read_u32_array(a2, a3, 0, 0);
  v8 = u32_array & (unsigned int)~(u32_array >> 31);
  if ( (int)v8 > (int)v3 )
    return 4294967274LL;
  if ( u32_array <= 0 )
  {
    v10 = 0;
    v11 = 0;
    goto LABEL_10;
  }
  v10 = 4LL * (u32_array & (unsigned int)~(u32_array >> 31));
  v11 = _kmalloc_noprof(v10, 3520);
  if ( !v11 )
    return 4294967284LL;
  do
  {
    v12 = fwnode_property_read_u32_array(a2, a3, v11, v8);
    if ( v12 )
    {
LABEL_19:
      v17 = v12;
      kfree(v11);
      return v17;
    }
LABEL_10:
    v13 = 0;
    v14 = 6;
    v15 = v10;
    while ( v14 - 6 >= v8 )
    {
      v16 = 0;
LABEL_12:
      ++v14;
      a1[v13 / 4 + 6] = v16;
      v15 -= 4LL;
      v13 += 4LL;
      if ( v14 - v3 == 6 )
      {
        v12 = 0;
        goto LABEL_19;
      }
    }
    if ( v10 >= v13 && v15 >= 4 )
    {
      v16 = *(_DWORD *)(v11 + v13);
      if ( v16 >= 0x19 )
        v16 = 0;
      goto LABEL_12;
    }
    __break(1u);
    v10 = 4LL * (unsigned int)v8;
    StatusReg = _ReadStatusReg(SP_EL0);
    v19 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cti_plat_read_trig_types__alloc_tag;
    v11 = _kmalloc_noprof(v10, 3520);
    *(_QWORD *)(StatusReg + 80) = v19;
  }
  while ( v11 );
  return 4294967284LL;
}
