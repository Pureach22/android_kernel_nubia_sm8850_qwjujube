__int64 sub_15404()
{
  __asm { PRFM            #0x1F, 0xFFFFFFFFFFFCB2D4 }
  return qcom_clk_bulk_dump();
}
