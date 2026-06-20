bool __fastcall cds_is_pm_fw_debug_enable(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x8
  _BOOL8 result; // x0

  v4 = gp_cds_context;
  result = false;
  if ( gp_cds_context || (printk(&unk_A3062F, "cds_get_global_context", a3, a4), (v4 = gp_cds_context) != 0) )
  {
    v5 = *(_QWORD *)(v4 + 152);
    if ( v5 )
    {
      if ( (*(_BYTE *)(v5 + 146) & 1) != 0 )
        return true;
    }
  }
  return result;
}
