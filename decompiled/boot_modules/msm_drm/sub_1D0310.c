__int64 __usercall sub_1D0310@<X0>(int a1@<W8>)
{
  if ( !a1 )
    JUMPOUT(0x236D24);
  return dsi_ctrl_hw_22_schedule_dma_cmd();
}
