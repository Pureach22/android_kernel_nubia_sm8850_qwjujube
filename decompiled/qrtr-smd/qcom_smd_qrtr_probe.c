__int64 __fastcall qcom_smd_qrtr_probe(_QWORD *a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x8
  _QWORD *v4; // x20
  __int64 v5; // x0
  __int64 property; // x21
  unsigned int v7; // w0
  __int64 v8; // x22
  __int64 v9; // x2
  unsigned int v10; // w21
  __int64 result; // x0
  unsigned int v12; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v12 = 0;
  v2 = (_QWORD *)devm_kmalloc(a1, 40, 3520);
  if ( !v2 )
    goto LABEL_10;
  v3 = a1[121];
  v4 = v2;
  *v2 = qcom_smd_qrtr_send;
  v2[3] = v3;
  v5 = a1[93];
  v4[4] = a1;
  *((_BYTE *)v4 + 16) = 1;
  if ( (of_property_read_variable_u32_array(v5, "qcom,net-id", &v12, 1, 0) & 0x80000000) != 0 )
    v12 = 1;
  property = of_find_property(a1[93], "qcom,low-latency", 0);
  v7 = of_property_count_elems_of_size(a1[93], "qcom,no-wake-svc", 4);
  if ( (int)v7 < 1 )
    goto LABEL_7;
  v8 = v7;
  v14 = v7;
  v9 = _kmalloc_noprof(4LL * v7, 3264);
  v13 = v9;
  if ( !v9 )
  {
LABEL_10:
    result = 4294967284LL;
    goto LABEL_11;
  }
  of_property_read_variable_u32_array(a1[93], "qcom,no-wake-svc", v9, v8, 0);
LABEL_7:
  v10 = qrtr_endpoint_register(v4, v12, property != 0, &v13);
  kfree(v13);
  if ( v10 )
  {
    dev_err(v4[4], "endpoint register failed: %d\n", v10);
    result = v10;
  }
  else
  {
    result = 0;
    a1[19] = v4;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
