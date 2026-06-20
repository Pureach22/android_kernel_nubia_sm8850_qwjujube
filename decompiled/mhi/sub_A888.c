__int64 sub_A888()
{
  __asm { STZG            X17, [X5,#0xF20] }
  return mhi_free_bhie_table();
}
