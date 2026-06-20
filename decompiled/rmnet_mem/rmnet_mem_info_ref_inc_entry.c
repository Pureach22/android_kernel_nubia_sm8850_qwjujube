__int64 __fastcall rmnet_mem_info_ref_inc_entry(__int64 result)
{
  unsigned int v7; // w9

  _X8 = (unsigned int *)(result + 52);
  __asm { PRFM            #0x11, [X8] }
  do
    v7 = __ldxr(_X8);
  while ( __stxr(v7 + 1, _X8) );
  return result;
}
