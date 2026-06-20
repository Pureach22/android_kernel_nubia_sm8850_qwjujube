__int64 sub_9428()
{
  __asm { PRFM            #0xB, [X25,#0x490] }
  return coresight_set_cti_ops();
}
