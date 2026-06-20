__int64 __fastcall cam_subdev_notify_message(__int64 result, unsigned int a2, __int64 a3)
{
  __int64 v3; // x8
  _QWORD *v4; // x23
  int v7; // w21
  _DWORD *v8; // x9

  v3 = qword_2FDA58;
  v4 = *(_QWORD **)(qword_2FDA58 + 16);
  if ( v4 != (_QWORD *)(qword_2FDA58 + 16) )
  {
    v7 = result;
    do
    {
      if ( *((_DWORD *)v4 - 19) == v7 )
      {
        v8 = (_DWORD *)v4[39];
        if ( v8 )
        {
          if ( *(v8 - 1) != 1988213104 )
            __break(0x8229u);
          result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v8)(v4 - 15, a2, a3);
          v3 = qword_2FDA58;
        }
      }
      v4 = (_QWORD *)*v4;
    }
    while ( v4 != (_QWORD *)(v3 + 16) );
  }
  return result;
}
