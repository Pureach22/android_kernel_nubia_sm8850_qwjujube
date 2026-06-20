__int64 __fastcall cam_hw_cdm_flush_hw(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  unsigned __int64 v10; // x9
  unsigned __int64 v13; // x10

  v2 = *(_QWORD *)(a1 + 3680);
  _X8 = (unsigned __int64 *)(v2 + 4856);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | 0x40, _X8) );
  result = cam_hw_cdm_reset_hw(a1, a2);
  _X8 = (unsigned __int64 *)(v2 + 4856);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
  return result;
}
