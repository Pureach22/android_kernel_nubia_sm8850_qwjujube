__int64 __fastcall enable_preemption_1(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  int *v4; // x8
  int v5; // w3
  int v6; // w3
  int v7; // w3
  int v8; // w3

  v1 = *(_QWORD *)(a1 + 14264);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  result = gen8_hfi_send_feature_ctrl(
             a1,
             2,
             1,
             *(_DWORD *)(a1 + 20576) & 3
           | (4 * *(unsigned __int8 *)(a1 + 20581))
           | (8 * (unsigned int)*(unsigned __int8 *)(a1 + 20580)));
  if ( !(_DWORD)result )
  {
    v4 = *(int **)(v1 + 216);
    if ( v4 )
    {
      if ( *v4 )
      {
        gen8_hfi_send_set_value(a1, 123, 0, *v4);
        v4 = *(int **)(v1 + 216);
      }
      v5 = v4[1];
      if ( v5 )
      {
        gen8_hfi_send_set_value(a1, 123, 1, v5);
        v4 = *(int **)(v1 + 216);
      }
      v6 = v4[2];
      if ( v6 )
      {
        gen8_hfi_send_set_value(a1, 123, 2, v6);
        v4 = *(int **)(v1 + 216);
      }
      v7 = v4[3];
      if ( v7 )
        gen8_hfi_send_set_value(a1, 123, 3, v7);
    }
    v8 = *(_DWORD *)(a1 + 10940);
    if ( v8 )
    {
      if ( (unsigned int)gen8_hfi_send_set_value(a1, 124, 0, v8) )
        *(_DWORD *)(a1 + 10940) = 0;
    }
    return gen8_hfi_send_set_value(a1, 117, 1, 160015);
  }
  return result;
}
