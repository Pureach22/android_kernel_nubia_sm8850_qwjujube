__int64 sub_279858()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_wait_complete_tasks();
}
