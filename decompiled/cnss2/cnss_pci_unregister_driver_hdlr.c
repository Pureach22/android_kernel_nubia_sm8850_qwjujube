__int64 __fastcall cnss_pci_unregister_driver_hdlr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  unsigned __int64 v17; // x9
  unsigned __int64 v20; // x10

  if ( !a1 )
    return 4294967274LL;
  v8 = *(_QWORD *)(a1 + 8);
  _X8 = (unsigned __int64 *)(v8 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v17 = __ldxr(_X8);
  while ( __stxr(v17 | 0x20, _X8) );
  cnss_pci_dev_shutdown(a1, a2, a3, a4, a5, a6, a7, a8);
  *(_QWORD *)(a1 + 40) = 0;
  _X8 = (unsigned __int64 *)(v8 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 & 0xFFFFFFFFFBFFFFFFLL, _X8) );
  return 0;
}
