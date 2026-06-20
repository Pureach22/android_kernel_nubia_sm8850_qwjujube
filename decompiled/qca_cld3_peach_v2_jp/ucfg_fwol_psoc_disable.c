__int64 __fastcall ucfg_fwol_psoc_disable(
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
  return tgt_fwol_unregister_ev_handler(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
