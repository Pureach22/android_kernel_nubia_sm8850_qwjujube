__int64 __fastcall cam_csiphy_register_baseaddress(__int64 a1)
{
  unsigned int v1; // w6
  char *v4; // x9
  __int64 v5; // x10
  __int64 v6; // x10

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 932);
    if ( v1 < 8 )
    {
      v4 = (char *)&g_phy_data + 56 * v1;
      v5 = *(_QWORD *)(a1 + 1200);
      *(_QWORD *)v4 = v5;
      *((_DWORD *)v4 + 3) = *(_DWORD *)(a1 + 88);
      v6 = *(_QWORD *)(**(_QWORD **)(a1 + 112) + 64LL);
      *((_DWORD *)v4 + 9) = 255;
      v4[16] = 0;
      *((_QWORD *)v4 + 3) = 0;
      *((_QWORD *)v4 + 5) = v6;
      *((_QWORD *)v4 + 6) = a1 + 4608;
      return 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_register_baseaddress",
        3463,
        "Invalid soc index: %u Max soc index: %u",
        v1,
        8);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_register_baseaddress",
      3457,
      "Data is NULL");
    return 4294967274LL;
  }
}
