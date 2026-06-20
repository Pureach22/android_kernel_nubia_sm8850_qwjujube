__int64 sub_2A80EC()
{
  __asm { PRFM            #0x1C, [X28],#0xFF }
  return dp_wait_complete_tasks();
}
