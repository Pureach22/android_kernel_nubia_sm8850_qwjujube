__int64 __fastcall list_rates_show(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x8
  __int64 *v5; // x9
  __int64 v6; // x21
  __int64 v7; // x10
  __int64 v8; // t1
  _DWORD *v9; // x8
  __int64 v10; // x0
  unsigned __int64 v11; // x2
  unsigned int v12; // w22
  _DWORD *v13; // x8

  v1 = *(_QWORD *)(a1 + 128);
  v3 = *(_QWORD *)(v1 + 48);
  clk_round_rate(*(_QWORD *)(v1 + 8), 0);
  if ( v3 )
  {
    v4 = *(unsigned int *)(v1 + 72);
    if ( (int)v4 < 1 )
    {
      v6 = 0;
    }
    else
    {
      v5 = *(__int64 **)(v1 + 64);
      v6 = 0;
      do
      {
        v8 = *v5++;
        v7 = v8;
        if ( v8 )
          v6 = v7;
        --v4;
      }
      while ( v4 );
    }
  }
  else
  {
    v6 = -1;
  }
  v9 = *(_DWORD **)(*(_QWORD *)(v1 + 88) + 8LL);
  if ( *(v9 - 1) != -958950422 )
    __break(0x8228u);
  v10 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v9)(v1, 0, v6);
  if ( (unsigned __int64)(v10 + 4095) >= 0x1000 )
  {
    v11 = v10;
    v12 = 1;
    do
    {
      seq_printf(a1, "%lu\n", v11);
      v13 = *(_DWORD **)(*(_QWORD *)(v1 + 88) + 8LL);
      if ( *(v13 - 1) != -958950422 )
        __break(0x8228u);
      v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v13)(v1, v12++, v6);
    }
    while ( v11 != 0 && v11 < 0xFFFFFFFFFFFFF001LL );
  }
  return 0;
}
