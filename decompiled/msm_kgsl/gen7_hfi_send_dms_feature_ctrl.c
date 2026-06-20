__int64 __fastcall gen7_hfi_send_dms_feature_ctrl(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v9; // x10

  if ( (*(_QWORD *)(a1 + 14240) & 0x4000) == 0 )
    return 0;
  result = gen7_hfi_send_feature_ctrl(a1, 27, 1, 0);
  if ( (_DWORD)result == -2 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "GMU doesn't support DMS feature\n");
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 & 0xFFFFFFFFFFFFBFFFLL, _X8) );
    *(_BYTE *)(a1 + 20441) = 0;
    return 0;
  }
  return result;
}
