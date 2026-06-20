__int64 __fastcall rmnet_map_dl_hdr_notify_v2(__int64 result, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x21
  _QWORD *i; // x22
  __int64 (__fastcall *v7)(__int64, __int64); // x8

  v3 = *(_QWORD **)(result + 2480);
  for ( i = (_QWORD *)(result + 2480); v3 != i; v3 = (_QWORD *)*v3 )
  {
    v7 = (__int64 (__fastcall *)(__int64, __int64))*(v3 - 2);
    if ( *((_DWORD *)v7 - 1) != 639187566 )
      __break(0x8228u);
    result = v7(a2, a3);
  }
  return result;
}
