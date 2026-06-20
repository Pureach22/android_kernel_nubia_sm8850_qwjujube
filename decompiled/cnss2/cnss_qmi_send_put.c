__int64 __fastcall cnss_qmi_send_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( (*(_QWORD *)(v2 + 552) & 1) != 0 )
    return cnss_bus_qmi_send_put(v2);
  else
    return 0;
}
