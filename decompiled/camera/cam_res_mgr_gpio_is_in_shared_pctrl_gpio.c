__int64 __fastcall cam_res_mgr_gpio_is_in_shared_pctrl_gpio(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  __int64 result; // x0

  v4 = *(_DWORD *)(cam_res + 116);
  if ( (int)v4 < 1 )
    return 0;
  if ( *(_DWORD *)(cam_res + 72) == a1 )
    return 1;
  result = v4 != 1;
  if ( v4 != 1 && *(_DWORD *)(cam_res + 76) != a1 )
  {
    result = v4 > 2;
    if ( v4 != 2 && *(_DWORD *)(cam_res + 80) != a1 )
    {
      result = v4 > 3;
      if ( v4 != 3 && *(_DWORD *)(cam_res + 84) != a1 )
      {
        result = v4 > 4;
        if ( v4 != 4 && *(_DWORD *)(cam_res + 88) != a1 )
        {
          result = v4 > 5;
          if ( v4 != 5 && *(_DWORD *)(cam_res + 92) != a1 )
          {
            result = v4 > 6;
            if ( v4 != 6 && *(_DWORD *)(cam_res + 96) != a1 )
            {
              result = v4 > 7;
              if ( v4 != 7 && *(_DWORD *)(cam_res + 100) != a1 )
              {
                result = v4 > 8;
                if ( v4 != 8 && *(_DWORD *)(cam_res + 104) != a1 )
                {
                  result = v4 > 9;
                  if ( v4 != 9 && *(_DWORD *)(cam_res + 108) != a1 )
                  {
                    result = v4 > 0xA;
                    if ( v4 != 10 )
                    {
                      __break(0x5512u);
                      return cam_res_mgr_gpio_request(result, a2, a3, a4);
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
