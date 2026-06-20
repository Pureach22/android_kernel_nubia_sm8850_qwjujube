__int64 __fastcall eusb2_repeater_read_overrides(__int64 a1, const char *a2, __int64 *a3, _BYTE *a4)
{
  int v8; // w0
  unsigned int v9; // w22
  __int64 v10; // x0
  int variable_u32_array; // w0
  unsigned int v13; // w21

  v8 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 744), a2, 4);
  if ( v8 < 1 )
    return 0;
  v9 = v8;
  if ( (v8 & 1) != 0 )
  {
    dev_err(a1, "invalid len for %s\n", a2);
    return 4294967274LL;
  }
  else
  {
    *a4 = v8;
    v10 = devm_kmalloc(a1, 4LL * (unsigned int)v8, 3520);
    *a3 = v10;
    if ( v10 )
    {
      variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), a2, v10, v9, 0);
      if ( (variable_u32_array & 0x80000000) == 0 )
        return 0;
      v13 = variable_u32_array;
      dev_err(a1, "%s read failed %d\n", a2, variable_u32_array);
      return v13;
    }
    else
    {
      return 4294967284LL;
    }
  }
}
