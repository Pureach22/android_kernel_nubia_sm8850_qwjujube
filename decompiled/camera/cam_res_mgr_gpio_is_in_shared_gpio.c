__int64 __fastcall cam_res_mgr_gpio_is_in_shared_gpio(int a1)
{
  unsigned int v1; // w8
  __int64 result; // x0

  v1 = *(_DWORD *)(cam_res + 112);
  if ( (int)v1 < 1 )
    return 0;
  if ( *(_DWORD *)(cam_res + 8) == a1 )
    return 1;
  result = v1 != 1;
  if ( v1 != 1 && *(_DWORD *)(cam_res + 12) != a1 )
  {
    result = v1 > 2;
    if ( v1 != 2 && *(_DWORD *)(cam_res + 16) != a1 )
    {
      result = v1 > 3;
      if ( v1 != 3 && *(_DWORD *)(cam_res + 20) != a1 )
      {
        result = v1 > 4;
        if ( v1 != 4 && *(_DWORD *)(cam_res + 24) != a1 )
        {
          result = v1 > 5;
          if ( v1 != 5 && *(_DWORD *)(cam_res + 28) != a1 )
          {
            result = v1 > 6;
            if ( v1 != 6 && *(_DWORD *)(cam_res + 32) != a1 )
            {
              result = v1 > 7;
              if ( v1 != 7 && *(_DWORD *)(cam_res + 36) != a1 )
              {
                result = v1 > 8;
                if ( v1 != 8 && *(_DWORD *)(cam_res + 40) != a1 )
                {
                  result = v1 > 9;
                  if ( v1 != 9 && *(_DWORD *)(cam_res + 44) != a1 )
                  {
                    result = v1 > 0xA;
                    if ( v1 != 10 && *(_DWORD *)(cam_res + 48) != a1 )
                    {
                      result = v1 > 0xB;
                      if ( v1 != 11 && *(_DWORD *)(cam_res + 52) != a1 )
                      {
                        result = v1 > 0xC;
                        if ( v1 != 12 && *(_DWORD *)(cam_res + 56) != a1 )
                        {
                          result = v1 > 0xD;
                          if ( v1 != 13 && *(_DWORD *)(cam_res + 60) != a1 )
                          {
                            result = v1 > 0xE;
                            if ( v1 != 14 && *(_DWORD *)(cam_res + 64) != a1 )
                            {
                              result = v1 > 0xF;
                              if ( v1 != 15 && *(_DWORD *)(cam_res + 68) != a1 )
                              {
                                result = v1 > 0x10;
                                if ( v1 != 16 )
                                {
                                  __break(0x5512u);
                                  return cam_res_mgr_gpio_is_in_shared_pctrl_gpio(result);
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
