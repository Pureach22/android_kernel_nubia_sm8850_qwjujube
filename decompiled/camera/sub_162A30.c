__int64 sub_162A30()
{
  __asm { SUBG            X17, X28, #0x30, #0xB ; '0' }
  return cam_cdm_write_wait_comp_event();
}
