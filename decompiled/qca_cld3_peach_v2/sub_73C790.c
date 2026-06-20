__int64 __fastcall sub_73C790(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        float a9)
{
  __int64 v9; // x24
  int v10; // s21

  *(float *)(v9 + 156) = a9;
  *(_DWORD *)(v9 + 160) = v10;
  return wmi_unified_send_tx_power_per_mcs_cmd(a1, a2);
}
