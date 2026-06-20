__int64 __fastcall dsi_phy_parse_dt_per_lane_cfgs(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v5; // x0
  _BYTE *property; // x0
  unsigned int v7; // w8
  __int64 result; // x0
  int v9; // w9
  unsigned int v10; // w8
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned int v13; // w8
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 760);
  v14 = 0;
  property = (_BYTE *)of_get_property(v5, a3, &v14);
  if ( !property )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Unable to read Phy %s settings\n", a3);
    result = 4294967274LL;
LABEL_37:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v7 = *(_DWORD *)(a2 + 68);
  if ( v14 != 5 * v7 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: incorrect phy %s settings, exp=%d, act=%d\n",
      a3,
      5 * v7,
      v14);
    result = 4294967274LL;
    goto LABEL_37;
  }
  if ( !v7 )
  {
    v9 = 0;
    goto LABEL_17;
  }
  *(_BYTE *)a2 = *property;
  if ( v7 == 1 )
  {
    ++property;
    goto LABEL_13;
  }
  *(_BYTE *)(a2 + 1) = property[1];
  if ( v7 < 3 )
  {
    property += 2;
    goto LABEL_13;
  }
  *(_BYTE *)(a2 + 2) = property[2];
  if ( v7 == 3 )
  {
    property += 3;
    goto LABEL_13;
  }
  *(_BYTE *)(a2 + 3) = property[3];
  if ( v7 < 5 )
  {
    property += 4;
LABEL_13:
    *(_BYTE *)(a2 + 8) = *property;
    if ( v7 < 2 )
    {
      v9 = v7;
      ++property;
    }
    else
    {
      *(_BYTE *)(a2 + 9) = property[1];
      if ( v7 == 2 )
      {
        property += 2;
        v9 = 1;
      }
      else
      {
        *(_BYTE *)(a2 + 10) = property[2];
        if ( v7 < 4 )
        {
          property += 3;
          v9 = 1;
        }
        else
        {
          *(_BYTE *)(a2 + 11) = property[3];
          if ( v7 == 4 )
          {
            property += 4;
            v9 = 1;
          }
          else
          {
            v7 = *(_DWORD *)(a2 + 68);
            *(_BYTE *)(a2 + 12) = property[4];
            if ( v7 < 6 )
            {
              property += 5;
            }
            else
            {
              v7 = *(_DWORD *)(a2 + 68);
              *(_BYTE *)(a2 + 13) = property[5];
              if ( v7 < 7 )
              {
                property += 6;
              }
              else
              {
                v7 = *(_DWORD *)(a2 + 68);
                *(_BYTE *)(a2 + 14) = property[6];
                if ( v7 < 8 )
                {
                  property += 7;
                }
                else
                {
                  v7 = *(_DWORD *)(a2 + 68);
                  *(_BYTE *)(a2 + 15) = property[7];
                  if ( v7 > 8 )
                    goto LABEL_89;
                  property += 8;
                }
              }
            }
            v9 = v7;
          }
        }
      }
    }
    goto LABEL_17;
  }
  v7 = *(_DWORD *)(a2 + 68);
  *(_BYTE *)(a2 + 4) = property[4];
  if ( v7 < 6 )
  {
    property += 5;
  }
  else
  {
    v7 = *(_DWORD *)(a2 + 68);
    *(_BYTE *)(a2 + 5) = property[5];
    if ( v7 < 7 )
    {
      property += 6;
    }
    else
    {
      v7 = *(_DWORD *)(a2 + 68);
      *(_BYTE *)(a2 + 6) = property[6];
      if ( v7 < 8 )
      {
        property += 7;
      }
      else
      {
        v7 = *(_DWORD *)(a2 + 68);
        *(_BYTE *)(a2 + 7) = property[7];
        if ( v7 > 8 )
          goto LABEL_89;
        property += 8;
      }
    }
  }
  v9 = v7;
  if ( v7 )
    goto LABEL_13;
