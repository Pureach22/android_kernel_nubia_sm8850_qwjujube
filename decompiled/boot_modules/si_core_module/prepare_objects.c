__int64 __fastcall prepare_objects(__int64 result, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  char v4; // w8
  __int64 v5; // x20
  __int64 v6; // x8
  unsigned __int64 v7; // x22
  unsigned int *v8; // x21
  unsigned int v9; // t1
  bool v10; // cf
  __int64 v11; // x20
  __int64 v12; // x8
  unsigned __int64 v13; // x22
  unsigned int *v14; // x21
  unsigned int v15; // t1
  __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v3 = result;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE *)(result + 4);
  v17 = a2;
  v18 = a3;
  if ( (v4 & 1) != 0 )
  {
    v11 = *(_QWORD *)(result + 1648);
    if ( (*(_DWORD *)(v11 + 12) & 0xF000) != 0 && a3 >= 0x18 )
    {
      v12 = (*(_DWORD *)(v11 + 12) & 0xF)
          + ((*(_DWORD *)(v11 + 12) >> 8) & 0xF)
          + (unsigned int)((unsigned __int8)*(_DWORD *)(v11 + 12) >> 4);
      v13 = v12 + 1;
      v14 = (unsigned int *)(v11 + 8LL * (unsigned int)v12 + 16);
      do
      {
        v15 = *v14;
        v14 += 2;
        result = call_prepare(v3, v15, &v17);
        v10 = v13++ >= ((unsigned __int8)*(_DWORD *)(v11 + 12) >> 4)
                     + (*(_DWORD *)(v11 + 12) & 0xF)
                     + ((*(_DWORD *)(v11 + 12) >> 8) & 0xF)
                     + (unsigned int)((unsigned __int16)*(_DWORD *)(v11 + 12) >> 12);
      }
      while ( !v10 && v18 > 0x17 );
    }
  }
  else
  {
    v5 = *(_QWORD *)(result + 1600);
    if ( (*(_DWORD *)(v5 + 8) & 0xF00) != 0 && a3 >= 0x18 )
    {
      v6 = (*(_DWORD *)(v5 + 8) & 0xF) + (unsigned int)((unsigned __int8)*(_DWORD *)(v5 + 8) >> 4);
      v7 = v6 + 1;
      v8 = (unsigned int *)(v5 + 8LL * (unsigned int)v6 + 12);
      do
      {
        v9 = *v8;
        v8 += 2;
        result = call_prepare(v3, v9, &v17);
        v10 = v7++ >= ((unsigned __int8)*(_DWORD *)(v5 + 8) >> 4)
                    + (*(_DWORD *)(v5 + 8) & 0xF)
                    + ((*(_DWORD *)(v5 + 8) >> 8) & 0xFu);
        v10 = !v10 && v18 >= 0x18;
      }
      while ( v10 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
