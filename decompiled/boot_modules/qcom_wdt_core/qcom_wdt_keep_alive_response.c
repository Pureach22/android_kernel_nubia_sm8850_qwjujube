__int64 __fastcall qcom_wdt_keep_alive_response(__int64 result)
{
  unsigned __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x10
  unsigned __int64 v4; // x9
  __int64 v5; // x8
  unsigned __int64 v12; // x10

  v1 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  v2 = result;
  v3 = result + 48;
  v4 = v1 >> 6;
  v5 = 1LL << v1;
  while ( 1 )
  {
    _X9 = (unsigned __int64 *)(v3 + 8 * v4);
    __asm { PRFM            #0x11, [X9] }
    do
      v12 = __ldxr(_X9);
    while ( __stxr(v12 | v5, _X9) );
    result = sched_clock(result);
    if ( (unsigned int)v1 < 0x20 )
      break;
    __break(0x5512u);
  }
  *(_QWORD *)(v2 + 8 * v1 + 568) = result;
  __dmb(0xBu);
  return result;
}
