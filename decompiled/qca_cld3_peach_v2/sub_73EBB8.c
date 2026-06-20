__int64 __fastcall sub_73EBB8(double a1, double a2, double a3, double a4, double a5, double a6, float a7)
{
  __int64 v7; // x24
  int v8; // s21

  *(float *)(v7 + 156) = a7;
  *(_DWORD *)(v7 + 160) = v8;
  return send_tx_power_per_mcs_cmd_tlv();
}
