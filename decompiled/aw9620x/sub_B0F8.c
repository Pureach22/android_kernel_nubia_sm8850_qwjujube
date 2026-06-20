__int64 sub_B0F8()
{
  __asm { PRFM            #0x1A, 0xFFFFFFFFFFFF2530 }
  return aw9620x_update();
}
