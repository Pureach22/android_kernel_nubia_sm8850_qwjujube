__int64 __fastcall cam_ife_csid_cid_release(__int64 a1, int a2, int a3)
{
  int v3; // w8
  int v4; // w8
  unsigned int v6; // w8
  __int64 v7; // x0

  v3 = *(_DWORD *)(a1 + 48);
  if ( v3 )
  {
    v4 = v3 - 1;
    *(_DWORD *)(a1 + 48) = v4;
    if ( v4 )
    {
      return 0;
    }
    else
    {
      v6 = *(_DWORD *)(a1 + 52);
      if ( !v6
        || (*(_BYTE *)(a1 + 8) = 0, v6 == 1)
        || (*(_BYTE *)(a1 + 20) = 0, v6 < 3)
        || (*(_BYTE *)(a1 + 32) = 0, v6 == 3)
        || (*(_BYTE *)(a1 + 44) = 0, v6 <= 4) )
      {
        *(_DWORD *)(a1 + 52) = 0;
        return 0;
      }
      else
      {
        __break(0x5512u);
        v7 = MEMORY[0x7B14184]();
        return cam_ife_csid_check_in_port_args(v7);
      }
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "cam_ife_csid_cid_release",
      505,
      "CSID[%d] unbalanced cid:%d release",
      a2,
      a3);
    return 0;
  }
}
