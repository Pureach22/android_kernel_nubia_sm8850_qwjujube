__int64 __fastcall sde_kms_dump_clks_state(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  _BOOL8 v4; // x1
  __int64 v5; // x20

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL);
  if ( (_drm_debug & 4) != 0 )
  {
    v4 = *(_DWORD *)(v2 + 500) == 2 && (*(_WORD *)(v2 + 488) & 7) == 0;
    result = printk(&unk_24316E, v4);
  }
  else
  {
    result = printk(&unk_26CEA9, "_sde_kms_dump_clks_state");
  }
  if ( *(int *)(a1 + 3568) >= 1 )
  {
    v5 = 0;
    do
      result = dsi_display_dump_clks_state(*(_QWORD *)(*(_QWORD *)(a1 + 3576) + 8 * v5++));
    while ( v5 < *(int *)(a1 + 3568) );
  }
  return result;
}
