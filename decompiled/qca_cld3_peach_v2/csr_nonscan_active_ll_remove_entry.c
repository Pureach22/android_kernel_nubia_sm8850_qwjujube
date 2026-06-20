bool __fastcall csr_nonscan_active_ll_remove_entry(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 active; // x0
  __int64 v12; // x8

  active = wlan_serialization_peek_head_active_cmd_using_psoc(
             *(_QWORD *)(a1 + 21624),
             0,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  if ( active && !*(_DWORD *)(active + 16) )
    v12 = *(_QWORD *)(active + 40);
  else
    v12 = 0;
  return v12 == a2;
}
