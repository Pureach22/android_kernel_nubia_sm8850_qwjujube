__int64 __fastcall cavium_cfg_probe(__int64 *a1)
{
  int v1; // w8
  __int64 v2; // x8
  unsigned int v10; // w9

  v1 = *((_DWORD *)a1 + 14);
  _X10 = &cavium_cfg_probe_context_count;
  __asm { PRFM            #0x11, [X10] }
  do
    v10 = __ldxr((unsigned int *)&cavium_cfg_probe_context_count);
  while ( __stlxr(v10 + v1, (unsigned int *)&cavium_cfg_probe_context_count) );
  __dmb(0xBu);
  v2 = *a1;
  *((_DWORD *)a1 + 82) = v10;
  dev_notice(v2, "\tenabling workaround for Cavium erratum 27704\n");
  return 0;
}
