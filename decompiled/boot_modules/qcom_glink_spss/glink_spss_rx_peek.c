__int64 __fastcall glink_spss_rx_peek(__int64 result, __int64 a2, int a3, unsigned __int64 a4)
{
  __int64 v4; // x9
  __int64 v6; // x20
  unsigned __int64 v8; // x8
  int v9; // w10
  __int64 v10; // x8
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x21

  v4 = *(_QWORD *)result;
  v6 = result;
  v8 = (unsigned int)(**(_DWORD **)(result + 48) + a3);
  if ( *(_QWORD *)result <= v8 )
    v9 = *(_QWORD *)result;
  else
    v9 = 0;
  v10 = (unsigned int)(v8 - v9);
  v11 = v4 - v10;
  if ( v4 - v10 >= a4 )
    v12 = a4;
  else
    v12 = v4 - v10;
  if ( v12 )
    result = _memcpy_fromio(a2, *(_QWORD *)(result + 64) + v10, v12);
  if ( v11 < a4 )
    return _memcpy_fromio(a2 + v12, *(_QWORD *)(v6 + 64), a4 - v12);
  return result;
}
