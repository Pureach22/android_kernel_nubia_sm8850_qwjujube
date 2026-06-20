__int64 __fastcall dp_ipa_get_wdi_version(__int64 result, _BYTE *a2)
{
  __int64 (__fastcall *v2)(_QWORD); // x8

  v2 = *(__int64 (__fastcall **)(_QWORD))(result + 1704);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -821198918 )
      __break(0x8228u);
    return v2(a2);
  }
  else
  {
    *a2 = 2;
  }
  return result;
}
