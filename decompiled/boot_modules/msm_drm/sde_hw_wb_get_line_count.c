__int64 __fastcall sde_hw_wb_get_line_count(__int64 a1)
{
  return (unsigned __int16)sde_reg_read(a1, 0x184u);
}
