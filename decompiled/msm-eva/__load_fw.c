__int64 __fastcall _load_fw(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned int v4; // w20

  v1 = *(_QWORD *)(a1 + 2208);
  if ( (*(_BYTE *)(v1 + 328) & 1) == 0 && *(_QWORD *)v1 )
    return 0;
  result = load_cvp_fw_impl(a1);
  if ( (_DWORD)result )
  {
    v4 = result;
    power_off_iris2(a1);
    return v4;
  }
  return result;
}
