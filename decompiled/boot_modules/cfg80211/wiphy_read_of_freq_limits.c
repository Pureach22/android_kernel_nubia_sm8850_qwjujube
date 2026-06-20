__int64 __fastcall wiphy_read_of_freq_limits(__int64 result)
{
  __int64 v1; // x27
  __int64 v2; // x21
  unsigned int v3; // w25
  __int64 v4; // x22
  unsigned __int64 v5; // x23
  _DWORD *v6; // x20
  unsigned int v7; // w27
  __int64 v8; // x1
  int v9; // w28
  bool v10; // w26
  _DWORD *v11; // x24
  __int64 u32; // x0
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  __int64 v15; // x22
  __int64 v16; // x27
  __int64 v17; // x28
  __int64 v18; // x19
  int v19; // w21
  int v21; // w21
  __int64 v22; // [xsp+0h] [xbp-20h]
  __int64 v23; // [xsp+8h] [xbp-18h]
  int v24; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 488);
  if ( v1 )
  {
    v2 = result;
    result = *(_QWORD *)(v1 + 744);
    if ( result )
    {
      v24 = 0;
      result = of_find_property(result, "ieee80211-freq-limit", &v24);
      if ( result )
      {
        if ( !v24 || (v24 & 7) != 0 )
        {
          result = dev_err(v1, "ieee80211-freq-limit wrong format");
        }
        else
        {
          v3 = v24 >> 3;
          v4 = result;
          v5 = 12LL * (unsigned int)(v24 >> 3);
          v6 = (_DWORD *)_kmalloc_noprof(v5, 3520);
          if ( v6 )
          {
            v22 = v1;
            v7 = 0;
            v8 = 0;
            if ( v3 <= 1 )
              v9 = 1;
            else
              v9 = v3;
            v10 = 1;
            do
            {
              v11 = &v6[3 * v7];
              u32 = of_prop_next_u32(v4, v8, v11);
              if ( !u32 )
                goto LABEL_36;
              v13 = of_prop_next_u32(v4, u32, v11 + 1);
              if ( !v13 )
                goto LABEL_36;
              v14 = 12LL * (int)v7;
              if ( v5 <= v14 )
                goto LABEL_38;
              if ( !*v11 )
              {
LABEL_36:
                kfree(v6);
                v1 = v22;
                v21 = -22;
                goto LABEL_40;
              }
              if ( v5 <= v14 + 4 )
LABEL_38:
                __break(1u);
              if ( *v11 >= v11[1] )
              {
                v21 = -22;
                goto LABEL_34;
              }
              ++v7;
              v8 = v13;
              v10 = v7 < v3;
            }
            while ( v9 != v7 );
            v15 = 0;
            v23 = v2 + 328;
            do
            {
              v16 = *(_QWORD *)(v23 + 8 * v15);
              if ( v16 && *(int *)(v16 + 20) >= 1 )
              {
                v17 = 0;
                do
                {
                  v18 = *(_QWORD *)v16 + (v17 << 6);
                  if ( (*(_BYTE *)(v18 + 12) & 1) == 0
                    && !cfg80211_does_bw_fit_range(v6, 1000 * *(_DWORD *)(v18 + 4), 0x4E20u) )
                  {
                    v19 = 1;
                    do
                    {
                      if ( v3 == v19 )
                        goto LABEL_23;
                    }
                    while ( !cfg80211_does_bw_fit_range(&v6[3 * v19++], 1000 * *(_DWORD *)(v18 + 4), 0x4E20u) );
                    if ( v19 - 1 >= v3 )
LABEL_23:
                      *(_DWORD *)(v18 + 12) |= 1u;
                  }
                  ++v17;
                }
                while ( v17 < *(int *)(v16 + 20) );
              }
              ++v15;
            }
            while ( v15 != 6 );
            v21 = 0;
LABEL_34:
            result = kfree(v6);
            v1 = v22;
            if ( v10 )
              goto LABEL_40;
          }
          else
          {
            kfree(0);
            v21 = -12;
LABEL_40:
            result = dev_err(v1, "Failed to get limits: %d\n", v21);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
