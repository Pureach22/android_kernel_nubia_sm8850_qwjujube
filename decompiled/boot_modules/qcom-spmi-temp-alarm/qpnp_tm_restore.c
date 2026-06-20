__int64 __fastcall qpnp_tm_restore(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x1
  __int64 v4; // x4
  __int64 result; // x0
  unsigned int v6; // w20

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(unsigned int *)(v1 + 56);
  if ( (int)v3 < 1
    || (*(_DWORD *)(v1 + 24) != 9 ? (v4 = 8193) : (v4 = 8195),
        result = devm_request_threaded_irq(a1, v3, 0, qpnp_tm_isr, v4, **(_QWORD **)(a1 + 744), v1),
        (result & 0x80000000) == 0) )
  {
    result = qpnp_tm_init((__int64 *)v1);
    if ( (result & 0x80000000) != 0 )
    {
      v6 = result;
      dev_err(a1, "init failed\n");
      return v6;
    }
  }
  return result;
}
