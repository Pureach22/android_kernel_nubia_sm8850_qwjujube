__int64 __fastcall wma_set_peer_param(__int64 *a1, __int64 a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w22

  _ReadStatusReg(SP_EL0);
  result = wmi_set_peer_param_send(*a1);
  if ( (_DWORD)result )
  {
    v17 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev_id: %d peer set failed, id %d, val %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wma_set_peer_param",
      a5,
      a3,
      a4);
    result = v17;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
