__int64 __fastcall enable_preemption_0(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  int *v4; // x8
  int v5; // w3
  int v6; // w3
  int v7; // w3
  int v8; // w3
  int v9; // w0
  int v10; // w8
  int v11; // w0

  v1 = *(_QWORD *)(a1 + 14264);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  result = gen7_hfi_send_feature_ctrl(
             a1,
             2,
             1,
             *(_DWORD *)(a1 + 20576) & 3
           | (4 * *(unsigned __int8 *)(a1 + 20581))
           | (8 * (unsigned int)*(unsigned __int8 *)(a1 + 20580)));
  if ( !(_DWORD)result )
  {
    v4 = *(int **)(v1 + 232);
    if ( v4 )
    {
      if ( *v4 )
      {
        gen7_hfi_send_set_value(a1, 123, 0, *v4);
        v4 = *(int **)(v1 + 232);
      }
      v5 = v4[1];
      if ( v5 )
      {
        gen7_hfi_send_set_value(a1, 123, 1, v5);
        v4 = *(int **)(v1 + 232);
      }
      v6 = v4[2];
      if ( v6 )
      {
        gen7_hfi_send_set_value(a1, 123, 2, v6);
        v4 = *(int **)(v1 + 232);
      }
      v7 = v4[3];
      if ( v7 )
        gen7_hfi_send_set_value(a1, 123, 3, v7);
    }
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 0x80) != 0 )
    {
      v8 = *(_DWORD *)(a1 + 10940);
      if ( v8 )
      {
        v9 = gen7_hfi_send_set_value(a1, 124, 0, v8);
        if ( v9 )
        {
          dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Failed to set rt bus hint %u, ret: %d\n", *(_DWORD *)(a1 + 10940), v9);
          *(_DWORD *)(a1 + 10940) = 0;
        }
      }
      v10 = *(_DWORD *)(a1 + 10948);
      if ( v10 != 255 )
      {
        v11 = gen7_hfi_send_set_value(a1, 133, 0, *(_DWORD *)(a1 + 10068) - v10);
        if ( v11 )
        {
          dev_err(
            *(_QWORD *)(a1 + 1544) + 16LL,
            "Failed to set rt pwrlevel hint %u, ret: %d\n",
            *(_DWORD *)(a1 + 10948),
            v11);
          *(_DWORD *)(a1 + 10948) = 255;
        }
      }
    }
    return gen7_hfi_send_set_value(a1, 117, 1, 160015);
  }
  return result;
}
