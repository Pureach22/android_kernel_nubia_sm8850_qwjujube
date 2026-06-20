__int64 __fastcall enable_preemption(__int64 a1)
{
  __int64 result; // x0

  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  result = a6xx_hfi_send_feature_ctrl(
             a1,
             2,
             1,
             *(_DWORD *)(a1 + 20576) & 3
           | (4 * *(unsigned __int8 *)(a1 + 20581))
           | (8 * (unsigned int)*(unsigned __int8 *)(a1 + 20580)));
  if ( !(_DWORD)result )
    return a6xx_hfi_send_set_value(a1, 117, 1, 160015);
  return result;
}
