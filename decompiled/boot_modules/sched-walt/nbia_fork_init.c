__int64 __fastcall nbia_fork_init(__int64 result)
{
  _BYTE *v1; // x8
  __int64 v2; // x9
  __int64 v3; // x9

  v1 = &vendor_data_pad;
  if ( (_UNKNOWN *)result != &init_task )
    v1 = (_BYTE *)(result + 5184);
  if ( result )
  {
    v2 = *(_QWORD *)(result + 2296);
    if ( v2 )
      v1[456] = *(_DWORD *)(v2 + 8) >> 4 > 0x270u;
  }
  v1[457] = 0;
  *((_DWORD *)v1 + 115) = -1;
  v3 = *(_QWORD *)(result + 1392);
  *((_DWORD *)v1 + 120) = 0;
  *((_QWORD *)v1 + 58) = v3;
  *((_QWORD *)v1 + 59) = v3;
  LODWORD(v3) = *(_DWORD *)(result + 152);
  *((_QWORD *)v1 + 61) = 0;
  *((_DWORD *)v1 + 121) = v3;
  return result;
}