LABEL_17:
  if ( v9 )
  {
    *(_BYTE *)(a2 + 16) = *property;
    if ( v7 < 2 )
    {
      v9 = v7;
      ++property;
    }
    else
    {
      *(_BYTE *)(a2 + 17) = property[1];
      if ( v7 == 2 )
      {
        property += 2;
        v9 = 1;
      }
      else
      {
        *(_BYTE *)(a2 + 18) = property[2];
        if ( v7 < 4 )
        {
          property += 3;
          v9 = 1;
        }
        else
        {
          *(_BYTE *)(a2 + 19) = property[3];
          if ( v7 == 4 )
          {
            property += 4;
            v9 = 1;
          }
          else
          {
            v7 = *(_DWORD *)(a2 + 68);
            *(_BYTE *)(a2 + 20) = property[4];
            if ( v7 < 6 )
            {
              property += 5;
            }
            else
            {
              v7 = *(_DWORD *)(a2 + 68);
              *(_BYTE *)(a2 + 21) = property[5];
              if ( v7 < 7 )
              {
                property += 6;
              }
              else
              {
                v7 = *(_DWORD *)(a2 + 68);
                *(_BYTE *)(a2 + 22) = property[6];
                if ( v7 < 8 )
                {
                  property += 7;
                }
                else
                {
                  v7 = *(_DWORD *)(a2 + 68);
                  *(_BYTE *)(a2 + 23) = property[7];
                  if ( v7 > 8 )
                    goto LABEL_89;
                  property += 8;
                }
              }
            }
            v9 = v7;
          }
        }
      }
    }
  }
  if ( v9 )
  {
    *(_BYTE *)(a2 + 24) = *property;
    if ( v7 < 2 )
    {
      v9 = v7;
      ++property;
    }
    else
    {
      *(_BYTE *)(a2 + 25) = property[1];
      if ( v7 == 2 )
      {
        property += 2;
        v9 = 1;
      }
      else
      {
        *(_BYTE *)(a2 + 26) = property[2];
        if ( v7 < 4 )
        {
          property += 3;
          v9 = 1;
        }
        else
        {
          *(_BYTE *)(a2 + 27) = property[3];
          if ( v7 == 4 )
          {
            property += 4;
            v9 = 1;
          }
          else
          {
            v7 = *(_DWORD *)(a2 + 68);
            *(_BYTE *)(a2 + 28) = property[4];
            if ( v7 < 6 )
            {
              property += 5;
            }
            else
            {
              v7 = *(_DWORD *)(a2 + 68);
              *(_BYTE *)(a2 + 29) = property[5];
              if ( v7 < 7 )
              {
                property += 6;
              }
              else
              {
                v7 = *(_DWORD *)(a2 + 68);
                *(_BYTE *)(a2 + 30) = property[6];
                if ( v7 < 8 )
                {
                  property += 7;
                }
                else
                {
                  v7 = *(_DWORD *)(a2 + 68);
                  *(_BYTE *)(a2 + 31) = property[7];
                  if ( v7 > 8 )
                    goto LABEL_89;
                  property += 8;
                }
              }
            }
            v9 = v7;
          }
        }
      }
    }
  }
  if ( !v9 )
    goto LABEL_36;
  *(_BYTE *)(a2 + 32) = *property;
  if ( v7 < 2 )
    goto LABEL_36;
  *(_BYTE *)(a2 + 33) = property[1];
  if ( v7 == 2 )
    goto LABEL_36;
  *(_BYTE *)(a2 + 34) = property[2];
  if ( v7 < 4 )
    goto LABEL_36;
  *(_BYTE *)(a2 + 35) = property[3];
  if ( v7 == 4 )
    goto LABEL_36;
  v10 = *(_DWORD *)(a2 + 68);
  *(_BYTE *)(a2 + 36) = property[4];
  if ( v10 < 6
    || (v11 = *(_DWORD *)(a2 + 68), *(_BYTE *)(a2 + 37) = property[5], v11 < 7)
    || (v12 = *(_DWORD *)(a2 + 68), *(_BYTE *)(a2 + 38) = property[6], v12 < 8)
    || (v13 = *(_DWORD *)(a2 + 68), *(_BYTE *)(a2 + 39) = property[7], v13 <= 8) )
  {
LABEL_36:
    result = 0;
    goto LABEL_37;
  }
LABEL_89:
  __break(0x5512u);
  return dsi_pwr_set_lp2_load();
}
