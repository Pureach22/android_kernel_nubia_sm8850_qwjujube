__int64 __fastcall cam_csiphy_update_qmargin_csid_vals(__int64 result, unsigned int a2)
{
  __int64 v2; // x8

  if ( a2 <= 7 )
  {
    v2 = *((_QWORD *)&g_phy_data + 7 * a2 + 6);
    if ( (*(_BYTE *)(result + 20) & 1) != 0 || (*(_BYTE *)(v2 + 12) & 1) == 0 )
    {
      *(_DWORD *)v2 = *(_DWORD *)(result + 8);
      *(_DWORD *)(v2 + 4) = *(_DWORD *)(result + 12);
      *(_DWORD *)(v2 + 8) = *(_DWORD *)(result + 16);
      *(_BYTE *)(v2 + 12) = *(_BYTE *)(result + 20);
      *(_BYTE *)(v2 + 13) = *(_BYTE *)(result + 21);
    }
  }
  return result;
}
