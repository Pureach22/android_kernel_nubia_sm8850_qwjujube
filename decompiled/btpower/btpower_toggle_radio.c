__int64 __fastcall btpower_toggle_radio(__int64 a1, char a2)
{
  char v2; // w20
  _DWORD *v3; // x8
  _BOOL8 v4; // x1
  __int64 result; // x0

  v2 = a2 & 1;
  if ( previous == (a2 & 1) )
    goto LABEL_5;
  v3 = *(_DWORD **)(a1 + 96);
  v4 = (a2 & 1) == 0;
  if ( *(v3 - 1) != 1390819368 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD, _BOOL8))v3)(0, v4);
  if ( !(_DWORD)result )
  {
LABEL_5:
    previous = v2;
    return 0;
  }
  return result;
}
