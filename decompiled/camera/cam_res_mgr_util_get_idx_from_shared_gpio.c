__int64 __fastcall cam_res_mgr_util_get_idx_from_shared_gpio(_QWORD *a1)
{
  __int64 v1; // x13
  int v2; // w8
  unsigned int v3; // w9

  v2 = *(_DWORD *)(cam_res + 112);
  if ( v2 < 1 || *(_DWORD *)(cam_res + 8) == (_DWORD)a1 )
  {
    v3 = 0;
  }
  else if ( v2 == 1 || *(_DWORD *)(cam_res + 12) == (_DWORD)a1 )
  {
    v3 = 1;
  }
  else if ( v2 == 2 || *(_DWORD *)(cam_res + 16) == (_DWORD)a1 )
  {
    v3 = 2;
  }
  else if ( v2 == 3 || *(_DWORD *)(cam_res + 20) == (_DWORD)a1 )
  {
    v3 = 3;
  }
  else if ( v2 == 4 || *(_DWORD *)(cam_res + 24) == (_DWORD)a1 )
  {
    v3 = 4;
  }
  else if ( v2 == 5 || *(_DWORD *)(cam_res + 28) == (_DWORD)a1 )
  {
    v3 = 5;
  }
  else if ( v2 == 6 || *(_DWORD *)(cam_res + 32) == (_DWORD)a1 )
  {
    v3 = 6;
  }
  else if ( v2 == 7 || *(_DWORD *)(cam_res + 36) == (_DWORD)a1 )
  {
    v3 = 7;
  }
  else if ( v2 == 8 || *(_DWORD *)(cam_res + 40) == (_DWORD)a1 )
  {
    v3 = 8;
  }
  else if ( v2 == 9 || *(_DWORD *)(cam_res + 44) == (_DWORD)a1 )
  {
    v3 = 9;
  }
  else if ( v2 == 10 || *(_DWORD *)(cam_res + 48) == (_DWORD)a1 )
  {
    v3 = 10;
  }
  else if ( v2 == 11 || *(_DWORD *)(cam_res + 52) == (_DWORD)a1 )
  {
    v3 = 11;
  }
  else if ( v2 == 12 || *(_DWORD *)(cam_res + 56) == (_DWORD)a1 )
  {
    v3 = 12;
  }
  else if ( v2 == 13 || *(_DWORD *)(cam_res + 60) == (_DWORD)a1 )
  {
    v3 = 13;
  }
  else if ( v2 == 14 || *(_DWORD *)(cam_res + 64) == (_DWORD)a1 )
  {
    v3 = 14;
  }
  else if ( v2 == 15 || *(_DWORD *)(cam_res + 68) == (_DWORD)a1 )
  {
    v3 = 15;
  }
  else
  {
    if ( v2 != 16 )
    {
      __break(0x5512u);
      *a1 = v1;
      return cam_res_mgr_util_shared_gpio_check_hold((char *)a1 + 217);
    }
    v3 = 16;
  }
  if ( v3 == v2 )
    return 4294967274LL;
  else
    return v3;
}
