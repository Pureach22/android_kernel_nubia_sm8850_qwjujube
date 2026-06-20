__int64 __fastcall rproc_find_status_register(_QWORD *a1)
{
  __int64 v2; // x20
  unsigned int v3; // w0
  __int64 v4; // x0
  __int64 v5; // x21
  unsigned int u32_index; // w0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x8
  unsigned int v10; // w19
  __int64 v11; // x8
  unsigned int v12; // w19
  __int64 v13; // [xsp+0h] [xbp-C0h] BYREF
  _QWORD v14[12]; // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v15[11]; // [xsp+68h] [xbp-58h] BYREF

  v15[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(*a1 + 744LL);
  memset(v14, 0, sizeof(v14));
  v13 = 0;
  memset(v15, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v2, "soccp-tcsr", 0, 0, 0, v15) || !v15[0] )
  {
    dev_err(*a1, "Unable to find the soccp config register\n");
LABEL_15:
    result = 4294967274LL;
    goto LABEL_9;
  }
  v3 = of_address_to_resource(v15[0], 0, v14);
  if ( v3 )
  {
    v9 = *a1;
    v10 = v3;
    dev_err(v9, "Unable to find the tcsr base addr\n");
    result = v10;
    goto LABEL_9;
  }
  v4 = ioremap_prot();
  if ( !v4 )
    goto LABEL_10;
  v5 = v4;
  u32_index = of_property_read_u32_index(v2, "soccp-tcsr", 1, (char *)&v13 + 4);
  if ( (u32_index & 0x80000000) != 0 )
  {
    v11 = *a1;
    v12 = u32_index;
    dev_err(v11, "Unable to find the tcsr config offset addr\n");
    iounmap(v5);
    result = v12;
    goto LABEL_9;
  }
  a1[164] = v5 + HIDWORD(v13);
  of_property_read_variable_u32_array(v2, "soccp-spare", &v13, 1, 0);
  if ( !(_DWORD)v13 )
  {
    dev_err(*a1, "Unable to find the running config register\n");
    goto LABEL_15;
  }
  v7 = ioremap_prot();
  a1[165] = v7;
  if ( !v7 )
  {
LABEL_10:
    dev_err(*a1, "Unable to find the tcsr base addr\n");
    result = 4294967284LL;
    goto LABEL_9;
  }
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
