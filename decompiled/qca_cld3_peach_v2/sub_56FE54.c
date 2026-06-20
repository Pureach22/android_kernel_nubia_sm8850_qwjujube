__int64 __fastcall sub_56FE54(double a1, float a2)
{
  __int64 v2; // x23
  int v3; // s24

  *(float *)v2 = a2;
  *(_DWORD *)(v2 + 4) = v3;
  return dp_tx_compute_hw_delay_us();
}
