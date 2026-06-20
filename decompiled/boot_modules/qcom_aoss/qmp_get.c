__int64 __fastcall qmp_get(__int64 a1)
{
  __int64 v1; // x0
  int v2; // w8
  __int64 result; // x0
  __int64 device_by_node; // x0
  __int64 v5; // x8
  _QWORD v6[11]; // [xsp+8h] [xbp-58h] BYREF

  v6[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_8;
  v1 = *(_QWORD *)(a1 + 744);
  if ( !v1 )
    goto LABEL_8;
  memset(v6, 0, 80);
  v2 = _of_parse_phandle_with_args(v1, "qcom,qmp", 0, 0, 0, v6);
  result = -19;
  if ( v2 || !v6[0] )
    goto LABEL_9;
  device_by_node = of_find_device_by_node(v6[0]);
  if ( !device_by_node )
  {
LABEL_8:
    result = -22;
    goto LABEL_9;
  }
  v5 = device_by_node;
  result = *(_QWORD *)(device_by_node + 168);
  if ( !result )
  {
    put_device(v5 + 16);
    result = -517;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
