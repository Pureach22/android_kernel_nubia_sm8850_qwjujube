__int64 __fastcall hif_dummy_bus_prevent_linkdown(__int64 a1, char a2)
{
  const char *v2; // x4

  if ( (a2 & 1) != 0 )
    v2 = "disable";
  else
    v2 = "enable";
  return qdf_trace_msg(61, 8, "%s: wlan: %s pcie power collapse ignored", "hif_dummy_bus_prevent_linkdown", v2);
}
