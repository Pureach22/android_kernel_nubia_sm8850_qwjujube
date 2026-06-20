__int64 __fastcall gen8_populate_ctxt_record_size(_QWORD *a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x9
  unsigned __int64 v5; // x8

  v1 = a1[1783];
  result = adreno_populate_ctxt_record_size(a1);
  if ( (_DWORD)result )
  {
    v4 = 13860864;
    if ( *(_QWORD *)(v1 + 176) )
      v4 = *(_QWORD *)(v1 + 176);
    v5 = 0x4000;
  }
  else
  {
    v4 = a1[3065];
    v5 = (a1[3067] + 4095LL) & 0xFFFFFFFFFFFFF000LL;
  }
  a1[3065] = (v4 + 4095) & 0xFFFFFFFFFFFFF000LL;
  a1[3067] = v5;
  return result;
}
