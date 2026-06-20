__int64 __fastcall adc5_gen3_fwnode_xlate(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  int v3; // w8
  __int64 v4; // x9
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 1040);
  v3 = *(_DWORD *)(v2 + 40);
  if ( !v3 )
    return 4294967294LL;
  v4 = *(_QWORD *)(v2 + 48);
  result = 0;
  while ( *(_QWORD *)(a2 + 16) != (*(unsigned __int8 *)(v4 + 200LL * (int)result)
                                 | ((*(_WORD *)(v4 + 200LL * (int)result + 12) & 0x1F) << 8) & 0x9FFF
                                 | ((*(_DWORD *)(v4 + 200LL * (int)result + 32) & 3) << 13)) )
  {
    result = (unsigned int)(result + 1);
    if ( v3 == (_DWORD)result )
      return 4294967294LL;
  }
  return result;
}
