__int64 __fastcall cnss_qmi_send(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  _QWORD *v8; // x0
  __int64 result; // x0
  _QWORD *v10; // x22

  v8 = (_QWORD *)cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v8 )
    return 4294967277LL;
  if ( (v8[69] & 1) == 0 )
    return 4294967274LL;
  v8[933] = a6;
  v8[932] = a5;
  v10 = v8;
  result = cnss_wlfw_get_info_send_sync();
  if ( (_DWORD)result )
  {
    v10[932] = 0;
    v10[933] = 0;
  }
  return result;
}
