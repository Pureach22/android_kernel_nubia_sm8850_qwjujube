__int64 __fastcall cam_res_mgr_util_get_idx_from_shared_pctrl_gpio(_QWORD *a1)
{
  __int64 v1; // x13
  int v2; // w8
  unsigned int v3; // w9

  v2 = *(_DWORD *)(cam_res + 116);
  if ( v2 < 1 || *(_DWORD *)(cam_res + 72) == (_DWORD)a1 )
  {
    v3 = 0;
  }
  else if ( v2 == 1 || *(_DWORD *)(cam_res + 76) == (_DWORD)a1 )
  {
    v3 = 1;
  }
  else if ( v2 == 2 || *(_DWORD *)(cam_res + 80) == (_DWORD)a1 )
  {
    v3 = 2;
  }
  else if ( v2 == 3 || *(_DWORD *)(cam_res + 84) == (_DWORD)a1 )
  {
    v3 = 3;
  }
  else if ( v2 == 4 || *(_DWORD *)(cam_res + 88) == (_DWORD)a1 )
  {
    v3 = 4;
  }
  else if ( v2 == 5 || *(_DWORD *)(cam_res + 92) == (_DWORD)a1 )
  {
    v3 = 5;
  }
  else if ( v2 == 6 || *(_DWORD *)(cam_res + 96) == (_DWORD)a1 )
  {
    v3 = 6;
  }
  else if ( v2 == 7 || *(_DWORD *)(cam_res + 100) == (_DWORD)a1 )
  {
    v3 = 7;
  }
  else if ( v2 == 8 || *(_DWORD *)(cam_res + 104) == (_DWORD)a1 )
  {
    v3 = 8;
  }
  else if ( v2 == 9 || *(_DWORD *)(cam_res + 108) == (_DWORD)a1 )
  {
    v3 = 9;
  }
  else
  {
    if ( v2 != 10 )
    {
      __break(0x5512u);
      *a1 = v1;
      return cam_res_mgr_util_get_idx_from_shared_gpio((char *)a1 + 217);
    }
    v3 = 10;
  }
  if ( v3 == v2 )
    return 4294967274LL;
  else
    return v3;
}
