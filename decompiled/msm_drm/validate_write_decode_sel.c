__int64 __fastcall validate_write_decode_sel(__int64 a1)
{
  __int64 v1; // x1
  _BOOL4 v2; // w8
  bool v3; // zf
  __int64 result; // x0

  if ( (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 24) + 16LL) - *(_DWORD *)(*(_QWORD *)(a1 + 24) + 20LL)) <= 7 )
  {
    _drm_err("buffer is full needs %d bytes\n", 8);
    return 4294967274LL;
  }
  v1 = *(unsigned int *)(a1 + 4);
  if ( !(_DWORD)v1 )
  {
    _drm_err("blk set as 0\n");
    return 4294967274LL;
  }
  v2 = (v1 & 0x30F000) == 0 || (v1 & 0xF00000F) == 0;
  v3 = (v1 & 0xF00) == 0 || (v1 & 0xF30F00F) == 0;
  if ( !v3 || !v2 || (result = 0, (v1 & 0x80000000) != 0) && (v1 & 0xF30FF0F) != 0 )
  {
    _drm_err("invalid blk combination %x\n", v1);
    return 4294967274LL;
  }
  return result;
}
