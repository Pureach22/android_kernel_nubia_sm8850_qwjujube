__int64 *__fastcall hal_tx_comp_get_status_generic_be(__int64 *result, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int16 v4; // w8
  unsigned __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x11
  __int64 v8; // x12

  v2 = result[2];
  v3 = result[3];
  v4 = ~(2 * v2);
  v5 = v2 & 0xFFFFFFFFFFFFFBFFLL;
  v6 = v4 & 0x400;
  if ( (result[2] & 0x100) == 0 )
    v6 = 1024;
  v8 = *result;
  v7 = result[1];
  *(_QWORD *)(a2 + 16) = v6 | v5;
  *(_QWORD *)(a2 + 24) = v3;
  *(_QWORD *)a2 = v8;
  *(_QWORD *)(a2 + 8) = v7;
  *(_DWORD *)(a2 + 28) = HIDWORD(v3) & 0xFF0FFFFF;
  return result;
}
