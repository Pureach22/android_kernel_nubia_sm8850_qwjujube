__int64 __fastcall csr_purge_pdev_all_ser_cmd_list(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return wlan_serialization_purge_all_pdev_cmd(*(_QWORD *)(a1 + 21632), a2, a3, a4, a5, a6, a7, a8, a9);
}
