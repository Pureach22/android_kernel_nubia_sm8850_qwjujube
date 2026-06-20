__int64 __fastcall tpda_get_element_size(__int64 a1, int **a2, int a3)
{
  int *v3; // x8
  __int64 v7; // x28
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x26
  __int64 v11; // x8
  __int64 v12; // x27
  __int64 v13; // x9
  int u32_array; // w0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w27
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  if ( **a2 < 1 )
  {
LABEL_26:
    result = 0;
    goto LABEL_27;
  }
  v7 = 0;
  while ( 1 )
  {
    v9 = *(_QWORD *)(*((_QWORD *)v3 + 2) + 8 * v7);
    v10 = *(_QWORD *)(v9 + 32);
    if ( !v10 || (a3 & 0x80000000) == 0 && *(_DWORD *)(v9 + 4) != a3 )
      goto LABEL_4;
    if ( *(_QWORD *)(v9 + 40) )
    {
      v10 = *(_QWORD *)(v9 + 48);
      if ( !v10 )
        goto LABEL_4;
    }
    if ( *(_DWORD *)(v10 + 8) != 3 || *(_DWORD *)(v10 + 12) != 3 )
    {
      result = tpda_get_element_size(a1, v10, 0xFFFFFFFFLL);
      if ( (_DWORD)result )
        goto LABEL_27;
      goto LABEL_4;
    }
    if ( *(_DWORD *)(a1 + 32) || *(_DWORD *)(a1 + 36) )
    {
      result = 4294967279LL;
      goto LABEL_27;
    }
    v11 = *(_QWORD *)(v10 + 152);
    v12 = *(_QWORD *)(v11 + 152);
    v13 = *(_QWORD *)(v12 + 32);
    if ( (v13 & 2) != 0 )
    {
      v15 = _dev_fwnode(*(_QWORD *)(v10 + 152));
      u32_array = fwnode_property_read_u32_array(v15, "qcom,dsb-element-bits", a1 + 32, 1);
      v11 = *(_QWORD *)(v10 + 152);
      if ( (*(_QWORD *)(v12 + 32) & 0x44LL) == 0 )
        goto LABEL_19;
LABEL_18:
      v16 = _dev_fwnode(v11);
      u32_array = fwnode_property_read_u32_array(v16, "qcom,cmb-element-bits", a1 + 36, 1);
      v11 = *(_QWORD *)(v10 + 152);
      goto LABEL_19;
    }
    u32_array = -22;
    if ( (v13 & 0x44) != 0 )
      goto LABEL_18;
LABEL_19:
    v17 = u32_array;
    s1[0] = nullptr;
    v18 = _dev_fwnode(v11);
    if ( (unsigned int)fwnode_property_read_string(v18, "compatible", s1)
      || strcmp(s1[0], "qcom,coresight-static-tpdm")
      || (v19 = _dev_fwnode(*(_QWORD *)(v10 + 152)),
          fwnode_property_read_u32_array(v19, "qcom,dsb-element-bits", a1 + 32, 1),
          v20 = _dev_fwnode(*(_QWORD *)(v10 + 152)),
          fwnode_property_read_u32_array(v20, "qcom,cmb-element-bits", a1 + 36, 1),
          !*(_DWORD *)(a1 + 32))
      && !*(_DWORD *)(a1 + 36) )
    {
      result = v17;
      if ( v17 )
        break;
    }
LABEL_4:
    v3 = *a2;
    if ( ++v7 >= **a2 )
      goto LABEL_26;
  }
  if ( (tpdm_read_element_size___print_once & 1) == 0 )
  {
    tpdm_read_element_size___print_once = 1;
    dev_warn(v10 + 56, "Failed to read TPDM Element size: %d\n", v17);
    result = v17;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
