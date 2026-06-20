__int64 __fastcall cdp_ipa_iounmap_doorbell_vaddr(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 (*v10)(void); // x8

  if ( !result )
    return qdf_trace_msg(
             0x45u,
             1u,
             "%s invalid instance",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cdp_ipa_iounmap_doorbell_vaddr");
  if ( !*(_QWORD *)result )
    return qdf_trace_msg(
             0x45u,
             1u,
             "%s invalid instance",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cdp_ipa_iounmap_doorbell_vaddr");
  v9 = *(_QWORD *)(*(_QWORD *)result + 152LL);
  if ( !v9 )
    return qdf_trace_msg(
             0x45u,
             1u,
             "%s invalid instance",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "cdp_ipa_iounmap_doorbell_vaddr");
  v10 = *(__int64 (**)(void))(v9 + 16);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != 261447488 )
      __break(0x8228u);
    return v10();
  }
  return result;
}
