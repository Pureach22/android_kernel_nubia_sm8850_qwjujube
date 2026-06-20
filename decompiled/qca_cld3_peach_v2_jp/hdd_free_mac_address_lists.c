void *__fastcall hdd_free_mac_address_lists(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  void *result; // x0

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Resetting MAC address lists",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_free_mac_address_lists");
  qdf_mem_set((char *)a1 + 3751, 0x24u, 0);
  result = qdf_mem_set((char *)a1 + 3787, 0x24u, 0);
  a1[480] = 0;
  a1[479] = 0;
  a1[478] = 0;
  return result;
}
