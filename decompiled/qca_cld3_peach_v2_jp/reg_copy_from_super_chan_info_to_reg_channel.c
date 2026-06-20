__int64 __fastcall reg_copy_from_super_chan_info_to_reg_channel(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x9

  if ( a3 == -1 )
    a3 = *(_DWORD *)(a2 + 4);
  if ( a3 - 13 >= 0xFFFFFFF4 )
  {
    v3 = a2 + 4LL * a3;
    v4 = a2 + 2LL * a3;
    *(_DWORD *)(result + 8) = *(_DWORD *)(v3 + 216);
    v5 = a2 + 8LL * a3;
    *(_DWORD *)(result + 12) = *(_DWORD *)(v3 + 60);
    *(_DWORD *)(result + 16) = *(_DWORD *)(v5 + 116);
    *(_WORD *)(result + 20) = *(_WORD *)(v4 + 8);
    *(_WORD *)(result + 22) = *(_WORD *)(v4 + 34);
    *(_BYTE *)(result + 27) = *(_BYTE *)(v5 + 112);
    *(_WORD *)(result + 28) = *(_WORD *)(v5 + 114);
  }
  return result;
}
