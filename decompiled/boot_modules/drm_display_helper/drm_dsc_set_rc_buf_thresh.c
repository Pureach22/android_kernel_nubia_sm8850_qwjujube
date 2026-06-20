__int64 __fastcall drm_dsc_set_rc_buf_thresh(__int64 result)
{
  int v1; // w9

  v1 = *(unsigned __int16 *)(result + 16);
  *(_QWORD *)(result + 30) = 0x38002A001C000ELL;
  *(_QWORD *)(result + 38) = 0x69006200540046LL;
  *(_QWORD *)(result + 46) = 0x7B007900770070LL;
  *(_DWORD *)(result + 54) = 8257661;
  if ( v1 == 96 )
    *(_DWORD *)(result + 54) = 8192124;
  return result;
}
