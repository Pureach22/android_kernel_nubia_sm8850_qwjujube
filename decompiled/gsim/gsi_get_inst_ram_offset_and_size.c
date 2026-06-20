__int64 __fastcall gsi_get_inst_ram_offset_and_size(__int64 result, __int64 *a2)
{
  _QWORD *v3; // x19

  if ( !gsi_ctx )
    return printk(&unk_2DEB9, "gsi_get_inst_ram_offset_and_size", 4922);
  v3 = (_QWORD *)result;
  if ( a2 )
  {
    result = gsihal_get_inst_ram_size();
    *a2 = result;
  }
  if ( v3 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))gsihal_get_reg_nk_ofst)(122, 0, 0);
    *v3 = (unsigned int)result;
  }
  return result;
}
