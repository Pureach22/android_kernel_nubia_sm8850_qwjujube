__int64 __fastcall qcom_mhi_qrtr_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x24
  __int64 compatible_node; // x0
  __int64 v8; // x22
  unsigned int v9; // w23
  _BOOL8 v10; // x2
  __int64 result; // x0
  unsigned int v12; // w0
  unsigned int v13; // w19
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 + 40;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = devm_kmalloc(a1 + 40, 104, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_16;
  }
  v4 = v3;
  *(_QWORD *)(v3 + 24) = a1;
  *(_QWORD *)(v3 + 32) = v1;
  *(_QWORD *)v3 = qcom_mhi_qrtr_send;
  *(_DWORD *)(v3 + 40) = 0;
  v5 = v3 + 40;
  _init_swait_queue_head(v3 + 48, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 72) = 0;
  _init_swait_queue_head(v4 + 80, "&x->wait", &init_completion___key);
  v6 = *(_QWORD *)(a1 + 16);
  *(_QWORD *)(a1 + 192) = v4;
  v14[0] = 0;
  compatible_node = of_find_compatible_node(0, 0, "qcom,qrtr-mhi");
  if ( !compatible_node )
  {
LABEL_10:
    v10 = 0;
    v9 = 1;
    goto LABEL_12;
  }
  v8 = compatible_node;
  v9 = 1;
  if ( (of_property_read_variable_u32_array(compatible_node, "qcom,dev-id", (char *)v14 + 4, 1, 0) & 0x80000000) == 0 )
  {
    if ( HIDWORD(v14[0]) == *(unsigned __int16 *)(*(_QWORD *)(v6 + 8) - 138LL) )
    {
      if ( (int)of_property_read_variable_u32_array(v8, "qcom,net-id", v14, 1, 0) < 0 )
        v9 = 1;
      else
        v9 = v14[0];
      v10 = of_find_property(v8, "qcom,low-latency", 0) != 0;
      goto LABEL_12;
    }
    goto LABEL_10;
  }
  v10 = 0;
LABEL_12:
  result = qrtr_endpoint_register(v4, v9, v10, 0);
  if ( !(_DWORD)result )
  {
    v12 = mhi_prepare_for_transfer_autoqueue(a1);
    if ( v12 )
    {
      v13 = v12;
      qrtr_endpoint_unregister(v4);
      result = v13;
    }
    else
    {
      complete_all(v5);
      result = 0;
    }
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
