__int64 __fastcall htc_get_credit_allocation(__int64 a1, unsigned __int16 a2)
{
  __int64 result; // x0

  if ( *(unsigned __int16 *)(a1 + 3416) == a2 )
    result = *(unsigned __int8 *)(a1 + 3418);
  else
    result = 0;
  if ( *(unsigned __int16 *)(a1 + 3420) == a2 )
    result = *(unsigned __int8 *)(a1 + 3422);
  if ( *(unsigned __int16 *)(a1 + 3424) == a2 )
    result = *(unsigned __int8 *)(a1 + 3426);
  if ( *(unsigned __int16 *)(a1 + 3428) == a2 )
    result = *(unsigned __int8 *)(a1 + 3430);
  if ( *(unsigned __int16 *)(a1 + 3432) == a2 )
    result = *(unsigned __int8 *)(a1 + 3434);
  if ( *(unsigned __int16 *)(a1 + 3436) == a2 )
    result = *(unsigned __int8 *)(a1 + 3438);
  if ( *(unsigned __int16 *)(a1 + 3440) == a2 )
    result = *(unsigned __int8 *)(a1 + 3442);
  if ( *(unsigned __int16 *)(a1 + 3444) == a2 )
    result = *(unsigned __int8 *)(a1 + 3446);
  if ( !(_DWORD)result && (dword_B804 & 0x10) != 0 )
  {
    qdf_trace_msg(56, 2, "%s: HTC Service TX : 0x%2.2X : allocation is zero!\n", "htc_get_credit_allocation", a2);
    return 0;
  }
  return result;
}
