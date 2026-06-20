__int64 __fastcall hdd_update_score_config(
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
  unsigned int v10; // w0

  v10 = hdd_cfg_xlate_to_csr_phy_mode(**(_DWORD **)(a1 + 104), a2, a3, a4, a5, a6, a7, a8, a9);
  sme_update_score_config(*(_QWORD *)(a1 + 16), v10, *(unsigned int *)(a1 + 1248));
  return 0;
}
