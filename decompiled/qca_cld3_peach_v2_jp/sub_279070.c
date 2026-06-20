__int64 sub_279070()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_attach_ctx();
}
