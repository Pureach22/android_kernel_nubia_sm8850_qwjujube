__int64 __fastcall rmnet_map_pb_ind_notify(__int64 result, unsigned int *a2)
{
  _QWORD *v2; // x21
  _QWORD *v3; // x22
  __int64 v4; // x19
  __int64 (__fastcall *v6)(_QWORD); // x8

  v2 = *(_QWORD **)(result + 2752);
  v3 = (_QWORD *)(result + 2752);
  if ( v2 != (_QWORD *)(result + 2752) )
  {
    v4 = result;
    do
    {
      *(_QWORD *)(v4 + 2720) = *a2;
      v6 = (__int64 (__fastcall *)(_QWORD))*(v2 - 1);
      if ( *((_DWORD *)v6 - 1) != 362581883 )
        __break(0x8228u);
      result = v6(a2);
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != v3 );
  }
  return result;
}
