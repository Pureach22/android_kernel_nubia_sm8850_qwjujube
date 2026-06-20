__int64 __fastcall ipcmem_rx_peak(__int64 result, __int64 a2, unsigned __int64 a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w8
  unsigned int v5; // w10
  __int64 v7; // x20
  unsigned int v8; // w8
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x22

  v3 = *(_DWORD *)result;
  v4 = **(_DWORD **)(result + 8);
  if ( v4 > *(_DWORD *)result )
  {
    __break(0x800u);
  }
  else
  {
    if ( v4 >= v3 )
      v5 = *(_DWORD *)result;
    else
      v5 = 0;
    v7 = result;
    v8 = v4 - v5;
    v10 = v3 - v8;
    if ( v10 >= a3 )
      v11 = a3;
    else
      v11 = v3 - v8;
    if ( v11 )
      result = _memcpy_fromio(a2, *(_QWORD *)(result + 24) + v8, v11);
    if ( v10 < a3 )
      return _memcpy_fromio(a2 + v11, *(_QWORD *)(v7 + 24), a3 - v11);
  }
  return result;
}
