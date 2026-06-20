__int64 __fastcall wlan_tasklet(__int64 result)
{
  __int64 v1; // x19
  unsigned int v8; // w10

  if ( *(_BYTE *)(result + 584) && !*(_DWORD *)(result + 684) )
  {
    v1 = result;
    hif_fw_interrupt_handler(*(unsigned int *)(result + 30900), result);
    result = v1;
  }
  *(_DWORD *)(result + 720) = 0;
  _X8 = (unsigned int *)(result + 672);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 - 1, _X8) );
  return result;
}
