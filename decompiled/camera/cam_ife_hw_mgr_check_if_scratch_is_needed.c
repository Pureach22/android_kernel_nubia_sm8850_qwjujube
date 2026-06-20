__int64 __fastcall cam_ife_hw_mgr_check_if_scratch_is_needed(__int64 result, __int64 a2)
{
  int v2; // w9
  _DWORD *v3; // x8
  int v4; // w9
  int v5; // w8
  _DWORD *v6; // x9
  int v7; // w9

  if ( (*(_BYTE *)(result + 9388) & 1) != 0 || *(_BYTE *)(result + 9387) == 1 )
  {
    v2 = *(_DWORD *)(result + 9352);
    *(_BYTE *)(a2 + 24) = 1;
    *(_DWORD *)a2 = v2;
    if ( **(_DWORD **)(result + 9368) )
    {
      *(_BYTE *)(a2 + 25) = 1;
      v3 = *(_DWORD **)(result + 9368);
      if ( *v3 )
      {
        v4 = v3[8];
        v5 = *(_DWORD *)(a2 + 8);
        *(_DWORD *)(a2 + 8) = v5 + 1;
        *(_DWORD *)(a2 + 12) = v4;
        v6 = *(_DWORD **)(result + 9368);
        if ( *v6 > 1u )
        {
          v7 = v6[18];
          *(_DWORD *)(a2 + 8) = v5 + 2;
          *(_DWORD *)(a2 + 16) = v7;
          if ( **(_DWORD **)(result + 9368) > 2u )
          {
            __break(0x5512u);
            return cam_ife_hw_mgr_sfe_scratch_buf_update();
          }
        }
      }
    }
  }
  return result;
}
