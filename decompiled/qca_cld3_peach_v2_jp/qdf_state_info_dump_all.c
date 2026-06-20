__int64 __fastcall qdf_state_info_dump_all(__int64 a1, __int16 a2, _WORD *a3)
{
  __int64 v5; // x21
  __int16 v6; // w8
  void (__fastcall *v7)(__int64 *, __int16 *); // x9
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int16 v10; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v5 = 0;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a2;
  v10 = a2;
  v9 = a1;
  do
  {
    v7 = *(void (__fastcall **)(__int64 *, __int16 *))((char *)&qdf_state_info_table + v5);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -28434718 )
        __break(0x8229u);
      v7(&v9, &v10);
      v6 = v10;
      if ( !v10 )
      {
        result = 2;
        goto LABEL_9;
      }
    }
    v5 += 8;
  }
  while ( v5 != 1336 );
  result = 0;
LABEL_9:
  *a3 = a2 - v6;
  _ReadStatusReg(SP_EL0);
  return result;
}
