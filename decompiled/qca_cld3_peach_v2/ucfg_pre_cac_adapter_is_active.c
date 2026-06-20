__int64 __fastcall ucfg_pre_cac_adapter_is_active(
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
  return pre_cac_adapter_is_active(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1;
}
