__int64 __fastcall richtap_rtp_work(__int64 a1)
{
  unsigned int v2; // w21
  unsigned int v3; // w23
  __int64 v4; // x20
  unsigned int *v5; // x22
  unsigned __int8 *v6; // x8
  int v7; // w9
  int v8; // w8
  __int16 v9; // w9
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 result; // x0
  __int64 v14; // x1
  _DWORD *v15; // x8
  unsigned __int8 (__fastcall *v16)(_QWORD); // x8
  __int64 (__fastcall *v17)(_QWORD); // x8
  void (__fastcall *v18)(_QWORD); // x8
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  void (__fastcall *v20)(__int64, __int64); // x8
  __int64 (__fastcall *v21)(_QWORD); // x8

  *(_DWORD *)(a1 + 120) = 0;
  v2 = 0;
  v3 = 0;
  v4 = a1 - 1608;
  v5 = (unsigned int *)(a1 - 496);
  *(_QWORD *)(a1 - 40) = *(_QWORD *)(a1 - 56);
  do
  {
    v6 = *(unsigned __int8 **)(a1 - 40);
    v7 = *v6;
    if ( v7 == 85 )
    {
      v8 = *((__int16 *)v6 + 1);
      if ( v2 + v8 <= *v5 )
      {
        memcpy((void *)(*(_QWORD *)(a1 - 64) + v2), (const void *)(*(_QWORD *)(a1 - 40) + 24LL), v8);
        v10 = *(_QWORD *)(a1 - 40);
        *(_BYTE *)v10 = -1;
        v2 += *(__int16 *)(v10 + 2);
        *(_WORD *)(*(_QWORD *)(a1 - 40) + 2LL) = 0;
        v11 = *(_QWORD *)(a1 - 40);
        *(_WORD *)(a1 + 112) = 0;
        *(_QWORD *)(a1 - 40) = *(_QWORD *)(v11 + 8);
      }
      else
      {
        memcpy((void *)(*(_QWORD *)(a1 - 64) + v2), (const void *)(*(_QWORD *)(a1 - 40) + 24LL), *v5 - v2);
        v9 = *v5 - v2;
        v2 = *v5;
        *(_WORD *)(a1 + 112) = v9;
      }
    }
    else
    {
      if ( v7 == 170 )
        break;
      msleep(1);
    }
    if ( v2 >= *v5 )
      break;
  }
  while ( v3++ < 0x1E );
  result = richtap_rtp_start(v4);
  if ( (result & 1) != 0 )
  {
    v14 = *(_QWORD *)(a1 - 64);
    v15 = *(_DWORD **)(*(_QWORD *)(a1 - 128) + 208LL);
    if ( *(v15 - 1) != -962088293 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v15)(v4, v14, v2);
    if ( *(_BYTE *)(a1 - 1591) == 1 )
    {
      *(_DWORD *)(a1 + 116) = 1;
      do
      {
        v16 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 128) + 368LL);
        if ( *((_DWORD *)v16 - 1) != 2018195540 )
          __break(0x8228u);
        if ( v16(v4) || *(_BYTE *)(a1 - 1585) != 2 || **(_BYTE **)(a1 - 40) != 85 )
          break;
        richtap_update_fifo_data(v4, *v5 >> 2);
        v17 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 128) + 352LL);
        if ( *((_DWORD *)v17 - 1) != 2018195540 )
          __break(0x8228u);
      }
      while ( (v17(v4) & 0xF) != 0 );
      v18 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 128) + 240LL);
      if ( *((_DWORD *)v18 - 1) != -2072377296 )
        __break(0x8228u);
      v18(v4);
      v19 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 128) + 272LL);
      if ( *((_DWORD *)v19 - 1) != 487251822 )
        __break(0x8228u);
      return v19(v4, 1);
    }
    else
    {
      v20 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 128) + 272LL);
      if ( *((_DWORD *)v20 - 1) != 487251822 )
        __break(0x8228u);
      v20(v4, 1);
      v21 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 - 128) + 240LL);
      if ( *((_DWORD *)v21 - 1) != -2072377296 )
        __break(0x8228u);
      result = v21(v4);
      *(_DWORD *)(a1 + 116) = 1;
    }
  }
  return result;
}
